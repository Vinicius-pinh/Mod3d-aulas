#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50;

// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;

GLfloat windowWidth;
GLfloat windowHeight;
GLint cliques=0;
char msg[10];

int x,y;
bool check=true;

void verificaAreaClique()
{
    int x2, x3, x4, y2, y3, y4;
    x2 = x1;
    y2 = y1+rsize;
    x3 = x1+rsize;
    y3 = y1;
    x4 = x1+rsize;
    y4 = y1+rsize;


}
void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON)
    //if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        check=true;
        x = mousex;
        y = windowHeight-mousey;

   }
   else if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)//undo(clear)the drawing
   {
        glClearColor(1, 1, 1, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
   }
   verificaAreaClique();
    glutPostRedisplay();
}

void DesenhaTextoStroke(char *aux)
{
	while(*aux)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*aux++);
}

void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0f, 0.0f, 0.0f);
     glBegin(GL_QUADS);
               glVertex2i(x1,y1+rsize);
               glVertex2i(x1,y1);
               glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(x1+rsize,y1);
               glVertex2i(x1+rsize,y1+rsize);
     glEnd();

     glPushMatrix();

     glTranslatef(0.0f, 200.0f, 0.0f);
     sprintf(msg, "Cliques:%d", cliques++);
     DesenhaTextoStroke(msg);
     glPopMatrix();

     glutSwapBuffers();

     printf("mouse x: %d, y:%d\n", x, y);
}



void Timer(int value)
{
    // Muda a direção quando chega na borda esquerda ou direita
      if(x1 > windowWidth-rsize || x1 < 0)
            xstep = -xstep;

    // Muda a direção quando chega na borda superior ou inferior
    if(y1 > windowHeight-rsize || y1 < 0)
          ystep = -ystep;

    // Verificação de bordas.  Se a window for menor e o quadrado sair do volume de visualização
   if(x1 > windowWidth-rsize)
         x1 = windowWidth-rsize-1;

   if(y1 > windowHeight-rsize)
         y1 = windowHeight-rsize-1;

    x1 += xstep;
    y1 += ystep;

    glutPostRedisplay();
    glutTimerFunc(5,Timer, 0);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
     printf("\n w: %d      h: %d ", w, h);
     glViewport(0, 0, w, h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
     windowWidth = w;
     windowHeight = h;
     gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

int main(int argc, char** argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(640,480);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Animacao");
     glutDisplayFunc(Desenha);
     glutReshapeFunc(AlteraTamanhoJanela);
     glutMouseFunc(mouse);
     glutTimerFunc(5, Timer, 0);
     glutMainLoop();
}

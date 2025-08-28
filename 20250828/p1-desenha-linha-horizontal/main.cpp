/*
 * DESENHA LINHA
 * Auth: Vinicius Pinheiro
 *
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include<GL/glut.h>
#include <stdlib.h>

/* GLUT callback Handlers */


static void display(void)
{
gl_Clear( GL_COLOR_BUFFER_BIT );
gluOrtho2D(-3, 3, -3, 3);
glBegin(GL_LINES);
glVertex2f(-2, 0);
glVertex2f(2, 0);
glEnd();
glFlush;
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glClearColor(1,1,1,1);
    glutMainLoop();

    return EXIT_SUCCESS;
}

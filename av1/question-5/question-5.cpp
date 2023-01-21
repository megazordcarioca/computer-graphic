#include <GL/glut.h>

// Questão numero 5 - Viewport

float R = 0.0;
float G = 0.0;
float B = 1.0;


void retangle();
void changeScreen(GLsizei w, GLsizei h);

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    retangle();
}

void retangle()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3f(R, G, B);
    glVertex2f(2.0, 6.0);
    glVertex2f(8.0, 6.0);
    glVertex2f(8.0, 4.0);
    glVertex2f(2.0, 4.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    int mode = GLUT_RGB | GLUT_SINGLE;
    glutInitDisplayMode(mode);
    glutCreateWindow("Questao 5");
    glutInitWindowSize(500,500);
    glutDisplayFunc(Draw);
    glutReshapeFunc(changeScreen);
    glutMainLoop();
}

void changeScreen(GLsizei w, GLsizei h)
{
    if (h == 0)
    {
        h = 1;
    }
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
    {
        gluOrtho2D(0.0f, 50.0f, 0.0f, 50.0f * h/w);
    }
    else
    {
        gluOrtho2D(0.0f, 50.0f * w/h, 0.0f, 50.0f);
    }
}
#include<GL/glut.h>
#define width 400
#define height 300

GLfloat R = 1.0; 
GLfloat G = 1.0; 
GLfloat B = 1.0;
float x_inic;
float y_inic;

void move_to (GLfloat x, GLfloat y);

void line_to (GLfloat x, GLfloat y) { 
    glBegin(GL_LINES);
    glVertex2f(x_inic, y_inic); 
    glVertex2f(x, y); 
    glEnd(); 
    glFlush(); 
}

void move_to (GLfloat x, GLfloat y){ 
    x_inic = x;
    y_inic = y; 
}
void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(R,G,B); //FILL BACKGROUND WITH BLACK COLOR
    move_to(-0.3f, -0.2f);
    line_to(0.3f,0.0f);
    line_to(-0.2f, 0.3f);
    move_to (0.4f, 0.1f);
    line_to (0.2f, 0.4f);
    line_to (0.1f, -0.2f);
    move_to (0.0f, -0.3f);
    /*
     */
}

int main(GLint argc, GLchar** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Questao 3 - Testing");
    glutDisplayFunc(Draw);
    
    glutMainLoop( );
}

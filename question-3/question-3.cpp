#include<GL/glut.h>
#define width 800
#define height 600



GLfloat R = 1.0; 
GLfloat G = 1.0; 
GLfloat B = 1.0;
GLfloat x_inic;
GLfloat y_inic;

void move_to (GLfloat x, GLfloat y){ 
    x_inic = x;
    y_inic = y; 
}

void line_to (GLfloat x, GLfloat y) { 
    glBegin(GL_LINES);
    glVertex2f(x_inic, y_inic); 
    glVertex2f(x, y); 
    glEnd(); 
    move_to (x, y); 
    glFlush(); 
}

void Draw(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(R,G,B); //FILL BACKGROUND WITH BLACK COLOR
    move_to (-3.0, -2.0);
    line_to (3.0, 0.0);
    line_to (-2.0, 3.0);
    move_to (4.0, 1.0);
    line_to (2.0, 4.0);
    line_to (1.0, -2.0);
    move_to (0.0, -3.0);
}

int main(GLint argc, GLchar** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Questao 3");
    glutDisplayFunc(Draw);
    //glutReshapeFunc( reshape ); 
    //glutKeyboardFunc( key );
    //glutIdleFunc( idle ); 
    
    glutMainLoop( );
}

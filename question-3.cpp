#include <GL/glut.h>


GLfloat R = 1.0; 
GLfloat G = 1.0; 
GLfloat B = 1.0;
GLfloat x_inic;
GLfloat y_inic;

void Draw(){
    glClearColor( 0.0, 0.0, 0.0, 1.0 );     //FILL BACKGROUND WITH BLACK COLOR

}

void line_to (GLfloat x, GLfloat y) { 
    glBegin(GL_LINES);
    glVertex2f(x_inic, y_inic); 
    glVertex2f(x, y); 
    glEnd(); 
    move_to (x, y); 
    glFlush(); 
} 

void move_to (GLfloat x, GLfloat y){ 
    x_inic = x; y_inic = y; 
} 

int main(GLint argc, GLchar** argv){
    glutInit(&argc, argv);
    int mode = GLUT_SINGLE | GLUT_RGB;
    glutInitDisplayMode(mode);
    glutCreateWindow( argv[0] );

    glutDisplayFunc( Draw );
    //glutReshapeFunc( reshape ); 
    //glutKeyboardFunc( key );
    //glutIdleFunc( idle ); 
    
    glutMainLoop( );
}

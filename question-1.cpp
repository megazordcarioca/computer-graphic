#define PI 3.1415926535
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

//OpenGL - Boilerplate


float R = 1.0; 
float G = 1.0; 
float B = 1.0;
int rsize = 10;
int width = 800;
int lenght = 600;


void DrawCircle(){
  GLfloat angle = 0;       //DECLARE LOCAL FLOAT ANGLE
  int i = 0;
  GLfloat circle_pt = 100; //QUANTITY OF POINTS
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);

  //DRAW CIRCLE
  for (i = 0; i < circle_pt; i++){
    angle = 2*PI*i/circle_pt;
    glColor3ub(0,0,255);
    glVertex2f(130*cos(angle)+135, 170*sin(angle) + 140-rsize);
  }
  glEnd();

  glFlush();
}

void DrawRetangle(){
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POLYGON);
    glVertex2f(0.2,0.0);
    glVertex2f(0.8,0.0);
    glVertex2f(0.8,0.4);
    glVertex2f(0.2,0.4);
    glEnd();
    glFlush();
}

void init(){
  glClearColor(0.0,0.0,0.0,1.0);
}

void Draw(){
  //glClearColor( 0.0, 0.0, 0.0, 1.0 );     //FILL BACKGROUND WITH BLACK COLOR
    glColor3f(1.0f, 1.0f, 1.0f);
    DrawRetangle();
    //DrawLosangle();
    DrawCircle();
}

int main(GLint argc, GLchar** argv){
  glutInit(& argc, argv);
  int mode = GLUT_RGB | GLUT_DOUBLE;
  glutInitDisplayMode( mode );
  glutCreateWindow( "Bandeira do Brasil" );
  init();
  glutDisplayFunc( Draw ); 
  glutMainLoop( );
  return 0;
}

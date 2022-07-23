#define PI 3.1415926535
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

//OpenGL - Boilerplate


GLfloat R = 1.0; 
GLfloat G = 1.0; 
GLfloat B = 1.0;
GLint rsize = 10;
GLint width = 800;
GLint height = 600;


void DrawCircle(){
  GLfloat angle = 0;       //DECLARE LOCAL FLOAT ANGLE
  GLfloat circle_pt = 100; //QUANTITY OF POINTS
  int i = 0;
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
    glColor3f(0.0f,G,0.0f);
    glVertex2f(0.2,0.0);
    glVertex2f(0.8,0.0);
    glVertex2f(0.8,0.4);
    glVertex2f(0.2,0.4);
    glEnd();
    glFlush();
}

void init(){
  glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void Draw(){
  //glClearColor( 0.0, 0.0, 0.0, 1.0 );     //FILL BACKGROUND WITH BLACK COLOR
    DrawRetangle();
    //DrawLosangle();
    DrawCircle();
}

int main(GLint argc, GLchar** argv){
  glutInit(&argc, argv);
  int mode = GLUT_RGB | GLUT_DOUBLE;
  glutInitDisplayMode(mode);
  glutInitWindowSize(width,height);
  glutCreateWindow("Bandeira do Brasil");
  init();
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;
}

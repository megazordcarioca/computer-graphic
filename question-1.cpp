#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535


GLfloat R = 1.0; 
GLfloat G = 1.0; 
GLfloat B = 1.0;
GLint rsize = 10;
GLint width = 300;
GLint height = 300;


void DrawCircle(){
  GLfloat angle = 0;       //DECLARE LOCAL FLOAT ANGLE
  GLfloat circle_pt = 100; //QUANTITY OF POINTS
  int i = 0;
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glColor3f(0.0f,0.0f,B);

  //DRAW CIRCLE
  for (i = 0; i < circle_pt; i++){
    angle = 2*PI*i/circle_pt;
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

void draw(){
  glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(R,G,B);     //FILL BACKGROUND WITH BLACK COLOR

  //DrawRetangle();
  //DrawLosangle();
  DrawCircle();
}

int main(GLint argc, GLchar** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(width,height);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Bandeira do Brasil");
  glutDisplayFunc(draw);
  glutMainLoop();
  return 0;
}

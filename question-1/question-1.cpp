#include <GL/glut.h>
#include <math.h>

#define PI 3.141593
#define CIRCUNFERENCE 360

GLfloat R = 1.0; 
GLfloat G = 1.0; 
GLfloat B = 1.0;
GLint width = 300;
GLint height = 300;


void DrawCircle(){           //BLUE CIRCLE

  GLfloat x,y,r,ini_x, ini_y,angle;
  GLfloat circle_pt = 100;  //QUANTITY OF POINTS

  ini_x = 0.0;
  ini_y = 0.0;
  r = 0.25;

  glColor3f(0.0f,0.0f,B); //DRAW IN BLUE COLOR
  glBegin(GL_LINE_LOOP);     //START TO DRAW
  for (int i = 0; i < CIRCUNFERENCE; i++){
    angle = (i*PI)/(CIRCUNFERENCE/2);
    x = ini_x+(cos(angle)*r);
    y = ini_y+(sin(angle)*r);
    glVertex2f(x,y);
  }
  glEnd();
  glFlush();
}


void DrawRetangle(){     //GREEN RETANGLE
  glColor3f(0.0,G,0.0);

  glBegin(GL_POLYGON);
    glVertex2f(-1.0,  0.5);
    glVertex2f(-1.0, -0.5);
    glVertex2f(1.0,  -0.5);
    glVertex2f(1.0,   0.5);
  glEnd();
}

void DrawLosangle(){    //YELLOW LOSANGLE
  glColor3f(R, G, 0.0);
  glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.40);
	glVertex2f(-1.0, 0.0);
	glVertex2f(0.0, -0.40);
	glVertex2f(1.0, 0.0);
  glEnd();
}

void draw(){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(R,G,B);     //FILL BACKGROUND WITH BLACK COLOR
  DrawRetangle();
  DrawLosangle();
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

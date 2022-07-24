#include <GL/glut.h>

//DEFININDO VETOR PRINCIPAL

#define translateX  0.2
#define translateY  0.-3
#define translateZ  0.0

//PONTOS: P1 - 2,4 / P2 - 8,4 / P3 - 8,6 / P4 - 2,6
float R = 0.0;
float G = 1.0;
float B = 0.0;

void retangle(){
  glBegin(GL_POLYGON);
  glColor3f(R,G,B);
  glVertex2f(0.2, 0.6);
  glVertex2f(0.8, 0.6);
  glVertex2f(0.8, 0.4);
  glVertex2f(0.2, 0.4);
  glEnd();
  glFlush();
}

void render(){
  glClearColor(0.0,0.0,0.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glRotatef(90,0,0,1);
  retangle();
  glScalef(3.5,1.5,0.0);
  glTranslatef(translateX, translateY, translateZ);
  glColor3f(R=1.0,0.0,B);
  retangle();
 }

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(300,300);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Questao 4");
  glutDisplayFunc(render);
  glutMainLoop();
  return 0;
}

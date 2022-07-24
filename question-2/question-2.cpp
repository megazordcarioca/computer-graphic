#define LINES 32
#define COLUMNS 2 
#include <GL/glut.h> //using
#include <stdio.h>
#include <stdlib.h>

int** ReadFile(const char* fileName, int lines, int columns)
{
    FILE* file = fopen(fileName, "r");
    int i = 0;
    int** numbers = (int**)malloc(lines * sizeof(int));
    for (int i = 0; i < lines; i++) 
    {
        numbers[i] = (int*)malloc(columns * sizeof(int));
    }

    int countColumns = 0;
    int countLines = 0;
    fscanf(file, "%d", &i);
    while (!feof(file))
    {
        if (countColumns >= columns) {
            countColumns = 0;
            countLines++;
        }
        if (countColumns < columns)
        {
            numbers[countColumns][countLines] = i;
            countLines++;
        }
        //printf("%d ", &i);
        fscanf(file, "%d", &i);
    }
    fclose(file);

    return numbers;
}

void Outline() 
{
    int** numbers = ReadFile("Contorno.txt", LINES, COLUMNS);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < LINES; i++) 
    {
      glVertex2f(numbers[i][0], numbers[i][1]);
    }
    glEnd();
    glFlush();
}

void Draw()
{
    float ang;
    int i;
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    Outline();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    int mode = GLUT_SINGLE;
    glutInitDisplayMode(mode);
    glutInitWindowSize(300,300);
    glutCreateWindow("Image");
    glutDisplayFunc(Draw);
    //gluOrtho2D(0.0f, 128, 0.0f,128.0f);
    glutMainLoop();
    
    return 0;
} 

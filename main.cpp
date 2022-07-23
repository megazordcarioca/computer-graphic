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
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < LINES; i++) 
    {
        glVertex2f(numbers[i][0], numbers[i][1]);
    }
    glEnd();
}

void Draw()
{
    float ang;
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    Outline();
    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 0);
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    int mode = GLUT_RGB | GLUT_DOUBLE;
    glutInitDisplayMode(mode);
    glutInitWindowSize(256, 256);
    glutCreateWindow("Image");
    init();
    glutDisplayFunc(Draw);
    gluOrtho2D(0.0f, 128, 0.0f,128.0f);
    glutMainLoop();
    
    return 0;
} 
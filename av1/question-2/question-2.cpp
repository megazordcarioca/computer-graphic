#define WIDHT 128
#define HEIGHT 128

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>


int **coordenatesList;
GLint listSize = 0;

char *DELIMITER = " ";
char *fileName = "Contorno.txt";

GLfloat R = 1.0;
GLfloat G = 1.0;
GLfloat B = 1.0;
GLfloat A = 1.0;

FILE* readFile(){
    FILE *file;
    file = fopen(fileName, "r");
    if (file == NULL){
        printf("Error while try to open file");
        exit(1);
    }
    return file;
}

void closeFile(FILE* file){
    fclose(file);
}

void defaultConfig(GLint maxValue){
    GLint negativeValue = maxValue * -1;
    glClearColor(R,G,B,A);
    gluOrtho2D(negativeValue, maxValue, negativeValue, maxValue);
}

/*void makeOutline() 
{
    GLint **pointer = coordenatesList;
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < listSize; i++) 
    {
        glVertex2i(pointer[i][0], pointer[i][1]);
    }
    glEnd();
    glFlush();
}*/

void Draw()
{
    int **pointer = coordenatesList;
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //makeOutline();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < listSize; i++) 
    {
        glVertex2f(pointer[i][0], pointer[i][1]);
    }
    glEnd();
    glFlush();
}

int getMaxValueFromCoordenates(){
    int maxValue = 0;
    int** pointer = coordenatesList;

    for (int index = 0; index < listSize;index++){
        for (int i=0;i<=1;i++){ 
            if (pointer[index][i] > maxValue){
                maxValue = pointer[index][i];
            }
        }
    }
    
    return maxValue;
}

void analyseCoordenatesFromFile(){
    char row[50];
    char *str;
    FILE *file = readFile();

    int count = 0;
    coordenatesList = (int **)malloc(10 * sizeof(int*));

    while((fgets(row,50,file)) != NULL){
        int x, y;
        int* coordenates = (int *)malloc(2 * sizeof(int));
        bool updated = 0;

        str = strtok(row, DELIMITER);
        while(str!=NULL){
            if(updated == 0)
                x = atoi(str); 
            else
                y = atoi(str);
            updated = 1;
            str = strtok(NULL, DELIMITER);
        }

        if((count+1) % 10 == 0){
          coordenatesList = realloc(coordenatesList,(count + 11) *sizeof(int*));
        }

        coordenates[0] = x;
        coordenates[1] = y;

        coordenatesList[count] = coordenates;
        count++;
    }
    listSize = count;
    closeFile(file);
}


int main(int argc, char** argv)
{
    analyseCoordenatesFromFile();
    int maxValue = getMaxValueFromCoordenates();
    glutInit( &argc, argv );
    int mode = GLUT_SINGLE;
    glutInitDisplayMode(mode);
    glutInitWindowSize(WIDHT, HEIGHT);
    glutCreateWindow("Questao 2");
    glutDisplayFunc(Draw);
    defaultConfig(maxValue);
    //gluOrtho2D(0.0f, 128, 0.0f,128.0f);
    glutMainLoop();
    
    return 0;
} 

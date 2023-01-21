#include <GL/glut.h>
static int year = 0, day = 0, wire = 0;
/* Define o modelo de cores a ser utilizado
GL_FLAT : a cor não varia na primitiva que é desenhada */
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}
/*
Função responsável pelo desenho das esferas.
Nesta função também serão aplicadas as tranformações
necessárias para o efeito desejado.
*/
void display(void)
{
    /*
    Limpa o buffer de pixels e
    determina a cor padrão dos objetos.
    */
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    /* Verifica se o grau de rotacao do ano é maior que 245
    67
    esta verificação é necessária para que, quando a esfera menor
    estiver atras da maior a mesma não sobreponha o desenho desta, o else
    deste if inverte a ordem de apresentação das esferas*/
    if (year < 245)
    {
        /* Armazena a situação atual da pilha de matrizes */
        glPushMatrix();
        glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
        glTranslatef(2.0, 0.0, 0.0);
        glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        /* Se a tecla w for pressionada irá fazer o controle
        do tipo de apresentação de sólido ou Wire (aramado) */
        if (wire == 0)
            glutSolidSphere(0.2, 10, 8);
        else
            glutWireSphere(0.2, 10, 8);
        /*Descarrega a pilha de matrizes até o último glPushMatrix */
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.89, 0.79, 0.09);
        if (wire == 0)
            glutSolidSphere(1.0, 20, 16);
        else
            glutWireSphere(1.0, 20, 16);
        glPopMatrix();
    }
    else
    {
        glPushMatrix();
        glColor3f(0.89, 0.79, 0.09);
        if (wire == 0)
            glutSolidSphere(1.0, 20, 16);
        else
            glutWireSphere(1.0, 20, 16);
        glPopMatrix();
        glPushMatrix();
        glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
        glTranslatef(2.0, 0.0, 0.0);
        glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        if (wire == 0)
            glutSolidSphere(0.2, 10, 8);
        else
            glutWireSphere(0.2, 10, 8);
        glPopMatrix();
    }
    // Executa os comandos
    glutSwapBuffers();
}
/*
Função responsável pelo desenho da tela
Nesta função são determinados o tipo de Projeção
o modelo de Matrizes e
a posição da câmera
Quando a tela é redimensionada os valores
da visão perspectiva são recalculados com base no novo tamanho da tela
68
assim como o Viewport
*/
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
/* Função responsável pelo controle de teclado
quando pressionada a tecla d, será executada uma rotação no
próprio eixo da esfera menor. Quando pressionada a tecla y
a esfera menor irá rotacionar em torno da esfera maior, em uma
órbida determinada na translação na função display()
A tecla w é responsável por determinar se as esferas serão sólidas
ou aramadas (wire)
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
    case 'D':
        day = (day + 10) % 360;
        glutPostRedisplay();
        break;
    case 'Y':
    case 'y':
        year = (year + 5) % 360;
        glutPostRedisplay();
        break;
    case 'w':
    case 'W':
        wire = wire == 1 ? 0 : 1;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}
/*
Esta função é chamada quando o botão esquerdo do
mouse é pressionado, a mesma irá calcular um novo
valor para os valores dos ângulos contidos em year e day
*/
void spinDisplay(void)
{
    year = (year + 1) % 360;
    day = (day + 2) % 360;
    glutPostRedisplay();
}
/*
Esta função irá controlar os botões do mouse.
Se pressionado o botão da esquerda ela define
a função spinDisplay como a função de "idle" do GLUT
o comando glutIdelFunc, executa uma determinada função quando
nenhum evento estiver ocorrendo. (pressionamento de botões etc.)
Quando o botão do meio é pressionado a função de Idle recebe NULL
desabilitando a animação
*/
void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
        break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}
/*
Função principal do programa.
*/
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("AV2 - SIMULAÇÃO PLANETÁRIA");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
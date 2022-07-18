#include <C:\Users\003908631\Desktop\CG\glut\glut.h>

//Exercio numero 5 - Viewport


float R = 1.0; 
float G = 1.0; 
float B = 1.0;

void Draw(){
    glClearColor( 0.0, 0.0, 0.0, 1.0 );

}

int main(int argc, char** argv){
    int mode = GLUT_RGB | GLUT_DOUBLE;glutInitDisplayMode( mode );
    glutCreateWindow( argv[0] );  
    init( );

    glutDisplayFunc( Draw );
    //glutReshapeFunc( reshape ); 
    //glutKeyboardFunc( key );
    //glutIdleFunc( idle ); 
    
    glutMainLoop( );
}


voic changeScreen(GLsizei w, GLsizei h){
    if(h == 0){
        h = 1;
    }
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h){
        gluOrtho2D(0.0f,50.0f,0.0f, 50.0f*h/w);
    }else{
        
        gluOrtho2D(0.0f,50.0f*w/h,0.0f,50.0f);
    }
}
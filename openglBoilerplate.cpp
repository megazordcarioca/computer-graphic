#include <C:\Users\003908631\Desktop\CG\glut\glut.h>

//OpenGL - Boilerplate


float R = 1.0; 
float G = 1.0; 
float B = 1.0;

void Draw(){
    glClearColor( 0.0, 0.0, 0.0, 1.0 );     //FILL BACKGROUND WITH BLACK COLOR

}

int main(int argc, char** argv){
    int mode = GLUT_RGB | GLUT_DOUBLE;glutInitDisplayMode( mode );
    glutCreateWindow( argv[0] );  
    init();

    glutDisplayFunc( Draw );
    //glutReshapeFunc( reshape ); 
    //glutKeyboardFunc( key );
    //glutIdleFunc( idle ); 
    
    glutMainLoop( );
}

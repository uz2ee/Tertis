#include <iostream>
#include <string>
using namespace std;
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#define PI 3.14159265358979323846
#include<math.h>

float xpos = 0 , ypos = 1;
bool taken [30][30] ;
int speed = 800;

void background_cloud()
{

    /// background

     int sky_colors_array [26][3]= {
            {245,223,173 },
            {245,225,175 },
            {246,226,178 },
            {247,229,180} ,
            {247,230,185} ,
            {248,232,190 },
            {248,234,195 },
            {249,236,200 },
            {249,238,205 },
            {250,240,210 },
            {251,242,215},
            {252,244,220} ,
            {253,247,226 },
            {253,247,232 },
            {254,247,236 },
            {254,248,240},
            {248,248,242 },
            {249,249,243 },
            {249,249,244 },
            {250,250,245 },
            {251,250,246},
            {252,251,247} ,
            {253,252,248 },
            {253,253,250 },
            {254,254,252 },
            {254,255,254}
    };

    ///draw sky

    float sky_color_band_width = 0.07 ; ///Width of each band
    float sky_position = 1; ///variable for each sky color band Y position

    for(auto i : sky_colors_array){
            glBegin(GL_QUADS);
            glColor3ub(i[0],i[1],i[2]);
            glVertex2f(-1 , sky_position);
            glVertex2f(-1 , sky_position-sky_color_band_width);
            glVertex2f(1 , sky_position-sky_color_band_width);
            glVertex2f(1 , sky_position);
            glEnd();

            sky_position = sky_position - sky_color_band_width;

    }



    ///cloud on sky



    // glColor3ub(251,240,208);
    GLfloat twicePi = 2.0f * PI;
    GLfloat cx=-0.7f; GLfloat cy=0.6f;

    GLfloat  cloudradius =.2f;
	int cloudTriangleAmount = 30; //# of triangles used to draw circle

		glBegin(GL_TRIANGLE_FAN);
		  glColor3ub(251,240,208);
		glVertex2f(cx, cy); // center of circle

		for(int i = 0; i <= cloudTriangleAmount;i++) {
			glVertex2f(
		            cx + (cloudradius * cos(i *  twicePi / cloudTriangleAmount)),
			    cy + (cloudradius * sin(i * twicePi / cloudTriangleAmount))
			);
		}
	glEnd();


	cx=-0.9f;  cy=0.6f;
	cloudradius =.3f;

	glBegin(GL_TRIANGLE_FAN);
	  glColor3ub(251,240,208);
		glVertex2f(cx, cy); // center of circle

		for(int i = 0; i <= cloudTriangleAmount;i++) {
			glVertex2f(
		            cx + (cloudradius * cos(i *  twicePi / cloudTriangleAmount)),
			    cy + (cloudradius * sin(i * twicePi / cloudTriangleAmount))
			);
		}
	glEnd();





		cx=0.4f;  cy=0.8f;
	cloudradius =.2f;

    glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cx, cy); // center of circle
		  glColor3ub(251,240,208);
		for(int i = 0; i <= cloudTriangleAmount;i++) {
			glVertex2f(
		            cx + (cloudradius * cos(i *  twicePi / cloudTriangleAmount)),
			    cy + (cloudradius * sin(i * twicePi / cloudTriangleAmount))
			);
		}
	glEnd();

    cx=0.1f;  cy=0.6f;
	cloudradius =.3f;

    glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cx, cy); // center of circle
	 glColor3ub(251,240,208);
		for(int i = 0; i <= cloudTriangleAmount;i++) {
			glVertex2f(
		            cx + (cloudradius * cos(i *  twicePi / cloudTriangleAmount)),
			    cy + (cloudradius * sin(i * twicePi / cloudTriangleAmount))
			);
		}
	glEnd();

    cx=0.3f;  cy=0.5f;
	cloudradius =.2f;

    glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cx, cy); // center of circle
		 glColor3ub(251,240,208);
		for(int i = 0; i <= cloudTriangleAmount;i++) {
			glVertex2f(
		            cx + (cloudradius * cos(i *  twicePi / cloudTriangleAmount)),
			    cy + (cloudradius * sin(i * twicePi / cloudTriangleAmount))
			);
		}
	glEnd();


    cx=0.6f;  cy=0.6f;
	cloudradius =.23f;

    glBegin(GL_TRIANGLE_FAN);
		glVertex2f(cx, cy); // center of circle
		glColor3ub(251,240,208);
		for(int i = 0; i <= cloudTriangleAmount;i++) {
			glVertex2f(
		            cx + (cloudradius * cos(i *  twicePi / cloudTriangleAmount)),
			    cy + (cloudradius * sin(i * twicePi / cloudTriangleAmount))
			);
		}
	glEnd();

}


void bottom_grass(){

    glBegin(GL_QUADS);
            glColor3ub(98,147,38);
            glVertex2f(-1 , -.9);
            glVertex2f(-1 , -1);
            glVertex2f(1 , -1);
            glVertex2f(1 , -.9);
    glEnd();

}
float move_right( float x ){
 if (x <1.0 and x> -1.0)
 {
     x = x+ 0.1 ;
 }
 return x;
}
float move_left( float x ){
 if (x <1.0 and x> -1.0)
 {
     x = x- 0.1 ;
 }
 return x;
}
void draw_quad(float x , float y , int color){

    /// quad positions
    float x1 , y1 , x2 ,y2 ;


    x1 = x ; y1 = y ;
    x2 = x + 0.1 ; y2 = y1 - 0.1 ;


    glBegin(GL_QUADS);
            glColor3ub(157,192,46);
            glVertex2f(x1 , y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2 ,y1);
    glEnd();

}
void display()
{

     ///dont touch
    glClearColor(1.0f ,1.0f ,1.0f ,0.0f  );
    glClear(GL_COLOR_BUFFER_BIT);


    background_cloud();
    draw_quad(xpos , ypos , 1);

        for( int i = 1 ; i<20 ; i++){

        for (int j = 1 ; j<20 ; j++ )
    {
       // cout<<taken[i][j];
        if (taken[i][j]){
                float iix , iiy ;

                if (i>9){
                    iix = (i - 10) / 10.0;
                }
                else iix = -(10- i ) / 10.0 ;

                  if (j>9){
                    iiy = (j - 10) / 10.0;
                }
                else iiy = -(10- j ) / 10.0 ;


                cout <<"drawing " <<i <<" "<<iix <<" " <<  j <<" " <<iiy <<endl;
            draw_quad(  iix, iiy , 1);
        }

    }
      cout<<endl;
    }



    //bottom_grass();
    glFlush();


}
void SpecialInput(int key, int x, int y)
{
    switch(key)
        {case GLUT_KEY_UP:

            break;
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:
            if (xpos >-1){
                xpos = xpos - .1;
            }

            break;
        case GLUT_KEY_RIGHT:
            if (xpos <.9){
                xpos = xpos + .1;
            }

            break;}
    glutPostRedisplay();

}



int convert_to_axis(float var){
    if (var<=0 ){
        var = 1+var;
    }
    else
        var+=1.0;
    return int(var*10);

}

void new_object()
{
    xpos= 0 ;
    ypos = 1;
}

bool valid(float x , float y){

    int ix = convert_to_axis(x);
    int iy = convert_to_axis(y);

 cout<<ix <<" " <<iy<<"ix iy"<<endl;

    if (taken[ix][iy]){
             cout<<ix <<" " <<iy<<"ix ______ iy"<<endl;
        return false;
    }
    return true;
}
void print_matrix()
{
    for( int i = 1 ; i<20 ; i++){

        for (int j = 1 ; j<20 ; j++ )
    {
        cout<<taken[i][j];
        }
        cout<<endl;

    }



    cout <<endl;


}

void update(int x ){

    print_matrix();

    if (ypos>-.80 )
    {

            ypos-=.1;


    }
    else {


    int ix = convert_to_axis(xpos);
    int iy = convert_to_axis(ypos);
    cout<<"second"<<endl;
        cout<<ix<<iy<<endl;

    taken[ix][iy] = true;
    new_object();
    }
    cout<<ypos<<" "<<xpos<<" current ypos  xpos " <<endl ;
glutPostRedisplay();

glutTimerFunc(speed, update , 0 );
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Tertis");
    glutInitWindowSize(640,880);
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialInput);
    glutTimerFunc(speed, update , 0 );

    glutMainLoop();

    return 0;
}

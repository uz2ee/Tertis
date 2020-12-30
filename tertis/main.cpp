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

float xpos = 1 , ypos = 0, type = 0;
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
void draw_quad(float x , float y , int type){

    /// quad positions
    float x1 , y1 , x2 ,y2 ;


    x1 = x ; y1 = y ;
    x2 = x + 0.1 ; y2 = y1 - 0.1 ;


    glBegin(GL_QUADS);
            glColor3ub(20,192,46);
            glVertex2f(x1 , y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2 ,y1);
    glEnd();

    if (type==1){
        x= x+.1;
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

}
void display()
{

     ///dont touch
    glClearColor(1.0f ,1.0f ,1.0f ,0.0f  );
    glClear(GL_COLOR_BUFFER_BIT);


    background_cloud();

    glTranslatef(-1,1,0);
    draw_quad(xpos , ypos , type);
    cout<<xpos<<" "<<ypos<<endl;

        for( int i = 0 ; i<20 ; i++){

        for (int j = 0 ; j<20 ; j++ )
    {
       // cout<<taken[i][j];
        if (taken[i][j]){

              //  cout<<i/10.0 << j/10.0<<endl;
            draw_quad(  float(i)/10.0, float(-j)/10.0 , 0); // type = 0  because it will print only one tile
        }

    }

    }

    glLoadIdentity();

    bottom_grass();
    glFlush();


}
void SpecialInput(int key, int x, int y)
{
    switch(key)
        {case GLUT_KEY_UP:
            if(speed>100)

            speed -= 100;
            cout<<"speed"<<speed<<endl;

            break;
        case GLUT_KEY_DOWN:
             if(speed<3000)

            speed += 100;
            cout<<"speed"<<speed<<endl;

            break;
        case GLUT_KEY_LEFT:
            if (xpos >0){
                xpos = xpos - .1;
            }

            break;
        case GLUT_KEY_RIGHT:
            if (xpos <1.9){
                xpos = xpos + .1;
            }

            break;}
    glutPostRedisplay();

}



int convert_to_axis(float var){
    cout<<"calling";
    if (var<=0 ){
        var = 1.00003+var;
    }
    else
        var+=1.00003;
    return int(var*10);

}

void new_object()
{
    xpos= 1 ;
    ypos = 0;
    type= 0;
  //  cout<<type<<endl;
}


void print_matrix()
{
    for( int i = 0 ; i<21 ; i++){

        for (int j = 0 ; j<21 ; j++ )
    {
        cout<<taken[j][i];
        }
        cout<<endl;

    }
    cout <<endl;

}

void update(int x ){


    print_matrix();
     cout<<xpos<<" "<<ypos<<" current ypos  xpos " <<endl ;




    if (ypos>-1.80 )
    {

        if(type==0){ /// _

            ///if next not empty

                    float next_ypos = ypos-0.10000000000 ;
                    int nix = int(xpos*10.0) + (xpos<1.0) - (xpos<0.1);
                    int niy = int(next_ypos*10.0) ;

                    if ( taken[nix][-niy])
                    {
                            int ix = int(xpos*10.000) + (xpos<1.0);
                            int iy = int(ypos*10.000);

                            cout <<ix << " adding enw object "<<iy <<endl;
                            taken[ix][-iy] = true;
                            new_object();
                    }
                    else
                    {
                            ypos-=.1;
                    }

        }

        else if (type == 1 ){
                    float next_ypos = ypos-.1 ;
                    int nix1 = int(xpos*10) + (xpos<1.0) ;
                    int nix2 = int((xpos+.1000001)*10) + (xpos<1.0);
                    int niy = int(next_ypos*10.0);

                    if ( taken[nix1][-niy] or taken[nix2][-niy])
                    {
                            int ix1 = int(xpos*10) + (xpos<1.0);
                            int iy = int(ypos*10)  ;
                            int ix2 = int((xpos+.1000001)*10);
                            taken[ix1][-iy] = true;
                            taken[ix2][-iy] = true;

                            cout<<" ix1 " <<ix1 <<" ix2 "<<ix2<<endl;

                            new_object();
                    }
                    else
                    {
                            ypos-=.1;
                    }

        }
    }
    else {

              if(type==0){  /// _
                            cout<<xpos<<" "<<ypos<<" current ypos  xpos " <<endl ;




                            int ix = int(xpos*10.0)+  (xpos<1.0) - (xpos<0.1);
                            int iy = int(ypos*10.0);
                            cout<<"second"<<endl;


                            cout <<ix << " adding enw object "<<iy <<endl;

                            taken[ix][-iy] = true;
                            new_object();
            }
            else if (type==1){    ///    __
                            int ix1 = int(xpos*10);
                            int iy =int(ypos*10);
                            int ix2 = int((xpos+.1000001)*10);
                            taken[ix1][-iy] = true;
                            taken[ix2][-iy] = true;

                            new_object();
            }
    }

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

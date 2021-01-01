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

float xpos = 1 , ypos = 0, type = 3;
bool taken [30][30] ;
int speed = 800;
bool game_over = false ;
int score = 0 ;
int final_score = 0;
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

void draw_quad(float x , float y , int type){

    /// quad positions
    float x1 , y1 , x2 ,y2 ;


    x1 = x ; y1 = y ;
    x2 = x + 0.1 ; y2 = y1 - 0.1 ;


    glBegin(GL_QUADS);
    if (type==99)
            glColor3ub(20,192,46);
            else             glColor3ub(157,192,46);
            glVertex2f(x1 , y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2 ,y1);
    glEnd();

        if (type==3){

       glBegin(GL_QUADS);
         glColor3ub(157,192,46);
            glVertex2f(x1 , y1+.1);
            glVertex2f(x1,y2+.1);
            glVertex2f(x2,y2+.1);
            glVertex2f(x2 ,y1+.1);
    glEnd();

    }



    if (type==1){
        x= x+.1;
        x1 = x ; y1 = y ;
    x2 = x + 0.1 ; y2 = y1 - 0.1 ; ///extre x2 at .1 width distance
             glBegin(GL_QUADS);
            glColor3ub(157,192,46);
            glVertex2f(x1 , y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2 ,y1);
    glEnd();

    }
    if (type==2){
        x= x+.1;
        x1 = x ; y1 = y ;
    x2 = x + 0.2 ; y2 = y1 - 0.1 ;   /// x2 = .2 width distance
             glBegin(GL_QUADS);
            glColor3ub(157,192,46);
            glVertex2f(x1 , y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2 ,y1);
    glEnd();

    }
    if (type==4){
        float ax= x+.1;
        x1 = ax ; y1 = y  ;
    x2 = ax + 0.1 ; y2 = y1 + 0.1 ; ///extre x2 at .1 width distance
             glBegin(GL_QUADS);
            glColor3ub(157,192,46);
            glVertex2f(x1 , y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2 ,y1);
    glEnd();
     x= x+.1;
        x1 = x ; y1 = y ;
    x2 = x + 0.1 ; y2 = y1 - 0.1 ; ///extre x2 at .1 width distance
             glBegin(GL_QUADS);
            glColor3ub(157,192,46);
            glVertex2f(x1 , y1);
            glVertex2f(x1,y2);
            glVertex2f(x2,y2);
            glVertex2f(x2 ,y1);
    glEnd();



    cout <<x1 <<" " << y1 <<" " <<" " <<x2 <<" ----  " <<y2;
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
            draw_quad(  float(i)/10.0, float(-j)/10.0 , 99); // type = 99   it will print only one tile
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
             type = rand()%5;
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
            if (xpos <1.9 and type==0){
                xpos = xpos + .1;
            }
            if (xpos <1.9 and type==3){
                xpos = xpos + .1;
            }
            if (xpos <1.8 and type==1)
            {
                  xpos = xpos + .1;
            }
            if (xpos <1.7 and type==2)
            {
                  xpos = xpos + .1;
            }
             if (xpos <1.8 and type==4)
            {
                  xpos = xpos + .1;
            }
            break;}
    glutPostRedisplay();

}





void new_object()
{

    xpos= 1 ;
    ypos = 0;
    type= rand()%5;

}

void delete_row(int i){

    cout << "deleting I "<<i<<endl;
    for (int ex = 0 ; ex< 21; ex++  )
            {
                taken[ex][i] = false ;
            }
            for (int bq = 0 ; bq < 21 ; bq++ )

            {
                for (int p = i ;p >0 ; p-- )
                {
                   // cout<<"q p" <<q <<p <<"      " ;
                    taken[bq][p] = taken[bq][p-1];
                }
                cout <<endl;
            }

}


void print_matrix()
{
    for( int i = 0 ; i<21 ; i++){

        for (int j = 0 ; j<21 ; j++ )
    {
        //if (taken[j][i])
     //   cout<< taken[j][i]<< j<< i <<" _ "  ;
        }
      //  cout<<endl;

    }

    int cnt = 0 ;



    if (game_over){ cout<<"Game over \n Final score !" <<final_score ;
    cout <<endl;

    }

    for( int j = 0 ; j < 21 ;j ++ )
    {
        if (taken[j][0]){
            game_over = true;
            final_score = score ;
        }
    }

    for( int i = 0 ; i < 21 ;i ++ ){

        int freq = 0 ;

        for( int j = 0 ; j < 21 ;j ++ )
        {
            freq = taken[j][i]  + freq;
        }

      //  cout<< i <<" rows " << freq <<endl;

        if (freq >=20 )
        {
           // cout<<"deleting " ;
            delete_row(i);
            cnt++;
        }
}

score+= cnt * 10 ;

cout<<"Score : " <<score<<endl;
}


void update(int x ){


    print_matrix();
  //   cout<<xpos<<" "<<ypos<<" current ypos  xpos " <<endl ;

    if (ypos>-1.80 )
    {

        if(type==0){ /// _

            ///if next not empty

                    float next_ypos = ypos-0.10000000000 ;
                    int nix = int(xpos*10.0) + (xpos<1.0) - (xpos<0.0999);
                    int niy = int(next_ypos*10.0) ;

                    if ( taken[nix][-niy])
                    {
                            int ix = int(xpos*10.000) + (xpos<1.0) - (xpos<0.0999); /// for zero < 009 for < 0.9 rounding <1.o
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
        else if(type==3){ /// _

            ///if next not empty

                    float next_ypos = ypos-0.10000000000 ;
                    int nix = int(xpos*10.0) + (xpos<1.0) - (xpos<0.0999);
                    int niy = int(next_ypos*10.0) ;

                    if ( taken[nix][-niy])
                    {
                            int ix = int(xpos*10.000) + (xpos<1.0) - (xpos<0.0999); /// for zero < 009 for < 0.9 rounding <1.o
                            int iy = int(ypos*10.000);

                            cout <<ix << " adding enw object "<<iy <<endl;
                            taken[ix][-iy] = true;
                            taken[ix][-iy - 1] = true;
                            new_object();
                    }
                    else
                    {
                            ypos-=.1;
                    }

        }

        else if (type == 1 ){
                    float next_ypos = ypos-.1 ;
                    int nix1 = int(xpos*10) + (xpos<1.0) - (xpos<0.0999) ;
                    int nix2 = nix1+1;
                    int niy = int(next_ypos*10.0);

                    if ( taken[nix1][-niy] or taken[nix2][-niy])
                    {

                        int enpos = int(ypos*10.0);

                            taken[nix1][-enpos] = true;
                            taken[nix2][-enpos] = true;

                            cout<<" nix1 " <<nix1<<" yopos" <<enpos<<endl <<" nix2 "<<nix2<<endl;

                            new_object();
                    }
                    else
                    {
                            ypos-=.1;
                    }

        }

                else if (type == 2 ){
                    float next_ypos = ypos-.1 ;
                    int nix1 = int(xpos*10) + (xpos<1.0) - (xpos<0.0999) ;
                    int nix2 = nix1+1;
                    int nix3 = nix1+2;
                    int niy = int(next_ypos*10.0);

                    if ( taken[nix1][-niy] or taken[nix2][-niy] or taken[nix3][-niy])
                    {

                        int enpos = int(ypos*10.0);

                            taken[nix1][-enpos] = true;
                            taken[nix2][-enpos] = true;
                            taken[nix3][-enpos] = true;

                            cout<<" nix1 " <<nix1<<" yopos" <<enpos<<endl <<" nix2 "<<nix2<<endl;

                            new_object();
                    }
                    else
                    {
                            ypos-=.1;
                    }

        }

        else if (type == 4 ){
                    float next_ypos = ypos-.1 ;
                    int nix1 = int(xpos*10) + (xpos<1.0) - (xpos<0.0999) ;
                    int nix2 = nix1+1;
                    int niy = int(next_ypos*10.0);

                    if ( taken[nix1][-niy] or taken[nix2][-niy])
                    {

                        int enpos = int(ypos*10.0);

                            taken[nix1][-enpos] = true;
                            taken[nix2][-enpos] = true;
                            taken[nix2][-enpos-1] = true;


                            cout<<" nix1 " <<nix1<<" yopos" <<enpos<<endl <<" nix2 "<<nix2<<endl;

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




                            int ix = int(xpos*10.0)+  (xpos<1.0) - (xpos<0.099); /// for zero < 009 for < 0.9 rounding <1.o
                            int iy = int(ypos*10.0);
                            cout<<"second"<<endl;


                            cout <<ix << " adding enw object "<<iy <<endl;

                            taken[ix][-iy] = true;
                            new_object();
            }
            else if(type==3){  /// _
                            cout<<xpos<<" "<<ypos<<" current ypos  xpos " <<endl ;




                            int ix = int(xpos*10.0)+  (xpos<1.0) - (xpos<0.099); /// for zero < 009 for < 0.9 rounding <1.o
                            int iy = int(ypos*10.0);
                            cout<<"second"<<endl;


                            cout <<ix << " adding enw object "<<iy <<endl;

                            taken[ix][-iy] = true;
                            taken[ix][-iy - 1] = true;
                            new_object();
            }
            else if (type==1){    ///
                            int nix1 = int(xpos*10) + (xpos<1.0) - (xpos<0.0999) ;
                    int nix2 = nix1+1;
                            int iy = int(ypos*10.0);

                            taken[nix1][-iy] = true;
                            taken[nix2][-iy] = true;

                            cout<<" nix1 " <<nix1<<" yopos" <<iy<<endl <<" nix2 "<<nix2<<endl;

                            new_object();
            }
            else if (type==2){    ///    __
                            int nix1 = int(xpos*10) + (xpos<1.0) - (xpos<0.0999) ;
                    int nix2 = nix1+1;
                    int nix3 = nix2+1;
                            int iy = int(ypos*10.0);
                            taken[nix1][-iy] = true;
                            taken[nix2][-iy] = true;
                            taken[nix3][-iy] = true;
                            cout<<" nix1 " <<nix1<<" yopos" <<iy<<endl <<" nix2 "<<nix2<<endl;
                            new_object();
            }
            else if (type==4){    ///    __
                            int nix1 = int(xpos*10) + (xpos<1.0) - (xpos<0.0999) ;
                    int nix2 = nix1+1;
                            int iy = int(ypos*10.0);

                            taken[nix1][-iy] = true;
                            taken[nix2][-iy] = true;
                            taken[nix2][-iy - 1] = true;

                            cout<<" nix1 " <<nix1<<" yopos" <<iy<<endl <<" nix2 "<<nix2<<endl;

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

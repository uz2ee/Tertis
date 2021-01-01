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
#include <bits/stdc++.h>

float xpos = 1 , ypos = 0, type = 3;
bool taken [30][30] ;
int speed = 1200;
bool game_over = false ;
int escore = 0 ;
int final_score = 0;
GLfloat ii = 0.0;
const int colorRed = 255;
const int colorGreen = 0;
const int colorBlue = 0;
bool startMusic = true;
bool playing = true ;

string toStr(int x)
{
    string s = "";
	if (x == 0) return "0";
	while(x > 0)
	{
		s = (char)('0' + (x % 10)) + s;
		x /= 10;
	}
	return s;
}


void playSound()
{
    PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void pauseSound()
{
    PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
}

void scoreText()
{
    glLoadIdentity();
    glTranslatef(-0.8f,0.8f,0.0f); // S
    glBegin(GL_LINES);
    glColor3ub(colorRed,colorGreen,colorBlue);
    glVertex2f(0.1,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.05);
    glVertex2f(0.0,0.05);
    glVertex2f(0.1,0.05);
    glVertex2f(0.1,0.05);
    glVertex2f(0.1,0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.675f,0.8f,0.0f); // C
    glBegin(GL_LINES);
    glColor3ub(colorRed,colorGreen,colorBlue);
    glVertex2f(0.1,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.55f,0.8f,0.0f); // O
    glBegin(GL_LINES);
    glColor3ub(colorRed,colorGreen,colorBlue);
    glVertex2f(0.1,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.0);
    glVertex2f(0.1,0.0);
    glVertex2f(0.1,0.1);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.425f,0.8f,0.0f); // R
    glBegin(GL_LINES);
    glColor3ub(colorRed,colorGreen,colorBlue);
    glVertex2f(0.1,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,0.05);
    glVertex2f(0.1,0.0);
    glVertex2f(0.1,0.1);
    glVertex2f(0.1,0.05);
    glVertex2f(0.0,0.05);
    glVertex2f(0.1,0.05);
    glEnd();


    glLoadIdentity();
    glTranslatef(-0.300f,0.8f,0.0f); // E
    glBegin(GL_LINES);
    glColor3ub(colorRed,colorGreen,colorBlue);
    glVertex2f(0.1,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.1);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,0.0);
    glVertex2f(0.1,0.0);
    glVertex2f(0.1,0.05);
    glVertex2f(0.0,0.05);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.17f,0.885f,0.0f); // Upper colon
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(0.0,0.0);
    glEnd();

    glLoadIdentity();
    glTranslatef(-0.170f,0.815f,0.0f); // Lower colon
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2f(0.0,0.0);
    glEnd();

}

void digitZero()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.1);
        glEnd();
}
void digitOne()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.1);
        glEnd();
}
void digitTwo()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.1,0.1);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.00);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glEnd();
}
void digitThree()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.1,0.1);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glEnd();
}
void digitFour()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.1);
        glVertex2f(0.1,0.0);
        glEnd();
}
void digitFive()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glEnd();
}
void digitSix()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.0,0.05);
        glEnd();
}
void digitSeven()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.1,0.1);
        glVertex2f(0.05,0.0);
        glEnd();
}
void digitEight()
{
            glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.05);
        glEnd();
}
void digitNine()
{
        glLoadIdentity();
        glTranslatef(-0.10f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glEnd();
}

void digitSecondZero()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.1);
        glEnd();
}
void digitSecondOne()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.1);
        glEnd();

}
void digitSecondTwo()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.1,0.1);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.00);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glEnd();

}
void digitSecondThree()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.1,0.1);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glEnd();

}
void digitSecondFour()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.1);
        glVertex2f(0.1,0.0);
        glEnd();

}
void digitSecondFive()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glEnd();

}
void digitSecondSix()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.0,0.05);
        glEnd();

}
void digitSecondSeven()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.1,0.1);
        glVertex2f(0.05,0.0);
        glEnd();

}
void digitSecondEight()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.05);
        glEnd();

}
void digitSecondNine()
{
            glLoadIdentity();
        glTranslatef(0.04f,0.805f,0.0f);
        glBegin(GL_LINES);
        glColor3ub(colorRed,colorGreen,colorBlue);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,0.1);
        glVertex2f(0.0,0.05);
        glVertex2f(0.1,0.05);
        glVertex2f(0.0,0.0);
        glVertex2f(0.1,0.0);
        glEnd();

}


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

void press_s_to_start(){
 glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.82f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.82f, 0.1f);
    glVertex2f(-0.9f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.9f, 0.1f);
    glVertex2f(-0.9, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.9, 0.0f);
    glVertex2f(-0.82f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.9, 0.0f);
    glVertex2f(-0.9f, -0.1f);
    glEnd();



    glBegin(GL_LINES);
    glVertex2f(-0.7, 0.0f);
    glVertex2f(-0.7f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.7, 0.1f);
    glVertex2f(-0.78f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.78, 0.1f);
    glVertex2f(-0.78f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.78, 0.0f);
    glVertex2f(-0.7f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.78, 0.0f);
    glVertex2f(-0.7f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.78, 0.0f);
    glVertex2f(-0.78f, -0.1f);
    glEnd();



    glBegin(GL_LINES);
    glVertex2f(-0.58f, 0.1f);
    glVertex2f(-0.66f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.66f, 0.1f);
    glVertex2f(-0.66f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.66f, 0.0f);
    glVertex2f(-0.58f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.66f, -0.1f);
    glVertex2f(-0.58f, -0.1f);
    glEnd();




    glBegin(GL_LINES);
    glVertex2f(-0.46f, 0.1f);
    glVertex2f(-0.54f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.54f, 0.1f);
    glVertex2f(-0.54f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.54f, 0.0f);
    glVertex2f(-0.46f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.46f, 0.0f);
    glVertex2f(-0.46f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.46f, -0.1f);
    glVertex2f(-0.54f, -0.1f);
    glEnd();




    glBegin(GL_LINES);
    glVertex2f(-0.34f, 0.1f);
    glVertex2f(-0.42f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.42f, 0.1f);
    glVertex2f(-0.42f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.42f, 0.0f);
    glVertex2f(-0.34f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.34f, 0.0f);
    glVertex2f(-0.34f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.34f, -0.1f);
    glVertex2f(-0.42f, -0.1f);
    glEnd();






    glBegin(GL_LINES);
    glVertex2f(-0.16f, 0.1f);
    glVertex2f(-0.24f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.24f, 0.1f);
    glVertex2f(-0.24f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.24f, 0.0f);
    glVertex2f(-0.16f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.16f, 0.0f);
    glVertex2f(-0.16f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.16f, -0.1f);
    glVertex2f(-0.24f, -0.1f);
    glEnd();






    glBegin(GL_LINES);
    glVertex2f(0.02f, 0.1f);
    glVertex2f(-0.06f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.02f, -0.1f);
    glVertex2f(-0.02f, 0.1f);
    glEnd();




    glBegin(GL_LINES);
    glVertex2f(0.12f, -0.1f);
    glVertex2f(0.12f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.12f, 0.1f);
    glVertex2f(0.06f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.06f, 0.1f);
    glVertex2f(0.06f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.06f, -0.1f);
    glVertex2f(0.12f, -0.1f);
    glEnd();




    glBegin(GL_LINES);
    glVertex2f(0.3f, 0.1f);
    glVertex2f(0.22f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.1f);
    glVertex2f(0.22f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.22f, 0.0f);
    glVertex2f(0.3f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.22f, -0.1f);
    glEnd();



    glBegin(GL_LINES);
    glVertex2f(0.42f, 0.1f);
    glVertex2f(0.34f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.38f, 0.1f);
    glVertex2f(0.38f, -0.1f);
    glEnd();





    glBegin(GL_LINES);
    glVertex2f(0.54f, -0.1f);
    glVertex2f(0.5f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.48f, 0.0f);
    glVertex2f(0.52f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.46f, -0.1f);
    glEnd();






    glBegin(GL_LINES);
    glVertex2f(0.66f, 0.0f);
    glVertex2f(0.66f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.66f, 0.1f);
    glVertex2f(0.58f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.58f, 0.1f);
    glVertex2f(0.58f, -0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.58f, 0.0f);
    glVertex2f(0.66f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.58f, 0.0f);
    glVertex2f(0.66f, -0.1f);
    glEnd();





    glBegin(GL_LINES);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.7f, 0.1f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.74f, 0.1f);
    glVertex2f(0.74f, -0.1f);
    glEnd();

}


void game_over_label(){
        ///Printing G
    glScalef(.5,.5,0);
    glTranslatef(0.0f,0.8f,0.0f);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(-.6-.15,.4),glVertex2d(-.8-.15,.4);
    glVertex2d(-.8-.15,.4),glVertex2d(-.8-.15,0);
    glVertex2d(-.8-.15,0),glVertex2d(-.6-.15,0);
    glVertex2d(-.6-.15,0),glVertex2d(-.6-.15,.2);
    glVertex2d(-.6-.15,.2),glVertex2d(-.7-.15,.2);
    glEnd();
    ///printing A
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(-.46-.15,.4),glVertex2d(-.54-.15,0);
    glVertex2d(-.46-.15,.4),glVertex2d(-.38-.15,0);
    glVertex2d(-.5-.15,0.2),glVertex2d(-.42-.15,.2);
    glEnd();
    ///printing M
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(-.32-.15,.4),glVertex2d(-.32-.15,0);
    glVertex2d(-.32-.15,.4),glVertex2d(-.22-.15,.2);
    glVertex2d(-.12-.15,0.4),glVertex2d(-.22-.15,.2);
    glVertex2d(-.12-.15,0.4),glVertex2d(-.12-.15,.0);
    glEnd();
    ///printing E
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(.1-.15,.4),glVertex2d(-.06-.15,.4);
    glVertex2d(-.06-.15,.2),glVertex2d(-.06-.15,.4);
    glVertex2d(-.06-.15,.2),glVertex2d(.1-.15,.2);
    glVertex2d(-.06-.15,.2),glVertex2d(-.06-.15,0);
    glVertex2d(-.06-.15,0),glVertex2d(.1-.15,0);
    glEnd();
    ///Printing O
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(.28-.15,.4),glVertex2d(.52-.15,.4);
    glVertex2d(.52-.15,.4),glVertex2d(.52-.15,0);
    glVertex2d(.52-.15,0),glVertex2d(.28-.15,0);
    glVertex2d(.28-.15,0),glVertex2d(.28-.15,.4);
    glEnd();
    ///Printing V
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(.56-.15,.4),glVertex2d(.65-.15,0);
    glVertex2d(.65-.15,0),glVertex2d(.74-.15,.4);
    glEnd();
    ///Printing E
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(.1+.86-.15,.4),glVertex2d(-.06+.86-.15,.4);
    glVertex2d(-.06+.86-.15,.2),glVertex2d(-.06+.86-.15,.4);
    glVertex2d(-.06+.86-.15,.2),glVertex2d(.1+.86-.15,.2);
    glVertex2d(-.06+.86-.15,.2),glVertex2d(-.06+.86-.15,0);
    glVertex2d(-.06+.86-.15,0),glVertex2d(.1+.86-.15,0);
    glEnd();
    ///printing R
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
    glVertex2d(1.05-.06-.15,.4),glVertex2d(1.2-.06-.15,.4);
    glVertex2d(1.2-.06-.15,.2),glVertex2d(1.2-.06-.15,.4);
    glVertex2d(1.2-.06-.15,.2),glVertex2d(1.05-.06-.15,.2);
    glVertex2d(1.05-.06-.15,.4),glVertex2d(1.05-.06-.15,.2);
    glVertex2d(1.05-.06-.15,.2),glVertex2d(1.05-.06-.15,0);
    glVertex2d(1.05-.06-.15,.2),glVertex2d(1.2-.06-.15,0);
    glEnd();

     glLoadIdentity();

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



    //cout <<x1 <<" " << y1 <<" " <<" " <<x2 <<" ----  " <<y2;
    }

}

void draw_tree(){

     glTranslatef(0.26,-.6,0);


    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();


              glLoadIdentity();

glTranslatef(-0.26,-.6,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();
     glTranslatef(-0.46,-.6,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

     glTranslatef(0.51,-.6,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

     glTranslatef(-0.74,-.6,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

     glTranslatef(0.7,-.6,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();








     ///////////////////////





     glLoadIdentity();

     glTranslatef(-0.17,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

          glLoadIdentity();

     glTranslatef(-0.27,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();



          glLoadIdentity();

     glTranslatef(0.57,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();



          glLoadIdentity();

     glTranslatef(-0.47,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();



          glLoadIdentity();

     glTranslatef(0.37,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

          glLoadIdentity();

     glTranslatef(-0.87,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

          glLoadIdentity();

     glTranslatef(-0.67,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

          glLoadIdentity();

     glTranslatef(-0.97,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();



          glLoadIdentity();

     glTranslatef(0.0,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

          glLoadIdentity();

     glTranslatef(0.87,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();

          glLoadIdentity();

     glTranslatef(0.83,-.8,0);
     glScalef(.5,.5,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(236,216,163);
    glVertex2f( 0.0f, 0.0f);
      glVertex2f(-0.02f, -0.3f);
    glVertex2f(0.02f, -0.3f);

    glEnd();

     glLoadIdentity();





















}
void display()
{

     ///dont touch
    glClearColor(1.0f ,1.0f ,1.0f ,0.0f  );
    glClear(GL_COLOR_BUFFER_BIT);


    background_cloud();
    draw_tree();









    glTranslatef(-1,1,0);
    draw_quad(xpos , ypos , type);
   // cout<<xpos<<" "<<ypos<<endl;

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



    if (playing) {
        playSound();
        playing = false;
    }


        glLoadIdentity();



    if (game_over ){
         game_over_label();
         press_s_to_start();

    }
    else
    {

         glLoadIdentity();


                       scoreText(); // for print "SCORE"

    string score = toStr(escore);
    if(score.size()==1)
    {
        if(score[0]=='0') digitZero();
        else if(score[0]=='1') digitOne();
        else if(score[0]=='2') digitTwo();
        else if(score[0]=='3') digitThree();
        else if(score[0]=='4') digitFour();
        else if(score[0]=='5') digitFive();
        else if(score[0]=='6') digitSix();
        else if(score[0]=='7') digitSeven();
        else if(score[0]=='8') digitEight();
        else if(score[0]=='9') digitNine();

    }
    else
    {
        char first = score[0];
        char second = score[1];
        if(first=='1') digitOne();
        else if(score[0]=='1') digitOne();
        else if(score[0]=='2') digitTwo();
        else if(score[0]=='3') digitThree();
        else if(score[0]=='4') digitFour();
        else if(score[0]=='5') digitFive();
        else if(score[0]=='6') digitSix();
        else if(score[0]=='7') digitSeven();
        else if(score[0]=='8') digitEight();
        else if(score[0]=='9') digitNine();

        if(second=='0') digitSecondZero();
        else if(second=='1') digitSecondOne();
        else if(second=='2') digitSecondTwo();
        else if(second=='3') digitSecondThree();
        else if(second=='4') digitSecondFour();
        else if(second=='5') digitSecondFive();
        else if(second=='6') digitSecondSix();
        else if(second=='7') digitSecondSeven();
        else if(second=='8') digitSecondEight();
        else if(second=='9') digitSecondNine();
    }
    }

     glLoadIdentity();



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


    speed += 100 ;
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
              //  cout <<endl;
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
            final_score = escore ;
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

escore+= cnt  ;


cout<<"Score : " <<escore<<endl;
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
void reset(){
    for( int i = 0 ; i<21 ; i++){

        for (int j = 0 ; j<21 ; j++ )
    {
       taken[j][i] = false ;
       escore = 0 ;
       final_score = 0 ;
       speed = 1200 ;
       xpos = 1 ;
        ypos = 0;
         type = 3;
         game_over = false ;
    }

}
}

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
        case 'm':
                if(startMusic)
                {
                    startMusic = false;
                    pauseSound();
                }
                else
                {
                    startMusic = true;
                    playSound();
                }
                break;
         case 'r':
             reset();
             break;

        case 's':
             reset();
             break;
	}
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Tertis");
    glutInitWindowSize(640,880);
    glutDisplayFunc(display);
    glutSpecialFunc(SpecialInput);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(speed, update , 0 );
    glutMainLoop();

    return 0;
}

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
#include "game.h"

struct vertex
{
	GLfloat x;
	GLfloat y;
};
std::string key;

int mScreenHeight;
int screenWidth;

Tile tetros;
Board mBoard (&tetros, 880);

Game mGame (&mBoard, &tetros,  880);


void display()
{
    glClearColor(1.0f ,1.0f ,1.0f ,0.0f  );
    glClear(GL_COLOR_BUFFER_BIT);











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














    mGame.drawScene();


    glFlush();


}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Tertis");
    glutInitWindowSize(640,880);
    glutDisplayFunc(display);

  //  glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.
  //  glutTimerFunc(900, update , 0 );
    glutMainLoop();

    return 0;
}

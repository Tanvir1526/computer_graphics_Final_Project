#include<iostream>
#include<cstdio>
#include<cmath>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

GLfloat trainPosition = 0.0f;
GLfloat trainSpeed = 0.05f;
GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.1f;
GLfloat carPosition2 = 0.0f;
GLfloat carSpeed2 = 0.02f;

float cloud1X = 0.0f;
float cloud1Speed = 0.01f;
float planeX = 0;
float planeSpeed = 0.05;
float rainY = 0;
float rainSpeed = 0.01;

float red, green, blue;

void init() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void DrawCircle(float cx, float cy, float r, int num_segments){
     glBegin(GL_TRIANGLE_FAN);
     for (int i = 0; i < num_segments; i++)
        {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

        }
     glEnd();
}

void update(int value) {

    if(trainPosition < -3.0)
        trainPosition = 1.2f;

    trainPosition -= trainSpeed;

    carPosition += carSpeed;
    if(carPosition > 1.0)
        carPosition = -1.2f;

    carPosition2 += carSpeed2;
    if(carPosition2 > 1.0)
        carPosition2 = -1.6f;

    cloud1X += cloud1Speed;
    if (cloud1X>1.5f)
    {
        cloud1X =-1.0f ;
    }

    planeX += planeSpeed;

    if (planeX>1.2f)
    {
        planeX =-1.0f ;
    }

    rainY -=rainSpeed;

    if (rainY<-1.0)
    {
        rainY = 1.5;
    }

	glutPostRedisplay();
	glutTimerFunc(100, update, 0);


}

void rain(){
    glPushMatrix();
    glTranslatef(0, rainY, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(192,199,225);

    for(float j= 1.979; j>-3; j -= 0.04){
        for(float i = -0.969; i<1.2; i += 0.064){
            glVertex2f(i,j);
            glVertex2f(i-0.024,j-0.02);
        }
    }
    glEnd();
    glPopMatrix();
}

void sun(){

    glColor3f(0.94,0.76,0.058);
    DrawCircle(0.69,0.70, 0.10, 10000);

}

void cloud(){

    glPushMatrix();
    glTranslatef(cloud1X, 0, 0);
    glColor3f(0.96,0.96,0.96);
    DrawCircle(-0.65,0.75, 0.05, 10000);

    DrawCircle(-0.64,0.72, 0.05, 10000);

    DrawCircle(-0.60,0.71, 0.05, 10000);

    DrawCircle(-0.59,0.77, 0.05, 10000);

    DrawCircle(-0.56,0.75, 0.05, 10000);

    DrawCircle(-0.52,0.71, 0.05, 10000);
    glPopMatrix();

}

void plane(){
    glPushMatrix();
    glTranslatef(planeX, 0, 0);

    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2f(-0.63,0.89);
    glVertex2f(-0.41,0.89);
    glVertex2f(-0.43,0.95);
    glVertex2f(-0.56,0.94);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(-0.54,0.93);
    glVertex2f(-0.53,1.03);
    glVertex2f(-0.56,0.97);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(-0.53,0.90);
    glVertex2f(-0.49,0.89);
    glVertex2f(-0.56,0.85);
    glEnd();

    glLineWidth(8.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-0.48,0.92);
    glVertex2f(-0.45,0.92);
    glEnd();
    glPopMatrix();

}

void sky(){
     glBegin(GL_QUADS);
     glColor3f(0.68,0.87,0.89);
     glVertex2f(-1,1.08);
     glVertex2f(-1,0.26);
     glVertex2f(1.19,0.26);
     glVertex2f(1.19,1.08);
     glEnd();
     sun();
     cloud();
     plane();
}

void myBuilding(){
glPushMatrix();

glPushMatrix(); //Right Down Window
glBegin(GL_QUADS);
glColor3f(red, green, blue);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.1f, 0.4f);
glVertex2f(-0.1f, 0.4f);
glVertex2f(-0.1f, 0.0f);
glEnd();
glPopMatrix();

glPushMatrix(); //Right Down Window
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex2f(0.02f, 0.06f);
glVertex2f(0.06f, 0.06f);
glVertex2f(0.06f, 0.15f);
glVertex2f(0.02f, 0.15f);
glEnd();
glPopMatrix();

glPushMatrix(); //Right Up Window
glTranslatef(0.0, 0.15, 0.0);
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex2f(0.02f, 0.06f);
glVertex2f(0.06f, 0.06f);
glVertex2f(0.06f, 0.15f);
glVertex2f(0.02f, 0.15f);
glEnd();
glPopMatrix();

glPushMatrix(); //Left up Window
glTranslatef(-0.08, 0.15, 0.0);
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex2f(0.02f, 0.06f);
glVertex2f(0.06f, 0.06f);
glVertex2f(0.06f, 0.15f);
glVertex2f(0.02f, 0.15f);
glEnd();
glPopMatrix();

glPushMatrix(); //Left Down Window
glTranslatef(-0.08, 0.0, 0.0);
glBegin(GL_QUADS);
glColor3f(0,0,0);
glVertex2f(0.02f, 0.06f);
glVertex2f(0.06f, 0.06f);
glVertex2f(0.06f, 0.15f);
glVertex2f(0.02f, 0.15f);
glEnd();
glPopMatrix();

glPopMatrix();

}

void Buildings(){

///--------------------------------------------------- Building Start -----------------------------------------------------

glPushMatrix();
glScalef(1.4, 1.6, 0.0);
glTranslatef(0.33, 0.0, 0.0);
red = 0.0f; green = 0.5f; blue =0.5f;
myBuilding();
glPopMatrix();

glPushMatrix();
glScalef(1.1, 1.5, 0.0);
glTranslatef(0.75, 0.0, 0.0);
red = 0.0f; green = 0.0f; blue = 0.5f;
myBuilding();
glBegin(GL_TRIANGLES);
glColor3f(0, 0, 0.5);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.98, 0.0, 0.0);
red = 0.5; green = 0.0f; blue = 0.5f;
myBuilding();
glPopMatrix();

glPushMatrix();
glTranslatef(0.68, 0.0, 0.0);
red = 1.0f; green = 0.5f; blue = 0.0f;
myBuilding();
glPopMatrix();

glPushMatrix();
glScalef(1.4, 1.9, 0.0);
glTranslatef(0.12, 0.0, 0.0);
red = 0.5f; green = 0.0f; blue =0.5f;
myBuilding();
glBegin(GL_TRIANGLES);
glColor3f(0.5, 0, 0.5);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(1.1, 1.1, 0.0);
glTranslatef(0.27, 0.0, 0.0);
red = 1.5f; green = 0.0f; blue = 0.0f;
myBuilding();
glPopMatrix();

glPushMatrix();
glScalef(2.0, 2.0, 0.0);
glTranslatef(-0.17, 0.0, 0.0);
red = 0.0f; green = 0.5f; blue = 0.5f;
myBuilding();
glPopMatrix();

glPushMatrix();
glScalef(1.5, 2.2, 0.0);
glTranslatef(-0.5, 0.0, 0.0);
red = 0.5f; green = 0.0f; blue = 0.0f;
myBuilding();
glPopMatrix();

glPushMatrix();
glScalef(1.1, 1.2, 0.0);
glTranslatef(-0.12, 0.0, 0.0);
red = 1.0f; green = 0.5f; blue =0.0f;
myBuilding();
glBegin(GL_TRIANGLES);
glColor3f(1.0, 0.5, 0.0);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(1.5, 1.5, 0.0);
glTranslatef(-0.37, 0.0, 0.0);
red = 0.0f; green = 0.8f; blue = 0.0f;
myBuilding();
glBegin(GL_TRIANGLES);
glColor3f(0.0, 0.8, 0.0);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(1.2, 1.6, 0.0);
glTranslatef(-0.77, 0.0, 0.0);
red = 1.0f; green = 0.0f; blue = 0.0f;
myBuilding();
glBegin(GL_TRIANGLES);
glColor3f(1.0, 0, 0.0);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(0.8, 0.8, 0.0);
glTranslatef(-0.97, 0.0, 0.0);
red = 0.3f; green = 0.0f; blue = 0.5f;
myBuilding();
glPopMatrix();

glPushMatrix();
glScalef(0.8,0.8,0.0);
red = 0.0f; green = 0.0f; blue =0.5f;
myBuilding();
glPopMatrix();


glPushMatrix(); /// Down border
glLineWidth(3);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-3,0);
glVertex2f(3,0);
glEnd();
glPopMatrix();

//--------------------------------------------------- Building End-----------------------------------------------------
}

void railBridge(){

   glColor3f(0.4f, 0.4f, 0.4f);
   glBegin(GL_TRIANGLES);
   glVertex2f(-1.0f,-0.2f);
   glVertex2f(-0.9f,-0.2f);
   glVertex2f(-0.9f,-0.3f);
   glEnd();

   glBegin(GL_QUADS);

      glVertex2f(-0.9f, -0.2f);
      glVertex2f(-0.9f, -0.5f);
      glVertex2f(-0.85f, -0.5f);
      glVertex2f(-0.85f, -0.2f);
   glEnd();
   glBegin(GL_TRIANGLES);

   glVertex2f(-0.85f,-0.2f);
   glVertex2f(-0.85f,-0.3f);
   glVertex2f(-0.75f,-0.2f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2f(-0.5f,-0.2f);
   glVertex2f(-0.5f,-0.3f);
   glVertex2f(-0.6f,-0.2f);
   glEnd();

   glBegin(GL_QUADS);

      glVertex2f(-0.5f, -0.2f);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f(-0.45f, -0.5f);
      glVertex2f(-0.45f, -0.2f);
   glEnd();

   glBegin(GL_TRIANGLES);

   glVertex2f(-0.45f,-0.2f);
   glVertex2f(-0.45f,-0.3f);
   glVertex2f(-0.35f,-0.2f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2f(-0.1f,-0.2f);
   glVertex2f(-0.1f,-0.3f);
   glVertex2f(-0.2f,-0.2f);
   glEnd();

   glBegin(GL_QUADS);

      glVertex2f(-0.1f, -0.2f);
      glVertex2f(-0.1f, -0.5f);
      glVertex2f(-0.05f, -0.5f);
      glVertex2f(-0.05f, -0.2f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2f(-0.05f,-0.2f);
   glVertex2f(-0.05f,-0.3f);
   glVertex2f(0.05f,-0.2f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2f(0.3f,-0.2f);
   glVertex2f(0.3f,-0.3f);
   glVertex2f(0.2f,-0.2f);
   glEnd();

    glBegin(GL_QUADS);

      glVertex2f(0.3f, -0.2f);
      glVertex2f(0.3f, -0.5f);
      glVertex2f(0.35f, -0.5f);
      glVertex2f(0.35f, -0.2f);
   glEnd();

   glBegin(GL_TRIANGLES);

   glVertex2f(0.35f,-0.2f);
   glVertex2f(0.35f,-0.3f);
   glVertex2f(0.45f,-0.2f);
   glEnd();

   glBegin(GL_TRIANGLES);

   glVertex2f(0.7f,-0.2f);
   glVertex2f(0.7f,-0.3f);
   glVertex2f(0.6f,-0.2f);
   glEnd();

   glBegin(GL_QUADS);

      glVertex2f(0.7f, -0.2f);
      glVertex2f(0.7f, -0.5f);
      glVertex2f(0.75f, -0.5f);
      glVertex2f(0.75f, -0.2f);
   glEnd();

   glBegin(GL_TRIANGLES);

   glVertex2f(0.75f,-0.2f);
   glVertex2f(0.75f,-0.3f);
   glVertex2f(0.85f,-0.2f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3f(0.1f,0.1f,0.1f);
   glVertex2f(-1.0f,-0.21f);
   glVertex2f(-1.0f,-0.25f);
   glVertex2f(1.0f,-0.25f);
   glVertex2f(1.0f,-0.21f);
   glEnd();

   glBegin(GL_QUADS);
   glColor3f(0.1f,0.1f,0.1f);
   glVertex2f(-1.0f,-0.11f);
   glVertex2f(-1.0f,-0.15f);
   glVertex2f(1.0f,-0.15f);
   glVertex2f(1.0f,-0.11f);
   glEnd();

}

void rails(){


    glColor3f(0.78f, 0.78f, 0.78f);

    glBegin(GL_QUADS);
    glVertex2f(-1.0f,-0.13f);
    glVertex2f(-0.9f,-0.22f);
    glVertex2f(-0.88f,-0.22f);
    glVertex2f(-0.98f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.9f,-0.13f);
    glVertex2f(-0.8f,-0.22f);
    glVertex2f(-0.78f,-0.22f);
    glVertex2f(-0.88f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.8f,-0.13f);
    glVertex2f(-0.7f,-0.22f);
    glVertex2f(-0.68f,-0.22f);
    glVertex2f(-0.78f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.7f,-0.13f);
    glVertex2f(-0.6f,-0.22f);
    glVertex2f(-0.58f,-0.22f);
    glVertex2f(-0.68f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.6f,-0.13f);
    glVertex2f(-0.5f,-0.22f);
    glVertex2f(-0.48f,-0.22f);
    glVertex2f(-0.58f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.5f,-0.13f);
    glVertex2f(-0.4f,-0.22f);
    glVertex2f(-0.38f,-0.22f);
    glVertex2f(-0.48f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.4f,-0.13f);
    glVertex2f(-0.3f,-0.22f);
    glVertex2f(-0.28f,-0.22f);
    glVertex2f(-0.38f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.3f,-0.13f);
    glVertex2f(-0.2f,-0.22f);
    glVertex2f(-0.18f,-0.22f);
    glVertex2f(-0.28f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.2f,-0.13f);
    glVertex2f(-0.1f,-0.22f);
    glVertex2f(-0.08f,-0.22f);
    glVertex2f(-0.18f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.1f,-0.13f);
    glVertex2f(0.0f,-0.22f);
    glVertex2f(0.02f,-0.22f);
    glVertex2f(-0.08f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.0f,-0.13f);
    glVertex2f(0.1f,-0.22f);
    glVertex2f(0.12f,-0.22f);
    glVertex2f(0.02f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.1f,-0.13f);
    glVertex2f(0.2f,-0.22f);
    glVertex2f(0.22f,-0.22f);
    glVertex2f(0.12f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(0.2f,-0.13f);
    glVertex2f(0.3f,-0.22f);
    glVertex2f(0.32f,-0.22f);
    glVertex2f(0.22f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(0.3f,-0.13f);
    glVertex2f(0.4f,-0.22f);
    glVertex2f(0.42f,-0.22f);
    glVertex2f(0.32f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(0.4f,-0.13f);
    glVertex2f(0.5f,-0.22f);
    glVertex2f(0.52f,-0.22f);
    glVertex2f(0.42f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.5f,-0.13f);
    glVertex2f(0.6f,-0.22f);
    glVertex2f(0.62f,-0.22f);
    glVertex2f(0.52f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(0.6f,-0.13f);
    glVertex2f(0.7f,-0.22f);
    glVertex2f(0.72f,-0.22f);
    glVertex2f(0.62f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.7f,-0.13f);
    glVertex2f(0.8f,-0.22f);
    glVertex2f(0.82f,-0.22f);
    glVertex2f(0.72f,-0.13f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(0.8f,-0.13f);
    glVertex2f(0.9f,-0.22f);
    glVertex2f(0.92f,-0.22f);
    glVertex2f(0.82f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.9f,-0.13f);
    glVertex2f(1.0f,-0.22f);
    glVertex2f(1.02f,-0.22f);
    glVertex2f(0.92f,-0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.28f, 0.281f, 0.0f);
    glVertex2f(-1.0f,-0.2f);
    glVertex2f(-1.0f,-0.22f);
    glVertex2f(1.0f,-0.22f);
    glVertex2f(1.0f,-0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.28f, 0.28f, 0.0f);
    glVertex2f(-1.0f,-0.11f);
    glVertex2f(-1.0f,-0.13f);
    glVertex2f(1.0f,-0.13f);
    glVertex2f(1.0f,-0.11f);
    glEnd();
}

void compartment(float tx){

//front view
    glBegin(GL_QUADS);
    glColor3b(0,0,0);
    glVertex2f( 0.0f+tx, -0.12f);
    glVertex2f( 0.1f+tx, -0.21f);
    glVertex2f( 0.1f+tx, -0.05f);
    glVertex2f( 0.0f+tx, 0.05f);
    glEnd();

//back view
    glBegin(GL_QUADS);
    glColor3b(256,256,256);
    glVertex2f( 0.37f+tx, -0.12f);
    glVertex2f( 0.47f+tx, -0.21f);
    glVertex2f( 0.47f+tx, -0.05f);
    glVertex2f( 0.37f+tx, 0.05f);
    glEnd();
//side view
    glBegin(GL_QUADS);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( 0.1f+tx, -0.21f);
    glVertex2f( 0.47f+tx, -0.21f);
    glVertex2f( 0.47f+tx, -0.05f);
    glVertex2f( 0.1f+tx, -0.05f);
    glEnd();
//top front
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f( 0.04f+tx, 0.08f);
    glVertex2f( 0.04f+tx, 0.004f);
    glVertex2f( 0.08f+tx, -0.04f);
    glVertex2f( 0.08f+tx, 0.04f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.04f+tx,0.08f);
    glVertex2f(0.04f+tx, 0.004f);
    glVertex2f(0.0f+tx, 0.05f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.08f+tx,-0.04f);
    glVertex2f(0.08f+tx, 0.04f);
    glVertex2f(0.1f+tx, -0.05f);
    glEnd();
//top
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.1f,1.0f);
    glVertex2f( 0.04f+tx, 0.08f);
    glVertex2f( 0.08f+tx, 0.04f);
    glVertex2f( 0.45f+tx, 0.04f);
    glVertex2f( 0.41f+tx, 0.08f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 1.0f);
    glVertex2f( 0.1f+tx, -0.05f);
    glVertex2f( 0.08f+tx, 0.04f);
    glVertex2f( 0.45f+tx, 0.04f);
    glVertex2f( 0.47f+tx, -0.05f);
    glEnd();
//1st door
    glBegin(GL_QUADS);
    glColor3f( 0.0f, 0.0f, 0.0f);
    glVertex2f( 0.146f+tx, -0.21f);
    glVertex2f( 0.204f+tx, -0.21f);
    glVertex2f( 0.204f+tx, -0.095f);
    glVertex2f( 0.146f+tx, -0.095f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f( 0.9f, 0.9f, 0.9f);
    glVertex2f( 0.15f+tx, -0.21f);
    glVertex2f( 0.2f+tx, -0.21f);
    glVertex2f( 0.2f+tx, -0.1f);
    glVertex2f( 0.15f+tx, -0.1f);
    glEnd();

//2nd door

    glBegin(GL_QUADS);
    glColor3f( 0.0f, 0.0f, 0.0f);
    glVertex2f( 0.395f+tx, -0.21f);
    glVertex2f( 0.455f+tx, -0.21f);
    glVertex2f( 0.455f+tx, -0.095f);
    glVertex2f( 0.395f+tx, -0.095f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f( 0.9f, 0.9f, 0.9f);
    glVertex2f( 0.4f+tx, -0.21f);
    glVertex2f( 0.45f+tx, -0.21f);
    glVertex2f( 0.45f+tx, -0.1f);
    glVertex2f( 0.4f+tx, -0.1f);
    glEnd();

//windows

    glBegin(GL_QUADS);
    glColor3f( 0.0f, 0.0f, 0.0f);
    glVertex2f( 0.245f+tx, -0.095f);
    glVertex2f( 0.245f+tx, -0.155f);
    glVertex2f( 0.35f+tx, -0.155f);
    glVertex2f( 0.35f+tx, -0.095f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f( 0.9f, 0.9f, 0.9f);
    glVertex2f( 0.25f+tx, -0.1f);
    glVertex2f( 0.25f+tx, -0.15f);
    glVertex2f( 0.27f+tx, -0.15f);
    glVertex2f( 0.27f+tx, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.275f+tx, -0.1f);
    glVertex2f( 0.275f+tx, -0.15f);
    glVertex2f( 0.295f+tx, -0.15f);
    glVertex2f( 0.295f+tx, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.3f+tx, -0.1f);
    glVertex2f( 0.3f+tx, -0.15f);
    glVertex2f( 0.32f+tx, -0.15f);
    glVertex2f( 0.32f+tx, -0.1f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f( 0.325f+tx, -0.1f);
    glVertex2f( 0.325f+tx, -0.15f);
    glVertex2f( 0.345f+tx, -0.15f);
    glVertex2f( 0.345f+tx, -0.1f);
    glEnd();
}

void head(){

    float tx = -0.1;
//top bar
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f( 0.04f+tx, 0.08f);
    glVertex2f( 0.04f+tx, 0.004f);
    glVertex2f( 0.08f+tx, -0.04f);
    glVertex2f( 0.08f+tx, 0.04f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.04f+tx,0.08f);
    glVertex2f(0.04f+tx, 0.004f);
    glVertex2f(0.0f+tx, 0.05f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.08f+tx,-0.04f);
    glVertex2f(0.08f+tx, 0.04f);
    glVertex2f(0.1f+tx, -0.05f);
    glEnd();

//extended part
    tx = -0.2;
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.1f,1.0f);
    glVertex2f( 0.14f+tx, 0.08f);
    glVertex2f( 0.18f+tx, 0.04f);
    glVertex2f( 0.45f+tx, 0.04f);
    glVertex2f( 0.41f+tx, 0.08f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 1.0f);
    glVertex2f( 0.2f+tx, -0.05f);
    glVertex2f( 0.18f+tx, 0.04f);
    glVertex2f( 0.45f+tx, 0.04f);
    glVertex2f( 0.5f+tx, -0.05f);
    glEnd();
//mid body
    glBegin(GL_QUADS);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( -0.1f, -0.05f);
    glVertex2f( -0.1f, -0.15f);
    glVertex2f( 0.1f, -0.15f);
    glVertex2f( 0.1f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( -0.1f, -0.15f);
    glVertex2f( -0.1f, -0.11f);
    glVertex2f( -0.15f, -0.11f);
    glVertex2f( -0.15f, -0.15f);
    glEnd();

//glass
    glBegin(GL_QUADS);
    glColor3f(0.83f,0.83f,1.0f);
    glVertex2f(-0.1f, 0.05f);
    glVertex2f(-0.13f, -0.08f);
    glVertex2f(-0.07f, -0.13f);
    glVertex2f(0.0f,-0.05f);
    glEnd();
//lower body
    glBegin(GL_QUADS);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( -0.15f, -0.15f);
    glVertex2f( -0.15f, -0.21f);
    glVertex2f( 0.1f, -0.21f);
    glVertex2f( 0.1f, -0.15f);
    glEnd();

//front panel
    glBegin(GL_QUADS);
    glColor3f(0.43f,0.43f,0.0f);
    glVertex2f(-0.13f, -0.08f);
    glVertex2f(-0.18f, -0.13f);
    glVertex2f(-0.15f,-0.15f);
    glVertex2f(-0.07f, -0.13f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( -0.1f, -0.21f);
    glVertex2f( -0.1f, -0.15f);
    glVertex2f( -0.18f, -0.13f);
    glVertex2f( -0.2f, -0.21f);
    glEnd();

}

void train(){
    compartment(1.2f);
    compartment(0.8f);
    compartment(0.4f);
    compartment(0.0f);
    head();

}

void railway(){

    glBegin(GL_QUADS);
    glColor3f(0.7f,0.7f,0.7f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f ,-0.25f);
    glVertex2f(1.0f ,-0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f,0.9f,0.7f);
    glVertex2f(1.0f, -0.25f);
    glVertex2f(-1.0f, -0.25f);
    glVertex2f(-1.0f ,-0.5f);
    glVertex2f(1.0f ,-0.5f);
    glEnd();


    railBridge();
    rails();
    glPushMatrix();
    glTranslatef(trainPosition,0.0f, 0.0f);
    train();
    glPopMatrix();

}

void roads(){
    //_________________road__________
glBegin(GL_QUADS);
      glColor3f(.5f, 0.5f, 0.5f);
      glVertex2f(-1.0f, -0.5f);
      glVertex2f(-1.0f, -1.0f);
      glVertex2f(1.0f, -1.0f);
      glVertex2f(1.0f, -0.5f);
 glEnd();
glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.0f, -0.75f);
      glVertex2f(0.0f, -0.77f);
      glVertex2f(0.1f, -0.77f);
      glVertex2f(.1f, -.75f);
 glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.12f, -0.75f);
      glVertex2f(0.12f, -0.77f);
      glVertex2f(0.22f, -0.77f);
      glVertex2f(.22f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.24f, -0.75f);
      glVertex2f(0.24f, -0.77f);
      glVertex2f(0.34f, -0.77f);
      glVertex2f(.34f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.36f, -0.75f);
      glVertex2f(0.36f, -0.77f);
      glVertex2f(0.46f, -0.77f);
      glVertex2f(.46f, -.75f);
 glEnd();
 //=====
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.48f, -0.75f);
      glVertex2f(0.48f, -0.77f);
      glVertex2f(0.58f, -0.77f);
      glVertex2f(.58f, -.75f);
 glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.6f, -0.75f);
      glVertex2f(0.6f, -0.77f);
      glVertex2f(0.7f, -0.77f);
      glVertex2f(.7f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.72f, -0.75f);
      glVertex2f(0.72f, -0.77f);
      glVertex2f(0.82f, -0.77f);
      glVertex2f(.82f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.84f, -0.75f);
      glVertex2f(0.84f, -0.77f);
      glVertex2f(0.94f, -0.77f);
      glVertex2f(.94f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.96f, -0.75f);
      glVertex2f(0.96f, -0.77f);
      glVertex2f(1.0f, -0.77f);
      glVertex2f(1.0f, -.75f);
 glEnd();
 //--

 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.2f, -0.75f);
      glVertex2f(-0.2f, -0.77f);
      glVertex2f(-0.1f, -0.77f);
      glVertex2f(-0.1f, -.75f);
 glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.12f, -0.75f);
      glVertex2f(-0.12f, -0.77f);
      glVertex2f(-0.22f, -0.77f);
      glVertex2f(-0.22f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.24f, -0.75f);
      glVertex2f(-0.24f, -0.77f);
      glVertex2f(-0.34f, -0.77f);
      glVertex2f(-0.34f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.36f, -0.75f);
      glVertex2f(-0.36f, -0.77f);
      glVertex2f(-0.46f, -0.77f);
      glVertex2f(-0.46f, -.75f);
 glEnd();

 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.48f, -0.75f);
      glVertex2f(-0.48f, -0.77f);
      glVertex2f(-0.58f, -0.77f);
      glVertex2f(-0.58f, -.75f);
 glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.6f, -0.75f);
      glVertex2f(-0.6f, -0.77f);
      glVertex2f(-0.7f, -0.77f);
      glVertex2f(-0.7f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.72f, -0.75f);
      glVertex2f(-0.72f, -0.77f);
      glVertex2f(-0.82f, -0.77f);
      glVertex2f(-0.82f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.84f, -0.75f);
      glVertex2f(-0.84f, -0.77f);
      glVertex2f(-0.94f, -0.77f);
      glVertex2f(-0.94f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.96f, -0.75f);
      glVertex2f(-0.96f, -0.77f);
      glVertex2f(-1.0f, -0.77f);
      glVertex2f(-1.0f, -.75f);
 glEnd();
//-------car1------------------------

 glLoadIdentity();
glPushMatrix();
glTranslatef(carPosition,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.0f, -0.6f);
      glVertex2f(0.0f, -0.7f);
      glVertex2f(0.3f, -0.7f);
      glVertex2f(0.3f, -0.6f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.1f, 0.0f);
      glVertex2f(0.05f, -0.6f);
      glVertex2f(0.25f, -0.6f);
      glVertex2f(0.2f, -0.54f);
      glVertex2f(0.1f, -0.54f);
   glEnd();
glBegin(GL_QUADS);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex2f(0.06f, -0.6f);
      glVertex2f(0.24f, -0.6f);
      glVertex2f(0.2f, -0.55f);
      glVertex2f(0.1f, -0.55f);
   glEnd();
glBegin(GL_QUADS);
      glColor3f(1.0f, 0.1f, 0.0f);
      glVertex2f(0.15f, -0.54f);
      glVertex2f(0.15f, -0.7f);
      glVertex2f(0.16f, -0.7f);
      glVertex2f(0.16f, -0.54f);
   glEnd();
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.27f, -0.62f);
      glVertex2f(0.29f, -0.62f);
      glVertex2f(0.29f, -0.66f);

   glEnd();
  glColor3f(.3f, .3f, .3f);
    DrawCircle(0.09, -0.7, .03, 10000);
  glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(0.09, -0.7, .01, 10000);
    glColor3f(.3f, .3f, .3f);
    DrawCircle(0.22, -0.7, .03, 10000);
  glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(0.22, -0.7, .01, 10000);

glPopMatrix();
//-------bus------------------------
glPushMatrix();
glTranslatef(carPosition2,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(.0f, 0.0f, 1.0f);
      glVertex2f(0.2f, -0.8f);
      glVertex2f(0.2f, -0.95f);
      glVertex2f(0.7f, -0.95f);
      glVertex2f(0.7f, -0.8f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(.0f, 1.f, 1.0f);
      glVertex2f(0.27f, -0.85f);
      glVertex2f(0.27f, -0.9f);
      glVertex2f(0.37f, -0.9f);
      glVertex2f(0.37f, -0.85f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(.0f, 1.f, 1.0f);
      glVertex2f(0.39f, -0.85f);
      glVertex2f(0.39f, -0.9f);
      glVertex2f(0.49f, -0.9f);
      glVertex2f(0.49f, -0.85f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(.0f, 1.f, 1.0f);
      glVertex2f(0.51f, -0.85f);
      glVertex2f(0.51f, -0.9f);
      glVertex2f(0.61f, -0.9f);
      glVertex2f(0.61f, -0.85f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(.0f, 1.f, 1.0f);
      glVertex2f(0.62f, -0.84f);
      glVertex2f(0.62f, -0.93f);
      glVertex2f(0.66f, -0.93f);
      glVertex2f(0.66f, -0.84f);
   glEnd();
glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.67f, -0.88f);
      glVertex2f(0.69f, -0.88f);
      glVertex2f(0.69f, -0.92f);
   glEnd();

   glColor3f(.3f, .3f, .3f);
    DrawCircle(0.37, -0.95, .03, 10000);
  glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(0.37, -0.95, .01, 10000);
    glColor3f(.3f, .3f, .3f);
    DrawCircle(0.58, -0.95, .03, 10000);
  glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(0.58, -0.95, .01, 10000);
glPopMatrix();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    init();
   glLoadIdentity();
    sky();
    Buildings();
   railway();
   roads();

   glFlush();
}

void moon(){

    glColor3f(0.9,0.9,0.9);
    DrawCircle(0.69,0.70, 0.10, 10000);

}

void nightCloud(){

    glPushMatrix();
    glTranslatef(cloud1X, 0, 0);
    glColor3f(0.96,0.96,0.96);
    DrawCircle(-0.65,0.75, 0.05, 10000);

    DrawCircle(-0.64,0.72, 0.05, 10000);

    DrawCircle(-0.60,0.71, 0.05, 10000);

    DrawCircle(-0.59,0.77, 0.05, 10000);

    DrawCircle(-0.56,0.75, 0.05, 10000);

    DrawCircle(-0.52,0.71, 0.05, 10000);
    glPopMatrix();

}

void nightSky(){
     glBegin(GL_QUADS);
     glColor3f(0.3,0.3,0.3);
     glVertex2f(-1,1.08);
     glVertex2f(-1,0.26);
     glVertex2f(1.19,0.26);
     glVertex2f(1.19,1.08);
     glEnd();
     moon();
     nightCloud();
}

void nightMyBuilding(){
glPushMatrix();

glPushMatrix(); //Right Down Window
glBegin(GL_QUADS);
glColor3f(red, green, blue);
glVertex2f(0.1f, 0.0f);
glVertex2f(0.1f, 0.4f);
glVertex2f(-0.1f, 0.4f);
glVertex2f(-0.1f, 0.0f);
glEnd();
glPopMatrix();

glPushMatrix(); //Right Down Window
glBegin(GL_QUADS);
glColor3f(1,1,0);
glVertex2f(0.02f, 0.06f);
glVertex2f(0.06f, 0.06f);
glVertex2f(0.06f, 0.15f);
glVertex2f(0.02f, 0.15f);
glEnd();
glPopMatrix();

glPushMatrix(); //Right Up Window
glTranslatef(0.0, 0.15, 0.0);
glBegin(GL_QUADS);
glColor3f(1,1,0);
glVertex2f(0.02f, 0.06f);
glVertex2f(0.06f, 0.06f);
glVertex2f(0.06f, 0.15f);
glVertex2f(0.02f, 0.15f);
glEnd();
glPopMatrix();

glPushMatrix(); //Left up Window
glTranslatef(-0.08, 0.15, 0.0);
glBegin(GL_QUADS);
glColor3f(1,1,0);
glVertex2f(0.02f, 0.06f);
glVertex2f(0.06f, 0.06f);
glVertex2f(0.06f, 0.15f);
glVertex2f(0.02f, 0.15f);
glEnd();
glPopMatrix();

glPushMatrix(); //Left Down Window
glTranslatef(-0.08, 0.0, 0.0);
glBegin(GL_QUADS);
glColor3f(1,1,0);
glVertex2f(0.02f, 0.06f);
glVertex2f(0.06f, 0.06f);
glVertex2f(0.06f, 0.15f);
glVertex2f(0.02f, 0.15f);
glEnd();
glPopMatrix();

glPopMatrix();

}

void nightBuildings(){

///--------------------------------------------------- Building Start -----------------------------------------------------

glPushMatrix();
glScalef(1.4, 1.6, 0.0);
glTranslatef(0.33, 0.0, 0.0);
red = 0.0f; green = 0.5f; blue =0.5f;
nightMyBuilding();
glPopMatrix();

glPushMatrix();
glScalef(1.1, 1.5, 0.0);
glTranslatef(0.75, 0.0, 0.0);
red = 0.0f; green = 0.0f; blue = 0.5f;
nightMyBuilding();
glBegin(GL_TRIANGLES);
glColor3f(0, 0, 0.5);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(0.98, 0.0, 0.0);
red = 0.5; green = 0.0f; blue = 0.5f;
nightMyBuilding();
glPopMatrix();

glPushMatrix();
glTranslatef(0.68, 0.0, 0.0);
red = 1.0f; green = 0.5f; blue = 0.0f;
nightMyBuilding();
glPopMatrix();

glPushMatrix();
glScalef(1.4, 1.9, 0.0);
glTranslatef(0.12, 0.0, 0.0);
red = 0.5f; green = 0.0f; blue =0.5f;
nightMyBuilding();
glBegin(GL_TRIANGLES);
glColor3f(0.5, 0, 0.5);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(1.1, 1.1, 0.0);
glTranslatef(0.27, 0.0, 0.0);
red = 1.5f; green = 0.0f; blue = 0.0f;
nightMyBuilding();
glPopMatrix();

glPushMatrix();
glScalef(2.0, 2.0, 0.0);
glTranslatef(-0.17, 0.0, 0.0);
red = 0.0f; green = 0.5f; blue = 0.5f;
nightMyBuilding();
glPopMatrix();

glPushMatrix();
glScalef(1.5, 2.2, 0.0);
glTranslatef(-0.5, 0.0, 0.0);
red = 0.5f; green = 0.0f; blue = 0.0f;
nightMyBuilding();
glPopMatrix();

glPushMatrix();
glScalef(1.1, 1.2, 0.0);
glTranslatef(-0.12, 0.0, 0.0);
red = 1.0f; green = 0.5f; blue =0.0f;
nightMyBuilding();
glBegin(GL_TRIANGLES);
glColor3f(1.0, 0.5, 0.0);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(1.5, 1.5, 0.0);
glTranslatef(-0.37, 0.0, 0.0);
red = 0.0f; green = 0.8f; blue = 0.0f;
nightMyBuilding();
glBegin(GL_TRIANGLES);
glColor3f(0.0, 0.8, 0.0);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(1.2, 1.6, 0.0);
glTranslatef(-0.77, 0.0, 0.0);
red = 1.0f; green = 0.0f; blue = 0.0f;
nightMyBuilding();
glBegin(GL_TRIANGLES);
glColor3f(1.0, 0, 0.0);
glVertex2f(0.0f,0.5f);
glVertex2f(0.10f, 0.4f);
glVertex2f(-0.10f, 0.4f);
glEnd();
glPopMatrix();

glPushMatrix();
glScalef(0.8, 0.8, 0.0);
glTranslatef(-0.97, 0.0, 0.0);
red = 0.3f; green = 0.0f; blue = 0.5f;
nightMyBuilding();
glPopMatrix();

glPushMatrix();
glScalef(0.8,0.8,0.0);
red = 0.0f; green = 0.0f; blue =0.5f;
nightMyBuilding();
glPopMatrix();


glPushMatrix(); // Down border
glLineWidth(3);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(-3,0);
glVertex2f(3,0);
glEnd();
glPopMatrix();

//--------------------------------------------------- Building End-----------------------------------------------------
}

void nightCompartment(float tx){

//front view
    glBegin(GL_QUADS);
    glColor3b(0,0,0);
    glVertex2f( 0.0f+tx, -0.12f);
    glVertex2f( 0.1f+tx, -0.21f);
    glVertex2f( 0.1f+tx, -0.05f);
    glVertex2f( 0.0f+tx, 0.05f);
    glEnd();

//back view
    glBegin(GL_QUADS);
    glColor3b(256,256,256);
    glVertex2f( 0.37f+tx, -0.12f);
    glVertex2f( 0.47f+tx, -0.21f);
    glVertex2f( 0.47f+tx, -0.05f);
    glVertex2f( 0.37f+tx, 0.05f);
    glEnd();
//side view
    glBegin(GL_QUADS);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( 0.1f+tx, -0.21f);
    glVertex2f( 0.47f+tx, -0.21f);
    glVertex2f( 0.47f+tx, -0.05f);
    glVertex2f( 0.1f+tx, -0.05f);
    glEnd();
//top front
    glBegin(GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f( 0.04f+tx, 0.08f);
    glVertex2f( 0.04f+tx, 0.004f);
    glVertex2f( 0.08f+tx, -0.04f);
    glVertex2f( 0.08f+tx, 0.04f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.04f+tx,0.08f);
    glVertex2f(0.04f+tx, 0.004f);
    glVertex2f(0.0f+tx, 0.05f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(0.08f+tx,-0.04f);
    glVertex2f(0.08f+tx, 0.04f);
    glVertex2f(0.1f+tx, -0.05f);
    glEnd();
//top
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.1f,1.0f);
    glVertex2f( 0.04f+tx, 0.08f);
    glVertex2f( 0.08f+tx, 0.04f);
    glVertex2f( 0.45f+tx, 0.04f);
    glVertex2f( 0.41f+tx, 0.08f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 1.0f);
    glVertex2f( 0.1f+tx, -0.05f);
    glVertex2f( 0.08f+tx, 0.04f);
    glVertex2f( 0.45f+tx, 0.04f);
    glVertex2f( 0.47f+tx, -0.05f);
    glEnd();
//1st door
    glBegin(GL_QUADS);
    glColor3f( 0.0f, 0.0f, 0.0f);
    glVertex2f( 0.146f+tx, -0.21f);
    glVertex2f( 0.204f+tx, -0.21f);
    glVertex2f( 0.204f+tx, -0.095f);
    glVertex2f( 0.146f+tx, -0.095f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f( 1.0f, 1.0f, 0.0f);
    glVertex2f( 0.15f+tx, -0.21f);
    glVertex2f( 0.2f+tx, -0.21f);
    glVertex2f( 0.2f+tx, -0.1f);
    glVertex2f( 0.15f+tx, -0.1f);
    glEnd();

//2nd door

    glBegin(GL_QUADS);
    glColor3f( 0.0f, 0.0f, 0.0f);
    glVertex2f( 0.395f+tx, -0.21f);
    glVertex2f( 0.455f+tx, -0.21f);
    glVertex2f( 0.455f+tx, -0.095f);
    glVertex2f( 0.395f+tx, -0.095f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f( 1.0f, 1.0f, 0.0f);
    glVertex2f( 0.4f+tx, -0.21f);
    glVertex2f( 0.45f+tx, -0.21f);
    glVertex2f( 0.45f+tx, -0.1f);
    glVertex2f( 0.4f+tx, -0.1f);
    glEnd();

//windows

    glBegin(GL_QUADS);
    glColor3f( 0.0f, 0.0f, 0.0f);
    glVertex2f( 0.245f+tx, -0.095f);
    glVertex2f( 0.245f+tx, -0.155f);
    glVertex2f( 0.35f+tx, -0.155f);
    glVertex2f( 0.35f+tx, -0.095f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f( 1.0f, 1.0f, 0.0f);
    glVertex2f( 0.25f+tx, -0.1f);
    glVertex2f( 0.25f+tx, -0.15f);
    glVertex2f( 0.27f+tx, -0.15f);
    glVertex2f( 0.27f+tx, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.275f+tx, -0.1f);
    glVertex2f( 0.275f+tx, -0.15f);
    glVertex2f( 0.295f+tx, -0.15f);
    glVertex2f( 0.295f+tx, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.3f+tx, -0.1f);
    glVertex2f( 0.3f+tx, -0.15f);
    glVertex2f( 0.32f+tx, -0.15f);
    glVertex2f( 0.32f+tx, -0.1f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f( 0.325f+tx, -0.1f);
    glVertex2f( 0.325f+tx, -0.15f);
    glVertex2f( 0.345f+tx, -0.15f);
    glVertex2f( 0.345f+tx, -0.1f);
    glEnd();
}

void nightHead(){

    float tx = -0.1;
//top bar
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f( 0.04f+tx, 0.08f);
    glVertex2f( 0.04f+tx, 0.004f);
    glVertex2f( 0.08f+tx, -0.04f);
    glVertex2f( 0.08f+tx, 0.04f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.04f+tx,0.08f);
    glVertex2f(0.04f+tx, 0.004f);
    glVertex2f(0.0f+tx, 0.05f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(0.08f+tx,-0.04f);
    glVertex2f(0.08f+tx, 0.04f);
    glVertex2f(0.1f+tx, -0.05f);
    glEnd();

//extended part
    tx = -0.2;
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.1f,1.0f);
    glVertex2f( 0.14f+tx, 0.08f);
    glVertex2f( 0.18f+tx, 0.04f);
    glVertex2f( 0.45f+tx, 0.04f);
    glVertex2f( 0.41f+tx, 0.08f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 1.0f);
    glVertex2f( 0.2f+tx, -0.05f);
    glVertex2f( 0.18f+tx, 0.04f);
    glVertex2f( 0.45f+tx, 0.04f);
    glVertex2f( 0.5f+tx, -0.05f);
    glEnd();
//mid body
    glBegin(GL_QUADS);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( -0.1f, -0.05f);
    glVertex2f( -0.1f, -0.15f);
    glVertex2f( 0.1f, -0.15f);
    glVertex2f( 0.1f, -0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( -0.1f, -0.15f);
    glVertex2f( -0.1f, -0.11f);
    glVertex2f( -0.15f, -0.11f);
    glVertex2f( -0.15f, -0.15f);
    glEnd();

//glass
    glBegin(GL_QUADS);
    glColor3f( 1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1f, 0.05f);
    glVertex2f(-0.13f, -0.08f);
    glVertex2f(-0.07f, -0.13f);
    glVertex2f(0.0f,-0.05f);
    glEnd();
//lower body
    glBegin(GL_QUADS);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( -0.15f, -0.15f);
    glVertex2f( -0.15f, -0.21f);
    glVertex2f( 0.1f, -0.21f);
    glVertex2f( 0.1f, -0.15f);
    glEnd();

//front panel
    glBegin(GL_QUADS);
    glColor3f(0.43f,0.43f,0.0f);
    glVertex2f(-0.13f, -0.08f);
    glVertex2f(-0.18f, -0.13f);
    glVertex2f(-0.15f,-0.15f);
    glVertex2f(-0.07f, -0.13f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4335,0.4335,1);
    glVertex2f( -0.1f, -0.21f);
    glVertex2f( -0.1f, -0.15f);
    glVertex2f( -0.18f, -0.13f);
    glVertex2f( -0.2f, -0.21f);
    glEnd();

}

void nightTrain(){
    nightCompartment(1.2f);
    nightCompartment(0.8f);
    nightCompartment(0.4f);
    nightCompartment(0.0f);
    nightHead();
}

void nightRailway(){

    glBegin(GL_QUADS);
    glColor3f(0.7f,0.7f,0.7f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f ,-0.25f);
    glVertex2f(1.0f ,-0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2f,0.2f,0.2f);
    glVertex2f(1.0f, -0.25f);
    glVertex2f(-1.0f, -0.25f);
    glVertex2f(-1.0f ,-0.5f);
    glVertex2f(1.0f ,-0.5f);
    glEnd();


    railBridge();
    rails();
    glPushMatrix();
    glTranslatef(trainPosition,0.0f, 0.0f);
    nightTrain();
    glPopMatrix();
}

void nightRoads(){
    //_________________road__________
glBegin(GL_QUADS);
      glColor3f(.5f, 0.5f, 0.5f);
      glVertex2f(-1.0f, -0.5f);
      glVertex2f(-1.0f, -1.0f);
      glVertex2f(1.0f, -1.0f);
      glVertex2f(1.0f, -0.5f);
 glEnd();
glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.0f, -0.75f);
      glVertex2f(0.0f, -0.77f);
      glVertex2f(0.1f, -0.77f);
      glVertex2f(.1f, -.75f);
 glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.12f, -0.75f);
      glVertex2f(0.12f, -0.77f);
      glVertex2f(0.22f, -0.77f);
      glVertex2f(.22f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.24f, -0.75f);
      glVertex2f(0.24f, -0.77f);
      glVertex2f(0.34f, -0.77f);
      glVertex2f(.34f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.36f, -0.75f);
      glVertex2f(0.36f, -0.77f);
      glVertex2f(0.46f, -0.77f);
      glVertex2f(.46f, -.75f);
 glEnd();
 //=====
  glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.48f, -0.75f);
      glVertex2f(0.48f, -0.77f);
      glVertex2f(0.58f, -0.77f);
      glVertex2f(.58f, -.75f);
 glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.6f, -0.75f);
      glVertex2f(0.6f, -0.77f);
      glVertex2f(0.7f, -0.77f);
      glVertex2f(.7f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.72f, -0.75f);
      glVertex2f(0.72f, -0.77f);
      glVertex2f(0.82f, -0.77f);
      glVertex2f(.82f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.84f, -0.75f);
      glVertex2f(0.84f, -0.77f);
      glVertex2f(0.94f, -0.77f);
      glVertex2f(.94f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(0.96f, -0.75f);
      glVertex2f(0.96f, -0.77f);
      glVertex2f(1.0f, -0.77f);
      glVertex2f(1.0f, -.75f);
 glEnd();
 //--

 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.2f, -0.75f);
      glVertex2f(-0.2f, -0.77f);
      glVertex2f(-0.1f, -0.77f);
      glVertex2f(-0.1f, -.75f);
 glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.12f, -0.75f);
      glVertex2f(-0.12f, -0.77f);
      glVertex2f(-0.22f, -0.77f);
      glVertex2f(-0.22f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.24f, -0.75f);
      glVertex2f(-0.24f, -0.77f);
      glVertex2f(-0.34f, -0.77f);
      glVertex2f(-0.34f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.36f, -0.75f);
      glVertex2f(-0.36f, -0.77f);
      glVertex2f(-0.46f, -0.77f);
      glVertex2f(-0.46f, -.75f);
 glEnd();

 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.48f, -0.75f);
      glVertex2f(-0.48f, -0.77f);
      glVertex2f(-0.58f, -0.77f);
      glVertex2f(-0.58f, -.75f);
 glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.6f, -0.75f);
      glVertex2f(-0.6f, -0.77f);
      glVertex2f(-0.7f, -0.77f);
      glVertex2f(-0.7f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.72f, -0.75f);
      glVertex2f(-0.72f, -0.77f);
      glVertex2f(-0.82f, -0.77f);
      glVertex2f(-0.82f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.84f, -0.75f);
      glVertex2f(-0.84f, -0.77f);
      glVertex2f(-0.94f, -0.77f);
      glVertex2f(-0.94f, -.75f);
 glEnd();
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.96f, -0.75f);
      glVertex2f(-0.96f, -0.77f);
      glVertex2f(-1.0f, -0.77f);
      glVertex2f(-1.0f, -.75f);
 glEnd();
//-------car1------------------------

 glLoadIdentity();
glPushMatrix();
glTranslatef(carPosition,0.0f, 0.0f);

   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.0f, -0.6f);
      glVertex2f(0.0f, -0.7f);
      glVertex2f(0.3f, -0.7f);
      glVertex2f(0.3f, -0.6f);
   glEnd();

   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.1f, 0.0f);
      glVertex2f(0.05f, -0.6f);
      glVertex2f(0.25f, -0.6f);
      glVertex2f(0.2f, -0.54f);
      glVertex2f(0.1f, -0.54f);
   glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.06f, -0.6f);
      glVertex2f(0.24f, -0.6f);
      glVertex2f(0.2f, -0.55f);
      glVertex2f(0.1f, -0.55f);
   glEnd();

glBegin(GL_QUADS);
      glColor3f(1.0f, 0.1f, 0.0f);
      glVertex2f(0.15f, -0.54f);
      glVertex2f(0.15f, -0.7f);
      glVertex2f(0.16f, -0.7f);
      glVertex2f(0.16f, -0.54f);
   glEnd();
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.27f, -0.62f);
      glVertex2f(0.29f, -0.62f);
      glVertex2f(0.29f, -0.66f);
   glEnd();

  glColor3f(.3f, .3f, .3f);
    DrawCircle(0.09, -0.7, .03, 10000);
  glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(0.09, -0.7, .01, 10000);
    glColor3f(.3f, .3f, .3f);
    DrawCircle(0.22, -0.7, .03, 10000);
  glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(0.22, -0.7, .01, 10000);

glPopMatrix();
//-------bus------------------------
glPushMatrix();
glTranslatef(carPosition2,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(.0f, 0.0f, 1.0f);
      glVertex2f(0.2f, -0.8f);
      glVertex2f(0.2f, -0.95f);
      glVertex2f(0.7f, -0.95f);
      glVertex2f(0.7f, -0.8f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.27f, -0.85f);
      glVertex2f(0.27f, -0.9f);
      glVertex2f(0.37f, -0.9f);
      glVertex2f(0.37f, -0.85f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.39f, -0.85f);
      glVertex2f(0.39f, -0.9f);
      glVertex2f(0.49f, -0.9f);
      glVertex2f(0.49f, -0.85f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.51f, -0.85f);
      glVertex2f(0.51f, -0.9f);
      glVertex2f(0.61f, -0.9f);
      glVertex2f(0.61f, -0.85f);
   glEnd();
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.62f, -0.84f);
      glVertex2f(0.62f, -0.93f);
      glVertex2f(0.66f, -0.93f);
      glVertex2f(0.66f, -0.84f);
   glEnd();
glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(0.67f, -0.88f);
      glVertex2f(0.69f, -0.88f);
      glVertex2f(0.69f, -0.92f);
   glEnd();

   glColor3f(.3f, .3f, .3f);
    DrawCircle(0.37, -0.95, .03, 10000);
  glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(0.37, -0.95, .01, 10000);
    glColor3f(.3f, .3f, .3f);
    DrawCircle(0.58, -0.95, .03, 10000);
  glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(0.58, -0.95, .01, 10000);
glPopMatrix();

}

void midnight(){
    glClear(GL_COLOR_BUFFER_BIT);

   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glLoadIdentity();
    nightSky();
    nightBuildings();
    nightRailway();
    nightRoads();
    glFlush();
}

void rainNight(){
    glClear(GL_COLOR_BUFFER_BIT);

   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glLoadIdentity();
    nightSky();
    nightBuildings();
    nightRailway();
    nightRoads();
    rain();
    glFlush();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			trainSpeed += 0.1f;
			carSpeed += 0.1f;
			carSpeed2 += 0.1f;
			cout<<"Speed up"<<endl;
		}
	}
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{

			trainSpeed -= 0.1f;
			carSpeed -= 0.1f;
			carSpeed2 -= 0.1f;
            cout<<"Speed down"<<endl;
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

    case 'a':
        carSpeed += 0.1f;
        break;
    case 'b':
        carSpeed2 += 0.1f;

    case 'r':
        glutDisplayFunc(rainNight);
        break;
    case 't':
        trainSpeed += 0.1f;
        break;
    case 'y':
        trainSpeed -= 0.1f;
        break;
    case 'd':
        glutDisplayFunc(display);
        break;
    case 'n':
        glutDisplayFunc(midnight);
        break;


    glutPostRedisplay();


	}
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1080, 720);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("City View");
   glutDisplayFunc(display);
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}

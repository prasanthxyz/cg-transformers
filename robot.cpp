#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "transformer.h"

using namespace std;

Transformer T;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   T.draw_left_arm();
}


void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   //hip

   glPushMatrix();
   glColor3f(0.96,0.8,0.69);
   glRotatef ((GLfloat) T.fullz, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.fullx,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.fully, 0.0, 1.0, 0.0);
   glPushMatrix();
   glTranslatef(0.0,-1.1,0.0);
   glScalef(1.6,0.3,1.0);
   glutSolidCube(1.0);
   glPopMatrix();
 
   //torso

   glPushMatrix();
   glTranslatef(0.0,-1.1,0.0);
   glRotatef ((GLfloat) T.bend, 1.0, 0.0, 0.0);
   glTranslatef(0.0,1.1,0.0);
   glPushMatrix();
   glScalef(1.6,2.0,1.0);
   glutSolidCube(1.0);
   glPopMatrix();
 
   //head		 
 
   glPushMatrix();
   glTranslatef (0.0, 1.9, 0.0);
   glRotatef ((GLfloat) T.headside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.headforward,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.headcurve, 0.0, 1.0, 0.0);
   glutSolidSphere(0.7,12,32);
   glColor3f(0,0,0);
   glPushMatrix();
   glTranslatef(-0.4,0.1,0.0);
   glutSolidSphere(0.15,32,32);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.4,0.1,0.0);
   glutSolidSphere(0.15,32,32);
   glPopMatrix();
   glColor3f(0.96,0.8,0.69);  
   glPopMatrix();
   
   //neck
   
   glPushMatrix();
   glTranslatef (0.0, 1.3, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   gluCylinder(T.neck,0.35f,0.35f,0.3f,32,32);
   glPopMatrix();
   glPopMatrix();
   
   //righthand
   
   glPushMatrix();
   glTranslatef (-1.0, 0.9, 0.0);
   glRotatef ((GLfloat) T.rshoulderside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.rshoulderforward,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.rshouldercurve ,0.0, 1.0, 0.0);
   glPushMatrix();
   glutSolidSphere(0.25,32,32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f,1.0f, 0.0f);
   gluCylinder(T.rshoulderhand,0.2f,0.2f,1.2f,32,32);
   glPopMatrix();
   glTranslatef (1.3, 0.0, 0.0);
   glutSolidSphere(0.2,32,32);
   glRotatef ((GLfloat) T.relbow, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.relbowhand,0.2f,0.2f,1.5f,32,32);
   glPopMatrix();
   glPopMatrix();

   //lefthand
   
   glPushMatrix();
   glTranslatef (1.0, 0.9, 0.0);
   glRotatef ((GLfloat) T.lshoulderside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.lshoulderforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.lshouldercurve, 0.0, 1.0, 0.0);
   glCallList(T.left_arm);
   glPopMatrix();
   glPopMatrix();

   //rightleg

   glPushMatrix();
   glTranslatef (-0.58, -1.38, 0.0);
   glRotatef ((GLfloat) T.rltcurve, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) T.rltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.rltside, 0.0, 0.0, 1.0);
   glPushMatrix();
   glutSolidSphere(0.35,32,32);
   glRotatef(90.0f, 0.0f,1.0f, 0.0f);
   gluCylinder(T.rtopleg,0.3f,0.3f,1.0f,32,32);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glutSolidSphere(0.3,32,32);
   glRotatef ((GLfloat) T.rlbforward, 0.0, 1.0, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.rbottomleg,0.3f,0.3f,1.2f,32,32);
   glPopMatrix();
   glTranslatef(1.3,0.0,0.2);
   glPushMatrix();
   glScalef(0.2,0.6,1.0);
   glutSolidCube(1.0);
   glPopMatrix();
   glPopMatrix();   

   //leftleg   

   glPushMatrix();
   glTranslatef (0.58, -1.38, 0.0);
   glRotatef ((GLfloat) T.lltcurve, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) T.lltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.lltside, 0.0, 0.0, 1.0);
   glPushMatrix();
   glutSolidSphere(0.35,32,32);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.ltopleg,0.3f,0.3f,1.0f,32,32);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glutSolidSphere(0.3,32,32);
   glRotatef ((GLfloat) T.llbforward, 0.0, 1.0, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.lbottomleg,0.3f,0.3f,1.2f,32,32);
   glPopMatrix();
   glTranslatef(1.3,0.0,0.2);
   glPushMatrix();

   glScalef(0.2,0.6,1.0);
   glutSolidCube(1.0);
   glPopMatrix();
   glPopMatrix();
   glColor3f(1,0.5,0.5);

   glPopMatrix();


   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(90.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}
void timer(int value)
{
   if(T.fullx==0&&T.fully==0&&T.fullz==0&&T.bend==0&&T.headside==0&&T.headforward==0&&T.headcurve==0&&T.rshoulderside==-135&&T.rshoulderforward==0&&T.rshouldercurve==0&&T.relbow==90&&T.lshoulderside==-45&&T.lshoulderforward==0&&T.lshouldercurve==0&&T.lelbow==-90&&T.rltside==-90&&T.rltforward==0&&T.rltcurve==0&&T.rlbforward==0&&T.lltside==-90&&T.lltforward==0&&T.lltcurve==0&&T.llbforward==0)
   return;
   T.transform();
   glutPostRedisplay();
glutTimerFunc(100,timer,0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) 
   {
      case 'v':
      T.rotateX(5);
      break;
      case 'V':
      T.rotateX(-5);
      break;
      case 'b':
      T.rotateY(5);
      break;
      case 'B':
      T.rotateY(-5);
      break;
      case 'n':
      T.rotateZ(5);
      break;
      case 'N':
      T.rotateZ(-5);
      break;

      case 'z':
      if(T.headside<=45)
      T.tiltHeadSide(5);
      break;
      case 'Z':
      if(T.headside>=-45)
      T.tiltHeadSide(-5);
      break;
      case 'x':
      if(T.headforward<45)
      T.tiltHeadFB(5);
      break;
      case 'X':
      if(T.headforward>=-90)
      T.tiltHeadFB(-5);
      break;
      case 'c':
      if(T.headcurve<=90)
      T.turnHead(5);
      break;
      case 'C':
      if(T.headcurve>=-90)
      T.turnHead(-5);
      break;

      case 't':
      if(T.bend<=180)
      T.bendForward(5);
      break;
      case 'y':
      if(T.bend>=-90)
      T.bendBack(-5);
      break;

      case 'a':
      T.rShoulderSide(5);
      break;
      case 'A':
      T.rShoulderSide(-5);
      break;
      case 's':
      T.rShoulderFB(5);
      break;
      case 'S':
      T.rShoulderFB(-5);
      break;
      case 'd':
      T.rShoulderCurve(5);
      break;
      case 'D':
      T.rShoulderCurve(-5);
      break;
      case 'f':
      T.rElbowBend(5);
      break;
      case 'F':
      T.rElbowBend(-5);
      break;

      case 'q':
      T.lShoulderSide(5);
      break;
      case 'Q':
      T.lShoulderSide(-5);
      break;
      case 'w':
      T.lShoulderFB(5);
      break;              
      case 'W':
      T.lShoulderFB(-5);
      break;                                            
      case 'e':
      T.lShoulderCurve(5);
      break;
      case 'E':
      T.lShoulderCurve(-5);
      break;
      case 'r':
      T.lElbowBend(5);
      break;
      case 'R':
      T.lElbowBend(-5);
      break;

      case 'h':
      if(T.rltside<=0)
      T.rLegSide(5);
      break;
      case 'H':
      if(T.rltside>=-180)
      T.rLegSide(-5);
      break;
      case 'j':
      if(T.rltforward<=90)
      T.rLegFB(5);
      break;
      case 'J':
      if(T.rltforward>=-180)
      T.rLegFB(-5);
      break;
      case 'k':
      if(T.rltcurve<=90)
      T.rLegCurve(5);
      break;
      case 'K':
      if(T.rltcurve>=-90)
      T.rLegCurve(-5);
      break;
      case 'l':
      if(T.rlbforward<=180)
      T.rCalfFB(5);
      break;
      case 'L':
      if(T.rlbforward>=T.rltforward)
      T.rCalfFB(-5);
      break;

      case 'u':
      if(T.lltside<=0)
      T.lLegSide(5);
      break;
      case 'U':
      if(T.lltside>=-180)
      T.lLegSide(-5);
      break;
      case 'i':
      if(T.lltforward<=90)
      T.lLegFB(5);
      break;
      case 'I':
      if(T.lltforward>=-180)
      T.lLegFB(-5);
      break;
      case 'o':
      if(T.lltcurve<=90)
      T.lLegCurve(5);
      break;
      case 'O':
      if(T.lltcurve>=-90)
      T.lLegCurve(-5);
      break;
      case 'p':
      if(T.llbforward<=180)
      T.lCalfFB(5);
      break;
      case 'P':
      if(T.llbforward>=T.lltforward)
      T.lCalfFB(-5);
      break;

      case 'g':
    timer(0);
    break;

      case 27:
      break;
      default:
      break;


   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

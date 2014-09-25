#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

#include "transformer.h"

using namespace std;


Transformer T;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();

   glColor3f(0.96, 0.8, 0.69);
   glRotatef ((GLfloat) T.fullz, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.fullx, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.fully, 0.0, 1.0, 0.0);
   glPushMatrix();

   glTranslatef(0.0, -1.1, 0.0);
   glScalef(1.6, 0.3, 1.0);
   glutSolidCube(1.0);
   glPopMatrix();

   //head		 
   glPushMatrix();
   glTranslatef (0.0, 2.0, 0.0);
   glRotatef ((GLfloat) T.headside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.headforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.headcurve, 0.0, 1.0, 0.0);
   glutSolidSphere(0.7, 32, 32);

   //eyes
   glColor3f(0, 0, 0);
   glPushMatrix();
   glTranslatef(-0.4, 0.1, 0.0);
   glutSolidSphere(0.15, 32, 32);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.4, 0.1, 0.0);
   glutSolidSphere(0.15, 32, 32);
   glPopMatrix();
   glColor3f(0.96, 0.8, 0.69);  
   glPopMatrix();

   //neck
   glPushMatrix();
   glTranslatef (0.0, 1.4, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   gluCylinder(T.neck, 0.35f, 0.35f, 0.3f, 32, 32);
   glPopMatrix();
   glPopMatrix();

   //righthand
   glPushMatrix();
   glTranslatef (1.0, 0.9, 0.0);
   glRotatef ((GLfloat) T.rshoulder, 0.0, 0.0, 1.0);
   glPushMatrix();
   glutSolidSphere(0.2, 32, 32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.rshoulderhand, 0.2f, 0.2f, 1.2f, 32, 32);
   glPopMatrix();
   glTranslatef (1.3, 0.0, 0.0);
   glRotatef ((GLfloat) T.relbow, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.relbowhand, 0.2f, 0.2f, 1.5f, 32, 32);
   glPopMatrix();
   glPopMatrix();

   //lefthand
   glPushMatrix();
   glTranslatef (-1.0, 0.9, 0.0);
   glRotatef ((GLfloat) T.lshoulder, 0.0, 0.0, 1.0);
   glPushMatrix();
   glutSolidSphere(0.2, 32, 32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.lshoulderhand, 0.2f, 0.2f, 1.2f, 32, 32);
   glPopMatrix();
   glTranslatef (1.3, 0.0, 0.0);
   glRotatef ((GLfloat) T.lelbow, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.lelbowhand, 0.2f, 0.2f, 1.5f, 32, 32);
   glPopMatrix();
   glPopMatrix();

   //body  
   glPushMatrix();
   glScalef(1.6, 2.0, 1.0);
   glutSolidCube(1.0);
   glPopMatrix();

   //rightleg
   glPushMatrix();
   glTranslatef (0.58, -1.38, 0.0);
   glRotatef ((GLfloat) T.rltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.rltside, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.rtopleg, 0.3f, 0.3f, 1.0f, 32, 32);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.rlbforward, 0.0, 1.0, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.rbottomleg, 0.3f, 0.3f, 1.2f, 32, 32);
   glPopMatrix();
   glPopMatrix();

   //leftleg   
   glPushMatrix();
   glTranslatef (-0.58, -1.38, 0.0);
   glRotatef ((GLfloat) T.lltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.lltside, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.ltopleg, 0.3f, 0.3f, 1.0f, 32, 32);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.llbforward, 0.0, 1.0, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.lbottomleg, 0.3f, 0.3f, 1.2f, 32, 32);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -6.0);
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
	  T.tiltHeadSide(5);
	  break;
	  case 'Z':
	  T.tiltHeadSide(-5);
	  break;
	  case 'x':
	  T.tiltHeadFB(5);
	  break;
	  case 'X':
	  T.tiltHeadFB(-5);
	  break;
	  case 'c':
	  T.turnHead(5);
	  break;
	  case 'C':
	  T.turnHead(-5);
	  break;

	  case 's':
	  T.rShoulderSide(5);
	  break;
	  case 'S':
	  T.rShoulderSide(-5);
	  break;
	  case 'e':
	  T.rElbowBend(5);
	  break;
	  case 'E':
	  T.rElbowBend(-5);
	  break;
	  case 'd':
	  T.lShoulderSide(5);
	  break;
	  case 'D':
	  T.lShoulderSide(-5);
	  break;
	  case 'r':
	  T.lElbowBend(5);
	  break;
	  case 'R':
	  T.lElbowBend(-5);
	  break;
	  case 'j':
	  T.rLegSide(5);
	  break;
	  case 'J':
	  T.rLegSide(-5);
	  break;
	  case 'k':
	  T.rLegFB(5);
	  break;
	  case 'K':
	  T.rLegFB(-5);
	  break;
	  case 'l':
	  T.rCalfFB(5);
	  break;
	  case 'L':
	  T.rCalfFB(-5);
	  break;

	  case 'i':
	  T.lLegSide(5);
	  break;
	  case 'I':
	  T.lLegSide(-5);
	  break;
	  case 'o':
	  T.lLegFB(5);
	  break;
	  case 'O':
	  T.lLegFB(-5);
	  break;

	  case 'p':
	  T.lCalfFB(5);
	  break;
	  case 'P':
	  T.lCalfFB(-5);
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
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

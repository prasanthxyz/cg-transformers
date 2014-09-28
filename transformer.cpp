#include <GL/glew.h>
#include <GL/glut.h>
#include<unistd.h>
#include <GLFW/glfw3.h>

#include "transformer.h"

Transformer::Transformer()
{

   fullx=0; fully=0; fullz=0;
   bend=0;
   headside=0; headforward=0; headcurve=0;
   rshoulderside=-135; rshoulderforward=0; rshouldercurve=0; relbow=90;
   lshoulderside=-45; lshoulderforward=0; lshouldercurve=0; lelbow=-90;
   rltside=-90; rltforward=0; rltcurve=0; rlbforward=0;
   lltside=-90; lltforward=0; lltcurve=0; llbforward=0;

   Cneck = gluNewQuadric();
   rshoulderhand = gluNewQuadric();
   relbowhand = gluNewQuadric();
   lshoulderhand = gluNewQuadric();
   lelbowhand = gluNewQuadric();
   rtopleg = gluNewQuadric();
   rbottomleg = gluNewQuadric();
   ltopleg = gluNewQuadric();
   lbottomleg = gluNewQuadric();
}
void Transformer::rotateX(int angle)
{
   fullx = (fullx + angle) % 360;
   glutPostRedisplay();
}
void Transformer::rotateY(int angle)
{
   fully = (fully + angle) % 360;
   glutPostRedisplay();
}
void Transformer::rotateZ(int angle)
{
   fullz = (fullz + angle) % 360;
   glutPostRedisplay();
}

void Transformer::tiltHeadSide(int angle)
{
   headside = (headside + angle) % 360;
   glutPostRedisplay();
}
void Transformer::tiltHeadFB(int angle)
{
   headforward = (headforward + angle) % 360;
   glutPostRedisplay();
}
void Transformer::turnHead(int angle)
{
   headcurve = (headcurve + angle) % 360;
   glutPostRedisplay();
}
void Transformer::bendForward(int angle)
{
   bend = (bend + angle) % 360;
   glutPostRedisplay();
}
void Transformer::bendBack(int angle)
{
   bend = (bend + angle) % 360;
   glutPostRedisplay();
}


void Transformer::rShoulderSide(int angle)
{
   rshoulderside = (rshoulderside + angle) % 360;
   glutPostRedisplay();
}
void Transformer::rShoulderFB(int angle)
{
   rshoulderforward = (rshoulderforward + angle) % 360;
   glutPostRedisplay();
}
void Transformer::rShoulderCurve(int angle)
{
   rshouldercurve = (rshouldercurve + angle) % 360;
   glutPostRedisplay();
}

void Transformer::rElbowBend(int angle)
{
   relbow = (relbow + angle) % 360;
   glutPostRedisplay();
}
void Transformer::lShoulderSide(int angle)
{
   lshoulderside = (lshoulderside + angle) % 360;
   glutPostRedisplay();
}
void Transformer::lShoulderFB(int angle)
{
   lshoulderforward = (lshoulderforward + angle) % 360;
   glutPostRedisplay();
}
void Transformer::lShoulderCurve(int angle)
{
   lshouldercurve = (lshouldercurve + angle) % 360;
   glutPostRedisplay();
}

void Transformer::lElbowBend(int angle)
{
   lelbow = (lelbow + angle) % 360;
   glutPostRedisplay();
}
void Transformer::rLegSide(int angle)
{
   rltside = (rltside + angle) % 360;
   glutPostRedisplay();
}
void Transformer::rLegFB(int angle)
{
   rltforward = (rltforward + angle) % 360;
   glutPostRedisplay();
}
void Transformer::rLegCurve(int angle)
{
   rltcurve = (rltcurve + angle) % 360;
   glutPostRedisplay();
}

void Transformer::rCalfFB(int angle)
{
   rlbforward = (rlbforward + angle) % 360;
   glutPostRedisplay();
}
void Transformer::lLegSide(int angle)
{
   lltside = (lltside + angle) % 360;
   glutPostRedisplay();
}
void Transformer::lLegFB(int angle)
{
   lltforward = (lltforward + angle) % 360;
   glutPostRedisplay();
}
void Transformer::lLegCurve(int angle)
{
   lltcurve = (lltcurve + angle) % 360;
   glutPostRedisplay();
}

void Transformer::lCalfFB(int angle)
{
   llbforward = (llbforward + angle) % 360;
   glutPostRedisplay();
}


void Transformer::draw_left_arm(void)
{
   left_arm=glGenLists(1);
   glNewList(left_arm,GL_COMPILE);

   glutSolidSphere(0.25,32,32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(lshoulderhand,0.2f,0.2f,1.2f,32,32);

   glEndList();
}

void Transformer::draw_left_elbow()
{
   left_elbow=glGenLists(1);
   glNewList(left_elbow,GL_COMPILE);

   glTranslatef (1.3, 0.0, 0.0);
   glutSolidSphere(0.2,32,32);

   glEndList();
}

void Transformer::draw_left_forearm()
{
   left_forearm = glGenLists(1);
   glNewList(left_forearm,GL_COMPILE);

   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(lelbowhand,0.2f,0.2f,1.5f,32,32);

   glEndList();
}

void Transformer::draw_right_elbow()
{
   right_elbow = glGenLists(1);
   glNewList(right_elbow, GL_COMPILE);

   glTranslatef (1.3, 0.0, 0.0);
   glutSolidSphere(0.2,32,32);

   glEndList();
}

void Transformer::draw_right_arm()
{
   right_arm = glGenLists(1);
   glNewList(right_arm, GL_COMPILE);

   glutSolidSphere(0.25,32,32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f,1.0f, 0.0f);
   gluCylinder(rshoulderhand,0.2f,0.2f,1.2f,32,32);

   glEndList();
}

void Transformer::draw_right_forearm()
{
   right_forearm = glGenLists(1);
   glNewList(right_forearm, GL_COMPILE);

   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(relbowhand,0.2f,0.2f,1.5f,32,32);

   glEndList();
}

void Transformer::draw_hip()
{
   hip = glGenLists(1);
   glNewList(hip, GL_COMPILE);
   
   glTranslatef(0.0,-1.1,0.0);
   glScalef(1.6,0.3,1.0);
   glutSolidCube(1.0);
 
   glEndList();
}

void Transformer::draw_torso()
{
   torso = glGenLists(1);
   glNewList(torso, GL_COMPILE);

   glScalef(1.6,2.0,1.0);
   glutSolidCube(1.0);
 
   glEndList();
}

void Transformer::draw_head()
{
   head = glGenLists(1);
   glNewList(head, GL_COMPILE);

   glutSolidSphere(0.7,12,32);

   glEndList();
}

void Transformer::draw_eyes()
{
	eyes = glGenLists(1);
	glNewList(eyes, GL_COMPILE);

	glTranslatef(-0.4,0.1,0.0);
	glutSolidSphere(0.15,32,32);
	glTranslatef(0.8,0,0);
	glutSolidSphere(0.15,32,32);

	glEndList();
}

void Transformer::draw_neck()
{
   neck = glGenLists(1);
   glNewList(neck, GL_COMPILE);

   glTranslatef (0.0, 1.3, 0.0);
   //glPushMatrix();
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   gluCylinder(Cneck,0.35f,0.35f,0.3f,32,32);
   //glPopMatrix();
	
   glEndList();
}

void Transformer::draw_right_thigh()
{
  	right_thigh = glGenLists(1);
	glNewList(right_thigh, GL_COMPILE);

   glutSolidSphere(0.35,32,32);
   glRotatef(90.0f, 0.0f,1.0f, 0.0f);
   gluCylinder(rtopleg,0.3f,0.3f,1.0f,32,32);

   glEndList();
}

void Transformer::draw_right_knee()
{
   right_knee = glGenLists(1);
   glNewList(right_knee, GL_COMPILE);

   glTranslatef (1.0, 0.0, 0.0);
   glutSolidSphere(0.3,32,32);

   glEndList();
}

void Transformer::draw_right_calf()
{
   right_calf = glGenLists(1);
   glNewList(right_calf, GL_COMPILE);

   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(rbottomleg,0.3f,0.3f,1.2f,32,32);

   glEndList();
}

void Transformer::draw_right_foot()
{
   right_foot = glGenLists(1);
   glNewList(right_foot, GL_COMPILE);

   glTranslatef(1.3,0.0,0.2);
   glScalef(0.2,0.6,1.0);
   glutSolidCube(1.0);

   glEndList();
}

void Transformer::draw_left_thigh()
{
   left_thigh = glGenLists(1);
   glNewList(left_thigh, GL_COMPILE);

   glutSolidSphere(0.35,32,32);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(ltopleg,0.3f,0.3f,1.0f,32,32);

   glEndList();
}

void Transformer::draw_left_knee()
{
   left_knee = glGenLists(1);
   glNewList(left_knee, GL_COMPILE);

   glTranslatef (1.0, 0.0, 0.0);
   glutSolidSphere(0.3,32,32);

   glEndList();

}

void Transformer::draw_left_calf()
{ 
   left_calf = glGenLists(1);
   glNewList(left_calf, GL_COMPILE);

   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(lbottomleg,0.3f,0.3f,1.2f,32,32);

   glEndList();

}

void Transformer::draw_left_foot()
{ 
   left_foot = glGenLists(1);
   glNewList(left_foot, GL_COMPILE);

   glTranslatef(1.3,0.0,0.2);
   glScalef(0.2,0.6,1.0);
   glutSolidCube(1.0);

   glEndList();
}

void Transformer::transform()
{ 
   if(fullx>0)
	  fullx=(fullx-5)%360;
   else if(fullx<0)
	  fullx=(fullx+5)%360;
   if(fully>0)
	  fully=(fully-5)%360;
   else if(fully<0)
	  fully=(fully+5)%360;
   if(fullz>0)
	  fullz=(fullz-5)%360;
   else if(fullz<0)
	  fullz=(fullz+5)%360;
   if(bend>0)
	  bend=(bend-5)%360;
   else if(bend<0)
	  bend=(bend+5)%360;
   if(headside>0)
	  headside=(headside-5)%360;
   else if(headside<0)
	  headside=(headside+5)%360;
   if(headforward>0)
	  headforward=(headforward-5)%360;
   else if(headforward<0)
	  headforward=(headforward+5)%360;
   if(headcurve>0)
	  headcurve=(headcurve-5)%360;
   else if(headcurve<0)
	  headcurve=(headcurve+5)%360;
   if(rshoulderside>-135)
	  rshoulderside=(rshoulderside-5)%360;
   else if(rshoulderside<-135)
	  rshoulderside=(rshoulderside+5)%360;
   if(rshoulderforward>0)
	  rshoulderforward=(rshoulderforward-5)%360;
   else if(rshoulderforward<0)
	  rshoulderforward=(rshoulderforward+5)%360;
   if(rshouldercurve>0)
	  rshouldercurve=(rshouldercurve-5)%360;
   else if(rshouldercurve<0)
	  rshouldercurve=(rshouldercurve+5)%360;
   if(relbow>90)
	  relbow=(relbow-5)%360;
   else if(relbow<90)
	  relbow=(relbow+5)%360;
   if(lshoulderside>-45)
	  lshoulderside=(lshoulderside-5)%360;
   else if(lshoulderside<-45)
	  lshoulderside=(lshoulderside+5)%360;
   if(lshoulderforward>0)
	  lshoulderforward=(lshoulderforward-5)%360;
   else if(lshoulderforward<-0)
	  lshoulderforward=(lshoulderforward+5)%360;
   if(lshouldercurve>0)
	  lshouldercurve=(lshouldercurve-5)%360;
   else if(lshouldercurve<0)
	  lshouldercurve=(lshouldercurve+5)%360;
   if(lelbow>-90)
	  lelbow=(lelbow-5)%360;
   else if(lelbow<-90)
	  lelbow=(lelbow+5)%360;

   if(lltside>-90)
	  lltside=(lltside-5)%360;
   else if(lltside<-90)
   lltside=(lltside+5)%360;
   if(lltforward>0)
   lltforward=(lltforward-5)%360;
   else if(lltforward<0)
   lltforward=(lltforward+5)%360;
   if(lltcurve>0)
   lltcurve=(lltcurve-5)%360;
   else if(lltcurve<0)
   lltcurve=(lltcurve+5)%360;
   if(llbforward>0)
   llbforward=(llbforward-5)%360;
   else if(llbforward<0)
   llbforward=(llbforward+5)%360;

   if(rltside>-90)
   rltside=(rltside-5)%360;
   else if(rltside<-90)
   rltside=(rltside+5)%360;
   if(rltforward>0)
   rltforward=(rltforward-5)%360;
   else if(rltforward<0)
   rltforward=(rltforward+5)%360;
   if(rltcurve>0)
   rltcurve=(rltcurve-5)%360;
   else if(rltcurve<0)
   rltcurve=(rltcurve+5)%360;
   if(rlbforward>0)
   rlbforward=(rlbforward-5)%360;
   else if(rlbforward<0)
   rlbforward=(rlbforward+5)%360;

}



#include <GL/glew.h>
#include <GL/glut.h>
#include<unistd.h>
#include <GLFW/glfw3.h>

#include "transformer.h"

Transformer::Transformer()
{

   fullx=0;
   fully=0;
   fullz=0;
   bend=0;
   headside=0;
   headforward=0;
   headcurve=0;
   rshoulderside= -135;
   rshoulderforward=0;
   rshouldercurve=0;
   relbow =90;
   lshoulderside=-45;
   lshoulderforward=0;
   lshouldercurve=0;
   lelbow=-90;
   rltside=-90;
   rltforward=0;
   rltcurve=0;
   rlbforward=0;
   lltside=-90;
   lltforward=0;
   lltcurve=0;
   llbforward=0;
     
   neck = gluNewQuadric();
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



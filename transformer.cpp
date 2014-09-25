#include <GL/glew.h>
#include <GL/glut.h>

#include "transformer.h"

Transformer::Transformer()
{
   rshoulder = -45;
   relbow = 0;
   fullx = 0;
   fully = 0;
   fullz = 0;
   headside = 0;
   headforward = 0;
   headcurve = 0;
   lshoulder = -135;
   lelbow = 0;
   lltside = -90;
   lltforward = 0;
   rltside = -90;
   rltforward = 0;
   llbforward = 0;
   rlbforward = 0;
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
void Transformer::rShoulderSide(int angle)
{
   rshoulder = (rshoulder + angle) % 360;
   glutPostRedisplay();
}
void Transformer::rElbowBend(int angle)
{
   relbow = (relbow + angle) % 360;
   glutPostRedisplay();
}
void Transformer::lShoulderSide(int angle)
{
   lshoulder = (lshoulder + angle) % 360;
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
void Transformer::lCalfFB(int angle)
{
   llbforward = (llbforward + angle) % 360;
   glutPostRedisplay();
}


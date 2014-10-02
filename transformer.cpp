#include <GL/glew.h>
#include "transformer.h"
Transformer::Transformer()
{

   fullx=0; fully=0; fullz=0;
   bend=0;
   headside=0; headforward=0; headcurve=0;
   rshoulderside=-135; rshoulderforward=0; rshouldercurve=0; relbow=90;
   lshoulderside=-45; lshoulderforward=0; lshouldercurve=0; lelbow=-90;
   rltside=-90; rltforward=0; rltcurve=0; rlbforward=0;
   ldoor=0.0;
   rdoor=0.0;
   rshift=0.0;
   lshift=0.0;
   upshift=1.6;
   move=0.0;
   fronttyretrans=0.0;
   backtyretrans=0.0;
   lltside=-90; lltforward=0; lltcurve=0; llbforward=0;
   vehiclefront=0;
   carfront=0.0;
   down=0.0;
   rfootrot=0.0;
   lfootrot=0.0;
   carback=0.0;
   carbackshift=0.0;
   draw_left_shoulder();
   draw_left_arm();
   draw_left_elbow();
   draw_left_forearm();
   draw_right_shoulder();
   draw_right_arm();
   draw_right_elbow();
   draw_right_forearm();
   draw_hip();
   draw_torso();
   draw_head();
   draw_eyes();
   draw_neck();

   draw_left_butt();
   draw_left_thigh();
   draw_left_knee();
   draw_left_calf();
   draw_left_foot();
   draw_right_butt();
   draw_right_thigh();
   draw_right_knee();
   draw_right_calf();
   draw_right_foot();

}
void Transformer::rotateX(int angle)
{
   fullx = (fullx + angle) % 360;
}
void Transformer::rotateY(int angle)
{
   fully = (fully + angle) % 360;
}
void Transformer::rotateZ(int angle)
{
   fullz = (fullz + angle) % 360;
}

void Transformer::tiltHeadSide(int angle)
{
   headside = (headside + angle) % 360;
}
void Transformer::tiltHeadFB(int angle)
{
   headforward = (headforward + angle) % 360;
}
void Transformer::turnHead(int angle)
{
   headcurve = (headcurve + angle) % 360;
}
void Transformer::bendForward(int angle)
{
   bend = (bend + angle) % 360;
}
void Transformer::bendBack(int angle)
{
   bend = (bend + angle) % 360;
}


void Transformer::rShoulderSide(int angle)
{
   rshoulderside = (rshoulderside + angle) % 360;
}
void Transformer::rShoulderFB(int angle)
{
   rshoulderforward = (rshoulderforward + angle) % 360;
}
void Transformer::rShoulderCurve(int angle)
{
   rshouldercurve = (rshouldercurve + angle) % 360;
}

void Transformer::rElbowBend(int angle)
{
   relbow = (relbow + angle) % 360;
}
void Transformer::lShoulderSide(int angle)
{
   lshoulderside = (lshoulderside + angle) % 360;
}
void Transformer::lShoulderFB(int angle)
{
   lshoulderforward = (lshoulderforward + angle) % 360;
}
void Transformer::lShoulderCurve(int angle)
{
   lshouldercurve = (lshouldercurve + angle) % 360;
}

void Transformer::lElbowBend(int angle)
{
   lelbow = (lelbow + angle) % 360;
}
void Transformer::rLegSide(int angle)
{
   rltside = (rltside + angle) % 360;
}
void Transformer::rLegFB(int angle)
{
   rltforward = (rltforward + angle) % 360;
}
void Transformer::rLegCurve(int angle)
{
   rltcurve = (rltcurve + angle) % 360;
}

void Transformer::rCalfFB(int angle)
{
   rlbforward = (rlbforward + angle) % 360;
}
void Transformer::lLegSide(int angle)
{
   lltside = (lltside + angle) % 360;
}
void Transformer::lLegFB(int angle)
{
   lltforward = (lltforward + angle) % 360;
}
void Transformer::lLegCurve(int angle)
{
   lltcurve = (lltcurve + angle) % 360;
}

void Transformer::lCalfFB(int angle)
{
   llbforward = (llbforward + angle) % 360;
}

void Transformer::draw_left_shoulder()
{
   left_shoulder = glGenLists(1);
   glNewList(left_shoulder, GL_COMPILE);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

   drawCylinder(0.35,0.4,32,32);
   //   glScalef(0.25,0.25,0.25);
   // drawSphere(32,32);

   glEndList();
}

void Transformer::draw_left_arm()
{
   left_arm=glGenLists(1);
   glNewList(left_arm,GL_COMPILE);

   glTranslatef (0.5, 0.0, 0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawCylinder(0.3,1.2,32,32);

   glEndList();
}

void Transformer::draw_left_elbow()
{
   left_elbow=glGenLists(1);
   glNewList(left_elbow,GL_COMPILE);
   glScalef(0.2,0.2,0.2);
   drawSphere(32,32);
   glEndList();
}

void Transformer::draw_left_forearm()
{
   left_forearm = glGenLists(1);
   glNewList(left_forearm,GL_COMPILE);
   glTranslatef(0.8,0.0,0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawCylinder(0.2,1.5,32,32);
   glEndList();
}

void Transformer::draw_right_elbow()
{
   right_elbow = glGenLists(1);
   glNewList(right_elbow, GL_COMPILE);

   glScalef(0.2,0.2,0.2);
   drawSphere(32,32);
   glEndList();
}

void Transformer::draw_right_shoulder()
{
   right_shoulder = glGenLists(1);
   glNewList(right_shoulder, GL_COMPILE);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

   drawCylinder(0.35,0.4,32,32);
   // glScalef(0.25,0.25,0.25);
   // drawSphere(32,32);

   glEndList();
}
void Transformer::draw_right_arm()
{
   right_arm = glGenLists(1);
   glNewList(right_arm, GL_COMPILE);
   glTranslatef (0.5, 0.0, 0.0);
   glRotatef(90.0f, 0.0f,1.0f, 0.0f);
   drawCylinder(0.3,1.2,32,32);
   glEndList();
}

void Transformer::draw_right_forearm()
{
   right_forearm = glGenLists(1);
   glNewList(right_forearm, GL_COMPILE);
   glTranslatef(0.8,0.0,0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawCylinder(0.2,1.5,32,32);
   glEndList();
}

void Transformer::draw_hip()
{
   hip = glGenLists(1);
   glNewList(hip, GL_COMPILE);

   glTranslatef(0.0,-1.1,0.0);
   glScalef(1.6,0.3,1.1);
   drawCube();
   glEndList();
}

void Transformer::draw_torso()
{
   torso = glGenLists(1);
   glNewList(torso, GL_COMPILE);

   glScalef(1.6,2.0,1.1);
   drawCube();
   glEndList();
}

void Transformer::draw_head()
{
   head = glGenLists(1);
   glNewList(head, GL_COMPILE);
   glPushMatrix();
   //glScalef(0.7,0.7,0.7);
   // drawSphere(32,32);
   glPushMatrix();
   glRotatef((GLfloat)carfront,1.0,0.0,0.0);
   glTranslatef(0.0,0.0+move,0.3);
   glScalef(1.7,1.1,0.5);
   drawCube();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.0,0.0,0.3);
   glScalef(1.7,1.1,0.8);

   drawCube();
   glPopMatrix();
   glPopMatrix();
   glEndList();
}

void Transformer::draw_eyes()
{
   eyes = glGenLists(1);
   glNewList(eyes, GL_COMPILE);
   glPushMatrix();
   glTranslatef(-0.3,-0.1,0.7);
   drawCircle(0.15,32);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.3,-0.1,0.7);
   drawCircle(0.15,32);
   glPopMatrix();
   glEndList();
}

void Transformer::draw_neck()
{
   neck = glGenLists(1);
   glNewList(neck, GL_COMPILE);
 /* 
   //top
glPushMatrix();
glColor3f(1.0,1.0,1.0);

glTranslatef(0.0,1.5+rshift,-0.7+move);
  glRotatef ((GLfloat) rdoor, 1.0, 0.0, 0.0);
   glScalef(1.6,1.8,0.1);
   drawCube();
   glPopMatrix();
   
//lside
glPushMatrix();
glColor3f(1.0,1.0,1.0);
   //   glRotatef ((GLfloat) vehiclefront, 0.0, 1.0, 0.0);
   glTranslatef(0.0+lshift,1.5,-0.7+move);
glRotatef ((GLfloat) ldoor, 0.0, 1.0, 0.0);

   glScalef(1.6,1.8,0.1);
   drawCube();
   glPopMatrix();
   
//rside
glPushMatrix();
glColor3f(1.0,1.0,1.0);
glTranslatef(0.0+rshift,1.5,-0.7+move);
//glTranslatef(-1.6,0.0,0.0);
glRotatef ((GLfloat) rdoor, 0.0, 1.0, 0.0);
//glTranslatef(1.6,0.0,0.0);
//glTranslatef(-rshift,0.0,0.0);
   glScalef(1.6,1.8,0.1);
   drawCube();
   glPopMatrix();

//front
   glPushMatrix();
   glColor3f(1.0,1.0,1.0);
   glTranslatef(0.0,1.5,-0.7);
   glScalef(1.6,1.8,0.1);
   drawCube();
   glPopMatrix();

   glPushMatrix();
   glColor3f(0.0,0.0,0.0);
   glTranslatef(0.0,1.5,-0.6);
   glScalef(1.6,1.8,0.1);
   drawCube();
   glPopMatrix();
*/
glColor3f(1,0,0);
   glTranslatef (0.0, 1.15, 0.0);
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   drawCylinder(0.35,0.3,32,32);

   glEndList();
}

void Transformer::draw_right_butt()
{
   right_butt = glGenLists(1);
   glNewList(right_butt, GL_COMPILE);
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   drawCylinder(0.35,0.6,32,32);

   //glScalef(0.35,0.35,0.35);
   //drawSphere(32,32);

   glEndList();
}
void Transformer::draw_right_thigh()
{
   right_thigh = glGenLists(1);
   glNewList(right_thigh, GL_COMPILE);
//   glTranslatef(0.65,0.0,0.0);
glTranslatef(0.6,0.0,0.0);
glRotatef(90.0f, 0.0f,1.0f, 0.0f);
   //drawCylinder(0.4,1.0,32,32);
   glScalef(0.6,0.6,1.0);
   drawCube();
   glEndList();
}

void Transformer::draw_right_knee()
{
   right_knee = glGenLists(1);
   glNewList(right_knee, GL_COMPILE);

   glScalef(0.3,0.3,0.3);
   drawSphere(32,32);
   glEndList();
}

void Transformer::draw_right_calf()
{
   right_calf = glGenLists(1);
   glNewList(right_calf, GL_COMPILE);
   glTranslatef(0.65,0.0,0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawCylinder(0.3,1.2,32,32);


   glEndList();
}

void Transformer::draw_right_foot()
{
   right_foot = glGenLists(1);
   glNewList(right_foot, GL_COMPILE);
  glRotatef((GLfloat)rfootrot,1.0,0.0,0.0);
  glTranslatef(1.3,0.0,0.2);
   glScalef(0.2,0.6,1.0);
   drawCube();
   glEndList();
}

void Transformer::draw_left_butt()
{
   left_butt = glGenLists(1);
   glNewList(left_butt, GL_COMPILE);
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   drawCylinder(0.35,0.6,32,32);


   //   glScalef(0.35,0.35,0.35);
   // drawSphere(32,32);

   glEndList();
}

void Transformer::draw_left_thigh()
{
   left_thigh = glGenLists(1);
   glNewList(left_thigh, GL_COMPILE);
   glTranslatef(0.6,0.0,0.0);   
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   //   drawCylinder(0.4,1.0,32,32);
   glScalef(0.6,0.6,1.0);
   drawCube();
 
   glEndList();
}

void Transformer::draw_left_knee()
{
   left_knee = glGenLists(1);
   glNewList(left_knee, GL_COMPILE);

   glScalef(0.3,0.3,0.3);
   drawSphere(32,32);
   glEndList();

}

void Transformer::draw_left_calf()
{ 
   left_calf = glGenLists(1);
   glNewList(left_calf, GL_COMPILE);
   glTranslatef(0.65,0.0,0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   drawCylinder(0.3,1.2,32,32);
   glEndList();

}

void Transformer::draw_left_foot()
{ 
   left_foot = glGenLists(1);
   glNewList(left_foot, GL_COMPILE);
   glRotatef((GLfloat)lfootrot,1.0,0.0,0.0);

   glTranslatef(1.3,0.0,0.2);
   glScalef(0.2,0.6,1.0);
   drawCube();
   glEndList();
}
void Transformer::drawCube(){
   glBegin(GL_QUADS);    
   glVertex3f( 0.5f, 0.5f, -0.5f);
   glVertex3f(-0.5f, 0.5f, -0.5f);
   glVertex3f(-0.5f, 0.5f,  0.5f);
   glVertex3f( 0.5f, 0.5f,  0.5f);

   glVertex3f( 0.5f, -0.5f,  0.5f);
   glVertex3f(-0.5f, -0.5f,  0.5f);
   glVertex3f(-0.5f, -0.5f, -0.5f);
   glVertex3f( 0.5f, -0.5f, -0.5f);

   glVertex3f( 0.5f,  0.5f, -0.5f);
   glVertex3f(-0.5f,  0.5f, -0.5f);
   glVertex3f(-0.5f, -0.5f, -0.5f);
   glVertex3f( 0.5f, -0.5f, -0.5f);

   glVertex3f( 0.5f, -0.5f, -0.5f);
   glVertex3f(-0.5f, -0.5f, -0.5f);
   glVertex3f(-0.5f,  0.5f, -0.5f);
   glVertex3f( 0.5f,  0.5f, -0.5f);

   glVertex3f(-0.5f,  0.5f,  0.5f);
   glVertex3f(-0.5f,  0.5f, -0.5f);
   glVertex3f(-0.5f, -0.5f, -0.5f);
   glVertex3f(-0.5f, -0.5f,  0.5f);

   glVertex3f(0.5f,  0.5f, -0.5f);
   glVertex3f(0.5f,  0.5f,  0.5f);
   glVertex3f(0.5f, -0.5f,  0.5f);
   glVertex3f(0.5f, -0.5f, -0.5f);

   glEnd();
}


void Transformer::drawSphere(GLint slices, GLint stacks ){
   float x, y, z ;
   for( float i = 0 ; i < M_PI ; i = i + M_PI/stacks )
   {
	  glBegin( GL_QUAD_STRIP ) ;
	  for( float j = 0 ; j < 2*M_PI ; j = j + 2*M_PI/slices )

	  {
		 x = cosf( i ) * sinf( j ) ;
		 y = sinf( i ) * sinf( j ) ;
		 z = cosf( j ) ;
		 glVertex3f( x, y, z ) ;
		 x = cosf( i + M_PI/stacks ) * sinf( j ) ;
		 y = sinf( i + M_PI/stacks ) * sinf( j ) ;
		 z = cosf( j ) ;
		 glVertex3f( x, y, z ) ;
	  }

	  glEnd() ;
   }

}
void Transformer::drawCircle( float r, int num_segments)
{
   glBegin(GL_POLYGON);
   for(int i = 0; i < num_segments; i++)
   {
	  float theta = 2.0f * 3.14159f * float(i) / float(num_segments);

	  float x = r * cosf(theta);//calculate the x component
	  float y = r * sinf(theta);//calculate the y component

	  glVertex2f(x, y);//output vertex

   }
   glEnd();
}

void Transformer::drawCylinder(float radius,float height,GLint numMajor, GLint numMinor )
{
   double majorStep = height / numMajor;
   double minorStep = 2.0 * M_PI / numMinor;
   int i, j;

   for (i = 0; i < numMajor; ++i) {
	  GLfloat z0 = 0.5 * height - i * majorStep;
	  GLfloat z1 = z0 - majorStep;

	  glBegin(GL_TRIANGLE_STRIP);
	  for (j = 0; j <= numMinor; ++j) {
		 double a = j * minorStep;
		 GLfloat x = radius * cos(a);
		 GLfloat y = radius * sin(a);
		 glNormal3f(x / radius, y / radius, 0.0);
		 glTexCoord2f(j / (GLfloat) numMinor, i / (GLfloat) numMajor);
		 glVertex3f(x, y, z0);
		 glNormal3f(x / radius, y / radius, 0.0);
		 glTexCoord2f(j / (GLfloat) numMinor, (i + 1) / (GLfloat) numMajor);
		 glVertex3f(x, y, z1);
	  }
	  glEnd();
   }
   drawCircle(radius,32);

}
void Transformer::timer()
{
   while(1){
	  if(rdoor==90&&ldoor==-90&&fronttyretrans!=0&&backtyretrans!=0&&fullx==0&&fully==90&&fullz==90&&bend==0&&headside==0&&headforward==0&&headcurve==0&&rshoulderside==0&&rshoulderforward==0&&rshouldercurve==0&&relbow==-90&&lshoulderside==-180&&lshoulderforward==0&&lshouldercurve==0&&lelbow==90&&rltside==-90&&rltforward==0&&rltcurve==0&&rlbforward==180&&lltside==-90&&lltforward==0&&lltcurve==0&&llbforward==180&&vehiclefront==90)
	  break;
	  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	  transform();
	  draw_neck();
	  draw_head();
	  draw_right_foot();
	  draw_left_foot();
	  display();
	  GLFWwindow * win=glfwGetCurrentContext();
	  glfwPollEvents();
	  glfwSwapBuffers(win);
	  usleep(400000);

   }
}


void Transformer::transform()
{ 
rshift=.8;
lshift=-.8;
 if(bend!=0)
   {
	  bend=0;
	  return;
   }
   if(headside!=0){
   headside=0;
}
if(headforward!=0)
{
   headforward=0;
}

if(headcurve!=0)
{
   headcurve=0;
   return;
}
 
if(relbow!=-90)
{
   relbow=-90;
}
  if(lelbow!=90){
	  lelbow=90;
	  return;
   }


if(rshoulderside!=0){
   rshoulderside=0;
}
if(lshoulderside!=-180){
   lshoulderside=-180;
   return;
}
if(rshoulderforward!=0){
   rshoulderforward=0;
}
   if(lshoulderforward!=0){
   lshoulderforward=0;
   return;
}

if(rshouldercurve!=0)
{
rshouldercurve=0;
}

   if(lshouldercurve!=0){
   lshouldercurve=0;
   return;
}

if(down==0.0)
{
   down=-0.9;
   return;
}
 
if(llbforward!=180)
   {
   llbforward=180;
}
  if(rlbforward!=180){
	  rlbforward=180;
	  return;
   }
 
   if(lltside!=-90){
   lltside=-90;
}
if(rltside!=-90){
   rltside=-90;
   return;
}

   if(lltforward!=0){
   lltforward=0;
}
      if(rltforward!=0){
   rltforward=0;
   return;
}
 
if(lltcurve!=0){
   lltcurve=0;
}
  if(rltcurve!=0){
	  rltcurve=0;
	  return;
   }
 
  if(ldoor!=-90)
   {
//move=0.7;
	  ldoor=-90;
   }
   if(rdoor!=90){
	  rdoor=90;
	  return;
   }
   

   if(vehiclefront!=90){
	  move=-0.3;
	  vehiclefront=90;
	  return;
   }
      
   if(fullx!=0){
	  fullx=0;
	  return ;
   }
   if(fully!=90)
   {
	  fully=90;
	  return;
   }
   if(fullz!=90)
   {
	  fullz=90;
	  return;
   }
	  fronttyretrans=-0.7;
	  backtyretrans=-0.7;
	  carfront=90.0;
	  rfootrot=-90.0;
	  lfootrot=90.0;
	  carback=-0.2;
	  carbackshift=0.5;
   }
/*
void Transformer::transform()
{ 
   fronttyretrans=-0.7;
   backtyretrans=0.7;
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
   if(rshoulderside>0)
   rshoulderside=(rshoulderside-5)%360;
   else if(rshoulderside<0)
   rshoulderside=(rshoulderside+5)%360;
   if(rshoulderforward>0)
   rshoulderforward=(rshoulderforward-5)%360;
   else if(rshoulderforward<0)
   rshoulderforward=(rshoulderforward+5)%360;
   if(rshouldercurve>0)
   rshouldercurve=(rshouldercurve-5)%360;
   else if(rshouldercurve<0)
   rshouldercurve=(rshouldercurve+5)%360;
   if(relbow>-90)
   relbow=(relbow-5)%360;
   else if(relbow<-90)
   relbow=(relbow+5)%360;
   if(lshoulderside>-180)
   lshoulderside=(lshoulderside-5)%360;
   else if(lshoulderside<-180)
   lshoulderside=(lshoulderside+5)%360;
   if(lshoulderforward>0)
   lshoulderforward=(lshoulderforward-5)%360;
   else if(lshoulderforward<-0)
   lshoulderforward=(lshoulderforward+5)%360;
   if(lshouldercurve>0)
   lshouldercurve=(lshouldercurve-5)%360;
   else if(lshouldercurve<0)
   lshouldercurve=(lshouldercurve+5)%360;
   if(lelbow>90)
   lelbow=(lelbow-5)%360;
   else if(lelbow<90)
   lelbow=(lelbow+5)%360;
   if(lltside>-90)
   lltside=(lltside-5)%360;
   else if(lltside<-90)
   lltside=(lltside+5)%360;
   if(lltforward>180)
   lltforward=(lltforward-5)%360;
   else if(lltforward<180)
   lltforward=(lltforward+5)%360;
   if(lltcurve>0)
   lltcurve=(lltcurve-5)%360;
   else if(lltcurve<0)
   lltcurve=(lltcurve+5)%360;
   if(llbforward>180)
   llbforward=(llbforward-5)%360;
   else if(llbforward<180)
   llbforward=(llbforward+5)%360;
   if(rltside>-90)
   rltside=(rltside-5)%360;
   else if(rltside<-90)
   rltside=(rltside+5)%360;
   if(rltforward>180)
   rltforward=(rltforward-5)%360;
   else if(rltforward<180)
   rltforward=(rltforward+5)%360;
   if(rltcurve>0)
   rltcurve=(rltcurve-5)%360;
   else if(rltcurve<0)
   rltcurve=(rltcurve+5)%360;
   if(rlbforward>180)
   rlbforward=(rlbforward-5)%360;
   else if(rlbforward<180)
   rlbforward=(rlbforward+5)%360;
   if(vehiclefront>90)
   vehiclefront=(vehiclefront-5)%360;
   else if(vehiclefront<90)
   vehiclefront=(vehiclefront+5)%360;
}
*/
void Transformer::display()
{
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);


   //hip
   glColor3f(0,0,1);

   glPushMatrix(); //identity matrix pushed
   glRotatef ((GLfloat)fullz, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat)fullx,1.0, 0.0, 0.0);
   glRotatef ((GLfloat)fully, 0.0, 1.0, 0.0);
   glPushMatrix(); //rotations for EVERYTHING pushed

   glCallList(hip);
   glPopMatrix(); //ID; have rotations

   //torso
   glColor3f(0.5,.4,1);

   glPushMatrix(); //univ rotations
   glTranslatef(0.0,-1.1,0.0);
   glRotatef ((GLfloat)bend, 1.0, 0.0, 0.0);
   glTranslatef(0.0,1.1,0.0);
   glPushMatrix(); //univ rotations, bend
   glCallList(torso);
   glPopMatrix(); //univ rotations; have bend

   //neck
   glPushMatrix(); //univ rotations, bend
   glColor3f(0,0,1);
 glTranslatef(0.0,1.0,0.0);
   glRotatef ((GLfloat) vehiclefront, 1.0, 0.0, 0.0);
   glTranslatef(0.0,-1.0,0.0);
   glTranslatef(0.0,0.0+down,0.0);
   glPushMatrix();
   glCallList(neck);
   glPopMatrix(); //univ rotations; have bend

   //head
   glPushMatrix(); //univ rotations, bend
   glTranslatef (0.0, 1.9, 0.0);
   glRotatef ((GLfloat) headside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) headforward,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) headcurve, 0.0, 1.0, 0.0);
   glColor3f(0,0,0);
   glPushMatrix(); //univ rotations, bend, head rotations
   glCallList(eyes);
   glPopMatrix(); //univ rotations, bend; have head rotations
   glColor3f(0,0,1);
   glCallList(head);
   glPopMatrix(); //univ rotations; have bend
   glPopMatrix();
   
   //righthand
   glColor3f(1,0,0);

   glPushMatrix(); //univ rotations, bend
   glTranslatef (-1.0, 0.9, 0.0);
   glRotatef ((GLfloat) rshoulderside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) rshoulderforward,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) rshouldercurve ,0.0, 1.0, 0.0);

   glPushMatrix(); //univ rotations, bend, rshoulder
   glTranslatef(0.0,0.0,(GLfloat)fronttyretrans);
   glCallList(right_shoulder);
   glPopMatrix();
   glColor3f(0,0,1);
   glPushMatrix();
   glCallList(right_arm);
   glPopMatrix(); //univ rotations, bend; have rshoulder
   glTranslatef(1.1,0.0,0.0);
   glColor3f(1,0,0);
   glPushMatrix();
   glCallList(right_elbow);
   glPopMatrix();
   glRotatef ((GLfloat) relbow, 0.0, 0.0, 1.0);
   glColor3f(0,0,1);
   glPushMatrix(); //univ rotations, bend, rshoulder+relbow
   glCallList(right_forearm);
   glPopMatrix(); //univ rotations, bend; has rshoulder+relbow
   glPopMatrix(); //univ rotations; has bend

   //lefthand
   glPushMatrix(); //univ rotations, bend
   glTranslatef (1.0, 0.9, 0.0);
   glRotatef ((GLfloat) lshoulderside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) lshoulderforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) lshouldercurve, 0.0, 1.0, 0.0);
   glPushMatrix(); //univ rotations, bend, lshoulder
   glTranslatef(0.0,0.0,(GLfloat)fronttyretrans);

   glColor3f(1,0,0);
   glCallList(left_shoulder);
   glPopMatrix();
	glColor3f(0,0,1);
   glPushMatrix();
   glCallList(left_arm);
   glPopMatrix(); //univ rotations, bend; has lshoulder
   glTranslatef(1.1,0.0,0.0);
   glColor3f(1,0,0);
   glPushMatrix();
   glCallList(left_elbow);
   glPopMatrix();
   glRotatef ((GLfloat) lelbow, 0.0, 0.0, 1.0);
	glColor3f(0,0,1);
   glPushMatrix(); //univ rotations, bend, lshoulder+lelbow
   glCallList(left_forearm);
   glPopMatrix(); //univ rotations, bend; has lshoulder+lelbow
   glPopMatrix(); //univ rotations; has bend
   glPopMatrix(); //ID; has univ rotations

   //rightleg

   glPushMatrix(); //univ rotations
   glTranslatef (-0.58, -1.38, 0.0);
   glRotatef ((GLfloat) rltcurve, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) rltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) rltside, 0.0, 0.0, 1.0);
   glPushMatrix(); //univ rotations, right leg rots
   glTranslatef(0.0,0.0,(GLfloat)backtyretrans);

   glColor3f(1,0,0);
   glCallList(right_butt);
   glPopMatrix();
   glTranslatef(carback,0.0,carback);
   glColor3f(0,.4,1);
   glPushMatrix();
   glCallList(right_thigh);
   glPopMatrix(); //univ rotations; has right leg rots
   glTranslatef(1.2,0.0,0.0);
   glColor3f(1,0,0);
   glPushMatrix();
   glCallList(right_knee);
   glPopMatrix();
   glRotatef ((GLfloat) rlbforward, 0.0, 1.0, 0.0);
   glColor3f(0,.4,1);
   glPushMatrix(); //univ rotations, rleg+rknee
   glTranslatef(0.0,carbackshift,0.0);

   glCallList(right_calf);
   glPopMatrix();
   glColor3f(0,0,1);
   glPushMatrix(); //univ rotations, rleg+rknee
   glCallList(right_foot);
   glPopMatrix(); //univ rotations; has rleg+rknee

   glPopMatrix(); //ID; has univ rotations

   //leftleg   

   glColor3f(1,0,0);
   glPushMatrix(); //univ rotations
   glTranslatef (0.58, -1.38, 0.0);
   glRotatef ((GLfloat) lltcurve, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) lltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) lltside, 0.0, 0.0, 1.0);
   glPushMatrix(); //univ rotations, lleg
   glTranslatef(0.0,0.0,(GLfloat)backtyretrans);

   glCallList(left_butt);
   glPopMatrix();
   glColor3f(0,.4,1);
   glTranslatef(carback,0.0,carback);

   glPushMatrix();
   glCallList(left_thigh);
   glPopMatrix(); //univ rotations; has lleg
   glTranslatef(1.2,0.0,0.0);
   glColor3f(1,0,0);
   glPushMatrix();
   glCallList(left_knee);
   glPopMatrix();
   glRotatef ((GLfloat) llbforward, 0.0, 1.0, 0.0);
   glColor3f(0,.4,1);
   glPushMatrix(); //univ rots,lleg+lknee
   glTranslatef(0.0,-carbackshift,0.0);
   glCallList(left_calf);
   glPopMatrix(); //univ rots; has lleg+lknee
   glColor3f(0,0,1);
   glPushMatrix(); //univ rots, lleg+lknee
   glCallList(left_foot);
   glPopMatrix(); //univ rots; has lleg+lknee
   glPopMatrix(); //ID; has univ rots
   glPopMatrix(); //empty

}



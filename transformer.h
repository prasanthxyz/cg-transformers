#ifndef _TRANSFORMER_CLASS_
#define _TRANSFORMER_CLASS_

#include <GL/glut.h>
#include<unistd.h>
#include <GLFW/glfw3.h>
#include <cmath>

class Transformer
{
   public:
   int flag;
	  int fullx;
	  int fully;
	  int fullz;
	  int headside;
	  int headforward;
	  int headcurve;
	  int bend;
	  int rshoulderside;
	  int rshoulderforward;
	  int rshouldercurve;
	  int relbow;

	  int lshoulderside;
	  int lshoulderforward;
	  int lshouldercurve;
	  int lelbow;
	  int rltside;
	  int rltforward;
	  int rltcurve;
	  int rlbforward;

	  int lltside;
	  int lltforward;

	  int lltcurve;
	  int llbforward;
	  int vehiclefront;
	  int ldoor;
	  int rdoor;
	  int carfront;
	  int rfootrot;
	  int lfootrot;
	  GLfloat rshift;
	  GLfloat lshift;
	  GLfloat move;
	  GLfloat down;
	  GLfloat upshift;
	  GLfloat fronttyretrans;
	  GLfloat carback;
	  GLfloat carbackshift;
	  GLfloat carbackinsert;
	  GLfloat backtyretrans;
	  GLfloat rbtyreshift;
	  GLfloat lbtyreshift;
	  GLuint left_shoulder;
	  GLuint left_arm;
	  GLuint left_forearm;
	  GLuint left_elbow;
	  GLuint right_shoulder;
	  GLuint right_arm;
	  GLuint right_forearm;
	  GLuint right_elbow;

	  GLuint right_butt;
	  GLuint right_thigh;
	  GLuint right_knee;
	  GLuint right_calf;
	  GLuint right_foot;
	  GLuint left_butt;
	  GLuint left_thigh;
	  GLuint left_knee;
	  GLuint left_calf;
	  GLuint left_foot;
	  GLuint hip;
	  GLuint torso;
	  GLuint head;
	  GLuint eyes;
	  GLuint neck;

	  Transformer();
	  void rotateX(int);
	  void rotateY(int);
	  void rotateZ(int);
      void display();
	  void tiltHeadSide(int);
	  void tiltHeadFB(int);
	  void turnHead(int);
	  void bendForward(int);
	  void bendBack(int);
	  void rShoulderSide(int);
	  void rShoulderFB(int);
	  void rShoulderCurve(int);

	  void rElbowBend(int);
	  void lShoulderSide(int);
	  void lShoulderFB(int);
	  void lShoulderCurve(int);

	  void lElbowBend(int);
	  void rLegSide(int);
	  void rLegFB(int);
	  void rLegCurve(int);
	  void rCalfFB(int);
	  void lLegSide(int);
	  void lLegFB(int);
	  void lLegCurve(int);
	  void lCalfFB(int);
	  void drawCube();
	  void drawSphere(GLint,GLint);
	  void drawCircle(float,int);
	  void drawCylinder(float,float,GLint,GLint);
	  void draw_left_shoulder();
	  void draw_left_arm();
	  void draw_left_elbow();
	  void draw_left_forearm();
	  void draw_right_shoulder();
	  void draw_right_arm();
	  void draw_right_elbow();
	  void draw_right_forearm();
	  void draw_hip();
	  void draw_torso();
	  void draw_head();
	  void draw_eyes();
	  void draw_neck();

	  void draw_right_butt();
	  void draw_right_thigh();
	  void draw_right_knee();
	  void draw_right_calf();
	  void draw_right_foot();

	  void draw_left_butt(); 
	  void draw_left_thigh();
	  void draw_left_knee();
	  void draw_left_calf();
	  void draw_left_foot();
	  void tocar();
	  void tohuman();
	  void transform();
};

#endif

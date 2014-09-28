#ifndef _TRANSFORMER_CLASS_
#define _TRANSFORMER_CLASS_

class Transformer
{
   public:
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
	  GLuint left_arm;
	  GLuint left_forearm;
	  GLuint left_elbow;
	  GLuint right_arm;
	  GLuint right_forearm;
	  GLuint right_elbow;

	  GLuint right_thigh;
	  GLuint right_knee;
	  GLuint right_calf;
	  GLuint right_foot;
	  GLuint left_thigh;
	  GLuint left_knee;
	  GLuint left_calf;
	  GLuint left_foot;
	  GLuint hip;
	  GLuint torso;
	  GLuint head;
	  GLuint eyes;
	  GLuint neck;
	  GLUquadricObj *Cneck;
	  GLUquadricObj *rshoulderhand;
	  GLUquadricObj *relbowhand;
	  GLUquadricObj *lshoulderhand;
	  GLUquadricObj *lelbowhand;
	  GLUquadricObj *rtopleg;
	  GLUquadricObj *rbottomleg;
	  GLUquadricObj *ltopleg;
	  GLUquadricObj *lbottomleg;

	  Transformer();
	  void rotateX(int);
	  void rotateY(int);
	  void rotateZ(int);

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
	  void draw_left_arm();
	  void draw_left_elbow();
	  void draw_left_forearm();
	  void draw_right_arm();
	  void draw_right_elbow();
	  void draw_right_forearm();
	  void draw_hip();
	  void draw_torso();
	  void draw_head();
	  void draw_eyes();
	  void draw_neck();

	  void draw_right_thigh();
	  void draw_right_knee();
	  void draw_right_calf();
	  void draw_right_foot();

	  void draw_left_thigh();
	  void draw_left_knee();
	  void draw_left_calf();
	  void draw_left_foot();

	  void transform();
};

#endif

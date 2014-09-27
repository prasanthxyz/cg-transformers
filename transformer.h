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
	  GLUquadricObj *neck;
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

	  void transform();
};

#endif

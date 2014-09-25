#ifndef _TRANSFORMER_CLASS_
#define _TRANSFORMER_CLASS_

class Transformer
{
   public:
	  int rshoulder;
	  int relbow;
	  int fullx;
	  int fully;
	  int fullz;
	  int headside;
	  int headforward;
	  int headcurve;
	  int lshoulder;
	  int lelbow;
	  int lltside;
	  int lltforward;
	  int rltside;
	  int rltforward;
	  int llbforward;
	  int rlbforward;
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
	  void rShoulderSide(int);
	  void rElbowBend(int);
	  void lShoulderSide(int);
	  void lElbowBend(int);
	  void rLegSide(int);
	  void rLegFB(int);
	  void rCalfFB(int);
	  void lLegSide(int);
	  void lLegFB(int);
	  void lCalfFB(int);
};

#endif

#ifndef _TRANSFORMER_CLASS_
#define _TRANSFORMER_CLASS_

#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <stdio.h>
#include "display.hpp"
#include "loadBmpTexture.hpp"
#include "cube.hpp"

#define NTEX 10
enum Textures {HDTOP, HDBOTTOM, HDBACK, HDFRONT, HDLEFT, HDRIGHT, WOOD, FACE};

class Transformer
{
    public:
        int flag;

        //Cube headObj;
        GLuint textures[NTEX];
        GLuint something;
        //angles and shifting lengths
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
        int rfootrot;

        int lltside;
        int lltforward;
        int lltcurve;
        int llbforward;
        int lfootrot;

        int vehiclefront;
        int carfront;

        GLfloat move;
        GLfloat down;

        GLfloat fronttyretrans;
        GLfloat backtyretrans;
        GLfloat rbtyreshift;
        GLfloat lbtyreshift;

        GLfloat carback;
        GLfloat carbackshift;
        GLfloat carbackinsert;

        //display lists
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

        //functions
        Transformer();

        //rotations
        void rotateX(int);
        void rotateY(int);
        void rotateZ(int);

        //modifications of angles and shifting lengths
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

        //generate the display lists
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

        //transformation functions
        void tocar();
        void tohuman();
        void transform();

        void getTextures();
};

#endif

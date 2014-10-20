#ifndef _TRANSFORMER_HPP_
#define _TRANSFORMER_HPP_

#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "drawing.hpp"
#include "texture.hpp"

class Transformer
{
    public:
        int flag;
        Drawing draw;

        //Textures
        Texture tex;
        
        //Camera flag
        bool camFlag;

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

        int vehicleback;
        int carback;

        int wheelrot;
        int wheelturn;

        GLfloat carmove;
        GLfloat prevcarmove;

        GLfloat move;
        GLfloat down;

        GLfloat fronttyretrans;
        GLfloat backtyretrans;
        GLfloat rftyreshift;
        GLfloat lftyreshift;

        GLfloat carfront;
        GLfloat carfrontshift;
        GLfloat carfrontinsert;

        //display lists
        GLuint left_shoulder;
        GLuint left_arm;
        GLuint left_forearm;
        GLuint left_elbow;
        GLuint left_palm;

        GLuint right_shoulder;
        GLuint right_arm;
        GLuint right_forearm;
        GLuint right_elbow;
        GLuint right_palm;

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
        GLuint back;
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
        void list_left_shoulder();
        void list_left_arm();
        void list_left_elbow();
        void list_left_forearm();
        void list_left_palm();

        void list_right_shoulder();
        void list_right_arm();
        void list_right_elbow();
        void list_right_forearm();
        void list_right_palm();

        void list_hip();
        void list_torso();

        void list_head();
        void list_back();
        void list_eyes();
        void list_neck();

        void list_right_butt();
        void list_right_thigh();
        void list_right_knee();
        void list_right_calf();
        void list_right_foot();

        void list_left_butt(); 
        void list_left_thigh();
        void list_left_knee();
        void list_left_calf();
        void list_left_foot();

        //transformation functions
        void tocar();
        void tohuman();
        void transform();

        //display functions
        void display();
        void drawHip();
        void drawTorso();
        void drawNeck();
        void drawHead();
        void drawRightHand();
        void drawLeftHand();
        void drawRightLeg();
        void drawLeftLeg();

        //car movement functions
        void carMove(GLfloat,int,int);
        void wheelTurn(int);
};

#endif

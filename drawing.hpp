#ifndef _DRAWING_HPP_
#define _DRAWING_HPP_

#include <GLFW/glfw3.h>
#include <cmath>

class Drawing
{
    public:
        void drawCube(GLuint T0=0,GLuint T1=0,GLuint T2=0,GLuint T3=0,GLuint T4=0,GLuint T5=0, bool flag=true);
        void drawSphere(GLint,GLint);
        void drawCircle(float,int,GLuint Tex = 0);
        void drawCylinder(float,float,GLint,GLint,GLuint TS1=0,GLuint TS2=0,GLuint Tex=0);
};

#endif

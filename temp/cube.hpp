#ifndef _CUBE_HPP_
#define _CUBE_HPP_
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "vertex.hpp"

class Cube
{
    public:
        GLuint T[6];
        Cube(GLuint T0=0,GLuint T1=0, GLuint T2=0, GLuint T3=0, GLuint T4=0, GLuint T5=0);
        void draw();
};

#endif

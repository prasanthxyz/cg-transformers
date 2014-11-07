#ifndef _LIGHT_HPP_
#define _LIGHT_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Light
{
public:
    GLfloat pos[4];
    GLfloat amb[4];
    GLfloat dif[4];
    GLfloat spec[4];
    GLenum light_id;

    Light();
    Light(GLenum,GLfloat,GLfloat,GLfloat,bool spotflag=false);
    void setPos(GLfloat,GLfloat,GLfloat);
    void setDirn(GLfloat,GLfloat,GLfloat);
    void on();
    void off();
};

#endif

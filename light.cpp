#include "light.hpp"

Light::Light()
{
    light_id = GL_LIGHT0;
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;
    pos[3] = 1;
    amb[0] = 1;
    amb[1] = 1;
    amb[2] = 1;
    amb[3] = 1;
    dif[0] = 1;
    dif[1] = 1;
    dif[2] = 1;
    dif[3] = 1;
    spec[0] = 1;
    spec[1] = 1;
    spec[2] = 1;
    spec[3] = 1;
    glLightfv(light_id, GL_POSITION,pos);
    glLightfv(light_id, GL_DIFFUSE,dif);
    glLightfv(light_id, GL_SPECULAR,spec);
    glLightfv(light_id, GL_AMBIENT,amb);
}

Light::Light(GLenum lid, GLfloat x,GLfloat y,GLfloat z, bool spotflag)
{
    light_id = lid;
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;
    pos[3] = 1;
    amb[0] = 1;
    amb[1] = 1;
    amb[2] = 1;
    amb[3] = 1;
    dif[0] = 1;
    dif[1] = 1;
    dif[2] = 1;
    dif[3] = 1;
    spec[0] = 1;
    spec[1] = 1;
    spec[2] = 1;
    spec[3] = 1;
    glLightfv(light_id, GL_POSITION,pos);
    glLightfv(light_id, GL_DIFFUSE,dif);
    glLightfv(light_id, GL_SPECULAR,spec);
    glLightfv(light_id, GL_AMBIENT,amb);
    if(spotflag)
    {
        glLightf(light_id, GL_SPOT_CUTOFF, 40.0f);
        glLightf(light_id, GL_SPOT_EXPONENT, 1.0f);
    }
}

void Light::setPos(GLfloat x, GLfloat y, GLfloat z)
{
    GLfloat pos[] = {x, y, z, 1};
    glLightfv(light_id, GL_POSITION,pos);
}

void Light::setDirn(GLfloat x, GLfloat y, GLfloat z)
{
    GLfloat dirn[] = {x, y, z, 1};
    glLightfv(light_id, GL_SPOT_DIRECTION, dirn);
}

void Light::on()
{
    glEnable(light_id);
}

void Light::off()
{
    glDisable(light_id);
}

#include "cube.hpp"

Cube::Cube(GLuint T0,GLuint T1,GLuint T2,GLuint T3,GLuint T4,GLuint T5)
{
    T[0] = T0; T[1] = T1; T[2] = T2;
    T[3] = T3; T[4] = T4; T[5] = T5;
}

void Cube::draw()
{
    //top - back(right;left) - front(left;right)
    glBindTexture(GL_TEXTURE_2D, T[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glTexCoord2f(0,1);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(1,1);
    glVertex3f(-0.5f, 0.5f,  0.5f);
    glTexCoord2f(1,0);
    glVertex3f( 0.5f, 0.5f,  0.5f);
    glEnd();

    // bottom - front(right;left) - back(left;right)
    glBindTexture(GL_TEXTURE_2D, T[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glTexCoord2f(0,1);
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glTexCoord2f(1,1);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1,0);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glEnd();

    //back - top(right;left) - bottom(left;right)
    glBindTexture(GL_TEXTURE_2D, T[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f( 0.5f,  0.5f, -0.5f);
    glTexCoord2f(0,1);
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glTexCoord2f(1,1);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1,0);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glEnd();

    //front - bottom(right;left) - top(left;right)
    glBindTexture(GL_TEXTURE_2D, T[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(1,0);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glTexCoord2f(0,0);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(0,1);
    glVertex3f(-0.5f,  0.5f, 0.5f);
    glTexCoord2f(1,1);
    glVertex3f( 0.5f,  0.5f, 0.5f);
    glEnd();

    //left - top(front;back) - bottom(back;front)
    glBindTexture(GL_TEXTURE_2D, T[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f(-0.5f,  0.5f,  0.5f);
    glTexCoord2f(0,1);
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glTexCoord2f(1,1);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1,0);
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glEnd();

    //right - front(back;front) - bottom(front;back)
    glBindTexture(GL_TEXTURE_2D, T[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f(0.5f,  0.5f, -0.5f);
    glTexCoord2f(0,1);
    glVertex3f(0.5f,  0.5f,  0.5f);
    glTexCoord2f(1,1);
    glVertex3f(0.5f, -0.5f,  0.5f);
    glTexCoord2f(1,0);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();
}

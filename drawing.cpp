#include "drawing.hpp"

void Drawing::drawCube(GLuint T0, GLuint T1, GLuint T2, GLuint T3, GLuint T4, GLuint T5){
    glColor3f(1,1,1);
    //top - back(right;left) - front(left;right)
    glBindTexture(GL_TEXTURE_2D, T0);
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

    glColor3f(1,1,1);
    // bottom - front(right;left) - back(left;right)
    glBindTexture(GL_TEXTURE_2D, T1);
    glBegin(GL_QUADS);
    glTexCoord2f(1,0);
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glTexCoord2f(0,0);
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glTexCoord2f(0,1);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1,1);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glEnd();

    glColor3f(1,1,1);
    //back - top(right;left) - bottom(left;right)
    glBindTexture(GL_TEXTURE_2D, T2);
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

    glColor3f(1,1,1);
    //front - bottom(right;left) - top(left;right)
    glBindTexture(GL_TEXTURE_2D, T3);
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

    glColor3f(1,1,1);
    //left - top(front;back) - bottom(back;front)
    glBindTexture(GL_TEXTURE_2D, T4);
    glBegin(GL_QUADS);
    glTexCoord2f(1,0);
    glVertex3f(-0.5f,  0.5f,  0.5f);
    glTexCoord2f(0,0);
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glTexCoord2f(0,1);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1,1);
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glEnd();

    glColor3f(1,1,1);
    //right - front(back;front) - bottom(front;back)
    glBindTexture(GL_TEXTURE_2D, T5);
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

void Drawing::drawSphere(GLint slices, GLint stacks)
{
    float x, y, z ;
    for(float i = 0; i < M_PI; i = i + M_PI/stacks)
    {
        glBegin(GL_QUAD_STRIP) ;
        for(float j = 0; j < 2*M_PI; j = j + 2*M_PI/slices)
        {
            x = cosf(i) * sinf(j) ;
            y = sinf(i) * sinf(j) ;
            z = cosf(j) ;
            glVertex3f(x, y, z) ;
            x = cosf(i + M_PI/stacks) * sinf(j) ;
            y = sinf(i + M_PI/stacks) * sinf(j) ;
            z = cosf(j) ;
            glVertex3f(x, y, z) ;
        }
        glEnd() ;
    }
}

void Drawing::drawCircle( float r, int num_segments, GLuint Tex)
{
    float angle, radian, x, y,tx,ty,pi=3.14159f;
    glBindTexture(GL_TEXTURE_2D, Tex);
    glBegin(GL_POLYGON);
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.14159f * float(i) / float(num_segments);
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glTexCoord2f(cosf(theta)*.5+0.5,sinf(theta)*.5+0.5);
        glVertex2f(x, y);//output vertex
    }
    glEnd();
}

void Drawing::drawCylinder(float radius,float height,GLint numMajor, GLint numMinor, GLuint TS1, GLuint TS2, GLuint Tex)
{
    double majorStep = height / numMajor;
    double minorStep = 2.0 * M_PI / numMinor;
    int i, j;

    glBindTexture(GL_TEXTURE_2D, Tex);
    for (i = 0; i < numMajor; ++i) {
        GLfloat z0 = 0.5 * height - i * majorStep;
        GLfloat z1 = z0 - majorStep;

        glBegin(GL_TRIANGLE_STRIP);
        for (j = 0; j <= numMinor; ++j) {
            double a = j * minorStep;
            GLfloat x = radius * cos(a);
            GLfloat y = radius * sin(a);
            glNormal3f(x / radius, y / radius, 0.0);
            glTexCoord2f(j / (GLfloat) numMinor, i / (GLfloat) numMajor);
            glVertex3f(x, y, z0);
            glNormal3f(x / radius, y / radius, 0.0);
            glTexCoord2f(j / (GLfloat) numMinor, (i + 1) / (GLfloat) numMajor);
            glVertex3f(x, y, z1);
        }
        glEnd();
    }
    glPushMatrix();
    glTranslatef(0.0,0.0,-height/2);
    drawCircle(radius,32,TS1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,0.0,height/2);
    drawCircle(radius,32,TS2);
    glPopMatrix();
}


#include "drawing.hpp"

void Drawing::drawCube(GLuint T0, GLuint T1, GLuint T2, GLuint T3, GLuint T4, GLuint T5, bool flag)
{
    float i, j, k, l;

    //----------------------------------------------------------------------------------------------------
    //top - back(right;left) - front(left;right)
    glBindTexture(GL_TEXTURE_2D, T0);

    if(flag)
        glNormal3f(0,1,0);
    else
        glNormal3f(0,-1,0);

    for(i = -0.5; i < 0.499; i += .05)
    {
        for(j = -0.5; j < 0.499; j += .05)
        {
            glBegin(GL_QUADS);
            glTexCoord2f(i+0.5,j+0.5);
            glVertex3f( i, 0.5f, j);

            glTexCoord2f(i+0.55,j+0.5);
            glVertex3f( i+.05f, 0.5f, j);

            glTexCoord2f(i+0.55,j+0.55);
            glVertex3f( i+.05f, 0.5f, j+.05f);

            glTexCoord2f(i+0.5,j+0.55);
            glVertex3f( i, 0.5f, j+.05f);
            glEnd();
        }
    }
    //----------------------------------------------------------------------------------------------------




    //----------------------------------------------------------------------------------------------------
    // bottom - front(right;left) - back(left;right)
    glBindTexture(GL_TEXTURE_2D, T1);

    if(flag)
        glNormal3f(0,-1,0);
    else
        glNormal3f(0,1,0);

    for(i = -0.5; i < 0.499; i += .05)
    {
        for(j = -0.5; j < 0.499; j += .05)
        {
            glBegin(GL_QUADS);
            glTexCoord2f(i+0.5,j+0.5);
            glVertex3f( i, -0.5f, j);

            glTexCoord2f(i+0.55,j+0.5);
            glVertex3f( i+.05f, -0.5f, j);

            glTexCoord2f(i+0.55,j+0.55);
            glVertex3f( i+.05f, -0.5f, j+.05f);

            glTexCoord2f(i+0.5,j+0.55);
            glVertex3f( i, -0.5f, j+.05f);
            glEnd();
        }
    }
    //----------------------------------------------------------------------------------------------------




    //----------------------------------------------------------------------------------------------------
    //back - top(right;left) - bottom(left;right)
    glBindTexture(GL_TEXTURE_2D, T2);

    if(flag)
        glNormal3f(0,0,-1);
    else
        glNormal3f(0,0,1);

    for(i = -0.5; i < 0.499; i += .05)
    {
        for(j = -0.5; j < 0.499; j += .05)
        {
            glBegin(GL_QUADS);
            glTexCoord2f(i+0.5,j+0.5);
            glVertex3f( i, j, -0.5f);

            glTexCoord2f(i+0.55,j+0.5);
            glVertex3f( i+.05f, j, -0.5f);

            glTexCoord2f(i+0.55,j+0.55);
            glVertex3f( i+.05f, j+.05f, -0.5f);

            glTexCoord2f(i+0.5,j+0.55);
            glVertex3f( i, j+.05f, -0.5f);
            glEnd();
        }
    }
    //----------------------------------------------------------------------------------------------------



    //----------------------------------------------------------------------------------------------------
    //front - bottom(right;left) - top(left;right)
    glBindTexture(GL_TEXTURE_2D, T3);

    if(flag)
        glNormal3f(0,0,1);
    else
        glNormal3f(0,0,-1);

    for(i = -0.5; i < 0.499; i += .05)
    {
        for(j = -0.5; j < 0.499; j += .05)
        {
            glBegin(GL_QUADS);
            glTexCoord2f(i+0.5,j+0.5);
            glVertex3f( i, j, 0.5f);

            glTexCoord2f(i+0.55,j+0.5);
            glVertex3f( i+.05f, j, 0.5f);

            glTexCoord2f(i+0.55,j+0.55);
            glVertex3f( i+.05f, j+.05f, 0.5f);

            glTexCoord2f(i+0.5,j+0.55);
            glVertex3f( i, j+.05f, 0.5f);
            glEnd();
        }
    }
    //----------------------------------------------------------------------------------------------------



    //----------------------------------------------------------------------------------------------------
    //left - top(front;back) - bottom(back;front)
    glBindTexture(GL_TEXTURE_2D, T4);

    if(flag)
        glNormal3f(-1,0,0);
    else
        glNormal3f(1,0,0);

    for(i = -0.5; i < 0.499; i += .05)
    {
        for(j = -0.5; j < 0.499; j += .05)
        {
            glBegin(GL_QUADS);
            glTexCoord2f(i+0.5,j+0.5);
            glVertex3f(-0.5f, i, j);

            glTexCoord2f(i+0.55,j+0.5);
            glVertex3f(-0.5f, i+.05f, j);

            glTexCoord2f(i+0.55,j+0.55);
            glVertex3f(-0.5f, i+.05f, j+.05f);

            glTexCoord2f(i+0.5,j+0.55);
            glVertex3f(-0.5f, i, j+.05f);
            glEnd();
        }
    }
    //----------------------------------------------------------------------------------------------------




    //----------------------------------------------------------------------------------------------------
    //right - front(back;front) - bottom(front;back)
    glBindTexture(GL_TEXTURE_2D, T5);

    if(flag)
        glNormal3f(1,0,0);
    else
        glNormal3f(-1,0,0);

    for(i = -0.5; i < 0.499; i += .05)
    {
        for(j = -0.5; j < 0.499; j += .05)
        {
            glBegin(GL_QUADS);
            glTexCoord2f(i+0.5,j+0.5);
            glVertex3f(0.5f, i, j);

            glTexCoord2f(i+0.55,j+0.5);
            glVertex3f(0.5f, i+.05f, j);

            glTexCoord2f(i+0.55,j+0.55);
            glVertex3f(0.5f, i+.05f, j+.05f);

            glTexCoord2f(i+0.5,j+0.55);
            glVertex3f(0.5f, i, j+.05f);
            glEnd();
        }
    }
    //----------------------------------------------------------------------------------------------------
}

void Drawing::drawSphere(GLint slices, GLint stacks,bool flag)
{
    float x, y, z ;
    for(float i = 0; i < M_PI; i = i + M_PI/stacks)
    {
        glBegin(GL_QUAD_STRIP) ;
        for(float j = 0; j < 2*M_PI; j = j + 2*M_PI/slices)
        {
            x = cosf(i) * sinf(j);
            y = sinf(i) * sinf(j);
            z = cosf(j) ; 

            if(flag)
                glNormal3f( x, y, z ) ;
            else
                glNormal3f( -x, -y, -z ) ;

            glVertex3f(x, y, z) ;
            x = cosf(i + M_PI/stacks) * sinf(j);
            y = sinf(i + M_PI/stacks) * sinf(j);
            z = cosf(j) ;

            if(flag)
                glNormal3f( x, y, z ) ;
            else
                glNormal3f( -x, -y, -z ) ;

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

        //glNormal3f(x, y, 0.0);

        glTexCoord2f(cosf(theta)*.5+0.5,sinf(theta)*.5+0.5);
        glVertex2f(x, y);//output vertex
    }
    glEnd();
}

void Drawing::drawCylinder(float radius,float height,GLint numMajor, GLint numMinor, GLuint TS1, GLuint TS2, GLuint Tex,bool flag)
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

            if(flag)
                glNormal3f(x / radius, y / radius, 0.0);
            else
                glNormal3f(-x / radius, -y / radius, 0.0);

            glTexCoord2f(j / (GLfloat) numMinor, i / (GLfloat) numMajor);
            glVertex3f(x, y, z0);
            if(flag)
                glNormal3f(x / radius, y / radius, 0.0);
            else
                glNormal3f(-x / radius, -y / radius, 0.0);
            glTexCoord2f(j / (GLfloat) numMinor, (i + 1) / (GLfloat) numMajor);
            glVertex3f(x, y, z1);
        }
        glEnd();
    }
    glPushMatrix();
    glTranslatef(0.0,0.0,-height/2);

    if(flag)
        glNormal3f(-1,0,0);
    else
        glNormal3f(1,0,0);

    drawCircle(radius,36,TS1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,0.0,height/2);

    if(flag)
        glNormal3f(1,0,0);
    else
        glNormal3f(-1,0,0);

    drawCircle(radius,36,TS2);
    glPopMatrix();
}


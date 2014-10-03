#include "display.hpp"

extern Transformer T;

void drawHip()
{
    glPushMatrix(); //identity matrix pushed
    glColor3f(0,0,1);
    glRotatef ((GLfloat)T.fullz, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat)T.fullx,1.0, 0.0, 0.0);
    glRotatef ((GLfloat)T.fully, 0.0, 1.0, 0.0);
    glPushMatrix(); //rotations for EVERYTHING pushed
    glCallList(T.hip);
    glPopMatrix(); //ID; have rotations
}

void drawTorso()
{
    glPushMatrix();
    glColor3f(0.5,.4,1);
    glTranslatef(0.0,-1.1,0.0);
    glRotatef ((GLfloat)T.bend, 1.0, 0.0, 0.0);
    glTranslatef(0.0,1.1,0.0);
    glPushMatrix();
    glCallList(T.torso);
    glPopMatrix();
}

void drawNeck()
{
    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0.0,1.0,0.0);
    glRotatef ((GLfloat) T.vehiclefront, 1.0, 0.0, 0.0);
    glTranslatef(0.0,-1.0,0.0);
    glTranslatef(0.0,0.0+T.down,0.0);
    glPushMatrix();
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, T.textures[FACE]);
    glCallList(T.neck);
    glPopMatrix(); 
}

void drawHead()
{
   glPushMatrix();
   glTranslatef (0.0, 1.9, 0.0);
   glRotatef ((GLfloat) T.headside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.headforward,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.headcurve, 0.0, 1.0, 0.0);

   glPushMatrix();
   glColor3f(0,0,0);
   glCallList(T.eyes);
   glPopMatrix();
   //glColor3f(0,0,1);
   glColor3f(1,1,1);

   glPushMatrix();
   glRotatef((GLfloat)T.carfront,1.0,0.0,0.0);
   glTranslatef(0.0,0.0+T.move,0.3);
   glScalef(1.7,1.25,0.5);
   glCallList(T.head);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.0,0.0,0.3);
   glScalef(1.7,1.25,0.8);


   glCallList(T.head);
   glPopMatrix();
   glPopMatrix();

   glPopMatrix();
}

void drawRightHand()
{
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef (-1.0, 0.9, 0.0);
    glRotatef ((GLfloat) T.rshoulderside, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) T.rshoulderforward,1.0, 0.0, 0.0);
    glRotatef ((GLfloat) T.rshouldercurve ,0.0, 1.0, 0.0);

    glPushMatrix(); //rshoulder
    glTranslatef(0.0,0.0,(GLfloat)T.fronttyretrans);
    glCallList(T.right_shoulder);
    glPopMatrix();

    glColor3f(0,0,1);
    glPushMatrix();
    glCallList(T.right_arm);
    glPopMatrix(); 
    glTranslatef(1.1,0.0,0.0);

    glColor3f(1,0,0);
    glPushMatrix();
    glCallList(T.right_elbow);
    glPopMatrix();
    glRotatef ((GLfloat) T.relbow, 0.0, 0.0, 1.0);
    glColor3f(0,0,1);

    glPushMatrix(); //rshoulder+relbow
    glCallList(T.right_forearm);
    glPopMatrix();
    glPopMatrix();
}

void drawLeftHand()
{
    glPushMatrix();
    glTranslatef (1.0, 0.9, 0.0);
    glRotatef ((GLfloat) T.lshoulderside, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) T.lshoulderforward, 1.0, 0.0, 0.0);
    glRotatef ((GLfloat) T.lshouldercurve, 0.0, 1.0, 0.0);

    glPushMatrix(); //lshoulder
    glTranslatef(0.0,0.0,(GLfloat)T.fronttyretrans);
    glColor3f(1,0,0);
    glCallList(T.left_shoulder);
    glPopMatrix();
    glColor3f(0,0,1);
    glPushMatrix();
    glCallList(T.left_arm);
    glPopMatrix();
    glTranslatef(1.1,0.0,0.0);

    glColor3f(1,0,0);
    glPushMatrix();
    glCallList(T.left_elbow);
    glPopMatrix();
    glRotatef ((GLfloat) T.lelbow, 0.0, 0.0, 1.0);
    glColor3f(0,0,1);
    glPushMatrix(); //lshoulder+lelbow
    glCallList(T.left_forearm);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix(); //has univ rotations
}

void drawRightLeg()
{
    glPushMatrix();
    glTranslatef (-0.58, -1.38, 0.0);
    glRotatef ((GLfloat) T.rltcurve, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) T.rltforward, 1.0, 0.0, 0.0);
    glRotatef ((GLfloat) T.rltside, 0.0, 0.0, 1.0);

    glPushMatrix(); //rleg
    glTranslatef(0.0,0.0+T.rbtyreshift,(GLfloat)T.backtyretrans);
    glColor3f(1,0,0);
    glCallList(T.right_butt);
    glPopMatrix();
    glTranslatef(T.carback,0.0,T.carback);
    glColor3f(0,.4,1);
    glPushMatrix();
    glCallList(T.right_thigh);
    glPopMatrix();
    glTranslatef(1.2,0.0,0.0);
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(T.carbackinsert,0.0,0.0);

    glPushMatrix();
    glCallList(T.right_knee);
    glPopMatrix();
    glRotatef ((GLfloat) T.rlbforward, 0.0, 1.0, 0.0);
    glColor3f(0,.4,1);

    glPushMatrix(); //rleg+rknee
    glTranslatef(0.0,T.carbackshift,0.0);
    glCallList(T.right_calf);
    glPopMatrix();
    glColor3f(0,0,1);
    glPushMatrix(); //rleg+rknee
    glRotatef((GLfloat)T.rfootrot,1.0,0.0,0.0);
    glCallList(T.right_foot);
    glPopMatrix(); 
    glPopMatrix();

    glPopMatrix();
}

void drawLeftLeg()
{
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef (0.58, -1.38, 0.0);
    glRotatef ((GLfloat) T.lltcurve, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) T.lltforward, 1.0, 0.0, 0.0);
    glRotatef ((GLfloat) T.lltside, 0.0, 0.0, 1.0);

    glPushMatrix(); //lleg
    glTranslatef(0.0,0.0+T.lbtyreshift,(GLfloat)T.backtyretrans);
    glCallList(T.left_butt);
    glPopMatrix();
    glColor3f(0,.4,1);
    glTranslatef(T.carback,0.0,T.carback);
    glPushMatrix();
    glCallList(T.left_thigh);
    glPopMatrix();
    glTranslatef(1.2,0.0,0.0);
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(T.carbackinsert,0.0,0.0);

    glPushMatrix();
    glCallList(T.left_knee);
    glPopMatrix();
    glRotatef ((GLfloat) T.llbforward, 0.0, 1.0, 0.0);
    glColor3f(0,.4,1);

    glPushMatrix(); //lleg+lknee
    glTranslatef(0.0,-T.carbackshift,0.0);
    glCallList(T.left_calf);
    glPopMatrix(); 

    glColor3f(0,0,1);
    glPushMatrix(); //lleg+lknee
    glRotatef((GLfloat)T.lfootrot,1.0,0.0,0.0);
    glCallList(T.left_foot);
    glPopMatrix(); 
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void display()
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    drawHip();
    drawTorso();
    drawNeck();
    drawHead();
    drawRightHand();
    drawLeftHand();
    drawRightLeg();
    drawLeftLeg();
}

void drawCube(GLuint T0, GLuint T1, GLuint T2, GLuint T3, GLuint T4, GLuint T5){
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

    //left - top(front;back) - bottom(back;front)
    glBindTexture(GL_TEXTURE_2D, T4);
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


void drawSphere(GLint slices, GLint stacks )
{
    float x, y, z ;
    for( float i = 0 ; i < M_PI ; i = i + M_PI/stacks )
    {
        glBegin( GL_QUAD_STRIP ) ;
        for( float j = 0 ; j < 2*M_PI ; j = j + 2*M_PI/slices )
        {
            x = cosf( i ) * sinf( j ) ;
            y = sinf( i ) * sinf( j ) ;
            z = cosf( j ) ;
            glVertex3f( x, y, z ) ;
            x = cosf( i + M_PI/stacks ) * sinf( j ) ;
            y = sinf( i + M_PI/stacks ) * sinf( j ) ;
            z = cosf( j ) ;
            glVertex3f( x, y, z ) ;
        }
        glEnd() ;
    }
}

void drawCircle( float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.14159f * float(i) / float(num_segments);
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x, y);//output vertex
    }
    glEnd();
}
void drawCylinder(float radius,float height,GLint numMajor, GLint numMinor)
{
    double majorStep = height / numMajor;
    double minorStep = 2.0 * M_PI / numMinor;
    int i, j;

//    glBindTexture(GL_TEXTURE_2D, X[1]);
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
    glTranslatef(0.0,0.0,-0.6*height/2);
    drawCircle(radius,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,0.0,0.6*height/2);
    drawCircle(radius,32);
    glPopMatrix();
}


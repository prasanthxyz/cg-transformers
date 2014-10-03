#include "transformer.hpp"

void Transformer::drawHip()
{
    glPushMatrix(); //identity matrix pushed
    glColor3f(0,0,1);
    glRotatef ((GLfloat)fullz, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat)fullx,1.0, 0.0, 0.0);
    glRotatef ((GLfloat)fully, 0.0, 1.0, 0.0);
    glPushMatrix(); //rotations for EVERYTHING pushed
    glCallList(hip);
    glPopMatrix(); //ID; have rotations
}

void Transformer::drawTorso()
{
    glPushMatrix();
    glColor3f(0.5,.4,1);
    glTranslatef(0.0,-1.1,0.0);
    glRotatef ((GLfloat)bend, 1.0, 0.0, 0.0);
    glTranslatef(0.0,1.1,0.0);
    glPushMatrix();
    glCallList(torso);
    glPopMatrix();
}

void Transformer::drawNeck()
{
    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0.0,1.0,0.0);
    glRotatef ((GLfloat) vehiclefront, 1.0, 0.0, 0.0);
    glTranslatef(0.0,-1.0,0.0);
    glTranslatef(0.0,0.0+down,0.0);
    glPushMatrix();
    glCallList(neck);
    glPopMatrix(); 
}

void Transformer::drawHead()
{
    glPushMatrix();
    glTranslatef (0.0, 1.9, 0.0);
    glRotatef ((GLfloat) headside, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) headforward,1.0, 0.0, 0.0);
    glRotatef ((GLfloat) headcurve, 0.0, 1.0, 0.0);

    glColor3f(1,1,1);
    glPushMatrix();
    glRotatef((GLfloat)carfront,1.0,0.0,0.0);
    glTranslatef(0.0,0.0+move,0.2);
    glScalef(1.7,1.25,0.8);
    glCallList(front);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,0.0,0.2);
    glScalef(1.7,1.25,0.8);


    glCallList(head);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void Transformer::drawRightHand()
{
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef (-1.0, 0.9, 0.0);
    glRotatef ((GLfloat) rshoulderside, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) rshoulderforward,1.0, 0.0, 0.0);
    glRotatef ((GLfloat) rshouldercurve ,0.0, 1.0, 0.0);

    glPushMatrix(); //rshoulder
    glTranslatef(0.0,0.0,(GLfloat)fronttyretrans);
    glCallList(right_shoulder);
    glPopMatrix();

    glColor3f(1,1,1);
    glPushMatrix();
    glCallList(right_arm);
    glPopMatrix(); 
    glTranslatef(1.1,0.0,0.0);

    glColor3f(1,0,0);
    glPushMatrix();
    glCallList(right_elbow);
    glPopMatrix();
    glRotatef ((GLfloat) relbow, 0.0, 0.0, 1.0);
    glColor3f(1,1,1);

    glPushMatrix(); //rshoulder+relbow
    glCallList(right_forearm);
    glPopMatrix();
    glPopMatrix();
}

void Transformer::drawLeftHand()
{
    glPushMatrix();
    glTranslatef (1.0, 0.9, 0.0);
    glRotatef ((GLfloat) lshoulderside, 0.0, 0.0, 1.0);
    glRotatef ((GLfloat) lshoulderforward, 1.0, 0.0, 0.0);
    glRotatef ((GLfloat) lshouldercurve, 0.0, 1.0, 0.0);

    glPushMatrix(); //lshoulder
    glTranslatef(0.0,0.0,(GLfloat)fronttyretrans);
    glColor3f(1,1,1);
    glCallList(left_shoulder);
    glPopMatrix();
    glColor3f(1,1,1);
    glPushMatrix();
    glCallList(left_arm);
    glPopMatrix();
    glTranslatef(1.1,0.0,0.0);

    glColor3f(1,0,0);
    glPushMatrix();
    glCallList(left_elbow);
    glPopMatrix();
    glRotatef ((GLfloat) lelbow, 0.0, 0.0, 1.0);
    glColor3f(1,1,1);
    glPushMatrix(); //lshoulder+lelbow
    glCallList(left_forearm);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix(); //has univ rotations
}

void Transformer::drawRightLeg()
{
    glPushMatrix();
    glTranslatef (-0.58, -1.38, 0.0);
    glRotatef ((GLfloat) rltcurve, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) rltforward, 1.0, 0.0, 0.0);
    glRotatef ((GLfloat) rltside, 0.0, 0.0, 1.0);

    glPushMatrix(); //rleg
    glTranslatef(0.0,0.0+rbtyreshift,(GLfloat)backtyretrans);
    glColor3f(1,1,1);
    glCallList(right_butt);
    glPopMatrix();
    glTranslatef(carback,0.0,carback);
    glColor3f(0,.4,1);
    glPushMatrix();
    glCallList(right_thigh);
    glPopMatrix();
    glTranslatef(1.2,0.0,0.0);
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(carbackinsert,0.0,0.0);

    glPushMatrix();
    glCallList(right_knee);
    glPopMatrix();
    glRotatef ((GLfloat) rlbforward, 0.0, 1.0, 0.0);
    glColor3f(1,1,1);

    glPushMatrix(); //rleg+rknee
    glTranslatef(0.0,carbackshift,0.0);
    glCallList(right_calf);
    glPopMatrix();
    glColor3f(0,0,1);
    glPushMatrix(); //rleg+rknee
    glRotatef((GLfloat)rfootrot,1.0,0.0,0.0);
    glCallList(right_foot);
    glPopMatrix(); 
    glPopMatrix();

    glPopMatrix();
}

void Transformer::drawLeftLeg()
{
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef (0.58, -1.38, 0.0);
    glRotatef ((GLfloat) lltcurve, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) lltforward, 1.0, 0.0, 0.0);
    glRotatef ((GLfloat) lltside, 0.0, 0.0, 1.0);

    glPushMatrix(); //lleg
    glTranslatef(0.0,0.0+lbtyreshift,(GLfloat)backtyretrans);
    glCallList(left_butt);
    glPopMatrix();
    glColor3f(0,.4,1);
    glTranslatef(carback,0.0,carback);
    glPushMatrix();
    glCallList(left_thigh);
    glPopMatrix();
    glTranslatef(1.2,0.0,0.0);
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(carbackinsert,0.0,0.0);

    glPushMatrix();
    glCallList(left_knee);
    glPopMatrix();
    glRotatef ((GLfloat) llbforward, 0.0, 1.0, 0.0);
    glColor3f(1,1,1);

    glPushMatrix(); //lleg+lknee
    glTranslatef(0.0,-carbackshift,0.0);
    glCallList(left_calf);
    glPopMatrix(); 

    glColor3f(0,0,1);
    glPushMatrix(); //lleg+lknee
    glRotatef((GLfloat)lfootrot,1.0,0.0,0.0);
    glCallList(left_foot);
    glPopMatrix(); 
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void Transformer::display()
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


#include "transformer.hpp"
#include <iostream>

void Transformer::getTextures()
{
    glGenTextures(NTEX, textures);

    loadBmpTexture("textures/hdfront.bmp", textures[HDFRONT]);
    loadBmpTexture("textures/back.bmp", textures[VEHBACK]);
    loadBmpTexture("textures/tyre.bmp", textures[TYRE]);
    loadBmpTexture("textures/tyreTex.bmp", textures[TYRETEX]);
    loadBmpTexture("textures/military.bmp", textures[MILITARY]);
    loadBmpTexture("textures/grill.bmp", textures[GRILL]);
    loadBmpTexture("textures/rside.bmp", textures[RSIDE]);
    loadBmpTexture("textures/lside.bmp", textures[LSIDE]);
    loadBmpTexture("textures/hiprside.bmp", textures[HIPRSIDE]);
    loadBmpTexture("textures/hiplside.bmp", textures[HIPLSIDE]);
    loadBmpTexture("textures/rfoot.bmp", textures[RFOOT]);
    loadBmpTexture("textures/lfoot.bmp", textures[LFOOT]);
    loadBmpTexture("textures/frontPane.bmp", textures[FRONTPANE]);
    loadBmpTexture("textures/faceleft.bmp", textures[FACELEFT]);
    loadBmpTexture("textures/faceright.bmp", textures[FACERIGHT]);
    loadBmpTexture("textures/vehiclebackleft.bmp", textures[BACKLEFT]);
    loadBmpTexture("textures/vehiclebackright.bmp", textures[BACKRIGHT]);
    loadBmpTexture("textures/frontright.bmp", textures[FRONTRIGHT]);
    loadBmpTexture("textures/frontleft.bmp", textures[FRONTLEFT]);
    loadBmpTexture("textures/bonnetright.bmp", textures[BONNETRIGHT]);
    loadBmpTexture("textures/bonnetleft.bmp", textures[BONNETLEFT]);
    loadBmpTexture("textures/bonnetmid.bmp", textures[BONNETMID]);
    loadBmpTexture("textures/sparetyre.bmp", textures[SPARETYRE]);
    loadBmpTexture("textures/lightfront.bmp", textures[LIGHTFRONT]);
}

Transformer::Transformer()
{
    getTextures();
    /*
    for(int i = 0; i < 6; i++)
        headObj.T[i] = i+1;
        */
    flag=0;

    fullx=0; fully=0; fullz=0;
    bend=0;
    headside=0; headforward=0; headcurve=0;

    rshoulderside=-135; rshoulderforward=0; rshouldercurve=0; relbow=90; rfootrot=0.0; 
    lshoulderside=-45; lshoulderforward=0; lshouldercurve=0; lelbow=-90; lfootrot=0.0;

    rltside=-90; rltforward=0; rltcurve=0; rlbforward=0;
    lltside=-90; lltforward=0; lltcurve=0; llbforward=0;

    move=0.0; fronttyretrans=0.0; backtyretrans=0.0;
    lbtyreshift=0.0; rbtyreshift=0.0;
    vehiclefront=0; carfront=0.0; down=0.0;

    carback=0.0; carbackshift=0.0; carbackinsert=0.0;

    draw_left_shoulder(); draw_left_arm(); draw_left_elbow(); draw_left_forearm();
    draw_right_shoulder(); draw_right_arm(); draw_right_elbow(); draw_right_forearm();
    draw_hip(); draw_torso();
    draw_head(); draw_front(); draw_eyes(); draw_neck();
    
    draw_left_butt(); draw_left_thigh(); draw_left_knee(); draw_left_calf(); draw_left_foot();
    draw_right_butt(); draw_right_thigh(); draw_right_knee(); draw_right_calf(); draw_right_foot();

}

void Transformer::rotateX(int angle)
{
    fullx = (fullx + angle) % 360;
}
void Transformer::rotateY(int angle)
{
    fully = (fully + angle) % 360;
}
void Transformer::rotateZ(int angle)
{
    fullz = (fullz + angle) % 360;
}


void Transformer::tiltHeadSide(int angle)
{
    headside = (headside + angle) % 360;
}
void Transformer::tiltHeadFB(int angle)
{
    headforward = (headforward + angle) % 360;
}
void Transformer::turnHead(int angle)
{
    headcurve = (headcurve + angle) % 360;
}

void Transformer::bendForward(int angle)
{
    bend = (bend + angle) % 360;
}
void Transformer::bendBack(int angle)
{
    bend = (bend + angle) % 360;
}


void Transformer::rShoulderSide(int angle)
{
    rshoulderside = (rshoulderside + angle) % 360;
}
void Transformer::rShoulderFB(int angle)
{
    rshoulderforward = (rshoulderforward + angle) % 360;
}
void Transformer::rShoulderCurve(int angle)
{
    rshouldercurve = (rshouldercurve + angle) % 360;
}
void Transformer::rElbowBend(int angle)
{
    relbow = (relbow + angle) % 360;
}

void Transformer::lShoulderSide(int angle)
{
    lshoulderside = (lshoulderside + angle) % 360;
}
void Transformer::lShoulderFB(int angle)
{
    lshoulderforward = (lshoulderforward + angle) % 360;
}
void Transformer::lShoulderCurve(int angle)
{
    lshouldercurve = (lshouldercurve + angle) % 360;
}
void Transformer::lElbowBend(int angle)
{
    lelbow = (lelbow + angle) % 360;
}

void Transformer::rLegSide(int angle)
{
    rltside = (rltside + angle) % 360;
}
void Transformer::rLegFB(int angle)
{
    rltforward = (rltforward + angle) % 360;
}
void Transformer::rLegCurve(int angle)
{
    rltcurve = (rltcurve + angle) % 360;
}
void Transformer::rCalfFB(int angle)
{
    rlbforward = (rlbforward + angle) % 360;
}

void Transformer::lLegSide(int angle)
{
    lltside = (lltside + angle) % 360;
}
void Transformer::lLegFB(int angle)
{
    lltforward = (lltforward + angle) % 360;
}
void Transformer::lLegCurve(int angle)
{
    lltcurve = (lltcurve + angle) % 360;
}
void Transformer::lCalfFB(int angle)
{
    llbforward = (llbforward + angle) % 360;
}

void Transformer::draw_left_shoulder()
{
    left_shoulder = glGenLists(1);
    glNewList(left_shoulder, GL_COMPILE);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.35,0.4,32,32,textures[TYRE],textures[TYRE],textures[TYRETEX]);
    glEndList();
}
void Transformer::draw_left_arm()
{
    left_arm=glGenLists(1);
    glNewList(left_arm,GL_COMPILE);

    glTranslatef (0.5, 0.0, 0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.3,1.2,32,32,textures[SPARETYRE],textures[SPARETYRE],textures[MILITARY]);

    glEndList();
}
void Transformer::draw_left_elbow()
{
    left_elbow=glGenLists(1);
    glNewList(left_elbow,GL_COMPILE);
    glScalef(0.2,0.2,0.2);
    draw.drawSphere(32,32);
    glEndList();
}
void Transformer::draw_left_forearm()
{
    left_forearm = glGenLists(1);
    glNewList(left_forearm,GL_COMPILE);
    glTranslatef(0.8,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.2,1.5,32,32,textures[MILITARY],textures[MILITARY],textures[MILITARY]);
    glEndList();
}

void Transformer::draw_right_elbow()
{
    right_elbow = glGenLists(1);
    glNewList(right_elbow, GL_COMPILE);
    glScalef(0.2,0.2,0.2);
    draw.drawSphere(32,32);
    glEndList();
}
void Transformer::draw_right_shoulder()
{
    right_shoulder = glGenLists(1);
    glNewList(right_shoulder, GL_COMPILE);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.35,0.4,32,32,textures[TYRE],textures[TYRE],textures[TYRETEX]);
    glEndList();
}
void Transformer::draw_right_arm()
{
    right_arm = glGenLists(1);
    glNewList(right_arm, GL_COMPILE);
    glTranslatef (0.5, 0.0, 0.0);
    glRotatef(90.0f, 0.0f,1.0f, 0.0f);
    draw.drawCylinder(0.3,1.2,32,32,textures[SPARETYRE],textures[SPARETYRE],textures[MILITARY]);
    glEndList();
}
void Transformer::draw_right_forearm()
{
    right_forearm = glGenLists(1);
    glNewList(right_forearm, GL_COMPILE);
    glTranslatef(0.8,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.2,1.5,32,32,textures[MILITARY],textures[MILITARY],textures[MILITARY]);
    glEndList();
}

void Transformer::draw_hip()
{
    hip = glGenLists(1);
    glNewList(hip, GL_COMPILE);
    glTranslatef(0.0,-1.1,0.0);
    glScalef(1.6,0.3,1.25);
    draw.drawCube(0,textures[FRONTPANE],textures[MILITARY],textures[MILITARY],textures[HIPRSIDE],textures[HIPLSIDE]);
    glEndList();
}
void Transformer::draw_torso()
{
    torso = glGenLists(1);
    glNewList(torso, GL_COMPILE);
    glScalef(1.6,2.0,1.25);
    draw.drawCube(0,0,textures[MILITARY],textures[MILITARY],textures[RSIDE],textures[LSIDE]);
    glEndList();
}

void Transformer::draw_head()
{
    head = glGenLists(1);
    glNewList(head, GL_COMPILE);
    //headObj.draw();
    //drawCube(textures[HDTOP],textures[HDBOTTOM],textures[HDBACK],textures[HDFRONT],textures[HDLEFT],textures[HDRIGHT]);
    draw.drawCube(textures[MILITARY],textures[VEHBACK],textures[MILITARY],textures[HDFRONT],textures[FACELEFT], textures[FACERIGHT]);
    glEndList();
}

void Transformer::draw_front()
{
    front = glGenLists(1);
    glNewList(front, GL_COMPILE);
    //drawCube(textures[HDTOP],textures[HDBOTTOM],textures[HDBACK],textures[HDFRONT],textures[HDLEFT],textures[HDRIGHT]);
    draw.drawCube(textures[MILITARY],textures[VEHBACK],textures[MILITARY],textures[HDFRONT],textures[BACKLEFT], textures[BACKRIGHT]);
    glEndList();
}

void Transformer::draw_eyes()
{
    eyes = glGenLists(1);
    glNewList(eyes, GL_COMPILE);
    glPushMatrix();
    glTranslatef(-0.35,0.05,0.7);
    draw.drawCircle(0.15,32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.35,0.05,0.7);
    draw.drawCircle(0.15,32);
    glPopMatrix();
    glEndList();
}
void Transformer::draw_neck()
{
    neck = glGenLists(1);
    glNewList(neck, GL_COMPILE);
    glColor3f(1,0,0);
    glTranslatef (0.0, 1.15, 0.0);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    draw.drawCylinder(0.35,0.3,32,32);
    glEndList();
}

void Transformer::draw_right_butt()
{
    right_butt = glGenLists(1);
    glNewList(right_butt, GL_COMPILE);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    draw.drawCylinder(0.35,0.6,32,32, textures[TYRE],textures[TYRE],textures[TYRETEX]);
    glEndList();
}
void Transformer::draw_right_thigh()
{
    right_thigh = glGenLists(1);
    glNewList(right_thigh, GL_COMPILE);
    glTranslatef(0.6,0.0,0.0);
    glRotatef(90.0f, 0.0f,1.0f, 0.0f);
    glScalef(0.6,0.6,1.0);
    draw.drawCube(textures[FRONTRIGHT],textures[FRONTRIGHT],textures[FRONTRIGHT],textures[LIGHTFRONT],textures[BONNETRIGHT],textures[FRONTRIGHT]);
    glEndList();
}
void Transformer::draw_right_knee()
{
    right_knee = glGenLists(1);
    glNewList(right_knee, GL_COMPILE);
    glScalef(0.3,0.3,0.3);
    draw.drawSphere(32,32);
    glEndList();
}
void Transformer::draw_right_calf()
{
    right_calf = glGenLists(1);
    glNewList(right_calf, GL_COMPILE);
    glTranslatef(0.65,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.3,1.2,32,32,textures[GRILL],textures[GRILL],textures[BONNETMID]);
    glEndList();
}
void Transformer::draw_right_foot()
{
    right_foot = glGenLists(1);
    glNewList(right_foot, GL_COMPILE);
    glTranslatef(1.3,0.0,0.2);
    glScalef(0.2,0.6,1.0);
    draw.drawCube(textures[RFOOT],textures[RFOOT],textures[RFOOT],textures[RFOOT],textures[RFOOT],textures[RFOOT]);
    glEndList();
}

void Transformer::draw_left_butt()
{
    left_butt = glGenLists(1);
    glNewList(left_butt, GL_COMPILE);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    draw.drawCylinder(0.35,0.6,32,32,textures[TYRE],textures[TYRE],textures[TYRETEX]);
    glEndList();
}
void Transformer::draw_left_thigh()
{
    left_thigh = glGenLists(1);
    glNewList(left_thigh, GL_COMPILE);
    glTranslatef(0.6,0.0,0.0);   
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glScalef(0.6,0.6,1.0);
   draw.drawCube(textures[FRONTLEFT],textures[FRONTLEFT],textures[FRONTLEFT],textures[LIGHTFRONT],textures[BONNETLEFT],textures[FRONTRIGHT]);
    glEndList();
}
void Transformer::draw_left_knee()
{
    left_knee = glGenLists(1);
    glNewList(left_knee, GL_COMPILE);
    glScalef(0.3,0.3,0.3);
    draw.drawSphere(32,32);
    glEndList();
}
void Transformer::draw_left_calf()
{ 
    left_calf = glGenLists(1);
    glNewList(left_calf, GL_COMPILE);
    glTranslatef(0.65,0.0,0.0);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    draw.drawCylinder(0.3,1.2,32,32,textures[GRILL],textures[GRILL],textures[BONNETMID]);
    glEndList();
}
void Transformer::draw_left_foot()
{ 
    left_foot = glGenLists(1);
    glNewList(left_foot, GL_COMPILE);
    glTranslatef(1.3,0.0,0.2);
    glScalef(0.2,0.6,1.0);
    draw.drawCube(textures[LFOOT],textures[LFOOT],textures[LFOOT],textures[LFOOT],textures[LFOOT],textures[LFOOT]);
    glEndList();
}

void Transformer::tocar()
{
    while(1){
        if(rbtyreshift<=-0.25&&lbtyreshift>=0.25&&down<=-0.9&&carback<=-0.3&&carbackshift>=0.5&&carbackinsert<=-0.3&&rfootrot==-90&&lfootrot==90&&fronttyretrans<=-0.7&&backtyretrans<=-0.7&&fullx==0&&fully==90&&fullz==90&&bend==0&&headside==0&&headforward==0&&headcurve==0&&rshoulderside==0&&rshoulderforward==0&&rshouldercurve==0&&relbow==-90&&lshoulderside==-180&&lshoulderforward==0&&lshouldercurve==0&&lelbow==90&&rltside==-90&&rltforward==0&&rltcurve==0&&rlbforward==180&&lltside==-90&&lltforward==0&&lltcurve==0&&llbforward==180&&vehiclefront==90&&carfront==90)
        {
            flag=1;
            break;
        }
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        transform();
        display();
        GLFWwindow * win=glfwGetCurrentContext();
        glfwPollEvents();
        glfwSwapBuffers(win);
        usleep(10000);
    }
}

void Transformer::tohuman()
{
    while(1){
        if(lbtyreshift<=0.025&&rbtyreshift>=-0.025&&down>=-0.05&&carback>=-0.05&&carbackshift<=0.05&&carbackinsert>=-0.05&&rfootrot==0.0&&lfootrot==0.0&&fronttyretrans>=-0.5&&backtyretrans>=-0.5&&fullx==0&&fully==0&&fullz==0&&bend==0&&headside==0&&headforward==0&&headcurve==0&&rshoulderside==-135&&rshoulderforward==0&&rshouldercurve==0&&relbow==90&&lshoulderside==-45&&lshoulderforward==0&&lshouldercurve==0&&lelbow==-90&&rltside==-90&&rltforward==0&&rltcurve==0&&rlbforward==0&&lltside==-90&&lltforward==0&&lltcurve==0&&llbforward==0&&vehiclefront==0&&carfront==0)
        {

            flag=0;
            break;
        }
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        transform();
        display();
        GLFWwindow * win=glfwGetCurrentContext();
        glfwPollEvents();
        glfwSwapBuffers(win);
        usleep(10000);

    }
}

void Transformer::transform()
{
    if(flag==0){
        if(bend>0){
            bend=(bend-5)%360;
            return;
        }
        else if(bend<0){
            bend=(bend+5)%360;
            return;
        }
        if(headside>0){
            headside=(headside-5)%360;

            return;
        }
        else if(headside<0){
            headside=(headside+5)%360;
            return;
        }
        if(headforward>0){
            headforward=(headforward-5)%360;

            return;
        }
        else if(headforward<0){
            headforward=(headforward+5)%360;
            return;
        }
        if(headcurve>0){
            headcurve=(headcurve-5)%360;

            return;
        }
        else if(headcurve<0){
            headcurve=(headcurve+5)%360;
            return;
        }
        if(relbow>-90){
            relbow=(relbow-5)%360;
        }
        else if(relbow<-90){
            relbow=(relbow+5)%360;
        }
        if(lelbow>90){
            lelbow=(lelbow-5)%360;

            return;
        }
        else if(lelbow<90){
            lelbow=(lelbow+5)%360;
            return;
        }
        if(rshoulderside>0){
            rshoulderside=(rshoulderside-5)%360;
        }
        else if(rshoulderside<0){
            rshoulderside=(rshoulderside+5)%360;
        }
        if(lshoulderside>-180){
            lshoulderside=(lshoulderside-5)%360;

            return;
        }
        else if(lshoulderside<-180){
            lshoulderside=(lshoulderside+5)%360;
            return;
        }
        if(rshoulderforward>0){
            rshoulderforward=(rshoulderforward-5)%360;
        }
        else if(rshoulderforward<0){
            rshoulderforward=(rshoulderforward+5)%360;
        }
        if(lshoulderforward>0){
            lshoulderforward=(lshoulderforward-5)%360;

            return;
        }
        else if(lshoulderforward<-0){
            lshoulderforward=(lshoulderforward+5)%360;
            return;
        }
        if(rshouldercurve>0){
            rshouldercurve=(rshouldercurve-5)%360;
        }
        else if(rshouldercurve<0){
            rshouldercurve=(rshouldercurve+5)%360;
        }
        if(lshouldercurve>0){
            lshouldercurve=(lshouldercurve-5)%360;

            return;
        }
        else if(lshouldercurve<0){
            lshouldercurve=(lshouldercurve+5)%360;
            return;
        }
        if(down>-0.9)
        {
            down=down-0.1;
            return;
        }
        if(rlbforward>180){
            rlbforward=(rlbforward-5)%360;
        }
        else if(rlbforward<180){
            rlbforward=(rlbforward+5)%360;
        }
        if(llbforward>180){
            llbforward=(llbforward-5)%360;

            return;
        }
        else if(llbforward<180){
            llbforward=(llbforward+5)%360;
            return;
        }
        if(rltside>-90){
            rltside=(rltside-5)%360;
        }
        else if(rltside<-90){
            rltside=(rltside+5)%360;
        }
        if(lltside>-90){
            lltside=(lltside-5)%360;

            return;
        }
        else if(lltside<-90){
            lltside=(lltside+5)%360;
            return;
        }
        if(rltforward>0){
            rltforward=(rltforward-5)%360;
        }
        else if(rltforward<0){
            rltforward=(rltforward+5)%360;
        }

        if(lltforward>0){
            lltforward=(lltforward-5)%360;

            return;
        }
        else if(lltforward<0){
            lltforward=(lltforward+5)%360;
            return;
        }
        if(rltcurve>0){
            rltcurve=(rltcurve-5)%360;
        }
        else if(rltcurve<0){
            rltcurve=(rltcurve+5)%360;
        }
        if(lltcurve>0){
            lltcurve=(lltcurve-5)%360;

            return;
        }
        else if(lltcurve<0){
            lltcurve=(lltcurve+5)%360;
            return;
        }
        move=-0.5;
        if(vehiclefront>90){
            vehiclefront=(vehiclefront-5)%360;

            return;
        }
        else if(vehiclefront<90){
            vehiclefront=(vehiclefront+5)%360;
            return;
        }
        if(rbtyreshift>-0.25)
        {
            rbtyreshift=rbtyreshift-0.05;
        }

        if(lbtyreshift<0.25)
        {
            lbtyreshift=lbtyreshift+0.05;
            return;
        }


        if(fullx>0){
            fullx=(fullx-5)%360;

            return;
        }
        else if(fullx<0){
            fullx=(fullx+5)%360;
            return;
        }
        if(fully>90){
            fully=(fully-5)%360;

            return;
        }
        else if(fully<90){
            fully=(fully+5)%360;
            return;
        }
        if(fullz>90){
            fullz=(fullz-5)%360;

            return;
        } 
        else if(fullz<90){
            fullz=(fullz+5)%360;
            return;
        }
        if(fronttyretrans>-0.7)
        {
            fronttyretrans=fronttyretrans-0.1;
        }
        if(backtyretrans>-0.7)
        {
            backtyretrans=backtyretrans-0.1;
            return;
        }
        if(carfront>90){
            carfront=(carfront-5)%360;

            return;
        }
        else if(carfront<90){
            carfront=(carfront+5)%360;
            return;
        }
        if(rfootrot>-90){
            rfootrot=(rfootrot-5)%360;

            return;
        }
        else if(rfootrot<-90){
            rfootrot=(rfootrot+5)%360;
            return;
        }
        if(lfootrot>90){
            lfootrot=(lfootrot-5)%360;

            return;
        }
        else if(lfootrot<90){
            lfootrot=(lfootrot+5)%360;
            return;
        }
        if(carback>-0.3)
        {
            carback=carback-0.1;
            return;

        }
        if(carbackshift<0.5)
        {
            carbackshift=carbackshift+0.1;
            return;
        }
        if(carbackinsert>-0.3)
        {
            carbackinsert=carbackinsert-0.1;
            return;
        }
    }
    else{
        if(carbackinsert<-0.05)
        {
            carbackinsert=carbackinsert+0.1;
            return;
        }
        if(carbackshift>0.05)
        {
            carbackshift=carbackshift-0.1;
            return;
        }

        if(carback<-0.05)
        {
            carback=carback+0.1;
            return;

        }
        if(lfootrot>0){
            lfootrot=(lfootrot-5)%360;

            return;
        }
        else if(lfootrot<0){
            lfootrot=(lfootrot+5)%360;
            return;
        }


        if(rfootrot>0){
            rfootrot=(rfootrot-5)%360;

            return;
        }
        else if(rfootrot<0){
            rfootrot=(rfootrot+5)%360;
            return;
        }

        if(carfront>0){
            carfront=(carfront-5)%360;

            return;
        }
        else if(carfront<0){
            carfront=(carfront+5)%360;
            return;
        }


        if(backtyretrans<-0.05)
        {
            backtyretrans=backtyretrans+0.1;
        }
        if(fronttyretrans<-0.05)
        {
            fronttyretrans=fronttyretrans+0.1;
            return;
        }
        if(fullz>0){
            fullz=(fullz-5)%360;

            return;
        }
        else if(fullz<0){
            fullz=(fullz+5)%360;
            return;
        }
        if(fully>0){
            fully=(fully-5)%360;
            return;
        }
        else if(fully<0){
            fully=(fully+5)%360;
            return;
        }
        if(fullx>0){
            fullx=(fullx-5)%360;
            return;
        }
        else if(fullx<0){
            fullx=(fullx+5)%360;
            return;
        }
        if(lbtyreshift>0.025)
        {
            lbtyreshift=lbtyreshift-0.05;
        }
        if(rbtyreshift<-0.025)
        {
            rbtyreshift=rbtyreshift+0.05;
            return;
        }
        move=0.0;
        if(vehiclefront>0){
            vehiclefront=(vehiclefront-5)%360;
            return;
        }
        else if(vehiclefront<0){
            vehiclefront=(vehiclefront+5)%360;
            return;
        }

        if(lltcurve>0){
            lltcurve=(lltcurve-5)%360;
        }
        else if(lltcurve<0){
            lltcurve=(lltcurve+5)%360;
        }
        if(rltcurve>0){
            rltcurve=(rltcurve-5)%360;

            return;
        }
        else if(rltcurve<0){
            rltcurve=(rltcurve+5)%360;
            return;
        }
        if(lltforward>0){
            lltforward=(lltforward-5)%360;
        }
        else if(lltforward<0){
            lltforward=(lltforward+5)%360;
        }



        if(rltforward>0){
            rltforward=(rltforward-5)%360;
            return;
        }
        else if(rltforward<0){
            rltforward=(rltforward+5)%360;
            return;
        }
        if(lltside>-90){
            lltside=(lltside-5)%360;
        }
        else if(lltside<-90){
            lltside=(lltside+5)%360;
        }
        if(rltside>-90){
            rltside=(rltside-5)%360;
            return;
        }
        else if(rltside<-90){
            rltside=(rltside+5)%360;
            return;
        }
        if(llbforward>0){
            llbforward=(llbforward-5)%360;
        }
        else if(llbforward<0){
            llbforward=(llbforward+5)%360;
        }

        if(rlbforward>0){
            rlbforward=(rlbforward-5)%360;
            return;
        }
        else if(rlbforward<0){
            rlbforward=(rlbforward+5)%360;
            return;

        }

        if(down<-0.05)
        {
            down=down+0.1;
            return;
        }

        if(lshouldercurve>0){
            lshouldercurve=(lshouldercurve-5)%360;
        }
        else if(lshouldercurve<0){
            lshouldercurve=(lshouldercurve+5)%360;
        }


        if(rshouldercurve>0){
            rshouldercurve=(rshouldercurve-5)%360;
            return;
        }
        else if(rshouldercurve<0){
            rshouldercurve=(rshouldercurve+5)%360;
            return;
        }
        if(lshoulderforward>0){
            lshoulderforward=(lshoulderforward-5)%360;
        }
        else if(lshoulderforward<0){
            lshoulderforward=(lshoulderforward+5)%360;
        }
        if(rshoulderforward>0){
            rshoulderforward=(rshoulderforward-5)%360;
            return;
        }
        else if(rshoulderforward<0){
            rshoulderforward=(rshoulderforward+5)%360;
            return;
        }

        if(lshoulderside>-45){
            lshoulderside=(lshoulderside-5)%360;
        }
        else if(lshoulderside<-45){
            lshoulderside=(lshoulderside+5)%360;
        }
        if(rshoulderside>-135){
            rshoulderside=(rshoulderside-5)%360;
            return;
        }
        else if(rshoulderside<-135){
            rshoulderside=(rshoulderside+5)%360;
            return;
        }

        if(lelbow>-90){
            lelbow=(lelbow-5)%360;
        }
        else if(lelbow<-90){
            lelbow=(lelbow+5)%360;
        }


        if(relbow>90){
            relbow=(relbow-5)%360;
            return;
        }
        else if(relbow<90){
            relbow=(relbow+5)%360;
            return;
        }



        if(headcurve>0){
            headcurve=(headcurve-5)%360;
            return;
        }
        else if(headcurve<0){
            headcurve=(headcurve+5)%360;
            return;
        }

        if(headforward>0){

            headforward=(headforward-5)%360;
            return;
        }
        else if(headforward<0){
            headforward=(headforward+5)%360;
            return;
        }

        if(headside>0){
            headside=(headside-5)%360;
            return;
        }
        else if(headside<0){
            headside=(headside+5)%360;
            return;
        }

        if(bend>0){
            bend=(bend-5)%360;
            return;
        }
        else if(bend<0){
            bend=(bend+5)%360;
            return;
        }
    }
}


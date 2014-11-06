#include "animation.hpp"

void displayWorld();

World Animation::setVector(string str)
{
    World newW;
    istringstream s(str);

    s>>newW.light1>>newW.light2;
    s>>newW.T.hd1>>newW.T.hd2>>newW.T.fullx>>newW.T.fully>>newW.T.fullz>>newW.T.bend>>newW.T.headside>>newW.T.headforward>>newW.T.headcurve;
    s>>newW.T.rshoulderside>>newW.T.rshoulderforward>>newW.T.rshouldercurve>>newW.T.relbow>>newW.T.rfootrot;
    s>>newW.T.lshoulderside>>newW.T.lshoulderforward>>newW.T.lshouldercurve>>newW.T.lelbow>>newW.T.lfootrot;
    s>>newW.T.rltside>>newW.T.rltforward>>newW.T.rltcurve>>newW.T.rlbforward;
    s>>newW.T.lltside>>newW.T.lltforward>>newW.T.lltcurve>>newW.T.llbforward;
    s>>newW.T.move>>newW.T.backtyretrans>>newW.T.fronttyretrans;
    s>>newW.T.lftyreshift>>newW.T.rftyreshift;
    s>>newW.T.vehicleback>>newW.T.carback>>newW.T.down;
    s>>newW.T.carfront>>newW.T.carfrontshift>>newW.T.carfrontinsert;
    s>>newW.T.car_x>>newW.T.car_y>>newW.T.car_z;
    s>>newW.T.wheelrot>>newW.T.wheelturn>>newW.T.flag;
    s>>newW.ball_x>>newW.ball_y>>newW.ball_z;

    return newW;
}

string Animation::getVector(World newW)
{
    ostringstream s;

    s<<newW.light1<<" "<<newW.light2<<" ";
    s<<newW.T.hd1<<" "<<newW.T.hd2<<" "<<newW.T.fullx<<" "<<newW.T.fully<<" "<<newW.T.fullz<<" "<<newW.T.bend<<" "<<newW.T.headside<<" "<<newW.T.headforward<<" "<<newW.T.headcurve<<" ";
    s<<newW.T.rshoulderside<<" "<<newW.T.rshoulderforward<<" "<<newW.T.rshouldercurve<<" "<<newW.T.relbow<<" "<<newW.T.rfootrot<<" ";
    s<<newW.T.lshoulderside<<" "<<newW.T.lshoulderforward<<" "<<newW.T.lshouldercurve<<" "<<newW.T.lelbow<<" "<<newW.T.lfootrot<<" ";
    s<<newW.T.rltside<<" "<<newW.T.rltforward<<" "<<newW.T.rltcurve<<" "<<newW.T.rlbforward<<" ";
    s<<newW.T.lltside<<" "<<newW.T.lltforward<<" "<<newW.T.lltcurve<<" "<<newW.T.llbforward<<" ";
    s<<newW.T.move<<" "<<newW.T.backtyretrans<<" "<<newW.T.fronttyretrans<<" ";
    s<<newW.T.lftyreshift<<" "<<newW.T.rftyreshift<<" ";
    s<<newW.T.vehicleback<<" "<<newW.T.carback<<" "<<newW.T.down<<" ";
    s<<newW.T.carfront<<" "<<newW.T.carfrontshift<<" "<<newW.T.carfrontinsert<<" ";
    s<<newW.T.car_x<<" "<<newW.T.car_y<<" "<<newW.T.car_z<<" ";
    s<<newW.T.wheelrot<<" "<<newW.T.wheelturn<<" "<<newW.T.flag<<" ";
    s<<newW.ball_x<<" "<<newW.ball_y<<" "<<newW.ball_z;
    string st=s.str();
    return st;
}

void Animation::capture_frame(unsigned int frame_num)
{
    unsigned char *pRGB;

    int SCREEN_WIDTH=512;
    int SCREEN_HEIGHT=512;
    //global pointer float *pRGB
    pRGB = new unsigned char [3 * (SCREEN_WIDTH+1) * (SCREEN_HEIGHT + 1) ];


    // set the framebuffer to read
    //default for double buffered
    glReadBuffer(GL_BACK);

    glPixelStoref(GL_PACK_ALIGNMENT,1);//for word allignment

    glReadPixels(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pRGB);
    char filename[200];
    sprintf(filename,"frames/frame_%04d.ppm",frame_num);
    std::ofstream out(filename, std::ios::out);
    out<<"P6"<<std::endl;
    out<<SCREEN_WIDTH<<" "<<SCREEN_HEIGHT<<" 255"<<std::endl;
    out.write(reinterpret_cast<char const *>(pRGB), (3 * (SCREEN_WIDTH+1) * (SCREEN_HEIGHT + 1)) * sizeof(int));
    out.close();

    //function to store pRGB in a file named count
    delete pRGB;
}

void Animation::drawScene()
{
    extern World W;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    GLFWwindow * win=glfwGetCurrentContext();
    displayWorld();
    glfwSwapBuffers(win);
    glfwPollEvents();
    glfwSetTime(0);

    while(glfwGetTime()<=0.01);
}
void Animation::record()
{
    extern World W;
    string newS=getVector(W);
    ofstream outfile;
    outfile.open("keyframes.txt",ofstream::out | ofstream::app);
    outfile << newS << endl;
}

void Animation::interPolate(World nextState)
{
    extern World W;
    static unsigned int framenum=0;
    float balldiff,i=0.0;
    if(abs(W.ball_x-nextState.ball_x)>abs(W.ball_z-nextState.ball_z))
        balldiff=abs(W.ball_x-nextState.ball_x);
    else
        balldiff=abs(W.ball_z-nextState.ball_z);

    while(1)
    {
        if(abs(W.ball_x-nextState.ball_x)<0.06&&abs(W.ball_z-nextState.ball_z)<0.06&&abs(W.T.car_x-nextState.T.car_x)<0.06&&abs(W.T.car_y-nextState.T.car_y)<0.006&&abs(W.T.car_z-nextState.T.car_z)<0.06&&abs(W.T.rftyreshift-nextState.T.rftyreshift)<0.03&&abs(W.T.lftyreshift-nextState.T.lftyreshift)<0.03&&abs(W.T.down-nextState.T.down)<0.06&&abs(W.T.carfront-nextState.T.carfront)<0.06&&abs(W.T.carfrontshift-nextState.T.carfrontshift)<0.06&&abs(W.T.carfrontinsert-nextState.T.carfrontinsert)<0.06&&abs(W.T.rfootrot-nextState.T.rfootrot)<3&&abs(W.T.lfootrot-nextState.T.lfootrot)<3&&abs(W.T.fronttyretrans-nextState.T.fronttyretrans)<0.06&&abs(W.T.backtyretrans-nextState.T.backtyretrans)<0.06&&abs(W.T.fullx-nextState.T.fullx)<3&&abs(W.T.fully-nextState.T.fully)<3&&abs(W.T.fullz-nextState.T.fullz)<3&&abs(W.T.headside-nextState.T.headside)<3&&abs(W.T.headforward-nextState.T.headforward)<3&&abs(W.T.headcurve-nextState.T.headcurve)<3&&abs(W.T.rshoulderside-nextState.T.rshoulderside)<3&&abs(W.T.rshoulderforward-nextState.T.rshoulderforward)<3&&abs(W.T.rshouldercurve-nextState.T.rshouldercurve)<3&&abs(W.T.relbow-nextState.T.relbow)<3&&abs(W.T.lshoulderside-nextState.T.lshoulderside)<3&&abs(W.T.lshoulderforward-nextState.T.lshoulderforward)<3&&abs(W.T.lshouldercurve-nextState.T.lshouldercurve)<3&&abs(W.T.lelbow-nextState.T.lelbow)<3&&abs(W.T.rltside-nextState.T.rltside)<3&&abs(W.T.rltforward-nextState.T.rltforward)<3&&abs(W.T.rltcurve-nextState.T.rltcurve)<3&&abs(W.T.rlbforward-nextState.T.rlbforward)<3&&abs(W.T.lltside-nextState.T.lltside)<3&&abs(W.T.lltforward-nextState.T.lltforward)<3&&abs(W.T.lltcurve-nextState.T.lltcurve)<3&&abs(W.T.llbforward-nextState.T.llbforward)<3&&abs(W.T.vehicleback-nextState.T.vehicleback)<3&&abs(W.T.carback-nextState.T.carback)<3)
        {
            break;
        }
        if(nextState.T.flag)
            W.T.flag=1;
        else
            W.T.flag=0;
        if(W.T.flag)
        {
            W.T.move=-0.5;
        }
        else
            W.T.move=0.0;
        if(nextState.light1)
        {
            W.light1=1;
            W.L1.on();
        }
        else
        {
            W.light1=0;
            W.L1.off();
        }
        if(nextState.light2)
        {
            W.light2=1;
            W.L2.on();
        }
        else
        {
            W.light2=0;
            W.L2.off();
        }
        if(nextState.T.hd1)
        {
            W.T.hd1=1;
            W.T.hdL1.on();
        }
        else
        {
            W.T.hd1=0;
            W.T.hdL1.off();
        }
        if(nextState.T.hd2)
        {
            W.T.hd2=1;
            W.T.hdL2.on();
        }
        else
        {
            W.T.hd2=0;
            W.T.hdL2.off();
        }
        /*
        if(abs(W.T.bend-nextState.T.bend)>=3)
        {
            if(W.T.bend>nextState.T.bend)
            {
                W.T.bend=(W.T.bend-5)%360;
            }
            else if(W.T.bend<nextState.T.bend)
            {
                W.T.bend=(W.T.bend+5)%360;
            }
        }*/
        if(abs(W.T.headside-nextState.T.headside)>=3)
        {
            if(W.T.headside>nextState.T.headside)
            {
                W.T.headside=(W.T.headside-5)%360;
            }
            else if(W.T.headside<nextState.T.headside)
            {
                W.T.headside=(W.T.headside+5)%360;
            }
        }
        if(abs(W.T.headforward-nextState.T.headforward)>=3)
        {
            if(W.T.headforward>nextState.T.headforward)
            {
                W.T.headforward=(W.T.headforward-5)%360;
            }
            else if(W.T.headforward<nextState.T.headforward)
            {
                W.T.headforward=(W.T.headforward+5)%360;
            }
        }
        if(abs(W.T.headcurve-nextState.T.headcurve)>=3)
        {
            if(W.T.headcurve>nextState.T.headcurve)
            {
                W.T.headcurve=(W.T.headcurve-5)%360;
            }
            else if(W.T.headcurve<nextState.T.headcurve)
            {
                W.T.headcurve=(W.T.headcurve+5)%360;
            }
        }
        if(abs(W.T.relbow-nextState.T.relbow)>=3)
        {
            if(W.T.relbow>nextState.T.relbow)
            {
                W.T.relbow=(W.T.relbow-5)%360;
            }
            else if(W.T.relbow<nextState.T.relbow)
            {
                W.T.relbow=(W.T.relbow+5)%360;
            }
        }
        if(abs(W.T.lelbow-nextState.T.lelbow)>=3)
        {
            if(W.T.lelbow>nextState.T.lelbow)
            {
                W.T.lelbow=(W.T.lelbow-5)%360;
            }
            else if(W.T.lelbow<nextState.T.lelbow)
            {
                W.T.lelbow=(W.T.lelbow+5)%360;
            }
        }
        if(abs(W.T.rshoulderside-nextState.T.rshoulderside)>=3)
        {
            if(W.T.rshoulderside>nextState.T.rshoulderside)
            {
                W.T.rshoulderside=(W.T.rshoulderside-5)%360;
            }
            else if(W.T.rshoulderside<nextState.T.rshoulderside)
            {
                W.T.rshoulderside=(W.T.rshoulderside+5)%360;
            }
        }
        if(abs(W.T.lshoulderside-nextState.T.lshoulderside)>=3)
        {
            if(W.T.lshoulderside>nextState.T.lshoulderside)
            {
                W.T.lshoulderside=(W.T.lshoulderside-5)%360;
            }
            else if(W.T.lshoulderside<nextState.T.lshoulderside)
            {
                W.T.lshoulderside=(W.T.lshoulderside+5)%360;
            }
        }
        if(abs(W.T.rshoulderforward-nextState.T.rshoulderforward)>=3)
        {
            if(W.T.rshoulderforward>nextState.T.rshoulderforward)
            {
                W.T.rshoulderforward=(W.T.rshoulderforward-5)%360;
            }
            else if(W.T.rshoulderforward<nextState.T.rshoulderforward)
            {
                W.T.rshoulderforward=(W.T.rshoulderforward+5)%360;
            }
        }
        if(abs(W.T.lshoulderforward-nextState.T.lshoulderforward)>=3)
        {
            if(W.T.lshoulderforward>nextState.T.lshoulderforward)
            {
                W.T.lshoulderforward=(W.T.lshoulderforward-5)%360;
            }
            else if(W.T.lshoulderforward<nextState.T.lshoulderforward)
            {
                W.T.lshoulderforward=(W.T.lshoulderforward+5)%360;
            }
        }
        if(abs(W.T.rshouldercurve-nextState.T.rshouldercurve)>=3)
        {
            if(W.T.rshouldercurve>nextState.T.rshouldercurve)
            {
                W.T.rshouldercurve=(W.T.rshouldercurve-5)%360;
            }
            else if(W.T.rshouldercurve<nextState.T.rshouldercurve)
            {
                W.T.rshouldercurve=(W.T.rshouldercurve+5)%360;
            }
        }
        if(abs(W.T.lshouldercurve-nextState.T.lshouldercurve)>=3)
        {
            if(W.T.lshouldercurve>nextState.T.lshouldercurve)
            {
                W.T.lshouldercurve=(W.T.lshouldercurve-5)%360;
            }
            else if(W.T.lshouldercurve<nextState.T.lshouldercurve)
            {
                W.T.lshouldercurve=(W.T.lshouldercurve+5)%360;
            }
        }
        if(abs(W.T.down-nextState.T.down)>=0.06)
        {
            if(W.T.down>nextState.T.down)
            {
                W.T.down=W.T.down-0.1;
            }
            else if(W.T.down<nextState.T.down)
            {
                W.T.down=W.T.down+0.1;
            }
        }
        if(abs(W.T.rlbforward-nextState.T.rlbforward)>=3)
        {
            if(W.T.rlbforward>nextState.T.rlbforward)
            {
                W.T.rlbforward=(W.T.rlbforward-5)%360;
            }
            else if(W.T.rlbforward<nextState.T.rlbforward)
            {
                W.T.rlbforward=(W.T.rlbforward+5)%360;
            }
        }
        if(abs(W.T.llbforward-nextState.T.llbforward)>=3)
        {
            if(W.T.llbforward>nextState.T.llbforward)
            {
                W.T.llbforward=(W.T.llbforward-5)%360;
            }
            else if(W.T.llbforward<nextState.T.llbforward)
            {
                W.T.llbforward=(W.T.llbforward+5)%360;
            }
        }
        if(abs(W.T.rltside-nextState.T.rltside)>=3)
        {
            if(W.T.rltside>nextState.T.rltside)
            {
                W.T.rltside=(W.T.rltside-5)%360;
            }
            else if(W.T.rltside<nextState.T.rltside)
            {
                W.T.rltside=(W.T.rltside+5)%360;
            }
        }
        if(abs(W.T.lltside-nextState.T.lltside)>=3)
        {
            if(W.T.lltside>nextState.T.lltside)
            {
                W.T.lltside=(W.T.lltside-5)%360;
            }
            else if(W.T.lltside<nextState.T.lltside)
            {
                W.T.lltside=(W.T.lltside+5)%360;
            }
        }
        if(abs(W.T.rltforward-nextState.T.rltforward)>=3)
        {
            if(W.T.rltforward>nextState.T.rltforward)
            {
                W.T.rltforward=(W.T.rltforward-5)%360;
            }
            else if(W.T.rltforward<nextState.T.rltforward)
            {
                W.T.rltforward=(W.T.rltforward+5)%360;
            }
        }
        if(abs(W.T.lltforward-nextState.T.lltforward)>=3)
        {
            if(W.T.lltforward>nextState.T.lltforward)
            {
                W.T.lltforward=(W.T.lltforward-5)%360;
            }
            else if(W.T.lltforward<nextState.T.lltforward)
            {
                W.T.lltforward=(W.T.lltforward+5)%360;
            }
        }
        if(abs(W.T.rltcurve-nextState.T.rltcurve)>=3)
        {
            if(W.T.rltcurve>nextState.T.rltcurve)
            {
                W.T.rltcurve=(W.T.rltcurve-5)%360;
            }
            else if(W.T.rltcurve<nextState.T.rltcurve)
            {
                W.T.rltcurve=(W.T.rltcurve+5)%360;
            }
        }
        if(abs(W.T.lltcurve-nextState.T.lltcurve)>=3)
        {
            if(W.T.lltcurve>nextState.T.lltcurve)
            {
                W.T.lltcurve=(W.T.lltcurve-5)%360;
            }
            else if(W.T.lltcurve<nextState.T.lltcurve)
            {
                W.T.lltcurve=(W.T.lltcurve+5)%360;
            }
        }
        if(abs(W.T.vehicleback-nextState.T.vehicleback)>=3)
        {
            if(W.T.vehicleback>nextState.T.vehicleback)
            {
                W.T.vehicleback=(W.T.vehicleback-5)%360;
            }
            else if(W.T.vehicleback<nextState.T.vehicleback)
            {
                W.T.vehicleback=(W.T.vehicleback+5)%360;
            }
        }
        if(abs(W.T.rftyreshift-nextState.T.rftyreshift)>=0.03)
        {
            if(W.T.rftyreshift>nextState.T.rftyreshift)
            {
                W.T.rftyreshift=W.T.rftyreshift-0.05;
            }
            else if(W.T.rftyreshift<nextState.T.rftyreshift)
            {
                W.T.rftyreshift=W.T.rftyreshift+0.05;
            }
        }
        if(abs(W.T.lftyreshift-nextState.T.lftyreshift)>=0.03)
        {
            if(W.T.lftyreshift<nextState.T.lftyreshift)
            {
                W.T.lftyreshift=W.T.lftyreshift+0.05;
            }
            else if(W.T.lftyreshift>nextState.T.lftyreshift)
            {
                W.T.lftyreshift=W.T.lftyreshift-0.05;
            }
        }
        if(abs(W.T.fullz-nextState.T.fullz)>=3)
        {
            if(W.T.fullz>nextState.T.fullz)
            {
                W.T.fullz=(W.T.fullz-5)%360;
            }
            else if(W.T.fullz<nextState.T.fullz)
            {
                W.T.fullz=(W.T.fullz+5)%360;
            }
        }
        if(abs(W.T.fullx-nextState.T.fullx)>=3)
        {
            if(W.T.fullx>nextState.T.fullx)
            {
                W.T.fullx=(W.T.fullx-5)%360;
            }
            else if(W.T.fullx<nextState.T.fullx)
            {
                W.T.fullx=(W.T.fullx+5)%360;
            }
        }
        if(abs(W.T.fully-nextState.T.fully)>=3)
        {
            if(W.T.fully>nextState.T.fully)
            {
                W.T.fully=(W.T.fully-5)%360;
            }
            else if(W.T.fully<nextState.T.fully)
            {
                W.T.fully=(W.T.fully+5)%360;
            }
        }
        if(abs(W.T.fronttyretrans-nextState.T.fronttyretrans)>=0.06)
        {
            if(W.T.fronttyretrans>nextState.T.fronttyretrans)
            {
                W.T.fronttyretrans=W.T.fronttyretrans-0.1;
            }
            else if(W.T.fronttyretrans<nextState.T.fronttyretrans)
            {
                W.T.fronttyretrans=W.T.fronttyretrans+0.1;
            }
        }
        if(abs(W.T.backtyretrans-nextState.T.backtyretrans)>=0.06)
        {
            if(W.T.backtyretrans>nextState.T.backtyretrans)
            {
                W.T.backtyretrans=W.T.backtyretrans-0.1;
            }
            else if(W.T.backtyretrans<nextState.T.backtyretrans)
            {
                W.T.backtyretrans=W.T.backtyretrans+0.1;
            }
        }
        if(abs(W.T.carback-nextState.T.carback)>=3)
        {
            if(W.T.carback>nextState.T.carback)
            {
                W.T.carback=(W.T.carback-5)%360;
            }
            else if(W.T.carback<nextState.T.carback)
            {
                W.T.carback=(W.T.carback+5)%360;
            }
        }
        if(abs(W.T.rfootrot-nextState.T.rfootrot)>=3)
        {
            if(W.T.rfootrot>nextState.T.rfootrot)
            {
                W.T.rfootrot=(W.T.rfootrot-5)%360;
            }
            else if(W.T.rfootrot<nextState.T.rfootrot)
            {
                W.T.rfootrot=(W.T.rfootrot+5)%360;
            }
        }
        if(abs(W.T.lfootrot-nextState.T.lfootrot)>=3)
        {
            if(W.T.lfootrot>nextState.T.lfootrot)
            {
                W.T.lfootrot=(W.T.lfootrot-5)%360;
            }
            else if(W.T.lfootrot<nextState.T.lfootrot)
            {
                W.T.lfootrot=(W.T.lfootrot+5)%360;
            }
        }
        if(abs(W.T.carfront-nextState.T.carfront)>=0.06)
        {
            if(W.T.carfront>nextState.T.carfront)
            {
                W.T.carfront=W.T.carfront-0.1;
            }
            else if(W.T.carfront<nextState.T.carfront)
            {
                W.T.carfront=W.T.carfront+0.1;
            }
        }
        if(abs(W.T.carfrontshift-nextState.T.carfrontshift)>=0.06)
        {
            if(W.T.carfrontshift<nextState.T.carfrontshift)
            {
                W.T.carfrontshift=W.T.carfrontshift+0.1;
            }
            else if(W.T.carfrontshift>nextState.T.carfrontshift)
            {
                W.T.carfrontshift=W.T.carfrontshift-0.1;
            }

        }
        if(abs(W.T.carfrontinsert-nextState.T.carfrontinsert)>=0.06)
        {
            if(W.T.carfrontinsert>nextState.T.carfrontinsert)
            {
                W.T.carfrontinsert=W.T.carfrontinsert-0.1;
            }
            else if(W.T.carfrontinsert<nextState.T.carfrontinsert)
            {
                W.T.carfrontinsert=W.T.carfrontinsert+0.1;
            }
        }
        if(abs(W.T.car_x-nextState.T.car_x)>=0.06)
        {
            if(W.T.car_x>nextState.T.car_x)
            {
                W.T.car_x=W.T.car_x-0.1;

                W.T.wheelrot=(W.T.wheelrot-3)%360;
            }
            else if(W.T.car_x<nextState.T.car_x)
            {
                W.T.car_x=W.T.car_x+0.1;

                W.T.wheelrot=(W.T.wheelrot+3)%360;
            }
        }
        if(abs(W.T.car_y-nextState.T.car_y)>=0.006)
        {
            if(W.T.car_y>nextState.T.car_y)
            {
                W.T.car_y=W.T.car_y-0.01;
            }
            else if(W.T.car_y<nextState.T.car_y)
            {
                W.T.car_y=W.T.car_y+0.01;
            }
        }
        if(abs(W.T.car_z-nextState.T.car_z)>=0.06)
        {
            if(W.T.car_z>nextState.T.car_z)
            {
                W.T.car_z=W.T.car_z-0.1;
            }
            else if(W.T.car_z<nextState.T.car_z)
            {
                W.T.car_z=W.T.car_z+0.1;
            }
        }
        if(abs(W.ball_x-nextState.ball_x)>=0.06)
        {
            if(W.ball_x>nextState.ball_x)
            {
                W.ball_x=W.ball_x-0.1;
            }
            else if(W.ball_x<nextState.ball_x)
            {
                W.ball_x=W.ball_x+0.1;
            }
           /* if(W.ball_z>nextState.ball_z)
            {
                W.ball_z=W.ball_z-0.1;
            }
            else if(W.ball_z<nextState.ball_z)
            {
                W.ball_z=W.ball_z+0.1;
            }
            if(i<(balldiff/2))
                W.ball_y=W.ball_y+0.1;
            else{
                W.ball_y=W.ball_y-0.1;
                W.ball_z=W.ball_z+0.1;

            }
            i=i+0.1;*/

        }
        
           /* if(abs(W.ball_y-nextState.ball_y)>=0.06)
            {
            if(W.ball_y>nextState.ball_y)
            {
            W.ball_y=W.ball_y-0.1;
            }
            else if(W.ball_y<nextState.ball_y)
            {
            W.ball_y=W.ball_y+0.1;
            }
            }
            */
            if(abs(W.ball_z-nextState.ball_z)>=0.06)
            {
            if(W.ball_z>nextState.ball_z)
            {
             
            W.ball_y=W.ball_y+0.1;
            W.ball_z=W.ball_z-0.1;
            }
            else if(W.ball_z<nextState.ball_z)
            {

            W.ball_y=W.ball_y-0.07;
            W.ball_z=W.ball_z+0.1;
if(W.ball_y<5){
if(W.T.bend>-90.0)
W.T.bend=W.T.bend-1;
}
            }
            }
            
        W.T.wheelturn=nextState.T.wheelturn;


        drawScene();
        if(W.capture)
        {
            capture_frame(framenum);
        }
    }
}
void Animation::playBack()
{
    extern World W;
    ifstream inputfile;
    inputfile.open("keyframes.txt");
    string next;
    World nextT;

    W.T.camFlag = false;
    W.T.cam2Flag = false;
    W.T.hdLights = false;
    W.T.hdL1 = Light(GL_LIGHT3, 0,0,0, true);
    W.T.hdL2 = Light(GL_LIGHT4, 0,0,0, true);

    W.T.hd1=0;
    W.T.hd2=0;
    W.light1=1;
    W.light2=1;
    W.T.flag = 0;

    W.T.fullx=0;
    W.T.fully=0;
    W.T.fullz=0;
    W.T.bend=0;
    W.T.headside=0;
    W.T.headforward=0;
    W.T.headcurve=0;

    W.T.rshoulderside=-135;
    W.T.rshoulderforward=0;
    W.T.rshouldercurve=0;
    W.T.relbow=90;
    W.T.rfootrot=0.0;
    W.T.lshoulderside=-45;
    W.T.lshoulderforward=0;
    W.T.lshouldercurve=0;
    W.T.lelbow=-90;
    W.T.lfootrot=0.0;

    W.T.rltside=-90;
    W.T.rltforward=0;
    W.T.rltcurve=0;
    W.T.rlbforward=0;
    W.T.lltside=-90;
    W.T.lltforward=0;
    W.T.lltcurve=0;
    W.T.llbforward=0;

    W.T.move=0.0;
    W.T.backtyretrans=0.0;
    W.T.fronttyretrans=0.0;
    W.T.lftyreshift=0.0;
    W.T.rftyreshift=0.0;
    W.T.vehicleback=0;
    W.T.carback=0;
    W.T.down=0.0;

    W.T.carfront=0.0;
    W.T.carfrontshift=0.0;
    W.T.carfrontinsert=0.0;

    W.T.car_x=0.0;
    W.T.car_y=-5.0;
    W.T.car_z=0.0;
    W.T.wheelrot=0;
    W.T.wheelturn=0;
    W.ball_x=-8.0;
    W.ball_y=-9.0;
    W.ball_z=-10.0;
    drawScene();
    while (getline( inputfile, next ))
    {
        nextT= setVector(next);
        interPolate(nextT);
    }
}

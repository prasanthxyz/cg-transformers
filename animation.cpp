#include "animation.hpp"
void displayWorld();

Transformer Animation::setVector(string str)
{
	Transformer newT;
	istringstream s(str);
	s>>newT.light1>>newT.light2;
	s>>newT.hd1>>newT.hd2>>newT.fullx>>newT.fully>>newT.fullz>>newT.bend>>newT.headside>>newT.headforward>>newT.headcurve;
	s>>newT.rshoulderside>>newT.rshoulderforward>>newT.rshouldercurve>>newT.relbow>>newT.rfootrot;
	s>>newT.lshoulderside>>newT.lshoulderforward>>newT.lshouldercurve>>newT.lelbow>>newT.lfootrot;
	s>>newT.rltside>>newT.rltforward>>newT.rltcurve>>newT.rlbforward;
	s>>newT.lltside>>newT.lltforward>>newT.lltcurve>>newT.llbforward;
	s>>newT.move>>newT.backtyretrans>>newT.fronttyretrans;
	s>>newT.lftyreshift>>newT.rftyreshift;
	s>>newT.vehicleback>>newT.carback>>newT.down;
	s>>newT.carfront>>newT.carfrontshift>>newT.carfrontinsert;
	s>>newT.car_x>>newT.car_y>>newT.car_z;
	s>>newT.wheelrot>>newT.wheelturn>>newT.flag;
	return newT;
}
string Animation::getVector(Transformer newT)
{
	ostringstream s;
	s<<newT.light1<<" "<<newT.light2<<" ";
	s<<newT.hd1<<" "<<newT.hd2<<" "<<newT.fullx<<" "<<newT.fully<<" "<<newT.fullz<<" "<<newT.bend<<" "<<newT.headside<<" "<<newT.headforward<<" "<<newT.headcurve<<" ";
	s<<newT.rshoulderside<<" "<<newT.rshoulderforward<<" "<<newT.rshouldercurve<<" "<<newT.relbow<<" "<<newT.rfootrot<<" ";
	s<<newT.lshoulderside<<" "<<newT.lshoulderforward<<" "<<newT.lshouldercurve<<" "<<newT.lelbow<<" "<<newT.lfootrot<<" ";
	s<<newT.rltside<<" "<<newT.rltforward<<" "<<newT.rltcurve<<" "<<newT.rlbforward<<" ";
	s<<newT.lltside<<" "<<newT.lltforward<<" "<<newT.lltcurve<<" "<<newT.llbforward<<" ";
	s<<newT.move<<" "<<newT.backtyretrans<<" "<<newT.fronttyretrans<<" ";
	s<<newT.lftyreshift<<" "<<newT.rftyreshift<<" ";
	s<<newT.vehicleback<<" "<<newT.carback<<" "<<newT.down<<" ";
	s<<newT.carfront<<" "<<newT.carfrontshift<<" "<<newT.carfrontinsert<<" ";
	s<<newT.car_x<<" "<<newT.car_y<<" "<<newT.car_z<<" ";
	s<<newT.wheelrot<<" "<<newT.wheelturn<<" "<<newT.flag;
	string st=s.str();
	return st;
}
void Animation::drawScene(){
	extern World W;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	GLFWwindow * win=glfwGetCurrentContext();
	displayWorld();
	glfwSwapBuffers(win);
	glfwSetTime(0);
	while(glfwGetTime()<=0.05);
}
void Animation::record(){
	extern World W;
	string newS=getVector(W.T);
	ofstream outfile;	
	outfile.open("keyframes.txt",ofstream::out | ofstream::app);
	outfile << newS << endl;
}

void Animation::interPolate(Transformer nextState){
	extern World W;
	while(1){
		if(abs(W.T.car_x-nextState.car_x)<0.06&&abs(W.T.car_y-nextState.car_y)<0.06&&abs(W.T.car_z-nextState.car_z)<0.06&&abs(W.T.rftyreshift-nextState.rftyreshift)<0.03&&abs(W.T.lftyreshift-nextState.lftyreshift)<0.03&&abs(W.T.down-nextState.down)<0.06&&abs(W.T.carfront-nextState.carfront)<0.06&&abs(W.T.carfrontshift-nextState.carfrontshift)<0.06&&abs(W.T.carfrontinsert-nextState.carfrontinsert)<0.06&&abs(W.T.rfootrot-nextState.rfootrot)<3&&abs(W.T.lfootrot-nextState.lfootrot)<3&&abs(W.T.fronttyretrans-nextState.fronttyretrans)<0.06&&abs(W.T.backtyretrans-nextState.backtyretrans)<0.06&&abs(W.T.fullx-nextState.fullx)<3&&abs(W.T.fully-nextState.fully)<3&&abs(W.T.fullz-nextState.fullz)<3&&abs(W.T.bend-nextState.bend)<3&&abs(W.T.headside-nextState.headside)<3&&abs(W.T.headforward-nextState.headforward)<3&&abs(W.T.headcurve-nextState.headcurve)<3&&abs(W.T.rshoulderside-nextState.rshoulderside)<3&&abs(W.T.rshoulderforward-nextState.rshoulderforward)<3&&abs(W.T.rshouldercurve-nextState.rshouldercurve)<3&&abs(W.T.relbow-nextState.relbow)<3&&abs(W.T.lshoulderside-nextState.lshoulderside)<3&&abs(W.T.lshoulderforward-nextState.lshoulderforward)<3&&abs(W.T.lshouldercurve-nextState.lshouldercurve)<3&&abs(W.T.lelbow-nextState.lelbow)<3&&abs(W.T.rltside-nextState.rltside)<3&&abs(W.T.rltforward-nextState.rltforward)<3&&abs(W.T.rltcurve-nextState.rltcurve)<3&&abs(W.T.rlbforward-nextState.rlbforward)<3&&abs(W.T.lltside-nextState.lltside)<3&&abs(W.T.lltforward-nextState.lltforward)<3&&abs(W.T.lltcurve-nextState.lltcurve)<3&&abs(W.T.llbforward-nextState.llbforward)<3&&abs(W.T.vehicleback-nextState.vehicleback)<3&&abs(W.T.carback-nextState.carback)<3)
		{
			break;
		}
		if(nextState.flag)
			W.T.flag=1;
		else
			W.T.flag=0;
		if(W.T.flag){
			W.T.move=-0.5;
		}
		else
			W.T.move=0.0;
		if(nextState.light1){
			W.T.light1=1;
			W.L1.on();
		}
		else{
			W.T.light1=0;
			W.L1.off();
		}
		if(nextState.light2){
			W.T.light2=1;
			W.L2.on();
		}
		else{
			W.T.light2=0;
			W.L2.off();
		}
		if(nextState.hd1){
			W.T.hd1=1;
			W.T.hdL1.on();
		}
		else{
			W.T.hd1=0;
			W.T.hdL1.off();
		}
		if(nextState.hd2){
			W.T.hd2=1;
			W.T.hdL2.on();
		}
		else{
			W.T.hd2=0;
			W.T.hdL2.off();
		}
		if(abs(W.T.bend-nextState.bend)>=3){
			if(W.T.bend>nextState.bend){
				W.T.bend=(W.T.bend-5)%360;
			}
			else if(W.T.bend<nextState.bend){
				W.T.bend=(W.T.bend+5)%360;
			}
		}
		if(abs(W.T.headside-nextState.headside)>=3){
		if(W.T.headside>nextState.headside){
			W.T.headside=(W.T.headside-5)%360;
		}
		else if(W.T.headside<nextState.headside){
			W.T.headside=(W.T.headside+5)%360;
		}}
		if(abs(W.T.headforward-nextState.headforward)>=3){
		if(W.T.headforward>nextState.headforward){
			W.T.headforward=(W.T.headforward-5)%360;
		}
		else if(W.T.headforward<nextState.headforward){
			W.T.headforward=(W.T.headforward+5)%360;
		}}
		if(abs(W.T.headcurve-nextState.headcurve)>=3){
		if(W.T.headcurve>nextState.headcurve){
			W.T.headcurve=(W.T.headcurve-5)%360;
		}
		else if(W.T.headcurve<nextState.headcurve){
			W.T.headcurve=(W.T.headcurve+5)%360;
		}}
		if(abs(W.T.relbow-nextState.relbow)>=3){
		if(W.T.relbow>nextState.relbow){
			W.T.relbow=(W.T.relbow-5)%360;
		}
		else if(W.T.relbow<nextState.relbow){
			W.T.relbow=(W.T.relbow+5)%360;
		}}
		if(abs(W.T.lelbow-nextState.lelbow)>=3){
		if(W.T.lelbow>nextState.lelbow){
			W.T.lelbow=(W.T.lelbow-5)%360;
		}
		else if(W.T.lelbow<nextState.lelbow){
			W.T.lelbow=(W.T.lelbow+5)%360;
		}}
		if(abs(W.T.rshoulderside-nextState.rshoulderside)>=3){
		if(W.T.rshoulderside>nextState.rshoulderside){
			W.T.rshoulderside=(W.T.rshoulderside-5)%360;
		}
		else if(W.T.rshoulderside<nextState.rshoulderside){
			W.T.rshoulderside=(W.T.rshoulderside+5)%360;
		}}
		if(abs(W.T.lshoulderside-nextState.lshoulderside)>=3){
		if(W.T.lshoulderside>nextState.lshoulderside){
			W.T.lshoulderside=(W.T.lshoulderside-5)%360;
		}
		else if(W.T.lshoulderside<nextState.lshoulderside){
			W.T.lshoulderside=(W.T.lshoulderside+5)%360;
		}}
		if(abs(W.T.rshoulderforward-nextState.rshoulderforward)>=3){
		if(W.T.rshoulderforward>nextState.rshoulderforward){
			W.T.rshoulderforward=(W.T.rshoulderforward-5)%360;
		}
		else if(W.T.rshoulderforward<nextState.rshoulderforward){
			W.T.rshoulderforward=(W.T.rshoulderforward+5)%360;
		}}
		if(abs(W.T.lshoulderforward-nextState.lshoulderforward)>=3){
		if(W.T.lshoulderforward>nextState.lshoulderforward){
			W.T.lshoulderforward=(W.T.lshoulderforward-5)%360;
		}
		else if(W.T.lshoulderforward<nextState.lshoulderforward){
			W.T.lshoulderforward=(W.T.lshoulderforward+5)%360;
		}}
		if(abs(W.T.rshouldercurve-nextState.rshouldercurve)>=3){
		if(W.T.rshouldercurve>nextState.rshouldercurve){
			W.T.rshouldercurve=(W.T.rshouldercurve-5)%360;
		}
		else if(W.T.rshouldercurve<nextState.rshouldercurve){
			W.T.rshouldercurve=(W.T.rshouldercurve+5)%360;
		}}
		if(abs(W.T.lshouldercurve-nextState.lshouldercurve)>=3){
		if(W.T.lshouldercurve>nextState.lshouldercurve){
			W.T.lshouldercurve=(W.T.lshouldercurve-5)%360;
		}
		else if(W.T.lshouldercurve<nextState.lshouldercurve){
			W.T.lshouldercurve=(W.T.lshouldercurve+5)%360;
		}}
		if(abs(W.T.down-nextState.down)>=0.06){
		if(W.T.down>nextState.down)
		{
			W.T.down=W.T.down-0.1;
		}else if(W.T.down<nextState.down)
		{
			W.T.down=W.T.down+0.1;
		}}
		if(abs(W.T.rlbforward-nextState.rlbforward)>=3){
		if(W.T.rlbforward>nextState.rlbforward){
			W.T.rlbforward=(W.T.rlbforward-5)%360;
		}
		else if(W.T.rlbforward<nextState.rlbforward){
			W.T.rlbforward=(W.T.rlbforward+5)%360;
		}}
		if(abs(W.T.llbforward-nextState.llbforward)>=3){
		if(W.T.llbforward>nextState.llbforward){
			W.T.llbforward=(W.T.llbforward-5)%360;
		}
		else if(W.T.llbforward<nextState.llbforward){
			W.T.llbforward=(W.T.llbforward+5)%360;
		}}
		if(abs(W.T.rltside-nextState.rltside)>=3){
		if(W.T.rltside>nextState.rltside){
			W.T.rltside=(W.T.rltside-5)%360;
		}
		else if(W.T.rltside<nextState.rltside){
			W.T.rltside=(W.T.rltside+5)%360;
		}}
		if(abs(W.T.lltside-nextState.lltside)>=3){
		if(W.T.lltside>nextState.lltside){
			W.T.lltside=(W.T.lltside-5)%360;
		}
		else if(W.T.lltside<nextState.lltside){
			W.T.lltside=(W.T.lltside+5)%360;
		}}
		if(abs(W.T.rltforward-nextState.rltforward)>=3){
		if(W.T.rltforward>nextState.rltforward){
			W.T.rltforward=(W.T.rltforward-5)%360;
		}
		else if(W.T.rltforward<nextState.rltforward){
			W.T.rltforward=(W.T.rltforward+5)%360;
		}
		}
		if(abs(W.T.lltforward-nextState.lltforward)>=3){
		if(W.T.lltforward>nextState.lltforward){
			W.T.lltforward=(W.T.lltforward-5)%360;
		}
		else if(W.T.lltforward<nextState.lltforward){
			W.T.lltforward=(W.T.lltforward+5)%360;
		}}
		if(abs(W.T.rltcurve-nextState.rltcurve)>=3){
		if(W.T.rltcurve>nextState.rltcurve){
			W.T.rltcurve=(W.T.rltcurve-5)%360;
		}
		else if(W.T.rltcurve<nextState.rltcurve){
			W.T.rltcurve=(W.T.rltcurve+5)%360;
		}}
		if(abs(W.T.lltcurve-nextState.lltcurve)>=3){
		if(W.T.lltcurve>nextState.lltcurve){
			W.T.lltcurve=(W.T.lltcurve-5)%360;
		}
		else if(W.T.lltcurve<nextState.lltcurve){
			W.T.lltcurve=(W.T.lltcurve+5)%360;
		}
		}
	if(abs(W.T.vehicleback-nextState.vehicleback)>=3){
		if(W.T.vehicleback>nextState.vehicleback){
			W.T.vehicleback=(W.T.vehicleback-5)%360;
		}
		else if(W.T.vehicleback<nextState.vehicleback){
			W.T.vehicleback=(W.T.vehicleback+5)%360;
		}}
		if(abs(W.T.rftyreshift-nextState.rftyreshift)>=0.03){
		if(W.T.rftyreshift>nextState.rftyreshift)
		{
			W.T.rftyreshift=W.T.rftyreshift-0.05;
		}
		else if(W.T.rftyreshift<nextState.rftyreshift)
		{
			W.T.rftyreshift=W.T.rftyreshift+0.05;
		}
		}
		if(abs(W.T.lftyreshift-nextState.lftyreshift)>=0.03){
		if(W.T.lftyreshift<nextState.lftyreshift)
		{
			W.T.lftyreshift=W.T.lftyreshift+0.05;
		}
		else if(W.T.lftyreshift>nextState.lftyreshift)
		{
			W.T.lftyreshift=W.T.lftyreshift-0.05;
		}}
		if(abs(W.T.fullz-nextState.fullz)>=3){
		if(W.T.fullz>nextState.fullz){

			W.T.fullz=(W.T.fullz-5)%360;
		} 
		else if(W.T.fullz<nextState.fullz){
			W.T.fullz=(W.T.fullz+5)%360;
		}}
		if(abs(W.T.fullx-nextState.fullx)>=3){
		if(W.T.fullx>nextState.fullx){

			W.T.fullx=(W.T.fullx-5)%360;
		}
		else if(W.T.fullx<nextState.fullx){
			W.T.fullx=(W.T.fullx+5)%360;
		}}
		if(abs(W.T.fully-nextState.fully)>=3){
		if(W.T.fully>nextState.fully){
			W.T.fully=(W.T.fully-5)%360;
		}
		else if(W.T.fully<nextState.fully){
			W.T.fully=(W.T.fully+5)%360;
		}
		}
		if(abs(W.T.fronttyretrans-nextState.fronttyretrans)>=0.06){
		if(W.T.fronttyretrans>nextState.fronttyretrans)
		{
			W.T.fronttyretrans=W.T.fronttyretrans-0.1;
		}
		else if(W.T.fronttyretrans<nextState.fronttyretrans)
		{
			W.T.fronttyretrans=W.T.fronttyretrans+0.1;
		}}
		if(abs(W.T.backtyretrans-nextState.backtyretrans)>=0.06){
		if(W.T.backtyretrans>nextState.backtyretrans)
		{
			W.T.backtyretrans=W.T.backtyretrans-0.1;
		}
		else if(W.T.backtyretrans<nextState.backtyretrans)
		{
			W.T.backtyretrans=W.T.backtyretrans+0.1;
		}}
		if(abs(W.T.carback-nextState.carback)>=3){
		if(W.T.carback>nextState.carback){
			W.T.carback=(W.T.carback-5)%360;
		}
		else if(W.T.carback<nextState.carback){
			W.T.carback=(W.T.carback+5)%360;
		}}
		if(abs(W.T.rfootrot-nextState.rfootrot)>=3){
		if(W.T.rfootrot>nextState.rfootrot){
			W.T.rfootrot=(W.T.rfootrot-5)%360;
		}
		else if(W.T.rfootrot<nextState.rfootrot){
			W.T.rfootrot=(W.T.rfootrot+5)%360;
		}
		}
		if(abs(W.T.lfootrot-nextState.lfootrot)>=3){
		if(W.T.lfootrot>nextState.lfootrot){
			W.T.lfootrot=(W.T.lfootrot-5)%360;
		}
		else if(W.T.lfootrot<nextState.lfootrot){
			W.T.lfootrot=(W.T.lfootrot+5)%360;
		}
		}
		if(abs(W.T.carfront-nextState.carfront)>=0.06){
		if(W.T.carfront>nextState.carfront)
		{
			W.T.carfront=W.T.carfront-0.1;
		}
		else if(W.T.carfront<nextState.carfront)
		{
			W.T.carfront=W.T.carfront+0.1;
		}
}
		if(abs(W.T.carfrontshift-nextState.carfrontshift)>=0.06){
		if(W.T.carfrontshift<nextState.carfrontshift)
		{
			W.T.carfrontshift=W.T.carfrontshift+0.1;
		}
		else if(W.T.carfrontshift>nextState.carfrontshift)
		{
			W.T.carfrontshift=W.T.carfrontshift-0.1;
		}

		}
		if(abs(W.T.carfrontinsert-nextState.carfrontinsert)>=0.06){
		if(W.T.carfrontinsert>nextState.carfrontinsert)
		{
			W.T.carfrontinsert=W.T.carfrontinsert-0.1;
		}
		else if(W.T.carfrontinsert<nextState.carfrontinsert)
		{
			W.T.carfrontinsert=W.T.carfrontinsert+0.1;
		}
		}
		if(abs(W.T.car_x-nextState.car_x)>=0.06){
			if(W.T.car_x>nextState.car_x)
		{
			W.T.car_x=W.T.car_x-0.1;

				W.T.wheelrot=(W.T.wheelrot-3)%360;
		}
			else if(W.T.car_x<nextState.car_x)
			{
				W.T.car_x=W.T.car_x+0.1;

				W.T.wheelrot=(W.T.wheelrot+3)%360;
			}
		}
		if(abs(W.T.car_y-nextState.car_y)>=0.06){
			if(W.T.car_y>nextState.car_y)
			{
				W.T.car_y=W.T.car_y-0.1;
			}
			else if(W.T.car_x<nextState.car_y)
			{
				W.T.car_y=W.T.car_y+0.1;
			}
		}
		if(abs(W.T.car_z-nextState.car_z)>=0.06){
			if(W.T.car_z>nextState.car_z)
			{
				W.T.car_z=W.T.car_z-0.1;
			}
			else if(W.T.car_z<nextState.car_z)
			{
				W.T.car_z=W.T.car_z+0.1;
			}
		}
W.T.wheelturn=nextState.wheelturn;


drawScene();
	}


}
void Animation::playBack(){
	extern World W;
	ifstream inputfile;
	inputfile.open("keyframes.txt");
	string next;
	Transformer nextT;

	W.T.camFlag = false;
	W.T.cam2Flag = false;
	W.T.hdLights = false;
	W.T.hdL1 = Light(GL_LIGHT3, 0,0,0, true);
	W.T.hdL2 = Light(GL_LIGHT4, 0,0,0, true);

	W.T.hd1=0;
	W.T.hd2=0;
	W.T.light1=0;
	W.T.light2=0;
	W.T.flag = 0;

	W.T.fullx=0; W.T.fully=0; W.T.fullz=0;
	W.T.bend=0;
	W.T.headside=0; W.T.headforward=0; W.T.headcurve=0;

	W.T.rshoulderside=-135; W.T.rshoulderforward=0; W.T.rshouldercurve=0; W.T.relbow=90; W.T.rfootrot=0.0; 
	W.T.lshoulderside=-45; W.T.lshoulderforward=0; W.T.lshouldercurve=0; W.T.lelbow=-90; W.T.lfootrot=0.0;

	W.T.rltside=-90; W.T.rltforward=0; W.T.rltcurve=0; W.T.rlbforward=0;
	W.T.lltside=-90; W.T.lltforward=0; W.T.lltcurve=0; W.T.llbforward=0;

	W.T.move=0.0; W.T.backtyretrans=0.0; W.T.fronttyretrans=0.0;
	W.T.lftyreshift=0.0; W.T.rftyreshift=0.0;
	W.T.vehicleback=0; W.T.carback=0; W.T.down=0.0;

	W.T.carfront=0.0; W.T.carfrontshift=0.0; W.T.carfrontinsert=0.0;

	W.T.car_x=0.0;
	W.T.car_y=-5.0;
	W.T.car_z=0.0;
	W.T.wheelrot=0;
	W.T.wheelturn=0;
	drawScene();
	while (getline( inputfile, next ))
	{
		nextT= setVector(next);
		interPolate(nextT);
	}

}

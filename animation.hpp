#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "world.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Animation{
public:
World setVector(string s);
string getVector(World);
void capture_frame(unsigned int);
void drawScene();
void playBack();
void interPolate(World);
void record();
};

#endif

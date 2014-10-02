#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <stdio.h>

#include "transformer.hpp"


void display();
void drawCube();
void drawSphere(GLint,GLint);
void drawCircle(float,int);
void drawCylinder(float,float,GLint,GLint);
void readTextures();

#endif

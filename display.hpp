#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <stdio.h>

#include "transformer.hpp"


void display();
void drawCube(GLuint T0=0,GLuint T1=0,GLuint T2=0,GLuint T3=0,GLuint T4=0,GLuint T5=0);
void drawSphere(GLint,GLint);
void drawCircle(float,int,GLuint Tex = 0);
void drawCylinder(float,float,GLint,GLint);
void readTextures();

#endif

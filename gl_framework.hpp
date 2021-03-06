#ifndef _GL_FRAMEWORK_HPP_
#define _GL_FRAMEWORK_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "world.hpp"
#include <iostream>
#include "animation.hpp"

void initGL(void);

void error_callback(int, const char*);

void framebuffer_size_callback(GLFWwindow*, int, int);

void key_callback(GLFWwindow*, int, int, int, int);

#endif

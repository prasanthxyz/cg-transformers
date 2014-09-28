#include "gl_framework.h"

int win_width;
int win_height;

void initGL(void)
{
   glClearColor(0, 0, 0, 1);
   glClearDepth(1);
   glShadeModel(GL_SMOOTH);
}

void error_callback(int error, const char* description)
{
   std::cerr << description << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
   if (height == 0)
   {
	  height = 1;
   }
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glViewport(0, 0, width, height);

   double aspect;
   if(width > height)
   {
	  aspect = (double)width/(double)height;
	  glOrtho(-aspect, aspect, -1, 1, -1, 1);
   }
   else
   {
	  aspect = (double)height/(double)width;
	  glOrtho(-1, 1, -aspect, aspect, -1, 1);
   }
   win_width = width;
   win_height = height;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
   if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
   glfwSetWindowShouldClose(window, GL_TRUE);
}



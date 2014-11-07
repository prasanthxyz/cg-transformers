#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "drawing.hpp"
#include "texture.hpp"
#include "transformer.hpp"
#include "light.hpp"

class World
{
    public:
        Transformer T;
        Light L1;
        Light L2;
	int light1,light2;
	bool capture;
	GLfloat ball_x,ball_y,ball_z;
        World();
        void drawOutCube();
        void display();
	void drawBall();
};


#endif

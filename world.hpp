#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "drawing.hpp"
#include "texture.hpp"
#include "transformer.hpp"

class World
{
    public:
        Transformer T;
        Texture tex;

        World();
        void drawOutCube();
        void display();
};

#endif

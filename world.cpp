#include "world.hpp"

World::World()
{
    tex.loadTextures();
}

void World::drawOutCube()
{
    Drawing D;
    glPushMatrix();
    glScalef(20,20,20);
    D.drawCube(tex.textures[tex.WTOP],tex.textures[tex.WBOTTOM], tex.textures[tex.WFAR],tex.textures[tex.WNEAR], tex.textures[tex.WLEFT],tex.textures[tex.WRIGHT]);
    glPopMatrix();
}

void World::display()
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
//    GLFWwindow* window =glfwGetCurrentContext();
    drawOutCube();
//    T.movement(window);
    T.display();

}

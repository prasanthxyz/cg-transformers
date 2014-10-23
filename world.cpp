#include "world.hpp"

World::World()
{
    tex.loadTextures();
    L1 = Light(GL_LIGHT1, 5,5,5);
    L2 = Light(GL_LIGHT2, -5,5,5);
}

void World::drawOutCube()
{
    Drawing D;
    glPushMatrix();
    glScalef(50,20,35);
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

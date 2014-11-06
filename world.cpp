#include "world.hpp"

World::World()
{
    tex.loadTextures();
    light1=1;
    light2=1;
    capture=false;
    ball_x=-8.0;
    ball_y=-9.0;
    ball_z=-10.0;
    L1 = Light(GL_LIGHT1, 5,5,5);
    L2 = Light(GL_LIGHT2, -5,-5,-5);
}

void World::drawOutCube()
{
    Drawing D;
    glPushMatrix();
    //glScalef(50,20,35);
    glScalef(70,70,70);
    D.drawCube(tex.textures[tex.WTOP],tex.textures[tex.WBOTTOM], tex.textures[tex.WFAR],tex.textures[tex.WNEAR], tex.textures[tex.WLEFT],tex.textures[tex.WRIGHT]);
    //D.drawSphere(36,36,false);
    //D.drawCylinder(36,36,false);
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
    drawBall();

}

void World::drawBall()
{
    Drawing D;
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(ball_x,ball_y,ball_z);
    D.drawSphere(36,36,true);
    glPopMatrix();
}

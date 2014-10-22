#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "world.hpp"
#include "transformer.hpp"
#include "gl_framework.hpp"
#include "texture.hpp"

World W;
//Transformer T;

void displayWorld()
{

   W.display();
}
void movem(GLFWwindow* window)
{
double result;
     int angle=0;
     if(glfwGetKey(window, GLFW_KEY_UP)==GLFW_PRESS)
     {
        angle=5;
        W.T.wheelturn=0;
        result=W.T.fully*(M_PI/180);
        W.T.car_x=W.T.car_x-0.1*cos(result);
        W.T.car_z=W.T.car_z-0.1*sin(result);
        W.T.wheelrot=(W.T.wheelrot+3)%360;
     }

     else if(glfwGetKey(window, GLFW_KEY_DOWN)==GLFW_PRESS)
     {
        angle=-5;
        W.T.wheelturn=0;
        result=W.T.fully*(M_PI/180);
        W.T.car_x=W.T.car_x+0.1*cos(result);
        W.T.car_z=W.T.car_z+0.1*sin(result);
        W.T.wheelrot=(W.T.wheelrot-3)%360;

     }
     if(glfwGetKey(window, GLFW_KEY_RIGHT)==GLFW_PRESS)
     {
        W.T.wheelturn=-30;
        if(angle){
        //   fully=fully+5;
        W.T.fully=(W.T.fully-angle)%360;
        if(W.T.fully<0)
        W.T.fully=360+W.T.fully;
//        cout <<W.T.fully<< " ";
     }

     }

     else if(glfwGetKey(window, GLFW_KEY_LEFT)==GLFW_PRESS)
     {
        W.T.wheelturn=30;
        if(angle){
           W.T.fully=(W.T.fully+angle)%360;
        if(W.T.fully<0)
        W.T.fully=W.T.fully+360;
     }
     }
     else
     {
        W.T.wheelturn=0;
     }
     }

int main (int argc, char *argv[]) 
{
    //! The pointer to the GLFW window
    GLFWwindow* window;

    //! Setting up the GLFW Error callback
    //if not working, make namespace
    glfwSetErrorCallback(error_callback);

    //! Initialize GLFW
    if (!glfwInit())
        return -1;

    int win_width=512;
    int win_height=512;

    //! Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(win_width, win_height, "Transformer", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    //! Make the window's context current 
    glfwMakeContextCurrent(window);

    //Keyboard Callback
    //OurOwn: set up key_callback
    glfwSetKeyCallback(window, key_callback);
    //Framebuffer resize callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwGetFramebufferSize(window, &win_width, &win_height);
    framebuffer_size_callback(window, win_width, win_height);
    //Initialize GL state
    initGL();
   
    //Texture tex;
    //tex.loadTextures();

    //T = Transformer();
    W = World();

    // Loop until the user closes the window
    glEnable(GL_TEXTURE_2D);
    while (glfwWindowShouldClose(window) == 0)
    {

        // Render here
        //renderGL();
        //movem(window);
        displayWorld();


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "transformer.hpp"
#include "gl_framework.hpp"
#include "display.hpp"

using namespace std;

Transformer T;

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
    T = Transformer();

    // Loop until the user closes the window
    glEnable(GL_TEXTURE_2D);
    while (glfwWindowShouldClose(window) == 0)
    {

        // Render here
        //renderGL();
        display();


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}


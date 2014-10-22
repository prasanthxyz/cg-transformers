#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "world.hpp"
#include "transformer.hpp"
#include "gl_framework.hpp"
#include "texture.hpp"

World W;

void displayWorld()
{
   W.display();
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
        displayWorld();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }
    glfwDestroyWindow(glfwGetCurrentContext());
    glfwTerminate();

    return 0;
}


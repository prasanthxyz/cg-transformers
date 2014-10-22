 #include "gl_framework.hpp"
#include <GL/glu.h>
void initGL(void)
{
    glClearColor(0, 0, 0, 1);
    glClearDepth(1);
}

void error_callback(int error, const char* description)
{
    std::cerr << description << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    const GLdouble pi = 3.14159;
    GLdouble fW, fH;
    double aspect;


    if (height == 0)
    {
        height = 1;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    glViewport(0, 0, width, height);
    if(width > height)
    {

        aspect = (double)width/(double)height;
    }
    else
    {

       aspect = (double)height/(double)width;
    }
    fH = tan(90.0 / 360 * pi ) * 1.0;
    fW = fH * aspect;
    //glFrustum( -fW, fW, -fH, fH, 1.25, 20.0 );
    gluPerspective(100, aspect, .1,5000);
    gluLookAt(0,0,3,0,0,0,0,1,0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -6.0);

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
   extern World W;
 double result;
     int angle=0;
     if(glfwGetKey(window, GLFW_KEY_UP))
     {
        angle=5;
        W.T.wheelturn=0;
        result=W.T.fully*(M_PI/180);
        W.T.car_x=W.T.car_x+0.1*cos(result);
        W.T.car_z=W.T.car_z-0.1*sin(result);
        W.T.wheelrot=(W.T.wheelrot+3)%360;
     }

     else if(glfwGetKey(window, GLFW_KEY_DOWN))
     {
        angle=-5;
        W.T.wheelturn=0;
        result=W.T.fully*(M_PI/180);
        W.T.car_x=W.T.car_x-0.1*cos(result);
        W.T.car_z=W.T.car_z+0.1*sin(result);
        W.T.wheelrot=(W.T.wheelrot-3)%360;

     }
     if(glfwGetKey(window, GLFW_KEY_RIGHT))
     {
        W.T.wheelturn=-30;
        if(angle)
        W.T.fully=(W.T.fully-angle)%360;
     }

     else if(glfwGetKey(window, GLFW_KEY_LEFT))
     {
        W.T.wheelturn=30;
        if(angle)
           W.T.fully=(W.T.fully+angle)%360;
     }
     else
     {
        W.T.wheelturn=0;
     }
    switch(key)
    {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GL_TRUE);
            break;
        case GLFW_KEY_V:
            if(mods==GLFW_MOD_SHIFT)
                W.T.rotateX(5);
            else 
                W.T.rotateX(-5);

            break;
        case GLFW_KEY_B:
            if(mods==GLFW_MOD_SHIFT)
                W.T.rotateY(5);
            else
                W.T.rotateY(-5);
            break;
        case GLFW_KEY_N:
            if(mods==GLFW_MOD_SHIFT)
                W.T.rotateZ(5);
            else
                W.T.rotateZ(-5);
            break;
        case GLFW_KEY_Z:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.headside<=45)
                    W.T.tiltHeadSide(5);}
                else{
                    if(W.T.headside>=-45)
                        W.T.tiltHeadSide(-5);
                }
            }break;
        case GLFW_KEY_X:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.headforward<45)
                    W.T.tiltHeadFB(5);
                }
                else{
                    if(W.T.headforward>=-10)
                        W.T.tiltHeadFB(-5);
                }
            }break;
        case GLFW_KEY_C:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.headcurve<=30)
                    W.T.turnHead(5);
                }else{
                    if(W.T.headcurve>=-30)
                        W.T.turnHead(-5);
                }
            } break;
        case GLFW_KEY_T:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {
                    if(W.T.bend<=180)
                        W.T.bendForward(5);
                }
                else
                {
                    if(W.T.bend>=-90)
                        W.T.bendBack(-5);
                }
            }  break;
        case GLFW_KEY_A:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                    W.T.rShoulderSide(5);
                else
                    W.T.rShoulderSide(-5);
            }  break;
        case GLFW_KEY_S:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                    W.T.rShoulderFB(5);
                else
                    W.T.rShoulderFB(-5);
            } break;
        case GLFW_KEY_D:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                    W.T.rShoulderCurve(5);
                else
                    W.T.rShoulderCurve(-5);
            } break;
        case GLFW_KEY_F:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                    W.T.rElbowBend(5);
                else
                    W.T.rElbowBend(-5);
            } break;
        case GLFW_KEY_Q:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                    W.T.lShoulderSide(5);
                else
                    W.T.lShoulderSide(-5);
            } break;
        case GLFW_KEY_W:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                    W.T.lShoulderFB(5);
                else
                    W.T.lShoulderFB(-5);
            } break;                                            
        case GLFW_KEY_E:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                    W.T.lShoulderCurve(5);
                else
                    W.T.lShoulderCurve(-5);
            } break;
        case GLFW_KEY_R:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                    W.T.lElbowBend(5);
                else
                    W.T.lElbowBend(-5);
            } break;
        case GLFW_KEY_H:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.rltside<=0)
                    W.T.rLegSide(5);
                }else
                {if(W.T.rltside>=-180)
                    W.T.rLegSide(-5);
                }
            } break;
        case GLFW_KEY_J:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.rltforward<=90)
                    W.T.rLegFB(5);
                }else{if(W.T.rltforward>=-180)
                    W.T.rLegFB(-5);}
            }  break;
        case GLFW_KEY_K:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.rltcurve<=90)
                    W.T.rLegCurve(5);
                }else{if(W.T.rltcurve>=-90)
                    W.T.rLegCurve(-5);}
            } break;
        case GLFW_KEY_L:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.rlbforward<=180)
                    W.T.rCalfFB(5);
                }else{if(W.T.rlbforward>=0)
                    W.T.rCalfFB(-5);}
            } break;
        case GLFW_KEY_U:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.lltside<=0)
                    W.T.lLegSide(5);
                }else{if(W.T.lltside>=-180)
                    W.T.lLegSide(-5);
                }} break;
        case GLFW_KEY_I:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.lltforward<=90)
                    W.T.lLegFB(5);
                }else{if(W.T.lltforward>=-180)
                    W.T.lLegFB(-5);
                }} break;
        case GLFW_KEY_O:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.lltcurve<=90)
                    W.T.lLegCurve(5);
                }else{if(W.T.lltcurve>=-90)
                    W.T.lLegCurve(-5);
                }
            }break;
        case GLFW_KEY_P:
            if(W.T.flag==0){
                if(mods==GLFW_MOD_SHIFT)
                {if(W.T.llbforward<=180)
                    W.T.lCalfFB(5);
                }else{if(W.T.llbforward>=0)
                    W.T.lCalfFB(-5);}
            }
            break;
        case GLFW_KEY_G:
            if(action==GLFW_PRESS)
            {
                if(W.T.flag==0)
                    W.T.tocar();
                else
                    W.T.tohuman();
            }
            break;
        case GLFW_KEY_1:
            W.T.camFlag = false;
            glLoadIdentity();
            gluLookAt(0,5,5, 0,0,0, 0,1,0);
            break;
        case GLFW_KEY_2:
            W.T.camFlag = true;
            break;

        default:
            break;
    }
}


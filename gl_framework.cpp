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
    glFrustum( -fW, fW, -fH, fH, 1.25, 20.0 );
    gluLookAt(0,0,2,0,0,0,0,1,0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.8, -5.0);

}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
   extern Transformer T;
    switch(key)
    {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GL_TRUE);
            break;
            case GLFW_KEY_V:
            if(mods==GLFW_MOD_SHIFT)
                T.rotateX(5);
            else 
            T.rotateX(-5);
         
            break;
        case GLFW_KEY_B:
            if(mods==GLFW_MOD_SHIFT)
                T.rotateY(5);
            else
            T.rotateY(-5);
            break;
        case GLFW_KEY_N:
            if(mods==GLFW_MOD_SHIFT)
                T.rotateZ(5);
            else
                T.rotateZ(-5);
             break;
        case GLFW_KEY_Z:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.headside<=45)
                T.tiltHeadSide(5);}
            else{
                if(T.headside>=-45)
                    T.tiltHeadSide(-5);
            }
         }break;
        case GLFW_KEY_X:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.headforward<45)
                T.tiltHeadFB(5);
            }
            else{
                if(T.headforward>=-10)
                    T.tiltHeadFB(-5);
            }
         }break;
        case GLFW_KEY_C:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.headcurve<=30)
                T.turnHead(5);
            }else{
                if(T.headcurve>=-30)
                    T.turnHead(-5);
            }
         } break;
        case GLFW_KEY_T:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {
                if(T.bend<=180)
                    T.bendForward(5);
            }
            else
            {
                if(T.bend>=-90)
                    T.bendBack(-5);
            }
         }  break;
        case GLFW_KEY_A:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
                T.rShoulderSide(5);
            else
                T.rShoulderSide(-5);
             }  break;
        case GLFW_KEY_S:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
                T.rShoulderFB(5);
            else
                T.rShoulderFB(-5);
             } break;
        case GLFW_KEY_D:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
                T.rShoulderCurve(5);
            else
                T.rShoulderCurve(-5);
             } break;
        case GLFW_KEY_F:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
                T.rElbowBend(5);
            else
                T.rElbowBend(-5);
             } break;
        case GLFW_KEY_Q:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
                T.lShoulderSide(5);
            else
                T.lShoulderSide(-5);
             } break;
        case GLFW_KEY_W:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
                T.lShoulderFB(5);
            else
                T.lShoulderFB(-5);
             } break;                                            
        case GLFW_KEY_E:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
                T.lShoulderCurve(5);
            else
                T.lShoulderCurve(-5);
             } break;
        case GLFW_KEY_R:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
                T.lElbowBend(5);
            else
                T.lElbowBend(-5);
             } break;
        case GLFW_KEY_H:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.rltside<=0)
                T.rLegSide(5);
            }else
            {if(T.rltside>=-180)
                T.rLegSide(-5);
            }
         } break;
        case GLFW_KEY_J:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.rltforward<=90)
                T.rLegFB(5);
            }else{if(T.rltforward>=-180)
                T.rLegFB(-5);}
             }  break;
        case GLFW_KEY_K:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.rltcurve<=90)
                T.rLegCurve(5);
            }else{if(T.rltcurve>=-90)
                T.rLegCurve(-5);}
             } break;
        case GLFW_KEY_L:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.rlbforward<=180)
                T.rCalfFB(5);
            }else{if(T.rlbforward>=0)
                T.rCalfFB(-5);}
             } break;
        case GLFW_KEY_U:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.lltside<=0)
                T.lLegSide(5);
            }else{if(T.lltside>=-180)
                T.lLegSide(-5);
             }} break;
        case GLFW_KEY_I:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.lltforward<=90)
                T.lLegFB(5);
            }else{if(T.lltforward>=-180)
                T.lLegFB(-5);
             }} break;
        case GLFW_KEY_O:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.lltcurve<=90)
                T.lLegCurve(5);
            }else{if(T.lltcurve>=-90)
                T.lLegCurve(-5);
             }
          }break;
        case GLFW_KEY_P:
            if(T.flag==0){
            if(mods==GLFW_MOD_SHIFT)
            {if(T.llbforward<=180)
                T.lCalfFB(5);
            }else{if(T.llbforward>=0)
            T.lCalfFB(-5);}
         }
         break;
         case GLFW_KEY_G:
         if(action==GLFW_PRESS)
         {
        if(T.flag==0)
        T.tocar();
        else
        T.tohuman();
     }
        break;
        case GLFW_KEY_UP:
        if(T.flag==1){
           if(glfwGetKey(window, GLFW_KEY_RIGHT))
        {
           T.wheelturn=-30;
           T.carMove(-0.1,5,-5);

        }

        else if(glfwGetKey(window, GLFW_KEY_LEFT))
        {
           T.wheelturn=30;
           T.carMove(-0.1,5,5);
        }
        else{
            T.wheelturn=0;
            T.carMove(-0.1,5,0);
         }
     }
        break;
        case GLFW_KEY_DOWN:
if(T.flag==1){
           if(glfwGetKey(window, GLFW_KEY_RIGHT))
        {
           T.wheelturn=-30;
           T.carMove(0.1,-5,5);

        }

        else if(glfwGetKey(window, GLFW_KEY_LEFT))
        {
           T.wheelturn=30;
           T.carMove(0.1,-5,-5);
        }
        else {
            T.wheelturn=0;
            T.carMove(0.1,-5,0);
         }
      }
        break;
        case GLFW_KEY_LEFT:
        if(T.flag==1){
           T.wheelturn=30;
        if(glfwGetKey(window, GLFW_KEY_UP))
        {
           T.carMove(-0.1,5,5);

        }
        else if(glfwGetKey(window, GLFW_KEY_DOWN))
        {
           T.carMove(0.1,-5,-5);

        }
        else if(action==GLFW_RELEASE){
           T.wheelturn=0;
         }
     }
  break; 
        case GLFW_KEY_RIGHT:
        if(T.flag==1){

           T.wheelturn=-30;
        if(glfwGetKey(window, GLFW_KEY_UP))
        {
           T.carMove(-0.1,5,-5);

        }
        else if(glfwGetKey(window, GLFW_KEY_DOWN))
        {
           T.carMove(0.1,-5,5);

        }
        else if(action == GLFW_RELEASE){
           T.wheelturn=0;
         }
     }
 
        break;
     
        default:
        break;
     }
}


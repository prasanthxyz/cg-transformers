#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "transformer.h"

using namespace std;

Transformer T;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   T.draw_left_arm();
   T.draw_left_elbow();
   T.draw_left_forearm();
   T.draw_right_arm();
   T.draw_right_elbow();
   T.draw_right_forearm();
   T.draw_hip();
   T.draw_torso();
   T.draw_head();
   T.draw_eyes();
   T.draw_neck();
   T.draw_left_thigh();
   T.draw_left_knee();
   T.draw_left_calf();
   T.draw_left_foot();

   T.draw_right_thigh();
   T.draw_right_knee();
   T.draw_right_calf();
   T.draw_right_foot();

}


void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   //hip

   glPushMatrix(); //identity matrix pushed
   glColor3f(0.96,0.8,0.69);
   glRotatef ((GLfloat) T.fullz, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.fullx,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.fully, 0.0, 1.0, 0.0);
   glPushMatrix(); //rotations for EVERYTHING pushed

   glCallList(T.hip);
   glPopMatrix(); //ID; have rotations
   
   //torso

   glPushMatrix(); //univ rotations

   glTranslatef(0.0,-1.1,0.0);
   glRotatef ((GLfloat) T.bend, 1.0, 0.0, 0.0);
   glTranslatef(0.0,1.1,0.0);
  
   glPushMatrix(); //univ rotations, bend
   glCallList(T.torso);
   glPopMatrix(); //univ rotations; have bend
 
   //head
 
   glPushMatrix(); //univ rotations, bend
   glTranslatef (0.0, 1.9, 0.0);
   glRotatef ((GLfloat) T.headside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.headforward,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.headcurve, 0.0, 1.0, 0.0);
   glCallList(T.head);
   glColor3f(0,0,0);
   glPushMatrix(); //univ rotations, bend, head rotations
   glCallList(T.eyes);
   glPopMatrix(); //univ rotations, bend; have head rotations
   glColor3f(0.96,0.8,0.69);  
   glPopMatrix(); //univ rotations; have bend
   
   //neck
   
   glPushMatrix(); //univ rotations, bend
   glCallList(T.neck);
   glPopMatrix(); //univ rotations; have bend
   
   //righthand
   
   glPushMatrix(); //univ rotations, bend
   glTranslatef (-1.0, 0.9, 0.0);
   glRotatef ((GLfloat) T.rshoulderside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.rshoulderforward,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.rshouldercurve ,0.0, 1.0, 0.0);

   glPushMatrix(); //univ rotations, bend, rshoulder
   glCallList(T.right_arm);
   glPopMatrix(); //univ rotations, bend; have rshoulder
   glCallList(T.right_elbow);
   glRotatef ((GLfloat) T.relbow, 0.0, 0.0, 1.0);
   glPushMatrix(); //univ rotations, bend, rshoulder+relbow
   glCallList(T.right_forearm);
   glPopMatrix(); //univ rotations, bend; has rshoulder+relbow

   glPopMatrix(); //univ rotations; has bend

   //lefthand
   
   glPushMatrix(); //univ rotations, bend
   glTranslatef (1.0, 0.9, 0.0);
   glRotatef ((GLfloat) T.lshoulderside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.lshoulderforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.lshouldercurve, 0.0, 1.0, 0.0);
   glPushMatrix(); //univ rotations, bend, lshoulder
   glCallList(T.left_arm);
   glPopMatrix(); //univ rotations, bend; has lshoulder
   glCallList(T.left_elbow);
   glRotatef ((GLfloat) T.lelbow, 0.0, 0.0, 1.0);
   glPushMatrix(); //univ rotations, bend, lshoulder+lelbow
   glCallList(T.left_forearm);
   glPopMatrix(); //univ rotations, bend; has lshoulder+lelbow

   glPopMatrix(); //univ rotations; has bend

   glPopMatrix(); //ID; has univ rotations

   //rightleg

   glPushMatrix(); //univ rotations
   glTranslatef (-0.58, -1.38, 0.0);
   glRotatef ((GLfloat) T.rltcurve, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) T.rltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.rltside, 0.0, 0.0, 1.0);
   glPushMatrix(); //univ rotations, right leg rots
   glCallList(T.right_thigh);
   glPopMatrix(); //univ rotations; has right leg rots
   glCallList(T.right_knee);
   glRotatef ((GLfloat) T.rlbforward, 0.0, 1.0, 0.0);
   glPushMatrix(); //univ rotations, rleg+rknee
   glCallList(T.right_calf);
   glPopMatrix(); //univ rotations; has rleg+rknee
   glPushMatrix(); //univ rotations, rleg+rknee
   glCallList(T.right_foot);
   glPopMatrix(); //univ rotations; has rleg+rknee

   glPopMatrix(); //ID; has univ rotations

   //leftleg   

   glPushMatrix(); //univ rotations
   glTranslatef (0.58, -1.38, 0.0);
   glRotatef ((GLfloat) T.lltcurve, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) T.lltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.lltside, 0.0, 0.0, 1.0);
   glPushMatrix(); //univ rotations, lleg
   glCallList(T.left_thigh);
   glPopMatrix(); //univ rotations; has lleg
   glCallList(T.left_knee);
   glRotatef ((GLfloat) T.llbforward, 0.0, 1.0, 0.0);
   glPushMatrix(); //univ rots,lleg+lknee
   glCallList(T.left_calf);
   glPopMatrix(); //univ rots; has lleg+lknee
   glPushMatrix(); //univ rots, lleg+lknee
   glCallList(T.left_foot);
   glPopMatrix(); //univ rots; has lleg+lknee
   glPopMatrix(); //ID; has univ rots
   glColor3f(1,0.5,0.5);

   glPopMatrix(); //empty

   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(90.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}
void timer(int value)
{
   if(T.fullx==0&&T.fully==0&&T.fullz==0&&T.bend==0&&T.headside==0&&T.headforward==0&&T.headcurve==0&&T.rshoulderside==-135&&T.rshoulderforward==0&&T.rshouldercurve==0&&T.relbow==90&&T.lshoulderside==-45&&T.lshoulderforward==0&&T.lshouldercurve==0&&T.lelbow==-90&&T.rltside==-90&&T.rltforward==0&&T.rltcurve==0&&T.rlbforward==0&&T.lltside==-90&&T.lltforward==0&&T.lltcurve==0&&T.llbforward==0)
   return;
   T.transform();
   glutPostRedisplay();
glutTimerFunc(100,timer,0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) 
   {
      case 'v':
      T.rotateX(5);
      break;
      case 'V':
      T.rotateX(-5);
      break;
      case 'b':
      T.rotateY(5);
      break;
      case 'B':
      T.rotateY(-5);
      break;
      case 'n':
      T.rotateZ(5);
      break;
      case 'N':
      T.rotateZ(-5);
      break;

      case 'z':
      if(T.headside<=45)
      T.tiltHeadSide(5);
      break;
      case 'Z':
      if(T.headside>=-45)
      T.tiltHeadSide(-5);
      break;
      case 'x':
      if(T.headforward<45)
      T.tiltHeadFB(5);
      break;
      case 'X':
      if(T.headforward>=-90)
      T.tiltHeadFB(-5);
      break;
      case 'c':
      if(T.headcurve<=90)
      T.turnHead(5);
      break;
      case 'C':
      if(T.headcurve>=-90)
      T.turnHead(-5);
      break;

      case 't':
      if(T.bend<=180)
      T.bendForward(5);
      break;
      case 'y':
      if(T.bend>=-90)
      T.bendBack(-5);
      break;

      case 'a':
      T.rShoulderSide(5);
      break;
      case 'A':
      T.rShoulderSide(-5);
      break;
      case 's':
      T.rShoulderFB(5);
      break;
      case 'S':
      T.rShoulderFB(-5);
      break;
      case 'd':
      T.rShoulderCurve(5);
      break;
      case 'D':
      T.rShoulderCurve(-5);
      break;
      case 'f':
      T.rElbowBend(5);
      break;
      case 'F':
      T.rElbowBend(-5);
      break;

      case 'q':
      T.lShoulderSide(5);
      break;
      case 'Q':
      T.lShoulderSide(-5);
      break;
      case 'w':
      T.lShoulderFB(5);
      break;              
      case 'W':
      T.lShoulderFB(-5);
      break;                                            
      case 'e':
      T.lShoulderCurve(5);
      break;
      case 'E':
      T.lShoulderCurve(-5);
      break;
      case 'r':
      T.lElbowBend(5);
      break;
      case 'R':
      T.lElbowBend(-5);
      break;

      case 'h':
      if(T.rltside<=0)
      T.rLegSide(5);
      break;
      case 'H':
      if(T.rltside>=-180)
      T.rLegSide(-5);
      break;
      case 'j':
      if(T.rltforward<=90)
      T.rLegFB(5);
      break;
      case 'J':
      if(T.rltforward>=-180)
      T.rLegFB(-5);
      break;
      case 'k':
      if(T.rltcurve<=90)
      T.rLegCurve(5);
      break;
      case 'K':
      if(T.rltcurve>=-90)
      T.rLegCurve(-5);
      break;
      case 'l':
      if(T.rlbforward<=180)
      T.rCalfFB(5);
      break;
      case 'L':
      if(T.rlbforward>=T.rltforward)
      T.rCalfFB(-5);
      break;

      case 'u':
      if(T.lltside<=0)
      T.lLegSide(5);
      break;
      case 'U':
      if(T.lltside>=-180)
      T.lLegSide(-5);
      break;
      case 'i':
      if(T.lltforward<=90)
      T.lLegFB(5);
      break;
      case 'I':
      if(T.lltforward>=-180)
      T.lLegFB(-5);
      break;
      case 'o':
      if(T.lltcurve<=90)
      T.lLegCurve(5);
      break;
      case 'O':
      if(T.lltcurve>=-90)
      T.lLegCurve(-5);
      break;
      case 'p':
      if(T.llbforward<=180)
      T.lCalfFB(5);
      break;
      case 'P':
      if(T.llbforward>=T.lltforward)
      T.lCalfFB(-5);
      break;

      case 'g':
    timer(0);
    break;

    case 27:
	 break;
    default:
    break;


   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
/*

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

  int win_width=500;
  int win_height=500;

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

  // Loop until the user closes the window
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
*/

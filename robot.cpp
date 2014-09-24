#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>

static int rshoulder = -45, relbow = 0,fullx=0,fully=0,fullz=0,headside=0,headforward=0,headcurve=0,lshoulder=-135,lelbow=0,lltside=-90,lltforward=0,rltside=-90,rltforward=0,llbforward=0,rlbforward=0;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
}
void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glColor3f(0.96,0.8,0.69);
   glRotatef ((GLfloat) fullz, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) fullx,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) fully, 0.0, 1.0, 0.0);
   glPushMatrix();
   glTranslatef(0.0,-1.1,0.0);
   glScalef(1.6,0.3,1.0);
   glutSolidCube(1.0);
   glPopMatrix();
   
   //head		 
   glPushMatrix();
   glTranslatef (0.0, 2.0, 0.0);
   glRotatef ((GLfloat) headside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) headforward,1.0, 0.0, 0.0);
   glRotatef ((GLfloat) headcurve, 0.0, 1.0, 0.0);

   glutSolidSphere(0.7,32,32);
   glColor3f(0,0,0);
   glPushMatrix();
   glTranslatef(-0.4,0.1,0.0);
   glutSolidSphere(0.15,32,32);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.4,0.1,0.0);
   glutSolidSphere(0.15,32,32);
   glPopMatrix();
   glColor3f(0.96,0.8,0.69);  
   glPopMatrix();
//neck
   glPushMatrix();
   glTranslatef (0.0, 1.4, 0.0);
   glPushMatrix();
   GLUquadricObj *neck;
   neck = gluNewQuadric();
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   gluCylinder(neck,0.35f,0.35f,0.3f,32,32);
   glPopMatrix();
   glPopMatrix();
//righthand
   glPushMatrix();
   glTranslatef (1.0, 0.9, 0.0);
   glRotatef ((GLfloat) rshoulder, 0.0, 0.0, 1.0);
   glPushMatrix();
   GLUquadricObj *rshoulderhand;
   rshoulderhand = gluNewQuadric();
   glutSolidSphere(0.2,32,32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f,1.0f, 0.0f);
   gluCylinder(rshoulderhand,0.2f,0.2f,1.2f,32,32);
   glPopMatrix();
   glTranslatef (1.3, 0.0, 0.0);
   glRotatef ((GLfloat) relbow, 0.0, 0.0, 1.0);
   glPushMatrix();
   GLUquadricObj *relbowhand;
   relbowhand = gluNewQuadric();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(relbowhand,0.2f,0.2f,1.5f,32,32);
   glPopMatrix();
   glPopMatrix();
//lefthand
   glPushMatrix();
   glTranslatef (-1.0, 0.9, 0.0);
   glRotatef ((GLfloat) lshoulder, 0.0, 0.0, 1.0);
   glPushMatrix();
   GLUquadricObj *lshoulderhand;
  lshoulderhand = gluNewQuadric();
   glutSolidSphere(0.2,32,32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(lshoulderhand,0.2f,0.2f,1.2f,32,32);
   glPopMatrix();
   glTranslatef (1.3, 0.0, 0.0);
   glRotatef ((GLfloat) lelbow, 0.0, 0.0, 1.0);
   glPushMatrix();
   GLUquadricObj *lelbowhand;
  lelbowhand = gluNewQuadric();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(lelbowhand,0.2f,0.2f,1.5f,32,32);
   glPopMatrix();
   glPopMatrix();
//body  
   glPushMatrix();
   glScalef(1.6,2.0,1.0);
   glutSolidCube(1.0);
   glPopMatrix();
//rightleg
   glPushMatrix();
   glTranslatef (0.58, -1.38, 0.0);
   glRotatef ((GLfloat) rltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) rltside, 0.0, 0.0, 1.0);
   glPushMatrix();
   GLUquadricObj *rtopleg;
  rtopleg = gluNewQuadric();
   glRotatef(90.0f, 0.0f,1.0f, 0.0f);
   gluCylinder(rtopleg,0.3f,0.3f,1.0f,32,32);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) rlbforward, 0.0, 1.0, 0.0);
   glPushMatrix();
   GLUquadricObj *rbottomleg;
   rbottomleg = gluNewQuadric();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(rbottomleg,0.3f,0.3f,1.2f,32,32);
   glPopMatrix();
   glPopMatrix();
//leftleg   
   glPushMatrix();
   glTranslatef (-0.58, -1.38, 0.0);
   glRotatef ((GLfloat) lltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) lltside, 0.0, 0.0, 1.0);
   glPushMatrix();
   GLUquadricObj *ltopleg;
  ltopleg = gluNewQuadric();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(ltopleg,0.3f,0.3f,1.0f,32,32);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) llbforward, 0.0, 1.0, 0.0);
   glPushMatrix();
   GLUquadricObj *lbottomleg;
  lbottomleg = gluNewQuadric();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(lbottomleg,0.3f,0.3f,1.2f,32,32);
   glPopMatrix();
   glPopMatrix();
   glPopMatrix();

   glutSwapBuffers();
}
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -6.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'v':
      fullx = (fullx + 5) % 360;
      glutPostRedisplay();
      break;
      case 'V':
     fullx = (fullx - 5) % 360;
      glutPostRedisplay();
      break;
      case 'b':
      fully = (fully + 5) % 360;
      glutPostRedisplay();break;
      case 'B':
      fully = (fully - 5) % 360;
      glutPostRedisplay();
      break;
      case 'n':
     fullz = (fullz + 5) % 360;
      glutPostRedisplay();
      break;
      case 'N':
      fullz = (fullz - 5) % 360;
      glutPostRedisplay();
      break;


      case 'z':
      headside = (headside + 5) % 360;
      glutPostRedisplay();
      break;
      case 'Z':
     headside = (headside - 5) % 360;
      glutPostRedisplay();
      break;
      case 'x':
      headforward = (headforward + 5) % 360;
      glutPostRedisplay();break;
      case 'X':
     headforward = (headforward - 5) % 360;
      glutPostRedisplay();
      break;
      case 'c':
      headcurve = (headcurve + 5) % 360;
      glutPostRedisplay();
      break;
      case 'C':
      headcurve = (headcurve - 5) % 360;
      glutPostRedisplay();
      break;

      case 's':
      rshoulder = (rshoulder + 5) % 360;
      glutPostRedisplay();
      break;
      case 'S':
      rshoulder = (rshoulder - 5) % 360;
      glutPostRedisplay();
      break;
      case 'e':
      relbow = (relbow + 5) % 360;
      glutPostRedisplay();break;
      case 'E':
      relbow = (relbow - 5) % 360;
      glutPostRedisplay();
      break;
      case 'd':
      lshoulder = (lshoulder + 5) % 360;
      glutPostRedisplay();
      break;
      case 'D':
      lshoulder = (lshoulder - 5) % 360;
      glutPostRedisplay();
      break;
      case 'r':
      lelbow = (lelbow + 5) % 360;
      glutPostRedisplay();break;
      case 'R':
      lelbow = (lelbow - 5) % 360;
      glutPostRedisplay();
      break;
      case 'j':
      rltside = (rltside + 5) % 360;
      glutPostRedisplay();
      break;
      case 'J':
      rltside = (rltside - 5) % 360;
      glutPostRedisplay();
      break;
      case 'k':
      rltforward = (rltforward + 5) % 360;
      glutPostRedisplay();break;
      case 'K':
      rltforward= (rltforward - 5) % 360;
      glutPostRedisplay();
      break;
      case 'l':
      rlbforward = (rlbforward + 5) % 360;
      glutPostRedisplay();break;
      case 'L':
      rlbforward= (rlbforward - 5) % 360;
      glutPostRedisplay();
      break;

      case 'i':
      lltside = (lltside + 5) % 360;
      glutPostRedisplay();
      break;
      case 'I':
      lltside = (lltside - 5) % 360;
      glutPostRedisplay();
      break;
      case 'o':
      lltforward = (lltforward + 5) % 360;
      glutPostRedisplay();break;
      case 'O':
      lltforward= (lltforward - 5) % 360;
      glutPostRedisplay();
      break;

      case 'p':
      llbforward = (llbforward + 5) % 360;
      glutPostRedisplay();break;
      case 'P':
      llbforward= (llbforward - 5) % 360;
      glutPostRedisplay();          
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
	 init ();
	 glutDisplayFunc(display);
	 glutReshapeFunc(reshape);
	 glutKeyboardFunc(keyboard);
	 glutMainLoop();
   return 0;
}

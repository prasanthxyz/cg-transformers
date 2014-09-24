#include <GL/glew.h>
#include <GL/glut.h>
#include <stdlib.h>

class Transformer
{
   public:
   int rshoulder;
   int relbow;
   int fullx;
   int fully;
   int fullz;
   int headside;
   int headforward;
   int headcurve;
   int lshoulder;
   int lelbow;
   int lltside;
   int lltforward;
   int rltside;
   int rltforward;
   int llbforward;
   int rlbforward;
   GLUquadricObj *neck;
   GLUquadricObj *rshoulderhand;
   GLUquadricObj *relbowhand;
   GLUquadricObj *lshoulderhand;
   GLUquadricObj *lelbowhand;
   GLUquadricObj *rtopleg;
   GLUquadricObj *rbottomleg;
   GLUquadricObj *ltopleg;
   GLUquadricObj *lbottomleg;
   Transformer()
   {
	  rshoulder = -45;
	  relbow = 0;
	  fullx = 0;
	  fully = 0;
	  fullz = 0;
	  headside = 0;
	  headforward = 0;
	  headcurve = 0;
	  lshoulder = -135;
	  lelbow = 0;
	  lltside = -90;
	  lltforward = 0;
	  rltside = -90;
	  rltforward = 0;
	  llbforward = 0;
	  rlbforward = 0;
	  neck = gluNewQuadric();
	  rshoulderhand = gluNewQuadric();
	  relbowhand = gluNewQuadric();
	  lshoulderhand = gluNewQuadric();
	  lelbowhand = gluNewQuadric();
	  rtopleg = gluNewQuadric();
	  rbottomleg = gluNewQuadric();
	  ltopleg = gluNewQuadric();
	  lbottomleg = gluNewQuadric();
   }
};

Transformer T;

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();

   glColor3f(0.96, 0.8, 0.69);
   glRotatef ((GLfloat) T.fullz, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.fullx, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.fully, 0.0, 1.0, 0.0);
   glPushMatrix();

   glTranslatef(0.0, -1.1, 0.0);
   glScalef(1.6, 0.3, 1.0);
   glutSolidCube(1.0);
   glPopMatrix();

   //head		 
   glPushMatrix();
   glTranslatef (0.0, 2.0, 0.0);
   glRotatef ((GLfloat) T.headside, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) T.headforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.headcurve, 0.0, 1.0, 0.0);
   glutSolidSphere(0.7, 32, 32);

   //eyes
   glColor3f(0, 0, 0);
   glPushMatrix();
   glTranslatef(-0.4, 0.1, 0.0);
   glutSolidSphere(0.15, 32, 32);
   glPopMatrix();
   glPushMatrix();
   glTranslatef(0.4, 0.1, 0.0);
   glutSolidSphere(0.15, 32, 32);
   glPopMatrix();
   glColor3f(0.96, 0.8, 0.69);  
   glPopMatrix();

   //neck
   glPushMatrix();
   glTranslatef (0.0, 1.4, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
   gluCylinder(T.neck, 0.35f, 0.35f, 0.3f, 32, 32);
   glPopMatrix();
   glPopMatrix();

   //righthand
   glPushMatrix();
   glTranslatef (1.0, 0.9, 0.0);
   glRotatef ((GLfloat) T.rshoulder, 0.0, 0.0, 1.0);
   glPushMatrix();
   glutSolidSphere(0.2, 32, 32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.rshoulderhand, 0.2f, 0.2f, 1.2f, 32, 32);
   glPopMatrix();
   glTranslatef (1.3, 0.0, 0.0);
   glRotatef ((GLfloat) T.relbow, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.relbowhand, 0.2f, 0.2f, 1.5f, 32, 32);
   glPopMatrix();
   glPopMatrix();

   //lefthand
   glPushMatrix();
   glTranslatef (-1.0, 0.9, 0.0);
   glRotatef ((GLfloat) T.lshoulder, 0.0, 0.0, 1.0);
   glPushMatrix();
   glutSolidSphere(0.2, 32, 32);
   glTranslatef (0.1, 0.0, 0.0);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.lshoulderhand, 0.2f, 0.2f, 1.2f, 32, 32);
   glPopMatrix();
   glTranslatef (1.3, 0.0, 0.0);
   glRotatef ((GLfloat) T.lelbow, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.lelbowhand, 0.2f, 0.2f, 1.5f, 32, 32);
   glPopMatrix();
   glPopMatrix();

   //body  
   glPushMatrix();
   glScalef(1.6, 2.0, 1.0);
   glutSolidCube(1.0);
   glPopMatrix();

   //rightleg
   glPushMatrix();
   glTranslatef (0.58, -1.38, 0.0);
   glRotatef ((GLfloat) T.rltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.rltside, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.rtopleg, 0.3f, 0.3f, 1.0f, 32, 32);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.rlbforward, 0.0, 1.0, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.rbottomleg, 0.3f, 0.3f, 1.2f, 32, 32);
   glPopMatrix();
   glPopMatrix();

   //leftleg   
   glPushMatrix();
   glTranslatef (-0.58, -1.38, 0.0);
   glRotatef ((GLfloat) T.lltforward, 1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.lltside, 0.0, 0.0, 1.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.ltopleg, 0.3f, 0.3f, 1.0f, 32, 32);
   glPopMatrix();
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) T.llbforward, 0.0, 1.0, 0.0);
   glPushMatrix();
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
   gluCylinder(T.lbottomleg, 0.3f, 0.3f, 1.2f, 32, 32);
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
   switch (key) 
   {
	  case 'v':
	  T.fullx = (T.fullx + 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'V':
	  T.fullx = (T.fullx - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'b':
	  T.fully = (T.fully + 5) % 360;
	  glutPostRedisplay();break;
	  case 'B':
	  T.fully = (T.fully - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'n':
	  T.fullz = (T.fullz + 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'N':
	  T.fullz = (T.fullz - 5) % 360;
	  glutPostRedisplay();
	  break;


	  case 'z':
	  T.headside = (T.headside + 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'Z':
	  T.headside = (T.headside - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'x':
	  T.headforward = (T.headforward + 5) % 360;
	  glutPostRedisplay();break;
	  case 'X':
	  T.headforward = (T.headforward - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'c':
	  T.headcurve = (T.headcurve + 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'C':
	  T.headcurve = (T.headcurve - 5) % 360;
	  glutPostRedisplay();
	  break;

	  case 's':
	  T.rshoulder = (T.rshoulder + 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'S':
	  T.rshoulder = (T.rshoulder - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'e':
	  T.relbow = (T.relbow + 5) % 360;
	  glutPostRedisplay();break;
	  case 'E':
	  T.relbow = (T.relbow - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'd':
	  T.lshoulder = (T.lshoulder + 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'D':
	  T.lshoulder = (T.lshoulder - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'r':
	  T.lelbow = (T.lelbow + 5) % 360;
	  glutPostRedisplay();break;
	  case 'R':
	  T.lelbow = (T.lelbow - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'j':
	  T.rltside = (T.rltside + 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'J':
	  T.rltside = (T.rltside - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'k':
	  T.rltforward = (T.rltforward + 5) % 360;
	  glutPostRedisplay();break;
	  case 'K':
	  T.rltforward= (T.rltforward - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'l':
	  T.rlbforward = (T.rlbforward + 5) % 360;
	  glutPostRedisplay();break;
	  case 'L':
	  T.rlbforward= (T.rlbforward - 5) % 360;
	  glutPostRedisplay();
	  break;

	  case 'i':
	  T.lltside = (T.lltside + 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'I':
	  T.lltside = (T.lltside - 5) % 360;
	  glutPostRedisplay();
	  break;
	  case 'o':
	  T.lltforward = (T.lltforward + 5) % 360;
	  glutPostRedisplay();break;
	  case 'O':
	  T.lltforward= (T.lltforward - 5) % 360;
	  glutPostRedisplay();
	  break;

	  case 'p':
	  T.llbforward = (T.llbforward + 5) % 360;
	  glutPostRedisplay();break;
	  case 'P':
	  T.llbforward= (T.llbforward - 5) % 360;
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

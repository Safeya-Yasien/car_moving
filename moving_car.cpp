#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
      glBegin(GL_POLYGON);
      glVertex2f(cx, cy);
      for (int i = 0; i <= 360; i++)
      {
            float angle = i * 3.1416 / 180;
            float x = rx * cos(angle);
            float y = ry * sin(angle);
            glVertex2f((x + cx), (y + cy));
      }
      glEnd();
}

void sun(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
      glBegin(GL_POLYGON);
      glVertex2f(cx, cy);
      for (int i = 0; i <= 360; i++)
      {
            float angle = i * 3.1416 / 180;
            float x = rx * cos(angle);
            float y = ry * sin(angle);
            glVertex2f((x + cx), (y + cy));
      }
      glEnd();
}
void ellipse(float rx, float ry, float cx, float cy)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}


void init(void)
{
      glClearColor(0.6, 0.9, 1.0, 0.0);
      glMatrixMode(GL_PROJECTION);
      gluOrtho2D(0.0, 500, 0.0, 500); // window size
}

float bx = 10;

void clouds()
{
    glPushMatrix();
    glTranslatef(bx, 0, 0);
    // Clouds code
        glColor3ub(227, 242, 253);
        ellipse(20, 30, 460, 460);
        ellipse(15, 20, 445, 460);
        ellipse(15, 20, 475, 460);

        ellipse(20, 30, 390, 420);
        ellipse(15, 20, 405, 420);
        ellipse(15, 20, 375, 420);
        glPopMatrix();

    bx += 0.025;
    if (bx > 0)
        bx = -500;
    glutPostRedisplay();
}


void hills() {
      // Hills 1
      glColor3ub(184, 134, 11);
      glBegin(GL_POLYGON);
          glVertex2d(-40, 300);
          glVertex2d(200, 300);
          glVertex2d(100, 450);
      glEnd();

      // Hills 2
      glColor3ub(218, 165, 32);
      glBegin(GL_POLYGON);
          glVertex2d(150, 300);
          glVertex2d(350, 300);
          glVertex2d(250, 450);
      glEnd();

      // Hills 3
      glColor3ub(184, 134, 11);
      glBegin(GL_POLYGON);
          glVertex2d(300, 300);
          glVertex2d(520, 300);
          glVertex2d(400, 450);
      glEnd();

}



void display(void)
{
      glClear(GL_COLOR_BUFFER_BIT);

      //Ground Color
      glColor3ub(105, 105, 105);
      glBegin(GL_POLYGON);
              glVertex2d(0, 0);
              glVertex2d(500, 0);
              glVertex2d(500, 150);
              glVertex2d(0, 150);
      glEnd();

      // road

      glColor3ub(255, 255, 255);
      glBegin(GL_POLYGON);
          glVertex2d(0, 55);
          glVertex2d(500, 55);
          glVertex2d(500, 115);
          glVertex2d(0, 115);
      glEnd();

      glColor3ub(0, 0, 0);
      glBegin(GL_POLYGON);
          glVertex2d(0, 60);
          glVertex2d(500, 60);
          glVertex2d(500, 110);
          glVertex2d(0, 110);
      glEnd();

      clouds();
      // hills
      hills();

      //sun design
      glColor3ub(255, 215, 0);
      sun(20, 20, 175, 450);

      glPushMatrix();
      glTranslatef(-bx, 0, 0);

      glColor3ub(51, 51, 255);
      glBegin(GL_POLYGON);
          glVertex2d(410, 100);
          glVertex2d(490, 100);
          glVertex2d(485, 130);
          glVertex2d(410, 130);
      glEnd();

      glColor3ub(51, 51, 255);
      glBegin(GL_POLYGON);
          glVertex2d(420, 130);
          glVertex2d(475, 130);
          glVertex2d(465, 160);
          glVertex2d(430, 160);
      glEnd();

      // car window
      glColor3ub(220, 220, 220);
      glBegin(GL_POLYGON);
          glVertex2d(425, 130);
          glVertex2d(445, 130);
          glVertex2d(445, 150);
          glVertex2d(430, 150);
      glEnd();

      // car window
      glColor3ub(220, 220, 220);
      glBegin(GL_POLYGON);
          glVertex2d(450, 130);
          glVertex2d(470, 130);
          glVertex2d(465, 150);
          glVertex2d(450, 150);
      glEnd();

      // car wheel
      glColor3ub(0, 0, 0);
      circle(10, 14, 435, 100);
      circle(10, 14, 465, 100);

      glColor3ub(245, 245, 245);
      circle(6, 10, 435, 100);
      circle(6, 10, 465, 100);

      glPopMatrix();
      bx += .05;
      if (bx > 0)
            bx = 400;
      glutPostRedisplay();
      glFlush();
      glutSwapBuffers();
}

int main(int argc, char** argv)

{
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(1000, 600);
      glutInitWindowPosition(300, 50);
      glutCreateWindow("A Moving Car Scenario");
      init();
      glutDisplayFunc(display);
      glutMainLoop();
      return 0;
}

#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void display()
{
     glClearColor(1,1,1,1);
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1, 0, 1);
     glBegin(GL_LINES);
     glVertex2f(20,20);
     glVertex2f(20,60);

     glVertex2f(20,60);
     glVertex2f(60,60);

     glVertex2f(60,60);
     glVertex2f(60,20);

     glVertex2f(60,20);
     glVertex2f(20,20);

     glEnd();
     glColor3f(1, 1, 0.1);
     glBegin(GL_TRIANGLES);
         glVertex2f(20,60);
         glVertex2f(40,80);
         glVertex2f(60,60);
     glEnd();
     glColor3f(1, 0, 0.8);
     glBegin(GL_QUADS);
         glVertex2f(30,20);
         glVertex2f(30,40);
         glVertex2f(50,40);
         glVertex2f(50,20);
     glEnd();
     glColor3f(1, 0, 0);
     glBegin(GL_QUADS);
         glVertex2f(45,45);
         glVertex2f(45,55);
         glVertex2f(55,55);
         glVertex2f(55,45);
     glEnd();

     glColor3f(1, 0, 0);
     glBegin(GL_LINES);
         glVertex2f(45,45);
         glVertex2f(45,55);

         glVertex2f(45,55);
         glVertex2f(55,55);

         glVertex2f(55,55);
         glVertex2f(55,45);

         glVertex2f(55,45);
         glVertex2f(45,45);

     glEnd();
     glColor3f(1, 1, 1);
     glBegin(GL_LINES);
         glVertex2f(45,45);
         glVertex2f(55,55);
         glEnd();
         glBegin(GL_LINES);
         glVertex2f(45,55);
         glVertex2f(55,45);
     glEnd();
     glFlush();
}

void init()
{
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(0,100,0,100);
     glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(50,50);
     glutCreateWindow("HRUSHIKESHA");
     glutDisplayFunc(display);
     init();
     glutMainLoop();
}

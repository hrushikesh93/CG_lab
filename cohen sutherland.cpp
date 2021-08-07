#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdbool.h>
double xmin=50,ymin=50,xmax=100,ymax=100;
const int RIGHT=8;
const int LEFT=2;
const int TOP=4;
const int BOTTOM=1;
float x0,y0,x1,y1;

int Compute(float x,float y)
{
    int code=0;
    if(y>ymax)
        code|=TOP;
    else if(y<ymin)
        code|=BOTTOM;
    if(x>xmax)
        code|=RIGHT;
    else if(x<xmin)
        code|=LEFT;
    return code;
}
void Cohen(float x0,float y0,float x1,float y1)
{
    int code0,code1,codeOut;
    bool accept=false,done=false;
    code0=Compute(x0,y0);
    code1=Compute(x1,y1);
    do
    {
    if(!(code0|code1))
    {
        accept=true;
        done=true;
    }
    else if(code0 & code1)
    {
        done=true;
    }
    else
    {
        double x,y;

        codeOut=code0?code0:code1;
        if(codeOut & TOP)
        {
        x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
        y=ymax;
        }
        else if(codeOut & BOTTOM)
        {
        x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
        y=ymin;
        }
        else if(codeOut & RIGHT)
        {
        y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
        x=xmax;
        }
        else
        {
        y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
        x=xmin;
        }
        if(codeOut==code0)
        {
        x0=x;
        y0=y;
        code0=Compute(x0,y0);
        }
        else
        {
        x1=x;
        y1=y;
        code1=Compute(x1,y1);
        }
        }
        }while(!done);
        if(accept)
        {
        glTranslatef(200,200,0);
        glScalef(2,2,1);
        glColor3f(0,0,1);
            glBegin(GL_LINE_LOOP);
            glVertex2f(xmin,ymin);
            glVertex2f(xmax,ymin);
            glVertex2f(xmax,ymax);
            glVertex2f(xmin,ymax);
        glEnd();
        glColor3f(1,0,0);
            glBegin(GL_LINES);
            glVertex2d(x0,y0);
            glVertex2d(x1,y1);
        glEnd();
        }
}
void display()
{


    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2d(x0,y0);
        glVertex2d(x1,y1);
    glEnd();
    glColor3f(0.0,1.0,1.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymax);
        glVertex2f(xmin,ymax);
    glEnd();

    Cohen(x0,y0,x1,y1);
    glFlush();
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);     
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char**argv)
{
    printf("enter line values\n");
    scanf("%f %f %f %f",&x0,&y0,&x1,&y1);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("HRUSHIKESHA - 1CR18CS074");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}

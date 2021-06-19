#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdlib.h>

float x1= 200 , y1=200;
float x2= 100 , y2=300;
float x3= 200 , y3=400;
float x4= 300 , y4=300;

float flag;

void edge(float x1,float y1, float x2, float y2,int *le,int *re)
{
    float mx,x,temp;

    if(y2<y1)
    {
        temp=x1;
        x1=x2;
        x2=temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }

    mx=(x2-x1)/(y2-y1);
    x=x1;
    for(int y=y1;y<=y2;y++)
    {
        if(x<(float)le[y])
        {
            le[y]=(int)x;
        }
        if(x>(float)re[y])
        {
            re[y]=(int)x;
        }
        x=x+mx;
    }
}

void scanline(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
    int le[500], re[500];

    for(int i=0;i<500;i++)
    {
        le[i]=500;
        re[i]=0;
    }

    edge(x1,y1,x2,y2,le,re);
    edge(x2,y2,x3,y3,le,re);
    edge(x3,y3,x4,y4,le,re);
    edge(x4,y4,x1,y1,le,re);


    for(int y=0;y<500;y++)
    {
        for(int x=le[y];x<=re[y];x++)
        {
            glBegin(GL_POINTS);
                glVertex2f(x,y);
            glEnd();
        }
    }
}

void display()
{
     glClearColor(1,1,1,1);
     glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(1, 0, 0);
     glBegin(GL_LINE_LOOP);
        glVertex2d(x1,y1);
        glVertex2d(x2,y2);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
     glEnd();

     if(flag==1)
     {
         scanline(x1,y1,x2,y2,x3,y3,x4,y4);
     }
     glFlush();
}

void init()
{
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(0,500,0,500);
     glMatrixMode(GL_MODELVIEW);
}



void mymenu(int id)
{
    if(id==10)
    {
        flag=1;
    }
    if(id==20)
    {
        flag=0;
    }
    if(id==30)
    {
        exit(0);
    }


    glutPostRedisplay();
}


int main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(50,50);
     glutCreateWindow("scanline - HRUSHIKESHA");
     glutDisplayFunc(display);
     init();
     glutCreateMenu(mymenu);
     glutAddMenuEntry("scanfill",10);
     glutAddMenuEntry("reset",20);
     glutAddMenuEntry("quit",30);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
     glutMainLoop();
}


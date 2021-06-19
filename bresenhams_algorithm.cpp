#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>

int a , b, c,d;
void draw_pixel(int x,int y)
{
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
}
void bresenhamas(int x1,int y1,int x2,int y2)
{
    float dx = x2-x1;
    float dy = y2-y1;
    if(dx<0) dx = -dx;
    if(dy<0) dy = -dy;

    float m = dy;
    if(dx!=0){
        m = dy/dx;
    }

    if(m<1){

    float p = 2*dy -dx;
    float ppos = 2*dy-2*dx;
    float  pneg = 2*dy;
    if(x1>x2)
    {

        int temp = x1;
        x1=x2;
        x2=temp;

        temp = y1;
        y1=y2;
        y2=temp;
    }
    int x = x1;
    int y = y1;
    draw_pixel(x,y);
    int incy=1;
    if(y2<y1)incy=-1;
    for(int k=0;k<dx;k++){
        x++;
        if(p <0)
        {

            p =p +pneg;
        }
        else{
  //          if(y2>y1)y++;
    //        else y--;
            y = y+incy;
            p = p+ppos;
        }
        draw_pixel(x,y);
    }
    }
    else
    {
        float p = 2*dx -dy;
    float ppos = 2*dx-2*dy;
    float  pneg = 2*dx;

    if(y1>y2)
    {

        int temp = x1;
        x1=x2;
        x2=temp;

        temp = y1;
        y1=y2;
        y2=temp;
    }
    int x = x1;
    int y = y1;

    int incx=1;
    if(x2<x1)incx=-1;
    draw_pixel(x,y);
    for(int k=0;k<dy;k++){
        y++;
        if(p <0)
        {

            p =p +pneg;
        }
        else{
  //          if(y2>y1)y++;
    //        else y--;
            x = x+incx;
            p = p+ppos;
        }
        draw_pixel(x,y);
    }
    }

}


void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    //
    glColor3f(1,0,0);
    bresenhamas(a,b,c,d);
    glColor3f(0,0,1);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(a,b);
        glVertex2f(c,d);
    glEnd();
    glFlush();
}
void init()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

/* Program entry point */

int main(int argc, char *argv[])
{
    printf("Enter end Points (X0,Y0) and (X1,Y1):\n");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham's Line Drawing - Hrushikesha");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}

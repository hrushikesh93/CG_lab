#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>

float v[4][3] = {{-1,-1,-1},{0,1,-1},{1,-1,-1},{0,0,1}};
int m;

void triangle(float a[3], float b[3], float c[3])
{
    glBegin(GL_TRIANGLES);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glEnd();
}

void divide_triangle(float a[3], float b[3], float c[3], int m)
{
    float v1[3], v2[3], v3[3];

    if(m>0)
    {
        for(int i=0;i<3;i++)
        {
            v1[i] = (a[i]+b[i])/2;
            v2[i] = (c[i]+b[i])/2;
            v3[i] = (a[i]+c[i])/2;
        }
        divide_triangle(b,v1,v2,m-1);
        divide_triangle(a,v1,v3,m-1);
        divide_triangle(c,v3,v2,m-1);

    }
    else
    {
        triangle(a,b,c);
    }

}

void tetrahedron()
{
    glColor3f(0,0,1);
    divide_triangle(v[0],v[1],v[3],m);

    glColor3f(0,1,0);
    divide_triangle(v[0],v[2],v[3],m);

    glColor3f(1,1,0);
    divide_triangle(v[1],v[2],v[3],m);

    glColor3f(1,0,0);
    divide_triangle(v[0],v[1],v[2],m);
}

void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    tetrahedron();

    glFlush();
}
void init()
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(-2,2,-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);
}



int main(int argc, char **argv)
{
    printf("enter number of divisions :");
    scanf("%d",&m);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow(" sierpinski gasket - Hrushikesha");
    glutDisplayFunc(display);
    init();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

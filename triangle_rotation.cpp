#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>

float triangle[3][3] = { {200,400,300}, //x  coordinates
                 {100,100,300}, //y  coordinates
                 {1,1,1}
                 };

float result[3][3] = { {0},{0},{0}};
float rot_matrix[3][3] = { {0},{0},{0}};

float h,k;
float theta = 0;

void draw_triangle(float a[][3])
{
    glBegin(GL_TRIANGLES);
        glVertex2f(a[0][0],a[1][0]);
        glVertex2f(a[0][1],a[1][1]);
        glVertex2f(a[0][2],a[1][2]);
    glEnd();


}

void multiply()
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            result[i][j] =0;
            for (int k=0;k<3;k++)
            {
                result[i][j]+= rot_matrix[i][k] * triangle[k][j];
            }
        }
    }
}

void rrotate(float h,float k)
{
  float  m = h*(1-cos(theta)) + k*sin(theta);
   float n = k*(1-cos(theta)) - h*sin(theta);

    rot_matrix[0][0] = cos(theta);
    rot_matrix[0][1] = -sin(theta);
    rot_matrix[0][2] = m;
    rot_matrix[1][0] = sin(theta);
    rot_matrix[1][1] = cos(theta);
    rot_matrix[1][2] = n;
    rot_matrix[2][0] = 0;
    rot_matrix[2][1] = 0;
    rot_matrix[2][2] = 1;

    multiply();

}

void display()
{
     glClearColor(1,1,1,1);
     glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(1, 0, 0);
     draw_triangle(triangle);

     glColor3f(0,0,1);
     rrotate(0,0);
     draw_triangle(result);

     glColor3f(0, 1, 0);
     rrotate(h,k);
     draw_triangle(result);

     glColor3f(0, 0, 0);
     glPointSize(5);
     glBegin(GL_POINTS);
        glVertex2f(0,0);
     glEnd();

     glFlush();
}

void init()
{
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(-500,500,-500,500);
     glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
    printf("enter the theta :");
    scanf("%f",&theta);
    theta=((3.14/180)*theta);
    printf("enter the coordinates of h and k:");
    scanf("%f %f",&h,&k);

     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(0,0);
     glutCreateWindow(" triangle rotation - HRUSHIKESHA");
     glutDisplayFunc(display);
     init();
     glutMainLoop();
}

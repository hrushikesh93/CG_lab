#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define PI 3.14159265f
GLfloat w=500,h=500;
void disp();
int x1,by, count=0,miss=0,xxxradius=100;
int s1=0,s2=0,s3=0,l=5;
float e,x,y,angle=0.0;
int flag=0,flag1=0,flag2=0,flag3=0,speed=2, flagl2=0,level=1;

static void key(unsigned char key, int x, int y);
void mymouse(int btn,int state,int x3,int y3);
void missdisp();
void scoredisp();
void star1();
void star2();
void star3();
void basket();
void level2();
void level3();
int n=60, m=0;
GLfloat xb=200, yb=20, xs1=230,xs2=330,xs3=160;
//GLfloat xb=200, yb=20, xs1=260,xs2=360;
void display();
void drawstring(float x,float y,float z,char *string)
{
 char *c;
 glRasterPos3f(x,y,z);
 for(c=string;*c!='\0';c++)
 {
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
 }
}
void frontscreen(void)
{
glClearColor(0.4, 0.0,1.0,1.0);
int xxxradius=200;

	{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glColor3f(1.0,1.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
	for(angle=0; angle<360; angle+=1)
	{
    		y =250+(cos(angle*PI/180)*xxxradius);
    		x =250+(sin(angle*PI/180)*xxxradius);
    		glVertex2f(x,y);
	}
	glEnd();


  glPointSize(10.0);
 glColor3f(0.0,0.0,0.0);

 glBegin(GL_POINTS);
 		glVertex2f(220,270);
 		glVertex2f(280,270);

 glEnd();
 glLineWidth(10.0);
 glBegin(GL_LINE_STRIP);
 		glVertex2f(210,220);
 		glVertex2f(235,200);
 		glVertex2f(250,195);
 	glVertex2f(265,200);
 //	glVertex2f(250,200);
 		glVertex2f(290,220);
 glEnd();

}

                                              //GLfloat xb=200, yb=20, xs1=230,xs2=330,xs3=160;
	//glColor3ub( rand()%255, rand()%255, rand()%255 );



	glColor3f(1.0,0.0,0.0);
	 drawstring(170,450,0.0,"Team 'i dont know'");
	glColor3f(0.9,0.0,1.0);
	 drawstring(195,415,0.0,"PRESENTS");
	glColor3f( 0.0,0.0,1.0 );
	 drawstring(168,380,0.0,"~DORACATCH~");
	 glColor3f( 1.0,0.0,0.0 );
	 drawstring(30,250,0.0,"BY:");
	 glColor3f( 0.9,0.0,1.0 );
	 drawstring(30,210,0.0,"Hrushikesha");
	drawstring(30,185,0.0,"k subbi reddy");
	glColor3f( 1.0,0.0,0.0 );
	 drawstring(350,250,0.0,"GUIDE : ");
	  glColor3f( 0.9,0.0,1.0 );
	drawstring(320,210,0.0,"Prof.Anjali ");
	glColor3f( 0.0,0.0,1.0 );
	 // drawstring(140,120,0.0,"Press i for Instructions");
	glColor3ub( rand()%250, rand()%250, rand()%200 );
	 drawstring(140,80,0.0,"Press ENTER to Begin ");
	 //glColor3f( 0.0,1.0,0.4 );

	glFlush();
}
void instr()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f( 0.0,0.0,0.9 );
	drawstring(180,450,0.0,"Instructions ");
	drawstring(20,400,0.0,"1.The player has to catch the falling DORAs ");
	drawstring(20,373,0.0,"into the basket to gain the Score. ");
	 drawstring(20,342,0.0,"2.a/A to move the basket to the left and d/D to ");
	 drawstring(20,315,0.0,"move the basket to the right. ");
	 drawstring(20,284,0.0,"3.Each DORA will increament the Score by +1. ");
	 drawstring(20,253,0.0,"4.Upon catching the fast moving BUZY DORA ");
	 drawstring(20,226,0.0,"the player will gain Bonus Score of +3. ");
	 drawstring(20,195,0.0,"5.A Score of 10 will lead the player to the next   ");
	 drawstring(20,168,0.0,"level increasing the complexity for the player. ");
	 drawstring(20,137,0.0,"6.A Miss of 10 will end the game. ");
	 drawstring(20,106,0.0,"7.To Quit the game at any stage press q/Q ");

	// drawstring(200,50,0.0,"GOOD LUCK! ");

	glColor3ub( rand()%250, rand()%250, rand()%200 );
 	drawstring(120,60,0.0,"PRESS 's' TO START");

	glFlush();
}

void mydisplay(void)
{   if(flag==0&&flag1==0 &&flag2==0)
    	frontscreen ();

    if(flag1==1 && flag==0 &&flag2==0)//&&flag==0)
        instr();


   if(flag==1 && flag1==0 &&flag2==0)
   	display();

   if(miss>=10 && flag==1 && flag1==1)
   missdisp();
   //scoredisp();

   /*if(count==10 && flag==1)

    {
   //display();
   	level2();

    }
   */
}


void reshape (int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w>h)
			gluOrtho2D((GLfloat)w/(GLfloat)h*(0),(GLfloat)w/(GLfloat)h*(500),0,500);
else
			gluOrtho2D(0,500,(GLfloat)h/(GLfloat)w*(0),(GLfloat)h/(GLfloat)w*500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void mytimer(int v)
{
	glutPostRedisplay();
	glutTimerFunc(25, mytimer, v);
}

void moveright(void)
{
	if(xb+50 < 500)
   		xb=xb+7;
	basket();
	//glTranslatef(5, 0.0, 0.0);
}
void moveleft(void)
{
	if(xb>0)
	xb=xb-7;
	basket();
	//glTranslatef(-5, 0.0, 0.0);

}
void level2()
{
	flag=1;
	flag1=1;
	//s1=0;
	//s2=0;
	//s3=0;
	glClear(GL_COLOR_BUFFER_BIT);

	glRasterPos2f(200,250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'V');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');
	glRasterPos2f(200,100);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'P');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'L');

	glFlush();

}
void level3()
{
	flag=1;
	flag1=1;
	flagl2=1;
	//s1=0;
	//s2=0;
	//s3=0;
	glClear(GL_COLOR_BUFFER_BIT);

	glRasterPos2f(200,250);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'V');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');
	glRasterPos2f(200,100);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'P');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'g');

	glFlush();

}

int main(int argc,char **argv)
{
        glutInit(&argc,argv);
        glutInitWindowSize(500,500);
	glutInitWindowPosition(300,200);

	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutCreateWindow("DoraCatch");
	glutDisplayFunc(mydisplay);

        glutReshapeFunc(reshape);
        glutKeyboardFunc(key);
       	glutMouseFunc(mymouse);
        glutTimerFunc(100, mytimer, n);

        glutMainLoop();

}
static void key(unsigned char key1, int x, int y)
{
	switch(key1)
	{
		case 'Q':
		case 'q':
			exit(0);
			break;
		case 'D':
		case 'd':

			moveright();
			break;
		case 'A':
		case 'a':

			moveleft();
		        break;
	 case 13:  flag1=1;
	 		//	if(flag1==0)
	 		//	flag=1;
	 		//	flag1=0;
              		break;
	case 's': if(flag1==1)
		  {
	           	flag=1;
			flag1=0;
		}

	break;

    	case 'l': if(flag1==1) // level 2
		  {
	           	flag=1;
			flag1=0;
			speed=speed+1;
		  }
 	            break;

	case 'g':if(flagl2==1) // level 3
	{
		flag=1;
		flagl2=0;
		flag1=0;
		speed=speed+2;
	}
	break;

}
}
void mymouse(int btn,int state,int x3,int y3)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	moveleft();
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	moveright();
}
void color1()
{

	if(count<10)
	glColor3f(1.0,0.0,0.8);
	else if(count<20)
	glColor3f(0.8,0.0,1.0);
	else if(count>20)
	glColor3ub( rand()%255, rand()%255, rand()%255 );
}
void color2()
{

	if(count<10)
	glColor3f(0.0,1.0,0.0);
	else if(count<20)
	glColor3f(0.0,0.8,0.8);
	else if(count>20)
	glColor3ub( rand()%255, rand()%255, rand()%255 );
}

void color3()
{

	if(count<10)
	glColor3f(1.0,0.0,0.0);
	else if(count<20)
	glColor3f(1.0,1.0,0.5);
	else if(count>20)
	glColor3f(1.0,0.0,0.0);
	//glColor3ub( rand()%260, rand()%250, rand()%255 );
}




void star1()
{
	if(s1==-500)
	s1=0;                                              //GLfloat xb=200, yb=20, xs1=230,xs2=330,xs3=160;
	//glColor3ub( rand()%255, rand()%255, rand()%255 );
//	glColor3f(1.0, 0.0,0.8);
	glBegin(GL_QUADS);
	color1();
		glVertex2f(xs1,s1+500);
		glVertex2f(xs1-10,s1+470);
		glVertex2f(xs1,s1+440);
		glVertex2f(xs1+10,s1+470);
	glEnd();
	if(s1>-500 & m == 0)// & count <10)
	{
		s1=s1-speed;
		printf("s1-->%d\t",s1);
	}

   	if(s1==-396 & xb+10<=xs1 & xs1<=xb+50)
	{
		m=1;
		count=count+1;
		s1=-500;
		s1=s1+speed;
		if(count>=10 & level==1)
		{

			level2();
			level=2;

		}
	 if(count>=20 & level==2)
		{
			level3();
			level=3;
		}
		xs1=xs1-(rand()%50);
		m=0;
		star1();
	}


	else if(s1==-396 & xb-10<=xs1<=xb+50 )
	{
		miss=miss+1;
		s1=-500;
		if(miss==10)
			missdisp();
	}


	//return count;
}



void star2()
{
	if(s2==-600)
	s2=0;
	//glColor3ub( rand()%255, rand()%255, rand()%255 );
        // glColor3f(0.0,1.0,0.0);
        color2();
	 glBegin(GL_QUADS);
		glVertex2f(xs2,s2+600);
		glVertex2f(xs2-10,s2+570);
		glVertex2f(xs2,s2+540);
		glVertex2f(xs2+10,s2+570);
	glEnd();


	if(s2>-600 & m==0)// &count<10)
	{
		s2=s2-speed;
		printf("s2-->%d\t",s2);
	}

	if(s2 ==-480 & xb+10<=xs2 & xs2<=xb+50)
	{
		m=1;
		count=count+1;
		s2=-600;
		s2=s2+speed;
		if(count>=10 & level==1)
		{
			level2();
			level=2;
		}
		 if(count>=20 & level==2)
		{
			level3();
			level=3;
		}
		xs2=xs2-(rand()%40);
		m=0;
		star2();

	}
	else if(s2 ==-480 & xb-10<=xs2<=xb+50)
	{
		miss=miss+1;
		s2=-600;
		if(miss==10)
			missdisp();
	}
}

void star3()
{
	if(s3==-500)               //GLfloat xb=200, yb=20, xs1=230,xs2=330,xs3=160;
		s3=0;
//	glColor3f(1.0,0.0,0.0);
color3();
	glBegin(GL_LINE_LOOP);
		glVertex2f(xs3,s3+500);
		glVertex2f(xs3+10,s3+480);
		glVertex2f(xs3+20,s3+500);
		glVertex2f(xs3+15,s3+500);
                glVertex2f(xs3+10,s3+490);
                glVertex2f(xs3+5,s3+500);
                glVertex2f(xs3,s3+500);

	glEnd();

	if(s3>-500 & m==0)// & count<10)
	{
		s3=s3-speed;
		printf("s3-->%d\t",s3);

	}
	if(s3==-420 & xb+2<=xs3 & xs3<=xb+50)
	{
		m=1;
		count=count+3;
		s3=-500;
		s3=s3+speed;
		if(count>=10 & level==1)
		{
			level2();
			level=2;
		}
		 if(count>=20 & level==2)
		{
			level3();
			level=3;
		}
		xs3=xs3+(rand()%30);
		m=0;
		star3();

	}
	else if(s3==-420 & xb-2<=xs3<=xb+50 )
	{
		miss=miss+1;
		s3=-500;
		if(miss==10)
			missdisp();
	}
}




void basket()
{
	//glColor3ub( rand()%255, 0.0, rand()%255 );
	glColor3f(0.9,0.9,0.9);
	 glBegin(GL_QUADS);                  // GLfloat xb=200, yb=20, xs1=260,xs2=360,xs3=160;

		glVertex2f(xb,yb);
		glVertex2f(xb+50,yb);
		glVertex2f(xb+50,yb+40);
		glVertex2f(xb,yb+40);
	glEnd();
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);
               glVertex2f(xb,yb);
               glVertex2f(xb+50,yb+40);
        glEnd();
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);
               glVertex2f(xb+50,yb);
               glVertex2f(xb,yb+40);
        glEnd();
        glBegin(GL_LINE_STRIP);
               glVertex2f(xb+25,yb);
               glVertex2f(xb+50,yb+20);
               glVertex2f(xb+25,yb+40);
               glVertex2f(xb,yb+20);
               glVertex2f(xb+25,yb);
        glEnd();
        glLineWidth(3.0);
        glBegin(GL_LINES);
               glVertex2f(xb,yb+60);
               glVertex2f(xb,yb);
               glVertex2f(xb+50,yb);
               glVertex2f(xb+50,yb+60);
        glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	//glColor3f(1.0,0.0,0.0);
   	 basket();
         //scoredisp();
	disp();
	//missdisp();
	glFlush();

}

void missd()
{
int p,m=0,n=0;
    p=miss;
	//glLoadIdentity();
	glColor3f(0.0,0.0,1.0);
	glRasterPos2f(10,400);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'M');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'I');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'S');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'S');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,':');
//	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,miss+48);
		while(p > 9)
        {
            n = p % 10;
            glRasterPos2f (62,400);
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+n);
           p /= 10;
           glRasterPos2f(55,400);
       }
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+p);

	//glFlush();

}

void disp()
{

	glColor3f(1.0,0.0,0.0);
 	glPushMatrix();
 	 glLoadIdentity();
	star1();
	 glPopMatrix();
	 glutSwapBuffers();
	  glPushMatrix();
 	 glLoadIdentity();
	star2();
	 glPopMatrix();
	 glutSwapBuffers();
	glPushMatrix();
 	 glLoadIdentity();
	star3();
	 glPopMatrix();
	 glutSwapBuffers();
	glPushMatrix();

	glPushMatrix();
 	 glLoadIdentity();
	 scoredisp();
	 glPopMatrix();
	 glPushMatrix();
 	 glLoadIdentity();
	 missd();
	 glPopMatrix();
}

void scoredisp()
{
	int z,j=0,k=0;
	z=count;

	//glLoadIdentity();
	glColor3f(0.0,0.0,1.0);
	glRasterPos2f(10,450);
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'S');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'C');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'O');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'R');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,'E');
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13,':');

	//glutBitmapCharacter(GLUT_BITMAP_8_BY_13,count+48);
		while(z > 9)
        {
            k = z % 10;
            glRasterPos2f (62,450);
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+k);
           z /= 10;
           glRasterPos2f(55,450);
       }
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+z);
}


void missdisp()
{
	flag=1;
	flag1=1;
	flag2=1;
	glClear(GL_COLOR_BUFFER_BIT);
	scoredisp();
	missd();
	glRasterPos2f(160,250);
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
	for(angle=0; angle<360; angle+=1)
	{
    		y =250+(cos(angle*PI/180)*xxxradius);
    		x =250+(sin(angle*PI/180)*xxxradius);
    		glVertex2f(x,y);
	}
 glEnd();

 glPointSize(20.0);
 glColor3f(0.0,0.0,0.0);

 glBegin(GL_POINTS);
 		glVertex2f(210,270);
 		glVertex2f(290,270);

 glEnd();
 glLineWidth(20.0);
 glBegin(GL_LINE_STRIP);
 		glVertex2f(200,180);
 	//	glVertex2f(250,200);
 	glVertex2f(225,200);
 	glVertex2f(275,200);
 		glVertex2f(300,180);
 glEnd();
 glLineWidth(5.0);
 glColor3f(1.0,1.0,0.9);
 glBegin(GL_LINES);
 	glVertex2f(210,250);
 	glVertex2f(210,240);
 	glVertex2f(290,250);
 	glVertex2f(290,240);
 	glVertex2f(210,220);
 	glVertex2f(210,210);
 	glVertex2f(290,220);
 	glVertex2f(290,210);
 	//glVertex2f(215,240);
 glEnd();
 glColor3f(0.0,0.0,1.0);
 glRasterPos2f(170,50);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'G');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'A');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'M');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'V');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
	glFlush();

}

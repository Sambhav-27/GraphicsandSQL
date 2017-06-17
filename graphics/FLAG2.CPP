
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

int x=50, y=50;

void create_sine(int x1,int y1, int x2, int y2)
{
	int angle=0;
	double x, y;
	for(x=x1;x<x2;x+=2)
	{
		y=10*sin(angle*M_PI/180);
		putpixel(x, y1+y, WHITE);
		angle+=5;
	}
}
int main()
{
	int i,xc,yc,r,t,xnew,flag=0;
	int yr;
	r=45;
	double theta, angle=0;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");

	while(!kbhit()) // determines if a key has been pressed
	{

			cleardevice(); //clears the screen and sets pointer at 0,0
			 xc=x+200; yc=y+150;
			setcolor(WHITE);
			create_sine(x,y, x+400, y);
			line(x,y,x,y+300);
			line(x+400,y,x+400,y+300);
			create_sine(x,y+100,x+400,y+100);
			create_sine(x,y+200,x+400,y+200);
			create_sine(x, y+300, x+400, y+300);
			setcolor(BLUE);
			circle(xc, yc, r);

			for(i=0;i<24;i++)
			{
				theta=M_PI*angle/180;     // for creating spokes
				int x2=xc+r*cos(theta);
				int y2=yc+r*sin(theta);
				angle+=15;  // dist b/w spokes 360/ no of spokes
				line(xc,yc,x2,y2);
			}

		   //	setcolor(RED);
		   //	rectangle(x,y+200, x+400,y+300);
		   //	setfillstyle(SOLID_FILL, GREEN);
		   //	floodfill(x+100, y+250, RED);
		  xnew=x;
		  if(!flag)
		  xnew+=20;
		  else
		  xnew-=20;
		  x=xnew;
		  flag=!flag;
		  delay(200);
	}
	getch();
	closegraph();
}

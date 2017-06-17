
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

int xc=50,yc=200,r=35;


void main()
{
	double angle=0,theta;
	int i,a;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");

	while(!kbhit()) // determines if a key has been pressed
	{
			theta=M_PI*angle/180;
			cleardevice(); //clears the screen and sets pointer at 0,0

			setcolor(RED);
			circle(xc, yc, r);
			for(i=0;i<24;i++)
			{
				theta=M_PI*angle/180;     // for creating spokes
				int x2=xc+r*cos(theta);
				int y2=yc+r*sin(theta);
				angle+=15;  // dist b/w spokes 360/ no of spokes
			  	line(xc,yc,x2,y2);
			}
			angle+=20; // this angle is for rotation or speed of rotation
			delay(50);
	}
	getch();
	closegraph();
}
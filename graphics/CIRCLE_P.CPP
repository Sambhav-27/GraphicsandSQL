
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

int x,y,r=80,d;
void plotcircle(int x, int y, int xc, int yc)
{
	putpixel(xc+x, yc-y, WHITE);
	putpixel(xc+y, yc-x, WHITE);
	putpixel(xc+x, yc+y, WHITE);
	putpixel(xc+y, yc+x, WHITE);

	putpixel(xc-x, yc-y, WHITE);
	putpixel(xc-y, yc-x, WHITE);
	putpixel(xc-x, yc+y, WHITE);
	putpixel(xc-y, yc+x, WHITE);
}
void draw_circle(int xc, int yc, int r)
{
	   x=0; y=r; d=5/4-r;
	   while(x<=y)
	   {
			if(d<=0)
			d+=(2*x+3);
			else
			{
				d+=(2*x-2*y+5);
				y--;
			}
			x++;
			plotcircle(x, y, xc, yc);
	   }
}
void main()
{
	int xc=320, yc=270;

	int r1=10;
	double theta, angle=0;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");

	while(!kbhit()) // determines if a key has been pressed
	{
	   cleardevice();
	   theta=M_PI*angle/180;
	   xc+=(r1*cos(theta));
	   yc+=(r1*sin(theta));
	   draw_circle(xc, yc, r);
	   draw_circle(xc, yc-r, r);
	   draw_circle(xc-r, yc, r);
	   draw_circle(xc+r, yc, r);
	   draw_circle(xc, yc+r, r);

	   angle+=20;
	   delay(100);
	}
	getch();
	closegraph();
}
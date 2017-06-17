
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
	int xc1,xc2,xc3,xc4,xc5,xc6;
	int yc1,yc2,yc3,yc4,yc5,yc6;
	int r1=10;
	double theta, angle=0;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");

	while(!kbhit()) // determines if a key has been pressed
	{
	   cleardevice();
	  //xc1=xc-r; yc1=yc;
	  yc1=yc;
	   //theta=M_PI*angle/180;
	  //xc+=(r1*cos(theta));
	  //yc+=(r1*sin(theta));
	   xc1=(xc-r)+cos(M_PI/6+angle);
	//   yc1+=(yc)+sin(M_PI/6+angle);
		//yc1=yc;
	   draw_circle(xc, yc, r);
	   draw_circle(xc1, yc1, r);
	   /*draw_circle(xc-r, yc, r);
	  draw_circle(xc+r, yc, r);
	   draw_circle(xc, yc+r, r);*/


	   angle+=20;
	   delay(100);
	}
	getch();
	closegraph();
}
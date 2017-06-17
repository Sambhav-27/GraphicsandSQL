
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>

void plotpixel(int x, int y, int xc, int yc, int m)
{



	putpixel(xc+x, yc+y, WHITE);
 putpixel(xc+x, yc-y, 15);
 //int x1= (2*m*y +(1-m*m)*x)/(1+m*m);
// int y1= ((m*m-1)*y + 2*m*x)/(1+m*m);
// putpixel(xc+x1, yc+y1, CYAN);
}

void draw_parabola(int xc, int yc, int p)
{


		int d,x,y,x1,y1;
		double theta, angle, m=1;
		x=0; y=0;
		d=2*(p-1);
		angle=45;
		plotpixel(x, y, xc, yc, m);
while(!kbhit())
{                y=0; x=0;
		d=2*(p-1);
			clearviewport();
		while(y<=p)
		{
			if(d<=0)
			{
				d+=( 4*p -6 -4*y);
				x++;
			}
			else
			d+=( -6 -4*y);
			y++;

			theta=M_PI*angle/180;
			 x1= x*cos(theta) + y*sin(theta);
			y1= -x*sin(theta) + y*cos(theta);



			plotpixel(x1, y1, xc, yc, m);
		}


			x=p/2; y=p;
		d= 4*p*p -2*p -1;
		angle=90;
		while(x<=p)
		{
			if(d<=0)
			d+=(4*p);
			else
			{
				d+=( 4*p -4 -4*y);
				y++;
			}
			x++;
		   theta=M_PI*angle/180;
		  x1= x*cos(theta) + y*sin(theta);
		  y1= -x*sin(theta) + y*cos(theta);


			plotpixel(x1, y1, xc, yc,m);
		}
	 angle+=10;
		delay(500);
		if(angle>70)
			angle=45;
}
}

int main(void)
{

   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

   initgraph(&gdriver, &gmode, "..\\bgi");
   errorcode = graphresult();

   if (errorcode != grOk)
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);
   }



   draw_parabola(320, 240, 80);



	getch();
   closegraph();
   return 0;
}

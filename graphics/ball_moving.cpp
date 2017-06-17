#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
using namespace std;
void plotpixel(int x, int y, int xc, int yc)
{
	putpixel(xc+x, yc+y, 15);
	putpixel(xc+x, yc-y, 15);
	putpixel(xc-x, yc+y, 15);
	putpixel(xc-x, yc-y, 15);
}

void bresenham_hyperbola(int xc, int yc, int a, int b)
{
       int x,y,d;
	   x=a; y=0;
	   d= 2*a*a - b*b - 2*a*b*b;
	   plotpixel(x,y,xc,yc);
	   while((a*a*y)<=(b*b*x))
	   {
			if(d<=0)
			d+= 2*a*a*(3+2*y);
			else
			{
				d+=2*a*a*(3+2*y) - b*b*(4+4*x);
				x++;
			}
			y++;
			plotpixel(x, y, xc, yc);
	   }

	   d = a*a*(y+1)*(y+1) + a*a*y*y + 2*a*a*b*b - 2*a*a*b*b*(x+1)*(x+1);
	   plotpixel(x,y,xc,yc);
	   while(y<220)
	   {
			if(d>=0)
			d+= -2.0*b*b*(2*x+3);
			else
			{
				d+= a*a*4*(y+1) - 2-b*b*(2*x+3);
				y++;
			}
			x++;
			plotpixel(x, y, xc, yc);
	   }



}



int main(void)
{

    initwindow(1080, 640, "Window");
    bresenham_hyperbola(320, 240, 40, 39);

    bresenham_hyperbola(300, 240, 40, 39);


    getch();
    closegraph();
    return 0;
}

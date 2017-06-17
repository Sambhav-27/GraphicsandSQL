#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>

void plotpixel(int x, int y, int xc, int yc)
{
	putpixel(xc+x, yc+y, 15);
	putpixel(xc+x, yc-y, 15);
}

void draw_parabola(int xc, int yc, int p)
{
		int d,x,y,x1,y1;
		x=0; y=0;
		d=2*(p-1);
		plotpixel(x, y, xc, yc);
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
			plotpixel(x, y, xc, yc);
		}

		x=p/2; y=p;
		d= 4*p*p -2*p -1;
		while(x<=2*p)
		{
			if(d<=0)
			d+=(4*p);
			else
			{
				d+=( 4*p -4 -4*y);
				y++;
			}
			x++;
	  		plotpixel(x, y, xc, yc);
		}
}


int main(void)
{

    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "..\\bgi");

    draw_parabola(320, 240, 80);

    getch();
    closegraph();
    return 0;
}

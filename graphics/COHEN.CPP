#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int xmin=100, xmax=300, ymin=100, ymax=300;
struct point{
	int x,y;
};
#define LEFT 0x1
#define RIGHT 0x2
#define BOTTOM 0x4
#define TOP 0x8

#define inside(a) (!a)
#define reject(a, b) (a&b)
#define accept(a, b) (!(a|b))

char encode(point p)
{
	char code=0x00;

	if(p.x < xmin)
	code|= LEFT;
	if(p.x > xmax)
	code|= RIGHT;
	if(p.y <ymin)
	code|= BOTTOM;
	if(p.y > ymax)
	code|= TOP;

	return code;
}


void clip(point p1, point p2)
{
	char code1, code2;
	int done=0, draw= 0;
	double m;
	while(!done)
	{
		code1=encode(p1);
		code2=encode(p2);

		if(accept(code1, code2))
		{
			done =draw =1;
		}
		else if(reject(code1, code2))
		done =1;
		else
		{
			if(inside(code1))
			{
				swap(p1, p2);
				swap(code1, code2);
			}
			if(p2.x!=p1.x)
			m=(p2.y - p1.y)/(p2.x - p1.x);

			if(code1 & LEFT)
			{
				p1.y+= (xmin - p1.x)*m;
				p1.x= xmin;
			}
			else if(code1 & RIGHT)
			{
				p1.y+=(xmax - p1.x)*m;
				p1.x= xmax;
			}
			else if(code1 & BOTTOM)
			{
				if(p2.x!=p1.x)
				p1.x+=(ymin - p1.y)/m;
				p1.y=ymin;
			}
			else if(code1 & TOP)
			{
				if(p2.x!=p1.x)
				p1.x+=(ymax - p1.y)/m;
				p1.y= ymax;
			}
		}
	} // end of while
	setcolor(YELLOW);
	if(draw)
	line(p1.x, p1.y, p2.x, p2.y);
}


int main(void)
{
  initwindow(1080, 640, "Window");

   rectangle(xmin, ymin, xmax, ymax);
   setcolor(GREEN);
   line(10,10,400,400);
   point p1, p2;
   p1.x=10; p1.y=10;
   p2.x=400; p2.y=400;
    point q1={200,0}, q2={200,250};
    line(q1.x, q1.y, q2.x, q2.y);
   clip(p1, p2);
   clip(q1, q2);

   getch();
   closegraph();
   return 0;
}

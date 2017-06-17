#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

#define LEFT 0x1
#define BOTTOM 0x2
#define RIGHT 0x4
#define TOP 0x8
using namespace std;
struct point{
	int x,y;
};

int xl,xr,yb,yt;
point p1, p2, pm, pm1, pm2;

int encode(point p)
{
	char code=0x00;

	if(p.x < xl)
	code|= LEFT;
	if(p.x > xr)
	code|= RIGHT;
	if(p.y <yb)
	code|= BOTTOM;
	if(p.y > yt)
	code|= TOP;

	return code;
}

bool isin(point p)
{
    char stcode=0x0;
    char c= encode(p);

    return ( ((stcode & c)==0) && ((stcode | c)==0) ) ;
}

int dist(point p1, point p2)
{
    return max(p1.x-p2.x, p1.y-p2.y);
}

void clip(point p1, point p2)
{

    if(p1.x > p2.x)
    swap(p1, p2);

    char code1=encode(p1);
    char code2=encode(p2);

    if(code1 & code2)  // fully invisible
    return;
    else if( !(code1 & code2) && !(code1 | code2))  // fully visible
    line(p1.x, p1.y, p2.x, p2.y);
    else  // partially visible
    {
        point t;
        t.x= (p1.x + p2.x)/2;
        t.y= (p1.y + p2.y)/2;

        if( (dist(t, p1)>0) || (dist(t, p2)>0) ) // i.e. mid point is not equal to either of p1 or p2
        {
            char codem=encode(t);
            if(isin(t)) // if mid point is inside
            {
                if(isin(p1))
                {
                    line(p1.x, p1.y, t.x, t.y);
                    p1=t;
                    clip(p1, p2);
                }
                else if(isin(p2))
                {
                    line(p2.x, p2.y, t.x, t.y);
                    p2=t;
                    clip(p1, p2);
                }
                else  // mid point is inside and p1 and p2 are outside
                {
                    clip(p1, t);
                    clip(t, p2);
                }
            }
            else  // m.p. is outside
            {
                if(code1 & codem) // m.p. and p1 are in same region
                p1=t;
                else if(code2 & codem)
                p2=t;

                clip(p1, p2);
            }
        }
    }
}

int main(void)
{

   initwindow(1080, 640, "Window");


	xl=100; xr=400; yb=100; yt=300;
	p1.x=80; p1.y=85;
	p2.x=500; p2.y=330;

    rectangle(xl, yt, xr, yb);
    //line(p1.x, p1.y, p2.x, p2.y);

    setcolor(YELLOW);
	clip(p1,p2);

	getch();
	closegraph();
}

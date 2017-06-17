
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<iostream>
using namespace std;

void dda_line(int x1, int y1, int x2, int y2)
{
    int dy,dx,x,y;
    dy=y2-y1; dx=x2-x1;
    if(x2<x1 && y2<y1)
    {
        int t;
        t=x1;
        x1=x2;
        x2=t;
        t=y1;
        y1=y2;
        y2=t;
    }

    x=x1; y=y1;
    if(abs(dy) <= abs(dx))
    {
        while(x<x2)
        {
            putpixel(x, y,15);
            y+=(dy/dx);
            x++;
        }
    }
    else
    {
        while(y<y2)
        {
            putpixel(x,y,15);
            x+=(dx/dy);
            y++;
        }
    }
}
void mp_line(int x1, int y1, int x2, int y2)
{
    int dx,dy,x,y,d;
    if(x2<x1 && y2<y1)
    {
        int t;
        t=x1;
        x1=x2;
        x2=t;
        t=y1;
        y1=y2;
        y2=t;
    }
    dx=x2-x1; dy=y2-y1;
    x=x1; y=y1;
    d=dy-dx/2;
    putpixel(x,y,15);
    if(abs(dy)<=abs(dx))
    {
        while(x<=x2)
        {
            if(d<0)
                d+=dy;
            else
            {
                d+=(dy-dx);
                y++;
            }
            x++;
            putpixel(x,y,15);
        }
    }
    else
    {
        d=dy-2*dx;
        while(y<=y2)
        {
            if(d<0)
                d+=2*(dy-dx);
            else
            {
                d+=-2*dx;
                x++;
            }
            y++;
            putpixel(x,y,15);
        }
    }
}
int main(void)
{

    int gdriver = DETECT;
    initwindow(1080,640,"Window");


    //dda_line(100,100, 00, 00);
   dda_line(400,400,-10,-10);
   //dda_line(0,200,200,0);
   //dda_line(200,10,400,10);
   //dda_line(-200,10,400,10);

   //mp_line(0,0,100,100);
   //mp_line(100,100,0,0);
    //mp_line(0,200,200,0);
   //mp_line(200,10,400,10);
   //mp_line(-200,10,400,10);




   getch();
   closegraph();
   return 0;
}

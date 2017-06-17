#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
using namespace std;
int a[500],b[500],c[500],d[500],k1,k2;
void plotpixel(int x, int y, int xc, int yc)
{
	putpixel(xc+x, yc+y, 15);
	putpixel(xc+x, yc-y, 15);
	putpixel(xc-x, yc+y, 15);
	putpixel(xc-x, yc-y, 15);
}
void plotpixel2(int x, int y, int xc, int yc)
{
	//putpixel(xc+x, yc+y, 11);
	a[k1]=xc+x; b[k1++]=yc+y;
	//putpixel(xc+x, yc-y, 11);
	c[k2]=xc+x; d[k2++]=yc-y;
	//putpixel(xc-x, yc+y, 15);
	//putpixel(xc-x, yc-y, 15);
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

void ball2(int xc, int yc, int a, int b)
{
       int x,y,d;
	   x=a; y=0;
	   d= 2*a*a - b*b - 2*a*b*b;
	   plotpixel2(x,y,xc,yc);
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
			plotpixel2(x, y, xc, yc);
	   }

	   d = a*a*(y+1)*(y+1) + a*a*y*y + 2*a*a*b*b - 2*a*a*b*b*(x+1)*(x+1);
	   plotpixel2(x,y,xc,yc);
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
			plotpixel2(x, y, xc, yc);
	   }
}

void draw()
{
    int i,j,r=10;float theta,angle=0,ang=0;
    for(i=k1-2;i>=0;--i)
    {
        int xc=a[i], yc=b[i],x,y;

          circle(xc,yc, r);
                for(j=0;j<2;j++)
                {
                    theta=M_PI*angle/180;
                    x=xc+r*cos(theta);
                    y=yc+r*sin(theta);
                    angle+=180+ang;
                    line(xc,yc,x,y);
//delay(60);
                }
        setcolor(BLACK);
        delay(30);
        circle(xc,yc, r);
        angle=0;
        /*for(j=0;j<2;j++)
        {
            theta=M_PI*angle/180;
            x=xc+r*cos(theta);
            y=yc+r*sin(theta);
            angle+=180+ang;
            line(xc,yc,x,y);
            getch();
        }*/
        setcolor(15);
        ang+=30;
    }
    /*for(i=0;i<k2-2;++i)
    {

        //cleardevice();

        circle(c[i],d[i], 10);
        setcolor(BLACK);
        delay(10);
        circle(c[i],d[i], 10);
        setcolor(15);
    }*/
}
int main(void)
{

    initwindow(1080, 640, "Window");
    bresenham_hyperbola(320, 240, 40, 39);
    ball2(300,240,40,39);
    draw();

    getch();
    closegraph();
    return 0;
}

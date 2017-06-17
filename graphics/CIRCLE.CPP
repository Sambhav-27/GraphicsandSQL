
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

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
void mp_circle(int xc,int yc, int r)
{
    int x=0,y=r; int d=5/4-r;
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

void mp_circle2(int xc, int yc, int r)
{
    int x,y,de,dse,d;
    x=0; y=r; d=5/4-r;
    de=3; dse=5-2*r;
    plotcircle(x, y, xc, yc);
    while(x<=y)
    {
        if(d<=0)
        {
            d+=de;
            de+=2; dse+=2;
        }
        else
        {
            d+=dse;
            de+=2; dse+=4;
            y--;
        }
        x++;
        plotcircle(x, y, xc, yc);
    }

}

void bresenham_circle(int xc,int yc, int r)
{
    int x=0,y=r; int d=3-2*r;
    while(x<=y)
    {
        if(d<=0)
        {
            d+=2*(3+2*x);
        }
        else
        {
            d+=4*x-4*y-10;
            y--;
        }
        x++;
        plotcircle(x, y, xc, yc);
    }
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	bresenham_circle(100, 100, 100);
	mp_circle(400,120,120);
	mp_circle2(300,340,100);
	getch();
	closegraph();
}

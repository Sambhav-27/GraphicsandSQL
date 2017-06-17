#include<iostream>
#include<math.h>
#include<graphics.h>
#include<stdio.h>
using namespace std;

int main()
{
    initwindow(1080,640);

    int i,j,x2,x1,y1,y2,x,y,xc=300, yc=200, r=100, r2=130;

    int n=8;
    float angle=0;
    while(!kbhit())
    {
        float t=angle*M_PI/180;
        x=xc+r*cos(t);
        y=yc+r*sin(t);
        putpixel(x,y, 15);
        circle(xc, yc, r);
        circle(xc, yc, r2);
        for(i=0;i<n;++i)
        {
            int r=0;
            float t=angle*M_PI/180;
            x1=xc+r*cos(t);
            y1=yc+r*sin(t);
            x2=xc+r2*cos(t);
            y2=yc+r2*sin(t);
            line (x1,y1, x2, y2);
            angle+=(360/n);
        }
        delay(20);
        cleardevice();
        angle+=2;
        //getch();

    }

    getch();
    closegraph();
}


#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>

#include<iostream>
using namespace std;
struct point{
	int x,y;
};


void seed(int x, int y, int fcolor, int bcolor)
{
    int cur=getpixel(x, y);
    if(cur!=bcolor && cur!=fcolor)
    {
        putpixel(x, y, fcolor);
        seed(x,y+1, fcolor, bcolor);
        seed(x+1,y, fcolor, bcolor);
        seed(x-1,y, fcolor, bcolor);
        seed(x,y-1, fcolor, bcolor);

        /*seed(x+1,y+1, fcolor, bcolor);
        seed(x-1,y-1, fcolor, bcolor);
        seed(x+1,y-1, fcolor, bcolor);
        seed(x-1,y+1, fcolor, bcolor);*/
    }
}
int main(void)
{

   initwindow(1080, 640, "Window");

    point p[]={{20,20}, {40,100}, {100,120}, {100,200}, {40,160}, {20,200}, {20,20} };
   // point p[]= { {20,20}, {200,20}, {200,200}, {20,200}, {20,20} };
    //point p[]={ {100,20}, {50,200}, {150,220}, {20,150}, {150,100}, {100,20} };

    int n=sizeof(p)/sizeof(p[0]);
    int i;
	for(i=1;i<n;++i)
	{
		line(p[i-1].x, p[i-1].y, p[i].x, p[i].y);
	}


    circle(300, 300, 100);

    seed(42, 130, 11, 15);

	getch();
   closegraph();
   return 0;
}


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


double Angle2D(double x1, double y1, double x2, double y2)
{
   double dtheta,theta1,theta2;

   theta1 = atan2(y1,x1);
   theta2 = atan2(y2,x2);
   dtheta = theta2 - theta1;
   while (dtheta > M_PI)
      dtheta -= 2*M_PI;
   while (dtheta < -M_PI)
      dtheta += 2*M_PI;

   return(dtheta);
}

bool InsidePolygon(point *polygon, int n, point p)
{
   int i;
   double angle=0;
   point p1,p2;

   for (i=1;i<n;i++) {
      p1.x = polygon[i-1].x - p.x;
      p1.y = polygon[i-1].y - p.y;
      p2.x = polygon[i].x - p.x;
      p2.y = polygon[i].y - p.y;
      angle += Angle2D(p1.x,p1.y,p2.x,p2.y);
   }

   if (abs(angle) < M_PI)
      return 0;
   else
      return 1;
}


void my_fill(point p[], int n)
{
    int i,j,xmin, xmax, ymin, ymax;
    xmin=xmax=p[0].x;
    ymin=ymax=p[0].y;

    for(i=0;i<n-1;++i)
    {
        xmin=min(xmin, p[i].x);
        xmax=max(xmax, p[i].x);
        ymin=min(ymin, p[i].y);
        ymax=max(ymax, p[i].y);
    }
    //cout<<xmin<<" " <<xmax<<" "<<ymin<<" "<<ymax;
    point p1;
    for(i=xmin;i<=xmax;++i)
    {
        for(j=ymin;j<=ymax;++j)
        {
            p1.x=i; p1.y=j;
             if(InsidePolygon(p, n, p1))
             {
                delay(0) ;
                putpixel(i, j, 11);
             }

        }
    }
}

int main(void)
{

   initwindow(1080, 640, "Window");

    //point p[]={{20,20}, {40,100}, {100,120}, {100,200}, {40,160}, {20,200}, {20,20} };
    //point p[]= { {20,20}, {200,20}, {200,200}, {20,200}, {20,20} };
    point p[]={ {100,20}, {50,200}, {150,220}, {20,150}, {150,100}, {100,20} };

    int n=sizeof(p)/sizeof(p[0]);
    int i;
	for(i=1;i<n;++i)
	{
		line(p[i-1].x, p[i-1].y, p[i].x, p[i].y);
	}



    my_fill(p, n);

	getch();
   closegraph();
   return 0;
}

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct point{
	int x,y;
}p1,p2;

//p1.x=-1; p1.y=9;
//p2.x=12; p2.y=10;
int main(void)
{
	p1.x=-1; p1.y=9;
	p2.x=121; p2.y=101;
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   initgraph(&gdriver, &gmode, "..\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);
   }

   point p;
   double t=0;
   while(t<1)
   {
	  p.x= p1.x +(p2.x-p1.x)*t;
	  p.y= p1.y +(p2.y-p1.y)*t;
	  putpixel(p.x, p.y, RED);

	  t+=0.001;
   }
   getch();

   getch();
   closegraph();
   return 0;
}
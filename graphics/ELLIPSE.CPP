
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<conio.h>




void plotellipse(int x, int y, int xc, int yc)
{
	putpixel(xc+x, yc-y, WHITE);
	putpixel(xc+x, yc+y, WHITE);
	putpixel(xc-x, yc-y, WHITE);
	putpixel(xc-x, yc+y, WHITE);
}
void mp_ellipse(int xc, int yc, int a, int b)
{
       int x,y,d;
	   x=0; y=b;
	   d=b*b + (a*a)/4 - a*a*b;
	   plotellipse(x,y,xc,yc);
	   while(x<= (a*a)/(b*b)*y)
	   {
			if(d<=0)
			d+=(b*b*(2*x+3));
			else
			{
				d+=( (b*b*(3+2*x)) + (a*a*2*(1-y)) );
				y--;
			}
			x++;
			plotellipse(x, y, xc, yc);
	   }


	   y=0; x=a;
	   d= a*a + (1/4 -a)*b*b;
	   plotellipse(x,y,xc,yc);
	   while((a*a*y)<= (b*b*x))
	   {
		  if(d<=0)
		  {
		      d+= (3+2*y)*a*a;
		  }
		  else
		  {
			d+= (3+2*y)*a*a + (2-2*x)*b*b;
			x--;
		  }
		  y++;
		  plotellipse(x,y,xc,yc);
	   }
}
void bresenham_ellipse(int xc, int yc, int a, int b)
{
       int x,y,d;
	   x=0; y=b;
	   d= a*a + 2*b*b -2*a*a*b;
	   plotellipse(x,y,xc,yc);
	   while(x<= (a*a)/(b*b)*y)
	   {
			if(d<=0)
			d+= 2*b*b*(3+2*x);
			else
			{
				d+=2*b*b*(3+2*x) + a*a*(4-4*y);
				y--;
			}
			x++;
			plotellipse(x, y, xc, yc);
	   }


	   y=0; x=a;
	   d= 2*a*a + b*b - 2*a*b*b;
	   plotellipse(x,y,xc,yc);
	   while((a*a*y)<= (b*b*x))
	   {
		  if(d<=0)
		  {
		      d+= 2*a*a*(3+2*y);
		  }
		  else
		  {
			d+= 2*a*a*(3+2*y) + b*b*(4-4*x);
			x--;
		  }
		  y++;
		  plotellipse(x,y,xc,yc);
	   }
}



int main(void)
{
   initwindow(1080, 640, "Window");

   mp_ellipse(320, 240, 80,40);
  bresenham_ellipse(620, 440, 80,40);
	getch();
   closegraph();
   return 0;
}

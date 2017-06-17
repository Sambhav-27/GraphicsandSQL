
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream.h>
#include<conio.h>

int px1[250], py1[250];
int px2[250], py2[250];
int k1=0, k2=0;
void plotpixel(int x, int y, int xc, int yc)
{
	putpixel(xc+x, yc-y, GREEN);
	px1[k1]=xc+x;
	py1[k1++]=yc-y;
	putpixel(xc-x, yc-y, 15);
	px2[k2]=xc-x;
	py2[k2++]=yc-y;

 }

void draw_parabola(int xc, int yc, int p)
{

//while(!kbhit())
 //{
	   //	clearviewport();
		int d,x,y,x1,y1;
		x=0; y=0;
		d=1-p;
		plotpixel(x, y, xc, yc);


		while(x<=p)
		{
			if(d>0)
			{
				d+=(3+2*x-2*p);
				y++;
			}
			else
			d+=( 3+2*x);
			x++;
			plotpixel(x, y, xc, yc);

		}

			x=p; y=p/2;
		d= 1/4 -p;

		while(y<=80)
		{
			if(d>0)
			d+=(-2*p);
			else
			{
				d+=( 2+2*x-2*p);
				x++;
			}
			y++;

			plotpixel(x, y, xc, yc);
		}
//  }
}
void rotate_ball()
{
	int i;
	while(!kbhit())
	{



	for(i=10;i<k1-10;++i)
	{
		circle(px1[i]-10, py1[i]-10, 10);
		delay(10);
	   setcolor(BLACK);
	   circle(px1[i]-10, py1[i]-10, 10);
	   setcolor(WHITE);
	}
	for(i=k1-10;i>10;--i)
	{
		circle(px1[i]-10, py1[i]-10, 10);
		delay(10);
	   setcolor(BLACK);
	   circle(px1[i]-10, py1[i]-10, 10);
	   setcolor(WHITE);
	}

	for(i=5;i<k2-10;++i)
	{
		circle(px2[i]-20, py2[i]-20, 10);
		delay(10);
	   setcolor(BLACK);
	   circle(px2[i]-20, py2[i]-20, 10);
	   setcolor(WHITE);
	}

	for(i=k2-10;i>5 ;--i)
	{
		circle(px2[i]-20, py2[i]-20, 10);
		delay(10);
	   setcolor(BLACK);
	   circle(px2[i]-20, py2[i]-20, 10);
	   setcolor(WHITE);
	}

 }
}


int main(void)
{

   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

   initgraph(&gdriver, &gmode, "..\\bgi");
   errorcode = graphresult();

   if (errorcode != grOk)
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1);
   }
	int a=1;

	 int p=80;
// while(!kbhit())
  {

		clearviewport();


		 draw_parabola(320, 240, p);
		 rotate_ball();
		 delay(10);
		p+=a;
   if(p >100)
   a=-1;
   if(p<40)
   a=1;

}

	getch();
   closegraph();
   return 0;
}
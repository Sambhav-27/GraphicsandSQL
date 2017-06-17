
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<conio.h>
#include"scircle.h"


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

	int xc=320,yc=240;
	int r1,r2,r3,r4;
	int xc1,yc1;
	r1=70;r2=120; r3=150;

   int i,x1,x2,y1,y2;
   double theta, angle;
   angle=0;
   r4=80;
   int flag=0;
    while(!kbhit())
   {
	 //	cleardevice();
	 delay(200);
	 clearviewport();

   draw_circle(xc,yc,r1);
   draw_circle(xc,yc,r2);
   draw_circle(xc,yc,r3);
		for(i=0;i<8;i++)
		{
				theta=M_PI*angle/180;

				x1=xc+r2*cos(theta);
				y1=yc+r2*sin(theta);

				x2=xc+r3*cos(theta);
				y2=yc+r3*sin(theta);

			   xc1=xc+r1*cos(theta);
			   yc1=yc+r1*sin(theta);


				angle+=45;  // dist b/w spokes; 360/ no of spokes
				line(x1,y1,x2,y2);

			  draw_circle(xc1,yc1,r2-r1);
		}


		r1-=1; r2-=2; r3-=2;


/*		if(r1<20 || r2<20 || r3<20)
		{
			r1+=2; r2+=2; r3+=2;
		}
		 if(r1>70 || r2>120 || r3>150)
		{
			r1-=2; r2-=2; r3-=2;
		}                         */
		angle+=1;

   }

   getch();
   closegraph();
   return 0;
}

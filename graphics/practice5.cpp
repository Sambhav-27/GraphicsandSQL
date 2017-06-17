#include<iostream>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
using namespace std;

//function prototype for DDA line function
void dda_line(int x1,int x2,int y1,int y2);

int main()

{

   int x1,x2,y1,y2,gd,gm;

   //clrscr();

   cout<<"\nEnter the First point (x1,y1) :";
   cin>>x1>>y1;

   cout<<"\nEnter the Second point (x2,y2) :";
   cin>>x2>>y2;

   detectgraph(&gd,&gm);
   initgraph(&gd,&gm,"C:\\turboc3\\bgi");

   setcolor(10);

//drawing the co-ordinate axes
   line(0,240,640,240);
   line(320,0,320,480);

   setcolor(5);

   //converting the screen co-ordinates to more user friendly co-ordinates
   // with respect to the centre of the screen.
   x1 = 320 + x1;
   x2 = 320 + x2;

   y1 = 240 - y1;
   y2 = 240 - y2;

   //function call to draw the dashed-dotted line.
   dda_line(x1,x2,y1,y2);

   getch();
    return 0;

}

/*
Function Definition for DDA line(dashed-dotted)

Function: dda_line() Draws the dashed-dotted line using DDA algorithm.
Input: Takes four input
       1) x co-ordinate for 1st point
	   2) y co-ordinate for 1st point
	   3) x co-ordinate for 2nd point
	   4) y co-ordinate for 2nd point

Return : This function does not return anything.

*/

void dda_line(int x1,int x2,int y1,int y2)
{

    float dx,dy,len,x,y,xi,yi;

   int i;

   dx = abs(x2-x1);

   dy = abs(y2-y1);



   if(dx>=dy)

      len=dx;

	  else

	  len=dy;



   dx = (x2-x1)/len;

   dy = (y2-y1)/len;



   x = x1 + 0.5;

   y = y1 + 0.5;

   putpixel(x1,y1,3);

   putpixel(x2,y2,3);

   for(i=0;i<=len;i++)

    {  if(i%9<2)

	    {}

       else if(i%9<6)

       putpixel(x,y,3);

       else if(i%9==7)

       {}

       else

       putpixel(x,y,3);

       x += dx;

       y += dy;

    }

}


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

int check(int a1, int b1, int c1, point p1, point p2) // check if two point lie on same side of a line
{
	int x1,x2;
	x1= (a1*p1.x + b1*p1.y - c1);
	x2= (a1*p2.x + b1*p2.y - c1);

	if((x1>0 && x2>0) || (x1<0 && x2<0))
	return 1;
	else
	return 0;
}
point intersect(point v1, point v2, point p1, point p2) // returns -1,-1 if doesn't intersect
{
	point inter;
	int a1,b1,c1, a2,b2,c2;
	a1= v2.y-v1.y;
	b1= v1.x-v2.x;
	c1= a1*v1.x+b1*v1.y;

	a2= p2.y-p1.y;
	b2= p1.x-p2.x;
	c2= a2*p1.x+b2*p1.y;

	int flag=check(a1, b1, c1, p1, p2);
	if(flag)
	{
		inter.x=-1; inter.y=-1;
		return inter;
	}

	double det= a1*b2 - a2*b1;
	if(det==0)
	{
		inter.x=-1; inter.y=-1;
	}
	else
	{
		inter.x= (b2*c1 - b1*c2)/det;
		inter.y= (a1*c2 - a2*c1)/det;
	}

	return inter;
}

bool simple_complex(point p[], int n)
{
    int i, j;
    point  temp;
    bool flag=1;
    for(i=1;i<n;++i)

    {
        for(j=1;j<i;++j)

        {
            temp=intersect(p[i], p[i-1], p[j], p[j-1]);
            if(temp.x!=-1 && temp.y!=-1 && temp.x!=p[i-1].x && temp.y!=p[i-1].y && temp.x!=p[i].x && temp.y!=p[i].y)
            {           // later 2 conditions in above line are to avoid starting and end being taken as intersection point
                cout<<temp.x<<", "<<temp.y<<"  ";
                flag= 0;
            }

        }
    }
    return flag;
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

    point p[]={ {100,20}, {50,200}, {150,220}, {20,150}, {150,100}, {100,20} };
    int n=sizeof(p)/sizeof(p[0]);

    int i;
    for(i=1;i<n;++i)
	{
		line(p[i-1].x, p[i-1].y, p[i].x, p[i].y);
	}

    if(simple_complex(p, n))
        cout<<"simple";
    else
        cout<<"complex";
	getch();
   closegraph();
   return 0;
}

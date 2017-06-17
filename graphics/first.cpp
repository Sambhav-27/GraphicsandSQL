
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

int xmin=0, xmax=150, ymin=0, ymax=100;
bool inside(point p)
{
	if(p.x>xmin && p.x<xmax && p.y>ymin && p.y<ymax)
	{
		//cout<<"here1";
		return true;
	}

	return false;
}
int concavity(point v[], int n)
{
	int i,j,ans,a1,a2,b1,b2;
	bool flag=0;
	point p1, p2, p3;
	for(i=1;i<n-1;++i)
	{
		p1=v[i];
		p2=v[i-1];
		p3=v[i+1];

		if(inside(p2) && inside(p3) && inside(p1))
		{
			cout<<"here"	;
			return 0;
		}

	}
	return 1;
}
int determine(point v[], int n)
{
	int i,j,ans,a1,a2,b1,b2;
	int ans1[10];
	int k=0;
	point p1, p2, p3;
	for(i=1;i<n-1;++i)
	{
		p1=v[i];
		p2=v[i-1];
		p3=v[i+1];

		a1=p2.x-p1.x; b1=p2.y-p1.y;
		a2=p3.x-p1.x; b2=p3.y-p1.y;

		ans=(a1*b2 - b1*a2);
		//cout<<ans<<"  ";
		ans1[k++]=ans;
	}

	if(ans1[0] >0)
	{
		for(i=1;i<k;++i)
		{
			if(ans1[i]<0)
			return 0;
		}
	}
	else if(ans1[0] <0)
	{
		for(i=1;i<k;++i)
		{
			if(ans1[i]>0)
			return 0;
		}
	}


	return 1;
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

	//line(100, 100, 400, 400);

	point p[]={ {0,0}, {150,0}, {150,100}, {0,100}, {0,0}, {150,0} };

	//point v[]={ {110,45}, {165,35}, {170,85}, {100,80}, {160,65}, {110,45}, {165,35} }; // concavity and concave

	//point v[]={ {110,45}, {165,35}, {170,85}, {100,80}, {130,65}, {110,45}, {165,35} };  // no concavitity
	point v[]={ {110,65}, {100, 20},{90,30},{95, -10},{120,-5}, {110, 65},{100,20}};


	int n=sizeof(v)/sizeof(v[0]);
	int i;
	if(determine(v, n))
	cout<<"convex";
	else
	cout<<"concave";
	for(i=1;i<n-1;++i)
	{
		line(v[i-1].x, v[i-1].y, v[i].x, v[i].y);
	}
	for(i=1;i<n-1;++i)
	{
		line(p[i-1].x, p[i-1].y, p[i].x, p[i].y);
	}


cout<<"\n\n";
if(concavity(v, n))
{
	cout<<" concavity";
}
else
cout<<" no concavity";
	getch();
   closegraph();
   return 0;
}

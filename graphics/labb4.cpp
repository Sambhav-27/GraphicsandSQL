
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

   initwindow(1080, 640);




	//line(100, 100, 400, 400);

	//point v[]={ {0,0}, {150,0}, {150,100}, {0,100}, {0,0}, {150,0} };

	//point v[]={ {110,45}, {165,35}, {170,85}, {100,80}, {160,65}, {110,45}, {165,35} }; // concavity and concave

	point v[]={ {110,45}, {165,35}, {170,85}, {100,80}, {130,65}, {110,45}, {165,35} };  // no concavitity
	//point v[]={ {110,65}, {100, 20},{90,30},{95, -10},{120,-5}, {110, 65},{100,20}};


	int n=sizeof(v)/sizeof(v[0]);
	int i;
	if(determine(v, n))
	cout<<"convex";
	else
	cout<<"concave";

	for(i=1;i<n-1;++i)
	line(v[i-1].x, v[i-1].y, v[i].x, v[i].y);





	getch();
   closegraph();
   return 0;
}

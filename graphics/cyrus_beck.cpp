#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<iostream>
#include<algorithm>
#include"cyrus.h"
using namespace std;
/*struct point{
	int x,y;
};*/



int main()
{
    initwindow(1080,640,"Window");

	point p1={50,200}, p2={400,200};
	point q1={250,100}, q2={300,300};
	point p[]={ {100,400}, {350,100},{150,230}, {50,100}};
	int n=sizeof(p)/sizeof(p[0]);


	line(p1.x, p1.y, p2.x, p2.y);
	line(q1.x, q1.y, q2.x, q2.y);
    for(int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        line(p[i].x, p[i].y, p[j].x, p[j].y);
	}
   cyrus_beck(p, n, p1, p2);
    cyrus_beck(p, n, q1, q2);

    getch();
   closegraph();
}

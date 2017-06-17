
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<iostream>
#include<time.h>

#define n1 3
using namespace std;
struct point{
	int x,y;
};
void translate(point *, int,int, int);

float ** mul1(float a[][3], float b[][n1])
{
    int i,j,x,k,n;
    float **p=(float**)calloc(4,sizeof(float*)); // no. of rows
    for(i=0;i<n1;i++)
        p[i]=(float*)calloc(4,sizeof(float)); // no. of col


        for(i=0;i<3;++i)
        {

            for(j=0;j<n1;++j)
            {
                x=0;
                for(k=0;k<3;++k)
                {
                     x+=a[i][k]*b[k][j];
                    p[i][j]=x;
                }

            }
        }


        return p;
}
/*int** mul(int a[][n1],int b[][n1])
{
    int i,j,k;
    int **p=(int**)calloc(4,sizeof(int*)); // no. of rows
    for(i=0;i<n1;i++)
        p[i]=(int*)calloc(4,sizeof(int)); // no. of col


    p[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0]+a[0][2]*b[2][0];
    p[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]+a[0][2]*b[2][1];
    p[0][2]=a[0][0]*b[0][2]+a[0][1]*b[1][2]+a[0][2]*b[2][2];

    p[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0]+a[1][2]*b[2][0];
    p[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1]+a[1][2]*b[2][1];
    p[1][2]=a[1][0]*b[0][2]+a[1][1]*b[1][2]+a[1][2]*b[2][2];

    p[2][0]=a[2][0]*b[0][0]+a[2][1]*b[1][0]+a[2][2]*b[2][0];
    p[2][1]=a[2][0]*b[0][1]+a[2][1]*b[1][1]+a[2][2]*b[2][1];
    p[2][2]=a[2][0]*b[0][2]+a[2][1]*b[1][2]+a[2][2]*b[2][2];


    return p;

}*/

void scale(float **p1, int n, int sx, int sy)
{
    int i,j;
    float a[][3]={sx,0,0,0,sy,0,0,0,1};
    float b[3][n1];
    /*for(i=0;i<n1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=1;
    }*/
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
            b[i][j]=p1[i][j];
    }


    //cout<<"here";
    float **s=mul1(a, b);
    setcolor(10);

    s[0][n-1]=s[0][0];s[1][n-1]=s[1][0]; // for repeating first point


    for(i=0;i<3;++i)
    {
        for(j=0;j<n;++j)
            cout<<b[i][j]<< "  ";
        cout<<"\n\n";
    }
    //translate(, n, -10, -20);

    setcolor(8);
    for(i=1;i<n;++i)
   {
       cout<<"yes ";
		line(s[0][i-1], s[1][i-1], s[0][i], s[1][i]);
   }


}

void translate(point *p,int n, int dx, int dy)
{
    int i,j; // a is 3x3 b is 3xn
    float a[][3]={1,0,dx,0,1,dy,0,0,1};
    //int b[][n1]={1,1,2,2,1,1,1,1,1,1};
    float b[3][n1];
    for(i=0;i<n1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=1;
    }

    float **p1=mul1(a,b);
    setcolor(11);

    p1[0][n-1]=p1[0][0];p1[1][n-1]=p1[1][0]; // for repeating first point


    for(i=0;i<3;++i)
    {
        for(j=0;j<n;++j)
            cout<<p1[i][j]<<"  ";
        cout<<"\n\n";
    }

    for(i=1;i<n;++i)
   {
		line(p1[0][i-1], p1[1][i-1], p1[0][i], p1[1][i]);
   }

    int sx, sy;
    sx+=2;
    sy+=2;
    scale(p1, n, sx, sy);


}
void rotate(point *p, int n, int angle)
{
    int i,j;
    float theta=angle*M_PI/180;
    cout<<"theta : "<<theta;
    float a[3][3]={cos(theta), -sin(theta),0,sin(theta),cos(theta),0,0,0,1};
    float b[3][n1];
    for(i=0;i<n1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=1;
    }


    cout<<"\n\n\n";

    float **p1=mul1(a, b);
    //for(i=0;i<3;++i)
    {
        //for(j=0;j<n;++j)
          //  p1[i][j]*=10;
    }
    /*for(i=0;i<3;++i)
    {
        for(j=0;j<n;++j)
            cout<<p1[i][j]<<"  ";
        cout<<"\n\n";
    }*/
    translate(p, n, 80, 80);

    p1[0][n-1]=p1[0][0];p1[1][n-1]=p1[1][0];

    setcolor(9);
    for(i=1;i<n;++i)
   {
		line(p1[0][i-1], p1[1][i-1], p1[0][i], p1[1][i]);
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


    int i;
   point p[] ={ {100,100},{200,100},{100,200},{100,100}};
   //point p[]={ {100,100},{150,150},{200,100},{150, 50}, {100,100} };
   int n=sizeof(p)/sizeof(p[0]);

   for(i=1;i<n;++i)
   {
		line(p[i-1].x, p[i-1].y, p[i].x, p[i].y);
   }
    int dx=-10,dy=-20;
   //cleardevice();
   //translate(p, n, dx, dy);
    int sx,sy;
    sx=sy=2;
    int angle=30;
    //scale(p, n, sx, sy);

    //rotate(p, n, 30);
    bool flag=1;
    bool flag2=1;
    bool flag3=1;
    bool flag4=1;
    srand(time(NULL));
    int r1=50;
    int xc=200;
    int yc=0;
    int r=100;
    while(!kbhit())
	{
	   cleardevice();
	   double theta=M_PI*angle/180;
	   xc+=(r1*cos(theta));
	   yc+=(r1*sin(theta));
	   //putpixel(xc, yc, 15);
	   translate(p, n, xc, yc);
	   //scale(p, n, sx, sy);

	   angle+=20;
	   delay(100);
	}

   getch();
   closegraph();
   return 0;
}

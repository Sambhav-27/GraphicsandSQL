
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<iostream>
#include<time.h>
#define n 7
using namespace std;
struct point{
	int x,y;
};

void draw(float a[][n], int n1)
{
    for(int i=0;i<n1;i++)
    {
        int j=(i+1)%n1;
        line(a[0][i], a[1][i], a[0][j], a[1][j]);
	}
}
void translate_2d(float a[][n], int n1, int dx, int dy)
{
     float b[][3]={1,0,dx,0,1,dy,0,0,1};
     int i,j,k,x;
     float temp[3][n1];
     for(i=0;i<3;++i)
     {
         for(j=0;j<n1;++j)
         {
             temp[i][j]=0;
             for(k=0;k<3;++k)
             {
                 temp[i][j]+=b[i][k]*a[k][j];
             }
         }
     }

    for(i=0;i<3;++i)
    {
        for(j=0;j<n;++j)
        {
            a[i][j]=temp[i][j];
           // cout<<temp[i][j]<<"  ";
        }
         //cout<<"\n\n";
    }
}
void scale_2d(float a[][n], int n1, float sx, float sy)
{
     float b[][3]={sx,0,0,0,sy,0,0,0,1};
     int i,j,k,x;
     float temp[3][n1];
     for(i=0;i<3;++i)
     {
         for(j=0;j<n1;++j)
         {
             temp[i][j]=0;
             for(k=0;k<3;++k)
             {
                 temp[i][j]+=b[i][k]*a[k][j];
             }
         }
     }

    for(i=0;i<3;++i)
    {
        for(j=0;j<n;++j)
        {
            a[i][j]=temp[i][j];
           // cout<<temp[i][j]<<"  ";
        }
         //cout<<"\n\n";
    }
}
void rotate_2d(float a[][n], int n1, int angle)
{
    int i,j,k,x;
    float temp[3][n1];
    float theta=angle*M_PI/180;
    float b[][3]={cos(theta),-sin(theta),0,  sin(theta),cos(theta),0, 0,0,1};

         for(i=0;i<3;++i)
         {
             for(j=0;j<n1;++j)
             {
                 temp[i][j]=0;
                 for(k=0;k<3;++k)
                 {
                     temp[i][j]+=b[i][k]*a[k][j];

                 }
             }
         }


    for(i=0;i<3;++i)
    {
        for(j=0;j<n;++j)
        a[i][j]=temp[i][j];
    }
}

/*void pattern()
{
    int xc=300,i, yc=300,xc1,yc1,r1=50;
    float angle=0, theta;
    while(!kbhit())
    {
        delay(200);
        cleardevice();

        //circle(xc, yc, r1);
		for(i=0;i<8;i++)
		{
            theta=M_PI*angle/180;
            xc1=xc+r1*cos(theta);
            yc1=yc+r1*sin(theta);


				angle+=45;  // dist b/w spokes; 360/ no of spokes
            putpixel(xc1,yc1,15);
            //circle(xc1,yc1,r1);
		}



		angle+=1;

   }
}*/
void pattern()
{
    int a=100;
    float p[3][n]={a/2,-a/2,-a/2,0,0,0,0,  0,a,-a,0,0,0,0,  1,1,1,1,0,0,0};  // don't forget to provide additional zeros
    int xc=500,i, yc=300,xc1,yc1,r1=150;
    float angle=0, theta;
    while(!kbhit())
    {
        delay(5);
        //getch();
        cleardevice();
        theta=M_PI*angle/180;
        xc1=xc+r1*cos(theta);
        yc1=yc+r1*sin(theta);
        //angle+=45;  // dist b/w spokes; 360/ no of spokes

        scale_2d(p, 4, 0.99, 0.99);
        rotate_2d(p, 4, 90/72);
        translate_2d(p, 4, xc1, yc1);
        draw(p, 4);
        translate_2d(p, 4, -xc1, -yc1);
        putpixel(xc1,yc1,15);
        angle+=1;

        if(angle==270||angle==270*2 || angle==270*3 || angle==270*4)
            scale_2d(p, 4, 17,17);
   }

}

int main(void)
{

   initwindow(1080,640,"Window");
    pattern();

   getch();
   closegraph();
   return 0;
}

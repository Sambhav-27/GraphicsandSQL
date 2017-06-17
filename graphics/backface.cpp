#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<iostream>
#define n 7
using namespace std;
struct point { int x,y,z;};
int a=50;
//point A={-a,a,a},B={a,a,a},C={a,-a,a},D={-a,-a,a},E={-a,a,-a},F={a,a,-a},G={a,-a,-a},H={-a,-a,-a};
float p1[4][n]={-a,a,a,-a,0,0,0,   a,a,-a,-a,0,0,0,  a,a,a,a,0,0,0,  1,1,1,1,0,0,0,};
float p2[4][n]={a,-a,-a,a,0,0,0,   a,a,-a,-a,0,0,0,   -a,-a,-a,-a,0,0,0,   1,1,1,1,0,0,0,};
float p3[4][n]={-a,-a,-a,-a,0,0,0,   a,a,-a,-a,0,0,0,   -a,a,a,-a,0,0,0,  1,1,1,1,0,0,0,};
float p4[4][n]={a,a,a,a,0,0,0,  a,a,-a,-a,0,0,0,  a,-a,-a,a,0,0,0,   1,1,1,1,0,0,0,};
float p5[4][n]={-a,a,a,-a,0,0,0,  a,a,a,a,0,0,0,  -a,-a,a,a,0,0,0,  1,1,1,1,0,0,0,};
float p6[4][n]={-a,a,a,-a,0,0,0,  -a,-a,-a,-a,0,0,0,  a,a,-a,-a,0,0,0,  1,1,1,1,0,0,0,};

float num1[4][n]={10,10,0,0,0,0,0,  30,-30,0,0,0,0,0,  a,a,0,0,0,0,0,  1,1,1,1,1,1,1};
float num2[4][n]={-30,30,30,-30,-30,30,0,  30,30,0,0,-30,-30,0,  -a,-a,-a,-a,-a,-a,0,  1,1,1,1,1,1,1};
float num3[4][n]={-a,-a,-a,-a,-a,-a,-a, 30,30,0,0,0,-30,-30, 30,-30,-30,30,-30,-30,30, 1,1,1,1,1,1,1};
float num4[4][n]={a,a,a,a,a,0,0,  -30,30,0,0,0,0,0, -10,-10,30,-30,-30,0,0,  1,1,1,1,1,1,1};
float num5[4][n]={30,-30,-30,30,30,-30,0,  a,a,a,a,a,a,a, 30,30,0,0,-30,-30,0, 1,1,1,1,1,1,1};
float num6[4][n]={30,-30,-30,30,30,-30,0,  -a,-a,-a,-a,-a,-a,-a,  30,30,-30,-30,0,0,0,  1,1,1,1,1,1,1};


bool visible(float p[4][n], int n1, int pos)
{
    point cen,p1,p2,p3;
    cen.x=(p[0][0]+p[0][1]+p[0][2]+p[0][3])/4;
    cen.y=(p[1][0]+p[1][1]+p[1][2]+p[1][3])/4;
    cen.z=(p[2][0]+p[2][1]+p[2][2]+p[2][3])/4;
    if(pos==1)
    {
        cen.x-=100; cen.y-=100; cen.z-=640;
    }
    else if(pos==2)
    {
        cen.x-=-640; cen.y-=300; cen.z-=100;
    }
    else if(pos==3)
    {
        cen.x-=500; cen.y-=-460; cen.z-=100;
    }

    //cout<<cen.x<<", "<<cen.y<<", "<<cen.z<<"\n";
    p1.x=p[0][3]-p[0][0];
    p1.y=p[1][3]-p[1][0];
    p1.z=p[2][3]-p[2][0];
    p2.x=p[0][1]-p[0][0];
    p2.y=p[1][1]-p[1][0];
    p2.z=p[2][1]-p[2][0];
    p3.x=p1.y*p2.z - p2.y*p1.z;
    p3.y=p1.z*p2.x - p2.z*p1.x;
    p3.z=p1.x*p2.y - p2.x*p1.y;

    return (cen.x*p3.x + p3.y*cen.y + cen.z*p3.z <= 0 );
}

void draw(float a[][n], int n1)
{
    int n2=n1;
    for(int i=0;i<n2;i++)
    {
        int j=(i+1)%n2;
        if(n1!=4 && j==0) continue;
        line(a[0][i], a[1][i], a[0][j], a[1][j]);
	}
}

void draw2(float a[][n], int n1)
{
    for(int i=0;i<n1;i++)
    {
        int j=(i+1)%n1;
        if(n1!=4 && j==0) continue;
        line(a[1][i], a[2][i], a[1][j], a[2][j]);
	}
}
void draw3(float a[][n], int n1)
{
    for(int i=0;i<n1;i++)
    {
        int j=(i+1)%n1;
        if(n1!=4 && j==0) continue;
        line(a[0][i], a[2][i], a[0][j], a[2][j]);
	}
}

void translate(float a[][n], int n1, int dx, int dy, int dz)
{
     float b[][4]={1,0,0,dx, 0,1,0,dy, 0,0,1,dz, 0,0,0,1};
     int i,j,k,x;
     float temp[4][n1];
     for(i=0;i<4;++i)
     {
         for(j=0;j<n1;++j)
         {
             temp[i][j]=0;
             for(k=0;k<4;++k)
             {
                 temp[i][j]+=b[i][k]*a[k][j];
             }
         }
     }

    for(i=0;i<4;++i)
    {
        for(j=0;j<n;++j)
        {
            a[i][j]=temp[i][j];
           // cout<<temp[i][j]<<"  ";
        }
         //cout<<"\n\n";
    }
}

void rotate(float a[][n], int n1, int angle, int opt)
{
    int i,j,k,x;
    float temp[4][n1];
    float theta=angle*M_PI/180;
    float b[4][4]={1,0,0,0,  0,cos(theta),-sin(theta),0,  0,sin(theta),cos(theta),0,  0,0,0,1}; // for x rotation
    float c[4][4]={cos(theta),0,sin(theta),0,  0,1,0,0,  -sin(theta),0,cos(theta),0,  0,0,0,1}; //y
    float d[4][4]={cos(theta), -sin(theta),0,0, sin(theta),cos(theta),0,0, 0,0,1,0,  0,0,0,1}; //z

    if(opt==1)
    {
         for(i=0;i<4;++i)
         {
             for(j=0;j<n1;++j)
             {
                 temp[i][j]=0;
                 for(k=0;k<4;++k)
                 {
                     temp[i][j]+=b[i][k]*a[k][j];

                 }
             }
         }
    }
    else if(opt==2)
    {
        for(i=0;i<4;++i)
         {
             for(j=0;j<n1;++j)
             {
                 temp[i][j]=0;
                 for(k=0;k<4;++k)
                 {
                     temp[i][j]+=c[i][k]*a[k][j];
                 }
             }
         }
    }
    else if(opt==3)
    {
        for(i=0;i<4;++i)
         {
             for(j=0;j<n1;++j)
             {
                 temp[i][j]=0;
                 for(k=0;k<4;++k)
                 {
                     temp[i][j]+=d[i][k]*a[k][j];
                 }
             }
         }
    }

    //cout<<"\n\n\n";
    for(i=0;i<4;++i)
    {
        for(j=0;j<n;++j)
        {
            a[i][j]=temp[i][j];
            //cout<<temp[i][j]<<"  ";
        }
         //cout<<"\n\n";
    }
}

void rotate_z(int k, int angle)
{
    rotate(p1, k, angle, 3);rotate(p2, k, angle, 3);
    rotate(p3, k, angle, 3);rotate(p4, k, angle, 3);
    rotate(p5, k, angle, 3);rotate(p6, k, angle, 3);

    rotate(num1, 2, angle, 3); rotate(num2, 6, angle, 3);
    rotate(num3, 7, angle, 3); rotate(num4, 5, angle, 3);
    rotate(num5, 6, angle, 3); rotate(num6, 6, angle, 3);
}
void rotate_y(int k, int angle)
{
    rotate(p1, k, angle, 2);rotate(p2, k, angle, 2);
    rotate(p3, k, angle, 2);rotate(p4, k, angle, 2);
    rotate(p5, k, angle, 2);rotate(p6, k, angle, 2);

    rotate(num1, 2, angle, 2); rotate(num2, 6, angle, 2);
    rotate(num3, 7, angle, 2); rotate(num4, 5, angle, 2);
    rotate(num5, 6, angle, 2); rotate(num6, 6, angle, 2);
}
void rotate_x(int k, int angle)
{
    rotate(p1, k, angle, 1);rotate(p2, k, angle, 1);
    rotate(p3, k, angle, 1);rotate(p4, k, angle, 1);
    rotate(p5, k, angle, 1);rotate(p6, k, angle, 1);

    rotate(num1, 2, angle, 1); rotate(num2, 6, angle, 1);
    rotate(num3, 7, angle, 1); rotate(num4, 5, angle, 1);
    rotate(num5, 6, angle, 1); rotate(num6, 6, angle, 1);
}
void trans_plus(int k, int dx, int dy, int dz)
{
        translate(p1, k, dx, dy, dz);translate(p2, k, dx, dy, dz);
        translate(p3, k, dx, dy, dz);translate(p4, k, dx, dy, dz);
        translate(p5, k, dx, dy, dz);translate(p6, k, dx, dy, dz);

        translate(num1, 2, dx, dy, dz); translate(num2, 6, dx, dy, dz);
        translate(num3, 7, dx, dy, dz); translate(num4, 5, dx, dy, dz);
        translate(num5, 6, dx, dy, dz); translate(num6, 6, dx, dy, dz);
}
void trans_neg(int k, int dx, int dy, int dz)
{
    translate(p1, k, -dx, -dy, -dz);translate(p2, k, -dx, -dy, -dz);
    translate(p3, k, -dx, -dy, -dz);translate(p4, k, -dx, -dy, -dz);
    translate(p5, k, -dx, -dy, -dz);translate(p6, k, -dx, -dy, -dz);

    translate(num1, 2, -dx, -dy, -dz); translate(num2, 6, -dx, -dy, -dz);
    translate(num3, 7, -dx, -dy, -dz); translate(num4, 5, -dx, -dy, -dz);
    translate(num5, 6, -dx, -dy, -dz); translate(num6, 6, -dx, -dy, -dz);
}



void draw_cube()
{
    int k=4,dx=100,dy=100,dz=100,angle=0;

    while(1)
    {
        getch();
        cleardevice();


        rotate_x(k, angle);
        rotate_y(k, angle);
        rotate_z(k, angle);
        trans_plus(k, dx, dy, dz);

        if(visible(p1, k, 1))
        {
            draw(p1, k); draw(num1, 2); cout<<"1 ";
        }

        if(visible(p2, k, 1))
        {
            draw(p2, k); draw(num2, 6); cout<<"2 ";
        }

        if(visible(p3, k, 1))
        {
            draw(p3, k); draw(num3, 7); cout<<"3 ";
        }

        if(visible(p4, k, 1))
        {
            draw(p4, k); draw(num4, 5); cout<<"4 ";
        }

        if(visible(p5, k, 1))
        {
             draw(p5, k); draw(num5, 6); cout<<"5 ";
        }

        if(visible(p6, k, 1))
        {
             draw(p6, k); draw(num6, 6); cout<<"6 ";
        }
//----------------------------------------//

        trans_plus(k, 0, dy+200, 0);
        if(visible(p1, k, 2))
        {
            draw2(p1, k); draw2(num1, 2); cout<<"1 ";
        }

        if(visible(p2, k, 2))
        {
            draw2(p2, k); draw2(num2, 6); cout<<"2 ";
        }

        if(visible(p3, k, 2))
        {
            draw2(p3, k); draw2(num3, 7); cout<<"3 ";
        }

        if(visible(p4, k, 2))
        {
            draw2(p4, k); draw2(num4, 5); cout<<"4 ";
        }

        if(visible(p5, k, 2))
        {
             draw2(p5, k); draw2(num5, 6); cout<<"5 ";
        }

        if(visible(p6, k, 2))
        {
             draw2(p6, k); draw2(num6, 6); cout<<"6 ";
        }
        trans_neg(k, 0, dy+200, 0);
//-----------------------------------------------//
        trans_plus(k, dx+400,0, 0);
        if(visible(p1, k, 3))
        {
            draw3(p1, k); draw3(num1, 2); cout<<"1 ";
        }

        if(visible(p2, k, 3))
        {
            draw3(p2, k); draw3(num2, 6); cout<<"2 ";
        }

        if(visible(p3, k, 3))
        {
            draw3(p3, k); draw3(num3, 7); cout<<"3 ";
        }

        if(visible(p4, k, 3))
        {
            draw3(p4, k); draw3(num4, 5); cout<<"4 ";
        }

        if(visible(p5, k, 3))
        {
             draw3(p5, k); draw3(num5, 6); cout<<"5 ";
        }

        if(visible(p6, k, 3))
        {
             draw3(p6, k); draw3(num6, 6); cout<<"6 ";
        }
        trans_neg(k, dx+400,0, 0);

         trans_neg(k, dx, dy, dz);
        angle+=2;
        delay(300);
    }

}
int main(void)
{

    int gdriver = DETECT;
    initwindow(1080,640,"Window");

    draw_cube();

   getch();
   closegraph();
   return 0;
}

#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define n1 4
using namespace std;
struct point{
	int x,y;
};
int s1=50,a=100, s2=260, s3=520;
float ** mul(float a[][3], float b[][n1])
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
point * translate(point *p,int n, int dx, int dy)
{
    int i,j,k; // a is 3x3 b is 3xn
    float a[][3]={1,0,dx,0,1,dy,0,0,1};
    float b[3][n1];
    for(i=0;i<n1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=1;
    }

    float **p1=mul(a,b);
    p1[0][n-1]=p1[0][0];p1[1][n-1]=p1[1][0]; // for repeating first point

    point *ans=(point *)malloc(n*sizeof(point));
    for(i=0;i<n;++i)
   {
       ans[i].x=p1[0][i];
       ans[i].y=p1[1][i];
   }

    return ans;

}
point* rotate(point *p, int n, int angle)
{
  // int dx=(p[0].x+p[1].x)/2;
   //int dy=(p[0].y+p[n-2].y)/2;
   // putpixel(dx, dy, 15);
    int dx=s1+a/2;
    int dy=s1+a/2;
    p= translate(p, n, -dx, -dy);
    int i,j;
    float theta=angle*M_PI/180;
    float a[3][3]={cos(theta), -sin(theta),0,sin(theta),cos(theta),0,0,0,1};
    float b[3][n1];
    for(i=0;i<n1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=1;
    }


    float **p1=mul(a, b);

    for(i=0;i<n;++i)
    {
       p[i].x=p1[0][i];
       p[i].y=p1[1][i];
    }
    p= translate(p, n, dx, dy);
    return p;
}
void partition()
{
    line(213,0,213,480);
   line(426,0,426,480);
   line(0,240,640,240);
}

void front_view(point *p, int n)
{
    int i,y,ymax,ymin;
    ymax=ymin=p[0].y;
    for(i=0;i<n-1;++i)
    {
        y=p[i].y;
        line(s2,y,s2+a,y);
        ymax=max(ymax, y);
        ymin=min(ymin, y);
    }

    line(s2,ymax,s2,ymin);
    line(s2+a,ymax,s2+a,ymin);
}

void top_view(point *p, int n)
{
    int i,y,ymax,ymin;
    ymax=ymin=p[0].y;
    for(i=0;i<n-1;++i)
    {
        y=p[i].y;
        line(s3,y,s3+a,y);
        ymax=max(ymax, y);
        ymin=min(ymin, y);
    }

    line(s3,ymax,s3,ymin);
    line(s3+a,ymax,s3+a,ymin);
}
void side_view(point *p, int n)
{
    int i,j;
    //for(i=1;i<n;++i)
    {
		//line(p[i-1].x, p[i-1].y, p[i].x, p[i].y);
    }

point *p1=(point *)malloc(n*sizeof(point));
int angle=30;

//while(!kbhit())
{
    for(j=0;j<160;++j)
    {
        delay(200);
        cleardevice();
        partition();
        p1=rotate(p, n, angle++);


        for(i=1;i<n;++i)
        line(p1[i-1].x, p1[i-1].y, p1[i].x, p1[i].y);

        front_view(p1, n);
        top_view(p1, n);
    }
}


   // front_view(p, n);

}

/*void cube()
{
    int i,n=5;
     point *p1=(point *)malloc(n*sizeof(point));
    int sx=240, sy=270;
    p1[0]={sx,sy};  p1[1]={sx+a,sy};  p1[2]={sx+a,sy+a};  p1[3]={sx,sy+a};  p1[4]={sx,sy};
     for(i=1;i<n;++i)
    line(p1[i-1].x, p1[i-1].y, p1[i].x, p1[i].y);

    point *p2=(point *)malloc(n*sizeof(point));
    sx=290, sy=320;
    p2[0]={sx,sy};  p2[1]={sx+a,sy};  p2[2]={sx+a,sy+a};  p2[3]={sx,sy+a};  p2[4]={sx,sy};
     for(i=1;i<n;++i)
    line(p2[i-1].x, p2[i-1].y, p2[i].x, p2[i].y);

    point *p3=(point *)malloc(8*sizeof(point));
    p3[0]=p1[0];  p3[1]=p2[0];  p3[2]=p1[1];  p3[3]=p2[1];  p3[4]=p1[2];  p3[5]=p2[2];  p3[6]=p1[3]; p3[7]=p2[3];
    for(i=1;i<8;i+=2)
    line(p3[i-1].x, p3[i-1].y, p3[i].x, p3[i].y);

    //-------------------------------------------------//

        getch();
        //cleardevice();
        p1=rotate(p1, n, 30);
        for(i=1;i<n;++i)
        line(p1[i-1].x, p1[i-1].y, p1[i].x, p1[i].y);

        p2=rotate(p2, n, 30);
        for(i=1;i<n;++i)
        line(p2[i-1].x, p2[i-1].y, p2[i].x, p2[i].y);

        //p3=rotate(p3, n, 30);
        //for(i=1;i<8;i+=2)
        //line(p3[i-1].x, p3[i-1].y, p3[i].x, p3[i].y);

}*/
int main()
{

    int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "..\\bgi");


   int i;

    int n=n1+1;
   point *p=(point *)malloc(n*sizeof(point));
   p[0]={s1,s1}; p[1]={a+s1,s1}; p[2]={a+s1,a+s1}; p[3]={s1,a+s1}; p[4]={s1,s1};
    side_view(p, n);

   //cube();



   getch();
   closegraph();

}

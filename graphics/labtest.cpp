#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#define ll long long int
using namespace std;
struct point{
	int x,y;
};
void dda_line(double x1,double y1,double x2,double y2)
{

    double dy=y2-y1,dx=x2-x1;
    double m=dy/dx;
    if(x1<=x2&&y1<=y2)    // 4th quad
    {
        if(abs(dy)<abs(dx))
        {
            while(x1<=x2)
            {
                putpixel(x1,y1,WHITE);
                y1+=m;
                x1++;
            }
        }
        else
        {
            while(y1<=y2)
            {
                putpixel(x1,y1,WHITE);
                x1+=1/m;
                y1++;
            }
        }

    }
    else if(x1<=x2&&y1>=y2)
    {
        if(abs(dy)<abs(dx))
        {
            while(x1<=x2)
            {
                putpixel(x1,y1,WHITE);
                y1+=m;
                x1++;
            }
        }
        else
        {
            while(y1>=y2)
            {
                putpixel(x1,y1,WHITE);
                x1-=1/m;
                y1--;
            }
        }
    }
    else if(x1>=x2&&y1<=y2)
    {
        if(abs(dy)<abs(dx))
        {
            while(x1>=x2)
            {
                putpixel(x1,y1,WHITE);
                y1-=m;
                x1--;
            }
        }
        else
        {
            while(y1<=y2)
            {
                putpixel(x1,y1,WHITE);
                x1+=1/m;
                y1++;
            }
        }
    }
    else
    {
        if(abs(dy)<abs(dx))
        {
            while(x1>=x2)
            {
                putpixel(x1,y1,WHITE);
                y1-=m;
                x1--;
            }
        }
        else
        {
            while(y1>=y2)
            {
                putpixel(x1,y1,WHITE);
                x1-=1/m;
                y1--;
            }
        }
    }
}

double Angle2D(double x1, double y1, double x2, double y2)
{
   double dtheta,theta1,theta2;

   theta1 = atan2(y1,x1);
   theta2 = atan2(y2,x2);
   dtheta = theta2 - theta1;
   while (dtheta > M_PI)
      dtheta -= 2*M_PI;
   while (dtheta < -M_PI)
      dtheta += 2*M_PI;

   return(dtheta);
}

bool InsidePolygon(point *polygon, int n, point p)
{
   int i;
   double angle=0;
   point p1,p2;

   for (i=1;i<n;i++) {
      p1.x = polygon[i-1].x - p.x;
      p1.y = polygon[i-1].y - p.y;
      p2.x = polygon[i].x - p.x;
      p2.y = polygon[i].y - p.y;
      angle += Angle2D(p1.x,p1.y,p2.x,p2.y);
   }

   if (abs(angle) < M_PI)
      return 0;
   else
      return 1;
}


void my_fill(point p[], int n, int f)
{
    int i,j,xmin, xmax, ymin, ymax;
    xmin=xmax=p[0].x;
    ymin=ymax=p[0].y;

    for(i=0;i<n-1;++i)
    {
        xmin=min(xmin, p[i].x);
        xmax=max(xmax, p[i].x);
        ymin=min(ymin, p[i].y);
        ymax=max(ymax, p[i].y);
    }
    //cout<<xmin<<" " <<xmax<<" "<<ymin<<" "<<ymax;
    point p1;
    for(i=xmin;i<=xmax;++i)
    {
        for(j=ymin;j<=ymax;++j)
        {
            p1.x=i; p1.y=j;
             if(InsidePolygon(p, n, p1))
             {
                delay(0) ;
                putpixel(i, j, f);
             }

        }
    }
}


void index(int comp,int f)
{
    int i,x1,x2,y1,y2;
    x1=400; y1=50; int wid=10;
    int len=5;
    f=f-1;
    char ch='A';
    char text[12]="company ";
    for(i=0;i<comp;++i)
    {
        x2=x1+15; y2=y1+15;
        rectangle(x1, y1, x2, y2);
        point p1[]={ {x1, y1}, {x1+15, y1}, {x1+15, y1+15}, {x1, y1+15}, {x1, y1}};
        f++;
        my_fill(p1, len, f);
        text[8]=ch; text[9]='  ';
        outtextxy(x1,y1+25,text);

       // wid+=30;
       ch++;
       x1+=80;
    }
    cout<<"yes";
}
static int ind=0;

void grid(int comp, int n, int maxd)
{
    int xmax= n*comp*10 + (n-1)*20 +20;
    int xg=xmax/n;
    int y=40, x=0;
    int inc=maxd/10;
    for(y=580-maxd;y<600;y+=inc)
    {
        line(x+10,y, xmax, y);
    }
    y=0;
    char text[6]="200";
    char ch='1';
    for(x=0;x<xmax; x+=xg) //vertical
    {
        line(x+10, 580-maxd, x+10,600);
        text[3]=ch;
        outtextxy(x+20,620,text);
        ch++;


    }
    outtextxy(700,620,"YEAR");
}
int main(void)
{

    initwindow(1080, 640, "Window");
    int n, comp,w=10;
    /*int a[10][10];
    cin>>n>>comp;
    int i, j,k;
    for(i=0;i<n;++i)
    {
        for(j=0;j<comp;++j)
        {
            cin>>a[i][j];
        }
    }*/
    int i,k,j,x=10,y=600;
    //int a[3][2]={30,60,40,80,50,100}; comp=3; n=2;
    //int a[4][4]={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160}; comp=4; n=4;

   //int a[5][6]={10,30,50,40,120,130,450,120,40,100,  110,120,130,140,150,160,170,180,190,200,  300, 290, 280, 270,260,250,240,230,220,210}; comp=5; n=6;
   int a[7][6]={10,30,50,40,120,130,450,120,40,100,  120,110,130,450,120,20,130,70,390,400,210,220,   110,120,130,140,150,160,170,180,190,200,  300, 290, 280, 270,260,250,240,230,220,210}; comp=7; n=6;
  // int a[3][6]={ 10,20,40,30,100,130,430,120,190,200,  110,130,120, 80, 170,390, 560,120}; comp=3; n=6;

    dda_line(10,10,10, 600);
    dda_line(10,600,800,600);
    int count=10;
    int f=2;
    int len;
    point p1[10];k=0;

   int ans=a[0][0];
    for(i=0;i<n;++i)
    {
        for(j=0;j<comp;++j)
        {
            ans=max(ans, a[i][j]);
        }
    }
    cout<<"   "<< ans<< "  ";

    grid(comp, n, ans);
    for(j=0;j<n;++j)
    {
        for(i=0;i<comp;++i)
        {
            int val=a[i][j];
            dda_line(x+count,y, x+count, y-val );
            dda_line(x+count+w,y, x+count+w, y-val);
            dda_line(x+count, y-val, x+count+w, y-val);

            if(ind==0)
            {
                index(comp, f);
                ind++;
            }

            point p1[]={ {x+count, y}, {x+count, y-val}, {x+count+w, y-val}, {x+count+w, y}, {x+count, y}};
            len=5;
            my_fill(p1, len, f);
            x+=10;
            f++;

        }
        x+=20; f=2;

    }

//-----------------------




    getch();
    closegraph();
    return 0;
}

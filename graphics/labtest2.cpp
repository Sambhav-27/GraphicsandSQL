#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#define ll long long int
#define n 7
using namespace std;
 struct Point{
	int x,y;
    };

int a=50;
float p1[4][n]={-a,a,a,-a,0,0,0,   a,a,-a,-a,0,0,0,  a,a,a,a,0,0,0,  1,1,1,1,0,0,0,};
float p2[4][n]={-a,a,a,-a,0,0,0,   a,a,-a,-a,0,0,0,   -a,-a,-a,-a,0,0,0,   1,1,1,1,0,0,0,};
float p3[4][n]={-a,-a,-a,-a,0,0,0,   a,a,-a,-a,0,0,0,   a,-a,-a,a,0,0,0,  1,1,1,1,0,0,0,};
float p4[4][n]={a,a,a,a,0,0,0,  a,a,-a,-a,0,0,0,  a,-a,-a,a,0,0,0,   1,1,1,1,0,0,0,};
float p5[4][n]={-a,-a,a,a,0,0,0,  a,a,a,a,0,0,0,  a,-a,-a,a,0,0,0,  1,1,1,1,0,0,0,};
float p6[4][n]={-a,-a,a,a,0,0,0,  -a,-a,-a,-a,0,0,0,  a,-a,-a,a,0,0,0,  1,1,1,1,0,0,0,};

float num1[4][n]={10,10,0,0,0,0,0,  30,-30,0,0,0,0,0,  a,a,0,0,0,0,0,  1,1,1,1,1,1,1};
float num2[4][n]={-30,30,30,-30,-30,30,0,  30,30,0,0,-30,-30,0,  -a,-a,-a,-a,-a,-a,0,  1,1,1,1,1,1,1};
float num3[4][n]={-a,-a,-a,-a,-a,-a,-a, 30,30,0,0,0,-30,-30, 30,-30,-30,30,-30,-30,30, 1,1,1,1,1,1,1};
float num4[4][n]={a,a,a,a,a,0,0,  -30,30,0,0,0,0,0, -10,-10,30,-30,-30,0,0,  1,1,1,1,1,1,1};
float num5[4][n]={30,-30,-30,30,30,-30,0,  a,a,a,a,a,a,a, 30,30,0,0,-30,-30,0, 1,1,1,1,1,1,1};
float num6[4][n]={30,-30,-30,30,30,-30,0,  -a,-a,-a,-a,-a,-a,-a,  30,30,-30,-30,0,0,0,  1,1,1,1,1,1,1};


void mid_point_line(double x1,double y1,double x2,double y2)
{
   double dy=y2-y1,dx=x2-x1;
   double d;
   if(x1<=x2&&y1<=y2)
   {
       if(abs(dy)<abs(dx))
       {
           d=2*dy-dx;
           while(x1<=x2)
           {
               putpixel(x1,y1,WHITE);
               if(d<0)
               {
                   d+=2*dy;
               }
               else
               {
                   d+=2*(dy-dx);
                   y1++;
               }
               x1++;
           }
       }
       else
       {
           d=dy-2*dx;
           while(y1<=y2)
           {
               putpixel(x1,y1,WHITE);
               if(d>0)
               {
                   d+=-2*dx;
               }
               else
               {
                   d+=2*(dy-dx);
                   x1++;
               }
               y1++;
           }
       }
   }
   else if(x1<=x2&&y1>=y2)
   {
       if(abs(dy)<abs(dx))
       {
           d=2*dy+dx;
           while(x1<=x2)
           {
               putpixel(x1,y1,WHITE);
               if(d>0)
               {
                   d+=2*dy;
               }
               else
               {
                   d+=2*(dy+dx);
                   y1--;
               }
               x1++;
           }
       }
       else
       {
           d=dy+2*dx;
           while(y1>=y2)
           {
               putpixel(x1,y1,WHITE);
               if(d<0)
               {
                   d+=2*dx;
               }
               else
               {
                   d+=2*(dy+dx);
                   x1++;
               }
               y1--;
           }
       }
   }
   else if(x1>=x2&&y1<=y2)
   {
       if(abs(dy)<abs(dx))
       {
           d=-2*dy-dx;
           while(x1>=x2)
           {
               putpixel(x1,y1,WHITE);
               if(d>0)
               {
                   d+=-2*dy;
               }
               else
               {
                   d+=-2*(dy+dx);
                   y1++;
               }
               x1--;
           }
       }
       else
       {
           d=-dy-2*dx;
           while(y1<=y2)
           {
               putpixel(x1,y1,WHITE);
               if(d<0)
               {
                   d+=-2*dx;
               }
               else
               {
                   d+=-2*(dy+dx);
                   x1--;
               }
               y1++;
           }
       }
   }
   else
   {
       if(abs(dy)<abs(dx))
       {
           d=-2*dy+dx;
           while(x1>=x2)
           {
               putpixel(x1,y1,WHITE);
               if(d<0)
               {
                   d+=-2*dy;
               }
               else
               {
                   d+=-2*(dy-dx);
                   y1--;
               }
               x1--;
           }
       }
       else
       {
           d=-dy+2*dx;
           while(y1>=y2)
           {
               putpixel(x1,y1,WHITE);
               if(d>0)
               {
                   d+=2*dx;
               }
               else
               {
                   d+=2*(-dy+dx);
                   x1--;
               }
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

bool InsidePolygon(Point *polygon, int n1, Point p)
{
   int i;
   double angle=0;
   Point p1,p2;

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


void my_fill(Point p[], int n1, int color)
{
    int i,j,xmin, xmax, ymin, ymax;
    xmin=xmax=p[0].x;
    ymin=ymax=p[0].y;

    for(i=0;i<n1-1;++i)
    {
        xmin=min(xmin, p[i].x);
        xmax=max(xmax, p[i].x);
        ymin=min(ymin, p[i].y);
        ymax=max(ymax, p[i].y);
    }
    //cout<<xmin<<" " <<xmax<<" "<<ymin<<" "<<ymax;
    Point p1;
    for(i=xmin+2;i<xmax-1;++i)
    {
        for(j=ymin+2;j<ymax-1;++j)
        {
            p1.x=i; p1.y=j;
             if(InsidePolygon(p, n1, p1))
             {
                delay(0) ;
                putpixel(i, j,color);
             }

        }
    }
}


void seed(int x, int y, int fcolor, int bcolor)
{
    int cur=getpixel(x, y);
    if(cur!=bcolor && cur!=fcolor)
    {
        putpixel(x, y, fcolor);
        seed(x,y+1, fcolor, bcolor);
        seed(x+1,y, fcolor, bcolor);
        seed(x-1,y, fcolor, bcolor);
        seed(x,y-1, fcolor, bcolor);

        /*seed(x+1,y+1, fcolor, bcolor);
        seed(x-1,y-1, fcolor, bcolor);
        seed(x+1,y-1, fcolor, bcolor);
        seed(x-1,y+1, fcolor, bcolor);*/
    }
}
void draw(float a[][n], int n1, int c)
{
    int n2=n1;
    for(int i=0;i<n2;i++)
    {
        int j=(i+1)%n2;
        if(n1!=4 && j==0) continue;
        setcolor(c);
        line(a[0][i], a[1][i], a[0][j], a[1][j]);
	}
	setcolor(15);
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

void trans_plus(int k, int dx, int dy, int dz)
{
        translate(p1, k, dx, dy, dz);translate(p2, k, dx, dy, dz);
        translate(p3, k, dx, dy, dz);translate(p4, k, dx, dy, dz);
        translate(p5, k, dx, dy, dz);translate(p6, k, dx, dy, dz);

        translate(num1, 2, dx, dy, dz);
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

void erase()
{
    int k=4;
    draw(p1, k,0); draw(p2, k, 0); draw(p3, k, 0); draw(p4, k, 0); draw(p5, k, 0); draw(p6, k, 0);
}
void fill()
{

    //Point t1[5]={{p1[0][0],p1[1][0]}, {p1[0][1],p1[1][1]}, {p1[0][2],p1[1][2]}, {p1[0][3],p1[1][3]},{p1[0][0],p1[1][0]}};
   // my_fill(t1, 5, 2);

   /* Point t2[5]={{p2[0][0],p2[1][0]}, {p2[0][1],p2[1][1]}, {p2[0][2],p2[1][2]}, {p2[0][3],p2[1][3]},{p2[0][0],p2[1][0]}};
    my_fill(t2, 5, 3);

    Point t3[5]={{p3[0][0],p3[1][0]}, {p3[0][1],p3[1][1]}, {p3[0][2],p3[1][2]}, {p3[0][3],p3[1][3]},{p3[0][0],p3[1][0]}};
    my_fill(t3, 5, 4);

    Point t4[5]={{p4[0][0],p4[1][0]}, {p4[0][1],p4[1][1]}, {p4[0][2],p4[1][2]}, {p4[0][3],p4[1][3]},{p4[0][0],p4[1][0]}};
    my_fill(t4, 5, 5);

    Point t5[5]={{p5[0][0],p5[1][0]}, {p5[0][1],p5[1][1]}, {p5[0][2],p5[1][2]}, {p5[0][3],p5[1][3]},{p5[0][0],p5[1][0]}};
    my_fill(t5, 5, 6);

    Point t6[5]={{p6[0][0],p6[1][0]}, {p6[0][1],p6[1][1]}, {p6[0][2],p6[1][2]}, {p6[0][3],p6[1][3]},{p6[0][0],p6[1][0]}};
    my_fill(t6, 5, 7);*/

    int x, y,k=4;
    x=(p1[0][0]+p1[0][1]+ p1[0][2]+ p1[0][3])/4;
    y=(p1[1][0]+p1[1][1]+ p1[1][2]+ p1[1][3])/4;
    cout<<x<<"  "<<y;
    erase();
    draw(p1, k,15);
    seed(x, y, 2, 15);
    draw(p1, k,15); draw(p2, k, 15); draw(p3, k, 15); draw(p4, k, 15); draw(p5, k, 15); draw(p6, k, 15);

    x=(p2[0][0]+p2[0][1]+ p2[0][2]+ p2[0][3])/4;
    y=(p2[1][0]+p2[1][1]+ p2[1][2]+ p2[1][3])/4;
    cout<<x<<"  "<<y;
    erase();
    draw(p2, k,15);
    seed(x, y, 3, 15);
    draw(p1, k,15); draw(p2, k, 15); draw(p3, k, 15); draw(p4, k, 15); draw(p5, k, 15); draw(p6, k, 15);


    x=(p3[0][0]+p3[0][1]+ p3[0][2]+ p3[0][3])/4;
    y=(p3[1][0]+p3[1][1]+ p3[1][2]+ p3[1][3])/4;
    cout<<x<<"  "<<y;
    erase();
    draw(p3, k,15);
    seed(x, y, 4, 15);
    draw(p1, k,15); draw(p2, k, 15); draw(p3, k, 15); draw(p4, k, 15); draw(p5, k, 15); draw(p6, k, 15);

     x=(p4[0][0]+p4[0][1]+ p4[0][2]+ p4[0][3])/4;
    y=(p4[1][0]+p4[1][1]+ p4[1][2]+ p4[1][3])/4;
    cout<<x<<"  "<<y;
    erase();
    draw(p4, k,15);
    seed(x, y, 5, 15);
    draw(p1, k,15); draw(p2, k, 15); draw(p3, k, 15); draw(p4, k, 15); draw(p5, k, 15); draw(p6, k, 15);

     x=(p5[0][0]+p5[0][1]+ p5[0][2]+ p5[0][3])/4;
    y=(p5[1][0]+p5[1][1]+ p5[1][2]+ p5[1][3])/4;
    cout<<x<<"  "<<y;
    erase();
    draw(p5, k,15);
    seed(x, y, 6, 15);
    draw(p1, k,15); draw(p2, k, 15); draw(p3, k, 15); draw(p4, k, 15); draw(p5, k, 15); draw(p6, k, 15);

     x=(p6[0][0]+p6[0][1]+ p6[0][2]+ p6[0][3])/4;
    y=(p6[1][0]+p6[1][1]+ p6[1][2]+ p6[1][3])/4;
    cout<<x<<"  "<<y;
    erase();
    draw(p6, k,15);
    seed(x, y, 7, 15);
    draw(p1, k,15); draw(p2, k, 15); draw(p3, k, 15); draw(p4, k, 15); draw(p5, k, 15); draw(p6, k, 15);

}
void draw_cube()
{
    int k=4,dx=100,dy=100,dz=100,angle=0;
   draw(p1, k,15); draw(p2, k, 15); draw(p3, k, 15); draw(p4, k, 15); draw(p5, k, 15); draw(p6, k, 15);

    while(1)
    {
        cleardevice();

        rotate_x(k, angle);
        rotate_y(k, angle);

        trans_plus(k, dx, dy, dz);
        draw(p1, k,15); draw(p2, k, 15); draw(p3, k, 15); draw(p4, k, 15); draw(p5, k, 15); draw(p6, k, 15);
        fill();


         trans_neg(k, dx, dy, dz);
        angle+=2;
        getch();
        //delay(300);
    }

}


int main()
{
    initwindow(1080, 640, "Window");


    draw_cube();
    getch();
    closegraph();
}

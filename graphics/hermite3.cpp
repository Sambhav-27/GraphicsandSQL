#include<iostream>
#include<graphics.h>
#define n 4
using namespace std;
struct point { int x,y,z;};

float p1[4][2]= { {100,100},{100,150}, {150,-50}, {-200,100} };
float p2[4][2]= { {100,150},{150,200}, {100,100}, {100,100} };
float p3[4][2]= { {100,150},{175,150}, {100,0}, {100,0} };
float p4[4][2]= { {175,95},{175,200}, {0,0}, {0,0} };

float p5[4][2]= { {210,100},{210,170}, {0,0}, {0,0} };
float p6[4][2]= { {210,100},{205,115}, {-30,5}, {30,10} };
float p7[4][2]= { {210,160},{210,170}, {-30,5}, {30,10} };
float p8[4][2]= { {210,160},{270,160}, {0,0}, {0,0} };
float p9[4][2]= { {270,95},{270,200}, {0,0}, {0,0} };

float p10[4][2]= { {350,95},{350,200}, {0,0}, {0,0} };
float p11[4][2]= { {350,133},{350,166}, {-200,-40}, {200,-40} };

float p12[4][2]= { {150,95},{190,95}, {0,0}, {0,0} };
float p13[4][2]= { {270,95},{360,95}, {0,0}, {0,0} };

float p14[4][2]= { {175,60},{175,60}, {-70,50}, {-70,-50} };

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

point bulldog(float c[4][2], float t)
{
    float b[4][4]={2,-2,1,1,  -3,3,-2,-1,  0,0,1,0,  1,0,0,0};
    float a[1][4]={ t*t*t, t*t, t, 1};
    int i,j,k;
    float ans[1][2],temp[1][4];
    point A;
    for(i=0;i<1;++i)  // pxq  * qxr ; loop will be like p r q
    {
        for(j=0;j<4;++j)
        {
            temp[i][j]=0;
            for(k=0;k<4;++k)
            {
                temp[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    for(i=0;i<1;++i)
    {
        for(j=0;j<2;++j)
        {
             ans[i][j]=0;
            for(k=0;k<4;++k)
            {
                ans[i][j]+=temp[i][k]*c[k][j];
            }
        }
    }
    A.x=ans[0][0]; A.y=ans[0][1];
    //cout<<ans[0][0].x; cout<<ans[0][0].y; cout<<ans[0][0].z;
    return A;

}

void draw()
{
    float i;
    for(i=0;i<=1;i+=0.01)
    {
        point ans= bulldog(p1, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p2, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p3, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p4, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p5, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p6, i);
        putpixel(ans.x, ans.y, 15);
         ans= bulldog(p7, i);
        putpixel(ans.x, ans.y, 15);
         ans= bulldog(p8, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p9, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p10, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p11, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p12, i);
        //putpixel(ans.x, ans.y, 15);
        ans= bulldog(p13, i);
        //putpixel(ans.x, ans.y, 15);
        ans= bulldog(p14, i);
        //putpixel(ans.x, ans.y, 15);

    }
}

void transpose(float a[4][2], int dx, int dy)
{
    int i,j;
    float temp[3][4]={0};
    /*for(i=0;i<4;++i)
    {
        for(j=0;j<2;++j)
            cout<<a[i][j]<<"  ";
        cout<<"\n";
    }*/
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            temp[i][j]=a[j][i];
        }
    }
    for(i=0;i<4;++i)
    {
        temp[2][i]=1;
    }


    translate_2d(temp, 2, dx,dy);
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            a[j][i]=temp[i][j];
        }
    }
   // cout<<"\n\n";
    /*for(i=0;i<4;++i)
    {
        for(j=0;j<2;++j)
            cout<<a[i][j]<<"  ";
        cout<<"\n";
    }*/
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

void scale(float a[4][2], float sx, float sy, int dx, int dy)
{
    int i,j;//dx,dy;
    float temp[3][4]={0};
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            temp[i][j]=a[j][i];
        }
    }
    for(i=0;i<4;++i)
    {
        temp[2][i]=1;
    }

    //dx=temp[0][0]; dy=temp[1][0];
    //dx=137; dy=150;
    translate_2d(temp, 2, -dx,-dy);
    scale_2d(temp, 4, sx, sy);
    translate_2d(temp, 2, dx,dy);
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            a[j][i]=temp[i][j];
        }
    }

}
void press1()
{
    float sx=2,sy=2;
    int dx=50, dy=0;
    cleardevice();
    scale(p1, sx, sy,137,150); scale(p2, sx, sy,137,150); scale(p3, sx, sy,137,150); scale(p4, sx, sy,137,150);
   // scale(p5, sx, sy,137,150); scale(p6, sx, sy,137,150); scale(p7, sx, sy,137,150); scale(p8, sx, sy,137,150); scale(p9, sx, sy,137,150);
   // scale(p10, sx, sy,137,150); scale(p11, sx, sy,137,150);
    transpose(p5, dx,dy); transpose(p6, dx,dy); transpose(p7,dx, dy); transpose(p8,dx, dy); transpose(p9,dx, dy);
    transpose(p10, dx,dy); transpose(p11, dx,dy);
    draw();
}
void hermite()
{
    int i,s1=20,s2=10;
    draw();

    press1();
    /*for(i=0;i<10;++i)
    {
        delay(100);
        cleardevice();
        transpose(p1, s1,s1); transpose(p2, s1,s1); transpose(p3,s1,s1); transpose(p4,s1,s1);
        transpose(p5, -s2,s1); transpose(p6, -s2,s1); transpose(p7,-s2, s1); transpose(p8,-s2, s1); transpose(p9,-s2, s1);
        transpose(p10, -s2,s1); transpose(p11, -s2,s1);
        draw();

    }*/

}
int main(void)
{
    initwindow(1080,640,"Window");
    hermite();

   getch();
   closegraph();
   return 0;
}

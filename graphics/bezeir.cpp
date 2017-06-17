#include<iostream>
#include<graphics.h>
using namespace std;
struct point { int x,y,z;};
point bulldog(point c[4][1], float t)
{
    float b[4][4]={-1,3,-3,1,  3,-6,3,0, -3,3,0,0, 1,0,0,0};
    float a[1][4]={ t*t*t, t*t, t, 1};
    int i,j,k;
    float temp[1][4];
    point  ans[1][1], A;
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
        for(j=0;j<1;++j)
        {
             ans[i][j].x=0; ans[i][j].y=0; ans[i][j].z=0;
            for(k=0;k<4;++k)
            {
                ans[i][j].x+=temp[i][k]*c[k][j].x;
                ans[i][j].y+=temp[i][k]*c[k][j].y;
                ans[i][j].z+=temp[i][k]*c[k][j].z;
            }
        }
    }
    A.x= ans[0][0].x;   A.y= ans[0][0].y;   A.z= ans[0][0].z;
    //cout<<ans[0][0].x; cout<<ans[0][0].y; cout<<ans[0][0].z;

    return A;

}

void baz()
{


     point p1[4][1]= { {100,100}, {180,100}, {100,150},{100,150} };
     point p2[4][1]= { {100,150}, {0,200}, {00,100},{150,200} };
     point p3[4][1]= { {100,150},{175,150}, {100,0}, {100,0} };
     point p4[4][1]= { {175,95},{175,200}, {0,0}, {0,0} };

     point p5[4][1]= { {210,100},{210,170}, {0,0}, {0,0} };
     point p6[4][1]= { {210,100},{205,115}, {-30,5}, {30,10} };
     point p7[4][1]= { {210,160},{210,170}, {-30,5}, {30,10} };
     point p8[4][1]= { {210,160},{270,160}, {0,0}, {0,0} };
     point p9[4][1]= { {270,95},{270,200}, {0,0}, {0,0} };

     point p10[4][1]= { {350,95},{350,200}, {0,0}, {0,0} };
     point p11[4][1]= { {350,133},{350,166}, {-200,-40}, {200,-40} };

      point p12[4][1]= { {150,95},{190,95}, {0,0}, {0,0} };
       point p13[4][1]= { {270,95},{360,95}, {0,0}, {0,0} };

       point p14[4][1]= { {175,60},{175,60}, {-70,50}, {-70,-50} };


    float i;
    for(i=0;i<=1;i+=0.01)
    {
        point ans= bulldog(p1, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p2, i);
        putpixel(ans.x, ans.y, 15);
        ans= bulldog(p3, i);
       // putpixel(ans.x, ans.y, 15);
        ans= bulldog(p4, i);
       // putpixel(ans.x, ans.y, 15);
        ans= bulldog(p5, i);
       // putpixel(ans.x, ans.y, 15);
        ans= bulldog(p6, i);
       // putpixel(ans.x, ans.y, 15);
         ans= bulldog(p7, i);
       // putpixel(ans.x, ans.y, 15);
         ans= bulldog(p8, i);
        //putpixel(ans.x, ans.y, 15);
        ans= bulldog(p9, i);
       // putpixel(ans.x, ans.y, 15);
        ans= bulldog(p10, i);
        //putpixel(ans.x, ans.y, 15);
        ans= bulldog(p11, i);
        //putpixel(ans.x, ans.y, 15);
        ans= bulldog(p12, i);
        //putpixel(ans.x, ans.y, 15);
        ans= bulldog(p13, i);
        //putpixel(ans.x, ans.y, 15);
        ans= bulldog(p14, i);
        //putpixel(ans.x, ans.y, 15);

    }
}
int main(void)
{
    initwindow(1080,640,"Window");
    baz();

   getch();
   closegraph();
   return 0;
}

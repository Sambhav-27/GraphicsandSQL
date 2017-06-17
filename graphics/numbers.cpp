#include<iostream>
#include<graphics.h>
using namespace std;
struct point { int x,y,z;};
point bulldog(point c[4][1], float t)
{
    float b[4][4]={2,-2,1,1,  -3,3,-2,-1,  0,0,1,0,  1,0,0,0};
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

void hermite()
{


     point p1[4][1]= { {50,50},{50,85}, {150,-50}, {-150,0} };
     point p2[4][1]= { {50,85},{50,120}, {150,-50}, {-150,-50} };
     point p3[4][1]= { {50,120},{70,120}, {30,-30}, {30,30} };
     point p4[4][1]= { {70,120},{90,135}, {30,30}, {30,30} };

     point p5[4][1]= { {140,90},{140,90}, {-170,150}, {-170,-150} };
     point p6[4][1]= { {120,50},{140,90}, {-70,0}, {30,30} };
     point p7[4][1]= { {160,50},{140,90}, {70,5}, {-30,10} };


     point p8[4][1]= { {200,70},{200,70}, {-70,-70}, {-70,70} };
     point p9[4][1]= { {205,65},{195,75}, {-50,50}, {0,0} };
     point p10[4][1]= { {195,75},{210,120}, {50,150}, {0,0} };




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

    }
}
int main(void)
{
    initwindow(1080,640,"Window");
    hermite();

   getch();
   closegraph();
   return 0;
}

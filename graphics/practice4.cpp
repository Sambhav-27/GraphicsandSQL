
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include<iostream>
#include<conio.h>
#include<iostream>
#define n1 4

using namespace std;
struct point{
	int x,y,z;
};

int s1=150,s2=150,a=100, n=n1+1;
point *p1=(point *)malloc(n*sizeof(point));
point *p2=(point *)malloc(n*sizeof(point));
point *p3=(point *)malloc(n*sizeof(point));
point *p4=(point *)malloc(n*sizeof(point));
point *p5=(point *)malloc(n*sizeof(point));
point *p6=(point *)malloc(n*sizeof(point));

point *p7=(point *)malloc(n*sizeof(point));
point *p8=(point *)malloc(n*sizeof(point));
point *p9=(point *)malloc(n*sizeof(point));
point *p10=(point *)malloc(n*sizeof(point));
point *p11=(point *)malloc(n*sizeof(point));
point *p12=(point *)malloc(n*sizeof(point));


point *num1=(point *)malloc(4*sizeof(point));
point *num2=(point *)malloc(7*sizeof(point));
point *num3=(point *)malloc(8*sizeof(point));
point *num4=(point *)malloc(5*sizeof(point));
point *num5=(point *)malloc(7*sizeof(point));
point *num6=(point *)malloc(7*sizeof(point));

point *num7=(point *)malloc(4*sizeof(point));
point *num8=(point *)malloc(7*sizeof(point));
point *num9=(point *)malloc(8*sizeof(point));
point *num10=(point *)malloc(5*sizeof(point));
point *num11=(point *)malloc(7*sizeof(point));
point *num12=(point *)malloc(7*sizeof(point));


float ** mul(float a[][4], float **b, int col)
{
    int i,j,x,k;
    float **p=(float**)calloc(4,sizeof(float*)); // no. of rows
    for(i=0;i<4;i++)
    p[i]=(float*)calloc(col+1,sizeof(float)); // no. of col


        for(i=0;i<4;++i)
        {
            for(j=0;j<col;++j)
            {
                x=0;
                for(k=0;k<4;++k)
                {
                     x+=a[i][k]*b[k][j];
                    p[i][j]=x;
                }
            }
        }

    return p;
}

point* translate_3d(point *p, int n, int dx, int dy, int dz)
{
    int i,j; // a is 4x4 b is 4xn
    float a[][4]={1,0,0,dx, 0,1,0,dy, 0,0,1,dz, 0,0,0,1};

    //float b[4][n1];
    float **b=(float **)calloc(4, sizeof(float *));
    for(i=0;i<4;++i)
        b[i]=(float *)calloc(n-1, sizeof(float));
    for(i=0;i<n-1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=p[i].z;
        b[3][i]=1;
    }

    float **p1=mul(a,b, n-1);
    p1[0][n-1]=p1[0][0]; p1[1][n-1]=p1[1][0]; p1[2][n-1]=p1[2][0]; // for repeating first point

    point *ans=(point *)malloc(n*sizeof(point));
    for(i=0;i<n;++i)
   {
       ans[i].x=p1[0][i];
       ans[i].y=p1[1][i];
       ans[i].z=p1[2][i];
   }
    return ans;
}
point* rotate_z(point *p, int n, int angle)
{
    int dx,dy,dz;
    dx=dy=dz=s1;
    p= translate_3d(p, n, -dx, -dy, -dz);
    int i,j;
    float theta=angle*M_PI/180;
    float a[4][4]={cos(theta), -sin(theta),0,0, sin(theta),cos(theta),0,0, 0,0,1,0,  0,0,0,1};
    float **b=(float **)calloc(4, sizeof(float *));
    for(i=0;i<4;++i)
        b[i]=(float *)calloc(n-1, sizeof(float));
    for(i=0;i<n-1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=p[i].z;
        b[3][i]=1;
    }

    float **p1=mul(a, b, n-1);
    p1[0][n-1]=p1[0][0]; p1[1][n-1]=p1[1][0]; p1[2][n-1]=p1[2][0];

    point *ans=(point *)malloc(n*sizeof(point));
    for(i=0;i<n;++i)
   {
       ans[i].x=p1[0][i];
       ans[i].y=p1[1][i];
       ans[i].z=p1[2][i];
   }
   ans= translate_3d(ans, n, dx, dy, dz);
    return ans;
}

point* rotate_x(point *p, int n, int angle)
{
    int dx,dy,dz;
    dx=dy=dz=s1;
    p= translate_3d(p, n, -dx, -dy, -dz);
    int i,j;
    float theta=angle*M_PI/180;
    float a[4][4]={1,0,0,0,  0,cos(theta),-sin(theta),0,  0,sin(theta),cos(theta),0,  0,0,0,1};
    float **b=(float **)calloc(4, sizeof(float *));
    for(i=0;i<4;++i)
        b[i]=(float *)calloc(n-1, sizeof(float));
    for(i=0;i<n-1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=p[i].z;
        b[3][i]=1;
    }

    float **p1=mul(a, b, n-1);
    p1[0][n-1]=p1[0][0]; p1[1][n-1]=p1[1][0]; p1[2][n-1]=p1[2][0];

    point *ans=(point *)malloc(n*sizeof(point));
    for(i=0;i<n;++i)
   {
       ans[i].x=p1[0][i];
       ans[i].y=p1[1][i];
       ans[i].z=p1[2][i];
   }
   ans= translate_3d(ans, n, dx, dy, dz);
    return ans;
}

point* rotate_y(point *p, int n, int angle)
{
    //int dx=p[0].x;
    //int dy=p[0].y;
    //int dz=p[0].z;
    int dx,dy,dz;
    dx=dy=dz=s1;
    p= translate_3d(p, n, -dx, -dy, -dz);
    int i,j;
    float theta=angle*M_PI/180;
    float a[4][4]={cos(theta),0,sin(theta),0,  0,1,0,0,  -sin(theta),0,cos(theta),0,  0,0,0,1};
    float **b=(float **)calloc(4, sizeof(float *));
    for(i=0;i<4;++i)
        b[i]=(float *)calloc(n-1, sizeof(float));
    for(i=0;i<n-1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=p[i].z;
        b[3][i]=1;
    }

    float **p1=mul(a, b, n-1);
    p1[0][n-1]=p1[0][0]; p1[1][n-1]=p1[1][0]; p1[2][n-1]=p1[2][0];

    point *ans=(point *)malloc(n*sizeof(point));
    for(i=0;i<n;++i)
   {
       ans[i].x=p1[0][i];
       ans[i].y=p1[1][i];
       ans[i].z=p1[2][i];
   }
   ans= translate_3d(ans, n, dx, dy, dz);
    return ans;
}





void draw1(int angle, int opt)
{
        setcolor(15);
        int i;
        if(opt==2)
        {
                    p7=rotate_x(p1, n, angle);
            for(i=1;i<n;++i)
            line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

            p8=rotate_x(p2, n, angle);
            for(i=1;i<n;++i)
            line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

            p9=rotate_x(p3, n, angle);
            for(i=1;i<n;++i)
            line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

            p10=rotate_x(p4, n, angle);
            for(i=1;i<n;++i)
            line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

            p11=rotate_x(p5, n, angle);
            for(i=1;i<n;++i)
            line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

            p12=rotate_x(p6, n, angle);
            for(i=1;i<n;++i)
            line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);

            //------------------------------------------------------------//
            setcolor(YELLOW);
            num7=rotate_x(num1, 3, angle);
            for(i=1;i<3;++i)
            line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

            num8=rotate_x(num2, 7, angle);
            for(i=1;i<6;++i)
            line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);


            num9=rotate_x(num3, 8, angle);
            for(i=1;i<7;++i)
            line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

            num10=rotate_x(num4, 5, angle);
            for(i=1;i<4;++i)
            line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

            num11=rotate_x(num5, 7, angle);
            for(i=1;i<6;++i)
            line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

            num12=rotate_x(num6, 7, angle);
            for(i=1;i<6;++i)
            line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
       }
       else if(opt==1)
        {
            p7=rotate_y(p1, n, angle);
        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

        p8=rotate_y(p2, n, angle);
        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

        p9=rotate_y(p3, n, angle);
        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

        p10=rotate_y(p4, n, angle);
        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

        p11=rotate_y(p5, n, angle);
        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

        p12=rotate_y(p6, n, angle);
        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);

        //------------------------------------------------------------//
        setcolor(YELLOW);
        num7=rotate_y(num1, 3, angle);
        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

        num8=rotate_y(num2, 7, angle);
        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);


        num9=rotate_y(num3, 8, angle);
        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

        num10=rotate_y(num4, 5, angle);
        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

        num11=rotate_y(num5, 7, angle);
        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

        num12=rotate_y(num6, 7, angle);
        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
        }
        else if(opt==3)
        {
            p7=rotate_z(p1, n, angle);
        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

        p8=rotate_z(p2, n, angle);
        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

        p9=rotate_z(p3, n, angle);
        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

        p10=rotate_z(p4, n, angle);
        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

        p11=rotate_z(p5, n, angle);
        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

        p12=rotate_z(p6, n, angle);
        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);

        //------------------------------------------------------------//
        setcolor(YELLOW);
        num7=rotate_z(num1, 3, angle);
        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

        num8=rotate_z(num2, 7, angle);
        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);


        num9=rotate_z(num3, 8, angle);
        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

        num10=rotate_z(num4, 5, angle);
        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

        num11=rotate_z(num5, 7, angle);
        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

        num12=rotate_z(num6, 7, angle);
        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
        }


}
void draw2(int angle, int opt)
{
        setcolor(15);
        int i,dx,dy;
        dx=150; dy=250;
        if(opt==3)
        {
            p7=rotate_y(p1, n, angle);
        p7=translate_3d(p7, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

        p8=rotate_y(p2, n, angle);
        p8=translate_3d(p8, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

        p9=rotate_y(p3, n, angle);
        p9=translate_3d(p9, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

        p10=rotate_y(p4, n, angle);
        p10=translate_3d(p10, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

        p11=rotate_y(p5, n, angle);
        p11=translate_3d(p11, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

        p12=rotate_y(p6, n, angle);
        p12=translate_3d(p12, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);

    //------------------------------------------------------------//
        setcolor(YELLOW);
        num7=rotate_y(num1, 3, angle);
        num7=translate_3d(num7, 3, dx, dy, 0);
        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

        num8=rotate_y(num2, 7, angle);
        num8=translate_3d(num8, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);


        num9=rotate_y(num3, 8, angle);
        num9=translate_3d(num9, 8, dx, dy, 0);
        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

        num10=rotate_y(num4, 5, angle);
        num10=translate_3d(num10, 5, dx, dy, 0);
        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

        num11=rotate_y(num5, 7, angle);
        num11=translate_3d(num11, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

        num12=rotate_y(num6, 7, angle);
        num12=translate_3d(num12, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
        }
        else if(opt==2)
        {
                p7=rotate_z(p1, n, angle);
        p7=translate_3d(p7, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

        p8=rotate_z(p2, n, angle);
        p8=translate_3d(p8, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

        p9=rotate_z(p3, n, angle);
        p9=translate_3d(p9, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

        p10=rotate_z(p4, n, angle);
        p10=translate_3d(p10, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

        p11=rotate_z(p5, n, angle);
        p11=translate_3d(p11, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

        p12=rotate_z(p6, n, angle);
        p12=translate_3d(p12, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);

    //------------------------------------------------------------//
        setcolor(YELLOW);
        num7=rotate_z(num1, 3, angle);
        num7=translate_3d(num7, 3, dx, dy, 0);
        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

        num8=rotate_z(num2, 7, angle);
        num8=translate_3d(num8, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);


        num9=rotate_z(num3, 8, angle);
        num9=translate_3d(num9, 8, dx, dy, 0);
        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

        num10=rotate_z(num4, 5, angle);
        num10=translate_3d(num10, 5, dx, dy, 0);
        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

        num11=rotate_z(num5, 7, angle);
        num11=translate_3d(num11, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

        num12=rotate_z(num6, 7, angle);
        num12=translate_3d(num12, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
        }
        else if(opt==1)
        {
                p7=rotate_x(p1, n, angle);
        p7=translate_3d(p7, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

        p8=rotate_x(p2, n, angle);
        p8=translate_3d(p8, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

        p9=rotate_x(p3, n, angle);
        p9=translate_3d(p9, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

        p10=rotate_x(p4, n, angle);
        p10=translate_3d(p10, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

        p11=rotate_x(p5, n, angle);
        p11=translate_3d(p11, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

        p12=rotate_x(p6, n, angle);
        p12=translate_3d(p12, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);

    //------------------------------------------------------------//
        setcolor(YELLOW);
        num7=rotate_x(num1, 3, angle);
        num7=translate_3d(num7, 3, dx, dy, 0);
        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

        num8=rotate_x(num2, 7, angle);
        num8=translate_3d(num8, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);


        num9=rotate_x(num3, 8, angle);
        num9=translate_3d(num9, 8, dx, dy, 0);
        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

        num10=rotate_x(num4, 5, angle);
        num10=translate_3d(num10, 5, dx, dy, 0);
        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

        num11=rotate_x(num5, 7, angle);
        num11=translate_3d(num11, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

        num12=rotate_x(num6, 7, angle);
        num12=translate_3d(num12, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
        }




}
void draw3(int angle, int opt)
{
        setcolor(15);
        int i,dx,dy;
        dx=500; dy=0;
        if(opt==1)
        {
                p7=rotate_z(p1, n, angle);
        p7=translate_3d(p7, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

        p8=rotate_z(p2, n, angle);
        p8=translate_3d(p8, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

        p9=rotate_z(p3, n, angle);
        p9=translate_3d(p9, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

        p10=rotate_z(p4, n, angle);
        p10=translate_3d(p10, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

        p11=rotate_z(p5, n, angle);
        p11=translate_3d(p11, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

        p12=rotate_z(p6, n, angle);
        p12=translate_3d(p12, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);


        //------------------------------------------------------------//
        setcolor(YELLOW);
        num7=rotate_z(num1, 3, angle);
        num7=translate_3d(num7, 3, dx, dy, 0);
        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

        num8=rotate_z(num2, 7, angle);
        num8=translate_3d(num8, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);

        num9=rotate_z(num3, 8, angle);
        num9=translate_3d(num9, 8, dx, dy, 0);
        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

        num10=rotate_z(num4, 5, angle);
        num10=translate_3d(num10, 5, dx, dy, 0);
        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

        num11=rotate_z(num5, 7, angle);
        num11=translate_3d(num11, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

        num12=rotate_z(num6, 7, angle);
        num12=translate_3d(num12, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
        }
        else if(opt==2)
        {
            p7=rotate_y(p1, n, angle);
        p7=translate_3d(p7, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

        p8=rotate_y(p2, n, angle);
        p8=translate_3d(p8, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

        p9=rotate_y(p3, n, angle);
        p9=translate_3d(p9, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

        p10=rotate_y(p4, n, angle);
        p10=translate_3d(p10, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

        p11=rotate_y(p5, n, angle);
        p11=translate_3d(p11, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

        p12=rotate_y(p6, n, angle);
        p12=translate_3d(p12, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);


        //------------------------------------------------------------//
        setcolor(YELLOW);
        num7=rotate_y(num1, 3, angle);
        num7=translate_3d(num7, 3, dx, dy, 0);
        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

        num8=rotate_y(num2, 7, angle);
        num8=translate_3d(num8, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);

        num9=rotate_y(num3, 8, angle);
        num9=translate_3d(num9, 8, dx, dy, 0);
        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

        num10=rotate_y(num4, 5, angle);
        num10=translate_3d(num10, 5, dx, dy, 0);
        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

        num11=rotate_y(num5, 7, angle);
        num11=translate_3d(num11, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

        num12=rotate_y(num6, 7, angle);
        num12=translate_3d(num12, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
        }
        else if(opt==3)
        {
            p7=rotate_x(p1, n, angle);
        p7=translate_3d(p7, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);

        p8=rotate_x(p2, n, angle);
        p8=translate_3d(p8, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);

        p9=rotate_x(p3, n, angle);
        p9=translate_3d(p9, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);

        p10=rotate_x(p4, n, angle);
        p10=translate_3d(p10, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);

        p11=rotate_x(p5, n, angle);
        p11=translate_3d(p11, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);

        p12=rotate_x(p6, n, angle);
        p12=translate_3d(p12, n, dx, dy, 0);
        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);


        //------------------------------------------------------------//
        setcolor(YELLOW);
        num7=rotate_x(num1, 3, angle);
        num7=translate_3d(num7, 3, dx, dy, 0);
        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

        num8=rotate_x(num2, 7, angle);
        num8=translate_3d(num8, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);

        num9=rotate_x(num3, 8, angle);
        num9=translate_3d(num9, 8, dx, dy, 0);
        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);

        num10=rotate_x(num4, 5, angle);
        num10=translate_3d(num10, 5, dx, dy, 0);
        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);

        num11=rotate_x(num5, 7, angle);
        num11=translate_3d(num11, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);

        num12=rotate_x(num6, 7, angle);
        num12=translate_3d(num12, 7, dx, dy, 0);
        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);
        }




}



point* isometric(point *p, int n)
{

    int i,j;
    int dx,dy,dz;
    dx=dy=dz=s1;
    p= translate_3d(p, n, -dx, -dy, -dz);
    //float a[4][4]={1,0,-1,0,  0,1,-1,0,  0,0,0,0, 0,0,0,1};
    float a[4][4]={0.707,0,0.707,0,  .7*.57, .82, -.57*.707,0,   0,0,0,0,  0,0,0,1};

    float **b=(float **)calloc(4, sizeof(float *));
    for(i=0;i<4;++i)
        b[i]=(float *)calloc(n-1, sizeof(float));
    for(i=0;i<n-1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=p[i].z;
        b[3][i]=1;
    }

    float **p1=mul(a, b, n-1);
    p1[0][n-1]=p1[0][0]; p1[1][n-1]=p1[1][0]; p1[2][n-1]=p1[2][0];

    point *ans=(point *)malloc(n*sizeof(point));
    for(i=0;i<n;++i)
   {
       ans[i].x=p1[0][i];
       ans[i].y=p1[1][i];
       ans[i].z=p1[2][i];
   }
    p= translate_3d(ans, n, -dx, -dy, -dz);
    return ans;
}
void draw4(int angle, int opt)
{
    setcolor(WHITE);
    int i,dx, dy;
    dx=500; dy=400; //angle=30;


        p7=rotate_z(p1, n, angle);
        p7=isometric(p7, n);
        p7=translate_3d(p7, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);


         p8=rotate_z(p2, n, angle);
         p8=isometric(p8, n);
        p8=translate_3d(p8, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);


         p9=rotate_z(p3, n, angle);
         p9=isometric(p9, n);
        p9=translate_3d(p9, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);


        p10=rotate_z(p4, n, angle);
        p10=isometric(p10, n);
        p10=translate_3d(p10, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);


         p11=rotate_z(p5, n, angle);
         p11=isometric(p11, n);
        p11=translate_3d(p11, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);


        p12=rotate_z(p6, n, angle);
        p12=isometric(p12, n);
        p12=translate_3d(p12, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);


        //----------------------------//
        setcolor(YELLOW);

        num7=rotate_z(num1, 3, angle);
        num7=isometric(num7, 3);
        num7=translate_3d(num7, 3, dx, dy, 0);

        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

    num8=rotate_z(num2, 7, angle);
        num8=isometric(num8, 7);
        num8=translate_3d(num8, 7, dx, dy, 0);

        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);
 num9=rotate_z(num3, 8, angle);
        num9=isometric(num9, 8);
         num9=translate_3d(num9, 8, dx, dy, 0);

        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);
num10=rotate_z(num4, 5, angle);
        num10=isometric(num10,5);
        num10=translate_3d(num10, 5, dx, dy, 0);

        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);
num11=rotate_z(num5, 7, angle);
        num11=isometric(num11, 7);
        num11=translate_3d(num11, 7, dx, dy, 0);

        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);
num12=rotate_z(num6, 7, angle);
        num12=isometric(num12, 7);
        num12=translate_3d(num12, 7, dx, dy, 0);

        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);

}


point* isometric1(point *p, int n)
{

    int i,j;
    int dx,dy,dz;
    dx=dy=dz=s1;
    p= translate_3d(p, n, -dx, -dy, -dz);
    float a[4][4]={1,0,-1,0,  0,1,-1,0,  0,0,0,0, 0,0,0,1};
   // float a[4][4]={0.707,0,0.707,0,  .7*.57, .82, -.57*.707,0,   0,0,0,0,  0,0,0,1};

    float **b=(float **)calloc(4, sizeof(float *));
    for(i=0;i<4;++i)
        b[i]=(float *)calloc(n-1, sizeof(float));
    for(i=0;i<n-1;++i)
    {
        b[0][i]=p[i].x;
        b[1][i]=p[i].y;
        b[2][i]=p[i].z;
        b[3][i]=1;
    }

    float **p1=mul(a, b, n-1);
    p1[0][n-1]=p1[0][0]; p1[1][n-1]=p1[1][0]; p1[2][n-1]=p1[2][0];

    point *ans=(point *)malloc(n*sizeof(point));
    for(i=0;i<n;++i)
   {
       ans[i].x=p1[0][i];
       ans[i].y=p1[1][i];
       ans[i].z=p1[2][i];
   }
    p= translate_3d(ans, n, -dx, -dy, -dz);
    return ans;
}
void draw5(int angle, int opt)
{
    setcolor(WHITE);
    int i,dx, dy;
    dx=800; dy=400; //angle=30;


        p7=rotate_z(p1, n, angle);
        p7=isometric1(p7, n);
        p7=translate_3d(p7, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p7[i-1].x, p7[i-1].y, p7[i].x, p7[i].y);


         p8=rotate_z(p2, n, angle);
         p8=isometric1(p8, n);
        p8=translate_3d(p8, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p8[i-1].x, p8[i-1].y, p8[i].x, p8[i].y);


         p9=rotate_z(p3, n, angle);
         p9=isometric1(p9, n);
        p9=translate_3d(p9, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p9[i-1].x, p9[i-1].y, p9[i].x, p9[i].y);


        p10=rotate_z(p4, n, angle);
        p10=isometric1(p10, n);
        p10=translate_3d(p10, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p10[i-1].x, p10[i-1].y, p10[i].x, p10[i].y);


         p11=rotate_z(p5, n, angle);
         p11=isometric1(p11, n);
        p11=translate_3d(p11, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p11[i-1].x, p11[i-1].y, p11[i].x, p11[i].y);


        p12=rotate_z(p6, n, angle);
        p12=isometric1(p12, n);
        p12=translate_3d(p12, n, dx, dy, 0);

        for(i=1;i<n;++i)
        line(p12[i-1].x, p12[i-1].y, p12[i].x, p12[i].y);


        //----------------------------//
        setcolor(YELLOW);

        num7=rotate_z(num1, 3, angle);
        num7=isometric1(num7, 3);
        num7=translate_3d(num7, 3, dx, dy, 0);

        for(i=1;i<3;++i)
        line(num7[i-1].x, num7[i-1].y, num7[i].x, num7[i].y);

    num8=rotate_z(num2, 7, angle);
        num8=isometric1(num8, 7);
        num8=translate_3d(num8, 7, dx, dy, 0);

        for(i=1;i<6;++i)
        line(num8[i-1].x, num8[i-1].y, num8[i].x, num8[i].y);
 num9=rotate_z(num3, 8, angle);
        num9=isometric1(num9, 8);
         num9=translate_3d(num9, 8, dx, dy, 0);

        for(i=1;i<7;++i)
        line(num9[i-1].x, num9[i-1].y, num9[i].x, num9[i].y);
num10=rotate_z(num4, 5, angle);
        num10=isometric1(num10,5);
        num10=translate_3d(num10, 5, dx, dy, 0);

        for(i=1;i<4;++i)
        line(num10[i-1].x, num10[i-1].y, num10[i].x, num10[i].y);
num11=rotate_z(num5, 7, angle);
        num11=isometric1(num11, 7);
        num11=translate_3d(num11, 7, dx, dy, 0);

        for(i=1;i<6;++i)
        line(num11[i-1].x, num11[i-1].y, num11[i].x, num11[i].y);
num12=rotate_z(num6, 7, angle);
        num12=isometric1(num12, 7);
        num12=translate_3d(num12, 7, dx, dy, 0);

        for(i=1;i<6;++i)
        line(num12[i-1].x, num12[i-1].y, num12[i].x, num12[i].y);

}



void cube_rotatey()
{
    p1[0]={s1,s1,s1}; p1[1]={a+s1,s1,s1}; p1[2]={a+s1,a+s1,s1}; p1[3]={s1,a+s1,s1}; p1[4]={s1,s1,s1};

    p2[0]={s1,s1,s1+a}; p2[1]={a+s1,s1,s1+a}; p2[2]={a+s1,a+s1,s1+a}; p2[3]={s1,a+s1,s1+a}; p2[4]={s1,s1,s1+a};

    p3[0]={s1,s1,s1}; p3[1]={s1,s1,s1+a}; p3[2]={s1,a+s1,s1+a}; p3[3]={s1,a+s1,s1}; p3[4]={s1,s1,s1};

    p4[0]={a+s1,s1,s1}; p4[1]={a+s1,s1,s1+a}; p4[2]={a+s1,a+s1,s1+a}; p4[3]={a+s1,a+s1,s1}; p4[4]={a+s1,s1,s1};

    p5[0]={s1,s1,s1}; p5[1]={a+s1,s1,s1}; p5[2]={a+s1,s1,s1+a}; p5[3]={s1,s1,s1+a}; p5[4]={s1,s1,s1};

    p6[0]={s1,s1+a,s1}; p6[1]={a+s1,a+s1,s1}; p6[2]={a+s1,a+s1,s1+a}; p6[3]={s1,a+s1,s1+a}; p6[4]={s1,a+s1,s1};

    num1[0].x=p1[0].x+60;  num1[0].y=p1[0].y+20;  num1[0].z=p1[0].z;
    num1[1].x=p1[0].x+60;  num1[1].y=p1[0].y+80;  num1[1].z=p1[0].z;
    num1[2].x=p1[0].x+60;  num1[2].y=p1[0].y+20;  num1[2].z=p1[0].z;

    num2[0].x=p2[0].x+20;  num2[0].y=p2[0].y+20;  num2[0].z=p2[0].z;
    num2[1].x=p2[0].x+80;  num2[1].y=p2[0].y+20;  num2[1].z=p2[0].z;
    num2[2].x=p2[0].x+80;  num2[2].y=p2[0].y+45;  num2[2].z=p2[0].z;
    num2[3].x=p2[0].x+20;  num2[3].y=p2[0].y+45;  num2[3].z=p2[0].z;
    num2[4].x=p2[0].x+20;  num2[4].y=p2[0].y+80;  num2[4].z=p2[0].z;
    num2[5].x=p2[0].x+80;  num2[5].y=p2[0].y+80;  num2[5].z=p2[0].z;
    num2[6].x=p2[0].x+20;  num2[6].y=p2[0].y+20;  num2[5].z=p2[0].z;

    num3[0].x=p3[0].x;  num3[0].y=p3[0].y+20;  num3[0].z=p3[0].z+20;
    num3[1].x=p3[0].x;  num3[1].y=p3[0].y+20;  num3[1].z=p3[0].z+80;
    num3[2].x=p3[0].x;  num3[2].y=p3[0].y+50;  num3[2].z=p3[0].z+80;
    num3[3].x=p3[0].x;  num3[3].y=p3[0].y+50;  num3[3].z=p3[0].z+20;
    num3[4].x=p3[0].x;  num3[4].y=p3[0].y+50;  num3[4].z=p3[0].z+80;
    num3[5].x=p3[0].x;  num3[5].y=p3[0].y+80;  num3[5].z=p3[0].z+80;
    num3[6].x=p3[0].x;  num3[6].y=p3[0].y+80;  num3[6].z=p3[0].z+20;
    num3[7].x=p3[0].x;  num3[7].y=p3[0].y+20;  num3[7].z=p3[0].z+20;

    num4[0].x=p4[0].x;  num4[0].y=p4[0].y+80;  num4[0].z=p4[0].z+65;
    num4[1].x=p4[0].x;  num4[1].y=p4[0].y+20;  num4[1].z=p4[0].z+65;
    num4[2].x=p4[0].x;  num4[2].y=p4[0].y+60;  num4[2].z=p4[0].z+20;
    num4[3].x=p4[0].x;  num4[3].y=p4[0].y+60;  num4[3].z=p4[0].z+80;
    num4[4].x=p4[0].x;  num4[4].y=p4[0].y+80;  num4[4].z=p4[0].z+65;

    num5[0].x=p5[0].x+80;  num5[0].y=p5[0].y;  num5[0].z=p5[0].z+20;
    num5[1].x=p5[0].x+20;  num5[1].y=p5[0].y;  num5[1].z=p5[0].z+20;
    num5[2].x=p5[0].x+20;  num5[2].y=p5[0].y;  num5[2].z=p5[0].z+45;
    num5[3].x=p5[0].x+80;  num5[3].y=p5[0].y;  num5[3].z=p5[0].z+45;
    num5[4].x=p5[0].x+80;  num5[4].y=p5[0].y;  num5[4].z=p5[0].z+80;
    num5[5].x=p5[0].x+20;  num5[5].y=p5[0].y;  num5[5].z=p5[0].z+80;
    num5[6].x=p5[0].x+80;  num5[6].y=p5[0].y;  num5[6].z=p5[0].z+20;

    num6[0].x=p6[0].x+80;  num6[0].y=p6[0].y;  num6[0].z=p6[0].z+20;
    num6[1].x=p6[0].x+20;  num6[1].y=p6[0].y;  num6[1].z=p6[0].z+20;
    num6[2].x=p6[0].x+20;  num6[2].y=p6[0].y;  num6[2].z=p6[0].z+80;
    num6[3].x=p6[0].x+80;  num6[3].y=p6[0].y;  num6[3].z=p6[0].z+80;
    num6[4].x=p6[0].x+80;  num6[4].y=p6[0].y;  num6[4].z=p6[0].z+60;
    num6[5].x=p6[0].x+20;  num6[5].y=p6[0].y;  num6[5].z=p6[0].z+60;
    num6[6].x=p6[0].x+80;  num6[6].y=p6[0].y;  num6[6].z=p6[0].z+20;


    int i,opt, angle=0;
    cout<<"\n1. Rotation about x axis\n2. Rotation about y axis\n3. Rotation about z axis\n4. Exit\n\n";
    opt=1;



    int timer=0;
    while(1)
    {

        //opt=getch();
        //cin>>opt;
        if(opt==4) exit(1);

        delay(200);
        cleardevice();


        draw1(angle, opt);
        draw2(angle, opt);
        draw3(angle, opt);

        draw4(angle, opt);
        draw5(angle, opt);
        setcolor(15);

        angle+=3;
        /*timer++;
        if(timer>20)
            opt=2;
        if(timer>40) opt=3;
        if(timer>60)
        {

            timer=0; opt=1;
        }*/
    }
}




int main(void)
{

    int gdriver = DETECT, gmode, errorcode;
    //initgraph(&gdriver, &gmode, "..\\bgi");
    initwindow(1080,640,"Window");



    cube_rotatey();



   getch();
   closegraph();
   return 0;
}



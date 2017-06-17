#include<iostream>
#include<stdlib.h>
using namespace std;
//If the matrices A, B are not of type 2n × 2n we fill the missing rows and columns with zeros.

int **declare(int r, int c)
{
    int i;
    int **ans=(int **)calloc(r, sizeof(int *));
    for(i=0;i<r;++i)
        ans[i]=(int *)calloc(c, sizeof(int));
    return ans;
}

int ** add(int **a, int **b, int r, int c)
{
    int i,j;
    int **ans=declare(r, c);
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
            ans[i][j]=a[i][j]+b[i][j];
    }
    return ans;
}
int ** sub(int **a, int **b, int r, int c)
{
    int i,j;
    int **ans=declare(r, c);

    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
            ans[i][j]=a[i][j]-b[i][j];
    }
    return ans;
}
int **mul(int **a, int **b, int **ans, int r, int c)
{
    int **m1=declare(r, c);
    int **m2=declare(r, c);
    int **m3=declare(r, c);
    int **m4=declare(r, c);
    int **m5=declare(r, c);
    int **m6=declare(r, c);
    int **m7=declare(r, c);

    int **p1=declare(r, c);  int **p8=declare(r, c);
    int **p2=declare(r, c);  int **p9=declare(r, c);
    int **p3=declare(r, c);  int **p10=declare(r, c);
    int **p4=declare(r, c);  int **p12=declare(r, c);
    int **p5=declare(r, c);  int **p13=declare(r, c);
    int **p6=declare(r, c);  int **p14=declare(r, c);
    int **p7=declare(r, c);  int **p11=declare(r, c);

    int **ans1=declare(r, c);
    int **ans2=declare(r, c);
    int **ans3=declare(r, c);
    int **ans4=declare(r, c);

    if(r<2)
    {
        int **w=declare(1, 1);
        w[0][0]=a[0][0]*b[0][0];
        return w;
    }
    if(r==c && c==2)
    {
        int **w=declare(2, 2);
        w[0][0]=a[0][0]*b[0][0] + a[0][1]*b[1][0];
        w[0][1]=a[0][0]*b[0][1] + a[0][1]*b[1][1];
        w[1][0]=a[1][0]*b[0][0] + a[1][1]*b[1][0];
        w[1][1]=a[1][0]*b[0][1] + a[1][1]*b[1][1];

        return w;
    }




    //p1=add(a, a+(r+1)*r/2, r/2-1, r/2-1);
        cout<<*(*(a+r/2)+r/2)<<"\n";
        int *x=(*(a+r/2)+r/2);
        //int *y =(*(a+r/2)+r/2);
    cout<<*x<<"  ";
    int **t=add(x, a,1,1);
//    cout<<&(*(a+r/2)+r/2);

    cout<<" here  ";
    /*p2=add(b, b+(r+1)*r/2, r/2-1, r/2-1);
    p3=add(a+(r/2*r), a+(r+1)*r/2, r/2-1, r/2-1);
    p4=b;
    p5=a;
    p6=sub(b+r/2, b+(r+1)*r/2, r/2-1, r/2-1);
    p7=a+(r+1)*r/2;

    p8=sub(b+(r/2*r), b, r/2-1, r/2-1);
    p9=add(a, a+r/2, r/2-1, r/2-1);
    p10=b+(r+1)*r/2;
    p11=sub(a+(r/2*r), a, r/2-1, r/2-1);
    p12=add(b, b+r/2, r/2-1, r/2-1);
    p13=sub(a+r/2, a+(r+1)*r/2, r/2-1, r/2-1);
    p14=add(b+(r/2*r), b+(r+1)*r/2, r/2-1, r/2-1);


    m1=mul(p1, p2, ans, r/2-1, r/2-1);
    m2=mul(p3, p4, ans, r/2-1, r/2-1);
    m3=mul(p5, p6, ans, r/2-1, r/2-1);
    m4=mul(p7, p8, ans, r/2-1, r/2-1);
    m5=mul(p9, p10, ans, r/2-1, r/2-1);
    m6=mul(p11, p12, ans, r/2-1, r/2-1);
    m7=mul(p13, p14, ans, r/2-1, r/2-1);

    ans1=add(m7, sub(add(m1, m4, r, c), m5, r, c), r, c);
    ans2=add(m3, m5, r, c);
    ans3=add(m2, m4, r, c);
    ans4=add(m6, sub(add(m1, m3, r, c), m2, r, c), r, c);*/

    return ans1;
}
int main()
{
    int r, c, i, j, k=1;
    r=4; c=4;
    int **a=declare(r, c);
    int **b=declare(r, c);
    int **ans=declare(r, c);

    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
            a[i][j]=k++;
    }
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        {
            if(i==j) b[i][j]=1;
        }
    }

    int **w=mul(a, b, ans, r, c);
    for(i=0;i<r;++i)
    {
        for(j=0;j<c;++j)
        cout<<w[i][j]<<"  ";
        cout<<"\n\n";
    }
    return 0;
}

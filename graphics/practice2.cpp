#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int r=3, c=5;
    int i,j;
    float **b=(float **)calloc(r, sizeof(float *));
    for(i=0;i<r;++i)
        b[i]=(float *)calloc(c, sizeof(float));

        for(i=0;i<r;++i)
        {
            for(j=0;j<c;++j)
                cout<<b[i][j]<<"  ";
            cout<<"\n\n";
        }


        cout<<sizeof(*b);
}

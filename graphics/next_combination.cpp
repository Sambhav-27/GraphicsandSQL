#include<iostream>
#include<math.h>
using namespace std;
int main()
{

    int a[10]={0,1,2,3,4},b[10],i,j,t,m,maxp,n=6,k=4;
    int count=0;
    while(count<10)
    {
        j=4;
        while(j)
        {
            maxp=n-k+j;
            if(a[j]!=maxp)
                break;
            j--;
        }
        int w=1;
        for(i=1;i<j;++i)
            b[w++]=a[i];
            b[w++]=a[j]+1;
        for(i=j+1;i<=k;++i)
            b[i]=b[i-1]+1;

        for(i=1;i<=k;++i)
            cout<<b[i]<<" ";
            cout<<"\n";
        for(i=0;i<=k;++i)
            a[i]=b[i];

            count++;
    }

}

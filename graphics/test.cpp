#include<iostream>
#include<algorithm>
using namespace std;
long long int a[10];

 int main()
{
    long long int test,i,j,k,pos,prev, n;
    cin>>test;

    while(test--)
    {
        cin>>n;
        for(i=0;i<n;++i)
            cin>>a[i];
            //sort(a, a+n);
        prev=0;
        bool flag=0;
        int x,y;
        for(i=0;i<n;++i)
        {
            if(a[i]!=0 && a[i]!=1)
                x=i;

        }
        for(i=0;i<n;++i)
        {
            if(a[i]!=0 && a[i]!=1 && i!=x)
            {
                y=i; flag=1;
            }
        }
        /*for(i=0;i<n;++i)
        {

            for(j=i+1;j<n;++j)
            {

                if( (a[i]!=0 && a[i]!=1 ) &&( a[j]!=0 && a[j]!=1))
                {
                    flag=1; break;
                }
            }
            if(flag) break;
        }*/
        if(flag)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
    return 0;
}

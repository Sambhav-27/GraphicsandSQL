#include<iostream>
#define n 5
using namespace std;
int a[n][n];
bool ref()
{
    int i;
    for(i=0;i<n;++i)
        if(!a[i][i])
        return 0;
    return 1;
}
bool sym()
{
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(a[i][j])
            {
                if(!a[j][i]) return 0;
            }
        }
    }
    return 1;
}
bool tran()
{
    int i,j,k;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            for(k=0;k<n;++k)
            {
                if(a[i][j] && a[j][k])
                {
                    if(!a[i][k]) return 0;
                }
            }
        }
    }
    return 1;
}
int main()
{
    int i,j,x;
    cin>>x;
    while(x--)
    {
        cin>>i>>j;
        a[i][j]=1;
    }
    //cout<<sym()<<" " <<tran()<<" "<<ref()<<"\n";
    if( sym() && tran() && ref())
        cout<<"\nEquivalence relation\n";
    else
        cout<<"\nNot an equivalence relation\n";
    return 0;
}

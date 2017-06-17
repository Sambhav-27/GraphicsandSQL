// check if a string is palindrome after replacing two chars at each query O(q+n)
#include<iostream>
#include<string.h>
using namespace std;
bool mark[20];
int noe;
char a[20];
void bulldog(char *a)
{
    int i,n=strlen(a);
    for(i=0;i<n/2;++i)
    {
        if(a[i]!=a[n-1-i])
            mark[i]=1;
            noe++;
    }
}
bool check(int i1, int i2, char ch)
{
    int n = strlen(a);
    a[i1]=a[i2]=ch;
    cout<<"a: "<<a<<"  ";
    // don't forget to convert i1, i2 > n/2 to first half
//    if(i1>n/2)
//        i1=n-1-i1;
//    if(i2>n/2)
//        i2=n-1-i2;

    if(a[i1]==a[n-1-i1])
    {
         mark[i1]=0; noe--;
    }

    if(a[i2]==a[n-1-i2])
    {
        mark[i2]=0; noe--;
    }

    cout<<noe<<" ";


    return (noe<=0);
}
int main()
{
    char ch;
    int q,i1,i2;
    cin>>a>>q;
    bulldog(a);
    while(q--)
    {
        cin>>i1>>i2>>ch;
        cout<<check(i1,i2,ch)<<"\n";

    }

}

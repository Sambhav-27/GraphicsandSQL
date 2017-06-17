#include<iostream>
#define INF 1000
#define N 4
using namespace std;
int a[4][4]={INF,10,15,20,  10,INF,35,25,  15,35,INF,30,  20,25,30,INF};
int ans=INF;
char path[10];
void travelling(char *b)
{
   // cout<<"\n"<<b<<"\n";
    int i,j,temp=0;
    for(i=0;i<N;++i)
    {
        j=(i+1)%N;
        //cout<<b[i]<<", "<<b[j];
        temp+=a[b[i]-49][b[j]-49];
    }
    if(temp<ans)
    {
        ans=temp;
        int i=0;
        for(i=0;i<N;++i)
            path[i]=b[i];
    }

}
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
   {
       char i,b[N];
       for(i=0;i<N;++i)
        b[i]=a[i];
       travelling(b);
   }
    // cout<<a<<"\n";
   else
   {
       for (i = l; i <= r; i++)
       {
           swap(a[l], a[i]);
          permute(a, l+1, r);
          swap(a[l], a[i]);
       }
   }
}

int main()
{
    char str[] = "1234";
    permute(str, 0, N-1);
    int i;
    cout<<" total path weight: "<<ans<<"\n\n";
    for(i=0;i<N;++i)
    cout<<path[i]<<"-- ";
}

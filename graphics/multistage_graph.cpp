#include<iostream>
#define N 13
#define INF 1000

using namespace std;
int c[N][N]; // cost matrix ; first row and col are left empty

void fgraph(int k, int n, int p[] )// k= no. of stages, n= no. of vertices ; p stores answer path
{
    int i,j,r,ans,d[N],cost[N]={0};
    for(j=n-1;j>=1;--j)
    {
        ans=INF;
        for(i=1; i<N; ++i)
        {
            if(c[j][i] +cost[i] <ans)
            {
                ans=c[j][i] + cost[i];
                r=i;
            }
        }
        cost[j]=ans;
        d[j]=r;
    }
    p[1]=1; p[k]=n;
    for(j=2;j<=k;++j)
        p[j]=d[p[j-1]];

}
int main()
{
     int i,j, k=5; int p[k+4];
     for(i=0;i<N;++i)
        for(j=0;j<N;++j)
        c[i][j]=INF;

    c[1][2]=9; c[1][3]=7; c[1][4]=3; c[1][5]=2;
    c[2][6]=4; c[2][7]=2; c[2][8]=1; c[3][6]=2; c[3][7]=7; c[4][8]=11; c[5][8]=8; c[5][7]=11;
    c[6][9]=6; c[6][10]=5; c[7][9]=4; c[7][10]=3; c[8][10]=5; c[8][11]=6;
    c[9][12]=4; c[10][12]=2; c[11][12]=5;


    cout<<"\n";
    fgraph(k, N-1, p);
    for(i=1;i<=k;++i)
       cout<<p[i]<< "  ";
}

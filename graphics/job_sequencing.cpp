#include<iostream>
#include<algorithm>
using namespace std;
struct job{
        int dead, profit;
    };

bool comp(job a, job b)
{
    return a.profit >b.profit;
}
int main()
{
    job j[5]={ {2,100}, {1,19}, {2,27}, {1,25}, {3,15} };
    sort(j, j+5, comp);

    int i,k,maxt=-1000;
    for(i=0;i<5;++i)
       cout<<j[i].profit<<" ";
       cout<<"\n\n";
    bool flag[5]={false};
    int ans=0;
    for(k=0;k<5;++k)
    {
        for(i=j[k].dead;i>0;--i)
        {
            if(!flag[i])
            {
                    flag[i]=true;
                    ans+=j[k].profit;
                    cout<<j[k].profit<<"  ";
                    break;
            }
        }
    }

    cout<<"\n\nMax profit: "<<ans;
}

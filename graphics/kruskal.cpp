#include<bits/stdc++.h>
using namespace std;

 vector<int> mst;

struct edge
{ int s, d, w;
};


bool sort_edge(const edge& a, const edge& b)
{ return a.w<b.w;
}

vector<edge> e;


int findP(int *u, int a)
{ if(u[a]==a)
  { return a;
  }
  return u[a]=findP(u, u[a]);
}
int main()
{ int n, m, temp;

  cin>>n>>m;
  //e.resize(m);
  edge t;
  for(int i=0;i<m;++i)
  { cin>>t.s>>t.d>>t.w;
    if(t.s==t.d)
    { continue;
    //m--;
    }
    e.push_back(t);
  }
  sort(e.begin(), e.end(), sort_edge);
  int u[n];
  for(int i=0;i<n;++i)
  { u[i]=i;
  }
  ////
  int p1, p2, c=0;

  for(int i=0;i<m-1;++i)
  { p1=findP(u, e[i].s);
    p2=findP(u, e[i].d);
    if(p1!=p2)
    { u[p2]=p1;
      c=c+e[i].w;
      mst.push_back(i);
    }
  }
  cout<<"MST cost : "<<c;
  /*for(int i=0;i<e.size();++i)
  { cout<<e[i].s<<" "<<e[i].d<<" "<<e[i].w<<"\n";
  }*/
}

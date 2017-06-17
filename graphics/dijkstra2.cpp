#include<bits/stdc++.h>
using namespace std;
struct node{
	int start,end,dist;
};

struct comp{
	bool operator()(const node &a, const node &b)
	{
		return a.dist > b.dist;
	}
};
vector<node> adj[10];
int ans[20];
bool notcontains[20];
node a,b,c;
void addedge(int src, int des, int w)
{
	node temp1={src, des, w};
	node temp2={des, src, w};
	adj[src].push_back(temp2);
	adj[des].push_back(temp1);
}
priority_queue<node, vector<node>,comp> Q;

int main()
{
	int u,i,v,vertices,edges,starting,w;
	edges=7; vertices=6;
	addedge(0,1,5); addedge(1,2,2); addedge(2,3,3); addedge(3,4,2); addedge(4,5,3); addedge(5,0,2); addedge(0,3,9);
	starting=0;

	c.start=starting;
	c.dist=0;
	for(i=0;i<vertices;++i)
	ans[i]=INT_MAX;
	ans[starting]=0;
	Q.push(c);

	while(!Q.empty())
	{
		u=Q.top().start; Q.pop();

		if(notcontains[u])
		continue;

		vector<node>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();++i)
		{
			v=(*i).start;
			w=(*i).dist;
			if(!notcontains[v] && ans[u]+w<ans[v])
			{
				ans[v]=ans[u]+w;
				c.start=v;
				c.dist=ans[v];
				Q.push(c);
			}
		}
		notcontains[u]=1;
	}

	for(i=0;i<vertices;++i)
	cout<<"vertix "<<i<<",  min weight "<<ans[i]<<"\n";

}// nodes are from 0 to n

#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
struct ed
{
	float x1,y1,x2,y2;
}win[101],sub[101];
struct pt
{
	float x,y,t;
	int io,l,m,vis;
};
vector<struct pt> w[100],s[100];
int csz=0, n1=3,n2=4;
float caltx(struct ed a,float x)
{
	return (x-a.x1)/(a.x2-a.x1);
}
float calty(struct ed a,float y)
{
	return (y-a.y1)/(a.y2-a.y1);
}
int calio(struct ed a,struct ed b)
{
    float l=(b.y1-b.y2)*(a.x2-a.x1) + (b.x2-b.x1)*(a.y2-a.y1);
    if(l<0)return 0;
    else return 1;

}
void inst(struct ed a,struct ed b,int i,int j)
{
	float m1,m2,t1,t2,x,y;
	struct pt tmp;
	if(a.x1==a.x2||b.x1==b.x2)
	{
		if(a.x1==a.x2&&b.x1==b.x2)
		{//parallel or coincident
		}
		else if(a.x1==a.x2)
		{
			x=a.x1;  m2=(b.y2-b.y1)/(b.x2-b.x1); y=m2*x - m2*b.x1 + b.y1;
			t1=calty(a,y);
			t2=caltx(b,x);
			if(t1>=0&&t2>=0&&t1<=1&&t2<=1)
			{
				tmp.x=x;tmp.y=y;tmp.t=t1;tmp.l=j;tmp.io=calio(a,b);
				s[i].push_back(tmp);
				tmp.t=t2;tmp.l=i; tmp.io=1-tmp.io;
				w[j].push_back(tmp);

			}

		}
		else
		{
			x=b.x1;  m1=(a.y2-a.y1)/(a.x2-a.x1); y=m1*x - m1*a.x1 + a.y1;
			t1=caltx(a,x);
			t2=calty(b,y);
			if(t1>=0&&t2>=0&&t1<=1&&t2<=1)
			{
				tmp.x=x;tmp.y=y;tmp.t=t1;tmp.l=j;tmp.io=calio(a,b);
				s[i].push_back(tmp);
				tmp.t=t2;tmp.l=i; tmp.io=1-tmp.io;
				w[j].push_back(tmp);

			}
		}
	}
	else
	{
		m1=(a.y2-a.y1)/(a.x2-a.x1);
		m2=(b.y2-b.y1)/(b.x2-b.x1);
		if(m1==m2)
		{//parallel or coincident lines
		}
		else
		{
			x=(b.y1-a.y1)/(m1-m2) +(m1*a.x1-m2*b.x1)/(m1-m2);
			y=m1*(x-a.x1)+ a.y1;
			t1=caltx(a,x);
			t2=caltx(b,x);
			if(t1>=0&&t2>=0&&t1<=1&&t2<=1)
			{
				tmp.x=x;tmp.y=y;tmp.t=t1;tmp.l=j;tmp.io=calio(a,b);
				s[i].push_back(tmp);
				tmp.t=t2;tmp.l=i; tmp.io=1-tmp.io;
				w[j].push_back(tmp);

			}

		}
	}
}
bool comp(struct pt a,struct pt b)
{
	if(a.t<b.t)return true;
	return false;
}
void inp(int n1,int n2)
{
	setcolor(YELLOW);
	for(int i=0;i<n1;i++)
	{
		cin>>sub[i].x1>>sub[i].y1>>sub[i].x2>>sub[i].y2;
		line(sub[i].x1,sub[i].y1,sub[i].x2,sub[i].y2);
	}
	setcolor(RED);
	for(int i=0;i<n2;i++)
	{
		cin>>win[i].x1>>win[i].y1>>win[i].x2>>win[i].y2;
		line(win[i].x1,win[i].y1,win[i].x2,win[i].y2);
	}

}
void atherton2(int a,int b,float cx[],float cy[])
{
	if(s[a][b].vis==1)return;
	s[a][b].vis=1;
	cx[csz]=s[a][b].x;cy[csz]=s[a][b].y;csz++;
	if(s[a][b].io==0)
	{
		int i=a,j=b+1;
		for(;j<s[i].size();j++)
		if(s[i][j].vis==1)return;
		else
		{
			s[i][j].vis=1;
	        cx[csz]=s[i][j].x;cy[csz]=s[i][j].y;csz++;
	        if(s[i][j].io==1)
	        break;
		}
		if(j==s[i].size())
		{

			while(1)
			{
				i=(i+1)%n1;
				for(j=0;j<s[i].size();j++)
				if(s[i][j].vis==1)return;
				else
				{
					s[i][j].vis=1;
	       		 	cx[csz]=s[i][j].x;cy[csz]=s[i][j].y;csz++;
	        		if(s[i][j].io==1)
	       			 break;
				}
				if(j!=s[i].size())break;
			}

		}
		a=s[i][j].l;b=s[i][j].m;
	}
	int i=a,j=b+1;
	for(;j<w[i].size();j++)
	{
		if(w[i][j].io==1)
		break;
		cx[csz]=w[i][j].x;cy[csz]=w[i][j].y;csz++;

	}
	if(j==w[i].size())
	{
		while(1)
		{
			i=(i+1)%n2;
			for(j=0;j<w[i].size();j++)
			{

				if(w[i][j].io==1)
				break;
				cx[csz]=w[i][j].x;cy[csz]=w[i][j].y;csz++;
			}
			if(j!=w[i].size())break;
		}
	}
	atherton2(w[i][j].l,w[i][j].m,cx,cy);
}
void atherton(int n1,int n2)
{
	struct pt t;
	sub[100].x1=INT_MAX;sub[100].y1=INT_MAX;
	sub[100].x2=INT_MIN;sub[100].y2=INT_MIN;
	for(int i=0;i<n1;i++)
	{
		t.x=sub[i].x1;t.y=sub[i].y1;t.io=-1;t.l=-1;t.t=0;
		s[i].push_back(t);
		if(sub[100].x1>sub[i].x1)sub[100].x1=sub[i].x1;
		if(sub[100].y1>sub[i].y1)sub[100].y1=sub[i].y1;
		if(sub[100].x2<sub[i].x1)sub[100].x2=sub[i].x1;
		if(sub[100].y2<sub[i].y1)sub[100].y2=sub[i].y1;
	}
	win[100].x1=INT_MAX;win[100].y1=INT_MAX;
	win[100].x2=INT_MIN;win[100].y2=INT_MIN;
	for(int i=0;i<n2;i++)
	{
		t.x=win[i].x1;t.y=win[i].y1;t.io=-1;t.l=-1;t.t=0;
		w[i].push_back(t);
		if(win[100].x1>win[i].x1)win[100].x1=win[i].x1;
		if(win[100].y1>win[i].y1)win[100].y1=win[i].y1;
		if(win[100].x2<win[i].x1)win[100].x2=win[i].x1;
		if(win[100].y2<win[i].y1)win[100].y2=win[i].y1;


	}
	for(int i=0;i<n1;i++)
	for(int j=0;j<n2;j++)
	inst(sub[i],win[j],i,j);

	for(int i=0;i<n1;i++)
	sort(s[i].begin(),s[i].begin()+s[i].size(),comp);

	for(int i=0;i<n2;i++)
	sort(w[i].begin(),w[i].begin()+w[i].size(),comp);

	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<s[i].size();j++)
		{
			s[i][j].vis=0;
			if(j!=0)
			{
				for(int k=0;k<w[s[i][j].l].size();k++)
				if(s[i][j].x==w[s[i][j].l][k].x&&s[i][j].y==w[s[i][j].l][k].y&&(1-s[i][j].io)==w[s[i][j].l][k].io&&w[s[i][j].l][k].l==i)
				{
					s[i][j].m=k;
					w[s[i][j].l][k].m=j;
					break;
				}
			}
		}
	}
	float cx[100],cy[100];
	//delay(5000);
	getch();
	cleardevice();

	setcolor(GREEN);
	int cnt=0;
	for(int i=0;i<n1;i++)
	for(int j=1;j<s[i].size();j++)
	{
		cnt++;
		if(s[i][j].vis==0)
		{
			csz=0;atherton2(i,j,cx,cy);
			cout<<"$\n";
			for(int k=0;k<csz;k++)
			{
				cout<<endl<<cx[k]<<" "<<cy[k];
				line(cx[k],cy[k],cx[(k+1)%csz],cy[(k+1)%csz]);
			}

		}
	}
	if(cnt==0)
	{
		if(sub[100].x1<=win[100].x1&&sub[100].y1<=win[100].y1&&sub[100].x2>=win[100].x2&&sub[100].y2>=win[100].y2)
		{
			//print wind
			for(int i=0;i<n2;i++)
			line(win[i].x1,win[i].y1,win[i].x2,win[i].y2);
		}
		else if(sub[100].x1>=win[100].x1&&sub[100].y1>=win[100].y1&&sub[100].x2<=win[100].x2&&sub[100].y2<=win[100].y2)
		{
			for(int i=0;i<n1;i++)
			line(sub[i].x1,sub[i].y1,sub[i].x2,sub[i].y2);
			// print sub
		}

	}


}
int main()
{
	initwindow(1000,640, "Window");
	setbkcolor(15);cleardevice();
	cin>>n1>>n2;
	inp(n1,n2);
	getch();
	atherton(n1,n2);
	cout<<"SUBJECT"<<endl;
	for(int i=0;i<n1;i++)
	{
		cout<<endl;
		for(int j=0;j<s[i].size();j++)
	cout<<s[i][j].x<<","<<s[i][j].y<<" ,"<<s[i][j].io<<" ,"<<s[i][j].l<<" ,"<<s[i][j].m<<"  ";
	}

		cout<<"WINDOW"<<endl;
	for(int i=0;i<n2;i++)
	{
		cout<<endl;
		for(int j=0;j<w[i].size();j++)
	cout<<w[i][j].x<<","<<w[i][j].y<<","<<w[i][j].io<<","<<w[i][j].l<<","<<w[i][j].m<<" ";
	}
	getch();


}
/*
3 4
70 200 200 600
200 600 200 200
200 200 70 200
100 100 100 500
100 500 500 500
500 500 500 100
500 100 100 100


3 4
70 200 300 500
300 500 400 600
400 600 70 200
100 100 100 500
100 500 500 500
500 500 500 100
500 100 100 100


3 3
100 200 200 500
200 500 400 200
400 200 100 200
100 400 400 400
400 400 200 100
200 100 100 400

3 4
200 200 400 200
400 200 200 400
200 400 200 200
100 100 100 500
100 500 500 500
500 500 500 100
500 100 100 100

3 4
70 200 200 400
200 400 200 200
200 200 70 200
100 100 100 400
100 400 400 400
400 400 400 100
400 100 100 100

4 4
50 250 250 450
250 450 450 250
450 250 250 50
250 50 50 250
100 100 100 400
100 400 400 400
400 400 400 100
400 100 100 100

*/


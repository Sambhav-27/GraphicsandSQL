#include<iostream>
#include<graphics.h>
#include<vector>
#include<algorithm>
using namespace std;

struct nd
{
	float x,y,m;
};
vector<struct nd>v[1000],c;
void swap(float *a,float *b)
{
	float t;
	t= *a; *a= *b; *b=t;
}
void build(int n)
{
	float x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	line(x1,y1,x2,y2);
	if(y2<y1)
	{
		swap(&y1,&y2);
		swap(&x1,&x2);
	}
	if(y1!=y2)
	{
		struct nd t;
		t.y=y2;t.x=x1;t.m=(x2-x1)/(y2-y1);
		v[(int)y1].push_back(t);
	}

}
bool comp(struct nd a,struct nd b)
{
	if(a.x<b.x)return true;
	else if(a.x>b.x)return false;
	else
	{
		if(a.m<b.m)return true;
		else return false;
	}
}
int main()
{

	int n;
	cin>>n;

	initwindow(1000,1000);
	//setbkcolor(15);
	cleardevice();
	//setcolor(BLACK);
	for(int i=1;i<=n;i++)build(n);
	setcolor(CYAN);
	delay(1000);
	for(int i=100;i<=1000;i++)
	{
		for(int j=0;j<v[i].size();j++)
		c.push_back(v[i][j]);

		for(int j=0;j<c.size();)
		 {
		 	if(c[j].y==i)
			 {
			 	c.erase(c.begin()+j);
			 }
		 	else j++;
		 }
		sort(c.begin(),c.begin()+c.size(),comp);
		 for(int j=0;j<c.size();j=j+2)
		 {
		 	line(c[j].x,i,c[j+1].x,i);
		 	c[j].x+=c[j].m;c[j+1].x+=c[j+1].m;
		 }
	}
	getch();

	return 0;
}
/*6
300 100 500 350
500 350 500 600
500 600 300 500
300 500 200 600
200 600 200 300
200 300 300 100

3
100 100 500 100
500 100 300 500
300 500 100 100


*/


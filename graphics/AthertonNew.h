#include<graphics.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define MAX 100000
using namespace std;

struct Point
{
	float x,y;
};

bool sorting(pair<pair<float,int>,Point>  a,pair<pair<float,int>,Point>  b)
{
	return a.first.first<b.first.first;
}


Point intersectpoint(Point p1,Point p2,Point q1,Point q2)
{
	Point p;
	p.x=MAX;
	p.y=MAX;
	Point n;
	if((q2.x-q1.x)>=0 && (q2.y-q1.y)>=0)
	{
		n.x=-1*fabs(q2.y-q1.y);
		n.y=fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)<=0 && (q2.y-q1.y)>=0)
	{
		n.x=-1*fabs(q2.y-q1.y);
		n.y=-1*fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)<=0 && (q2.y-q1.y)<=0)
	{
		n.x=fabs(q2.y-q1.y);
		n.y=-1*fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)>=0 && (q2.y-q1.y)<=0)
	{
		n.x=fabs(q2.y-q1.y);
		n.y=fabs(q2.x-q1.x);
	}
	float den=(n.x*(p2.x-p1.x)+n.y*(p2.y-p1.y));
	float num=(n.x*(p1.x-q1.x)+n.y*(p1.y-q1.y));
	float t=num/(-1*den);

	if((p2.x-p1.x)>=0 && (p2.y-p1.y)>=0)
	{
		n.x=-1*fabs(p2.y-p1.y);
		n.y=fabs(p2.x-p1.x);
	}
	else if((p2.x-p1.x)<=0 && (p2.y-p1.y)>=0)
	{
		n.x=-1*fabs(p2.y-p1.y);
		n.y=-1*fabs(p2.x-p1.x);
	}
	else if((p2.x-p1.x)<=0 && (p2.y-p1.y)<=0)
	{
		n.x=fabs(p2.y-p1.y);
		n.y=-1*fabs(p2.x-p1.x);
	}
	else if((p2.x-p1.x)>=0 && (p2.y-p1.y)<=0)
	{
		n.x=fabs(p2.y-p1.y);
		n.y=fabs(p2.x-p1.x);
	}
	float den1=(n.x*(q2.x-q1.x)+n.y*(q2.y-q1.y));
	float num1=n.x*(q1.x-p1.x)+n.y*(q1.y-p1.y);
	float t1=num1/(-1*den1);

	if((t>=0 && t<=1) && (t1>=0 && t1<=1))
	{
	p.x=p1.x+(p2.x-p1.x)*t;
	p.y=p1.y+(p2.y-p1.y)*t;
	}
	return p;
}




float tval(Point p1,Point p2,Point q1,Point q2)
{
	Point p;
	p.x=MAX;
	p.y=MAX;
	Point n;
	if((q2.x-q1.x)>=0 && (q2.y-q1.y)>=0)
	{
		n.x=-1*fabs(q2.y-q1.y);
		n.y=fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)<=0 && (q2.y-q1.y)>=0)
	{
		n.x=-1*fabs(q2.y-q1.y);
		n.y=-1*fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)<=0 && (q2.y-q1.y)<=0)
	{
		n.x=fabs(q2.y-q1.y);
		n.y=-1*fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)>=0 && (q2.y-q1.y)<=0)
	{
		n.x=fabs(q2.y-q1.y);
		n.y=fabs(q2.x-q1.x);
	}
	float den=(n.x*(p2.x-p1.x)+n.y*(p2.y-p1.y));
	float num=(n.x*(p1.x-q1.x)+n.y*(p1.y-q1.y));
	float t=num/(-1*den);

	if((p2.x-p1.x)>=0 && (p2.y-p1.y)>=0)
	{
		n.x=-1*fabs(p2.y-p1.y);
		n.y=fabs(p2.x-p1.x);
	}
	else if((p2.x-p1.x)<=0 && (p2.y-p1.y)>=0)
	{
		n.x=-1*fabs(p2.y-p1.y);
		n.y=-1*fabs(p2.x-p1.x);
	}
	else if((p2.x-p1.x)<=0 && (p2.y-p1.y)<=0)
	{
		n.x=fabs(p2.y-p1.y);
		n.y=-1*fabs(p2.x-p1.x);
	}
	else if((p2.x-p1.x)>=0 && (p2.y-p1.y)<=0)
	{
		n.x=fabs(p2.y-p1.y);
		n.y=fabs(p2.x-p1.x);
	}
	float den1=(n.x*(q2.x-q1.x)+n.y*(q2.y-q1.y));
	float num1=n.x*(q1.x-p1.x)+n.y*(q1.y-p1.y);
	float t1=num1/(-1*den1);

	if((t>=0 && t<=1) && (t1>=0 && t1<=1))
	return t;
	else
	return -1;
}


int otoi(Point p1,Point p2,Point q1,Point q2)
{
	Point n;
	if((q2.x-q1.x)>=0 && (q2.y-q1.y)>=0)
	{
		n.x=-1*fabs(q2.y-q1.y);
		n.y=fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)<=0 && (q2.y-q1.y)>=0)
	{
		n.x=-1*fabs(q2.y-q1.y);
		n.y=-1*fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)<=0 && (q2.y-q1.y)<=0)
	{
		n.x=fabs(q2.y-q1.y);
		n.y=-1*fabs(q2.x-q1.x);
	}
	else if((q2.x-q1.x)>=0 && (q2.y-q1.y)<=0)
	{
		n.x=fabs(q2.y-q1.y);
		n.y=fabs(q2.x-q1.x);
	}
	float den=(n.x*(p2.x-p1.x)+n.y*(p2.y-p1.y));
	if(den<0)
	return -1;//Potentially entering o to i
	else
	return 1;//Potentially Leaving i to o
}

void Weiler(Point sub[],Point win[],int ns,int nw)
{
	vector< pair<int, Point> >v;
	vector< pair<int, Point> >v1;
	vector< pair <pair<float,int> , Point>  > temp;

	for(int i=0;i<ns;i++)
	{
	if(i==0)
	v.push_back(pair<int,Point>(0,sub[i]));
	int j=(i+1)%ns;
	for(int k=0;k<nw;k++)
	{
	int l=(k+1)%nw;
	float t=tval(sub[i],sub[j],win[k],win[l]);
	if(t!=-1)
	{
	Point h=intersectpoint(sub[i],sub[j],win[k],win[l]);
	int i1=otoi(sub[i],sub[j],win[k],win[l]);
	temp.push_back(pair < pair< float,int > ,Point> ( make_pair(t,i1) ,h) );
	//printf("%f %d %f %f\n",temp[k].first.first,temp[k].first.second,temp[k].second.x,temp[k].second.y);
	}
	}
	sort(temp.begin(),temp.end(),sorting);
	for(int i=0;i<temp.size();i++)
	v.push_back(pair<int,Point>(temp[i].first.second,temp[i].second));
	temp.clear();
	v.push_back(pair<int,Point>(0,sub[j]));
	}



	for(int i=0;i<nw;i++)
	{
	if(i==0)
	v1.push_back(pair<int,Point>(0,win[i]));
	int j=(i+1)%nw;
	for(int k=0;k<ns;k++)
	{
	int l=(k+1)%ns;
	float t=tval(win[i],win[j],sub[k],sub[l]);
	if(t!=-1)
	{
	Point h=intersectpoint(win[i],win[j],sub[k],sub[l]);
	int i1=otoi(win[i],win[j],sub[k],sub[l]);
	temp.push_back(pair < pair< float,int > ,Point> ( make_pair(t,i1) ,h) );
	//printf("%f %d %f %f\n",temp[k].first.first,temp[k].first.second,temp[k].second.x,temp[k].second.y);
	}
	}
	sort(temp.begin(),temp.end(),sorting);
	for(int i=0;i<temp.size();i++)
	v1.push_back(pair<int,Point>(temp[i].first.second,temp[i].second));
	temp.clear();
	v1.push_back(pair<int,Point>(0,win[j]));
	}

	int tempv[v.size()];
	int tempv1[v1.size()];

	for(int i=0;i<v.size();i++)
	tempv[i]=0;

	for(int i=0;i<v1.size();i++)
	tempv1[i]=0;


//	for(int i=0;i<v.size();i++)
//	{
//		cout<<v[i].first<<" "<<v[i].second.x<<" "<<v[i].second.y<<" "<<endl;
//	}
//
//	for(int i=0;i<v1.size();i++)
//	{
//		cout<<v1[i].first<<" "<<v1[i].second.x<<" "<<v1[i].second.y<<" "<<endl;
//	}


	vector<Point> draw;
	while(1)
	{
		int i=0;
		while((v[i].first==0 || tempv[i]==1) && i<(v.size()))
		i++;
	//	cout<<i<<endl;
		char c='f';
		if(i<v.size())
		{
		int j=i;
		while(1)
		{
		if(tempv[j]!=1 && c=='f')
		{
		tempv[j]=1;
//		cout<<v[j].second.x<<"LL "<<v[j].second.y<<endl;
		draw.push_back(v[j].second);
	//	cout<<draw[0].x<<" KK"<<draw[0].y<<endl;
		j=(j+1)%v.size();
		if(v[j].first==1)
		{
		tempv[j]=1;
		int k;
		for(k=0;k<v1.size();k++)
		{
	//		cout<<v1[k].second.x<<"Equal"<<v[j].second.x<<endl;
			if(0.01>=fabs(v1[k].second.x-v[j].second.x) && 0.01>=fabs(v1[k].second.y-v[j].second.y))
			break;
		}
		j=k;
		c='s';
	//	cout<<j<<"Itna"<<endl;
		}
		}



		else if(c=='s' && tempv1[j]!=1)
		{
//		cout<<j<<endl;
		tempv1[j]=1;
		draw.push_back(v1[j].second);
		j=(j+1)%v1.size();
		if(v1[j].first==1)
		{
		int k;
		tempv1[j]=1;
		for(k=0;k<v.size();k++)
		{
			if(0.001>=fabs(v[k].second.x-v1[j].second.x) && 0.001>=fabs(v[k].second.y-v1[j].second.y))
			break;
		}
		j=k;
	//	cout<<j<<endl;
		c='f';
		}
		}
		else if(j==i)
		{
	//		cout<<c<<" "<<j<<" "<<v.size()<<" "<<v1.size()<<endl;
			draw.push_back(v[j].second);
			break;
		}
		}
		for(int i1=0;i1<draw.size();i1++)
		{
			int j1=(i1+1)%draw.size();
	//		printf("%f %f %f %f \n",draw[i1].x,draw[i1].y,draw[j1].x,draw[j1].y);
			line(draw[i1].x,draw[i1].y,draw[j1].x,draw[j1].y);
		}
	//	cout<<endl;
		draw.clear();
		}
		else
		break;
	}


}


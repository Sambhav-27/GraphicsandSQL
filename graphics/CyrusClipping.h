//Cyrus-Beck Line Clipping

#include<graphics.h>
#include<math.h>
#include<algorithm>
struct Point 
{
	float x,y;
	
};


using namespace std;



void cyrus(Point arr[],int n,Point p1,Point p2)
{
	//Check for concave
		Point qq[n];
	for(int i=0;i<n;i++)
	{
		int j;
		if(i==n-1)
		j=0;
		else 
		j=i+1;
		qq[i].x=arr[j].x-arr[i].x;
		qq[i].y=arr[j].y-arr[i].y;
	}
	int flag=0;int flag1=0,noconcavity=0;
	for(int i=0;i<n;i++)
	{
		int j;
		if(i==n-1)
		j=0;
		else 
		j=i+1;
		float w=qq[i].x*qq[j].y-qq[i].y*qq[j].x;
		if(w<0)
		flag++;
		else
		flag1++;
	}
	int con=0;
	if(flag==n || flag1==n)
	con=0;
	else con=1;

	int counter=0;
	Point normal[n];
	Point p;
	float t[n];
	int chk[n];
	p.x=p2.x-p1.x;
	p.y=p2.y-p1.y;
	for(int i=0;i<n;i++)
	{
		
		int j;
		if(i==n-1)
		j=0;
		else 
		j=i+1;
		
		
		
		
		float x1=arr[j].x-arr[i].x;
		float y1=arr[j].y-arr[i].y;
		Point Pei;
		Pei.x=p1.x-arr[i].x;
		Pei.y=p1.y-arr[i].y;
		if(x1>=0 && y1>=0)
		{
			normal[i].x=-1*fabs(y1);
			normal[i].y=fabs(x1);
		}
		else if(x1<=0 && y1 >=0)
		{
			normal[i].x=-1*fabs(y1);
			normal[i].y=-1*fabs(x1);
		}
		else if(x1<=0 && y1 <=0)
		{
			normal[i].x=fabs(y1);
			normal[i].y=-1*fabs(x1);
		}
		else
		{
			normal[i].x=fabs(y1);
			normal[i].y=fabs(x1);
		}
		float den=((p.x)*(normal[i].x)+(p.y)*(normal[i].y));
		t[i]=((Pei.x*normal[i].x)+(Pei.y*normal[i].y))/(-1*den);
		if(den==0)
		t[i]=-3;
		
		if(t[i]>=0 && t[i]<=1)
		{
		Point norm;
		float x2=p.x;
		float y2=p.y;
		Point Pei1;
		Point ptemp;
		ptemp.x=arr[j].x-arr[i].x;
		ptemp.y=arr[j].y-arr[i].y;
		Pei1.x=arr[i].x-p1.x;
		Pei1.y=arr[i].y-p1.y;
		if(x2>=0 && y2>=0)
		{
			norm.x=-1*fabs(y2);
			norm.y=fabs(x2);
		}
		else if(x2<=0 && y2 >=0)
		{
			norm.x=-1*fabs(y2);
			norm.y=-1*fabs(x2);
		}
		else if(x2<=0 && y2 <=0)
		{
			norm.x=fabs(y2);
			norm.y=-1*fabs(x2);
		}
		else
		{
			norm.x=fabs(y2);
			norm.y=fabs(x2);
		}
		float den1=((ptemp.x)*(norm.x)+(ptemp.y)*(norm.y));
		float tempor=((Pei1.x*norm.x)+(Pei1.y*norm.y))/(-1*den1);
		if(tempor<0 || tempor>1)
		t[i]=-2;
		}
		
		
		
	
		if(t[i]<0 || t[i]>1)
		{
		counter++;
		chk[i]=-1;
		}
		else if(den<0)
		{
		noconcavity++;
		chk[i]=0;
		}
		else if(den>0)
		{
		noconcavity++;
		chk[i]=1;
		}
	}
	
		
		if(con==0 || noconcavity==2)
		{
		float t1=0,t2=1;
		for(int i=0;i<n;i++)
		{
			if(chk[i]==0)
			t1=max(t1,t[i]);
			else if(chk[i]==1)
			t2=min(t2,t[i]);
		}
	
		float temp1=p1.x;
		float temp2=p1.y;
		p1.x=temp1+(p.x)*t1;
		p1.y=temp2+(p.y)*t1;
		p2.x=temp1+(p.x)*t2;
		p2.y=temp2+(p.y)*t2;

		if(counter!=n)
		line(p1.x,p1.y,p2.x,p2.y);
		}
		
		
		else if(con==1)
		{
			float h[n],h2[n];
			int k=0,l=0;
			for(int i=0;i<n;i++)
			{
				if((0<=t[i]<=1))
				{
				if(chk[i]==0)
				{
				h[k++]=t[i];
				}
				else if(chk[i]==1)
				{
				h2[l++]=t[i];
				}
				}
			}
			sort(h,h+k);
			sort(h2,h2+l);
			float temp1=p1.x;
			float temp2=p1.y;

			for(int i=0;i<k;i++)
			{
				p1.x=temp1+(p.x)*h[i];
				p1.y=temp2+(p.y)*h[i];
				p2.x=temp1+(p.x)*h2[i];
				p2.y=temp2+(p.y)*h2[i];
				if(counter!=n)
				line(p1.x,p1.y,p2.x,p2.y);
			}
		}	
		
}


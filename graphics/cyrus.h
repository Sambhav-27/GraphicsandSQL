#include<algorithm>
struct point{
	int x,y;
};
bool alternate(int a[], int n)
{
    int i;
    for(i=1;i<=n;i+=2)
    {
        if(a[1]>0)
        {
            if(a[i]<0) return 0;
        }
        else if(a[1]<=0)
        {
            if(a[i]>0) return 0;
        }
    }
    for(i=2;i<=n;i+=2)
    {
        if(a[2]>0)
        {
            if(a[i]<0) return 0;
        }
        else if(a[2]<=0)
        {
            if(a[i]>0) return 0;
        }
    }
    return 1;
}


void cyrus_beck(point p[], int n, point p1, point p2)
{
    point p1p2, temp[10], v[10];
    int k, sum, i[10], j[10];
	double t[10];
    p1p2.x= p2.x-p1.x;
	p1p2.y= p2.y-p1.y;


	for(k=1;k<n;++k)
	{
		v[k].x=p[k].x-p[k-1].x;
		v[k].y=p[k].y-p[k-1].y;
	}
	v[n].x=p[0].x-p[n-1].x;
	v[n].y=p[0].y-p[n-1].y;



	for(k=1;k<n;++k)
	{
		//m= (y[k]- y[k-1])/ (x[k]-x[k-1]);
		if(p[k].x>p[k-1].x && p[k].y>p[k-1].y) // 1st quad 0 < m && m < INT_MAX &&
		{
			i[k]= -abs(v[k].y);
			j[k]= abs(v[k].x);
		}
		else if( p[k].x>p[k-1].x && p[k].y< p[k-1].y) // 2nd quad INT_MIN < m && m < 0 &&
		{
			i[k]= abs(v[k].y);
			j[k]= abs(v[k].x);
		}
		else if( p[k].x<p[k-1].x && p[k].y<p[k-1].y)// 3rd quad  0 < m && m < INT_MAX &&
		{
			i[k]= abs(v[k].y);
			j[k]= -abs(v[k].x);
		}
		else if(p[k].x<p[k-1].x && p[k].y>p[k-1].y) // 4th quad  INT_MIN <m && m< 0 &&
		{
			i[k]= -abs(v[k].y);
			j[k]= -abs(v[k].x);
		}

		 // for the last edge
		if(p[0].x>p[n-1].x && p[0].y>p[n-1].y) // 1st quad 0 < m && m < INT_MAX &&
		{
			i[n]= -abs(v[n].y);
			j[n]= abs(v[n].x);
		}
		else if( p[0].x>p[n-1].x && p[0].y< p[n-1].y) // 2nd quad INT_MIN < m && m < 0 &&
		{
			i[n]= abs(v[n].y);
			j[n]= abs(v[n].x);
		}
		else if( p[0].x<p[n-1].x && p[0].y<p[n-1].y)// 3rd quad  0 < m && m < INT_MAX &&
		{
			i[n]= abs(v[n].y);
			j[n]= -abs(v[n].x);
		}
		else if(p[0].x<p[n-1].x && p[0].y>p[n-1].y) // 4th quad  INT_MIN <m && m< 0 &&
		{
			i[n]= -abs(v[n].y);
			j[n]= -abs(v[n].x);
		}
	}

		sum=0;
	for(k=1;k<n;++k)
	sum+= (p[k].x-p[k-1].x) * (p[k].y+p[k-1].y);
	sum+= (p[0].x-p[n-1].x) * (p[0].y+p[n-1].y);

	if(sum<0) // anti CW
	{
		for(k=1;k<=n;++k)
		{
			i[k]*=-1; j[k]*=-1;
		}
	}

		for(k=1;k<=n;++k)
		{
			temp[k].x= p1.x- p[k-1].x;
			temp[k].y= p1.y- p[k-1].y;
		}

		for(k=1;k<=n;++k)
		t[k]=  -1* (i[k]*temp[k].x + j[k]*temp[k].y ) / ( t[k]= i[k]*p1p2.x + j[k]*p1p2.y );

		for(k=1;k<=n;++k)
		std::cout<<t[k]<<"  ";

        std::cout<<"\n\n";
        int sign[10];
		for(k=1;k<=n;++k)
		{
			//std::cout<<i[k]<<"i "<<j[k]<<"j\n";
			sign[k]= i[k]*p1p2.x+j[k]*p1p2.y;
			//std::cout<<sign[k]<<" ";
		}
        t[0]=-3000;
		std::sort(t, t+n+1);
        if(alternate(sign, n))
        {
            setcolor(YELLOW);
            int i,x1,y1,x2,y2;
            for(i=1;i<n;i+=2)
            {
                x1=p1.x+(p2.x-p1.x)*t[i];
                y1=p1.y+(p2.y-p1.y)*t[i];
                x2=p1.x+(p2.x-p1.x)*t[i+1];
                y2=p1.y+(p2.y-p1.y)*t[i+1];
                std::cout<<"yes\n"<<x1<<", "<<y1<<"   "<<x2<<", "<<y2<<"\n";
                line(x1,y1,x2,y2);
            }
        }
        else
        {
            int i;
            float t1,t2,x1,y1,x2,y2;
            t1=300;
            t2=t[1];
            for(i=1;i<=n;++i)
            {
                if(t[i]>t2 && t[i]<=1)
                    t2=t[i];
                if(t[i]<t1 && t[i]>=0)
                    t1=t[i];
            }
            setcolor(YELLOW);
            std::cout<<"here\n\n"<<t1<<"  "<<t2;
            x1=p1.x+(p2.x-p1.x)*t1;
            y1=p1.y+(p2.y-p1.y)*t1;
            x2=p1.x+(p2.x-p1.x)*t2;
            y2=p1.y+(p2.y-p1.y)*t2;
            std::cout<<"yes\n"<<x1<<", "<<y1<<"   "<<x2<<", "<<y2<<"\n";
            line(x1,y1,x2,y2);
        }
}


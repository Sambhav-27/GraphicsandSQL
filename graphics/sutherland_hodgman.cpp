#include<iostream>
#include<graphics.h>
#include<stdio.h>

using namespace std;
struct point{
	int x,y;
};

int xmin=20, xmax=200, ymin=20, ymax=150;
int check(int a1, int b1, int c1, point p1, point p2) // check if two point lie on same side of a line
{
	int x1,x2;
	x1= (a1*p1.x + b1*p1.y - c1);
	x2= (a1*p2.x + b1*p2.y - c1);

	if((x1>0 && x2>0) || (x1<0 && x2<0))
	return 1;
	else
	return 0;
}
int direction(point v1, point v2, point p1, point p2)
{
    if(v1.x==v2.x && v2.x==xmin) // left edge
    {
        if( (p1.x >v1.x) && (p2.x > v1.x) )
            return 1; // i to i
        else if( (p1.x> v1.x) && (p2.x <v1.x) )
            return 2; // i to o
        else if( (p1.x < v1.x) && (p2.x > v1.x) )
            return 3; // outside to inside
        else if( (p1.x< v1.x) && (p2.x <v1.x) )
            return 4; // o to o
    }
    else if(v1.x==v2.x && v2.x==xmax) // right edge
    {
        if( (p1.x <v1.x) && (p2.x < v1.x) )
            return 1; // i to i
        else if( (p1.x< v1.x) && (p2.x >v1.x) )
            return 2; // i to o
        else if( (p1.x < v1.x) && (p2.x > v1.x) )
            return 3; // outside to inside
        else if( (p1.x> v1.x) && (p2.x >v1.x) )
            return 4; // o to o
    }

    else if(v1.y==v2.x && v2.y==ymin) // Bottom edge
    {
        if( (p1.y >v1.y) && (p2.y > v1.y) )
            return 1; // i to i
        else if( (p1.y> v1.y) && (p2.y <v1.y) )
            return 2; // i to o
        else if( (p1.y < v1.y) && (p2.y > v1.y) )
            return 3; // outside to inside
        else if( (p1.y< v1.y) && (p2.y <v1.y) )
            return 4; // o to o
    }
    else if(v1.y==v2.x && v2.y==ymax) // right edge
    {
        if( (p1.y <v1.y) && (p2.y < v1.y) )
            return 1; // i to i
        else if( (p1.y< v1.y) && (p2.y >v1.y) )
            return 2; // i to o
        else if( (p1.y < v1.y) && (p2.y > v1.y) )
            return 3; // outside to inside
        else if( (p1.y> v1.y) && (p2.y >v1.y) )
            return 4; // o to o
    }
}
point intersect(point v1, point v2, point p1, point p2)
{
	point inter;
	int a1,b1,c1, a2,b2,c2;
	a1= v2.y-v1.y;
	b1= v1.x-v2.x;
	c1= a1*v1.x+b1*v1.y;

	a2= p2.y-p1.y;
	b2= p1.x-p2.x;
	c2= a2*p1.x+b2*p1.y;

	int flag=check(a1, b1, c1, p1, p2);
	if(flag)
	{
		inter.x=-1; inter.y=-1;
		return inter;
	}

	double det= a1*b2 - a2*b1;
	if(det==0)
	{
		inter.x=-1; inter.y=-1;
	}
	else
	{
		inter.x= (b2*c1 - b1*c2)/det;
		inter.y= (a1*c2 - a2*c1)/det;
	}

	return inter;
}
void suther_hodgman(point v[], point  p[], int n1,  int n2) // n1 is no of vertices in v and n2 in p; v is the window
{
	int i=1,j,k=0,n3=0;
	point p1, p2, v1, v2, temp[10];

	//for(i=1;i<n1;++i)
    {
        v1=v[i];
        v2=v[i-1];
        k=0;
        for(j=1;j<n2;++j)
        {
            p1=p[i-1];  // CW
            p2=p[i];

            int x=direction(v1, v2, p1, p2);
            if(x==1) // i to i
            {
                temp[k++]=p2;
            }
            else if(x==2) // i to o
            {
                point inter=intersect(v1, v2, p1, p2);
                temp[k++]=inter;
            }
            else if(x==3) // o to i
            {
                point inter=intersect(v1, v2, p1, p2);
                temp[k++]=inter;
                temp[k++]=p2;

                cout<<inter.x<<", "<<inter.y<<"\n";
            }
        }


        temp[k++]=temp[0];
        for(j=0;j<k;++j)
        p[j]=temp[j];
        n2=k;

        cout<<"k: "<<k<<"\n  ";
    }


    for(i=1;i<n2;++i)
    {
    //    cout<<p[i].x<<", "<<p[i].y<<"\t";
        line(p[i].x, p[i].y, p[i-1].x, p[i-1].y);
    }

}
int main()
{
	/*point v1,v2,p1,p2;
	v1.x=1; v1.y=0;	v2.x=20; v2.y=0;

	p1.x=5; p1.y=-1; p2.x=5; p2.y=5;



	point temp= intersect(v1, v2, p1, p2);

			cout<<temp.x<<", "<<temp.y;*/

    int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "..\\bgi");


   point v[]={ {20,20}, {20,150}, {200, 150}, {200, 20}, {20, 20} }; //window; first point is repeated;
                                //with this update the global xmin xmax etc. also; provide points in CW order
   point p[]={ {0,65}, {100,170}, {220,65}, {100,0}, {0,65} }; // polygon

   int i, n1, n2;
   n1=5;
   n2=sizeof(p)/sizeof(p[0]);


    for(i=1;i<n1;++i)
    line(v[i].x, v[i].y, v[i-1].x, v[i-1].y);

    setcolor(YELLOW);
   //for(i=1;i<n2;++i)
   //line(p[i].x, p[i].y, p[i-1].x, p[i-1].y);

    suther_hodgman(v, p, n1, n2);

   getch();
   closegraph();

}

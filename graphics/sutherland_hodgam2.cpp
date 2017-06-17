#include<iostream>
#include<conio.h>
#include<graphics.h>

using namespace std;
struct point {   int x,y; };
int createlist(int i, point cl[], int nc, point s[], int ns)
{   point t[20];   int k=0;
  if(i==0)    // TOP EDGE
  {
    for(int j=0;j<ns;j++)
    {     // o -> i
        if(s[j].y<cl[0].y && s[j+1].y>cl[0].y)
	    {  //find point of intersection
		  int ax = int(((cl[0].y-s[j].y)*(s[j+1].x-s[j].x)/(s[j+1].y-s[j].y)*1.0)+s[j].x);
		   t[k].x = ax;  t[k].y = cl[0].y;  k++;  t[k] = s[j+1];  k++;
	    }
	     //i -> o
        else if(s[j].y>cl[0].y && s[j+1].y<cl[0].y)
	    { int ax = int(((cl[0].y-s[j].y)*(s[j+1].x-s[j].x)/(s[j+1].y-s[j].y)*1.0)+s[j].x);  t[k].x = ax;  t[k].y = cl[0].y;  k++;
	    }
	    //i -> i
        else if(s[j].y>=cl[0].y && s[j+1].y>=cl[0].y)
        {  t[k] = s[j+1];  k++;
	    }
	    //o -> o => do nothing
   }
  }
  else if(i==1)    // RIGHT EDGE
  {
    for(int j=0;j<ns;j++)
	{       // o -> i
	    if(s[j].x>cl[1].x && s[j+1].x<cl[1].x)
		{  //find point of intersection
		   int ay = int(((cl[1].x-s[j].x)*(s[j+1].y-s[j].y)/(s[j+1].x-s[j].x)*1.0)+s[j].y);  t[k].x = cl[1].x;  t[k].y = ay;  k++;  t[k] = s[j+1];  k++;
		}
		    //i -> o
	    else if(s[j].x<cl[1].x && s[j+1].x>cl[1].x)
		{  int ay = int(((cl[1].x-s[j].x)*(s[j+1].y-s[j].y)/(s[j+1].x-s[j].x)*1.0)+s[j].y);  t[k].x = cl[1].x;  t[k].y = ay;  k++;
		}
		     //i -> i
		else if(s[j].x<=cl[1].x && s[j+1].x<=cl[1].x)
		{  t[k] = s[j+1];  k++;
		}
   }
 }
 else if(i==2)      //  BOTTOM EDGE
 {
    for(int j=0;j<ns;j++)
    {       // o -> i
	    if(s[j].y>cl[2].y && s[j+1].y<cl[2].y)
		{  //find point of intersection
		int ax = int(((cl[2].y-s[j].y)*(s[j+1].x-s[j].x)/(s[j+1].y-s[j].y)*1.0)+s[j].x);  t[k].x = ax;  t[k].y = cl[2].y;  k++;  t[k] = s[j+1];  k++;
		}
		     //i -> o
	    else if(s[j].y<cl[2].y && s[j+1].y>cl[2].y)
		{
		int ax = int(((cl[2].y-s[j].y)*(s[j+1].x-s[j].x)/(s[j+1].y-s[j].y)*1.0)+s[j].x);  t[k].x = ax;  t[k].y = cl[2].y;  k++;
		}
		    //i -> i
	    else if(s[j].y<=cl[2].y && s[j+1].y<=cl[2].y)
		{
		t[k] = s[j+1];  k++;
		}
	}
 }
 else if(i==3)    //  LEFT EDGE
 {
    for(int j=0;j<ns;j++)
	{       // o -> i
	    if(s[j].x<cl[0].x && s[j+1].x>cl[0].x)
		{  //find point of intersection
		int ay = int(((cl[0].x-s[j].x)*(s[j+1].y-s[j].y)/(s[j+1].x-s[j].x)*1.0)+s[j].y);  t[k].x = cl[0].x;  t[k].y = ay;  k++;  t[k] = s[j+1];  k++;
		}
		    //i -> o
		else if(s[j].x>cl[0].x && s[j+1].x<cl[0].x)
		{
		int ay = int(((cl[0].x-s[j].x)*(s[j+1].y-s[j].y)/(s[j+1].x-s[j].x)*1.0)+s[j].y);  t[k].x = cl[0].x;  t[k].y = ay;  k++;
		}
		     //i -> i
		else if(s[j].x>=cl[0].x && s[j+1].x>=cl[0].x)
		{
		t[k] = s[j+1];  k++;
		}

    }
 }
 t[k]=t[0];
 for(int l=0;l<=k;l++)   {     s[l]=t[l];   }
 return k;
}

void suthodg( point cl[], int nc, point s[], int ns)
{
  for(int i=0;i<nc;i++)
  {
  ns = createlist(i, cl, nc, s, ns);
  }
  setcolor(GREEN);
  cout<<ns;
  for(int i=0;i<ns;i++)
  {
  line(s[i].x,s[i].y,s[i+1].x,s[i+1].y);
  }
}

int main()
{

  point cl[4];   point sub[10], dup_sub[10];
  int nc;   cout<<"    Clipping Polygon ";

  //min is top left and max is bottom right
  cout<<"\n Enter the co-ordinates (x,y) ";
  cout<<"\n Xwmin : ";   cin>>cl[0].x;
  cout<<"\n Ywmin : ";   cin>>cl[0].y;
  cout<<"\n Xwmax : ";   cin>>cl[2].x;
  cout<<"\n Ywmax : ";   cin>>cl[2].y;
  cl[1].x = cl[2].x;   cl[1].y = cl[0].y;   cl[3].x = cl[0].x;   cl[3].y = cl[2].y;
  int ns;
  cout<<"    Subject Polygon ";

  do
  {
  cout<<"\n Enter the no. of vertices : ";     cin>>ns;
  }while(ns>10);

  cout<<"\n Enter the co-ordinates in clockwise order (x,y) ";
  int i=0  ;
  for(;i<ns;i++)
  {
  cout <<i+1<<". ";     cin>>sub[i].x>>sub[i].y;     dup_sub[i] = sub[i];
  }
  sub[i] = sub[0];   dup_sub[i] = sub[0];
  int gdriver = DETECT, gmode;

  initgraph(&gdriver, &gmode, "");

  //setbkcolor(15);
  cleardevice();

  setcolor(RED);

  for(i=0;i<3;i++)
  {     line(cl[i].x, cl[i].y, cl[i+1].x, cl[i+1].y);
  }

  line( cl[3].x, cl[3].y, cl[0].x, cl[0].y);
  setcolor(YELLOW);
  for(i=0;i<ns;i++)
  {
  line(sub[i].x,sub[i].y,sub[i+1].x,sub[i+1].y);
  }
 // delay(5000);
 getch();
  cleardevice();
  suthodg(cl,4,dup_sub,ns);
  for(i=0;i<3;i++)
  {     line(cl[i].x, cl[i].y, cl[i+1].x, cl[i+1].y);
  }
  getch();
  closegraph();
}


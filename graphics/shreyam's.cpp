#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
struct Point
{
	int x,y,z;
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float side;
//Point G,C,D,E,F,A;
Point A={0,0,0};
Point G={80,80,80};
//int side=(B.x-H.x);
float ans[4][8];
float num[4][4];
float temp[4][8];
void Translate(int dx,int dy,int dz)
{
	float transmat[4][4];


	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			transmat[i][j]=0;
			if(i==j)
			transmat[i][j]=1;
		}
	}

	transmat[0][3]=dx;
	transmat[1][3]=dy;
	transmat[2][3]=dz;

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			temp[i][j]=0;
			for(int k=0;k<4;k++)
			{
				temp[i][j]+=transmat[i][k]*ans[k][j];
			}
		}
	}



	/*for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			ans[i][j]=temp[i][j];
		}
	}*/
}


void rotatey(int angle)
{
	float rotatemat[4][4];
	float angle1=M_PI/180*angle;

	rotatemat[0][0]=cos(angle1);
	rotatemat[0][1]=rotatemat[0][3]=rotatemat[1][0]=rotatemat[1][2]=rotatemat[1][3]=rotatemat[2][1]=rotatemat[2][3]=0;
	rotatemat[3][0]=rotatemat[3][1]=rotatemat[3][2]=0;
	rotatemat[0][2]=sin(angle1);
	rotatemat[2][0]=-1*sin(angle1);
	rotatemat[2][2]=cos(angle1);
	rotatemat[1][1]=rotatemat[3][3]=1;

	float temp[4][8];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			temp[i][j]=0;
			for(int k=0;k<4;k++)
			{
				temp[i][j]+=rotatemat[i][k]*ans[k][j];
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			ans[i][j]=temp[i][j];
		}
	}
}




void rotatex(int angle)
{
	float rotatemat[4][4];
	float angle1=M_PI/180*angle;

	rotatemat[1][1]=cos(angle1);
	rotatemat[0][1]=rotatemat[0][2]=rotatemat[0][3]=rotatemat[1][0]=rotatemat[1][3]=rotatemat[2][0]=rotatemat[2][3]=0;
	rotatemat[3][0]=rotatemat[3][1]=rotatemat[3][2]=0;
	rotatemat[2][1]=sin(angle1);
	rotatemat[1][2]=-1*sin(angle1);
	rotatemat[2][2]=cos(angle1);
	rotatemat[0][0]=rotatemat[3][3]=1;

	float temp[4][8];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			temp[i][j]=0;
			for(int k=0;k<4;k++)
			{
				temp[i][j]+=rotatemat[i][k]*ans[k][j];
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			ans[i][j]=temp[i][j];
		}
	}
}



void rotatez(int angle)
{
	float rotatemat[4][4];
	float angle1=M_PI/180*angle;

	rotatemat[0][0]=cos(angle1);
	rotatemat[0][2]=rotatemat[0][3]=rotatemat[1][2]=rotatemat[1][3]=rotatemat[2][0]=rotatemat[2][1]=rotatemat[2][3]=0;
	rotatemat[3][0]=rotatemat[3][1]=rotatemat[3][2]=0;
	rotatemat[1][0]=sin(angle1);
	rotatemat[0][1]=-1*sin(angle1);
	rotatemat[1][1]=cos(angle1);
	rotatemat[2][2]=rotatemat[3][3]=1;

	float temp[4][8];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			temp[i][j]=0;
			for(int k=0;k<4;k++)
			{
				temp[i][j]+=rotatemat[i][k]*ans[k][j];
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<8;j++)
		{
			ans[i][j]=temp[i][j];
		}
	}
}





void initial(Point A, Point G)
{
	for(int i=0;i<8;i++)
	ans[3][i]=1;

	ans[0][0]=A.x;
	ans[1][0]=A.y;
	ans[2][0]=A.z;

	ans[0][1]=G.x;
	ans[1][1]=A.y;
	ans[2][1]=A.z;

	ans[0][2]=G.x;
	ans[1][2]=A.y;
	ans[2][2]=G.z;

	ans[0][3]=A.x;
	ans[1][3]=A.y;
	ans[2][3]=G.z;

	ans[0][4]=A.x;
	ans[1][4]=G.y;
	ans[2][4]=A.z;

	ans[0][5]=G.x;
	ans[1][5]=G.y;
	ans[2][5]=A.z;

	ans[0][6]=G.x;
	ans[1][6]=G.y;
	ans[2][6]=G.z;

	ans[0][7]=A.x;
	ans[1][7]=G.y;
	ans[2][7]=G.z;


	side=ans[0][1]-ans[0][0];
//	rotatex(45);
//	rotatey(45);
//	rotatez(45);
	line(300,0,300,640);
	line(800,0,800,640);

}





void Face1(int k,int m)
{
for(int i=0;i<4;i++)
	{
	int j=(i+1)%4;
	line(temp[k][i],temp[m][i],temp[k][j],temp[m][j]);
	}

	float cenx=(temp[k][0]+temp[k][2])/2;
	float cenz=(temp[m][0]+temp[m][2])/2;
		float x1=(temp[k][1]+temp[k][0])/2;
		float x2=(temp[k][2]+temp[k][3])/2;
		float z1=(temp[m][1]+temp[m][0])/2;
		float z2=(temp[m][2]+temp[m][3])/2;
		float x11=(x1+cenx)/2;
		float z11=(z1+cenz)/2;
		float x12=(x2+cenx)/2;
		float z12=(z2+cenz)/2;

		line(x11,z11,x12,z12);
}


void Face2(int k,int m)
{
for(int i=4;i<8;i++)
	{
		int j;
	if(i!=7)
	j=i+1;
	else
	j=4;
	line(temp[k][i],temp[m][i],temp[k][j],temp[m][j]);
	}

	float cenx=(temp[k][0]+temp[k][2])/2;
	float ceny=(temp[m][0]+temp[m][2])/2;
	float x1=(temp[k][1]+temp[k][0])/2;
	float x2=(temp[k][2]+temp[k][3])/2;
	float y1=(temp[m][1]+temp[m][0])/2;
	float y2=(temp[m][2]+temp[m][3])/2;
	float x11=(x1+cenx)/2;
	float y11=(y1+ceny)/2;
	float x12=(x2+cenx)/2;
	float y12=(y2+ceny)/2;


}





void drawFront()
{
	Translate(200,200,200);
	Face1(0,1);
	Face2(0,1);
	line(temp[0][0],temp[1][0],temp[0][4],temp[1][4]);
	line(temp[0][1],temp[1][1],temp[0][5],temp[1][5]);
	line(temp[0][2],temp[1][2],temp[0][6],temp[1][6]);
	line(temp[0][3],temp[1][3],temp[0][7],temp[1][7]);

}



void drawSide()
{
	Translate(0,500,200);
	Face1(1,2);
	Face2(1,2);
	line(temp[1][0],temp[2][0],temp[1][4],temp[2][4]);
	line(temp[1][1],temp[2][1],temp[1][5],temp[2][5]);
	line(temp[1][2],temp[2][2],temp[1][6],temp[2][6]);
	line(temp[1][3],temp[2][3],temp[1][7],temp[2][7]);

}




void drawTop()
{
	Translate(900,0,200);
	Face1(0,2);
	Face2(0,2);
	line(temp[0][0],temp[2][0],temp[0][4],temp[2][4]);
	line(temp[0][1],temp[2][1],temp[0][5],temp[2][5]);
	line(temp[0][2],temp[2][2],temp[0][6],temp[2][6]);
	line(temp[0][3],temp[2][3],temp[0][7],temp[2][7]);

}



/*void drawcube(Point A, Point G)
{
	C.x=B.x;C.y=H.y;C.z=B.z;
	D.x=H.x;D.y=H.y;D.z=B.z;
	A.x=H.x;A.y=B.y;C.z=B.z;
	E.x=H.x;C.y=B.y;C.z=H.z;
	F.x=B.x;F.y=B.y;F.z=H.z;
	G.x=B.x;G.y=H.y;G.z=H.z;
}*/

int main() {

	initial(A,G);
	int angle=0;
			initwindow(1080,640,"Window");
	while(1)
	{

		int choice;
/*		cout<<"Enter your choice \n";
		cout<<"1 Rotate about x\n2 Rotate about y\n3 Rotate about z\n4 Exit\n";
		cin>>choice;
		if(choice==4)
		{
			exit(1);
		}
*/
	//printf("%d",'a');

	char ch;
	while(1)
	{

	ch=getch();
	switch(ch) {
    case 65:    // key up
    	//Rotation abt X;
		initial(A,G);
		rotatex(angle);
//		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatex(angle);
//		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatex(angle);
//		Translate(900,0,200);
		drawTop();
		delay(100);
		cleardevice();
		angle+=1;
        break;
    case 66:    exit(0);
        break;
    case 67:    // key right
    	//Rotation abt y

    	initial(A,G);
		rotatey(angle);
//		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatey(angle);
//		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatey(angle);
//		Translate(900,0,200);
		drawTop();
		delay(100);
		cleardevice();
		angle+=1;

        break;
    case 68:    // key left
    //Rotation abt z
    	initial(A,G);
		rotatez(angle);
//		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatez(angle);
//		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatez(angle);
//		Translate(900,0,200);
		drawTop();
		delay(100);
		cleardevice();
		angle+=1;
        break;
}
}

/*


	if(choice==1)
	{
	while(!kbhit())
	{
		initial(A,G);
		rotatex(angle);
		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatex(angle);
		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatex(angle);
		Translate(900,0,200);
		drawTop();
		delay(100);
		cleardevice();
		angle+=1;
	}
	}


	else	if(choice==2)
		{
	while(!kbhit())
	{
		initial(A,G);
		rotatey(angle);
		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatey(angle);
		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatey(angle);
		Translate(900,0,200);
		drawTop();
		delay(100);
		cleardevice();
		angle+=1;
	}
	}




	else	if(choice==3)
		{
	while(!kbhit())
	{
		initial(A,G);
		rotatez(angle);
		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatez(angle);
		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatez(angle);
		Translate(900,0,200);
		drawTop();
		delay(100);
		cleardevice();
		angle+=1;
	}
	}

*/

	getch();
	closegraph();
	}

	return 0;
}

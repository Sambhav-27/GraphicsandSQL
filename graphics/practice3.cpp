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
Point A={-80,-80,-80};
Point G={80,80,80};
//int side=(B.x-H.x);
float ans[4][8];

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
	//rotatex(45);
	//rotatey(45);
	//rotatez(45);
	line(400,0,400,720);
	line(900,0,900,720);

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

	float cenx=(temp[k][4]+temp[k][6])/2;
	float ceny=(temp[m][4]+temp[m][6])/2;

	float x1=(temp[k][5]+temp[k][4])/2;
	float x2=(temp[k][6]+temp[k][7])/2;
	float y1=(temp[m][5]+temp[m][4])/2;
	float y2=(temp[m][6]+temp[m][7])/2;

	float xn=(x1+cenx)/2;
	float yn=(y1+ceny)/2;

	float xs=(x2+cenx)/2;
	float ys=(y2+ceny)/2;

	x1=(temp[k][4]+temp[k][7])/2;
	x2=(temp[k][6]+temp[k][5])/2;
	y1=(temp[m][4]+temp[m][7])/2;
	y2=(temp[m][6]+temp[m][5])/2;

	float xw=(x1+cenx)/2;
	float yw=(y1+ceny)/2;

	float xe=(x2+cenx)/2;
	float ye=(y2+ceny)/2;

	x1=(xn+xw)/2;
	y1=(yn+yw)/2;

	float xnw=2*x1-cenx;
	float ynw=2*y1-ceny;


	x1=(xn+xe)/2;
	y1=(yn+ye)/2;

	float xne=2*x1-cenx;
	float yne=2*y1-ceny;

	x1=(xs+xw)/2;
	y1=(ys+yw)/2;

	float xsw=2*x1-cenx;
	float ysw=2*y1-ceny;

	x1=(xs+xe)/2;
	y1=(ys+ye)/2;

	float xse=2*x1-cenx;
	float yse=2*y1-ceny;

	line(xnw,ynw,xne,yne);
	line(xne,yne,xe,ye);
	line(xe,ye,xw,yw);
	line(xw,yw,xsw,ysw);
	line(xsw,ysw,xse,yse);

}


void Face3(int k,int m)
{
	line(temp[k][0],temp[m][0],temp[k][3],temp[m][3]);
	line(temp[k][3],temp[m][3],temp[k][7],temp[m][7]);
	line(temp[k][7],temp[m][7],temp[k][4],temp[m][4]);
	line(temp[k][4],temp[m][4],temp[k][0],temp[m][0]);


	float cenx=(temp[k][4]+temp[k][3])/2;
	float ceny=(temp[m][4]+temp[m][3])/2;

	float x1=(temp[k][7]+temp[k][4])/2;
	float x2=(temp[k][0]+temp[k][3])/2;
	float y1=(temp[m][7]+temp[m][4])/2;
	float y2=(temp[m][0]+temp[m][3])/2;

	float xn=(x1+cenx)/2;
	float yn=(y1+ceny)/2;

	float xs=(x2+cenx)/2;
	float ys=(y2+ceny)/2;

	x1=(temp[k][3]+temp[k][7])/2;
	x2=(temp[k][0]+temp[k][4])/2;
	y1=(temp[m][3]+temp[m][7])/2;
	y2=(temp[m][0]+temp[m][4])/2;

	float xw=(x1+cenx)/2;
	float yw=(y1+ceny)/2;

	float xe=(x2+cenx)/2;
	float ye=(y2+ceny)/2;

	x1=(xn+xw)/2;
	y1=(yn+yw)/2;

	float xnw=2*x1-cenx;
	float ynw=2*y1-ceny;


	x1=(xn+xe)/2;
	y1=(yn+ye)/2;

	float xne=2*x1-cenx;
	float yne=2*y1-ceny;

	x1=(xs+xw)/2;
	y1=(ys+yw)/2;

	float xsw=2*x1-cenx;
	float ysw=2*y1-ceny;

	x1=(xs+xe)/2;
	y1=(ys+ye)/2;

	float xse=2*x1-cenx;
	float yse=2*y1-ceny;

	line(xnw,ynw,xne,yne);
	line(xne,yne,xse,yse);
	line(xe,ye,xw,yw);
	line(xsw,ysw,xse,yse);
}




void Face4(int k,int m)
{
	line(temp[k][1],temp[m][1],temp[k][2],temp[m][2]);
	line(temp[k][2],temp[m][2],temp[k][6],temp[m][6]);
	line(temp[k][6],temp[m][6],temp[k][5],temp[m][5]);
	line(temp[k][5],temp[m][5],temp[k][1],temp[m][1]);


	float cenx=(temp[k][5]+temp[k][2])/2;
	float ceny=(temp[m][5]+temp[m][2])/2;

	float x1=(temp[k][6]+temp[k][5])/2;
	float x2=(temp[k][1]+temp[k][2])/2;
	float y1=(temp[m][6]+temp[m][5])/2;
	float y2=(temp[m][1]+temp[m][2])/2;

	float xn=(x1+cenx)/2;
	float yn=(y1+ceny)/2;

	float xs=(x2+cenx)/2;
	float ys=(y2+ceny)/2;

	x1=(temp[k][2]+temp[k][6])/2;
	x2=(temp[k][1]+temp[k][5])/2;
	y1=(temp[m][2]+temp[m][6])/2;
	y2=(temp[m][1]+temp[m][5])/2;

	float xw=(x1+cenx)/2;
	float yw=(y1+ceny)/2;

	float xe=(x2+cenx)/2;
	float ye=(y2+ceny)/2;

	x1=(xn+xw)/2;
	y1=(yn+yw)/2;

	float xnw=2*x1-cenx;
	float ynw=2*y1-ceny;


	x1=(xn+xe)/2;
	y1=(yn+ye)/2;

	float xne=2*x1-cenx;
	float yne=2*y1-ceny;

	x1=(xs+xw)/2;
	y1=(ys+yw)/2;

	float xsw=2*x1-cenx;
	float ysw=2*y1-ceny;

	x1=(xs+xe)/2;
	y1=(ys+ye)/2;

	float xse=2*x1-cenx;
	float yse=2*y1-ceny;

	line(xnw,ynw,xw,yw);
	line(xw,yw,xe,ye);
	line(xne,yne,xse,yse);
}




void Face5(int k,int m)
{
	line(temp[k][2],temp[m][2],temp[k][3],temp[m][3]);
	line(temp[k][3],temp[m][3],temp[k][7],temp[m][7]);
	line(temp[k][7],temp[m][7],temp[k][6],temp[m][6]);
	line(temp[k][6],temp[m][6],temp[k][2],temp[m][2]);


	float cenx=(temp[k][7]+temp[k][2])/2;
	float ceny=(temp[m][7]+temp[m][2])/2;

	float x1=(temp[k][6]+temp[k][7])/2;
	float x2=(temp[k][3]+temp[k][2])/2;
	float y1=(temp[m][6]+temp[m][7])/2;
	float y2=(temp[m][3]+temp[m][2])/2;

	float xn=(x1+cenx)/2;
	float yn=(y1+ceny)/2;

	float xs=(x2+cenx)/2;
	float ys=(y2+ceny)/2;

	x1=(temp[k][3]+temp[k][7])/2;
	x2=(temp[k][2]+temp[k][6])/2;
	y1=(temp[m][3]+temp[m][7])/2;
	y2=(temp[m][2]+temp[m][6])/2;

	float xw=(x1+cenx)/2;
	float yw=(y1+ceny)/2;

	float xe=(x2+cenx)/2;
	float ye=(y2+ceny)/2;

	x1=(xn+xw)/2;
	y1=(yn+yw)/2;

	float xnw=2*x1-cenx;
	float ynw=2*y1-ceny;


	x1=(xn+xe)/2;
	y1=(yn+ye)/2;

	float xne=2*x1-cenx;
	float yne=2*y1-ceny;

	x1=(xs+xw)/2;
	y1=(ys+yw)/2;

	float xsw=2*x1-cenx;
	float ysw=2*y1-ceny;

	x1=(xs+xe)/2;
	y1=(ys+ye)/2;

	float xse=2*x1-cenx;
	float yse=2*y1-ceny;

	line(xne,yne,xnw,ynw);
	line(xnw,ynw,xw,yw);
	line(xw,yw,xe,ye);
	line(xe,ye,xse,yse);
	line(xsw,ysw,xse,yse);
}


void Face6(int k,int m)
{
	line(temp[k][1],temp[m][1],temp[k][0],temp[m][0]);
	line(temp[k][0],temp[m][0],temp[k][4],temp[m][4]);
	line(temp[k][4],temp[m][4],temp[k][5],temp[m][5]);
	line(temp[k][5],temp[m][5],temp[k][1],temp[m][1]);


	float cenx=(temp[k][4]+temp[k][1])/2;
	float ceny=(temp[m][4]+temp[m][1])/2;

	float x1=(temp[k][5]+temp[k][4])/2;
	float x2=(temp[k][0]+temp[k][1])/2;
	float y1=(temp[m][5]+temp[m][4])/2;
	float y2=(temp[m][0]+temp[m][1])/2;

	float xn=(x1+cenx)/2;
	float yn=(y1+ceny)/2;

	float xs=(x2+cenx)/2;
	float ys=(y2+ceny)/2;

	x1=(temp[k][0]+temp[k][4])/2;
	x2=(temp[k][1]+temp[k][5])/2;
	y1=(temp[m][0]+temp[m][4])/2;
	y2=(temp[m][1]+temp[m][5])/2;

	float xw=(x1+cenx)/2;
	float yw=(y1+ceny)/2;

	float xe=(x2+cenx)/2;
	float ye=(y2+ceny)/2;

	x1=(xn+xw)/2;
	y1=(yn+yw)/2;

	float xnw=2*x1-cenx;
	float ynw=2*y1-ceny;


	x1=(xn+xe)/2;
	y1=(yn+ye)/2;

	float xne=2*x1-cenx;
	float yne=2*y1-ceny;

	x1=(xs+xw)/2;
	y1=(ys+yw)/2;

	float xsw=2*x1-cenx;
	float ysw=2*y1-ceny;

	x1=(xs+xe)/2;
	y1=(ys+ye)/2;

	float xse=2*x1-cenx;
	float yse=2*y1-ceny;

	line(xne,yne,xnw,ynw);
	line(xnw,ynw,xw,yw);
	line(xw,yw,xe,ye);
	line(xe,ye,xse,yse);
	line(xsw,ysw,xse,yse);
	line(xsw,ysw,xw,yw);
}



void drawFront()
{
	Translate(250,200,0);
	Face1(0,1);
	Face2(0,1);
	Face3(0,1);
	Face4(0,1);
	Face5(0,1);
	Face6(0,1);
}



void drawSide()
{
	Translate(0,650,200);
	Face1(1,2);
	Face2(1,2);
	Face3(1,2);
	Face4(1,2);
	Face5(1,2);
	Face6(1,2);
}




void drawTop()
{
	Translate(1150,0,200);
	Face1(0,2);
	Face2(0,2);
	Face3(0,2);
	Face4(0,2);
	Face5(0,2);
	Face6(0,2);
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
	int anglex=0,angley=0,anglez=0;
			initwindow(2040,720,"Window");
//	while(1)
//	{

	//	int choice;
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
    	cleardevice();
		initial(A,G);
		rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);
//		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);
//		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);
//		Translate(900,0,200);
		drawTop();
		delay(100);
		anglex+=1;
        break;
    case 66:    exit(0);
        break;
    case 67:    // key right
    	//Rotation abt y
    			cleardevice();
    	initial(A,G);
    	rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);

//		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);

//		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);

//		Translate(900,0,200);
		drawTop();
		delay(100);

		angley+=1;

        break;
    case 68:    // key left
    //Rotation abt z
    cleardevice();
    	initial(A,G);
		rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);

//		Translate(200,200,200);
		drawFront();
		initial(A,G);
		rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);

//		Translate(0,500,200);
		drawSide();
		initial(A,G);
		rotatex(anglex);
		rotatey(angley);
		rotatez(anglez);

//		Translate(900,0,200);
		drawTop();
		delay(100);
		anglez+=1;
        break;
}
//}

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
	//closegraph();
	}

	return 0;
}

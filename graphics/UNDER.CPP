#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
//using namespace std;
struct ad{
	char city[10];
	int hno;
	char state[10];
};


struct telephone{
	long int no;
	char name[10];
	struct ad ad1;
}s1;
FILE *fp,*ft;

int main()
{        textcolor(GREEN);
	textbackground(BLACK);
	clrscr();
	//clrscr();
	for(int len=0;len<80;++len)
{
cout<<"_";
delay(20);
}
	textcolor(7);
	int opt;
	char search[10];
	int search1;
	do
	{
	printf("\n1. Add record\n2. Modify record\n3. Delete record\n4. Show data \n5.search by name \n6.search by number\n7. Exit\n");
	scanf("%d",&opt);
	fp=fopen("tel.dat","rb+");

	if(opt==1)
	{
		char ch='y';
		while(ch=='y')
		{
			printf("\nEnter phone no. name address(Hno City State) : ");
			scanf("%d%s%d%s%s",&s1.no,s1.name,&s1.ad1.hno,s1.ad1.city,s1.ad1.state);
			int flag=1;



			struct telephone s2;

			{
				rewind(fp);
				while(fread(&s2,sizeof(s2),1,fp)==1)
				{
					if((s1.no==s2.no))
					{

						//printf("\n%d  %s  %d  %s  %s",s1.no,s1.name,s1.ad1.hno,s1.ad1.city,s1.ad1.state);
						flag=0;
						break;
					}
				}

			}
			if(!flag)
			cout<<"\nNo. already exist\n";
			else
			{
				fwrite(&s1,sizeof(s1),1,fp);
			}


			printf("Add another record ? ");
			fflush(stdin);
			scanf("%c",&ch);
		}
	}

	else if(opt==2)
	{
		printf("\nEnter name to modify : ");
		scanf("%s",search);
		rewind(fp);
		while(fread(&s1,sizeof(s1),1,fp)==1)
		{
			if(strcmp(s1.name,search)==0)
			{
				printf("\nEnter phone no. name address(Hno City State) : ");
				scanf("%d%s%d%s%s",&s1.no,s1.name,&s1.ad1.hno,s1.ad1.city,s1.ad1.state);
				fseek(fp,-1*sizeof(s1),SEEK_CUR);
				fwrite(&s1,sizeof(s1),1,fp);
				break;
			}
		}
	}

	else if(opt==3)
	{
		printf("Enter name of person to delete :");
		scanf("%s",search);
		ft=fopen("temp.dat","wb");
		rewind(fp);
		while(fread(&s1,sizeof(s1),1,fp)==1)
		{
			if(strcmp(s1.name,search)!=0)
			fwrite(&s1,sizeof(s1),1,ft);
		}
		fclose(fp);
		fclose(ft);
		remove("tel.dat");
		rename("temp.dat","tel.dat");
		fp=fopen("tel.dat","rb+");
	}

	else if(opt==4)
	{

		rewind(fp);
		while(fread(&s1,sizeof(s1),1,fp)==1)
		{
			//printf("\nEnter phone no. name address(Hno City State) : ");
			printf("\n%d  %s  %d  %s  %s",s1.no,s1.name,s1.ad1.hno,s1.ad1.city,s1.ad1.state);

		}
	}
	else if(opt==5)
	{

		printf("\nEnter name to search : ");
		scanf("%s",search);
		rewind(fp);
		while(fread(&s1,sizeof(s1),1,fp)==1)
		{
			if(strcmp(s1.name,search)==0)
			{

				printf("\n%d  %s  %d  %s  %s",s1.no,s1.name,s1.ad1.hno,s1.ad1.city,s1.ad1.state);
				//break;
			}
		}
	}
	else if(opt==6)
	{

		printf("\nEnter number to search : ");
		scanf("%d",&search1);
		rewind(fp);
		while(fread(&s1,sizeof(s1),1,fp)==1)
		{
			if((s1.no==search1))
			{

				printf("\n%d  %s  %d  %s  %s",s1.no,s1.name,s1.ad1.hno,s1.ad1.city,s1.ad1.state);
				break;
			}
		}
	}
	else if(opt==7)
	printf("\nExitting!!!!!!");
	else
	printf("\nEnter Correct Option ");
	fclose(fp);
	}while(opt!=7);
	return 0;
}



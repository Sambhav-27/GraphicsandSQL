#include<fstream.h>
#include<conio.h>
#include<dos.h>
//for delay
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>

class book
{
	char bno[6];
	char bname[50];
	char aname[20];
	public:
	void create_book()
	{
		cout<<"\n  NEW BOOK ENTRY !!\n";
		cout<<"\n  Enter The book number : ";
		cin>>bno;
		cout<<"\n  Enter The Name of The Book : ";
		gets(bname);
		cout<<"\n  Enter The Author's Name : ";
		gets(aname);
		cout<<"\n\n\n  Book Created !!";
	}

	void show_book()
	{
		cout<<"\n  Book no. : "<<bno;
		cout<<"\n  Book Name : ";
		puts(bname);
		cout<<"  Author Name : ";
		puts(aname);
	}

	void modify_book()
	{
		cout<<"\n  Book no. : "<<bno;
		cout<<"\n  Modified Book Name : ";
		gets(bname);
		cout<<"\n  Modified Author's Name of Book : ";
		gets(aname);
	}

	char* retbno()
	{
		return bno;
	}

	void report()
	{cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}


}bk;         //end of book class


class student
{
	char admno[10];
	char name[30];
	char stbno[6];
	int token;
	public:
	void create_student()
	{       textcolor(RED);
		textbackground(WHITE);
		clrscr();
		cout<<"\n  NEW STUDENT ENTRY !!\n";
		cout<<"\n  Enter The admission no : ";
		cin>>admno;
		cout<<"\n  Enter The Name of The Student : ";
		gets(name);
		token=0;
		stbno[0]='/0';
		cout<<"\n  Student Record Created !!";
	}

	void show_student()
	{
		cout<<"\n  Admission no. : "<<admno;
		cout<<"\n  Student Name : ";
		puts(name);
		cout<<"\n  No of Book issued : "<<token;
		if(token==1)
		cout<<"\n  Book No "<<stbno;
	}

	void modify_student()
	{
		cout<<"\n  Admission no. : "<<admno;
		cout<<"\n  Modified Student Name : ";
		gets(name);
	}

	char* retadmno()
	{
		return admno;
	}

	char* retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token=1;}

	void resettoken()
	{token=0;}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;}

}st;         //end of student class

fstream f,f1;

void write_book()
{
	char ch='y';
	f.open("lib.dat",ios::out|ios::app);
	while(ch=='y'||ch=='Y')
	{
	textcolor(BLACK);
	textbackground(WHITE);
	clrscr();
	bk.create_book();
	f.write((char*)&bk,sizeof(book));
	cout<<"\n\n  Do you want to add more record (y/n)";
	cin>>ch;
	}
	f.close();
}

void write_student()
{
	char ch='y';
	f.open("stud.dat",ios::out|ios::app);
	while(ch=='y')
	{
	st.create_student();
	f.write((char*)&st,sizeof(student));
	cout<<"\n\n  Do you want to add more record(y/n)";
	cin>>ch;
	}
	f.close();
}




void display_spb(char n[])
{
	cout<<"\n  BOOK DETAILS\n";
	int flag=0;
	f.open("lib.dat",ios::in);
	while(f.read((char*)&bk,sizeof(book)))
	{
	if(strcmp(bk.retbno(),n)==0)
	{
		bk.show_book();
		flag=1;
	}
	}

	f.close();
	if(flag==0)
	cout<<"\n\n  Book does not exist !!";
	getch();
}

void display_sps(char n[])
{
	cout<<"\n  STUDENT DETAILS\n";
	int flag=0;
	f.open("stud.dat",ios::in);
	while(f.read((char*)&st,sizeof(student)))
	{
	if((strcmp(st.retadmno(),n)==0))
	{
		st.show_student();
		flag=1;
	}
	}

	f.close();
	if(flag==0)
	cout<<"\n\n  Student does not exist !!";
	getch();
}


void modify_book()
{
	char n[6];
	int found=0;
	textcolor(GREEN);
	textbackground(BLACK);
	clrscr();
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. : ";
	cin>>n;
	f.open("lib.dat",ios::in|ios::out);
	while(f.read((char*)&bk,sizeof(book)) && found==0)
	{
	if(strcmp(bk.retbno(),n)==0)
	{
		bk.show_book();
		cout<<"\n  Enter The New Details of book"<<endl;
		bk.modify_book();
		int pos=-1*sizeof(bk);
		f.seekp(pos,ios::cur);
		f.write((char*)&bk,sizeof(book));
		cout<<"\n\n\t Record Updated";
		found=1;
	}
	}

	f.close();
	if(found==0)
	cout<<"\n\n Record Not Found !!";
	getch();
}


void modify_student()
{
	char n[6];
	int found=0;
	clrscr();
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The admission no. of The student : ";
	cin>>n;
	f.open("stud.dat",ios::in|ios::out);
	while(f.read((char*)&st,sizeof(student)) && found==0)
	{
	if(strcmp(st.retadmno(),n)==0)
	{
		st.show_student();
		cout<<"\nEnter The New Details of student : "<<endl;
		st.modify_student();
		int pos=-1*sizeof(st);
		f.seekp(pos,ios::cur);
		f.write((char*)&st,sizeof(student));
		cout<<"\n\n\t Record Updated";
		found=1;
	}
	}

	f.close();
	if(found==0)
	cout<<"\n\n Record Not Found !! ";
	getch();
}


void delete_student()
{
	char n[6];
	int flag=0;
	textcolor(YELLOW);
	textbackground(BLACK);
	clrscr();
	cout<<"\n\n\n\tDELETE STUDENT...";
	cout<<"\n\nEnter The admission no. of the Student Whose RecordYou Want To Delete : ";
	cin>>n;
	f.open("stud.dat",ios::in|ios::out);
	fstream f2;
	f2.open("Temp.dat",ios::out);
	f.seekg(0,ios::beg);
	while(f.read((char*)&st,sizeof(student)))
	{
	if(strcmp(st.retadmno(),n)!=0)
	f2.write((char*)&st,sizeof(student));
	else
	flag=1;
	}

	f2.close();
	f.close();
	remove("stud.dat");
	rename("Temp.dat","stud.dat");
	if(flag==1)
	cout<<"\n\n\tRecord Deleted !!";
	else
	cout<<"\n\n  Record not found !!";
	getch();
}


void delete_book()
{
	char n[6];
	textcolor(YELLOW);
	textbackground(BLACK);
	clrscr();
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	f.open("lib.dat",ios::in|ios::out);
	fstream f2;
	f2.open("Temp.dat",ios::out);
	f.seekg(0,ios::beg);
	while(f.read((char*)&bk,sizeof(book)))
	{
	if(strcmp(bk.retbno(),n)!=0)
	{
		f2.write((char*)&bk,sizeof(book));
	}
	}

	f2.close();
	f.close();
	remove("lib.dat");
	rename("Temp.dat","lib.dat");
	cout<<"\n\n\tRecord Deleted !!";
	getch();
}


void display_alls()
{

	textcolor(RED);
	textbackground(WHITE);
	clrscr();
	f.open("stud.dat",ios::in);
	if(!f)
	{
		cout<<"\n\n\t\tERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"==============================================================================\n";
	cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
	cout<<"==============================================================================\n";

	while(f.read((char*)&st,sizeof(student)))
	{
		st.report();
	}

	f.close();
	getch();
}

void display_allb()
{
	textcolor(RED);
	textbackground(WHITE);
	clrscr();
	f.open("lib.dat",ios::in);
	if(!f)
	{
		cout<<"\n\n\t\tERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"================================================================================\n";
	cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"\tAuthor\n";
	cout<<"================================================================================\n";

	while(f.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
	f.close();
	getch();
}


void book_issue()
{
	char sn[10],bn[10];
	int found=0,flag=0;
	textcolor(RED);
	textbackground(WHITE);
	clrscr();
	cout<<"\n\n\t\t\t\tBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's admission no.";
	cin>>sn;
	f.open("stud.dat",ios::in|ios::out);
	f1.open("lib.dat",ios::in|ios::out);
	while(f.read((char*)&st,sizeof(student)) && found==0)
	{
	if(strcmp(st.retadmno(),sn)==0)
	{
		found=1;
		if(st.rettoken()==0)
		{
		cout<<"\n\n\tEnter the book no. : ";
		cin>>bn;
		while(f1.read((char*)&bk,sizeof(book))&& flag==0)
		{
		if(strcmp(bk.retbno(),bn)==0)
		{
		bk.show_book();
		flag=1;
		st.addtoken();
		st.getstbno(bk.retbno());//student gets the book no. returned by retbno
		int pos=-1*sizeof(st);
		f.seekp(pos,ios::cur);
		f.write((char*)&st,sizeof(student));
		cout<<"\n\n\t Book issued successfully !!\n\n";
		cout<<"Please Note: Write current date inbackside of book and submit within 15 days !!";
		cout<<"\n\t\tFine Rs. 1 for each day after 15 days period !!";
		}
		}//end of while
		if(flag==0)
		cout<<"Book number does not exist !!";
		}
		else
		cout<<"You have not returned the last book !!";

		}
	}
	if(found==0)
	cout<<"Student record does not exist !!";
	getch();
	f.close();
	f1.close();
}


void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    textcolor(RED);
    textbackground(WHITE);
    clrscr();
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The students admission no. : ";
    cin>>sn;
    f.open("stud.dat",ios::in|ios::out);
    f1.open("lib.dat",ios::in|ios::out);
    while(f.read((char*)&st,sizeof(student)) && found==0)
    {
	if(strcmp(st.retadmno(),sn)==0)
	{
	found=1;
	if(st.rettoken()==1)
	{
	while(f1.read((char*)&bk,sizeof(book))&& flag==0)
	{
	if(strcmp(bk.retbno(),st.retstbno())==0) //if book no depositd by student is equal to book in record
	{
	bk.show_book();
	flag=1;
	cout<<"\n\nBook deposited in no. of days : ";
	cin>>day;
	if(day>15)
	{
	fine=(day-15)*1;
	cout<<"\n\nFine has to deposited Rs. "<<fine;
	}
	st.resettoken();
	int pos=-1*sizeof(st);
	f.seekp(pos,ios::cur);
	f.write((char*)&st,sizeof(student));
	cout<<"\n\n\t Book deposited successfully !!";
	}
	}//end of while
	  if(flag==0)
	   cout<<"Book no does not exist !!";
	}
	 else
	cout<<"No book is issued..please check!!";
	}
    }
      if(found==0)
	cout<<"Student record not exist...";
	getch();
  f.close();
  f1.close();
  }


void main()
{
char ch='y';
int opt,x,len;
x=250;
char user[20];
textcolor(GREEN);

clrscr();
cout<<"\n\n\n\t\t\tEnter User Name to begin......  \n";
cout<<"\n\n\t\t\t\t   ";
cin>>user;
if(strcmp(user,"$ambhav")==0)
{
while(ch=='y'||ch=='Y')
{       textcolor(GREEN);
	textbackground(BLACK);
	clrscr();
	cout<<"\n\t\t\t\t  MAIN MENU\n\n";
	delay(x);
for(len=0;len<80;++len)
{
cout<<"_";
delay(20);
}
	cout<<"\n\n\n  1. Create Student Record";
	delay(x);
	cout<<"\t\t2. Display All Student Record ";
	delay(x);
	cout<<"\n\n  3. Display Specific Student Record ";
	delay(x);
	cout<<"\t4. Modify Student Record";
	delay(x);
	cout<<"\n\n  5. Delete Student Record";
	delay(x);
	cout<<"\t\t6. Create Book ";
	delay(x);
	cout<<"\n\n  7. Display All Books ";
	delay(x);
	cout<<"\t\t\t8. Display Specific Book ";
	delay(x);
	cout<<"\n\n  9. Modify Book ";
	delay(x);
	cout<<"\t\t\t10. Delete Book ";
	delay(x);
	cout<<"\n\n  11. Book Issue";
	delay(x);
	cout<<"\t\t\t12. Book Deposit";
	delay(x);
	cout<<"\n\n\t\t\t\t13. Exit\n\n";
	delay(x);
for(len=0;len<80;++len)
{
cout<<"_";
delay(20);
}
	cout<<"\n\n\t\t\tPlease Enter Your Choice (1-13) ";
	delay(x);
	cin>>opt;
	if(opt==1)
	{
	clrscr();
	write_student();
	}
	else if(opt==2)
	{
	 display_alls();
	}
	else if(opt==3)
	{
	char num[6];
	clrscr();
	cout<<"\n\n\tPlease Enter The Admission No. ";
	cin>>num;
	display_sps(num);
	}
	else if(opt==4)
	{
	modify_student();
	}
	else if(opt==5)
	{
	delete_student();
	}
	else if(opt==6)
	{
	clrscr();
	write_book();
	}
	else if(opt==7)
	{
	display_allb();
	}
	else if(opt==8)
	{
	char num[6];
	clrscr();
	cout<<"\n\n\tPlease Enter The book No. ";
	cin>>num;
	display_spb(num);
	}
	else if(opt==9)
	{
	modify_book();
	}
	else if(opt==10)
	{
	delete_book();
	}
	else if(opt==11)
	{
	clrscr();
	book_issue();
	}
	else if(opt==12)
	{
	book_deposit();
	}
	else if(opt==13)
	{
	textcolor(RED);
	textbackground(YELLOW);
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\t\t\tTHANKYOU FOR USING OUR SOFTWARE !!\n\n ";
	cout<<"\n\n\n \t\t\t\t... EXITING... !!\n\n";
	delay(2000);
	exit(0);
	}
	else
	cout<<"\a";
	cout<<"\n  Back To Main Menu(y/n)\n";
	cin>>ch;
	} //end of while
if(ch=='n')
{
textcolor(RED);
textbackground(YELLOW);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\t\t\tTHANKYOU FOR USING OUR SOFTWARE !!\n\n ";
cout<<"\n\n\n \t\t\t\t... EXITING... !!\n\n";
delay(2000);
exit(0);
}
}  // end of if
else
{
clrscr();
cout<<"\n\n\n\n\t\t\t Sorry !! Wrong Username !!\n\n\n\t\t\t\tAborting !!";
delay(2500);
exit(0);
}
}



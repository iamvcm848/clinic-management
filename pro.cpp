#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
int x=1;
class DOCTOR
{
	int day,month,year,rno,age,ad,ay,am,ano,m1d,m1m,m1y,cost,dl,bmiage;
	float h,w,bm,bmih,bmiw,bmic;
	char name[100],bmigender,bminame[100],pn[100],med[10000],dname[200],dn[100],dq[2000],dad[1000],remark[10000],gender,b[1000],b1[100],key[100];
	public:
	void patientmenu();
	void setup1();
	void pass2();
	void pass1();
	void precord1();
	void tcost();
	int malep();
	int malep1();
	int fp1();
	void pass();
	void date();
	void BMI();
	int fp();
	int pb();
	int pb0();
	int f1p();
	int pb10();
	int pb1();
	int pb2();
	int pb20();
	int pb3();
	int pb30();
	int pb4();
	int pb40();
	int pb50();
	int pb5();
	void dhelp();
	void billdisplay();
	void ddisplay();
	void show();
	void newapp();
	void BMIin();
	void BMIout();
	void getname(int);
	int as();
	int bs();
	void appointment();
	void appdisp();
	void existingp();
	void dispmed();
	void dispname();
	void newmed();
	void new_entry();
	void search();
	void modify();
	void del();
	void drecord();
	void setup();
	int reno()
	{
		return rno;
	}
	void precord();
}D1;
void DOCTOR::BMIin()
{
	system("cls");
	cout<<"\n please enter your NAME : \n";
	cin.ignore();cout<<" ";cin.get(bminame,100);
	cout<<"\n enter your age \n";
	cin>>bmiage;
	cout<<"\n enter your gender \n";
	cin>>bmigender;
	cout<<"\n enter your height (in m) \n";
	cin>>bmih;
	cout<<"\n enter your weight (in Kg) \n";
	cin>>bmiw;
	bmic=bmiw/(bmih*bmih);
	cout<<"##############################\n";
	cout<<"your BMI is :"<<bmic<<" ";
	if(bmic<=18.5)
	{
		cout<<" you are UNDERWEIGHT \n";
		strcpy(b1,"UNDERWEIGHT");
	}
	else if(bmic>18.5&&bmic<=30.00)
    {
		cout<<"you are NORMAL \n";
		strcpy(b1,"NORMAL");
	}
	else
	{
		cout<<" you are OBESE \n";
		strcpy(b1,"OBESE");
	}
}
void DOCTOR::BMIout()
{
	  float a=0,b=0,c=0,d,e,f;
	  cout<<"         RESULTS        \n";
	  cout<<"||||||||||||||||||||||||||| \n";
	  cout<<"--------------------------- \n";
	  	cout<<" NO OF MALE PATIENTS ARE   "<<D1.malep1()<<" \n";
    cout<<" NO OF FEMALE PATIENTS ARE "<<D1.fp1()<<"\n\n";
    cout<<" MALE SECTION \n";
    cout<<"----------------------------------------------\n";
    cout<<" NO OF MALE PATIENTS (UNDERWEIGHT)  "<<D1.pb0()<< " |\n";
    cout<<" NO OF MALE PATIENTS (NORMAL)       "<<D1.pb10()<<" |\n";
    cout<<" NO OF MALE PATIENTS (OBESE)        "<<D1.pb20()<<" |\n";
    cout<<"----------------------------------------------\n";
    cout<<" FEMALE SECTION \n";
    cout<<"----------------------------------------------\n";
    cout<<" NO OF FEMALE PATIENTS (UNDERWEIGHT)  "<<D1.pb30()<<"|\n";
    cout<<" NO OF FEMALE PATIENTS (NORMAL)       "<<D1.pb40()<<"|\n";
    cout<<" NO OF FEMALE PATIENTS (OBESE)        "<<D1.pb50()<<"|\n";
    cout<<"----------------------------------------------\n\n";
    a=((D1.pb20()+D1.pb50())*100)/(D1.malep1()+D1.fp1());
    b=((D1.pb40()+D1.pb10())*100)/(D1.malep1()+D1.fp1());
    c=((D1.pb0()+D1.pb30())*100)/(D1.malep1()+D1.fp1());
    cout<<"STATISTICS \n";
    cout<<"--------------------------------- \n";
    cout<<" % OF PEOPLE WHO ARE OBESE       : "<<a<<"%"<<endl;
    cout<<" % OF PEOPLE WHO ARE NORMAL      : "<<b<<"%"<<endl;
    cout<<" % OF PEOPLE WHO ARE UNDERWEIGHT : "<<c<<"%"<<endl;
    cout<<"--------------------------------- \n";
}
void DOCTOR::BMI()
{
	system("cls");
	cout<<"       BMI CALCULATOR             \n\n";
	cout<<"===================================\n";
	cout<<"PRESS 1 TO ENTER THE BMI           |\n";
	cout<<"PRESS 2 TO SEE THE OVERALL RESULTS |\n";
	cout<<"===================================\n\n";
	int x;
	cout<<"enter your option :";
	cin>>x;
	switch(x)
	{
		case 1:
		{
			fstream a;
		a.open("BMI.DAT",ios::out|ios::binary|ios::app);
		D1.BMIin();
		a.write((char *)&D1,sizeof(D1));
		a.close();
		}
		D1.BMI();
		break;
		case 2:
		{
			fstream a;
		a.open("BMI.DAT",ios::in|ios::binary);
		a.read((char *)&D1,sizeof(D1));
		 D1.BMIout();
		 a.close();
		}
		cout<<"do you want to go to main.? press 1 \n";
		int o;
		cin>>o;
		if(o==1)
		D1.show();
		else 
		exit(o);
		break;
		default:
		cout<<"wrong option !";
	}
}
void DOCTOR ::precord1()
{
	cout<<"------------------------------------------- \n";
	cout<<"DATE : "<<m1d<<"/"<<m1m<<"/"<<m1y<<endl;
	cout<<"previous MEDICATIONS \n";
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	puts(med);cout<<"\n";
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	cout<<endl;
	cout<<"previous REMARKS \n";
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	puts(remark);
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n";
	cout<<"your BMI INDEX was "<<bm<<" , You were ";puts(b);
	cout<<" \n";
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n";
}
void DOCTOR::tcost()
{
	fstream a;
		int c=0,w1,w2,w3;
		cout<<"enter the day   :\n";
		cin>>w1;cout<<endl;
		cout<<"enter the month :\n";
		cin>>w2;cout<<endl;
		cout<<"enter the year :\n";
		cin>>w3;cout<<endl;
		a.open("cost1.DAT",ios::in|ios::binary);
		while(a.read((char *)&D1,sizeof(D1)))
		{
			
			if(w1==m1d&&w2==m1m&&w3==m1y)
			c=c+cost;
		}
		cout<<"-------------------------------------\n";
		cout<<" total money earned was : Rs "<<c<<" \n";
		cout<<"-------------------------------------\n";
	a.close();
}
void DOCTOR::pass1()
{
	int x=3;
	while(x>0)
	{
	system("cls");	
   cout<<"                    "<<x<<" try                          \n";
                                D1.pass2();
	x--;         
	}
    if(x==0)
		{
		    	system("cls");
 	        cout<<"                                                          \n";
 	        cout<<"                                                          \n";
 	        cout<<"                                                          \n";
 	        cout<<"                                                          \n";
			cout<<"              SORRY ! YOU HAVE ENTERED THE WRONG PASSWORD 3 TIMES      \n";
			cout<<"                            PROGRAM  TERMINATED !                      \n";
			cout<<"                                                          \n";
			cout<<"                                                          \n";
			cout<<"                                                          \n";
			cout<<"                                                          \n";
			exit(0);
		}
}
void DOCTOR::pass2()
{
	char c[100];
	cout<<"                                                          \n";
	cout<<"                                                          \n";
	cout<<"                  _____________________                   \n";
	cout<<"                   ENTER YOUR PASSWORD                    \n";
	cout<<"                  ---------------------                   \n";
	cout<<"                     ";cin>>c;
	cout<<"\n\n";
	if(strcmp(D1.key,c)==0)
		D1.show();
}
void DOCTOR::pass()
{
	char c[100];
	system("cls");
	cout<<"                                                           \n";
	cout<<"                                                           \n";
	cout<<"                                                           \n";
	cout<<"                                                           \n";
	cout<<"                                                           \n";
	cout<<"                                                           \n";
    cout<<" WELCOME DR.";puts(D1.dname);cout<<"                        \n";
	cout<<"                   _____________________                   \n";
	cout<<"                    ENTER YOUR PASSWORD                    \n";
	cout<<"                   ---------------------                   \n";
	cout<<"                     ";cin>>c;
	cout<<"\n\n";
	if(strcmp(D1.key,c)==0)
		D1.show();
		else
		D1.pass1();
}
int DOCTOR::pb()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while( b.read((char *)&D1,sizeof(D1)))
       {
       		if(D1.bm<=18.5&&(D1.gender=='m'||D1.gender=='M'))
	         x++;
       }
   b.close();
   return x;
}
int DOCTOR::pb0()
{
	int x=0;
	fstream b;
		b.open("BMI.DAT",ios::binary|ios::in);
       while( b.read((char *)&D1,sizeof(D1)))
       {
       		if(D1.bmic<=18.5&&(D1.bmigender=='m'||D1.bmigender=='M'))
	         x++;
       }
   b.close();
   return x;
}
int DOCTOR::pb1()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
			   
	           if(D1.bm>18.5&&D1.bm<=30&&(D1.gender=='m'||D1.gender=='M'))
	         x++;       
       }
   b.close();
   return x;
}
int DOCTOR::pb10()
{
	int x=0;
	fstream b;
		b.open("BMI.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
			   
	           if(D1.bmic>18.5&&D1.bmic<=30&&(D1.bmigender=='m'||D1.bmigender=='M'))
	         x++;       
       }
   b.close();
   return x;
}
int DOCTOR::pb2()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
       		 
	       if(D1.bm>30&&(D1.gender=='m'||D1.gender=='M'))
	          x++;
       }
   b.close();
   return x;
}
int DOCTOR::pb20()
{
	int x=0;
	fstream b;
		b.open("BMI.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
       		 
	       if(D1.bmic>30&&(D1.bmigender=='m'||D1.bmigender=='M'))
	          x++;
       }
   b.close();
   return x;
}
int DOCTOR::pb3()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
			   
	            if(D1.bm<=18.5&&(D1.gender=='f'||D1.gender=='F'))
	         x++;   
       }
   b.close();
   return x;
}
int DOCTOR::pb30()
{
	int x=0;
	fstream b;
		b.open("BMI.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
			   
	            if(D1.bmic<=18.5&&(D1.bmigender=='f'||D1.bmigender=='F'))
	         x++;   
       }
   b.close();
   return x;
}
int DOCTOR::as()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
       		 
	       if(D1.age>65)
	         x++;
       }
   b.close();
   return x;
}
int DOCTOR::pb4()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
       		  
	        if(D1.bm>18.5&&D1.bm<=30&&(D1.gender=='f'||D1.gender=='F'))
	         x++;
       }
   b.close();
   return x;
}
int DOCTOR::pb40()
{
	int x=0;
	fstream b;
		b.open("BMI.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
       		  
	        if(D1.bmic>18.5&&D1.bmic<=30&&(D1.bmigender=='f'||D1.bmigender=='F'))
	         x++;
       }
   b.close();
   return x;
}
int DOCTOR::pb5()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
       		 
	       if(D1.bm>30&&(D1.gender=='f'||D1.gender=='F'))
	          x++;
       }
   b.close();
   return x;
}
int DOCTOR::pb50()
{
	int x=0;
	fstream b;
		b.open("BMI.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
       		 
	       if(D1.bmic>30&&(D1.bmigender=='f'||D1.bmigender=='F'))
	          x++;
       }
   b.close();
   return x;
}
int DOCTOR::bs()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while( b.read((char *)&D1,sizeof(D1)))
       {
       		
	       if(D1.age<65)
	         x++;
       }
   b.close();
   return x;
}
void DOCTOR::date()
{
	time_t t=time(0);
	struct tm*now=localtime(&t);
	int day=now->tm_mday;
	int month=now->tm_mon+1;
	int year=now->tm_year+1900;
	cout<<day<<"-"<<month<<"-"<<year<<endl;
}
int DOCTOR::malep()
{
	int x=0;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
	           if(D1.gender=='m'||D1.gender=='M')
	           x++;   
       }
   b.close();
   return x;
}
int DOCTOR::malep1()
{
	int x=0;
	fstream b;
		b.open("BMI.DAT",ios::binary|ios::in);
       while(b.read((char *)&D1,sizeof(D1)))
       {
	           if(D1.bmigender=='m'||D1.bmigender=='M')
	           x++;   
       }
   b.close();
   return x;
}
int DOCTOR::fp()
{
	int x=0;
	fstream b1;
		b1.open("patient1.DAT",ios::binary|ios::in);
       while(b1.read((char *)&D1,sizeof(D1)))
       {
       		
       		 if(D1.gender=='f'||D1.gender=='F')
	         x++;
      }
      return x;
   b1.close();   
}
int DOCTOR::fp1()
{
	int x=0;
	fstream b1;
		b1.open("BMI.DAT",ios::binary|ios::in);
       while(b1.read((char *)&D1,sizeof(D1)))
       {
       		
       		 if(D1.bmigender=='f'||D1.bmigender=='F')
	         x++;
      }
      return x;
   b1.close();
   
}
void DOCTOR::show()
{
	 system("COLOR B0");
	 system("cls");
	cout<<"================\n";
	cout<<"Todays DATE ";D1.date();
	cout<<"\n";
	cout<<"================\n";
	int a;
	cout<<"\n       !!!!!! WELCOME !!!!!! \n\n\n";
	cout<<" _____________| MAIN MENU |_____________\n\n";
	cout<<"press 1 for PATIENT MENU                |\n\n";
	cout<<"press 2 for APPOINTMENT MENU            |\n\n";
	cout<<"press 3 for BILLING MENU                |\n\n";
	cout<<"press 4 for DOCTORS HELP                |\n\n";
	cout<<"press 5 for SETUP MENU                  |\n\n";
	cout<<"press 6 for BMI CALCULATOR              |\n\n";
	cout<<"----------------------------------------|\n\n";
	cout<<"ENTER YOUR OPTION  = ";
	cin>>a;
	cout<<"\n\n";
	switch(a)
	{
		case 1:
		D1.patientmenu();
		break;
		case 6:
		D1.BMI();
		break;
		case 2:
		D1.appointment();
		break;
		case 5:
		{
			fstream a;
	       a.open("xyz.DAT",ios::binary|ios::out|ios::app);
	        D1.setup();
	       a.write((char *)&D1,sizeof(D1));
	       a.close();
	       	cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
		}
		break;
		case 3:
		{
			DOCTOR yz;
	cout<<"enter the REGN NO to GENERATE PRESCRIPTION cum BILL = ";
	int x;
	cin>>x;
	cout<<"\n";
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b)
       {
       		 if(yz.reno()==x)
	         yz.billdisplay();
			   b.read((char *)&yz,sizeof(yz));
	       
       }
   b.close();
		}
		break;
		case 4:
		D1.dhelp();
		cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
		break;
		default:
		cout<<"wrong option \n";
		exit(0);
	}
}
void DOCTOR::dhelp()
{
	system("cls");
	cout<<" NO OF MALE PATIENTS ARE   "<<malep()<<" \n";
    cout<<" NO OF FEMALE PATIENTS ARE "<<fp()<<"\n\n";
    cout<<" NO OF PATIENTS ABOVE THE AGE OF 65 "<<as()<<"\n";
    cout<<" NO OF PATIENTS BELOW THE AGE OF 65 "<<bs()<<"\n\n";
    cout<<" MALE SECTION \n";
    cout<<"----------------------------------------------\n";
    cout<<" NO OF MALE PATIENTS (UNDERWEIGHT)  "<<pb()<< " |\n";
    cout<<" NO OF MALE PATIENTS (NORMAL)       "<<pb1()<<" |\n";
    cout<<" NO OF MALE PATIENTS (OBESE)        "<<pb2()<<" |\n";
    cout<<"----------------------------------------------\n";
    cout<<" FEMALE SECTION \n";
    cout<<"----------------------------------------------\n";
    cout<<" NO OF FEMALE PATIENTS (UNDERWEIGHT)  "<<pb3()<<"|\n";
    cout<<" NO OF FEMALE PATIENTS (NORMAL)       "<<pb4()<<"|\n";
    cout<<" NO OF FEMALE PATIENTS (OBESE)        "<<pb5()<<"|\n";
    cout<<"----------------------------------------------\n";
    cout<<"do you want to see how much you earned on any day.? PRESS 1 FOR YES \n";
	int p;
	cin>>p;
	if(p==1)
	D1.tcost();
    cout<<"do you want to go back to the MAIN MENU .? PRESS 1 FOR YES \n";
	int p1;
	cin>>p1;
	if(p1==1)
	D1.show();
	else
	exit(0);
   }

void DOCTOR::billdisplay()
{
	system("COLOR F8");
	system("cls");
	cout<<"================\n";
    cout<<"DATE : ";D1.date();
	cout<<"\n";
	cout<<"================\n";
	D1.ddisplay();
	cout<<"\n";
	cout<<" NAME of PATIENT : ";puts(name);cout<<endl;
	cout<<" MEDICINES PRESCRIBED \n";
	cout<<"------------------------------------\n";
	puts(med);
	cout<<"-------------------------------------\n";
	cout<<"\n\n\n";
	cout<<"                    -----------------------\n";
	cout<<"                    |  COST :"<<cost<<endl;
	cout<<"                    -----------------------\n";
	cout<<"do you want to go back to the MAIN MENU .? PRESS 1 FOR YES \n";
	int p;
	cin>>p;
	if(p==1)
	D1.show();
	else
	exit(0);
}
void DOCTOR::drecord()
{
	system("cls");
	cout<<"============================================================|\n";
	cout<<"DOCTOR ID     ="<<dl<<"                                      \n\n";
	cout<<"NAME  Dr.     =";puts(dname);cout<<"                         \n";
	cout<<"QUALIFICATION =";puts(dq);cout<<"                            \n";
	cout<<"ADDRESS       = ";puts(dad);cout<<"                          \n";
	cout<<"ph.no         =";puts(dn);cout<<"                            \n";
	cout<<"=============================================================\n";
}
void DOCTOR::ddisplay()
{
    system("cls");
    cout<<"================\n";
	D1.date();
	cout<<"\n";
	cout<<"================\n";
	fstream b;
		b.open("xyz.DAT",ios::binary|ios::in);
       while(b)
       {
       		  
	         D1.drecord();
			   b.read((char *)&D1,sizeof(D1));
	       
       }
   b.close();
}
void DOCTOR::setup()
{
	system("COLOR B0");
	system("cls");
	cout<<"================\n";
	cout<<"Today's DATE ";D1.date();
	cout<<"\n";
	cout<<"================\n\n";
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=|\n";
	cout<<"      SETUP MENU       |\n";
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=|\n\n";
	cout<<"DO YOU WANT TO CHANGE THE PASSWORD .? press 1 for YES \n";
	int x;
	cin>>x;
	if(x==1)
	{
		cout<<"(IT IS CASE SENSITIVE) \n\n";
	cout<<"enter your NEW PASSWORD  : ";
	cin>>key;
	cout<<"\nconfirm your PASSWORD    : ";
	char as[100];
	cin>>as;
	if(strcmp(key,as)==0)
	{
		system("cls");
		cout<<"                                         \n";
		cout<<"                                         \n";
		cout<<"                                         \n";
		cout<<"        PASSWORD set successfully !     \n\n";
		cout<<"                                         \n";
		cout<<"                                         \n";
		cout<<"                                         \n";
	}
	else
	{
		D1.setup();
	}
	}
	cout<<"enter your ID or LICENSE NUMBER \n";
	cin>>dl;cout<<endl;
	cout<<"   enter your NAME \n";
	cout<<" ";cin.ignore();cout<<" ";cin.get(dname,100);
	cout<<"\n enter your QUALIFICATIONS \n";
			cin.ignore();cout<<" ";cin.get(dq,100);
	cout<<"\n enter your contact number \n";
			cin.ignore();cout<<" ";cin.get(dn,100);cout<<endl;
	cout<<"\n enter your address \n";
		cin.ignore();cout<<" ";cin.get(dad,100);
		
}
void DOCTOR::setup1()
{
	system("COLOR B0");
	system("cls");
	cout<<"================\n";
	cout<<"Today's DATE ";D1.date();
	cout<<"\n";
	cout<<"================\n\n";
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=|\n";
	cout<<"      SETUP MENU       |\n";
	cout<<"=-=-=-=-=-=-=-=-=-=-=-=|\n\n";
	cout<<"(IT IS CASE SENSITIVE) \n\n";
	cout<<"enter your NEW PASSWORD  : ";
	cin>>key;
	cout<<"\nconfirm your PASSWORD    : ";
	char as[100];
	cin>>as;
	if(strcmp(key,as)==0)
	{
		system("cls");
		cout<<"                                         \n";
		cout<<"                                         \n";
		cout<<"                                         \n";
		cout<<"        PASSWORD set successfully !     \n\n";
		cout<<"                                         \n";
		cout<<"                                         \n";
		cout<<"                                         \n";
	}
	else
	{
		D1.setup();
	}
	
	cout<<"enter your ID or LICENSE NUMBER \n";
	cin>>dl;cout<<endl;
	cout<<"   enter your NAME \n";
	cout<<" ";cin.ignore();cout<<" ";cin.get(dname,100);
	cout<<"\n enter your QUALIFICATIONS \n";
			cin.ignore();cout<<" ";cin.get(dq,100);
	cout<<"\n enter your contact number \n";
			cin.ignore();cout<<" ";cin.get(dn,100);cout<<endl;
	cout<<"\n enter your address \n";
		cin.ignore();cout<<" ";cin.get(dad,150);
}
void DOCTOR::dispname()
{
	puts(name);
}
void DOCTOR::getname(int x)
{
	 
	DOCTOR yz;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b)
       {
       		 if(yz.reno()==x)
	          yz.dispname();
			   b.read((char *)&yz,sizeof(yz));
       }
   b.close();
    
}
void DOCTOR::appdisp()
{
	cout<<" \n\n";
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
	cout<<"REGN no :"<<ano<<"\n";
	cout<<"NAME    :" ; getname(ano);
	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@ \n";
	cout<<endl;
	::x++;
}
void DOCTOR::newapp()
{
	system("cls");
	cout<<"================\n";
	cout<<"Todays DATE ";D1.date();
	cout<<"\n";
	cout<<"================\n";
	cout<<"enter the Regn ID to BOOK AN APPOINTMENT  ";
	cin>>ano;
	cout<<"\n";
	cout<<"ENTER THE DATE OF APPOINTMENT \n";
	cout<<"DAY   = ";cin>>ad;cout<<"\n";
	cout<<"MONTH = ";cin>>am;cout<<"\n";
	cout<<"YEAR = ";cin>>ay;cout<<"\n";
	cout<<"APPOINTMENT BOOKED SUCCESSFULLY ! \n";
}
void DOCTOR::appointment()
{
	system("cls");
	system("COLOR B0");
	cout<<"================\n";
	cout<<"Today's DATE ";D1.date();
	cout<<"\n";
	cout<<"================\n";
	cout<<endl;
	cout<<"^-^-^-^-^-^-^-^-^-| APPOINTMENT MENU |^-^-^-^-^-^-^-^-^|\n\n";
	cout<<"press 1 to book APPOINTMENT                            |\n\n";
	cout<<"press 2 to see the LIST OF APPOINTMENT on any DAY     |\n\n";
	cout<<"press 3 to delete an APPOINTMENT                       |\n\n";
	cout<<"*******************************************************|\n";
	cout<<"enter your OPTION = ";
	int x;
	cin>>x;
	cout<<"\n";
	switch(x)
	{
		case 1:
		{
			system("COLOR B0");
			fstream a;
	       a.open("app1.DAT",ios::binary|ios::app|ios::out);
	       D1.newapp();
	       a.write((char *)&D1,sizeof(D1));
	       a.close();
		    cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
		}
		break;
		case 2:
		{
			system("COLOR B0");
			DOCTOR ab;
			fstream xyz;
			cout<<"PLEASE ENTER THE DATE TO SEARCH AN APPOINTMENT : \n";
	  xyz.open("app1.DAT",ios::in|ios::binary); 
	  int x,y,z;
			cout<<"DAY   = ";cin>>x;cout<<"\n";
	        cout<<"MONTH = ";cin>>y;cout<<"\n";
         	cout<<"YEAR  = ";cin>>z;cout<<"\n";
         	system("cls");
         	cout<<" THE LIST ON "<<x<<"/"<<y<<"/"<<z<<" is \n";
         	cout<<"-----------------------------------------\n\n";
	         while(xyz.read((char *)&ab,sizeof(ab)))
	        {
			  if(ab.ad==x&&ab.am==y&&ab.ay==z)
		        ab.appdisp();
	  
            }
	       cout<<"-----------------------------------------\n\n";
	       xyz.close();
	       cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
 	    break;	
 	    }
 	    case 3:
 	    {
    	 	system("COLOR B0");
			 ifstream fio("app1.DAT",ios::binary);
	ofstream file("temp1.DAT",ios::binary);
	DOCTOR s1,stud;
	int rno1;
	int found=1,confirm=2;
	cout<<"Enter PATIENT'S REGN NO whose APPOINTMENT is to be deleted";
	cin>>rno1;
	cout<<endl;
	while(!fio.eof())
	{
		fio.read((char*)&s1,sizeof(s1));
			if(s1.ano==rno1)
		{
		    s1.appdisp();
			found=0;
			cout<<"Are you sure you want to delete , PRESS 1 for YES & 2 for NO \n";
			cin>>confirm;
			if(confirm==2)
			file.write((char *)&s1,sizeof(s1));
			else
		break;
		}
		else
		file.write((char *)&s1,sizeof(s1));
	}
	if(found==1)
	cout<<"record not found"<<endl;
	fio.close();
	file.close();
	remove("app1.DAT");
	rename("temp1.DAT","app1.DAT");
    	 }
    	 cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
    	 break;
 	   }
}
void DOCTOR::newmed()
{
	system("COLOR B0");
	cout<<"================\n";
	cout<<"Today's date is ";D1.date();
	cout<<"\n";
	cout<<"================\n";
	
	cout<<"ENTER THE DATE \n";
	cout<<"DAY   = ";cin>>m1d;cout<<"\n";
    cout<<"MONTH = ";cin>>m1m;cout<<"\n";
	cout<<"YEAR  = ";cin>>m1y;cout<<"\n";
	cout<<"------------------\n";
	cout<<"BMI CALCULATOR   |\n";
	cout<<"------------------\n\n";
	cout<<"###############################\n";
	cout<<"ENTER THE WEIGHT (in Kg)    :  ";
	cin>>w;cout<<" \n";
	cout<<"ENTER THE HEIGHT (in meters : ";
	cin>>h;cout<<" \n";
	bm=w/(h*h);
	cout<<"##############################\n";
	cout<<"your BMI is :"<<bm <<" ";
	if(bm <=18.5)
	{
		cout<<" you are UNDERWEIGHT \n";
		strcpy(b,"UNDERWEIGHT");
	}
	else if(bm >18.5&&bm <=30.00)
    {
		cout<<"you are NORMAL \n";
		strcpy(b,"NORMAL");
	}
	else
	{
		cout<<" you are OBESE \n";
		strcpy(b,"OBESE");
	}
	cout<<"!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!\n";
	cout<<"enter remarks \n";cin.ignore();cout<<" ";
    cin.get(remark,100);
	cout<<"!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!^!\n";
	cout<<"\n ###############################\n";
	cout<<"enter the medicines \n";cin.ignore();cout<<" ";
	cin.get(med,50);
	cout<<"enter the CHARGES \n";
	cin>>cost;
}
void DOCTOR::existingp()
{
	    system("cls");
	    system("COLOR B0");
		 DOCTOR r1;
	long pos;
	int p=0;
	fstream xyz,a1,b1;
	xyz.open("patient1.DAT",ios::in|ios::binary|ios::out);
	a1.open("cost1.DAT",ios::binary|ios::out|ios::app);
	b1.open("hist1.DAT",ios::binary|ios::out|ios::app);
	cout<<"enter PATIENT'S REGN NO  = ";
	int x;
	cin>>x;
	cout<<"\n";
	while(!xyz.eof())
	{
		pos=xyz.tellg();
		xyz.read((char *)&r1,sizeof(r1));
		if(r1.reno()==x)
		{
			r1.dispmed();
			r1.newmed();
			xyz.seekg(pos);
			xyz.write((char *)&r1,sizeof(r1));
			a1.write((char *)&r1,sizeof(r1));
			b1.write((char *)&r1,sizeof(r1));
			p=1;
			break;
		}
	   	
	}
	if(p==0)
	cout<<"RECORD not found \n";
	xyz.close();
	a1.close();	
	b1.close(); 
}
void DOCTOR::dispmed()
{
    cout<<"================\n";
	cout<<"Today's DATE = ";D1.date();
	cout<<"\n";
	cout<<"================\n";
	cout<<"NAME  =";puts(name);cout<<"\n";
	cout<<"ID    =";
	cout<<"[ ";cout<<reno();cout<<" ] \n";
	cout<<"                                  previous DATE :"<<m1d<<"/"<<m1m<<"/"<<m1y<<"\n";
	cout<<"previous MEDICATIONS \n";
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	puts(med);cout<<"\n";
	cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n";
	cout<<endl;
	cout<<"                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"                   previous REMARKS                   |\n";
	cout<<"                ";puts(remark);
	cout<<"                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"previous BMI status  \n";
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n\n";
	cout<<"your BMI INDEX was "<<bm<<" , You were ";puts(b);
	cout<<" \n";
	cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%% \n";
}
void DOCTOR::precord()
{
	
	cout<<"----------------------------------\n";
	cout<<"\n ID     :"<<rno;
	cout<<"\n name   : ";puts(name);
	cout<<"\n age    : "<<age;
	cout<<"\n ph.no  : "<<puts(pn);
	cout<<"-----------------------------------\n";
}
void DOCTOR::new_entry()
{
	system("COLOR B0");
	cout<<"================\n";
	D1.date();
	cout<<"\n";
	cout<<"================\n";
	cout<<"welcome ! \n\n";
	cout<<"1) : enter PATIENT'S NAME :\n";
	cin.ignore();gets(name);
	cout<<"2) : enter PATIENT'S DATE OF BIRTH :\n";
	cout<<"day    : ";cin>>day;
	cout<<" month : ";cin>>month;
	cout<<" year  :";cin>>year;
	cout<<endl;
	cout<<"3) : enter PATIENT'S GENDER : (M/F) \n";
	cin>>gender;cout<<"\n";
	cout<<"4) : enter PATIENT'S CONTACT NO \n";
	cin.ignore();cout<<" ";cin.get(pn,100);
	age=2016-year;
	unsigned int value;
   time_t t;
   value=(unsigned)time(&t);
   srand(value);
    D1.rno=(rand()%99)+100;
	cout<<"PATIENT'S  ID is : "<<rno;
	cout<<endl;
}
void DOCTOR::search()
{
	  
	 DOCTOR yz;
	cout<<"enter the REGN NO to SEARCH =";
	int x;
	cin>>x;
	cout<<endl;
	fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&yz,sizeof(yz)))
       {
       		 if(yz.reno()==x)
   				{
				   	yz.precord();
         	     b.close();
				   }
       }
   
}
void DOCTOR::modify()
{
 
	DOCTOR r1;
	long pos;
	int p=0;
	fstream xyz;
	xyz.open("patient1.DAT",ios::in|ios::binary|ios::out);
	cout<<"enter REGN NO to MODIFY ";
	int x;
	cin>>x;
	cout<<endl;
	while(!xyz.eof())
	{
		pos=xyz.tellg();
		xyz.read((char *)&r1,sizeof(r1));
		if(r1.reno()==x)
		{
			r1.precord();
			r1.new_entry();
			xyz.seekg(pos);
			xyz.write((char *)&r1,sizeof(r1));
			p=1;
			break;
		}
		else
	       cout<<"PATIENT DATA does not exist \n";	
	}
	if(p==0)
	cout<<"RECORD not found \n";
	xyz.close();
}
void DOCTOR::del()
{
 
	ifstream fio("patient1.DAT",ios::binary);
	ofstream file("temp.DAT",ios::binary);
	DOCTOR s1,stud;
	int rno1;
	int found=1,confirm=2;
	cout<<"Enter REGN NO to DELETE =";
	cin>>rno1;
	cout<<endl;
	while(!fio.eof())
	{
		fio.read((char*)&s1,sizeof(s1));
			if(s1.reno()==rno1)
		{
		
			s1.precord();
			cout<<endl;
			found=0;
			cout<<"Are you sure you want to delete 1 for yes / 2 for no \n";
			cin>>confirm;
			if(confirm==2)
			file.write((char *)&s1,sizeof(s1));
			else
		   break;
		}
		else
		file.write((char *)&s1,sizeof(s1));
	}
	if(found==1)
	cout<<"record not found"<<endl;
	fio.close();
	file.close();
	remove("patient1.DAT");
	rename("temp.DAT","patient1.DAT");
}
void DOCTOR::patientmenu()
{
	system("cls");
	system("COLOR B0");
	cout<<"================\n";
	D1.date();
	cout<<"\n";
	cout<<"================\n";
	cout<<"\n welcome Dr \n\n";
	cout<<";.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:. \n\n";
	cout<<"press 1 for NEW ENTRY                : \n\n";
	cout<<"press 2 for EXISTING PATIENT         : \n\n";
	cout<<"press 3 to SEARCH FOR A PATIENT      : \n\n";
	cout<<"press 4 to MODIFY RECORD             : \n\n";
	cout<<"press 5 to DELETE A RECORD           : \n\n";
	cout<<"press 6 to go back to MAIN MENU      : \n\n";
	cout<<"press 7 to SHOW PATIENTS HISTORY     : \n\n";
	cout<<"press 8 to DISPLAY ALL RECORDS       : \n\n";
	cout<<"[.].[.].[.].[.].[.].[.].[.].[.].[.]\n\n";
	int x;
	cout<<"PLEASE ENTER YOUR OPTION =";
	cin>>x;
	cout<<" \n";
	switch(x)
	{
		case 1:
		{
	        fstream a;
	       a.open("patient1.DAT",ios::binary|ios::app|ios::out);
	       D1.new_entry();
	       a.write((char *)&D1,sizeof(D1));
	       a.close();
	       cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);	
		   break;
		}
		case 7:
		{
			   DOCTOR D2;
			   int p;
			   cout<<"enter PATIENT'S REGN NO TO OUTPUT HIS MEDICAL HISTORY : ";
			   cin>>p;
				fstream b;
		b.open("hist1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D2,sizeof(D2)))
       {
	        if(D2.reno()==p) 
	       D2.precord1();
       }
   b.close();
   cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
   break;
		}
		case 8:
		{
			   DOCTOR D2;
				fstream b;
		b.open("patient1.DAT",ios::binary|ios::in);
       while(b.read((char *)&D2,sizeof(D2)))
       {
	         D2.precord();
       
       }
   b.close();
   cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
   break;
		}
		case 2:
	    {
    	D1.existingp();
    	 cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);	
		break;
    	}
		case 3:
		{
			D1.search();
		cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
		}
		break;
		case 4:
		{
			D1.modify();
			cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
		}
		break;
		case 5:
		{
			D1.del();
			cout<<"do you want to go to the MAIN MENU .? press 1 if yes \n";
		int p;
		cin>>p;
		if(p==1)
		D1.show();
		else
		exit(0);
		}
		break;
		case 6:
		 show();
		break;
		default:
		cout<<"wrong option \n";
	exit(0);
	}
}
int main()
{
	system("COLOR B0");
	cout<<"================\n";
	D1.date();
	cout<<"\n";
	cout<<"================\n";
	int x=0;
	fstream b;
		b.open("xyz.DAT",ios::binary|ios::in);
       while( b.read((char *)&D1,sizeof(D1)))
       {
			   x++;
       }
   b.close();
   if(x==0)
  {
        fstream b;
		b.open("xyz.DAT",ios::binary|ios::out);
		D1.setup1();
        b.write((char *)&D1,sizeof(D1));
        b.close();
        D1.pass();
  }
   else if(x>0)
  D1.pass();
   
	
}

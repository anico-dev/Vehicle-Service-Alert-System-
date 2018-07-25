#include<fstream>
#include<windows.h>
#include<conio.h>
#include <ctype.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string.h>
using namespace std;
void gotoXY(int x, int y); 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
static int a;


class car //class for car related things
{
	public:
	char finame[100],color[100],add[100],type[100];
	char modelname1[100];
	char model_year[100],last_serviced[100],rc_number1[100],car_no[100];
	float initial_reading[5],final_reading[5],car_mileage,sum,car_avg,initial_fuel[5],final_fuel[5],sum1,car_fuel;
	int count,count1,f,i;
		void car_data() //function for inputing car data
		{
			system("cls"); //function for cleaning the screen
			f=1;
			cout<<"\n          ";
	char b[]="please fill up the following information for your car\n"; 
	int x=strlen(b);     //logic used for animation of b[]
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}
			
			
		cout<<"\nNAME :"; //enter name of customer
		cin.ignore();//it is a inbuilt function to clean the buffer
		cin.getline(finame,100);
		cout<<"\t\t\t\t\t\t Address : ";//enter the address of customer
		cin.getline(add,100);
		cout<<"MODEL NAME : ";//enter the model name of car
		cin.getline(modelname1,100);
		cout<<"\t\t\t\t\t\t FUEL TYPE : ";//enter fuel used by car
		cin.getline(type,100);
		cout<<"MODEL YEAR : ";//enter manufacturig year of a car
		cin.getline(model_year,100);
		cout<<"\t\t\t\t\t\t LAST SERVICED : ";//enter date when car was last serviced
		cin.getline(last_serviced,100);
		cout<<"RC NUMBER : ";//enter registration no for the car
		cin.getline(rc_number1,100) ;	
		cout<<"\t\t\t\t\t\t Car Number : ";//enter car plate no
		cin.getline(car_no,100);
	}
	void service()
   {
   	system("cls");
			cout<<"\n          ";
	char b[]="*********************************SERVICE NEED CALCULATOR**************************************\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
		
	}	//enter readings noted for the car from odometer after refueling
	
		cout<<"Enter the five readings from odometer of car after each fueling::\n";
		cout<<"Enter values::\n";
		for(int i=0;i<5;i++)
		{
			cout<<"Reading["<<i<<"] ::";
			cin>>initial_reading[i];
		}
		for(int i=0;i<4;i++) //calculating distance covered between two refuelings
			{
				final_reading[i]=initial_reading[i+1]-initial_reading[i];
			}
		count=0;//counter to keep count on the readings
		for(int i=0;i<4;i++)
		{
			sum+=final_reading[i];
			count++;		
		}		
		car_avg=sum/count;//average distance covered by the vehicle
		
		cout<<"Total distance covered by vehicle :: "<<car_avg<<endl<<endl;
		
		cout<<"Enter Amount of Fuel Filled : \n";//amount of fuel filled on each refueling in kilometers
		for(int i=0;i<4;i++)
		{
			cout<<"Fuel Filled ["<<i<<"] ::";
			cin>>initial_fuel[i];
		}
		count1=0;
		for(int i=0;i<4;i++)
		{
			sum1+=initial_fuel[i];
			count1++;
		}
		car_fuel=sum1/count1;
		cout<<"Total Fuel Consumed : \n"<<car_fuel<<endl<<endl;//total fuel consumed in liters
		car_mileage=car_avg/car_fuel;//mileage of a vehicle in kmpl
		cout<<" Total Distance Covered : "<<car_avg<<" Km"<<endl<<endl;
		cout<<" Total Fuel Consumed : "<<car_fuel<<" Liters"<<endl<<endl;
		cout<<"	Mileage of CAR is : "<<car_mileage<<" Kmpl"<<endl<<endl;
		system("pause");
   }
			void file_hand()
{
		
		ofstream fout("token_car.txt");
		fout<<"******************************CUSTOMER SERVICE TOKEN*****************************"<<endl<<endl;
		fout<<"Customer NAME : "<<finame<<"\n";
		fout<<"Customer Address : "<<add<<"\n";
		fout<<"Car Model : "<<modelname1<<"\n";
		fout<<"Model Year : "<<model_year<<"\n";
		fout<<"Fuel Type : "<<type<<"\n";
		fout<<"Registration Number:"<<rc_number1<<"\n";
		fout<<"Plate Number : "<<car_no<<"\n";
		fout<<"Last Serviced : "<<last_serviced<<"\n";
		fout<<"Total Distance Covered : "<<car_avg<<"\n";
		fout<<"Total Fuel Consumed : "<<car_fuel<<"\n";
		fout<<"Mileage of Car : "<<car_mileage<<"\n";
		fout<<"Customer Sign:-"<<"\t\t\t\t\t\t"<<"Auth. sign :-";
		fout.close();
		cout<<"\n\n\n\t\t\t\t Your Service Trip is succesfully Transfered!!!";

		
}
void ser_list()
		{
			system("cls");
			i=1;
			cout<<"***********************************Service Booking Portal*****************************\n";
 			
				ofstream fout1("service_queue(car).txt");	
				fout1<<"*******************************Service List(CAR)********************\n";
				fout1<<"S.No\t"<<"Customer Name\t"<<"Vehicle\t"<<"Mileage\t\n";
				fout1<<i<<".\t"<<finame<<"\t"<<modelname1<<"\t"<<car_mileage;
				i++;
				fout1.close();
				cout<<"\t\t\t\t\n\n\n\n\nYour Service is booked please come before the time alloted\t\t\t\t\n";
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Developed By:- ANICO-DEV Co.\n";

				system("pause");	
				}
   
	
	void display_car()
	
	
		{
			system("cls");
			cout<<"\n  ";
	char b[]="****************************************CAR INFORMATION FORM******************************\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}	
	cout<<"\n NAME : "<<finame<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" Address : "<<add<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" CAR MODEL : "<<modelname1<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" CAR MANUFACTURING : "<<model_year<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" LAST SERVICE DATE : "<<last_serviced<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" REGISTRATION NUMBER : "<<rc_number1<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" CAR NUMBER : "<<car_no<<"\t\t\t\t\t\t\t\t\n\n";
	system("pause");
	service();
	if(car_mileage>14)
	{
	cout<<"\t\t\tCongratulations!!! your CAR need not to go for a service.\n\n";	
	}
	else if(car_mileage<=14 && car_mileage>11)
	{
		cout<<"\t\t\tYour Car needs service within 1 month.\n\n";
	}
	else if(car_mileage>=11 && car_mileage>8)
		{
		cout<<"\t\t\tYour Car needs service within 15 days.\n\n";
		}
	else if(car_mileage<=8)
	{
		cout<<"\t\t\tYour Car needs service within a week.\n\n";
	}
		
	
	
	cout<<"\t\t\tEnter your choice to print the slip(Y/N) :: ";
	char ch;
	cin>>ch;
	if(ch=='y'||'Y')
	{
	cout<<"\n\n\n\t\t\tPlease Wait Your slip is procesing";
	char c[]="............................";
	int y=strlen(c);
	for(int i=0;i<y;i++)
	{
		Sleep(500);
		cout<<c[i];
	}
	file_hand();
	}
	else
		{
		cout<<"\t\t\t\n\n\nThank you For coming to HONDA ONLINE SERVICE STATION";
		}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Developed By:- ANICO-DEV Co.\n";
	
	system("pause");
	system("cls");
	int q;
	cout<<"\t\t\t\t\t\nTo Book Service at service station [1=yes and 2=NO] : \n";
	cin>>q;
	if(q==1)
	{
		ser_list();
	}
	else 
	{
		cout<<"\t\t\t\t\t\nThankyou for coming to this portal !!\n";
	}
	

		}
	
};
class bike
{
	public:
	char fname[100],color[100],add[100],type[100];
	char modelname[100];
	char model_year[100],last_serviced[100],rc_number[100],bike_no[100];
	float initial_reading[5],final_reading[5],mileage,sum,avg,initial_fuel[5],final_fuel[5],sum1,fuel;
	int count,count1,f,i;
		void bike_data()
		{
			system("cls");
			f=2;
			cout<<"\n          ";
	char b[]="please fill up the following information for your BIKE\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}
			
			
		cout<<"\nNAME :";
		cin.ignore();
		cin.getline(fname,100);
		cout<<"\t\t\t\t\t\t Address : ";
		cin.getline(add,100);
		cout<<"BIKE MODEL NAME : ";
		cin.getline(modelname,100);
		cout<<"\t\t\t\t\t\t FUEL TYPE : ";
		cin.getline(type,100);
		cout<<"MODEL YEAR : ";
		cin.getline(model_year,100);
		cout<<"\t\t\t\t\t\t LAST SERVICED : ";
		cin.getline(last_serviced,100);
		cout<<"RC NUMBER : ";
		cin.getline(rc_number,100) ;	
		cout<<"\t\t\t\t\t\t BIKE Number : ";
		cin.getline(bike_no,100);
	}
	void file_hand()
{
		
		ofstream fout("token_bike.txt");
		fout<<"******************************CUSTOMER SERVICE TOKEN*****************************"<<endl<<endl;
		fout<<"Customer NAME : "<<fname<<"\n";
		fout<<"Customer Address : "<<add<<"\n";
		fout<<"Bike Model : "<<modelname<<"\n";
		fout<<"Model Year : "<<model_year<<"\n";
		fout<<"Fuel Type : "<<type<<"\n";
		fout<<"Registration Number:"<<rc_number<<"\n";
		fout<<"Plate Number : "<<bike_no<<"\n";
		fout<<"Last Serviced : "<<last_serviced<<"\n";
		fout<<"Total Distance Covered : "<<avg<<"\n";
		fout<<"Total Fuel Consumed : "<<fuel<<"\n";
		fout<<"Mileage of Bike : "<<mileage<<"\n\n\n";
		fout<<"Customer Sign:-"<<"\t\t\t\t\t\t"<<"Auth. sign :-";
		fout.close();
		cout<<"\n\n\n\t\t\t\t Your Service Slip is succesfully Transfered!!!";
		
}
	void service()
   {
   	system("cls");
			cout<<"\n          ";
	char b[]="*********************************SERVICE NEED CALCULATOR**************************************\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}	
		cout<<"Enter the five readings from odometer of bike after each fueling::\n";
		cout<<"Enter values::\n";
		for(int i=0;i<5;i++)
		{
			cout<<"Reading["<<i<<"] ::";
			cin>>initial_reading[i];
		}
		for(int i=0;i<4;i++)
			{
				final_reading[i]=initial_reading[i+1]-initial_reading[i];
			}
		count=0;
		for(int i=0;i<4;i++)
		{
			sum+=final_reading[i];
			count++;		
		}		
		avg=sum/count;
		
		cout<<"Total distance covered by vehicle :: "<<avg<<endl<<endl;
		
		cout<<"Enter Amount of Fuel Filled : \n";
		for(int i=0;i<4;i++)
		{
			cout<<"Fuel Filled ["<<i<<"] ::";
			cin>>initial_fuel[i];
		}
		count1=0;
		for(int i=0;i<4;i++)
		{
			sum1+=initial_fuel[i];
			count1++;
		}
		fuel=sum1/count1;
		cout<<"Total Fuel Consumed : \n"<<fuel<<endl<<endl;
		mileage=avg/fuel;
		
		cout<<" Total Distance Covered : "<<avg<<" Km"<<endl<<endl;
		cout<<" Total Fuel Consumed : "<<fuel<<" Liters"<<endl<<endl;
	    cout<<"	Mileage of BIKE is : "<<mileage<<" Kmpl"<<endl<<endl;
	
		system("pause");
   }
	
	void serv_list()
				{
				ofstream fout2("service_queue(bike).txt");	
				fout2<<"*******************************Service List(BIKE)********************\n";
				fout2<<"S.No\t"<<"Customer Name\t"<<"Vehicle\t"<<"Mileage\t\n";
				fout2<<i;
				fout2<<".\t"<<fname;
				fout2<<"\t"<<modelname;
				fout2<<"\t"<<mileage;
				i++;
				fout2.close();
				cout<<"\t\t\t\t\t\n\n\n\nYour Service is booked please come before the time alloted\t\t\t\t\n";
				
				
			
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Developed By:- ANICO-DEV Co.\n";
			system("pause");
	}

		void bike_display()
		{
				{
			system("cls");
			cout<<"\n  ";
	char b[]="****************************************BIKE INFORMATION FORM******************************\n";
	int x=strlen(b);
	for(int i=0;i<x;i++)
	{
		Sleep(25);
		cout<<b[i];
	}	
	cout<<"\n NAME : "<<fname<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" Address : "<<add<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" BIKE MODEL : "<<modelname<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" BIKE MANUFACTURING : "<<model_year<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" LAST SERVICE DATE : "<<last_serviced<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" REGISTRATION NUMBER : "<<rc_number<<"\t\t\t\t\t\t\t\t\n\n";
	cout<<" BIKE NUMBER : "<<bike_no<<"\t\t\t\t\t\t\t\t\n\n";
	system("pause");
	service();
	if(mileage>45)
	{
	cout<<"\t\t\tCongratulations!!! your bike need not to go for a service.\n\n";
	}
	else if(mileage<=45 && mileage>35)
	{
		cout<<"\t\t\tYour Bike needs service within 1 month.\n\n";
	}
	else if(mileage<=35 && mileage>30)
		{
		cout<<"\t\t\tYour Car needs service within 15 days.\n\n";
		}
	else if(mileage<=30)
	{
		cout<<"\t\t\tYour bike needs service within a week.\n\n";
	}
		
		
	
	cout<<"\t\t\tEnter your choice to print the slip(Y/N) :: ";
	char ch;
	cin>>ch;
	if(ch=='y'||'Y')
	{
	cout<<"\n\n\n\t\t\tPlease Wait Your slip is procesing";
	char c[]="............................";
	int y=strlen(c);
	for(int i=0;i<y;i++)
	{
		Sleep(500);
		cout<<c[i];
	}
		file_hand();
	}
		else
		{
		cout<<"\t\t\t\n\n\nThank you For coming to HONDA ONLINE SERVICE STATION";
		}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Developed By:- ANICO-DEV Co.\n";
	
	system("pause");
	system("cls");
	int q;
	cout<<"\n\t\t\t\tTo Book Service at service station : \n";
	cin>>q;
	if(q==1)
	{
		serv_list();
	}
	
	

	}
	}

};


class maintence
{
	public:
		char message[200],name[100];
		void display()
		{
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tCalling HONDA SERVICES.";
			char c[]="............................";
	int y=strlen(c);
	for(int i=0;i<y;i++)
	{
		Sleep(500);
		cout<<c[i];
	}
	cout<<"\nThankyou For Calling HONDA SERVICES\n";
	cout<<"Enter Your Name ::\n";
	cin>>name;
	cout<<"Write Your message below ::\n";
	cin.ignore();
	cin.getline(message,100);
	
	ofstream fo("message.txt",ios::app);
	fo<<"***********************CUSTOMER CARE********************\n";
	fo<<" By : "<<name<<"\n"<<"Mesage :: "<<message<<"\n";
	fo.close();	
	cout<<"\nYour message is delivered!!!!";
	
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  Developed By:- ANICO-DEV Co.\n";
	system("pause");
			
		}
};









      
main() 
{
	car cr;
	bike bk;
	maintence ma;
	system("COLOR 2C");
	while(1)
	{
		system("cls");
		cout<<endl<<endl;
	
	Sleep(1000);
	system("COLOR 8F");
		char a[]="                                           $$$$$$$$$$$ HONDA MOTOR SERVICES $$$$$$$$$$$";
		int size;
		size=strlen(a);
		for(int i=0;i<size;i++)
		{
			Sleep(25);
			cout<<a[i];
		}
		int c=1;
		cout<<endl<<endl;
		Sleep(0);
		cout<<"\n                                                       1.CAR SERVICE\n                                                       2.BIKE SERVICE\n"
		    <<"                                                       3.CALL FOR MAINTENCE";
	cout<<"\n\t\t\t\t\t\t\t";
   	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Developed By:- ANICO-DEV Co.";

	for(int i=0;i<1;i++)
    {
    	int x = 1;
    	int y = 20;
    	for (x=40;x>1;x--)  
   		{
    	  gotoXY(x,y);
    	  cout << "THANK YOU FOR CHOSING HONDA SERVICES ::WE ARE ALWAYS THERE WITH YOU";
    	  Sleep(100);
    	  gotoXY(x,y); 
		  cout << "                                                         ";
		     cout<<"                                            "; 
  		}
  		cout <<endl<<" THANK YOU FOR CHOSING HONDA SERVICES 'APKA HUMSAFAR'"<<endl;
	}
   int ch;
   
	cout<<"\nSelect your option :";
	cin>>ch;
	
	switch(ch)
	{
		case 1:system("COLOR 1F");
				cr.car_data();
				cr.display_car();
				break;
		case 2:system("COLOR 1F");
				bk.bike_data();
				bk.bike_display();
				break;
		
		case 3:system("COLOR 1F");
				ma.display();
				break;
		default:system("COLOR E6");
				system("cls"); 
				cout<<"\nOopsss!!! you entered wrong choice!!!!";
	 			system("pause");
				 break;
	}
}
}	


void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

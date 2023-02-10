#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
using namespace std;
void login();
void registr();
void forgot();
int choose;
int price;
int quantity;
char buy;
long long int credit;
void electronics();
void general_Items();
void cloths();
void cosmatics();
void MainMenu();
 loginpage()
{
        int choice;
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t************************************************************************\n";
        cout<<"\t\t\t\t\t\t||                     Welcome to Our Login Page                      ||\n";
        cout<<"\t\t\t\t\t\t||                                                                    ||\n";
        cout<<"\t\t\t\t\t\t*******************        MENU        *********************************\n\n";
        cout<<"\t\t\t\t\t\t1.LOGIN"<<endl;
        cout<<"\t\t\t\t\t\t2.CREATE A NEW ACCOUNT"<<endl;
        cout<<"\t\t\t\t\t\t3.FORGOT PASSWORD (or) USERNAME"<<endl;
        cout<<"\t\t\t\t\t\t4.If your are login successful Press 4 going To Shopping Menu\n\n "<<endl;
        cout<<"\t\t\t\t\t\tEnter your choice :";
        cin>>choice;
        cout<<endl;
        while(choice <1 or choice>4)
        {
    	    cin.clear();
        	cout<<"\t\t\t\t\t\tPlease Enter a Valid Option :";
        	cin>>choice;
    	}
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:
                        cout<<"\t\t\t\t\t\tGoing to Shopping menu.\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"\t\t\t\t\t\tYou've made a mistake , give it a try again\n"<<endl; 
                        loginpage();
        }
        
}

void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"\t\t\t\t\t\tPlease Enter the following Details.\n"<<endl;
        cout<<"\t\t\t\t\t\tUSERNAME :";
        cin>>user;
        cout<<"\t\t\t\t\t\tPASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\t\t\t\t\t\t Hello  "<<user<<" LOGIN SUCESS\n\t\t\t\t\t\t We're glad that you're here.\n\t\t\t\t\t\t Thanks for logging in\n\n";
                cout<<"\t\t\t\t\t\t Press any key to go to the mainmenu.\n";
                cin.get();
                cin.get();
                loginpage();
        }
        else
        {
                cout<<"\t\t\t\t\t\tLOGIN ERROR\n\t\t\t\t\t\tPlease check your username and password\n\n\n";
                cout<<"\n\t\t\t\t\t\tPress any Key to Continue------\n\n\n";
                getch();
                loginpage();
        }
    
}

void registr()
{
    string reguser,regpass,ru,rp;
    system("cls");
    cout<<"\t\t\t\t\t\tEnter the username :";
    cin>>reguser;
    cout<<"\n\t\t\t\t\t\tEnter the password :";
    cin>>regpass;  
    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"\n\t\t\t\t\t\tCreated Your Account  Sucessfuly\n\n\n\n";
    loginpage();     
}

void forgot()
{
        int ch;
        system("cls");
        cout<<"\t\t\t\t\t\tForgotten ? We're here for help\n";
        cout<<"\t\t\t\t\t\t1.Search your id by username"<<endl;
        cout<<"\t\t\t\t\t\t2.Search your id by password"<<endl;
        cout<<"\t\t\t\t\t\t3.Main menu"<<endl;
        cout<<"\t\t\t\t\t\tEnter your choice :";
        cin>>ch;
        while(ch <1 or ch>3)
        {
    	    cin.clear();
    	    cout<<"\t\t\t\t\t\tPlease Enter a Valid Option :";
    	    cin>>ch;
    	}
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\n\t\t\t\t\t\tEnter your remembered username :";
                        cin>>searchuser;
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\n\t\t\t\t\t\tYour, account found\n";
                                cout<<"\n\t\t\t\t\t\tYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                 loginpage();
                        }
                        else
                        {
                                cout<<"\n\t\t\t\t\t\tSorry, Your userID is not found in our database\n";
                                cout<<"\n\t\t\t\t\t\tPlease kindly contact your system administrator for more details \n";
                                cout<<"\n\n\n\t\t\t\t\t\tPress any Key to Continue -------\n\n\n";
                                cin.get();
                                cin.get();
                                loginpage();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\n\t\t\t\t\t\tEnter the remembered password :";
                        cin>>searchpass;
                        
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\n\t\t\t\t\t\tYour password is found in the database \n";
                                cout<<"\n\t\t\t\t\t\tYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                loginpage();
                        }
                        else
                        {
                                cout<<"\t\t\t\t\t\tSorry, We cannot found your password in our database \n";
                                cout<<"\n\t\t\t\t\t\tkindly contact your administrator for more information\n";
                                cout<<"\n\n\n\t\t\t\t\t\tPress any Key to Continue -------\n\n\n";
                                cin.get();
                                cin.get();
                               loginpage();
                        }
                
                        break;
                }
                
                case 3:
                {
                	cout<<"\n\n\n\n";
                        cin.get();
                         loginpage();
                }
        }
}
int main()
{
	loginpage();
	MainMenu();
	return 0;
}
void MainMenu()
{
void electronics();
void general_Items();
void cloths();
void cosmatics();
	label1:
	system("cls");
	cout<<"\t\t\t\t\t\t***************************************************\n";
	cout<<"\t\t\t\t\t\t||      Welcome To Online Shopping System        ||\n";
	cout<<"\t\t\t\t\t\t***************************************************";
	cout<<"\n\n\n\t\t\t\t\t\tChoose anyone from below :"<<endl<<endl<<
	"\n\t\t\t\t\t\t1. Electronics Gadegets :"<<endl<<
	"\n\t\t\t\t\t\t2. General Items :"<<endl<<
	"\n\t\t\t\t\t\t3.Cloths :"<<endl<<
	"\n\t\t\t\t\t\t4. Cosmatics :"<<endl<<endl<<"\n\t\t\t\t\t\tYour choice :";
	cin>>choose;
   while(choose <1 or choose>4)
    {
    	cin.clear();
    	cout<<"\n\t\t\t\t\t\tPlease Enter a Valid Option :";
    	cin>>choose;
	}
	switch(choose)
	{
		case 1:
			electronics();
			break;
			case 2:
			    general_Items();
			    break;
			    case 3:
			        cloths();
			        break;
			        case 4:
			            cosmatics();
			            break;		
	}
}
	void electronics()
	{
		system("cls");
	    cout<<"\t\t\t\t\t\t***************************************************\n";
    	cout<<"\t\t\t\t\t\t||                Electronics Gadegets           ||\n";
    	cout<<"\t\t\t\t\t\t***************************************************";
        cout<<"\n\n\n\t\t\t\t\t\tChoose anyone from below :"<<endl<<endl<<
	      "\n\t\t\t\t\t\t1. Fridge:"<<endl<<
	      "\n\t\t\t\t\t\t2. AC :"<<endl<<
	      "\n\t\t\t\t\t\t3.Computer/Laptop :"<<endl<<
	      "\n\t\t\t\t\t\t4. Smart Phones :"<<endl<<endl<<"\t\t\t\t\t\tYour choice :";
	    cin>>choose;
	    if(choose==1)
	    {
	       system("cls");
	       price=15000;
           cout<<"\t\t\t\t\t\t***************************************************\n";
	       cout<<"\t\t\t\t\t\t||                  Fridge Area                  ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
	       cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the Fridge .\n";
	       cout<<"\n\t\t\t\t\t\tPrice :"<<price<<endl;
	       cout<<"\n\t\t\t\t\t\tHow many items you want to purchase :";
	       cin>>quantity;
	       cout<<"\n\t\t\t\t\t\tYou want to buy Fridge your items are ("<<quantity<<")"<<endl;
	       cout<<"\n\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
	       cout<<"\n\t\t\t\t\t\tDo you want to buy ( Y or N ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"\n\t\t\t\t\t\tEnter your credit card number  :";
	       	cin>>credit;
	       	cout<<"\n\t\t\t\t\t\tYou have entered this credit card Number :"<<credit<<endl;
	       	cout<<"\n\t\t\t\t\t\tPress 1 to buy\n\n\t\t\t\t\t\t Press any key to go to thew Main Menu\n\n\n\t\t\t\t\t\tYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"\n\n\t\t\t\t\t\tYou have Successfully bought the fridge :";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	cout<<"\t\t\t\t\t\t";
			   	MainMenu();
			   }
		   }
		   else
		   {
		   	MainMenu();
		   }
		}
		else if(choose==2)
	    {
	       price=20000;
	       system("cls");
           cout<<"\t\t\t\t\t\t***************************************************\n";
	       cout<<"\t\t\t\t\t\t||                     AC Area                   ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
	       cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the AC\n";
	       cout<<"\n\t\t\t\t\t\tPrice :"<<price<<endl;
	       cout<<"\n\t\t\t\t\t\tHow many items you want to purchase:";
	       cin>>quantity;
	       cout<<"\n\t\t\t\t\t\tYou want to buy AC your items are ("<<quantity<<")"<<endl;
	       cout<<"\n\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
	       cout<<"\n\t\t\t\t\t\tDo you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"\n\t\t\t\t\t\tEnter your credit card number :";
	       	cin>>credit;
	       	cout<<"\n\t\t\t\t\t\tYou have entered this credit card Number :"<<credit<<endl;
	       	cout<<"\n\t\t\t\t\t\tPress 1 to buy\n\n\t\t\t\t\t\t Press any key to go to thew Main Menu\n\n\n\t\t\t\t\t\tYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"\n\t\t\t\t\t\tYou have Successfully bought the AC :";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		    else
		   {
		   	MainMenu();
		   }
		}
		else if(choose==3)
	    {
	    	price=60000;
	    	system("cls");
           cout<<"\t\t\t\t\t\t***************************************************\n";
	       cout<<"\t\t\t\t\t\t||                  Computer Area                  ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
	       cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the COMPUTER\n";
	       cout<<"\n\t\t\t\t\t\tPrice :"<<price<<endl;
	       cout<<"\n\t\t\t\t\t\tHow many items you want to purchase:";
	       cin>>quantity;
	       cout<<"\n\t\t\t\t\t\tYou want to buy COMPUTER your items are ("<<quantity<<")"<<endl;
	       cout<<"\n\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
	       cout<<"\n\t\t\t\t\t\tDo you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"\n\t\t\t\t\t\tEnter your credit card number :";
	       	cin>>credit;
	       	cout<<"\n\t\t\t\t\t\tYou have entered this credit card Number :"<<credit<<endl;
	       	cout<<"\n\t\t\t\t\t\tPress 1 to buy\n\n\t\t\t\t\t\t Press any key to go to thew Main Menu\n\n\n\t\t\t\t\t\tYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"\n\t\t\t\t\t\tYou have Successfully bought the COMPUTER ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		    else
		   {
		   	MainMenu();
		   }
		}
		else if(choose==4)
		{
		   price=8000;
		   system("cls");
           cout<<"\t\t\t\t\t\t***************************************************\n";
	       cout<<"\t\t\t\t\t\t||              Smart Phone Area                  ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
	       cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the SMART PHONE\n";
	       cout<<"\n\t\t\t\t\t\tPrice :"<<price<<endl;
	       cout<<"\n\t\t\t\t\t\tHow many items you want to purchase:";
	       cin>>quantity;
	       cout<<"\n\t\t\t\t\t\tYou want to buy SMART PHONE your items are ("<<quantity<<")"<<endl;
	       cout<<"\n\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
	       cout<<"\n\t\t\t\t\t\tDo you want to buy ( Yes or No )";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"\n\t\t\t\t\t\tEnter your credit card number";
	       	cin>>credit;
	       	cout<<"\n\t\t\t\t\t\tYou have entered this credit card Number :"<<credit<<endl;
	       	cout<<"\n\t\t\t\t\t\tPress 1 to buy\n \t\t\t\t\t\tPress any key to go to thew Main Menu\n\n\n\t\t\t\t\t\tYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"\n\t\t\t\t\t\tYou have Successfully bought the SMART PHONE ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		   else
		   {
		   	MainMenu();
		   }
		}
	}
	void general_Items()
	{
		system("cls");
           cout<<"\t\t\t\t\t\t***************************************************\n";
	       cout<<"\t\t\t\t\t\t||                 GENERAL ITEMS                 ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
        cout<<"\n\n\n\t\t\t\t\t\tChoose anyone from below :"<<endl<<endl<<
	      "\n\t\t\t\t\t\t1. RICE:"<<endl<<
	      "\n\t\t\t\t\t\t2. PULSE :"<<endl<<
	      "\n\t\t\t\t\t\t3.VEGETABLE :"<<endl<<
	      "\n\t\t\t\t\t\t4. SPICE :"<<endl<<endl<<"\n\t\t\t\t\t\tYour choice";
	    cin>>choose;
	    if(choose==1)
	    {
	       system("cls");
	       price=500;
           cout<<"\t\t\t\t\t\t***************************************************\n";
	       cout<<"\t\t\t\t\t\t||                   Rice  Area                  ||\n";
           cout<<"\t\t\t\t\t\t***************************************************";
	       cout<<"\n\n\t\t\t\t\t\tYou are about to purchase the RICE :\n";
	       cout<<"\t\t\t\t\t\tPrice :"<<price<<endl;
	       cout<<"\t\t\t\t\t\tHow many items you want to purchase:";
	       cin>>quantity;
	       cout<<"\t\t\t\t\t\tYou want to buy RICE your items are : ("<<quantity<<")"<<endl;
	       cout<<"\t\t\t\t\t\tYour total Price :"<<quantity*price<<endl;
	       cout<<"\t\t\t\t\t\tDo you want to buy ( Yes or No )";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the RICE ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
	    
		}
		else if(choose==2)
	    {
	       price=600;
	       system("cls");
	       cout<<"\n\t\t\t\t\t\t***************************************************";
	       cout<<"\n\n\t\t\t\t\t||                  PULSE Area                   ||";
	       cout<<"\n\t\t\t\t\t\t***************************************************";
	       cout<<"\n\nYou are about to purchase the PULSE\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase:";
	       cin>>quantity;
	       cout<<"you want to buy PULSE your items are :("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the PULSE ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
		else if(choose==3)
	    {
	    	price=700;
	    	system("cls");
	    	cout<<"***************************************************";
	       cout<<"\n\nVEGETABLE Area\n\n";
	       cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the VEGETABLE\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase :";
	       cin>>quantity;
	       cout<<"you want to buy VEGETABLE your items are :("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the VEGETABLE ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
		else if(choose==4)
		{
		   price=800;
		   system("cls");
		   cout<<"***************************************************";
		   cout<<"\n\nSPICE Area\n\n";
		   cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the SPICE\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase:";
	       cin>>quantity;
	       cout<<"you want to buy SMART PHONE your items are ("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the SPICE ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
	}
	void cloths()
	{
	
		system("cls");
		cout<<"***************************************************";
	    cout<<"\n\n\n\t\tCLOTHES SECTION\n\n\n";
	    cout<<"***************************************************";
        cout<<"\n\n\nChoose anyone from below :"<<endl<<endl<<
	      "1. SHIRT:"<<endl<<
	      "2. T.SHIRT :"<<endl<<
	      "3.JEANS :"<<endl<<
	      "4. DUPATTA :"<<endl<<endl<<"Your choice :";
	    cin>>choose;
	    if(choose==1)
	    {
	       system("cls");
	       price=1000;
	       cout<<"***************************************************";
	       cout<<"\n\n SHIRT\n\n";
	       cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the  SHIRT\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase:";
	       cin>>quantity;
	       cout<<"you want to buy  SHIRT your items are :("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the  SHIRT";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
	    
		}
		else if(choose==2)
	    {
	       price=2000;
	       system("cls");
	       cout<<"***************************************************";
	       cout<<"\n\nT.SHIRT Area\n\n";
	       cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the T.SHIRT\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase:";
	       cin>>quantity;
	       cout<<"you want to buy AC your items are ("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No )";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the T.SHIRT ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
		else if(choose==3)
	    {
	    	price=3000;
	    	system("cls");
	    	cout<<"***************************************************";
	       cout<<"\n\nJEANS\n\n";
	       cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the JEANS\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase:";
	       cin>>quantity;
	       cout<<"you want to buy JEANS your items are : ("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the JEANS";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
		else if(choose==4)
		{
		   price=4000;
		   system("cls");
		   cout<<"***************************************************";
		   cout<<"\n\n DUPATTA  Area\n\n";
		   cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the  DUPATTA \n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase :";
	       cin>>quantity;
	       cout<<"you want to buy  DUPATTA  your items are : ("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the  DUPATTA ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
	}
	void cosmatics()
	{
	
		system("cls");
		cout<<"***************************************************";
	    cout<<"\n\n\n\t\tCOSMATIC Section\n\n\n";
	    cout<<"***************************************************";
        cout<<"\n\n\nChoose anyone from below :"<<endl<<endl<<
	      "1. NAILPAINT:"<<endl<<
	      "2. MEHNDI :"<<endl<<
	      "3.BINDI :"<<endl<<
	      "4. PAYAL :"<<endl<<endl<<"Your choice";
	    cin>>choose;
	    if(choose==1)
	    {
	       system("cls");
	       price=50;
	       cout<<"***************************************************";
	       cout<<"\n\nNAILPAINT\n\n";
	       cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the NAILPAINT\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase :";
	       cin>>quantity;
	       cout<<"you want to buy NAILPAINT your items are :("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the NAILPAINT ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
	    
		}
		else if(choose==2)
	    {
	       price=60;
	       system("cls");
	       cout<<"***************************************************";
	       cout<<"\n\nMEHNDI Area\n\n";
	       cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the MEHNDI\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase :";
	       cin>>quantity;
	       cout<<"you want to buy MEHNDI your items are :("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the MEHNDI ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
		else if(choose==3)
	    {
	    	price=70;
	    	system("cls");
	    	cout<<"***************************************************";
	       cout<<"\n\nBINDI  Area\n\n";
	       cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the BINDI \n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase :";
	       cin>>quantity;
	       cout<<"you want to buy BINDI  your items are : ("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the BINDI  ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
		else if(choose==4)
		{
		   price=80;
		   system("cls");
		   cout<<"***************************************************";
		   cout<<"\n\nPAYAL Area\n\n";
		   cout<<"***************************************************";
	       cout<<"\n\nYou are about to purchase the PAYAL\n";
	       cout<<"Price :"<<price<<endl;
	       cout<<"How many items you want to purchase :";
	       cin>>quantity;
	       cout<<"you want to buy PAYAL your items are : ("<<quantity<<")"<<endl;
	       cout<<"Your total Price :"<<quantity*price<<endl;
	       cout<<"Do you want to buy ( Yes or No ) :";
	       cin>>buy;
	       if(buy=='y'||buy=='Y')
	       {
	       	cout<<"Enter your credit card number :";
	       	cin>>credit;
	       	cout<<"You have entered this credit card Number :"<<credit<<endl;
	       	cout<<"Press 1 to buy\n Press any key to go to thew Main Menu\n\n\nYour Choice :";
	       	cin>>choose;
	       	if(choose==1)
	       	{
	       		cout<<"You have Successfully bought the PAYAL ";
	       		system("pause");
	       		MainMenu();
			   }
			   else
			   {
			   	MainMenu();
			   }
		   }
		}
	}	

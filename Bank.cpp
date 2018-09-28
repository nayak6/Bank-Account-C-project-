//************************************************************
// HEADER FILES USED IN THE PROJECT
//************************************************************

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream.h>

//*************************************************************
//CLASS USED IN PROJECT
//*************************************************************

class Bank
{
private:
int Acc_No;
char Name[50];
char Type;
int T_Amount;
public:
int Deposit;

void Entry_Acc();             //function to get the details of the account by the user
void Display_Acc();           //function to display the account details given by the user
char ret_Type();               // function to return the type of the account
void Modify();                //function to get new data
int ret_AccNo()               //function to return account number
{ return Acc_No;}
Bank()
{
Deposit=0;
}


int ret_Balance_DP()              //function to return the amount deposited
{
return T_Amount=Deposit+T_Amount;
}

int ret_Balance_WD()             //function to return the amount withdrawn
{
return T_Amount=T_Amount-Deposit;
}

int ret_TAmount()                 //function to return the total amount
{return T_Amount;}

}Acc_1;                           //closing the class and creating an object Acc_1
int n;

char Bank::ret_Type()             // function to return the tupe of accout
{ return Type;}

void Bank::Entry_Acc()             //describing the function Entry_Acc() to enter the account details
{
cout<<"\n***************************************************\n";
cout<<"\n\nEnter The Account No. :";
cin>>Acc_No;
cout<<"Enter The Name Of The Account Holder :";
gets(Name);
cout<<"Enter The Type Of The Accont(C/S) :";
cin>>Type;
Type=toupper(Type);
cout<<"Enter The Initial Amount The Account Holder Want To Deposit\n(>=1000 For Saving Account and >=2500 For Current Account) :";
cin>>T_Amount;
cout<<"\n\n\n\n\nACCOUNT CREATED.............";
cout<<"\n***************************************************\n";
}                                     //closing Entry_Acc()


void Bank::Display_Acc()                 //describing the function Display_Acc() to d
{
cout<<"\n***************************************************\n";
cout<<"\n\nYour Account No. is :";
cout<<Acc_No;
cout<<"\nName Of The Account Holder is :";
cout<<Name;
cout<<"\nThe Type Of The Accont is :";
cout<<Type;
cout<<"\nThe Initial Amount The Account Holder Want To Deposit\n(>=1000 For Saving Account and >=2500 For Current Account) is :";
cout<<T_Amount;
cout<<"\nYour Balance Amount is :"<<Acc_1.T_Amount;
cout<<"\n***************************************************\n";
getche();
}

void Bank::Modify()            //describing the function modify to get the details of the account
{
cout<<"\n***************************************************\n";
cout<<"\n\nEnter The Account No. :";
cin>>Acc_No;
cout<<"Enter The Name Of The Account Holder :";
gets(Name);
cout<<"Enter The Type Of The Accont(C/S) :";
cin>>Type;
Type=toupper(Type);
cout<<"Enter The Initial Amount The Account Holder Want To Deposit\n(>=1000 For Saving Account and >=2500 For Current Account) :";
cin>>T_Amount;
cout<<"\n***************************************************\n";
}

void Welcome()                 //describing the function to welcome the customer as it enters into the bank
{
clrscr();
cout<<"\n***************************************************\n";
cout<<"\n\n\n\n\n\t\t\t\tWE WELCOME YOU";
getche();
clrscr();
cout<<"\n\n\n\n\n\n\t\t\t\t TO";
cout<<"\n***************************************************\n";
getche();
clrscr();
 cout<<"\n***************************************************\n";
cout<<"\n\t\t\t\t   BANK"<<"\n\n\t\t\t\tMANAGEMERNT"<<"\n\n\t\t\t\t  SYSTEM" ;
cout<<"\n***************************************************\n";
getche();
clrscr();
cout<<"\n***************************************************\n";
cout<<"\n\t\t\t\tMADE BY" ;
cout<<"\n\n\t\t\t\tGROUP MEMBERS"<<"\n\t\t\t\t1.Amrish Nayak"<<"\n\t\t\t\t2.Aprajita"<<"\n\t\t\t\t3.Pawan Kumar"<<"\n\t\t\t\t4.Ram Kumar";
cout<<"\n***************************************************\n";
getche();

}
void Create_Acc()                               //describing the function to creat a new account
{
cout<<"\n***************************************************\n";
cout<<"\t\t\tNEW ACCOUNT SCREEN";
ofstream ofile;
ofile.open("BANK_ACC.dat",ios::binary|ios::app);
Acc_1.Entry_Acc();
ofile.write((char*)&Acc_1,sizeof(Acc_1));
ofile.close();
cout<<"\n***************************************************\n";
}

void Balance_Details()  //describing the function to showm balance details
{
cout<<"\n***************************************************\n";
cout<<"\n\t\t\t\tBALANCE DETAILS";
int set=0;
cout<<"\n\n\n\nEnter The Account No. :";
cin>>n;
ifstream f2;
f2.open("BANK_ACC.dat",ios::binary);    //opening a binary file BANK

if(!f2)
 {
 cout<<"FILE COULD NOT BE OPENED.";
 getch();
 return;
 }

while(f2.read((char*)&Acc_1,sizeof(Bank)))     //loop to read the binary file created on conditions given
{
 if(Acc_1.ret_AccNo()==n)
  {
 Acc_1.Display_Acc();
 set=1 ;
  }

}
f2.close();   //closing the file


  if(set==0)
  {
  cout<<"OOPS!!!This Account No. Doesn't Exist.\n\n" ;
  cout<<"\n\n\n PLEASE ENTER THE CORRECT ACCOUNT NO.";
  }
  cout<<"\n***************************************************\n";
getche();

}

void Delete_Acc()          //function to delete the record of the file
{
cout<<"\n***************************************************\n";
cout<<"\n\t\t\t\tDELETE ACCOUNT SCREEN";
cout<<"\n\n\nEnter The Account No. To Be Deleted :";
cin>>n;
ifstream f1;
ofstream f2;
f1.open("BANK_ACC.dat",ios::binary);
f2.open("Temp.dat",ios::binary);
while(f1.read((char*)&Acc_1,sizeof(Bank)))
{
if(Acc_1.ret_AccNo()!=n)
{

f2.write((char*)&Acc_1,sizeof(Bank));

}
}
f1.close();
f2.close();
remove("BANK_ACC.dat");
rename("Temp.dat","BANK_ACC.dat");
cout<<"\n\n\nRECORD DELETED...............";
cout<<"\n***************************************************\n";
}
void All_Users()  //function to display all account details
{
cout<<"\n***************************************************\n";
cout<<"\n\t\t\tAll ACCOUNT HOLDER LIST";
ifstream f1("BANK_ACC.dat",ios::binary);
while(f1.read((char*)&Acc_1,sizeof(Bank)))
{
Acc_1.Display_Acc();
}
f1.close();
}

void Deposit()                       //function to deposit amount
{
int t,flag=0;
cout<<"\n\t\t\tDEPOSIT AMOUNT";
cout<<"\n\n\nEnter The Account No. :";
cin>>t;

fstream file("BANK_ACC.dat",ios::in|ios::out|ios::binary);
while(file.read((char*)&Acc_1,sizeof(Bank)))
{
if(Acc_1.ret_AccNo()==t)
{
Acc_1.Display_Acc();
cout<<"\n\n\n\t\t\tTO DEPOSIT AMOUNT";
cout<<"\nEnter The Amount To Be Deposited :";
cin>>Acc_1.Deposit;
Acc_1.ret_Balance_DP();
int pos=(-1)*sizeof(Acc_1) ;
file.seekp(pos,ios::cur);
file.write((char*)&Acc_1,sizeof(Bank));
cout<<"RECORD UPDATED.........";
flag=1;
}
}
file.close();
if(flag==0)
cout<<"\n\nOOPS! THIS ACCOUNT NO. DOESN'T EXIST.";
cout<<"\n***************************************************\n";
}
				    //function to withdraw amount
void Withdraw()
{
cout<<"\n***************************************************\n";
cout<<"\n\t\t\tWITHDRAW AMOUNT SCREEN";
int tmp=0;
cout<<"\n\t\t\tDEPOSIT AMOUNT";
cout<<"\n\n\nEnter The Account No. :";
cin>>n;

fstream file("BANK_ACC.dat",ios::binary|ios::in|ios::out);
while(file.read((char*)&Acc_1,sizeof(Bank)))
{
if(Acc_1.ret_AccNo()==n)
{
Acc_1.Display_Acc();
cout<<"\n\n\n\t\t\tTO WITHDRAW AMOUNT";
cout<<"\nEnter The Amount To Be Withdrawn";
cin>>Acc_1.Deposit;
int bal=Acc_1.ret_TAmount()-Acc_1.Deposit;
if((bal<=1000 && Acc_1.ret_Type()=='S') || (bal<=2500 && Acc_1.ret_Type()=='C'))
cout<<"\n\nSorry!!! Your Balance Is Insufficient.";
else
Acc_1.ret_Balance_WD();

int pos=(-1)*sizeof(Acc_1) ;
file.seekp(pos,ios::cur);
file.write((char*)&Acc_1,sizeof(Bank));
cout<<"RECORD UPDATED......";
tmp=1;
}
}
file.close();
if(tmp==0)
cout<<"\n\nOOPS! THIS ACCOUNT NO. DOESN'T EXIST.";
cout<<"\n***************************************************\n";
}

void Modify_Account()               //function to modify the record of file
{
cout<<"\n***************************************************\n";
cout<<"\n\t\t\tMODIFY ACCOUNT SCREEN\n\n\n\n" ;
int flag=0;
cout<<"\tEnter The Account No. To be MODOIFIED :";
cin>>n;
fstream iofile;
iofile.open("BANK_ACC.dat",ios::binary|ios::in|ios::out);
while(iofile.read((char*)&Acc_1,sizeof(Bank)))
{
if(Acc_1.ret_AccNo()==n)
{
Acc_1.Display_Acc();
cout<<"\n\nEnter The New Details Of The Account :";
Acc_1.Modify();
int pos=(-1)*sizeof(Bank);
iofile.seekp(pos,ios::cur);
iofile.write((char*)&Acc_1,sizeof(Bank)) ;
cout<<"\n\nRecord Has Been Successfully Modified......";
flag=1;
}
}
iofile.close();
if(flag==0)
cout<<"\n\nOOPS! THIS ACCOUNT NO. DOESN'T EXIST.";
cout<<"\n***************************************************\n";
}






     //****************************************************

      //THE MAIN BODY OF THE PROGRAM

      //****************************************************
void main()
{
clrscr();
char ch;
Welcome();
do
{
clrscr();
cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL Account HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNTt";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";

		cin>>ch;
		clrscr();
		switch(ch)
		{
		case '1':
			Create_Acc();
			cout<<"Thanks For Creating New Account." ;
			break;
		case '2':
			Deposit();
			break;
		case '3':
			Withdraw();
			break;
		case '4':
			Balance_Details();
			break;
		case '5':
			All_Users();
			break;
		case '6':

			Delete_Acc();
			break;
		case '7':
			 Modify_Account();
			 break;
		case '8':
		cout<<"\n***************************************************\n";
			cout<<"\n\n\n\n\n\tThanks For Using Our Bank Management System.";
		cout<<"\n***************************************************\n";
			break;
		default :cout<<"\n***************************************************\n";
		cout<<"\a";
			  cout<<"\n\t\t\t\tOOPS!!!"<<"\nSorry!We could not recognise your choice.";
			  cout<<"\n\n\t\tPlease select one of the given Options(1-8).";
		cout<<"\n***************************************************\n";
		}
		getche();
	}while(ch!='8');

}

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

class bank
{  int accountno,amount;
   char name[50],type;
   public:
   void create_account();
   void showacc();
   void report();
   void modify();
   int retacno() const;
   int amountd(int) const;

};
void bank::create_account()
{
    cout<<"\n==========<<< WELCOME TO BANK OF ASG >>>========== ";
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>accountno;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>amount;
	cout<<"\n\n\t\t\tAccount Created..";
}


void bank::showacc()

{
 cout<<"==========<<< WELCOME TO BANK OF ASG >>>========== \n";
 cout<<"\nthe account no is:-"<<accountno;
 cout<<"\nthe name of account holder is:-"<<name;
 cout<<"\nthe type of account:-"<<type;
 cout<<"\nenter the initial account:-"<<amount;
}

void bank::modify()
{   cout<<"==========<<< WELCOME TO BANK OF ASG >>>========== ";
	cout<<"\n\tAccount No. : "<<accountno;
	cout<<"\n\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tModify Balance amount : ";
	cin>>amount;
}
int bank::retacno() const
{
	return accountno;
}

int bank::amountd(int x) const
{
  amount;
  return amount;
}
void bank::report()
{
	cout<<"AMOUNT IS:-"<<accountno<<"\t"<<"NAME IS:-"<<name<<"\t"<<"TYPE OF ACCOUNT IS:-"<<type<<"\t"<<"AMOUNT IS:-"<<amount<<"\t"<<endl;
}


void write_account();
void modify_account(int);
void show_all();
void show_details(int);
void add_amount(int);
void delete_account(int);

int main()
{ char ch;
  int inp;
  do{ cout<<"<<<<<<<<<<<<* ADARSH SINGH GAHARWAR NATIONAL BANK *>>>>>>>>>>>>>>\n";
      cout<<"#################################################################\n";
      cout<<"<<<      CHOOSE ANY OPTION AMOUNG THIS GIVE BELOW OPTION      >>>\n";
      cout<<"1. for Enteringrg the details \n";
      cout<<"2. for modifing the details of the account \n";
      cout<<"3. for printing all the accounts present \n";
      cout<<"4. for printing details of a specific account \n";
      cout<<"5. for Adding ammount in the account \n";
      cout<<"6. for deleting account from the bank\n";
      cout<<"7. for exiting the file \n";
      cout<<"#################################################################\n\n\n";
      cin>>ch;
      switch(ch)
      {
          case '1':
           cout<<"-------ENTER THE DETAILS-------";
          write_account();
          break;

          case '2':
           cout<<"-------To modify the details of the account is---------";
           cin>>inp;
           modify_account(inp);
           break;

          case '3':
          cout<<"-------ALL THE ACCOUNT HOLDER DETAILS ARE------\n";
          show_all();
          break;

          case '4' :
          cout<<"-------TO print details of a specific account -----------";
          cin>>inp;
          show_details(inp);
          break;

           case '5' :
          cout<<"-------To add amount in account -----------";
          cin>>inp;
          add_amount(inp);
          break;

          case '6':
          cout<<"--------To delete account from the bank------";
          cin>>inp;
          delete_account(inp);
          break;
          case '7':
			cout<<"\n\n\tThanks for using bank managemnt system";
			break;



          default: cout<<"\n";

       }
        cin.ignore();
        cin.get();
    }while(ch!='6');
 return 0;
}
//this will help in adding accounts the bank.
void write_account()
{
	bank ac;
	ofstream outFile;
	outFile.open("account.docx",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(bank));
	outFile.close();
}


//this will modify the details in the account.
void modify_account(int n)
{
    bool found=false;
	bank ac;
	fstream File;
    File.open("account.docx",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(bank));
		if(ac.retacno()==n)
		{
			ac.showacc();
			cout<<"\n\n\t\t\tEnter The New Details of account \n"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(bank));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(bank));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";


}

// this will show all the accounts present in the bank.
void show_all()
{
  bank ac;
  ifstream show;
  show.open("account.docx",ios::binary);
  if(!show)
  { cout<<"the acccount dose not exist in the file";
    return;
  }
  cout<<"--------ALL THE DETAILS OF THE ACCOUNT ARE --------\n";
  while(show.read(reinterpret_cast<char *> (&ac),sizeof(bank)))
  ac.report();
  show.close();
}

void show_details(int n)
{
    bool found=false;
	bank ac;
	fstream File;
    File.open("account.docx",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(bank));
		if(ac.retacno()==n)
		{
			ac.showacc();

		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";


}



void add_amount(int n)
{ bank ac;
  fstream File;
  File.open("account.docx",ios::binary|ios::in|ios::out);
  if(!File)
  {
     cout<<"could not open file may it is empty";
     return ;

  }
  while(!File.eof())
  {

   File.read(reinterpret_cast<char *> (&ac), sizeof(bank));
   if(ac.retacno()==n)
   {  ac.showacc();
      int p;
      cout<<"enter the amount to be added";
      cin>>p;
      ac.amountd(p);

     int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(bank));
			cout<<"\n\n\t Record Updated";
   }
  }
 File.close();

}

void delete_account(int n)
{ bank ac;
  fstream File;
  File.open("account.docx",ios::binary|ios::in|ios::out);
  if(!File)
  { cout<<"The account does not exist in the Bank";
    return ;

  }
  while(!File.eof())
  { File.read(reinterpret_cast<char *>(&ac),sizeof(bank));
    if(ac.retacno()!=n)
    {
       File.write(reinterpret_cast<char *> (&ac), sizeof(bank));
    }
    File.close();
    remove("account.docx");
    rename("pqr.docx","account.docx");
    cout<<"-----record deleted-----";
  }
}

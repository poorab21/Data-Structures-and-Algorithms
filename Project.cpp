#include<iostream>
#include<stdlib.h>
#include"Calculator.cpp"
struct CustomerInfo{
	int Account_Number;
	std::string name;
	std::string gender;
	std::string Mobile_Number;
	int age;
	std::string CNIC;
	std::string Password;
	std::string Job_Description;
	float Balance;
	CustomerInfo *next;
	CustomerInfo *prev;
}*start=NULL,*last=NULL;
void InputData(CustomerInfo *z)
{
	static int x=1;
	std::cout<<"\t\tPlease Fill out the Following Requirements"<<std::endl;
	std::cout<<std::endl;
	std::cin.ignore();
	std::cout<<"Name = ";
	getline(std::cin,z->name);
	std::cout<<"Age = ";
	std::cin>>z->age;
	std::cin.ignore();
	std::cout<<"Gender = ";
	getline(std::cin,z->gender);
	std::cout<<"Job Description = ";
	getline(std::cin,z->Job_Description);
	std::cin.ignore();
	std::cout<<"Mobile Number = ";
	getline(std::cin,z->Mobile_Number);
	std::cout<<"CNIC = ";
	getline(std::cin,z->CNIC);
	std::cout<<"Enter Initial Balance for Account:"<<std::endl;
	std::cin>>z->Balance;
	z->Account_Number=x;
	std::cout<<std::endl;
	std::cout<<"Your Account has been Created and your Account Number is "<<x<<"\n";
	std::cout<<"Password for your Account = ";
	std::cin>>z->Password;
	x++;
}
void Create_Account()
{
	std::string choice;
	std::cout<<"Would you Like to Create Account:";
	std::cin>>choice;
	if(choice=="yes" || choice=="Yes")
	{
		if(start==NULL)
		{
			start=new CustomerInfo;
			InputData(start);
			start->prev=NULL;
			last=start;
		}
		else
		{
			last->next=new CustomerInfo;
			last->next->prev=last;
			last=last->next;
			InputData(last);
		}
		last->next=NULL;
	}
}
void Display_Info(CustomerInfo *z)
{
	std::cout<<std::endl;
	std::cout<<"________________________________________"<<std::endl;
	std::cout<<"      CURRENT ACCOUNT INFO              "<<std::endl;
	std::cout<<"________________________________________"<<std::endl;
	std::cout<<"Account Number = "<<z->Account_Number<<"\n";
	std::cout<<"Account Occupant = "<<z->name<<"\n";
	std::cout<<"Occupant's Gender = "<<z->gender<<"\n";
	std::cout<<"Occupant's Age = "<<z->age<<"\n";
	std::cout<<"Occupant's CNIC = "<<z->CNIC<<"\n";
	std::cout<<"Occupant's Job Description = "<<z->Job_Description<<"\n";
	std::cout<<"Occupant's Mobile Number = "<<z->Mobile_Number<<"\n";
	std::cout<<"Occupant's Balance = "<<z->Balance<<std::endl;
	std::cout<<"________________________________________"<<std::endl;
}
CustomerInfo* Search(int value)
{
	for(CustomerInfo *z=start;z != NULL;z=z->next)
	{
		if(z->Account_Number==value)
		{
			return z;
			break;
		}
	}
	return NULL;
}
void Individual_Info()
{
	int number;
	std::string verification;
	std::cout<<"Enter Your Account Number:";
	std::cin>>number;
	CustomerInfo *Account=Search(number);
	if(Account==NULL)
	{
		std::cout<<"Account not Found"<<std::endl;
	}
	else
	{
		std::cout<<"Enter Password for Verification:";
		std::cin>>verification;
		if(verification==Account->Password)
		{
			std::cout<<" _______________________________________"<<"\n";
			std::cout<<"          YOUR ACCOUNT INFORMATION      "<<"\n";
			std::cout<<"________________________________________"<<"\n";
			std::cout<<" ACCOUNT NUMBER = "<<Account->Account_Number<<std::endl;
			std::cout<<"________________________________________"<<"\n";
			std::cout<<" OCCUPANT NAME = "<<Account->name<<std::endl;
			std::cout<<"________________________________________"<<std::endl;
			std::cout<<" OCCUPANT AGE = "<<Account->age<<std::endl;
			std::cout<<"________________________________________"<<std::endl;
			std::cout<<" OCCUPANT GENDER = "<<Account->gender<<std::endl;
			std::cout<<"________________________________________"<<std::endl;
			std::cout<<" OCCUPANT CNIC = "<<Account->CNIC<<std::endl;
			std::cout<<"________________________________________"<<std::endl;
			std::cout<<" OCCUPANT JOB = "<<Account->Job_Description<<std::endl;
			std::cout<<"________________________________________"<<std::endl;
			std::cout<<" OCCUPANT CONTACT NUMBER = "<<Account->Mobile_Number<<std::endl;
			std::cout<<"________________________________________"<<std::endl;
			std::cout<<"OCCUPANT'S BALANCE = "<<Account->Balance<<std::endl;
		}
		else
		{
			std::cout<<"Password is Incorrect"<<std::endl;
		}
	}
}
void Change_Data(CustomerInfo *z)
{
	std::string data;
	std::cin.ignore();
	std::cout<<"What Would you like to Change:";
	getline(std::cin,data);
	if(data=="name" || data=="Name")
	{
		std::cin.ignore();
		std::cout<<"Enter New Name:";
		getline(std::cin,z->name);
		std::cout<<"Data Amendment Complete"<<std::endl;
	}
	else if(data=="Age" || data=="age")
	{
		std::cout<<"Enter Age:";
		std::cin>>z->age;
		std::cout<<"Data Amendment Complete"<<std::endl;
	}
	else if(data=="CNIC" || data=="cnic")
	{
		std::cout<<"Enter CNIC:";
		std::cin>>z->CNIC;
		std::cout<<"Data Amendment Complete"<<std::endl;
	}
	else if(data=="gender" || data=="Gender")
	{
		std::cout<<"Enter Gender:";
		std::cin>>z->gender;
		std::cout<<"Data Amendment Complete"<<std::endl;
	}
	else if(data.find("Mobile") != std::string::npos || data.find("mobile") != std::string::npos)
	{
		std::cout<<"Enter New Mobile Number:";
		std::cin>>z->Mobile_Number;
		std::cout<<"Data Amendment Complete"<<std::endl;
	}
	else if(data.find("Job") != std::string::npos || data.find("job") != std::string::npos)
	{
		std::cin.ignore();
		std::cout<<"Enter New Job Description:";
		getline(std::cin,z->Job_Description);
		std::cout<<"Data Amendment Complete"<<std::endl;
	}
	else if(data.find("password") != std::string::npos || data.find("Password") != std::string::npos)
	{
		std::cout<<"Assign new Password:";
		std::cin>>z->Password;
		std::cout<<"Data Amendment Complete"<<std::endl;
	}
}
void Append_Info()
{
	int number;
	std::string verification;
	std::cout<<"Enter your Assigned Account Number:";
	std::cin>>number;
	CustomerInfo *Account=Search(number);
	if(Account==NULL)
	{
		std::cout<<"Account is Non-Existent"<<std::endl;
	}
	else
	{
		std::cout<<"Enter Verification Password:";
		std::cin>>verification;
		if(verification==Account->Password)
		{
			Display_Info(Account);
			Change_Data(Account);
		}
		else
		{
			std::cout<<"Invalid Password"<<std::endl;
		}
	}
}
void DeleteAccount()
{
	int number;
	std::string verification;
	std::cout<<"Enter Account to Delete = ";
	std::cin>>number;
	CustomerInfo *Account=Search(number);
	if(Account==NULL)
	{
		std::cout<<"Account does not Exist"<<std::endl;
	}
	else
	{
		std::cout<<"Enter Verification Password:";
		std::cin>>verification;
		if(verification==Account->Password) 
		{
			if(Account==start && Account==last)
			{
				start=NULL;
				last=NULL;
			}
			else if(Account==start)
			{
				CustomerInfo *z=Account;
				start=start->next;
				start->prev=NULL;
				z->next=NULL;
				delete z;
			}
			else if(Account==last)
			{
				last=last->prev;
				last->next=NULL;
				delete Account;
			}
			else if(Account != start && Account != last)
			{
				Account->next->prev=Account->prev;
				Account->prev->next=Account->next;
				Account->next=NULL;
				Account->prev=NULL;
				delete Account;
			}
		}
		else
		{
			std::cout<<"Password is Invalid"<<std::endl;
		}
	}
}
void Display()
{
	for(CustomerInfo *z=start;z != NULL;z=z->next)
	{
		std::cout<<"Account Number = "<<z->Account_Number<<std::endl;
		std::cout<<"Owner Name = "<<z->name<<std::endl;
		std::cout<<"Owner Age = "<<z->age<<std::endl;
		std::cout<<"Owner Job = "<<z->Job_Description<<std::endl;
		std::cout<<"Owner Contact Number = "<<z->Mobile_Number<<std::endl;
		std::cout<<"Owner CNIC = "<<z->CNIC<<std::endl;
		std::cout<<"Owner Gender = "<<z->gender<<std::endl;
		std::cout<<"Owner Balance = "<<z->Balance<<std::endl;
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}
void Deposit_Money(int value)
{
	CustomerInfo *Account=Search(value);
	float increment;
	std::string verification;
	if(Account==NULL)
	{
		std::cout<<"No Account Found"<<std::endl;
	}
	else
	{
		std::cout<<"Enter Verification Password:";
		std::cin>>verification;
		if(verification==Account->Password)
		{
			std::cout<<"Enter Increment Amount:";
			std::cin>>increment;
			Account->Balance+=increment;
			std::cout<<"Money Successfully Deposited into Account"<<std::endl;
		}
		else
		{
			std::cout<<"Invalid Password"<<std::endl;
		}
	}
}
void Transfer(int value,int value2)
{
	float transfer_amount;
	std::string verification;
	CustomerInfo *Account=Search(value);
	CustomerInfo *Account2=Search(value2);
	if(Account==NULL && Account2 != NULL) 
	{
		std::cout<<"Your Account Number is Invalid"<<std::endl;
	}
	else if(Account != NULL && Account2==NULL)
	{
		std::cout<<"The Destination Account is Invalid"<<std::endl;
	}
	else if(Account==NULL && Account2==NULL)
	{
		std::cout<<"Your Account and the Destination Account are both Invalid"<<std::endl;
	}
	else if(Account != NULL && Account2 != NULL)
	{
		std::cout<<"Enter Verification Password for your Account:";
		std::cin>>verification;
		if(verification==Account->Password)
		{
			std::cout<<"Enter Amount you wish to Transfer:";
			std::cin>>transfer_amount;
			if(transfer_amount>Account->Balance)
			{
				std::cout<<"Transfer Amount Exceeds your Current Balance"<<"\n";
			}
			else if(transfer_amount<=Account->Balance)
			{
				Account->Balance-=transfer_amount;
				Account2->Balance+=transfer_amount;
				std::cout<<"Amount Successfully Transfered"<<std::endl;
			}
		}
		else
		{
			std::cout<<"Password is Invalid"<<std::endl;
		}
	}
}
void Money_Transaction()
{
	int choice,Source_Account,Destination_Account,number,withdraw_amount;
	std::cout<<"1.DEPOSIT MONEY TO PERSONAL ACCOUNT"<<std::endl;
	std::cout<<"2.TRANSFER MONEY TO ANOTHER ACCOUNT"<<std::endl;
	std::cout<<"3.CHECK BALANCE"<<std::endl;
	std::cout<<"4.WITHDRAW MONEY FROM ONE'S ACCOUNT"<<std::endl;
	std::cout<<"What Service would you like to be performed:";
	std::cin>>choice;
	if(choice==1)
	{
		std::cout<<"Enter Your Account Number:";
		std::cin>>number;
		Deposit_Money(number);
	}
	else if(choice==2)
	{
		std::cout<<"Enter Your Account Number:";
		std::cin>>Source_Account;
		std::cout<<"Enter Account Number to Transfer Money to:";
		std::cin>>Destination_Account;
		Transfer(Source_Account,Destination_Account);
	}
	else if(choice==3)
	{
		std::cout<<"Enter Your Account Number:";
		std::cin>>number;
		CustomerInfo *Account=Search(number);
		if(Account==NULL)
		{
			std::cout<<"Account does not Exist"<<std::endl;
		}
		else
		{
			std::cout<<"Your Current Balance is "<<"\n";
			std::cout<<Account->Balance<<std::endl;
		}
	}
	else if(choice==4)
	{
		std::cout<<"Enter Your Account Number:";
		std::cin>>number;
		CustomerInfo *Account=Search(number);
		if(Account==NULL)
		{
			std::cout<<"Account does not Exist"<<std::endl;
		}
		else
		{
			std::cout<<"Enter Amount to Withdraw:";
			std::cin>>withdraw_amount;
			if(withdraw_amount>Account->Balance)
			{
				std::cout<<"Withdraw Amount Exceeds your Current Balance"<<"\n";
			}
			else if(withdraw_amount<=Account->Balance)
			{
				Account->Balance-=withdraw_amount;
			}
		}
	}
}
void Accounts_Overview();
int top=-1;
int top2=-1;
char arr[20];
int stack[20];
void PUSH(int n)
{
	top2++;
	stack[top2]=n;
}
int POP()
{
	int value=stack[top2];
	top2--;
	return value;
}
void Push(char value)
{
	top++;
	arr[top]=value;
}
void Pop()
{
	arr[top]='\0';
	top--;
}
void PostFix_Conversion(std::string Infix,std::string& PostFix)
{
	for(int i=0;i<Infix.length();i++)
	{
		if(Infix[i]>=65 && Infix[i]<=90 || Infix[i]>=97 && Infix[i]<=122)
		{
			PostFix+=Infix[i];
		}
		else if(Infix[i]=='(')
		{
			Push(Infix[i]);
		}
		else if(Infix[i]==')')
		{
			while(arr[top] != '(')
			{
				PostFix+=arr[top];
				Pop();
			}
			Pop();
		}
		else if(Infix[i]=='/')
		{
			if(arr[top]=='*' || arr[top]=='/')
			{
				PostFix+=arr[top];
				Pop();
				Push('/');
			}
			else
			{
				Push('/');
			}
		}
		else if(Infix[i]=='*')
		{
			if(arr[top]=='/' || arr[top]=='*')
			{
				PostFix+=arr[top];
				Pop();
				Push('*');
			}
			else
			{
				Push('*');
			}
		}
		else if(Infix[i]=='+')
		{
			if(arr[top]=='-' || arr[top]=='+')
			{
				PostFix+=arr[top];
				Pop();
				Push('+');
			}
			else if(arr[top]=='(')
			{
				Push('+');
			}
			else
			{
				while(1)
				{
					if(arr[top]=='*' || arr[top]=='/')
					{
						PostFix+=arr[top];
						Pop();
					}
					else if(arr[top]=='-' || arr[top]=='+')
					{
						PostFix+=arr[top];
						Pop();
						Push('+');
						break;
					}
					else
					{
						Push('+');
						break;
					}
				}
			}
		}
		else if(Infix[i]=='-')
		{
			if(arr[top]=='+' || arr[top]=='-')
			{
				PostFix+=arr[top];
				Pop();
				Push('-');
			}
			else if(arr[top]=='(')
			{
				Push('-');
			}
			else
			{
				while(1)
				{
					if(arr[top]=='*' || arr[top]=='/')
					{
						PostFix+=arr[top];
						Pop();
					}
					else if(arr[top]=='+' || arr[top]=='-')
					{
						PostFix+=arr[top];
						Pop();
						Push('-');
						break;
					}
					else
					{
						Push('-');
						break;
					}
				}
			}
		}
	}
	while(top != -1)
	{
		PostFix+=arr[top];
		top--;
	}
}
int Function(int operand1,int operand2,char Operator)
{
	if(Operator=='+')
	{
		return operand1+operand2;
	}
	else if(Operator=='-')
	{
		return operand1-operand2;
	}
	else if(Operator=='/')
	{
		return operand1/operand2;
	}
	else if(Operator=='*')
	{
		return operand1*operand2;
	}
}
void Calculations()
{
	std::string Infix,PostFix;
	std::cout<<"Enter Expression:";
	std::cin>>Infix;
	PostFix_Conversion(Infix,PostFix);
	std::string value,postfix;
	for(int i=0;i<PostFix.length();i++)
	{
		if(PostFix[i]>=65 && PostFix[i]<=90 || PostFix[i]>=97 && PostFix[i]<=122)
		{
			std::cout<<"Enter Value for "<<PostFix[i]<<":";
			std::cin>>value;
			value+=" ";
			postfix+=value;
		}
		else
		{
			postfix+=PostFix[i];
		}
	}
	for(int i=0;i<postfix.length();i++)
	{
		if(postfix[i]>=48 && postfix[i]<=57)
		{
			if(postfix[i]=='0')
			{	
				PUSH(0);
			}
			else if(postfix[i]=='1')
			{
				PUSH(1);
			}
			else if(postfix[i]=='2')
			{
				PUSH(2);
			}
			else if(postfix[i]=='3')
			{
				PUSH(3);
			}
			else if(postfix[i]=='4')
			{
				PUSH(4);
			}
			else if(postfix[i]=='5')
			{
				PUSH(5);
			}
			else if(postfix[i]=='6')
			{
				PUSH(6);
			}
			else if(postfix[i]=='7')
			{
				PUSH(7);
			}
			else if(postfix[i]=='8')
			{
				PUSH(8);
			}
			else if(postfix[i]=='9')
			{
				PUSH(9);
			}
		}
		else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
		{
			int operand2=POP();
			int operand1=POP();
			PUSH(Function(operand1,operand2,postfix[i]));
		}
	}
	std::cout<<"Calculation = "<<stack[0]<<std::endl;
	top=-1,top2=-1;	
}
int main()
{
	system("cls");
	int choice;
	while(1)
	{
		std::cout<<"\t\t________________________________"<<std::endl;
		std::cout<<"\t\t|1.CREATE ACCOUNT               |"<<std::endl;
		std::cout<<"\t\t|-------------------------------|"<<std::endl;
		std::cout<<"\t\t|2.INDIVIDUAL ACCOUNT DISPLAY   |"<<std::endl;
		std::cout<<"\t\t|-------------------------------|"<<std::endl;
		std::cout<<"\t\t|3.APPEND ACCOUNT INFORMATION   |"<<std::endl;
		std::cout<<"\t\t|-------------------------------|"<<std::endl;
		std::cout<<"\t\t|4.DELETE ACCOUNT               |"<<std::endl;
		std::cout<<"\t\t|-------------------------------|"<<std::endl;
		std::cout<<"\t\t|5.MONEY TRANSACTION            |"<<std::endl;
		std::cout<<"\t\t|-------------------------------|"<<std::endl;
		std::cout<<"\t\t|6.ALL ACCOUNT OVERVIEW         |"<<std::endl;
		std::cout<<"\t\t|-------------------------------|"<<std::endl;
		std::cout<<"\t\t|7.SIMPLE CALCULATIONS          |"<<std::endl;
		std::cout<<"\t\t|-------------------------------|"<<std::endl;
		std::cout<<"\t\t|8.SCIENTIFIC CALCULATION       |"<<std::endl;
		std::cout<<"\t\t|-------------------------------|"<<std::endl;
		std::cout<<"\t\t|9.EXIT                         |"<<std::endl;
		std::cout<<"\t\t|_______________________________|"<<std::endl;
		std::cout<<"\t\tENTER YOUR CHOICE:";
		std::cin>>choice;
		switch(choice)
		{
			case 1:system("cls");
			Create_Account();
			break;
			case 2:system("cls");
			Individual_Info();
			break;
			case 3:system("cls");
			Append_Info();
			break;
			case 4:system("cls");
			DeleteAccount();
			break;
			case 5:system("cls");
				Money_Transaction();
				break;
			case 6:
				Accounts_Overview();
				break;
			case 7:
				Calculations();
				break;
			case 8:
				system("cls");
				Main();
				break;
			case 9:
				abort();
		}
	}
}
void Accounts_Overview()
{
	system("cls");
	int choice;
	CustomerInfo *z=start;
	if(z==NULL)
	{
		std::cout<<"No Accounts to Display"<<std::endl;
	}
	else
	{
		std::string verification;
		while(1)
		{
			system("cls");
			Display_Info(z);
			std::cout<<"1.DELETE THIS ACCOUNT"<<std::endl;
			std::cout<<"2.MOVE TO NEXT ACCOUNT"<<std::endl;
			std::cout<<"3.MOVE TO PREVIOUS ACCOUNT"<<std::endl;
			std::cout<<"4.EXIT TO MAIN MENU"<<std::endl;
			std::cin>>choice;
			if(choice==1)
			{
				std::cout<<"Enter Verification Code:";
				std::cin>>verification;
				if(verification==z->Password)
				{
					if(z != start && z != last)
					{
						CustomerInfo *temp=z;
						temp->prev->next=temp->next;
						temp->next->prev=temp->prev;
						z=z->next;
						temp->next=NULL;
						temp->prev=NULL;
						delete temp;
					}
					else if(z==start && z->next==NULL)
					{
						start=NULL;
						last=NULL;
						z=NULL;
						main();
					}
					else if(z==start && z->next != NULL)
					{
						CustomerInfo *temp=start;
						start=start->next;
						start->prev=NULL;
						z=start;
						temp->next=NULL;
						delete temp;
					}
					else if(z==last)
					{
						CustomerInfo *temp=last;
						last=last->prev;
						last->next=NULL;
						z=last;
						temp->prev=NULL;
						delete temp;
					}	
				}
			}
			else if(choice==2)
			{
				if(z->next != NULL)
				{
					z=z->next;
				}
				else
				{
					std::cout<<"No More Accounts to Show"<<std::endl;
				}
			}
			else if(choice==3)
			{
				if(z->prev != NULL)
				{
					z=z->prev;
				}
				else if(z->prev==NULL)
				{
					std::cout<<"No Account to show"<<std::endl;
				}
			}
			else if(choice==4)
			{
				main();
			}
		}
	}
}

#include<iostream>
#include<stdlib.h>
std::string arr[6]={" "," "," "," "," "," "};
std::string arr2[6]={" "," "," "," "," "," "};
std::string arr3[7]={" "," "," "," "," "," "," "};
std::string zero="",word="",wrong="";
static int confirm=0,x=0;
int head=0,hand1=0,hand2=0,leg1=0,leg2=0,abdomen1=0,abdomen2=0,wrong_count=0;
std::string guesswords[10]={"cherry","tiger","sandalwood","spiderman","india","kangaroo","magician","computer","chocolate","alcohol"};
std::string hint1="Fruit (Fleshy Drupe)";
std::string hint2="Belongs to the rose family";
std::string hint3="Light Pink in Color";
void hints()
{
	std::cout<<"\t\t\t\t\t\t____________________________________________"<<std::endl;
	std::cout<<"\t\t\t\t\t\t           HINTS                   "<<std::endl;
	std::cout<<"\t\t\t\t\t\t____________________________________________"<<std::endl;
	std::cout<<"\t\t\t\t\t\t1."<<hint1<<std::endl;
	std::cout<<"\t\t\t\t\t\t____________________________________________"<<std::endl;
	std::cout<<"\t\t\t\t\t\t2."<<hint2<<std::endl;
	std::cout<<"\t\t\t\t\t\t____________________________________________"<<std::endl;
	std::cout<<"\t\t\t\t\t\t3."<<hint3<<std::endl;
	std::cout<<"\t\t\t\t\t\t____________________________________________"<<std::endl;
}
void design()
{
	int count=30,count2=0,counter=0,length=0,length2=0,length3=0,increase=9;
	std::cout<<"                     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2       "<<std::endl;
	std::cout<<"                     \xB2         \xB2       "<<std::endl;
	std::cout<<"                     \xB2      "<<zero<<zero<<zero<<zero<<zero<<zero<<zero<<std::endl;
    std::cout<<"                     \xB2     "<<zero<<"       "<<zero<<std::endl;
    std::cout<<"                     \xB2     "<<zero<<"       "<<zero<<std::endl;
	std::cout<<"                     \xB2      "<<zero<<zero<<zero<<zero<<zero<<zero<<zero<<std::endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<count-increase;j++)
		{
			std::cout<<" ";
		}
		std::cout<<"\xB2";
		increase--;
		for(int j=0;j<(increase);j++)
		{
			std::cout<<" ";
		}
		std::cout<<arr[length];
		length++;
		for(int k=0;k<=count2;k++)
		{
			if(k==counter)
			{
			std::cout<<arr2[length2];
			length2++;
			}
			else
			{
				std::cout<<" ";
			}
		}
		
		std::cout<<arr3[length3]<<std::endl;
		length3++;
		count2+=2;
		count-=1;
		counter++;
	}
	count=30;
	increase=9;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<count-increase;j++)
		{
			std::cout<<" ";
		}
		std::cout<<"\xB2";
		for(int j=0;j<increase;j++)
		{
			std::cout<<" ";
		}
		std::cout<<arr2[length2]<<std::endl;
		length2++;
	}
	count=30;
	count2=0;
	counter=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<count-increase;j++)
		{
			std::cout<<" ";
		}
		std::cout<<"\xB2";
		increase--;
		for(int j=0;j<increase;j++)
		{
			std::cout<<" ";
		}
		std::cout<<arr[length];
		length++;
		for(int k=0;k<=count2;k++)
		{
			std::cout<<" ";
		}
		std::cout<<arr3[length3]<<std::endl;
		length3++;
		count2+=2;
		count-=1;
		counter++;
	}
}
void guess()
{
	hints();
	std::cout<<std::endl;
	std::cout<<std::endl;
	if(confirm==0)
	{
		for(int i=0;i<guesswords[x].length();i++)
		{
		word+="_";
		}
		confirm++;	
	}
	std::cout.width(20);
	for(int i=0;i<word.length();i++)
	{
		std::cout<<word[i]<<" ";
	}
	std::cout<<std::endl<<std::endl;
	std::cout.width(33);
	std::cout<<"Wrong Guess = ";
	for(int i=0;i<wrong.length();i++)
	{
		if(wrong.length()>1)
		{
			if(i==0)
			{
				std::cout<<wrong[i];
			}
			else if(i>0)
			{
				std::cout<<" , "<<wrong[i];
			}
		}
		else if(wrong.length()==1)
		{
			std::cout<<wrong[i];
		}
	}
}
void guess_result()
{
	std::string guessword;
	int count=0,breaker=0,certain=0,certain2=0;
	std::cout<<std::endl;
	std::cout<<"Enter Guess(One letter):"<<std::endl;
	std::cin>>guessword;
	if(guessword.length()>1)
	{
		wrong_count++;
		certain=1;
	if(wrong_count==1)
		{
			head=1;
		}
		else if(wrong_count==2)
		{
			abdomen1=1;
		}
		else if(wrong_count==3)
		{
			abdomen2=1;
		}
		else if(wrong_count==4)
		{
			hand1=1;
		}
		else if(wrong_count==5)
		{
			hand2=1;
		}
		else if(wrong_count==6)
		{
			leg1=1;
		}
		else if(wrong_count==7)
		{
			leg2=1;
		}
	if(head==1)
	{
	zero="\xB2";
	}
	if(hand1==1)
	{
		for(int i=0;i<3;i++)
		{
			arr[i]="/";
		}
	}
	if(hand2==1)
	{
		for(int i=0;i<3;i++)
		{
			arr3[i]="\\";
		}
	}
	if(leg1==1)
	{
		for(int i=3;i<6;i++)
		{
			arr[i]="/";
		}
	}
	if(leg2==1)
	{
		for(int i=3;i<6;i++)
		{
			arr3[i]="\\";
		}
	}
	if(abdomen1==1)
	{
		for(int i=0;i<3;i++)
		{
			arr2[i]="|";
		}
	}
	if(abdomen2==1)
	{
		for(int i=3;i<6;i++)
		{
			arr2[i]="|";
		}
	}
	}
	if(certain==0)
	{
	for(int i=0;i<word.length();i++)
	{
		if(word[i]==guessword[0])
		{
			wrong_count++;
			certain2=1;
			if(wrong_count==1)
		{
			head=1;
		}
		else if(wrong_count==2)
		{
			abdomen1=1;
		}
		else if(wrong_count==3)
		{
			abdomen2=1;
		}
		else if(wrong_count==4)
		{
			hand1=1;
		}
		else if(wrong_count==5)
		{
			hand2=1;
		}
		else if(wrong_count==6)
		{
			leg1=1;
		}
		else if(wrong_count==7)
		{
			leg2=1;
		}
			break;
		}
	}
	if(certain2==0)
	{
	for(int i=0;i<guesswords[x].length();i++)
	{
		if(guessword[0]==guesswords[x][i])
		{
			word[i]=guessword[0];
			count++;
		}
	}
	if(count==0)
	{
		wrong_count++;
		for(int i=0;i<wrong.length();i++)
		{
			if(wrong[i]==guessword[0])
			{
				breaker=1;
			}
		}
		if(breaker==0)
		{
			wrong+=guessword[0];
		}
		if(wrong_count==1)
		{
			head=1;
		}
		else if(wrong_count==2)
		{
			abdomen1=1;
		}
		else if(wrong_count==3)
		{
			abdomen2=1;
		}
		else if(wrong_count==4)
		{
			hand1=1;
		}
		else if(wrong_count==5)
		{
			hand2=1;
		}
		else if(wrong_count==6)
		{
			leg1=1;
		}
		else if(wrong_count==7)
		{
			leg2=1;
		}
	}	
}
	if(head==1)
	{
		zero="\xB2";
	}
	if(hand1==1)
	{
		for(int i=0;i<3;i++)
		{
			arr[i]="/";
		}
	}
	if(hand2==1)
	{
		for(int i=0;i<3;i++)
		{
			arr3[i]="\\";
		}
	}
	if(leg1==1)
	{
		for(int i=3;i<6;i++)
		{
			arr[i]="/";
		}
	}
	if(leg2==1)
	{
		for(int i=3;i<6;i++)
		{
			arr3[i]="\\";
		}
	}
	if(abdomen1==1)
	{
		for(int i=0;i<3;i++)
		{
			arr2[i]="|";
		}
	}
	if(abdomen2==1)
	{
		for(int i=3;i<6;i++)
		{
			arr2[i]="|";
		}
	}	
	}
}
void result()
{
	if(head==1 && hand1==1 && hand2==1 && leg1==1 && leg2==1 && abdomen1==1 && abdomen2==1)
	{
		system("cls");
		design();
		int choice;
		std::cout<<"You Could Not Guess the Word Correctly within time"<<std::endl;
		std::cout<<std::endl;
		std::cout<<std::endl;
		if(x<9)
		{
		std::cout<<"Would you like to retry(1) OR go to next level(2) OR exit(3):"<<std::endl;
		std::cin>>choice;
		if(choice==1)
		{
			x+=0;
		}
		else if(choice==2)
		{
			x++;
		}
		else if(choice==3)
		{
			exit(0);
		}
		}
		else if(x==9)
		{
			std::cout<<"No more Levels"<<std::endl;
			exit(0);
		}
		head=0;
		hand1=0;
		hand2=0;
		leg1=0;
		leg2=0;
		abdomen1=0;
		abdomen2=0;
		word.clear();
		wrong.clear();
		confirm=0;
		wrong_count=0;
		zero="";
		for(int i=0;i<=6;i++)
		{
			arr[i]=" ";
		}
		for(int i=0;i<=6;i++)
		{
			arr2[i]=" ";
		}
		for(int i=0;i<=7;i++)
		{
			arr3[i]=" ";
		}
	}
	else if(word==guesswords[x])
	{
		system("cls");
		design();
		guess();
		int choice;
		std::cout<<std::endl;
		std::cout<<"You Guessed the Word Correctly within time"<<std::endl;
		std::cout<<std::endl;
		std::cout<<std::endl;
		if(x<9)
		{
		std::cout<<"Would you like to redo(1) OR go to next level(2) OR exit(3):"<<std::endl;
		std::cin>>choice;
		if(choice==1)
		{
			x+=0;
		}
		else if(choice==2)
		{
			x++;
		}
		else if(choice==3)
		{
		exit(0);	
		}	
		}
		else if(x==9)
		{
			std::cout<<"No more Levels"<<std::endl;
			exit(0);
		}
		head=0;
		hand1=0;
		hand2=0;
		leg1=0;
		leg2=0;
		abdomen1=0;
		abdomen2=0;
		word.clear();
		wrong.clear();
		confirm=0;
		wrong_count=0;
		zero="";
		for(int i=0;i<=6;i++)
		{
			arr[i]=" ";
		}
		for(int i=0;i<=6;i++)
		{
			arr2[i]=" ";
		}
		for(int i=0;i<=7;i++)
		{
			arr3[i]=" ";
		
	}
	}
	if(x==1)
			{
				hint1="Biggest Species(Cat Family)";
				hint2="Has Dark Stripes";
				hint3="Apex Predator";
			}
			else if(x==2)
			{
				hint1="it is a Class of Wood";
				hint2="is Semi-Parasite";
				hint3="Can Survive 80 Years in Nature";
			}
			else if(x==3)
			{
				hint1="Famous Superhero";
				hint2="Associated with Stan Lee";
				hint3="First Appeared in 1962";
			}
			else if(x==4)
			{
				hint1="largest producer of milk(Country)";
				hint2="First Country to Consume Sugar";
				hint3="Originated Snakes and Ladders(game)";
			}
			else if(x==5)
			{
				hint1="Marsupial Animals";
				hint2="Strict Herbivores";
				hint3="Famously Found in Australia";
			}
			else if(x==6)
			{
				hint1="a conjuror";
				hint2="Performs Tricks";
				hint3="Uses Deception";
			}
			else if(x==7)
			{
				hint1="Electronic Device";
				hint2="Invented Between 1833 and 1871";
				hint3="Used to look like an Oversized Calculator";
			}
			else if(x==8)
			{
				hint1="reduces cholesterol";
				hint2="Can Improve Blood Flow";
				hint3="popular sweet treat";
			}
			else if(x==9)
			{
				hint1="Contains Ethanol";
				hint2="Acts as a Depressant";
				hint3="Can Slow the Heart Rate";
			}
}
int main()
{
	while(x<10)
	{
	system("cls");
	design();
	guess();
	guess_result();
	result();
	} 
}

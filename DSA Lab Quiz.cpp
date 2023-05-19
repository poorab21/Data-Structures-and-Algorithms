#include<iostream>
int *isbn;
std::string *booktitle;
int *bookprices;
int *createBookIsbn(int size)
{
	int *arr=new int[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=0;
	}
	return arr;
}
std::string* createBookTitles(int size)
{
	std::string *arr=new std::string[size];
	for(int i=0;i<size;i++)
	{
		arr[i]="No Book Available";
	}
	return arr;
}
int* createBookPrices(int size)
{
	int *arr=new int[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=0;
	}
	return arr;
}
void Insertion(int a,std::string b,int c)
{
	static int x=0;
	if(x==10)
	{
	std::cout<<"Shelf is Full"<<std::endl;	
	}
	else
	{
	int index;
	std::cout<<"Enter Index to Insert in:"<<std::endl;
	std::cin>>index;
	isbn[index]=a;
	booktitle[index]=b;
	bookprices[index]=c;
	x++;
	}
}
void Deletion(int a,int &size)
{
	if(size != 0)
	{
	for(int i=0;i<size;i++)
	{
		if(a==isbn[i])
		{
			for(int j=i;j<(size)-1;j++)
			{
				isbn[j]=isbn[j+1];
				booktitle[j]=booktitle[j+1];
				bookprices[j]=bookprices[j+1];
			}
			size--;
			break;
		}
		else if(a != isbn[i] && i==size-1)
		{
			std::cout<<"Not Found"<<std::endl;
		}
	}
}
	else
	{
		std::cout<<"Book Shelf Empty"<<std::endl;
	}
	}
int main()
{
	char ch='y';
	int a,c;
	std::string b;
	int size=10;
	isbn=createBookIsbn(10);
	booktitle=createBookTitles(10);
	bookprices=createBookPrices(10);
	while(ch=='y')
	{
		std::cout<<"Would you like to Insert Data:";
		std::cin>>ch;
		if(ch=='y')
		{
		system("cls");
		for(int i=0;i<10;i++)
		{
			std::cout<<i+1<<")  "<<isbn[i]<<"   "<<booktitle[i]<<"   "<<bookprices[i]<<"\n";
		}
		std::cout<<"Enter ISBN:";
		std::cin>>a;
		std::cin.ignore();
		std::cout<<"Enter Book:";
		getline(std::cin,b);
		std::cout<<"Enter Price:";
		std::cin>>c;
		Insertion(a,b,c);
		}
	}
	ch='y';
	while(ch=='y')
	{
		for(int i=0;i<size;i++)
		{
			std::cout<<i+1<<")  "<<isbn[i]<<"   "<<booktitle[i]<<"   "<<bookprices[i]<<"\n";
		}
		std::cout<<"Would you like to Delete Data:";
		std::cin>>ch;
		if(ch=='y')
		{
		std::cout<<"Enter ISBN:";
		std::cin>>a;
		Deletion(a,size);
		}
	}
	delete[] isbn;
	delete[] booktitle;
	delete[] bookprices;
}

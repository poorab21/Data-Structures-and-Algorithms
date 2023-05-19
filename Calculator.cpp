#include<iostream>
#include<string>
#include<math.h>
std::string content;
std::string choice,function,arr2[100];
int count=0,counter=0;
float arr1[100],number;
void calculator()
{
	std::cout<<"_____________________________"<<"\n";
   std::cout<<"|                             |"<<"\n";
   std::cout<<"|"<<content<<"                             |"<<"\n";
   std::cout<<"|_____________________________|"<<"\n";
   std::cout<<"|     |     |     |     |     |"<<"\n";
   std::cout<<"|  +  |  /  |  -  |  x  |  %  |"<<"\n";
   std::cout<<"|-----------------------------|"<<"\n";
   std::cout<<"|     |     |     |     |     |"<<"\n";
   std::cout<<"|SIN  |COS  |TAN  |Sqrt |Cbrt |"<<"\n";
   std::cout<<"|-----------------------------|"<<"\n";
   std::cout<<"|     |     |     |     |     |"<<"\n";
   std::cout<<"|CEIL |FLOOR|ROUND|POWER|LOG  |"<<"\n";
   std::cout<<"|-----------------------------|"<<"\n";
   std::cout<<"|     |     |     |     |     |"<<"\n";
   std::cout<<"|SINH |COSH |TANH | CLR |  =  |"<<"\n";
   std::cout<<"|_____________________________|"<<"\n";
   std::cout<<"\n\n";
}
int Main()
{
   while(1)
   {
   	std::cout<<"Number OR Function OR Exit(1):"<<std::endl;
   	std::cin>>choice;
   	if(choice=="number" || choice=="Number")
   	{
   		std::cout<<"Enter Number:";
   		std::cin>>number;
   		arr1[count]=number;
   		count++;
   	    content+=std::to_string(number);
	}
	else if(choice=="1")
	{
		count=0,counter=0;
		content="";
		return 0;
	}
	else if(choice=="function" || choice=="Function")
	{
	    std::cout<<"Enter Function:";
	    std::cin>>function;
	    if(function=="+")
	    {
	        content+="+";
	        arr2[counter]="+";
	        counter++;
	    }
	    else if(function=="-")
	    {
	        content+="-";
	        arr2[counter]="-";
	        counter++;
	    }
	    else if(function=="/")
	    {
	        content+="/";
	        arr2[counter]="/";
	        counter++;
	    }
	    else if(function=="power")
	    {
	        int power;
	        float n1;
	        std::cout<<"Enter Power value:";
	        std::cin>>power;
	        n1=pow(arr1[count-1],power);
	        for(int i=content.length()-1;i>=0;i--)
	        {
	            if(content[i]=='x' || content[i]=='+' || content[i]=='-' || content[i]=='/')
	            {
	                break;
	            }
	            content.resize(content.length()-1);
	        }
	        content+=std::to_string(n1);
	        arr1[count-1]=n1;
	    }
	    else if(function=="x")
	    {
	        content+="x";
	        arr2[counter]="x";
	        counter++;
	    }
	    else if(function=="sin")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=sin(num);
	        count++;
	        content+=std::to_string(sin(num));
	    }
	    else if(function=="cos")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=cos(num);
	        count++;
	        content+=std::to_string(cos(num));
	    }
	    else if(function=="tan")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=tan(num);
	        count++;
	        content+=std::to_string(tan(num));
	    }
	    else if(function=="sinh")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=sinh(num);
	        count++;
	        content+=std::to_string(sinh(num));
	    }
	    else if(function=="cosh")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=cosh(num);
	        count++;
	        content+=std::to_string(cosh(num));
	    }
	    else if(function=="tanh")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=tanh(num);
	        count++;
	        content+=std::to_string(tanh(num));
	    }
	    else if(function=="sqrt")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=sqrt(num);
	        count++;
	        content+=std::to_string(sqrt(num));
	    }
	    else if(function=="cbrt")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=cbrt(num);
	        count++;
	        content+=std::to_string(cbrt(num));
	    }
	    else if(function=="round")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=round(num);
	        count++;
	        content+=std::to_string(round(num));
	    }
	    else if(function=="ceil")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=ceil(num);
	        count++;
	        content+=std::to_string(ceil(num));
	    }
	    else if(function=="floor")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=floor(num);
	        count++;
	        content+=std::to_string(floor(num));
	    }
	    else if(function=="CLR")
	    {
	      content="";
	      count=0;
	      counter=0;
	    }
	    else if(function=="log")
	    {
	        float num;
	        std::cout<<"Enter Value:";
	        std::cin>>num;
	        arr1[count]=log(num);
	        count++;
	        content+=std::to_string(log(num));
	    }
	    else if(function=="%")
	    {
	        float value,answer;
	        std::cout<<"Enter Value:";
	        std::cin>>value;
	        answer=fmod(arr1[count-1],value);
	        for(int i=content.length()-1;i>=0;i--)
	        {
	            if(content[i]=='+' || content[i]=='-' || content[i]=='/' || content[i]=='x')
	            {
	                break;
	            }
	            content.resize(content.length()-1);
	        }
	        content+=std::to_string(answer);
	        arr1[count-1]=answer;
	    }
	    else if(function=="=")
	    {
	        float answer;
	        int n=1;
	        answer=arr1[0];
	        for(int i=0;i<counter;i++)
	        {
	            if(arr2[i]=="+")
	            {
	                answer+=arr1[n];
	            }
	            else if(arr2[i]=="-")
	            {
	                answer-=arr1[n];
	            }
	            else if(arr2[i]=="/")
	            {
	                answer/=arr1[n];
	            }
	            else if(arr2[i]=="x")
	            {
	                answer*=arr1[n];
	            }
	            n++;
	        }
	        content=std::to_string(answer);
	        count=0;
	        counter=0;
	        arr1[count]=answer;
	        count++;
	    }
	}
	if(count==0 && counter==0)
	{
	calculator();
	}
	else 
	{
	    calculator();
	}
   }
}

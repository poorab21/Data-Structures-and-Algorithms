#include<iostream>
int main()
{
	std::string s,input;
	int i=0,j=0,increase=0,breaker=0;
	std::string sub;
	std::cout<<"Enter String:";
	getline(std::cin,s);
	std::cout<<"Enter Pattern:";
	getline(std::cin,input);
	while(i<s.length())
	{
		if(s[i]==input[j])
		{
			if(j==input.length()-1)
			{
				std::cout<<"Found at Index "<<i-j<<std::endl;
				i-=j-1;
				j=0;
			}
			else
			{
				i++;
				j++;
			}
		}
		else if(s[i] != input[j])
		{
			for(int k=(i-j)+1;k<=i;k++)
			{
				increase=0;
				for(int counter=k;counter<=i;counter++)
				{
					sub[increase]=s[counter];
					increase++;
				}
	for(int counter=0;counter<increase;counter++)
				{
	             if(sub[counter]==input[counter] && counter==increase-1)
					{
						j=increase;
						breaker=1;
						break;
					}
	else if(sub[counter] != input[counter])
	            {
	            	j=0;
	            	break;
				}	
				}
				if(breaker==1)
				{
					breaker=0;
					break;
				}
	        }
	        i++;
		}
	}
}

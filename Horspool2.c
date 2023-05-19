#include<stdio.h>
int length(char *s)
{
	int i,count=0;
	for(i=0;s[i] != '\0';i++)
	{
		count++;
	}
	return count-1;
}
int main()
{
	char s[50],search[20],alphabets[26];
	int i,j,count=0,others,alphabetCount[10],counter=0,certain=0;
	int sub,decrease=0,location,determine=0,determine2=0;
	printf("Enter String:");
	fgets(s,100,stdin);
	printf("Enter Substring to Search:");
	fgets(search,100,stdin);	
	for(i=0;i<length(search);i++)
	{
		for(j=-1;j<i;j++)
		{
			if(search[i]==search[j])
			{
				break;
			}
			else if(search[i] != search[j] && j==i-1)
			{
				alphabets[count]=search[i];
				count++;
			}
		}
	}
	others=length(search);
	for(i=0;i<length(alphabets)+1;i++)
	{
		for(j=0;j<length(search);j++)
		{
			if(alphabets[i]==search[j] && j<length(search)-1)
			{
				alphabetCount[counter]=length(search)-1-j;
				certain=1;
			}
			else if(alphabets[i]==search[j] && j==length(search)-1 && certain==1)
			{
				break;
			}
			else if(alphabets[i]==search[j] && j==length(search)-1 && certain==0)
			{
				alphabetCount[counter]=length(search);
			}
		}
		certain=0;
		counter++;
	}
	sub=length(search)-1;
	location=length(search)-1;
	while(1)
	{
		if(search[sub]==s[location])
		{
			for(i=sub;i>=0;i--)
			{
				if(search[i]==s[location-decrease])
				{
					determine++;
					decrease++;
				}
				else if(search[i] != s[location-decrease])
				{
					for(i=0;i<length(alphabets)+1;i++)
					{
						if(s[location]==alphabets[i])
						{
							location+=alphabetCount[i];
							break;
						}
						else if(s[location] != alphabets[i] && i==length(alphabets))
						{
							location+=others;
						}
					}
					decrease=0;
					determine=0;
					break;
				}
			}
			if(determine==length(search))
			{
				printf("Word Found at Index %d\n",location-(length(search))+1);
				determine2=1;
			}
		}
		else if(search[sub] != s[location] && location<length(s))
		{
			for(i=0;i<length(alphabets)+1;i++)
					{
						if(s[location]==alphabets[i])
						{
							location+=alphabetCount[i];
							break;
						}
						else if(s[location] != alphabets[i] && i==length(alphabets))
						{
							location+=others;
						}
					}
		}
		else
		{
			if(determine2==0)
			{
				printf("Word Not Found");
			}
			break;
		}
	} 
}

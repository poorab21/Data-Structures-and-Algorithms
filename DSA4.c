#include<stdio.h>
int length(char *s)
{
	int i=0,count=0;
	for(i=0;s[i] != '\0';i++)
	{
		count++;
	}
	return count-1;
}
int index(char *s,char *s1)
{
	int i=0,j=0,count=0;
	for(i=0;i<length(s);i++)
	{
		if(s1[0]==s[i])
		{
			for(j=i;j<(i+length(s1));j++)
			{
				if(s[j]==s1[count])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			if(count==length(s1))
			{
				return i;
			}
			count=0;
		}
	}
	return -1;
}
int main()
{
	char s[100],s1[100];
	printf("Enter String:");
	fgets(s,100,stdin);
	printf("Enter Substring to Find:");
	fgets(s1,100,stdin);
	if(index(s,s1)==-1)
	{
		printf("Not Found");
	}
	else
	{
		printf("Found at %d Index",index(s,s1));
	}
}

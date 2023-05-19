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
int main()
{
	char s[100];
	printf("Enter String:");
	fgets(s,100,stdin);
	printf("Length = %d",length(s));
}

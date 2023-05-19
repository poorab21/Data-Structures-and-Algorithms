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
void concat(char *s1,char *s2)
{
	int i=0,count=0;
	char s[length(s1)+length(s2)+1];
	for(i=0;i<length(s1);i++)
	{
		s[count]=s1[i];
		count++;
	}
	s[count]=32;
	count++;
	for(i=0;i<length(s2);i++)
	{
		s[count]=s2[i];
		count++;
	}
	for(i=0;i<count;i++)
	{
		printf("%c",s[i]);
	}
}
int main()
{
	char s[100],s2[100];
	printf("Enter String:");
	fgets(s,100,stdin);
	printf("Enter String:");
	fgets(s2,100,stdin);
	printf("Concatenated Form = ");
	concat(s,s2);
}

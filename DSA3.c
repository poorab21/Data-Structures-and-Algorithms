#include<stdio.h>
void substr(char *s,int position,int length)
{
	char s1[length+1];
	int i=0,count=0;
	for(i=position;i<(position+length);i++)
	{
		s1[count]=s[i];
		count++;
	}
	for(i=0;i<count;i++)
	{
		printf("%c",s1[i]);
	}
}
int main()
{
	char s[50];
	int length,position;
	printf("Enter String:");
	fgets(s,50,stdin);
	printf("Enter Position:");
	scanf("%d",&position);
	printf("Enter Length:");
	scanf("%d",&length);
	substr(s,position,length);
}

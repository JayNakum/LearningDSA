#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,len;
	char a[20];
	printf("enter the desired string : ");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		n++;
	}
	for(i=n;i>=0;i--)
	{
		printf("%c",a[i]);
	}
	

	return 0;
}

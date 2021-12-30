#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i;
	char a[20];
	printf("enter the desired string : ");
	gets(a);

	
	for(i=0;a[i]!='\0';i++)
	{
		n++;
	}
	printf("The number of charachter in the strings are %d",n);
	return 0;
}

#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int i,j;
	char a[20],b[20],c[40];
	printf("enter the desired string : ");
	gets(a);
	
	printf("\nenter the second desired string : ");
	gets(b);
	for(i=0;a[i]!='\0';i++)
	{
		c[j]=a[i];
		j++;
	}
	
	
	
	
	for(i=0;b[i]!='\0';i++)
	{
		c[j]=b[i];
		j++;
	}
	c[j]='\0';
	puts(c);


	return 0;
}

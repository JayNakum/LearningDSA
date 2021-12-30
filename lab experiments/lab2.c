#include<stdio.h>
#include<conio.h>
#define size 20

int top=-1;
char stack[size];

char push(char ch)
{
    if(top==(size-1))
        printf("stack overflow");
    else
        stack[++top]=ch;
}

char pop()
{
    if(top==-1)
        printf("stack underflow");
    else
        return stack[top--];
}
void main()
{
    char str[20];
    int i;
    printf("Enter string \n");
    scanf("%s",&str);
    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    for(i=0;i<strlen(str);i++)
    {
        str[i]=pop();
    }
    printf("reverse string:");
    puts(str);
}

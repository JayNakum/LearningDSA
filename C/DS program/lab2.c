/* Write a c program to reverse a string using stack. */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

int top = -1;
char stack[MAX];
char pop();
void push(char);

int main(){
        char str[20];
        unsigned int i;
        printf("Enter the string : " );
        gets(str);
        for(i=0;i<strlen(str);i++)
                push(str[i]);
        for(i=0;i<strlen(str);i++)
                str[i]=pop();
        printf("\nReversed string is : ");
        puts(str);
        return 0;
}

void push(char item){
        if(top == (MAX-1)){
                printf("\nStack Overflow\n");
                return;
        }
        stack[++top] =item;
}

char pop(){
        if(top == -1){
                printf("\nStack Underflow\n");
                exit(1);
        }
        return stack[top--];
}
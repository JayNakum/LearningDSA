#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>  
#include<string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char input)
{
    if(top>=SIZE-1)
    {
        printf("\n Stack overflow...");
    }

    else
    {
        top = top + 1;
        stack[top] = input;
    }
}

char pop()
{
    char input ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		input = stack[top];
		top = top-1;
		return(input);
	}

}

int is_operator(char symbol)
{
	if(symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
		return 1;
	else
		return 0;
	
}

int precedence(char symbol)
{
    if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void Infix_to_Postfix(char infix_exp[], char postfix_exp[])
{
    int i,j;
    char input;
    char x;

    push('#');
    strcat(infix_exp,"#");

    i=0, j=0;
    input = infix_exp[i];

    while(input != '\0')
    {
        if(isdigit(input) || isalpha(input))
        {
            postfix_exp[j] = input;
            j++;
        }

        else if (is_operator(input) == 1)
        {
            x=pop();

            while(is_operator(x) == 1 && precedence(x) >= precedence(input))
            {
                postfix_exp[j] = x;
                j++;
                x=pop();
            }

            push(x);

            push(input);
        }

        else if(input == '#')
        {
            x = pop();                   
			while(x != '#')                
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
        }
        else
		{ 
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
        i++;

        input = infix_exp[i];
    }

    if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}

    postfix_exp[j] = '\0';
}

int main()
{
    char infix[SIZE], postfix[SIZE];

    printf("\n Enter Infix Expression: ");
    gets(infix);

    Infix_to_Postfix(infix,postfix);

    printf("\n Postfix Expression: ");
    puts(postfix);

    return 0;
}
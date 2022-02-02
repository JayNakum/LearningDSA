
#include <stdio.h>
#define MAXSIZE 5
 
struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;
 
void push(void);
int  pop(void);
void display(void); 
void search(void);
void update(void);
 
void main ()
{
    int choice;
    int option = 1;
    s.top = -1;
    printf ("STACK OPERATION\n");
    while (option)
    {
        printf ("------------------------------------------\n");
        printf ("      1           PUSH               \n");
        printf ("      2           POP               \n");
        printf ("      3           DISPLAY               \n");
        printf ("      4           SEARCH               \n");
        printf ("      5           UPDATE               \n");
        printf ("      6           EXIT           \n");
        printf ("------------------------------------------\n");
 
        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
			search();
			break;   
		case 5:
			update(); 
			break;
        case 6:
            return;
        }
        fflush (stdin);

    }
}
/*  Function to add an element to the stack */
void push ()
{
    int num;
    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}
/*  Function to delete an element from the stack */
int pop ()
{
    int num;
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf ("poped element is = %dn", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}
/*  Function to display the status of the stack */
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}

/*  Function to search the index of the stack */
void search ()
{
    int a;
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n Enter the search element \n");
        scanf("\n%d",&a);
         
        for (i = s.top; i >= 0; i--)
        {
        	if(a == s.stk[i] )
        	{
        		printf("\nYour searched element is at index %d",i);
			}
            
        }
    }
    printf ("\n");
}



/*  Function to search the index of the stack */
void update ()
{
    int a,n;
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n Enter the number for updation \n");
        scanf("\n%d",&a);

		printf ("\n Enter the new number for updation \n");
        scanf("\n%d",&n);        
        
        	if(a == s.stk[i] )
        	{
        		s.stk[i] = n;
			}
            else
            {
            	printf("Enter the correct element");
			}
    }
    printf ("\n");
}


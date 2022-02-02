#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void traverse();
void insertFirst();
void insertLast();
void insertMid();
void deleteFirst();
void deleteLast();
void deleteMid();

void main()
{
    printf("Singly Linked List\n");
    int choice = 1;
    while (choice != 0)
    {
        printf("\n\nOperations available:\n");
        printf("0 -> Exit\n");
        printf("1 -> Traverse\n");
        printf("2 -> Insert at beginning\n");
        printf("3 -> Insert at end\n");
        printf("4 -> Insert at a particular position\n");
        printf("5 -> Delete at beginning\n");
        printf("6 -> Delete at end\n");
        printf("7 -> Delete at a particular position\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 2:
            insertFirst();
            break;
        case 3:
            insertLast();
            break;
        case 4:
            insertMid();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteLast();
            break;
        case 7:
            deleteMid();
            break;
        default:
            printf("Invalid choice :/");
            break;
        }
    }
}

void traverse()  
{  
    struct node *node;  
    node = head;   
    if(node == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nPrinting values:\n");   
        while (node!=NULL)  
        {  
            printf("\t%d",node->data);  
            node = node -> next;  
        }  
    }  
}     

void insertFirst()
{
    struct node *node;
    int data;
    node = (struct node *)malloc(sizeof(struct node *));
    if (node == NULL)
    {
        printf("\nOVERFLOW :(");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &data);
        node->data = data;
        node->next = head;
        head = node;
        printf("\nNode inserted!");
    }
}

void insertLast()  
{  
    struct node *node,*temp;  
    int data;     
    node = (struct node*)malloc(sizeof(struct node));      
    if(node == NULL)  
    {  
        printf("\nOVERFLOW :(");     
    }  
    else  
    {  
        printf("\nEnter value: ");  
        scanf("%d",&data);  
        node->data = data;  
        if(head == NULL)  
        {  
            node -> next = NULL;  
            head = node;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = node;  
            node->next = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}

void insertMid()  
{  
    int i,position,data;   
    struct node *node, *temp;  
    node = (struct node *) malloc (sizeof(struct node));  
    if(node == NULL)  
    {  
        printf("\nOVERFLOW :(");  
    }  
    else
    {  
        printf("\nEnter element value: ");  
        scanf("%d",&data);  
        node->data = data;  
        printf("\nEnter the location after which you want to insert: ");  
        scanf("\n%d",&position);  
        temp=head;  
        for(i=0;i<position;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\nsomething went wrong :( \nCan't insert\n");  
                return;  
            }  
          
        }  
        node ->next = temp ->next;   
        temp ->next = node;   
        printf("\nNode inserted!");  
    }  
}

void deleteFirst()  
{  
    struct node *node;  
    if(head == NULL)  
    {  
        printf("\nList is empty :(\n");  
    }  
    else   
    {  
        node = head;  
        head = node->next;  
        free(node);  
        printf("\nNode deleted from the begining\n");  
    }  
}

void deleteLast()  
{  
    struct node *node,*prevNode;
    if(head == NULL)  
    {  
        printf("\nlist is empty :(\n");  
    }
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted\n");  
    }     
    else  
    {  
        node = head;   
        while(node->next != NULL)  
        {  
            prevNode = node;  
            node = node ->next;  
        }  
        prevNode->next = NULL;  
        free(node);  
        printf("\nDeleted Node from the last\n");  
    }     
}

void deleteMid()  
{  
    struct node *node,*prevNode;  
    int position,i;    
    printf("\nEnter the location of the node after which you want to perform deletion: ");  
    scanf("%d",&position);  
    node=head;  
    for(i=0;i<position;i++)  
    {  
        prevNode = node;       
        node = node->next;  
              
        if(node == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    prevNode ->next = node ->next;  
    free(node);  
    printf("\nDeleted node %d ",position+1);  
}
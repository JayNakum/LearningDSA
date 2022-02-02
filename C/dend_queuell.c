#include <stdio.h>
#include <stdlib.h>

struct queue_node
{
    int ele;
    struct queue_node* next;
};
typedef struct queue_node node;

node* create_node(void);
void traverse(node* head);
node* enqueue_rear(node* head);
node* enqueue_front(node* head);
node* dequeue_front(node* head);
node* dequeue_rear(node* head);

int main(void)
{
    int n;
    int flag = 0;
    node* head = create_node();
    while(flag == 0)
    {
        printf("------------------------------------------\n");
        printf("Enter 1 to dequeue at front.\n");
        printf("Enter 2 to dequeue at rear.\n");
        printf("Enter 3 to enqueue at front.\n");
        printf("Enter 4 to enqueue at rear.\n");
        printf("Enter 5 to traverse from front to rear.\n"); 
        printf("Enter 6 to quit.\n");
        printf("------------------------------------------\n");     
        printf("Enter: ");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                head = dequeue_front(head);
                break;

            case 2:
                head = dequeue_rear(head);
                break;
            
            case 3:
                head = enqueue_front(head);
                break;
            
            case 4:
                head = enqueue_rear(head);
                break;

            case 5:
                traverse(head);
                break;

            case 6:
                flag = 1;
                break;

            default:
                printf("Incorrect input.\n");
        }
    }
}

node* create_node(void)
{
    int new_ele;
    printf("\nEnter new element: ");
    scanf("%d", &new_ele);
    node* new_node = (node*)malloc(sizeof(node));
    

    new_node->ele = new_ele;
    new_node->next = NULL;

    return new_node;
}

void traverse(node* head)
{
    if(head != NULL)
    {
        node* temp = head;
        while(temp->next != NULL)
        {
            printf("%d, ", temp->ele);
            temp = temp->next;
        }
        printf("%d\n", temp->ele);
    }
    else
    {
        printf("The Queue doesn't exist.\n");
    }
}
node* enqueue_rear(node* head)
{
    if(head != NULL)
    {
       node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = create_node();
        return head; 
    }
    else
    {
        head = create_node();
        return head;
    } 
}

node* enqueue_front(node* head)
{
    if(head != NULL)
    {
        node* temp = create_node();
    
        temp->next = head;
        head = temp;
        return head;
    }
    else
    {
        head = create_node();
        return head;
    }
}

node* dequeue_rear(node* head)
{
    if(head != NULL)    //Queue exists
    {
        if(head->next == NULL)  //If head is the only element
        {
            free(head);
            head = NULL;
            return head;
        }
        node* temp = head;  //else 
        node* temp2;
        while(temp->next != NULL)
        {
            //Adjust Pointers
            temp2 = temp;
            temp = temp->next;
        }
        free(temp); //free last element
        temp2->next = NULL; //set second last element's next to NULL
        return head;    
    }
    else    //If Queue doesn't exist
    {
        printf("Queue doesn't exist.\n");
    }
}

node* dequeue_front(node* head)
{
    if(head != NULL)    //Queue exists
    {
        //Adjust pointers
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else    //If Queue doesn't exist
    {
        printf("Queue doesn't exist.\n");
    }
}


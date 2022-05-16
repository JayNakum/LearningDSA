#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} *head = NULL, *tmp = NULL, *ptr = NULL;

struct node *create()
{
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\nMEMORY OVERFLOW");
        return NULL;
    }
    else
    {
        return ptr;
    }
};

void insert_first(int x)
{
    ptr = create();
    if (head == NULL)
    {
        ptr->data = x;
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
        printf("\nNode inserted\n");
    }
    else
    {
        ptr->data = x;
        ptr->prev = NULL;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted\n");
    }
}

void insert_last(int x)
{
    ptr = create();
    if (head == NULL)
    {
        ptr->data = x;
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
        printf("\nNode inserted\n");
    }
    else
    {
        tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        ptr->data = x;
        tmp->next = ptr;
        ptr->next = NULL;
        ptr->prev = tmp;
        printf("\nNode inserted\n");
    }
}

void insert_between(int x, int pos)
{

    tmp = head;
    if (pos == 1)
    {
        insert_first(x);
    }
    else
    {

        for (int i = 1; i < pos - 1; i++)
        {
            tmp = tmp->next;
            if (tmp == NULL)
            {
                printf("\n Next does not exist\n ");
                return;
            }
        }
        ptr = create();
        ptr->prev = tmp;
        ptr->next = tmp->next;
        tmp->next = ptr;
        ptr->data = x;
        printf("\nNode Inserted.\n");
    }
}

void delete_at_first()
{
    tmp = head;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
    }
    head = head->next;
    head->prev = NULL;
    free(tmp);
    printf("Deleted");
}

void delete_at_end()
{
    tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
}
void display()
{
    tmp = head;
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
    }
    while (tmp != NULL)
    {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void reverseDisplay() {
    if (head == NULL)
    {
        printf("UNDERFLOW\n");
    }
    tmp = head->prev;

    while (tmp != head)
    {
        printf("%d\t", tmp->data);
        tmp = tmp->prev;
    }
    printf("\n");
    
}
void main()
{
    int ch, val, pos;
    while (1)
    {
        printf("\n1. Display");
        printf("\n2. Insert beginning");
        printf("\n3. Insert end");
        printf("\n4. Insert at position");
        printf("\n5. Delete beginning");
        printf("\n6. Delete end");
        printf("\n7. Reverse Display");
        printf("\n8. Exit");
        printf("\n Enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;

        case 2:
            printf("Enter value:");
            scanf("%d", &val);
            insert_first(val);
            break;

        case 3:
            printf("Enter Value:");
            scanf("%d", &val);
            insert_last(val);
            break;

        case 4:
            printf("Enter value:");
            scanf("%d", &val);
            printf("Enter Position:");
            scanf("%d", &pos);
            insert_between(val, pos);
            break;

        case 5:
            delete_at_first();
            break;

        case 6:
            delete_at_end();
            break;

        case 7:
            reverseDisplay();
            break;

        case 8:
            exit(0);
            break;
        
        default:
            printf("Invalid Choice");
            break;
        }
    }
}
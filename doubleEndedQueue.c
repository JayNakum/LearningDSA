#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node
{
    int val;
    Node *prev;
    Node *next;
};

Node *createNode()
{
    int n;
    printf("Enter info for new node: ");
    scanf("%d", &n);
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    new_node->val = n;
    new_node->prev = new_node->next = new_node;
    return new_node;
}

Node *enqueueAtEnd(Node *head, Node *new_node)
{
    if (head != NULL)
    {
        Node *last = head->prev;
        new_node->prev = last;
        new_node->next = head;
        head->prev = last->next = new_node;
    }
    else
        head = new_node;
    return head;
}

Node *enqueueAtFront(Node *head, Node *new_node)
{
    if (head != NULL)
    {
        Node *last = head->prev;
        new_node->prev = last;
        new_node->next = head;
        last->next = head->prev = new_node;
        head = new_node;
    }
    else
        head = new_node;
    return head;
}

Node *dequeueAtFront(Node *head)
{
    Node *ptr, *p = head;
    if (head == NULL)
        printf("List is empty.\n");
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        ptr = head->next;
        ptr->prev = p->prev;
        (p->prev)->next = ptr;
        head = ptr;
        free(p);
    }
    return head;
}

Node *dequeueAtEnd(Node *head)
{
    if (head == NULL)
        printf("List is empty.\n");
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *p, *n;
        n = head->prev;
        p = n->prev;
        p->next = head;
        head->prev = p;
        free(n);
    }
    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    if (head == NULL)
        printf("Queue is empty.\n");
    else
    {
        printf("Status of queue:\n");
        while (temp->next != head)
        {
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("%d\n", temp->val);
    }
}

int main()
{
    int n = 1, flag = 0, key;
    Node *head = createNode();
    Node *new_node;
    while (flag == 0)
    {
        printf("\n1. Enqueue at end operation."
               "\n2. Enqueue at beginning operation."
               "\n3. Dequeue at end operation."
               "\n4. Dequeue at beginning operation."
               "\n5. To traverse through queue."
               "\n6. Exit"
               "\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            new_node = createNode();
            head = enqueueAtEnd(head, new_node);
            break;
        case 2:
            new_node = createNode();
            head = enqueueAtFront(head, new_node);
            break;
        case 3:
            head = dequeueAtEnd(head);
            break;
        case 4:
            head = dequeueAtFront(head);
            break;
        case 5:
            traverse(head);
            break;
        case 6:
            flag = 1;
            break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <conio.h>

#define MAX 5

struct queue
{
    int element[MAX];
    int front;
    int rear;
} queue;

int isEmpty()
{
    int isEmpty = 1;
    if (queue.front != -1)
    {
        printf("Queue is empty");
        isEmpty = 0;
    }
    return isEmpty;
}

int isFull()
{
    int isFull = 0;
    if ((queue.front == 0 && queue.rear == (MAX - 1)) || (queue.front == (queue.rear + 1)))
    {
        printf("Queue is full");
        isFull = 1;
    }
    return isFull;
}

void traverse()
{
    int i = queue.front;

    while (i != queue.rear)
    {
        printf("%d", queue.element[i]);
        i += 1;
    }
    printf("%d", queue.element[queue.rear]);
}

void peekFront()
{
    if (isEmpty() == 1)
    {
    }
    else
    {
        printf("%d is at front.", queue.element[queue.front]);
    }
}

int peekRear()
{
    if (isEmpty() == 1)
    {
    }
    else
    {
        printf("%d is at rear.", queue.element[queue.rear]);
    }
}

void enqueueFront(int value)
{
    if (isFull() == 1)
    {
    }
    else if ((queue.front == -1) && (queue.rear == -1))
    {
        queue.front = 0;
        queue.rear = 0;
        queue.element[queue.front] = value;
    }
    else if (queue.front == 0)
    {
        queue.front = (MAX - 1);
        queue.element[queue.front] = value;
    }
    else
    {
        queue.front -= 1;
        queue.element[queue.front] = value;
    }
}

void enqueueBack(int value)
{
    if (isFull() == 1)
    {
    }
    else if ((queue.front == -1) && (queue.rear == -1))
    {
        queue.front = 0;
        queue.rear = 0;
        queue.element[queue.rear] = value;
    }
    else if (queue.rear == (MAX - 1))
    {
        queue.rear = 0;
        queue.element[queue.rear] = value;
    }
    else
    {
        queue.rear += 1;
        queue.element[queue.rear] = value;
    }
}

void dequeueFront()
{
    int oldElement;
    if (isEmpty() == 1)
    {
    }
    else if (queue.front == queue.rear)
    {
        oldElement = queue.element[queue.front];
        queue.front = -1;
        queue.rear = -1;
    }
    else if (queue.front == (MAX - 1))
    {
        oldElement = queue.element[queue.front];
        queue.front = 0;
    }
    else
    {
        oldElement = queue.element[queue.front];
        queue.front += 1;
    }
    printf("%d is deleted.", oldElement);
}

void dequeueBack()
{
    int oldElement;
    if (isEmpty() == 1)
    {
    }
    else if (queue.front == queue.rear)
    {
        oldElement = queue.element[queue.rear];
        queue.front = -1;
        queue.rear = -1;
    }
    else if (queue.rear == 0)
    {
        oldElement = queue.element[queue.rear];
        queue.rear = (MAX - 1);
    }
    else
    {
        oldElement = queue.element[queue.rear];
        queue.rear -= 1;
    }
}

int main()
{
    enqueueFront(2);
    enqueueFront(1);
    enqueueBack(3);
    enqueueBack(5);
    enqueueBack(8);
    traverse();
    peekFront();
    peekRear();
    dequeueFront();
    dequeueBack();
    traverse();
    return 0;
}

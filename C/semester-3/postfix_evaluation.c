#include <stdio.h>
#include <conio.h>

#define MAX 10

struct stack
{
    int ele[MAX];
    int top;
} s;

int isEmpty() {
    if(s.top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if(s.top == MAX) {
        return 1;
    } else {
        return 0;
    }
}

void push(int ele) {
    if(isFull()) {
        printf("Stack is full :/");
    }
    else {
        s.top += 1;
        s.ele[s.top] = ele;
    }
}

int pop() {
    int ele = s.ele[s.top];
    s.ele[s.top] = 0;
    s.top -= 1;
    return ele;
}


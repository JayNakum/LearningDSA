/*
Array:
    Display / Traverse
    Insert : start, end, key
    Delete : start, end, key
    Peek
    Search : element, pos
*/

#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

#define MAX 5
int arr[MAX];

void traverse();
void insertStart();
void insertPos(int pos);
void insertEnd();
int deleteStart();
int deletePos(int pos);
int deleteEnd();
int peek();
int searchEle(int ele);
int searchPos(int pos);


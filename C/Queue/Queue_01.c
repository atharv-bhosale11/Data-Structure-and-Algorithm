/*
===============================================================================
Program Name    : Queue Using Singly Linear Linked List
Program Number  : 01
File Name       : Queue01.c

Description     : This program contains the basic skeleton
                  of Queue Data Structure using Singly
                  Linear Linked List.

Date            : August 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

struct Queue
{
    PNODE first;
    int iCount;
};

typedef struct Queue QUEUE;

int main()
{
    QUEUE qobj;

    qobj.first = NULL;
    qobj.iCount = 0;

    return 0;
}

/*
===============================================================================
End of Program

Queue Using Singly Linear Linked List

Author  : Atharv Tushar Bhosale
Date    : August 2026
===============================================================================
*/

/*
===============================================================================
Program Name    : Stack Display Operation
Program Number  : 003
File Name       : Stack03.c

Description     : This program demonstrates Stack using
                  Singly Linear Linked List and supports
                  Push and Display operations.

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
typedef struct node** PPNODE;

void Push(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = *first;

    *first = newn;
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|\n",first->data);
        first = first->next;
    }
}

int main()
{
    PNODE head = NULL;

    Push(&head,11);
    Push(&head,21);
    Push(&head,51);
    Push(&head,101);

    Display(head);

    return 0;
}

/*
===============================================================================
End of Program
===============================================================================
*/

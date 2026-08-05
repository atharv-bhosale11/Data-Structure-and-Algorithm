/*
===============================================================================
Program Name    : Stack Push Operation
Program Number  : 002
File Name       : Stack02.c

Description     : Insert element at First Position.

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

int main()
{
    PNODE head = NULL;

    Push(&head,11);
    Push(&head,21);
    Push(&head,51);
    Push(&head,101);

    return 0;
}

/*
===============================================================================
End of Program
===============================================================================
*/

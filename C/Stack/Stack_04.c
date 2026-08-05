/*
===============================================================================
Program Name    : Stack Count Operation
Program Number  : 004
File Name       : Stack04.c

Description     : This program demonstrates Stack using 
                  Singly Linear Linked List and supports
                  Push, Display and Count operations.

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

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Push(&head,11);
    Push(&head,21);
    Push(&head,51);
    Push(&head,101);

    Display(head);

    iRet = Count(head);

    printf("Number of Elements : %d\n",iRet);

    return 0;
}

/*
===============================================================================
Output :

|101|
|51|
|21|
|11|

Number of Elements : 4

===============================================================================
End of Program
===============================================================================
*/

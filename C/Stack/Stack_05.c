/*
===============================================================================
Program Name    : Stack Pop Operation
Program Number  : 005
File Name       : Stack05.c

Description     : This program demonstrates Stack using
                  Singly Linear Linked List and supports
                  Push, Display, Count and Pop operations.

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
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = *first;

    *first = newn;
}

int Pop(PPNODE first)
{
    PNODE temp = NULL;
    int iValue = 0;

    if(*first == NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }

    iValue = (*first)->data;

    temp = *first;
    *first = (*first)->next;

    free(temp);

    return iValue;
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

    iRet = Pop(&head);
    printf("Removed Element : %d\n",iRet);

    Display(head);

    return 0;
}

/*
===============================================================================
Sample Output

|101|
|51|
|21|
|11|

Removed Element : 101

|51|
|21|
|11|

===============================================================================
End of Program
===============================================================================
*/


/*
===============================================================================
Program Name    : Queue Count Operation
Program Number  : 004
File Name       : Queue04.c

Description     : This program demonstrates Count
                  operation in Queue.

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

void Enqueue(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d| -> ",first->data);
        first = first->next;
    }

    printf("NULL\n");
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

    Enqueue(&head,11);
    Enqueue(&head,21);
    Enqueue(&head,51);
    Enqueue(&head,101);

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes : %d\n",iRet);

    return 0;
}

/*
===============================================================================
Output :

|11| -> |21| -> |51| -> |101| -> NULL
Number of Nodes : 4

===============================================================================
End of Program
===============================================================================
*/

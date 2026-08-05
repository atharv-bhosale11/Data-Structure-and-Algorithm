/*
===============================================================================
Program Name    : Queue Dequeue Operation
Program Number  : 005
File Name       : Queue05.c

Description     : This program demonstrates Dequeue
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

int Dequeue(PPNODE first)
{
    int iValue = 0;
    PNODE temp = NULL;

    if(*first == NULL)
    {
        printf("Queue is Empty\n");
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
        printf("|%d| -> ",first->data);
        first = first->next;
    }

    printf("NULL\n");
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

    iRet = Dequeue(&head);

    printf("Removed Element : %d\n",iRet);

    Display(head);

    return 0;
}

/*
===============================================================================
Output :

|11| -> |21| -> |51| -> |101| -> NULL
Removed Element : 11
|21| -> |51| -> |101| -> NULL

===============================================================================
End of Program
===============================================================================
*/

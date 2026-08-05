/*
===============================================================================
Program Name    : Queue Enqueue Operation
Program Number  : 002
File Name       : Queue02.c

Description     : This program demonstrates insertion
                  of elements into Queue.

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

int main()
{
    PNODE head = NULL;

    Enqueue(&head,11);
    Enqueue(&head,21);
    Enqueue(&head,51);

    return 0;
}

/*
===============================================================================
End of Program 02 : Enqueue Operation
===============================================================================
*/

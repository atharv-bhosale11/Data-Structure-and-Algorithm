```c
/*
=====================================================================

Name            : Doubly Circular Linked List - DeleteFirst
Program Number  : 007

Description     : This program demonstrates deletion of
                  the first node from a Doubly Circular
                  Linked List.

                  The program also includes Display(),
                  Count(), InsertFirst() and InsertLast()
                  operations for testing.

Concepts Used   : Doubly Circular Linked List,
                  DeleteFirst,
                  Dynamic Memory Allocation,
                  Pointer Manipulation,
                  Circular Linking

Input           : Node data

Output          : Linked list before and after deletion
                  along with node count

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Doubly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    printf("<=> ");

    do
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    }while(first != last->next);

    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return 0;
    }

    do
    {
        iCount++;
        first = first->next;
    }while(first != last->next);

    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        *last = newn;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first)->next;

        free((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{

}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{

}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);

    DeleteFirst(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);

    return 0;
}

/*
=====================================================================

Sample Output :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of Nodes : 6

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of Nodes : 5

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. DeleteFirst()

Pending Functions :

1. InsertAtPos()
2. DeleteLast()
3. DeleteAtPos()

=====================================================================

Notes :

1. DeleteFirst removes the first node.
2. first pointer is updated to the next node.
3. Circular links are re-established.
4. prev pointer of first points to last.
5. next pointer of last points to first.

=====================================================================
End of Program
=====================================================================
*/
```

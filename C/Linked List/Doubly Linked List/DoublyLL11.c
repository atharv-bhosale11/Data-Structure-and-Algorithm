/*
=====================================================================

Name            : Doubly Linked List - InsertLast Operation
Program Number  : 011
Description     : This program demonstrates insertion of nodes at
                  the end of a Doubly Linked List.

                  A new node is dynamically allocated and attached
                  after the last node of the list. The next and prev
                  pointers are updated appropriately to maintain the
                  doubly linked structure.

Concepts Used   : Doubly Linked List, Dynamic Memory Allocation,
                  InsertLast Operation, Traversal,
                  Self-Referential Structure,
                  Pointer to Pointer

Input           : Integer values to be inserted

Output          : Nodes inserted successfully at the end of the
                  Doubly Linked List

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

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

void Display(PNODE first)
{

}

int Count(PNODE first)
{
    return 0;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(NULL == *first)
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
        newn->prev = temp;
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{

}

void DeleteLast(PPNODE first)
{

}

void DeleteAtPos(PPNODE first, int iPos)
{

}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,121);

    return 0;
}

/*
=====================================================================

Insertion Sequence :

InsertFirst(&head,51);
InsertFirst(&head,21);
InsertFirst(&head,11);

InsertLast(&head,101);
InsertLast(&head,121);

Final Linked List :

NULL <- |11| <=> |21| <=> |51| <=> |101| <=> |121| -> NULL

=====================================================================

Note :

- Traversal is required to reach the last node.
- New node is attached after the last node.
- prev pointer of new node points to old last node.
- next pointer of old last node points to new node.
- Time Complexity : O(N)

=====================================================================
*/



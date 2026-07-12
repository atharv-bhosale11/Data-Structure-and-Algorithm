/*
=====================================================================

Program Name    : Singly Linked List - Display Linked List
Program Number  : 023
Description     : This program demonstrates the implementation of
                  InsertFirst() and Display() operations in a
                  Singly Linked List. Nodes are inserted at the
                  beginning of the list and displayed in a
                  linked-list format using traversal.

Concepts Used   : Structure, Self-Referential Structure,
                  Dynamic Memory Allocation,
                  Head Pointer Manipulation,
                  Linked List Traversal,
                  Insert First Operation

Functions       : InsertFirst()
                  Display()

Input           : Node values passed through function calls.

Output          : Displays all nodes of the linked list.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
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

void Display(PNODE first)
{
    while (first!= NULL)
    {
        printf("|%d| -> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    return 0;
}

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {

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

    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    return 0;
}

/*
=====================================================================

Expected Output :

|11| -> |21| -> |51| -> |101| -> NULL

Explanation :

The linked list is initially empty.

Insertion Sequence :

InsertFirst(&head,101)
InsertFirst(&head,51)
InsertFirst(&head,21)
InsertFirst(&head,11)

Linked List Formation :

Step 1:
HEAD
 |
 v
|101| -> NULL

Step 2:
HEAD
 |
 v
|51| -> |101| -> NULL

Step 3:
HEAD
 |
 v
|21| -> |51| -> |101| -> NULL

Step 4:
HEAD
 |
 v
|11| -> |21| -> |51| -> |101| -> NULL

Display Traversal :

HEAD
 |
 v
|11| -> |21| -> |51| -> |101| -> NULL

The Display() function traverses the linked
list node by node. It prints the data part of
every node and moves to the next node until
NULL is encountered.

Operations Performed :

1. Created an empty linked list.
2. Inserted four nodes using InsertFirst().
3. Updated the Head pointer after each insertion.
4. Traversed the linked list using Display().
5. Printed all node values in linked-list format.

Conclusion :

This program demonstrates how a linked list
can be traversed and displayed using a Head
pointer. The Display() function is one of the
most fundamental operations in linked list
implementation and is widely used for debugging
and visualization purposes.

=====================================================================
*/

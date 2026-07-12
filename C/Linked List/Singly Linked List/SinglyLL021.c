/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst Operation
Program Number  : 021
Description     : This program demonstrates the implementation of
                  the InsertFirst() function in a Singly Linked
                  List. New nodes are dynamically created and
                  inserted at the beginning of the linked list.

Concepts Used   : Structure, Self-Referential Structure,
                  Dynamic Memory Allocation,
                  Pointer to Pointer,
                  Head Pointer Manipulation,
                  Insert First Operation

Functions       : InsertFirst()

Input           : Node values passed through function calls.

Output          : No output generated.

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

}

int Count(PNODE first)
{
    return 0;
}

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)          // Linked List is Empty
    {
        *first = newn;
    }
    else                        // Linked List contains nodes
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)          // Linked List is Empty
    {
        *first = newn;
    }
    else                        // Linked List contains nodes
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

    return 0;
}

/*
=====================================================================

Expected Output :

(No Output)

Linked List Formation :

InsertFirst(&head,101)

HEAD
 |
 v
|101| -> NULL

--------------------------------------------------

InsertFirst(&head,51)

HEAD
 |
 v
|51| -> |101| -> NULL

--------------------------------------------------

InsertFirst(&head,21)

HEAD
 |
 v
|21| -> |51| -> |101| -> NULL

--------------------------------------------------

InsertFirst(&head,11)

HEAD
 |
 v
|11| -> |21| -> |51| -> |101| -> NULL

Explanation :

The InsertFirst() function inserts every new
node at the beginning of the linked list.

Steps Performed :

1. Allocate memory for a new node.
2. Store the given data value.
3. Initialize next pointer to NULL.
4. Check whether the list is empty.
5. If empty, make the new node the first node.
6. Otherwise, connect the new node before
   the current first node.
7. Update the Head pointer.

Function Call Flow :

InsertFirst(&head,101)
InsertFirst(&head,51)
InsertFirst(&head,21)
InsertFirst(&head,11)

Final Linked List :

HEAD
 |
 v
|11| -> |21| -> |51| -> |101| -> NULL

Conclusion :

InsertFirst() is one of the most efficient
linked list operations because it does not
require traversal. The new node is inserted
directly at the beginning, making its time
complexity O(1).

=====================================================================
*/

/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst with Display
Program Number  : 022
Description     : This program demonstrates the implementation of
                  the InsertFirst() operation along with the
                  Display() function in a Singly Linked List.
                  Nodes are inserted at the beginning of the
                  list and later displayed through traversal.

Concepts Used   : Structure, Self-Referential Structure,
                  Dynamic Memory Allocation,
                  Pointer to Pointer,
                  Linked List Traversal,
                  Insert First Operation

Functions       : InsertFirst()
                  Display()

Input           : Node values passed through function calls.

Output          : Displays all nodes present in the
                  linked list.

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
    while(first != NULL)
    {
        printf("%d\t", first->data);
        first = first->next;
    }
    printf("\n");
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

11      21      51      101

Explanation :

The InsertFirst() function inserts every new
node at the beginning of the linked list.

Insertion Sequence :

InsertFirst(&head,101)
InsertFirst(&head,51)
InsertFirst(&head,21)
InsertFirst(&head,11)

Linked List Formation :

After inserting 101

HEAD
 |
 v
101 -> NULL

After inserting 51

HEAD
 |
 v
51 -> 101 -> NULL

After inserting 21

HEAD
 |
 v
21 -> 51 -> 101 -> NULL

After inserting 11

HEAD
 |
 v
11 -> 21 -> 51 -> 101 -> NULL

Display Traversal :

HEAD
 |
 v
11 -> 21 -> 51 -> 101 -> NULL

The Display() function starts from the Head
pointer and visits each node one by one until
NULL is encountered.

Operations Performed :

1. Created an empty linked list.
2. Inserted four nodes using InsertFirst().
3. Updated the Head pointer after each insertion.
4. Traversed the linked list using Display().
5. Printed all node values.

Conclusion :

This program demonstrates how InsertFirst()
adds nodes at the beginning of a linked list
and how Display() traverses the list to show
all stored elements. These operations form the
foundation of linked list manipulation.

=====================================================================
*/

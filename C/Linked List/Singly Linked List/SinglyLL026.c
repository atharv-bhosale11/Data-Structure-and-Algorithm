/*
=====================================================================

Program Name    : Singly Linked List - Assignment Operator Issue
Program Number  : 026
Description     : This program demonstrates the implementation of
                  basic Singly Linked List operations such as
                  InsertFirst(), Display(), and Count(). It also
                  highlights a common programming mistake where the
                  assignment operator (=) is used instead of the
                  comparison operator (==) inside a conditional
                  statement.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Dynamic Memory Allocation,
                  Pointer Manipulation, Linked List Traversal,
                  Assignment Operator, Comparison Operator

Input           : None

Output          : Demonstrates the effect of using an assignment
                  operator inside an if condition.

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
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    return iCount;
}

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first = NULL)          // ISSUE 
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

    if(*first == NULL)          // Linked List is Empty
    {
        *first = newn;
    }
    else                       // Linked List at lest contain one Node
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
    int iRet = 0;
    
    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);

    return 0;
}

/*
=====================================================================

Expected Behavior :

The InsertFirst() function should check whether the
linked list is empty before inserting a new node.

Correct Condition :

if(*first == NULL)

Issue Demonstrated :

In this program, the following statement is used:

if(*first = NULL)

Instead of comparing *first with NULL, it assigns
NULL to *first.

Effect :

1. The head pointer becomes NULL.
2. The condition evaluates to false.
3. Control always enters the else block.
4. The linked list structure gets corrupted.
5. InsertFirst() does not work as expected.

Assignment vs Comparison :

Assignment Operator :
=
Used to assign a value.

Example :
x = 10;

Comparison Operator :
==
Used to compare two values.

Example :
if(x == 10)

Learning Outcome :

This program demonstrates one of the most common
mistakes made by C programmers. Understanding the
difference between '=' and '==' is essential for
writing correct conditional statements and avoiding
logical errors in linked list implementations.

Conclusion :

Always use the comparison operator (==) when
checking conditions. Accidentally using the
assignment operator (=) can lead to unexpected
behavior and difficult-to-find bugs.

=====================================================================
*/

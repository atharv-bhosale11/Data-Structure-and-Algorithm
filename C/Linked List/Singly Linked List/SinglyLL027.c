/*
=====================================================================

Program Name    : Singly Linked List - Safe NULL Comparison
Program Number  : 027
Description     : This program demonstrates the implementation of
                  basic Singly Linked List operations including
                  InsertFirst(), Display(), and Count(). It also
                  illustrates the recommended coding practice of
                  placing constants on the left side of comparison
                  expressions to avoid accidental assignment errors.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Dynamic Memory Allocation,
                  Pointer Manipulation, Linked List Traversal,
                  NULL Comparison, Defensive Programming

Input           : None

Output          : Displays the linked list elements and
                  prints the total number of nodes.

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

    if(NULL == *first)
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

Expected Output :

|11| -> |21| -> |51| -> |101| -> NULL
Number of Nodes: 4

Explanation :

The program creates a Singly Linked List and inserts
four nodes at the beginning of the list using the
InsertFirst() function.

Insertion Sequence :

InsertFirst(101)
InsertFirst(51)
InsertFirst(21)
InsertFirst(11)

Final Linked List :

Head
 |
 v
|11| -> |21| -> |51| -> |101| -> NULL

Safe NULL Comparison :

The condition used in InsertFirst() is:

if(NULL == *first)

This style is commonly known as Yoda Condition.

Reason :

If a programmer accidentally writes:

NULL = *first

the compiler immediately generates an error,
preventing accidental assignment mistakes.

Comparison Styles :

Traditional Style :
if(*first == NULL)

Defensive Style :
if(NULL == *first)

Both conditions produce the same result.

Operations Performed :

1. Created a self-referential structure.
2. Allocated memory dynamically.
3. Inserted nodes at the beginning.
4. Traversed and displayed the list.
5. Counted total nodes.
6. Demonstrated safe NULL comparison.

Conclusion :

Using NULL on the left side of comparison is a
defensive programming technique that helps prevent
accidental assignment errors and improves code
reliability in large projects.

=====================================================================
*/

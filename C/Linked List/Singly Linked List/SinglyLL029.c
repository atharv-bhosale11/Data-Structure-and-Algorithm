/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst Operation
Program Number  : 029
Description     : This program demonstrates the implementation of
                  the InsertFirst() operation in a Singly Linked
                  List. Nodes are dynamically created and inserted
                  at the beginning of the linked list. The program
                  also displays all nodes and counts the total
                  number of nodes present in the list.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Dynamic Memory Allocation,
                  Pointer Manipulation, Linked List Traversal,
                  Insert First Operation, Node Counting

Input           : None

Output          : Displays the linked list and total number
                  of nodes.

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
    while (first != NULL)
    {
        printf("|%d| -> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

void InsertFirst(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(NULL == *first)
    {
        *first = newn;
    }
    else
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

The InsertFirst() function inserts every new node
at the beginning of the linked list.

Insertion Sequence :

InsertFirst(101)
InsertFirst(51)
InsertFirst(21)
InsertFirst(11)

List Formation :

After InsertFirst(101)

|101| -> NULL

After InsertFirst(51)

|51| -> |101| -> NULL

After InsertFirst(21)

|21| -> |51| -> |101| -> NULL

After InsertFirst(11)

|11| -> |21| -> |51| -> |101| -> NULL

Display Operation :

The Display() function traverses the linked list
from the first node to the last node and prints
the contents of each node.

Count Operation :

The Count() function traverses the linked list
and increments a counter for every node visited.

Counting Sequence :

11  -> Count = 1
21  -> Count = 2
51  -> Count = 3
101 -> Count = 4
NULL -> Stop

Operations Performed :

1. Created a self-referential structure.
2. Allocated memory dynamically for nodes.
3. Inserted nodes at the beginning.
4. Displayed all nodes.
5. Counted total nodes.
6. Printed the result.

Conclusion :

This program demonstrates the fundamental
InsertFirst operation of a Singly Linked List.
Understanding this operation is essential before
implementing advanced operations such as
InsertLast, DeleteFirst, DeleteLast, and
InsertAtPosition.

=====================================================================
*/

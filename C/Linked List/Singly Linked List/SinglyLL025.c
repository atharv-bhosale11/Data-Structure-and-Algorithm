/*
=====================================================================

Program Name    : Singly Linked List - Display and Count Nodes
Program Number  : 025
Description     : This program demonstrates the basic implementation
                  of a Singly Linked List in C. It performs insertion
                  of nodes at the beginning of the list, displays all
                  nodes using traversal, and counts the total number
                  of nodes present in the linked list.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Dynamic Memory Allocation,
                  Pointer Traversal, Display Operation,
                  Count Operation, Insert First

Input           : None

Output          : Displays all nodes in the linked list and
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
    while (first)
    {
        printf("|%d| -> ",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while (first)
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

    if(*first == NULL)
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

The program creates a Singly Linked List using
dynamic memory allocation. Four nodes are inserted
at the beginning of the list using the InsertFirst()
function.

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

Display Operation :

The Display() function traverses the linked list
from the first node to the last node and prints
the data stored in each node.

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

1. Created a node structure.
2. Defined typedef aliases.
3. Inserted nodes at the beginning.
4. Displayed all nodes.
5. Counted total nodes.
6. Printed the node count.

Conclusion :

This program demonstrates the fundamental
operations of a Singly Linked List including
node creation, insertion at first position,
display traversal, and node counting. These
operations form the foundation for advanced
linked list manipulations.

=====================================================================
*/

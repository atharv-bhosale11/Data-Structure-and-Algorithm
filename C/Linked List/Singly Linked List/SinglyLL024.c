/*
=====================================================================

Program Name    : Singly Linked List - Count Nodes
Program Number  : 024
Description     : This program demonstrates the implementation of
                  Display() and Count() operations in a Singly
                  Linked List. The Count() function traverses
                  the entire list and returns the total number
                  of nodes present.

Concepts Used   : Structure, Self-Referential Structure,
                  Dynamic Memory Allocation,
                  Linked List Traversal,
                  Node Counting,
                  Head Pointer

Functions       : InsertFirst()
                  Display()
                  Count()

Input           : Node values passed through function calls.

Output          : Displays the linked list and total
                  number of nodes.

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
        printf("|%d| -> ", first->data);
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
    printf("Number of Nodes: %d\n", iRet);

    return 0;
}

/*
=====================================================================

Expected Output :

|11| -> |21| -> |51| -> |101| -> NULL
Number of Nodes: 4

Explanation :

The Count() function is used to determine the
total number of nodes present in the linked list.

Linked List Structure :

HEAD
 |
 v
|11| -> |21| -> |51| -> |101| -> NULL

Traversal Performed by Count() :

Step 1 :
Current Node = 11
Count = 1

Step 2 :
Current Node = 21
Count = 2

Step 3 :
Current Node = 51
Count = 3

Step 4 :
Current Node = 101
Count = 4

Step 5 :
Current Node = NULL
Traversal Stops

Function Call Flow :

head
 |
 v
Count(head)
     |
     v
Traverses all nodes
     |
     v
Returns 4

Operations Performed :

1. Created an empty linked list.
2. Inserted four nodes using InsertFirst().
3. Displayed all nodes using Display().
4. Traversed the linked list using Count().
5. Counted each node encountered.
6. Returned the total count.
7. Displayed the result.

Conclusion :

The Count() function is a fundamental linked
list operation used to determine the size of
the list. It is frequently used before
position-based insertion and deletion
operations to validate user input.

Time Complexity : O(N)
Space Complexity : O(1)

=====================================================================
*/

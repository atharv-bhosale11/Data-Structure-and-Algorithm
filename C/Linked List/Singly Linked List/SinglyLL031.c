/*
=====================================================================

Program Name    : Singly Linked List - DeleteFirst Operation
Program Number  : 031
Description     : This program demonstrates the implementation of
                  DeleteFirst() operation in a Singly Linear Linked
                  List. The first node of the linked list is removed
                  safely by updating the head pointer and releasing
                  the allocated memory.

Concepts Used   : Singly Linked List,
                  Dynamic Memory Allocation,
                  Pointer Manipulation,
                  DeleteFirst Operation,
                  Traversal, Node Counting

Input           : Node values inserted using InsertFirst() and
                  InsertLast() functions.

Output          : Displays the linked list before and after
                  deleting the first node along with the
                  total number of nodes.

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
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)          // Linked List is Empty
    {
        *first = newn;
    }
    else                       // Linked List at lest contain one Node
    {
        temp = *first;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{   
    PNODE temp = NULL;
    if(*first == NULL)                  // Linked List is Empty
    {   
        return;
    }
    else if((*first) -> next == NULL)     // Linked List contains one node
    {
        free(*first);
        *first = NULL;
    }
    else                                // Linked List more than one nodes
    {
        temp = *first;

        *first = (*first) -> next;

        free(temp);
    }
}

void DeleteLast(PPNODE first)
{   
    if(*first == NULL)                  // Linked List is Empty
    {   
        return;
    }
    else if((*first) -> next == NULL)     // Linked List contains one node
    {
        free(*first);
        *first = NULL;
    }
    else                                // Linked List more than one nodes
    {
        
    }
}

void DeleteAtPos(PPNODE first, int iPos)
{

}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    // INSERT AT FIRST
    InsertFirst(&head,101);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);


    // INSERT AT LAST
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes: %d\n",iRet);

    // DELETE AT FIRST
    DeleteFirst(&head);
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

|11| -> |21| -> |51| -> |101| -> |111| -> |121| -> NULL
Number of Nodes: 6

|21| -> |51| -> |101| -> |111| -> |121| -> NULL
Number of Nodes: 5

Explanation :

Initial Linked List :

Head
 |
 v
11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

DeleteFirst() Operation :

temp = first

Head
 |
 v
11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL
^
|
temp

Head is shifted to next node :

Head
 |
 v
21 -> 51 -> 101 -> 111 -> 121 -> NULL

The old first node (11) is freed from memory.

Operations Performed :

1. Inserted nodes at first position.
2. Inserted nodes at last position.
3. Displayed linked list.
4. Counted total nodes.
5. Deleted first node.
6. Updated head pointer.
7. Freed removed node memory.
8. Displayed updated linked list.

Conclusion :

DeleteFirst() successfully removes the first node
from the linked list while maintaining proper
memory management and list integrity.

=====================================================================
*/

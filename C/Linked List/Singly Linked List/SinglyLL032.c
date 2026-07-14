/*
=====================================================================

Program Name    : Singly Linked List - DeleteLast Operation
Program Number  : 032
Description     : This program demonstrates the implementation of
                  DeleteLast() operation in a Singly Linear Linked
                  List. The last node of the linked list is removed
                  by traversing to the second last node and
                  updating its next pointer to NULL.

Concepts Used   : Singly Linked List,
                  Dynamic Memory Allocation,
                  Pointer Manipulation,
                  DeleteLast Operation,
                  Traversal, Node Counting

Input           : Node values inserted using InsertFirst() and
                  InsertLast() functions.

Output          : Displays the linked list before and after
                  deleting the last node along with the
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
    while (first!= NULL)        // Type 1
    {
        printf("|%d| -> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{   
    int iCount = 0;

    while (first != NULL)       // Type 1
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
        while(temp -> next != NULL)     // Type 2
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
        while(temp -> next -> next != NULL)
        {   
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
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

    // DELETE LAST
    DeleteLast(&head);
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

|21| -> |51| -> |101| -> |111| -> NULL
Number of Nodes: 4

Explanation :

Initial Linked List :

11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

After DeleteFirst() :

21 -> 51 -> 101 -> 111 -> 121 -> NULL

DeleteLast() Traversal :

21 -> 51 -> 101 -> 111 -> 121 -> NULL
                    ^
                    |
              Second Last Node

The loop stops at node 111 because
temp->next->next becomes NULL.

Node 121 is deleted and the next pointer
of node 111 is updated to NULL.

Updated Linked List :

21 -> 51 -> 101 -> 111 -> NULL

Operations Performed :

1. Inserted nodes at first position.
2. Inserted nodes at last position.
3. Displayed linked list.
4. Counted total nodes.
5. Deleted first node.
6. Deleted last node.
7. Freed memory of deleted node.
8. Displayed updated linked list.

Conclusion :

DeleteLast() successfully removes the last
node from the linked list by locating the
second last node and updating its next
pointer to NULL while maintaining proper
memory management.

=====================================================================
*/

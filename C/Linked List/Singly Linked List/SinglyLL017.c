/*
=====================================================================

Program Name    : Singly Linked List - Complete Implementation
Program Number  : 017
Description     : This program implements all fundamental operations
                  of a Singly Linked List using dynamic memory
                  allocation. It demonstrates insertion, deletion,
                  traversal, counting, and position-based operations
                  through modular functions.

Concepts Used   : Structure, Self-Referential Structure,
                  Dynamic Memory Allocation,
                  typedef, Pointer to Pointer,
                  Linked List Traversal,
                  Insertion Operations,
                  Deletion Operations

Functions Used  : InsertFirst()
                  InsertLast()
                  DeleteFirst()
                  DeleteLast()
                  InsertAtPos()
                  DeleteAtPos()
                  Display()
                  Count()

Input           : Node values and positions passed through
                  function calls.

Output          : Displays the linked list contents and
                  total number of nodes after each operation.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
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

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)   
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) ->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first) -> next;

        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) ->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL) 
        {
            temp = temp ->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE first)
{
    while(first != NULL)    
    {
        printf("| %d | -> ",first->data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first ->next;
    }

    return iCount;
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCnt = 0;
    int iSize = 0;
    iSize = Count(*first);

    if((pos < 1) || (pos > iSize + 1))      
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iSize+1)
    {
        InsertLast(first,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;    
        temp->next = newn;          
    }

}

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize))      
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        target = temp->next;

        temp->next = target -> next;        
        free(target);                       
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);
    
    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);
    
    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);

    InsertAtPos(&head,105,3);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);
    
    DeleteAtPos(&head,3);

    Display(head);
    iRet = Count(head);

    printf("Number of nodes are : %d\n",iRet);
    
    return 0;
}

/*
=====================================================================

Expected Output :

| 11 | -> | 21 | -> | 51 | -> NULL
Number of nodes are : 3

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of nodes are : 6

| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of nodes are : 5

| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 4

| 21 | -> | 51 | -> | 105 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 5

| 21 | -> | 51 | -> | 101 | -> | 111 | -> NULL
Number of nodes are : 4

Explanation :

This program demonstrates a complete implementation
of a Singly Linked List using dynamically allocated
nodes and modular functions.

The linked list supports insertion and deletion
operations at the beginning, end, and any valid
position within the list. Additional utility
functions are provided for displaying elements
and counting the total number of nodes.

Functions Overview :

1. InsertFirst()
   Inserts a new node at the beginning.

2. InsertLast()
   Inserts a new node at the end.

3. DeleteFirst()
   Deletes the first node.

4. DeleteLast()
   Deletes the last node.

5. Display()
   Traverses and displays all nodes.

6. Count()
   Counts and returns total nodes.

7. InsertAtPos()
   Inserts a node at a specified position.

8. DeleteAtPos()
   Deletes a node from a specified position.

Operations Performed :

1. Created an empty linked list.
2. Inserted nodes at the beginning.
3. Inserted nodes at the end.
4. Displayed the linked list.
5. Counted total nodes.
6. Deleted the first node.
7. Deleted the last node.
8. Inserted a node at position 3.
9. Deleted the node from position 3.
10. Displayed the updated list after every operation.

Conclusion :

This program combines all fundamental Singly Linked
List operations into a single implementation. It
demonstrates dynamic memory allocation, pointer
manipulation, traversal techniques, insertion and
deletion algorithms, forming the foundation for
advanced linked list and data structure concepts.

=====================================================================
*/

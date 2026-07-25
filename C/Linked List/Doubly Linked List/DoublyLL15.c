/*
=====================================================================

Name            : Doubly Linked List - Delete Last Node
Program Number  : 015
Description     : This program demonstrates deletion of the last
                  node from a Doubly Linked List.

                  The program performs the following operations:
                  - Insert nodes at beginning
                  - Insert nodes at end
                  - Display linked list
                  - Count total nodes
                  - Delete first node
                  - Delete last node

                  During DeleteLast(), the list is traversed up to
                  the second last node. The last node is removed,
                  memory is deallocated, and the next pointer of
                  the new last node is set to NULL.

Concepts Used   : Doubly Linked List, DeleteLast Operation,
                  Dynamic Memory Allocation,
                  Dynamic Memory Deallocation,
                  Pointer Traversal, Self-Referential Structure,
                  Memory Management

Input           : Integer values inserted into the linked list

Output          : Displays linked list before and after deletion

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
    struct node* prev;          // $
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{   
    printf("\nNULL <=>");
    while(first != NULL)
    {
        printf("|%d| <=>",first->data);
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
        first = first -> next;
    }

    return iCount;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;                                           // $

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        (*first)-> prev = newn;                                  // $
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
    newn -> prev = NULL;                                        // $

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;                                    // $
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{
    
}

void DeleteFirst(PPNODE first)
{

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        *first = (*first) -> next;
        free((*first)->prev);                           // $
        (*first) -> prev = NULL;                        // $
    }

}

void DeletetLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
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

void DeletetAtPos(PPNODE first, int iPos)
{
    
}


int main()
{
    PNODE head = NULL;
    int iRet  = 0;
    
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,121);

    Display(head);

    iRet = Count(head);
    printf("Number of Nodes are %d\n",iRet);

    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are %d\n",iRet);

    DeletetLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are %d\n",iRet);

    
    return 0;
}

/*
=====================================================================

Sample Output :

NULL <=>|11| <=>|21| <=>|51| <=>|101| <=>|121| <=>NULL
Number of Nodes are 5

NULL <=>|21| <=>|51| <=>|101| <=>|121| <=>NULL
Number of Nodes are 4

NULL <=>|21| <=>|51| <=>|101| <=>NULL
Number of Nodes are 3

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. DeleteFirst()
6. DeleteLast()

Functions Pending :

1. InsertAtPos()
2. DeleteAtPos()

=====================================================================

Observation :

- DeleteLast() traverses up to the second last node.
- The last node is deallocated using free().
- The next pointer of the new last node becomes NULL.
- Doubly Linked List remains properly connected.
- Total node count decreases after deletion.

=====================================================================
*/

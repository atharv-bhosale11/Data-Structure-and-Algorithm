/*
=====================================================================

Name            : Doubly Linked List - Display Function
Program Number  : 012
Description     : This program demonstrates creation and display of
                  a Doubly Linked List using InsertFirst() and
                  InsertLast() operations.

                  The Display() function traverses the list from
                  first node to last node and prints all elements
                  in Doubly Linked List format.

Concepts Used   : Doubly Linked List, Dynamic Memory Allocation,
                  InsertFirst, InsertLast, Display Function,
                  Traversal, Self-Referential Structure,
                  Pointer Manipulation

Input           : Integer values inserted into the linked list

Output          : Displays all nodes of the Doubly Linked List

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
    return 0;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;        // $

    if(NULL == *first)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        (*first)-> prev = newn;     // $
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
    newn -> prev = NULL;        // $

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
        newn -> prev = temp;        // $
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{
    
}

void DeleteFirst(PPNODE first)
{

}

void DeletetLast(PPNODE first)
{
    
}

void DeletetAtPos(PPNODE first, int iPos)
{
    
}


int main()
{
    PNODE head = NULL;
    
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,121);

    Display(head);
    
    return 0;
}

/*
=====================================================================

Sample Output :

NULL <=>|11| <=>|21| <=>|51| <=>|101| <=>|121| <=>NULL

=====================================================================

Functions Implemented :

1. Display()
2. InsertFirst()
3. InsertLast()

Functions Pending :

1. Count()
2. InsertAtPos()
3. DeleteFirst()
4. DeleteLast()
5. DeleteAtPos()

=====================================================================

Observation :

- InsertFirst() inserts node at beginning.
- InsertLast() inserts node at end.
- Display() traverses the list using next pointer.
- prev pointer is maintained for backward linkage.

=====================================================================
*/

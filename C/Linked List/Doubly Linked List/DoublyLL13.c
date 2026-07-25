/*
=====================================================================

Name            : Doubly Linked List - Count Nodes
Program Number  : 013
Description     : This program demonstrates basic operations of a
                  Doubly Linked List.

                  The program performs the following operations:
                  - Insert nodes at the beginning
                  - Insert nodes at the end
                  - Display all nodes
                  - Count total number of nodes

                  The Count() function traverses the entire linked
                  list and returns the total number of nodes present.

Concepts Used   : Doubly Linked List, Dynamic Memory Allocation,
                  InsertFirst, InsertLast, Display Function,
                  Count Function, Traversal,
                  Self-Referential Structure,
                  Pointer Manipulation

Input           : Integer values inserted into the linked list

Output          : Displays the linked list and total node count

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
    int iRet  = 0;
    
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,121);

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

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()

Functions Pending :

1. InsertAtPos()
2. DeleteFirst()
3. DeleteLast()
4. DeleteAtPos()

=====================================================================

Observation :

- Count() traverses the entire linked list.
- Each node contributes 1 to the node count.
- Doubly Linked List maintains both next and prev links.
- Display() shows nodes from first to last.

=====================================================================
*/

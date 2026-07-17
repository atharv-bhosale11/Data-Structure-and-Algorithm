/*
=====================================================================

Name            : Doubly Linked List - Position Validation Framework
Program Number  : 016
Description     : This program introduces position validation logic
                  for InsertAtPos() and DeleteAtPos() operations
                  in a Doubly Linked List.

                  The program performs:
                  - InsertFirst()
                  - InsertLast()
                  - DeleteFirst()
                  - DeleteLast()
                  - Count()
                  - Position validation for insertion
                  - Position validation for deletion

                  Before performing insertion or deletion at a
                  specific position, the entered position is
                  verified using the current node count.

Concepts Used   : Doubly Linked List, Position Validation,
                  Count Function, Boundary Conditions,
                  Pointer Manipulation, Dynamic Memory Allocation,
                  Self-Referential Structure

Input           : Integer values and position values

Output          : Linked list display and position validation

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
    int iCount = 0;

    iCount = Count(*first);

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first,iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first,iNo);
    }
    else
    {
        
    }
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
    int iCount = 0;

    iCount = Count(*first);

    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iCount)
    {
        DeletetLast(first);
    }
    else
    {
        
    }
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
7. InsertAtPos() Validation Logic
8. DeleteAtPos() Validation Logic

Functions Pending :

1. InsertAtPos() Actual Insertion
2. DeleteAtPos() Actual Deletion

=====================================================================

Observation :

- Position validation prevents invalid insertions.
- Position validation prevents invalid deletions.
- Count() is used to determine valid range.
- Boundary positions are redirected to
  InsertFirst(), InsertLast(), DeleteFirst()
  and DeleteLast() respectively.
- This framework improves robustness of
  linked list operations.

=====================================================================
*/

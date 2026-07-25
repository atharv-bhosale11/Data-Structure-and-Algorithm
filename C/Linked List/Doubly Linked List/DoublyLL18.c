/*
=====================================================================

Name            : Doubly Linear Linked List - DeleteAtPos Operation
Program Number  : 018

Description     : This program demonstrates deletion of a node from
                  a specified position in a Doubly Linear Linked List.

                  The program includes:
                  - InsertFirst()
                  - InsertLast()
                  - InsertAtPos()
                  - DeleteFirst()
                  - DeleteLast()
                  - DeleteAtPos()
                  - Display()
                  - Count()

                  The DeleteAtPos() function removes a node from the
                  desired position and properly updates both next
                  and prev links of surrounding nodes.

Concepts Used   : Doubly Linked List, Dynamic Memory Allocation,
                  Node Deletion, Position Based Operations,
                  Pointer Manipulation, Memory Management

Input           : Node values and position for deletion

Output          : Linked List before and after DeleteAtPos operation

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/
// Doubly Liner Linked List

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
    int i = 0;
    PNODE newn = 0;
    PNODE temp = NULL;

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
        temp = *first;
        newn = (PNODE)malloc(sizeof(NODE));
        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;                            // $

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;                    // $
        temp -> next = newn;
        newn -> prev = temp;                            // $
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
    int i = 0;
    PNODE temp = NULL;

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
        temp = *first;
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        free(temp -> next -> prev);                 // $
        temp -> next -> prev = temp;                // $

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
    InsertLast(&head,111);
    InsertLast(&head,121);
    InsertLast(&head,151);

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

    InsertAtPos(&head,105,4);
    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are %d\n",iRet);

    DeletetAtPos(&head,4);
    Display(head);
    iRet = Count(head);
    printf("Number of Nodes are %d\n",iRet);
    
    return 0;
}

/*
=====================================================================

Sample Output :

NULL <=>|11| <=>|21| <=>|51| <=>|101| <=>|111| <=>|121| <=>|151| <=>NULL
Number of Nodes are 7

NULL <=>|21| <=>|51| <=>|101| <=>|111| <=>|121| <=>|151| <=>NULL
Number of Nodes are 6

NULL <=>|21| <=>|51| <=>|101| <=>|111| <=>|121| <=>NULL
Number of Nodes are 5

NULL <=>|21| <=>|51| <=>|101| <=>|105| <=>|111| <=>|121| <=>NULL
Number of Nodes are 6

NULL <=>|21| <=>|51| <=>|101| <=>|111| <=>|121| <=>NULL
Number of Nodes are 5

=====================================================================
*/

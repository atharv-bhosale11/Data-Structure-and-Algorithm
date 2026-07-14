/*
=====================================================================

Program Name    : Singly Linked List - Menu Driven Implementation
Program Number  : 034
Description     : This program implements a complete Menu Driven
                  Singly Linear Linked List. Users can perform
                  insertion, deletion, display and count operations
                  interactively through a menu interface.

Concepts Used   : Singly Linked List,
                  Dynamic Memory Allocation,
                  Menu Driven Programming,
                  Pointer Manipulation,
                  Traversal,
                  Position Based Operations,
                  Switch Case

Functions       : Display()
                  Count()
                  InsertFirst()
                  InsertLast()
                  InsertAtPos()
                  DeleteFirst()
                  DeleteLast()
                  DeleteAtPos()

Input           : User choice and node values.

Output          : Performs requested linked list operations and
                  displays updated linked list information.

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
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ",first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCnt = 0;
    while(first != NULL)
    {
        iCnt++;
        first = first -> next;
    }
    return iCnt;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL)
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

    if(*first == NULL)
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
        newn -> next = NULL;
    }
}

void InsertAtPos(PPNODE first,int iNo, int iPos)
{
    int i = 0;
    int iCount = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first);

    if(iPos < 1 || iPos > iCount + 1)
    {
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
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;

        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

    }   
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first) -> next == NULL)
    {
        free (*first);
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
    else if((*first) -> next == NULL)
    {
        free (*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free (temp -> next);
        temp -> next = NULL;
    }
}

void DeleteAtPos(PPNODE first,int iPos)
{
    int i = 0;
    int iCount = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*first);

    if(iPos < 1 || iPos > iCount)
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;
        temp -> next = target -> next;
        free (target);
    }   
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;
    int iChoice = 9;
    int iValue = -1;
    int iPosition = 0;

    while(iChoice != 0)
    {
        printf("-------------------------------------------------------------------\n");
        printf("Enter Your Choice:\n");
        printf("-------------------------------------------------------------------\n");

        printf("1: Insert Node at First Position:\n");
        printf("2: Insert Node at Last Position:\n");
        printf("3: Insert Node at Given Position:\n");
        printf("4: Delete Node at First Position:\n");
        printf("5: Delete Node at Last Position:\n");
        printf("6: Delete Node at Given Position:\n");
        printf("7: Display Node:\n");
        printf("8: Count the Node:\n");
        printf("0: Exit the Program!!!\n");

         scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
            printf("Enter the Value:");
            scanf("%d",&iValue);
            InsertFirst(&head,iValue);
            break;

            case 2:
            printf("Enter the Value:");
            scanf("%d",&iValue);
            InsertLast(&head,iValue);
            break;

            case 3:
            printf("Enter the Value:");
            scanf("%d",&iValue);
            printf("Enter the Position:");
            scanf("%d",&iPosition);
            InsertAtPos(&head,iValue,iPosition);
            break;

            case 4:
            DeleteFirst(&head);
            break;

            case 5:
            DeleteLast(&head);
            break;

            case 6:
            printf("Enter the Position:");
            scanf("%d",&iPosition);
            DeleteAtPos(&head,iPosition);
            break;

            case 7:
            Display(head);
            break;

            case 8:
            iRet = Count(head);
            printf("\nNumber of Nodes: %d\n",iRet);
            break;

            case 0:
            printf("-------------------Thank you for using program--------------------");
            break;

            default:
            printf("Invalid Choice");

        }
    }
    return 0;
}

/*
=====================================================================

Sample Execution :

-------------------------------------------------------------------
Enter Your Choice:
-------------------------------------------------------------------
1: Insert Node at First Position:
2: Insert Node at Last Position:
3: Insert Node at Given Position:
4: Delete Node at First Position:
5: Delete Node at Last Position:
6: Delete Node at Given Position:
7: Display Node:
8: Count the Node:
0: Exit the Program!!!

Choice : 1
Enter the Value : 11

Choice : 1
Enter the Value : 21

Choice : 2
Enter the Value : 51

Choice : 7

| 21 | -> | 11 | -> | 51 | -> NULL

Choice : 8

Number of Nodes : 3

Choice : 0

-------------------Thank you for using program--------------------

Operations Demonstrated :

✓ InsertFirst()
✓ InsertLast()
✓ InsertAtPos()
✓ DeleteFirst()
✓ DeleteLast()
✓ DeleteAtPos()
✓ Display()
✓ Count()

Conclusion :

This program provides a complete Menu Driven
implementation of a Singly Linear Linked List.
It allows users to dynamically perform all
basic linked list operations efficiently through
an interactive console interface.

This serves as the final integrated version of
the Singly Linked List implementation in C.

=====================================================================
*/

/*
=====================================================================

Name            : Doubly Linear Linked List - Menu Driven Program
Program Number  : 019

Description     : This program implements a Doubly Linear Linked List
                  using dynamic memory allocation.

                  The program provides the following operations:

                  - Insert First
                  - Insert Last
                  - Insert At Position
                  - Delete First
                  - Delete Last
                  - Delete At Position
                  - Display
                  - Count

                  A menu-driven interface is provided to perform all
                  linked list operations interactively.

Concepts Used   : Doubly Linear Linked List,
                  Dynamic Memory Allocation,
                  Self-Referential Structure,
                  Pointer Manipulation,
                  Traversal,
                  Insertion,
                  Deletion,
                  Menu Driven Programming

Input           : User choice, node data, and position

Output          : Updated linked list and node count

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
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    while(1)
    {
        printf("\n-------------------------------------------------\n");
        printf("        Doubly Linear Linked List\n");
        printf("-------------------------------------------------\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert At Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete At Position\n");
        printf("7. Display\n");
        printf("8. Count\n");
        printf("0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d",&iValue);
                InsertFirst(&head,iValue);
                break;

            case 2:
                printf("Enter data : ");
                scanf("%d",&iValue);
                InsertLast(&head,iValue);
                break;

            case 3:
                printf("Enter data : ");
                scanf("%d",&iValue);

                printf("Enter position : ");
                scanf("%d",&iPos);

                InsertAtPos(&head,iValue,iPos);
                break;

            case 4:
                DeleteFirst(&head);
                break;

            case 5:
                DeletetLast(&head);
                break;

            case 6:
                printf("Enter position : ");
                scanf("%d",&iPos);

                DeletetAtPos(&head,iPos);
                break;

            case 7:
                Display(head);
                break;

            case 8:
                iRet = Count(head);
                printf("Number of nodes are : %d\n",iRet);
                break;

            case 0:
                printf("Thank you for using the application\n");
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

/*
=====================================================================

Sample Operations :

1. Insert First
2. Insert Last
3. Insert At Position
4. Delete First
5. Delete Last
6. Delete At Position
7. Display
8. Count
0. Exit

=====================================================================

Result :

Successfully implemented a Doubly Linear Linked List
with complete insertion, deletion, display, and count
operations using a menu-driven approach.

=====================================================================
*/

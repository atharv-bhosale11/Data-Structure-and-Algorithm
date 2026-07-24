/*
=====================================================================

Name            : Doubly Circular Linked List - Menu Driven Program
Program Number  : 011

Description     : This program demonstrates all basic operations
                  on a Doubly Circular Linked List using a
                  menu-driven approach.

                  Operations Supported:
                  - Insert First
                  - Insert Last
                  - Insert At Position
                  - Delete First
                  - Delete Last
                  - Delete At Position
                  - Display
                  - Count

Concepts Used   : Doubly Circular Linked List,
                  Dynamic Memory Allocation,
                  Menu Driven Programming,
                  Insertion Operations,
                  Deletion Operations,
                  Traversal

Input           : Node data and position values

Output          : Displays linked list contents and
                  performs requested operations

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
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE first, PNODE last)
{   
    if(first == NULL && last == NULL)
    {
        return;
    }


    printf("<=>");
    do
    {
        printf("| %d | <=> ",first -> data);
        first = first -> next;
    }while(first != last -> next);
    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
    {
        return 0;
    }
    
    do
    {
        iCount++;
        first = first -> next;
    } while (first != last -> next);
    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn -> next = *first;
        (*first )-> prev = newn;
        *first = newn;
    }
    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void InsertLast(PPNODE first, PPNODE last,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last) -> next = newn;
        newn -> prev = *last;
        *last = newn;
    }
    (*last) -> next = *first;
    (*first) -> prev = *last;
}

void InsertAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int i = 0;
    int iCount = 0;

    iCount = Count(*first,*last);

    if(iPos < 1 || iPos > iCount + 1)
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(first,last,iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(first,last,iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = *first;
        for(i = 1 ; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    }
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first) -> next;
        free((*first) -> prev);
        (*last) -> next = *first;
        (*first) -> prev = *last;
    }
}

void DeleteLast(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
       *last = (*last) -> prev;
       free ((*last) -> next);
       (*last) -> next = *first;
       (*first) -> prev = *last;
    }   
}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    PNODE temp = NULL;
    int i = 0;
    int iCount = 0;

    iCount = Count(*first,*last);

    if(iPos < 1 || iPos > iCount)
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        free (temp -> next -> prev);
        temp -> next -> prev = temp;
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    while(1)
    {
        printf("\n=================================================\n");
        printf("      Doubly Circular Linked List\n");
        printf("=================================================\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert At Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete At Position\n");
        printf("7. Display\n");
        printf("8. Count\n");
        printf("0. Exit\n");
        printf("=================================================\n");

        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d",&iValue);

                InsertFirst(&head,&tail,iValue);
                break;

            case 2:
                printf("Enter data : ");
                scanf("%d",&iValue);

                InsertLast(&head,&tail,iValue);
                break;

            case 3:
                printf("Enter data : ");
                scanf("%d",&iValue);

                printf("Enter position : ");
                scanf("%d",&iPos);

                InsertAtPos(&head,&tail,iValue,iPos);
                break;

            case 4:
                DeleteFirst(&head,&tail);
                printf("First node deleted successfully\n");
                break;

            case 5:
                DeleteLast(&head,&tail);
                printf("Last node deleted successfully\n");
                break;

            case 6:
                printf("Enter position : ");
                scanf("%d",&iPos);

                DeleteAtPos(&head,&tail,iPos);
                printf("Node deleted successfully\n");
                break;

            case 7:
                Display(head,tail);
                break;

            case 8:
                iRet = Count(head,tail);
                printf("Number of Nodes : %d\n",iRet);
                break;

            case 0:
                printf("Thank you for using the application\n");
                return 0;

            default:
                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

/*
=====================================================================

Output :

=================================================
      Doubly Circular Linked List
=================================================
1. Insert First
2. Insert Last
3. Insert At Position
4. Delete First
5. Delete Last
6. Delete At Position
7. Display
8. Count
0. Exit
=================================================

Enter your choice : 1
Enter data : 11

Enter your choice : 2
Enter data : 21

Enter your choice : 7

<=>| 11 | <=> | 21 | <=>

Enter your choice : 8

Number of Nodes : 2

=====================================================================
*/

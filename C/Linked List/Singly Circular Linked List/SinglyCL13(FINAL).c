/*
=====================================================================

Name            : Singly Circular Linked List - Menu Driven Program
Program Number  : 013

Description     : This program demonstrates all basic operations
                  of Singly Circular Linked List using a
                  menu-driven approach.

Operations       :
                  1. Insert First
                  2. Insert Last
                  3. Insert At Position
                  4. Delete First
                  5. Delete Last
                  6. Delete At Position
                  7. Display
                  8. Count

Concepts Used   : Dynamic Memory Allocation,
                  Self-Referential Structure,
                  Singly Circular Linked List,
                  Menu Driven Programming

Input           : Node data and position

Output          : Updated circular linked list after
                  insertion and deletion operations

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Singly Circular Linked List

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

void Display(PNODE first, PNODE last)
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    
    do
    {
        printf(" |%d| -> ",first -> data);
        first = first -> next;
    }while(first != last -> next);
    printf("\n");
}


int count(PNODE first, PNODE last)
{
    int iCount = 0;
    if(first == NULL && last == NULL)
    {
        return iCount;
    }

    do
    {
        iCount++;
        first = first -> next;
    }while(first != last -> next);
    
    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }
    (*last) -> next = *first;
}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        (*last) -> next = newn;
        *last = (*last) -> next;
    }
    (*last) -> next = *first;
}

void InsertAtPos(PPNODE first, PPNODE last, int iPos, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = 0;
    int i = 0;

    iCount = count(*first,*last);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Invalid Positions");
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

        temp = *first;

        for(i = 1 ; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        
        newn -> next = temp -> next;
        temp -> next = newn;
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

        free((*last) -> next);                      // without "temp" variable

        (*last) -> next = *first;
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
        PNODE temp = NULL;
        
        temp = *first;

        while(temp -> next != *last)
        {
            temp = temp -> next;
        }
        free(*last);                        // also write free(temp -> next);
        *last = temp;
        (*last) -> next = *first;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCount = 0;
    int i = 0;

    iCount = count(*first,*last);

    if(iPos < 1 || iPos > iCount)
    {
        printf("Invalid Positions\n");
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

        for(i = 1; i < iPos - 1 ; i++)
        {
            temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = target -> next;
        free(target);
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
        printf("        Singly Circular Linked List\n");
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

                InsertAtPos(&head,&tail,iPos,iValue);
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
                break;

            case 7:
                Display(head,tail);
                break;

            case 8:
                iRet = count(head,tail);
                printf("Number of Nodes are : %d\n",iRet);
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

Sample Output

=================================================
        Singly Circular Linked List
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

Enter your choice : 2
Enter data : 31

Enter your choice : 7

|11| -> |21| -> |31| ->

Enter your choice : 8

Number of Nodes are : 3

Enter your choice : 0

Thank you for using the application

=====================================================================
End of Program
=====================================================================
*/

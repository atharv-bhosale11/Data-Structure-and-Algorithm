/*
=====================================================================

Name            : Doubly Circular Linked List - InsertAtPos Function
Program Number  : 009

Description     : This program demonstrates insertion of
                  a node at a specific position in a
                  Doubly Circular Linked List.

                  InsertAtPos() validates the position,
                  traverses the list, and inserts the
                  new node while maintaining both next
                  and prev links.

Concepts Used   : Doubly Circular Linked List,
                  InsertAtPos Operation,
                  Position Validation,
                  Dynamic Memory Allocation,
                  Pointer Manipulation

Input           : Node data and position

Output          : Displays linked list before and after
                  insertion along with total node count

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Doubly Circular Linked list

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
        DeleteFirst(first,last);
    }
    else if(iPos == iCount + 1)
    {
        DeleteLast(first,last);
    }
    else
    {
       
    }
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);

    DeleteFirst(&head,&tail);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);   
    
    DeleteLast(&head,&tail);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);   

    InsertAtPos(&head,&tail,105,4);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);  
    
    DeleteAtPos(&head,&tail,4);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);  

    return 0;
}

/*
=====================================================================

Sample Output :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of Nodes : 6

After DeleteFirst()

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>
Number of Nodes : 5

After DeleteLast()

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>
Number of Nodes : 4

After InsertAtPos(105,4)

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 105 | <=> | 111 | <=>
Number of Nodes : 5

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. InsertAtPos()
6. DeleteFirst()
7. DeleteLast()

Pending Functions :

1. DeleteAtPos()

=====================================================================

Notes :

1. InsertAtPos() inserts a node at any valid position.
2. Position validation is performed before insertion.
3. InsertFirst() is called for position 1.
4. InsertLast() is called for last position.
5. Both next and prev links are updated correctly.
6. Circular structure remains intact after insertion.

=====================================================================

Time Complexity :

InsertAtPos() : O(N)
Display()     : O(N)
Count()       : O(N)

=====================================================================

End of Program

=====================================================================
*/

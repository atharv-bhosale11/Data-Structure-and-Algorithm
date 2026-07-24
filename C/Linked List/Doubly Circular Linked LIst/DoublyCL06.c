/*
=====================================================================

Name            : Doubly Circular Linked List - Count Function
Program Number  : 006

Description     : This program demonstrates counting the
                  number of nodes present in a Doubly
                  Circular Linked List.

                  Display() traverses and displays the
                  linked list while Count() returns the
                  total number of nodes.

Concepts Used   : Doubly Circular Linked List,
                  Count Function,
                  Display Function,
                  do-while Loop,
                  Dynamic Memory Allocation

Input           : Node data

Output          : Displays linked list and total number
                  of nodes

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

}

void DeleteFirst(PPNODE first, PPNODE last)
{

}

void DeleteLast(PPNODE first, PPNODE last)
{

}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{

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

    return 0;
}

/*
=====================================================================

Sample Output :

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=>

Number of Nodes : 6

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()

Pending Functions :

1. InsertAtPos()
2. DeleteFirst()
3. DeleteLast()
4. DeleteAtPos()

=====================================================================

Notes :

1. Count uses a do-while loop.
2. Traversal starts from the first node.
3. Each node is counted exactly once.
4. Suitable for circular linked list traversal.
5. Returns total number of nodes present.

=====================================================================
End of Program
=====================================================================
*/

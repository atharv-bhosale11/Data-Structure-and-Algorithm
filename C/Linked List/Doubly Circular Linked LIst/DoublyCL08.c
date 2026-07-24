/*
=====================================================================

Name            : Doubly Circular Linked List - DeleteLast Function
Program Number  : 008

Description     : This program demonstrates deletion of
                  the last node from a Doubly Circular
                  Linked List.

                  DeleteLast() removes the last node,
                  updates the tail pointer and maintains
                  the circular links between the first
                  and last nodes.

                  Display() traverses and displays the
                  linked list while Count() returns the
                  total number of nodes.

Concepts Used   : Doubly Circular Linked List,
                  DeleteLast Operation,
                  Tail Node Deletion,
                  Circular Linking,
                  Dynamic Memory Allocation

Input           : Node data

Output          : Displays linked list before and after
                  deletion of the last node along with
                  total node count

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

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. DeleteFirst()
6. DeleteLast()

Pending Functions :

1. InsertAtPos()
2. DeleteAtPos()

=====================================================================

Notes :

1. DeleteLast() removes the last node from the list.
2. The last pointer is moved to the previous node.
3. The old last node is deallocated using free().
4. Circular links are re-established after deletion.
5. last->next always points to first.
6. first->prev always points to last.
7. Handles empty list and single-node list cases.

=====================================================================

Time Complexity :

DeleteLast()  : O(1)
Display()     : O(N)
Count()       : O(N)

=====================================================================

End of Program

=====================================================================
*/

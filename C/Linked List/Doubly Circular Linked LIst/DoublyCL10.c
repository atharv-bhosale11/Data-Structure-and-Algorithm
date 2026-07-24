/*
=====================================================================

Name            : Doubly Circular Linked List - DeleteAtPos Function
Program Number  : 010

Description     : This program demonstrates deletion of
                  a node from a specified position in a
                  Doubly Circular Linked List.

                  DeleteAtPos() validates the given
                  position and removes the node while
                  maintaining both next and prev links
                  of the surrounding nodes.

                  Special cases such as deletion of the
                  first node and last node are handled
                  using DeleteFirst() and DeleteLast().

Concepts Used   : Doubly Circular Linked List,
                  DeleteAtPos Operation,
                  Position Validation,
                  Dynamic Memory Allocation,
                  Pointer Manipulation

Input           : Position of node to be deleted

Output          : Displays linked list before and after
                  deletion along with total node count

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

After DeleteAtPos(4)

<=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>
Number of Nodes : 4

=====================================================================

Functions Implemented :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. InsertAtPos()
6. DeleteFirst()
7. DeleteLast()
8. DeleteAtPos()

=====================================================================

Notes :

1. DeleteAtPos() removes a node from any valid position.
2. Position validation is performed before deletion.
3. DeleteFirst() is called for position 1.
4. DeleteLast() is called for the last position.
5. Both next and prev links are updated correctly.
6. Circular structure remains intact after deletion.
7. Dynamically allocated memory is released using free().

=====================================================================

Time Complexity :

DeleteAtPos() : O(N)
Display()     : O(N)
Count()       : O(N)

=====================================================================

End of Program

=====================================================================
*/

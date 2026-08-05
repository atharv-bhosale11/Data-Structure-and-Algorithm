/*
===============================================================================
Program Name    : Complete Stack Application
Program Number  : 006
File Name       : Stack06.c

Description     : This program demonstrates complete Stack
                  implementation using Singly Linear Linked
                  List with Push, Pop, Peep, Display and
                  Count operations.

Date            : August 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Push
// Description   : Insert element at First
//
///////////////////////////////////////////////////////////////////////////////

void Push(PPNODE first,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = *first;

    *first = newn;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Pop
// Description   : Delete element from First
//
///////////////////////////////////////////////////////////////////////////////

int Pop(PPNODE first)
{
    PNODE temp = NULL;
    int iValue = 0;

    if(*first == NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }

    iValue = (*first)->data;

    temp = *first;
    *first = (*first)->next;

    free(temp);

    return iValue;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Peep
// Description   : Return First Element without deleting
//
///////////////////////////////////////////////////////////////////////////////

int Peep(PNODE first)
{
    if(first == NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }

    return first->data;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Display Stack Elements
//
///////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("|%d|\n",first->data);
        first = first->next;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Count number of elements
//
///////////////////////////////////////////////////////////////////////////////

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Push(&head,11);
    Push(&head,21);
    Push(&head,51);
    Push(&head,101);

    Display(head);

    iRet = Count(head);
    printf("Number of Elements : %d\n",iRet);

    iRet = Pop(&head);
    printf("Removed Element : %d\n",iRet);

    Display(head);

    iRet = Peep(head);
    printf("Peep Element : %d\n",iRet);

    iRet = Count(head);
    printf("Number of Elements : %d\n",iRet);

    return 0;
}

/*
===============================================================================
Sample Output

|101|
|51|
|21|
|11|

Number of Elements : 4

Removed Element : 101

|51|
|21|
|11|

Peep Element : 51

Number of Elements : 3

===============================================================================
End of Program
===============================================================================
*/

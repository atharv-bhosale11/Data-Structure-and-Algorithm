/*
===============================================================================
Program Name    : Queue Menu Driven Application
Program Number  : 007
File Name       : Queue07.c

Description     : This program demonstrates a complete
                  Menu Driven Queue using Singly Linear
                  Linked List.

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
// Function Name : Enqueue
// Description   : Insert element at Last
//
///////////////////////////////////////////////////////////////////////////////

void Enqueue(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Dequeue
// Description   : Delete element from First
//
///////////////////////////////////////////////////////////////////////////////

int Dequeue(PPNODE first)
{
    PNODE temp = NULL;
    int iValue = 0;

    if(*first == NULL)
    {
        printf("Queue is Empty\n");
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
// Function Name : Display
// Description   : Display Queue
//
///////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    printf("\nQueue Elements :\n");

    while(first != NULL)
    {
        printf("|%d| -> ",first->data);
        first = first->next;
    }

    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Count number of nodes
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

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    printf("-------------------------------------------------\n");
    printf("          Queue Menu Driven Application\n");
    printf("-------------------------------------------------\n");

    while(1)
    {
        printf("\n-------------------------------------------------\n");
        printf("\n---------------------QUEUE-----------------------\n");
        printf("\n-------------------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("-------------------------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:

                printf("Enter the data : ");
                scanf("%d",&iValue);

                Enqueue(&head,iValue);

                printf("Element inserted successfully\n");
                break;

            case 2:

                iRet = Dequeue(&head);

                if(iRet != -1)
                {
                    printf("Removed Element : %d\n",iRet);
                }
                break;

            case 3:

                Display(head);
                break;

            case 4:

                iRet = Count(head);

                printf("Number of Elements : %d\n",iRet);
                break;

            case 5:

                printf("Thank you for using Queue Application\n");
                return 0;

            default:

                printf("Invalid Choice\n");
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Sample Output
-------------------------------------------------
---------------------QUEUE-----------------------
-------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
-------------------------------------------------

Enter your choice : 1
Enter the data : 11

Enter your choice : 1
Enter the data : 21

Enter your choice : 3

Queue Elements :
|11| -> |21| -> NULL

Enter your choice : 2

Removed Element : 11

Queue Elements :
|21| -> NULL

===============================================================================
End of Program
===============================================================================
*/

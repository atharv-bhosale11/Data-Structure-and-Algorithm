/*
===============================================================================
Program Name    : Stack Menu Driven Application
Program Number  : 007
File Name       : Stack07.c

Description     : This program demonstrates a complete
                  Menu Driven Stack using Singly Linear
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
    printf("\nStack Elements :\n");

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

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    printf("-------------------------------------------------\n");
    printf("          Stack Menu Driven Application\n");
    printf("-------------------------------------------------\n");

    while(1)
    {
        printf("\n-------------------------------------------------\n");
        printf("---------------------STACK-----------------------\n");
        printf("-------------------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("-------------------------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:

                printf("Enter the data : ");
                scanf("%d",&iValue);

                Push(&head,iValue);

                printf("Element inserted successfully\n");
                break;

            case 2:

                iRet = Pop(&head);

                if(iRet != -1)
                {
                    printf("Removed Element : %d\n",iRet);
                }
                break;

            case 3:

                iRet = Peep(head);

                if(iRet != -1)
                {
                    printf("Top Element : %d\n",iRet);
                }
                break;

            case 4:

                Display(head);
                break;

            case 5:

                iRet = Count(head);

                printf("Number of Elements : %d\n",iRet);
                break;

            case 6:

                printf("Thank you for using Stack Application\n");
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

1. Push
2. Pop
3. Peep
4. Display
5. Count
6. Exit

Enter your choice : 1
Enter the data : 11

Enter your choice : 1
Enter the data : 21

Enter your choice : 1
Enter the data : 51

Enter your choice : 4

Stack Elements :

|51|
|21|
|11|

Enter your choice : 3

Top Element : 51

Enter your choice : 2

Removed Element : 51

Enter your choice : 4

Stack Elements :

|21|
|11|

Enter your choice : 5

Number of Elements : 2

Enter your choice : 6

Thank you for using Stack Application

===============================================================================
End of Program
===============================================================================
*/

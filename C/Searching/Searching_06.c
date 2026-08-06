/*
===============================================================================
Program Name    : Searching Menu Driven Application
Program Number  : 006
File Name       : Searching06.c

Description     : This program demonstrates a complete
                  Menu Driven Searching Application.

                  Operations:
                  1. Accept Elements
                  2. Display Elements
                  3. Linear Search
                  4. Bi-Directional Search

Date            : August 2026
Language        : C
Author          : Atharv Tushar Bhosale
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct Searching
{
    int *Arr;
    int iSize;
};

typedef struct Searching SEARCHING;
typedef struct Searching* PSEARCHING;

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Accept
//
///////////////////////////////////////////////////////////////////////////////

void Accept(PSEARCHING first)
{
    int i = 0;

    printf("Enter the Elements:\n");

    for(i = 0; i < first->iSize; i++)
    {
        scanf("%d",&first->Arr[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
//
///////////////////////////////////////////////////////////////////////////////

void Display(PSEARCHING first)
{
    int i = 0;

    printf("\nElements of the Array are:\n");

    for(i = 0; i < first->iSize; i++)
    {
        printf("%d\n",first->Arr[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinearSearch
//
///////////////////////////////////////////////////////////////////////////////

int LinearSearch(PSEARCHING first,int iNo)
{
    int i = 0;

    for(i = 0; i < first->iSize; i++)
    {
        if(first->Arr[i] == iNo)
        {
            return 1;
        }
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : BiDirectionalSearch
//
///////////////////////////////////////////////////////////////////////////////

int BiDirectionalSearch(PSEARCHING first,int iNo)
{
    int iStart = 0;
    int iEnd = first->iSize - 1;

    while(iStart <= iEnd)
    {
        if((first->Arr[iStart] == iNo) || (first->Arr[iEnd] == iNo))
        {
            return 1;
        }

        iStart++;
        iEnd--;
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    SEARCHING sobj;

    int iChoice = 0;
    int iRet = 0;
    int iValue = 0;

    printf("Enter the Number of Elements : ");
    scanf("%d",&sobj.iSize);

    sobj.Arr = (int *)malloc(sizeof(int) * sobj.iSize);

    while(1)
    {
        printf("\n-------------------------------------------------\n");
        printf("------------------ SEARCHING --------------------\n");
        printf("-------------------------------------------------\n");
        printf("1. Accept Elements\n");
        printf("2. Display Elements\n");
        printf("3. Linear Search\n");
        printf("4. Bi-Directional Search\n");
        printf("5. Exit\n");
        printf("-------------------------------------------------\n");

        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:

                Accept(&sobj);
                break;

            case 2:

                Display(&sobj);
                break;

            case 3:

                printf("Enter Element to Search : ");
                scanf("%d",&iValue);

                iRet = LinearSearch(&sobj,iValue);

                if(iRet == 1)
                {
                    printf("Element is Present\n");
                }
                else
                {
                    printf("Element is Absent\n");
                }
                break;

            case 4:

                printf("Enter Element to Search : ");
                scanf("%d",&iValue);

                iRet = BiDirectionalSearch(&sobj,iValue);

                if(iRet == 1)
                {
                    printf("Element is Present\n");
                }
                else
                {
                    printf("Element is Absent\n");
                }
                break;

            case 5:

                free(sobj.Arr);

                printf("Thank you for using Searching Application\n");
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

Enter the Number of Elements : 5

1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit

Enter your choice : 1

Enter the Elements:
10
20
30
40
50

Enter your choice : 2

Elements of the Array are:
10
20
30
40
50

Enter your choice : 3

Enter Element to Search : 30

Element is Present

Enter your choice : 4

Enter Element to Search : 50

Element is Present

===============================================================================
End of Program
===============================================================================
*/

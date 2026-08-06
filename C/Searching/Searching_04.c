/*
===============================================================================
Program Name    : Bi-Directional Search      
Program Number  : 004
File Name       : Searching04.c

Description     : This program accepts elements from user,
                  displays them and performs Bi-Directional
                  Search.

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
// Description   : Accept elements from user
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
// Description   : Display elements of array
//
///////////////////////////////////////////////////////////////////////////////

void Display(PSEARCHING first)
{
    int i = 0;

    printf("Elements of the Array are:\n");

    for(i = 0; i < first->iSize; i++)
    {
        printf("%d\n",first->Arr[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : BiDirectionalSearch
// Description   : Search element using Bi-Directional Search
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
    int iRet = 0;

    sobj.iSize = 5;
    sobj.Arr = (int *)malloc(sizeof(int) * sobj.iSize);

    Accept(&sobj);
    Display(&sobj);

    iRet = BiDirectionalSearch(&sobj,30);

    if(iRet == 1)
    {
        printf("Element is Present\n");
    }
    else
    {
        printf("There is no such element\n");
    }

    free(sobj.Arr);

    return 0;
}

/*
===============================================================================
Sample Output

Enter the Elements:
10
20
30
40
50

Elements of the Array are:
10
20
30
40
50

Element is Present

===============================================================================
End of Program
===============================================================================
*/

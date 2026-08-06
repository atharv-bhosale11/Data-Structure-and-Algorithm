/*
===============================================================================
Program Name    : Accept and Display Array
Program Number  : 002
File Name       : Searching02.c

Description     : This program accepts elements from user
                  and displays them using Array.    

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
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    SEARCHING sobj;

    sobj.iSize = 5;
    sobj.Arr = (int *)malloc(sizeof(int) * sobj.iSize);

    Accept(&sobj);
    Display(&sobj);

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

===============================================================================
End of Program
===============================================================================
*/

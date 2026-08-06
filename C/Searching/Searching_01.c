/*
===============================================================================
Program Name    : Searching Skeleton
Program Number  : 001
File Name       : Searching01.c

Description     : Basic Skeleton Program for Searching Techniques.

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

void Accept(PSEARCHING ptr)
{
}

void Display(PSEARCHING ptr)
{
}

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
Output :

(No Output)

===============================================================================
End of Program
===============================================================================
*/

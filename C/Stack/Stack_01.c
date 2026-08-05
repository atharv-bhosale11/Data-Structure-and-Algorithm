/*
===============================================================================
Program Name    : Stack Skeleton
Program Number  : 001
File Name       : Stack01.c

Description     : Basic Stack Structure Declaration.

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

int main()
{
    PNODE head = NULL;

    return 0;
}

/*
===============================================================================
End of Program
===============================================================================
*/

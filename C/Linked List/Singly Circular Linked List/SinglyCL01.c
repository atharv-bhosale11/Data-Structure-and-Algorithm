/*
=====================================================================

Name            : Singly Circular Linked List - Skeleton Program
Program Number  : 001

Description     : This program provides the basic structure
                  required for implementing a Singly Circular
                  Linked List in C.

                  It includes:
                  - Node structure
                  - Function declarations
                  - Head and Tail pointers
                  - Linked List operation prototypes

Concepts Used   : Structure,
                  Self Referential Structure,
                  Pointer,
                  Function Prototype,
                  Dynamic Memory Allocation

Input           : N/A

Output          : N/A

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Singly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Display(PNODE first, PNODE last)
{}

int Count(PNODE first, PNODE last)
{
    return 0;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{}

void InsertAtPos(PPNODE first, PPNODE last, int iPos, int iNo)
{}

void DeleteFirst(PPNODE first, PPNODE last)
{}

void DeleteLast(PPNODE first, PPNODE last)
{}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    return 0;
}

/*
=====================================================================

Program Summary :

-> Defined node structure
-> Created typedefs for node pointers
-> Declared all linked list operations
-> Initialized head and tail pointers
-> Prepared basic framework for Singly Circular Linked List

=====================================================================
*/

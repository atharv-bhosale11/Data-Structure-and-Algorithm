/*
=====================================================================

Name            : Doubly Linked List - Function Skeleton
Program Number  : 009
Description     : This program provides the basic framework of a
                  Doubly Linked List. All major operations are
                  declared and defined with empty function bodies.

                  This skeleton serves as a foundation for future
                  implementation of insertion, deletion, display,
                  and counting operations.

Concepts Used   : Doubly Linked List, Function Prototypes,
                  Function Definitions, Self-Referential Structure,
                  Pointer to Pointer, Modular Programming

Input           : None

Output          : None

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

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

void Display(PNODE first)
{

}

int Count(PNODE first)
{
    return 0;
}

void InsertFirst(PPNODE first, int iNo)
{

}

void InsertLast(PPNODE first, int iNo)
{

}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{

}

void DeleteLast(PPNODE first)
{

}

void DeleteAtPos(PPNODE first, int iPos)
{

}

int main()
{
    PNODE head = NULL;

    return 0;
}

/*
=====================================================================

Functions Included :

1. Display()
2. Count()
3. InsertFirst()
4. InsertLast()
5. InsertAtPos()
6. DeleteFirst()
7. DeleteLast()
8. DeleteAtPos()

=====================================================================

Note :

- All functions are currently empty.
- This program establishes the complete structure of
  a Doubly Linked List implementation.
- Individual functions will be implemented in the
  upcoming programs.
- Pointer-to-pointer technique is used for insertion
  and deletion operations.

=====================================================================
*/

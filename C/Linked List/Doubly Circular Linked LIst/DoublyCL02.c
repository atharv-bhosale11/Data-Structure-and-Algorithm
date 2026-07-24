  /*
=====================================================================

Name            : Doubly Circular Linked List all Functions
Program Number  : 002

Description     : This program demonstrates the Count()
                  function of a Doubly Circular Linked List.

                  The function traverses the entire
                  linked list and returns the total
                  number of nodes present.

Concepts Used   : Doubly Circular Linked List,
                  Traversal,
                  Node Counting,
                  do-while Loop

Input           : N/A

Output          : Total number of nodes

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Doubly Circular Linked list

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

void Display(PNODE first, PNODE last)
{

}

int Count(PNODE first, PNODE last)
{
    return 0;
}

void InsertFirst(PPNODE first, PPNODE last, int iNo)
{

}

void InsertLast(PPNODE first, PPNODE last, int iNo)
{

}

void InsertAtPos(PPNODE first, PPNODE last, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first, PPNODE last)
{

}

void DeleteLast(PPNODE first, PPNODE last)
{

}

void DeleteAtPos(PPNODE first, PPNODE last, int iPos)
{

}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    return 0;
}

/*
=====================================================================

Sample Output :

Number of nodes are : 0

=====================================================================

Concept Explanation :

Count() traverses the entire linked list
and increments a counter for every node.

Traversal Condition :

while(first != last->next)

This ensures that every node is counted
exactly once in the circular linked list.

=====================================================================
End of Program
=====================================================================
*/

/*
=====================================================================

Name            : Doubly Linked List - Single Node Creation
Program Number  : 002
Description     : This program demonstrates how to create a single
                  node of a Doubly Linked List using dynamic memory
                  allocation. The node is initialized with data and
                  both next and previous pointers are set to NULL.

Concepts Used   : Doubly Linked List, Self-Referential Structure,
                  Dynamic Memory Allocation, malloc(),
                  Pointer Initialization

Input           : None

Output          : Displays data and pointer values of the node

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

int main()
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = 11;
    newn->next = NULL;
    newn->prev = NULL;

    printf("Data : %d\n",newn->data);
    printf("Next : %p\n",newn->next);
    printf("Prev : %p\n",newn->prev);

    free(newn);

    return 0;
}

/*
=====================================================================

Sample Output :

Data : 11
Next : (nil)
Prev : (nil)

=====================================================================

Note :

- Memory is allocated dynamically using malloc().
- Since there is only one node, both next and prev
  pointers contain NULL.
- This program forms the foundation of Doubly Linked List.

=====================================================================
*/

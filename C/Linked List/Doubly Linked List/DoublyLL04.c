/*
=====================================================================

Name            : Doubly Linked List - Three Nodes Linking
Program Number  : 004
Description     : This program demonstrates creation of three nodes
                  in a Doubly Linked List and links them using
                  next and prev pointers.

                  The nodes are connected in sequence and accessed
                  through the first node.

Concepts Used   : Doubly Linked List, Self-Referential Structure,
                  Dynamic Memory Allocation, Pointer Linking,
                  Forward Traversal, Bidirectional Linking

Input           : None

Output          : Displays data of all three linked nodes

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
    PNODE first = NULL;
    PNODE second = NULL;
    PNODE third = NULL;

    first = (PNODE)malloc(sizeof(NODE));
    second = (PNODE)malloc(sizeof(NODE));
    third = (PNODE)malloc(sizeof(NODE));

    first->data = 11;
    first->next = second;
    first->prev = NULL;

    second->data = 21;
    second->next = third;
    second->prev = first;

    third->data = 51;
    third->next = NULL;
    third->prev = second;

    printf("%d\n", first->data);
    printf("%d\n", first->next->data);
    printf("%d\n", first->next->next->data);

    free(first);
    free(second);
    free(third);

    return 0;
}

/*
=====================================================================

Sample Output :

11
21
51

=====================================================================

Node Representation :

NULL <- |11| <=> |21| <=> |51| -> NULL

=====================================================================

Note :

- Three nodes are dynamically created.
- next pointers connect nodes in forward direction.
- prev pointers connect nodes in backward direction.
- Data is accessed through the first node.

=====================================================================
*/

/*
=====================================================================

Name            : Doubly Linked List - Two Nodes Linking
Program Number  : 003
Description     : This program demonstrates creation of two nodes
                  in a Doubly Linked List and establishes links
                  between them using next and prev pointers.

                  The first node points to the second node through
                  the next pointer, while the second node points
                  back to the first node through the prev pointer.

Concepts Used   : Doubly Linked List, Self-Referential Structure,
                  Dynamic Memory Allocation, Pointer Linking,
                  Forward Link, Backward Link

Input           : None

Output          : Displays data of both nodes using links

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

    first = (PNODE)malloc(sizeof(NODE));
    second = (PNODE)malloc(sizeof(NODE));

    first->data = 11;
    first->next = second;
    first->prev = NULL;

    second->data = 21;
    second->next = NULL;
    second->prev = first;

    printf("First Node Data  : %d\n", first->data);
    printf("Second Node Data : %d\n", first->next->data);

    free(first);
    free(second);

    return 0;
}

/*
=====================================================================

Sample Output :

First Node Data  : 11
Second Node Data : 21

=====================================================================

Node Representation :

NULL <- |11| <=> |21| -> NULL

=====================================================================

Note :

- first->next stores address of second node.
- second->prev stores address of first node.
- This creates a bidirectional connection between nodes.
- Doubly Linked List supports traversal in both directions.

=====================================================================
*/

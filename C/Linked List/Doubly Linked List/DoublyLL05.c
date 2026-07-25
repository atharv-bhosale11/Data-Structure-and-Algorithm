/*
=====================================================================

Name            : Doubly Linked List - Traversal Using Head Pointer
Program Number  : 005
Description     : This program demonstrates traversal of a Doubly
                  Linked List using the head pointer. The head is
                  moved from one node to the next node using the
                  next pointer until the end of the list is reached.

Concepts Used   : Doubly Linked List, Dynamic Memory Allocation,
                  Pointer Traversal, Head Pointer Manipulation,
                  next Pointer

Input           : None

Output          : Displays all node elements

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

    printf("%d\n",first->data);

    first = first->next;

    printf("%d\n",first->data);

    first = first->next;

    printf("%d\n",first->data);

    free(first);

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

- The head pointer is moved to traverse the list.
- Original address of first node is lost during traversal.
- This method is useful for understanding traversal logic.
- A temporary pointer is generally preferred in practice.

=====================================================================
*/

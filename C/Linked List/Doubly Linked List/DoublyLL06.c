/*
=====================================================================

Name            : Doubly Linked List - Traversal Using Temporary Pointer
Program Number  : 006
Description     : This program demonstrates traversal of a Doubly
                  Linked List using a temporary pointer. The original
                  head pointer remains unchanged while the temporary
                  pointer moves through the list.

Concepts Used   : Doubly Linked List, Dynamic Memory Allocation,
                  Temporary Pointer, Pointer Traversal,
                  next Pointer, Data Access

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
    PNODE temp = NULL;

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

    temp = first;

    printf("%d\n",temp->data);

    temp = temp->next;

    printf("%d\n",temp->data);

    temp = temp->next;

    printf("%d\n",temp->data);

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

- Temporary pointer is used for traversal.
- Original head pointer remains unchanged.
- This is the preferred method for traversing a linked list.
- It preserves access to the entire list after traversal.

=====================================================================
*/x  

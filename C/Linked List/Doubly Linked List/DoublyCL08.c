/*
=====================================================================

Name            : Doubly Linked List - Display Function
Program Number  : 008
Description     : This program demonstrates creation of a Display()
                  function for a Doubly Linked List. The function
                  traverses the list and displays all elements in
                  a formatted manner.

Concepts Used   : Doubly Linked List, User Defined Function,
                  Pointer Traversal, While Loop,
                  Function Calling

Input           : None

Output          : Displays all elements of the Doubly Linked List

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

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | <=> ",first->data);
        first = first->next;
    }

    printf("NULL\n");
}

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

    Display(first);

    free(first);
    free(second);
    free(third);

    return 0;
}

/*
=====================================================================

Sample Output :

| 11 | <=> | 21 | <=> | 51 | <=> NULL

=====================================================================

Node Representation :

NULL <- |11| <=> |21| <=> |51| -> NULL

=====================================================================

Note :

- Display() is a reusable function.
- The function traverses the entire list.
- Elements are displayed in forward direction.
- Original head pointer remains unchanged in main().

=====================================================================
*/

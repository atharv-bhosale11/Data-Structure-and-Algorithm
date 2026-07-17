/*
=====================================================================

Name            : Doubly Linked List - Traversal Using While Loop
Program Number  : 007
Description     : This program demonstrates traversal of a Doubly
                  Linked List using a while loop. A temporary pointer
                  starts from the first node and visits every node
                  until it becomes NULL.

Concepts Used   : Doubly Linked List, Dynamic Memory Allocation,
                  While Loop, Temporary Pointer,
                  Linked List Traversal

Input           : None

Output          : Displays all node elements sequentially

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

    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }

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

- Temporary pointer starts from first node.
- While loop continues until temp becomes NULL.
- This is the standard technique used for traversal.
- The logic will later be used inside Display() function.

=====================================================================
*/

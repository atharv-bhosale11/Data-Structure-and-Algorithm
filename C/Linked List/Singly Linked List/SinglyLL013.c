/*
=====================================================================

Program Name    : Singly Linked List - Counting Nodes
Program Number  : 013
Description     : This program demonstrates how to count the number
                  of nodes in a singly linked list using iterative
                  traversal. A temporary pointer is used to visit
                  each node, and a counter is incremented during
                  every iteration.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Head Pointer,
                  Temporary Pointer, While Loop,
                  Node Counting

Input           : None

Output          : Displays the total number of nodes
                  present in the linked list.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<stdio.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

int main()
{
    PNODE head = NULL;
    PNODE temp = NULL;
    NODE obj1, obj2, obj3;
    int iCount = 0;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    temp = head;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }

    printf("Number of Nodes are : %d", iCount);

    return 0;
}

/*
=====================================================================

Expected Output :

Number of Nodes are : 3

Explanation :
A temporary pointer is initialized with the address
stored in head. The linked list is traversed node
by node using a while loop.

For every node visited:
1. The counter variable is incremented.
2. The pointer moves to the next node.

Traversal Sequence :

Node 1 -> Count = 1
Node 2 -> Count = 2
Node 3 -> Count = 3
NULL   -> Stop Traversal

Operations Performed :
1. Created and linked three nodes.
2. Initialized a counter variable.
3. Traversed the linked list.
4. Counted each visited node.
5. Displayed the final node count.

Conclusion :
Node counting is performed by traversing the entire
linked list and incrementing a counter for every
node encountered. This technique is widely used in
linked list operations and validations.

=====================================================================
*/

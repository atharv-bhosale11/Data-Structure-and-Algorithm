/*
=====================================================================

Program Name    : Singly Linked List - Dynamic Node Creation
Program Number  : 014
Description     : This program demonstrates how to create a node
                  dynamically using malloc(). The node is allocated
                  memory from the heap, initialized with data, and
                  accessed through a pointer.

Concepts Used   : Structure, Self-Referential Structure,
                  Dynamic Memory Allocation,
                  malloc(), Heap Memory,
                  Pointer Operations

Input           : None

Output          : Displays the data stored in the dynamically
                  allocated node.

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
};

typedef struct node NODE;
typedef struct node *PNODE;

int main()
{
    struct node *newn = NULL;

    newn = (struct node *)malloc(sizeof(struct node));

    newn->data = 11;
    newn->next = NULL;

    printf("%d", newn->data);

    return 0;
}

/*
=====================================================================

Expected Output :

11

Explanation :
A node is dynamically created using malloc().
The malloc() function allocates memory from the
heap section and returns the starting address of
the allocated memory block.

newn = malloc(sizeof(struct node));

After successful allocation:
1. The data member is initialized to 11.
2. The next pointer is initialized to NULL.
3. The stored data is displayed.

Memory Representation :

newn
 |
 v
+------+------+
|  11  | NULL |
+------+------+

Operations Performed :
1. Allocated memory for a node dynamically.
2. Stored the returned address in a pointer.
3. Initialized node members.
4. Accessed node data using the arrow operator.
5. Displayed the stored value.

Conclusion :
Dynamic memory allocation allows linked list nodes
to be created during program execution, making the
linked list flexible and capable of growing or
shrinking as needed.

=====================================================================
*/

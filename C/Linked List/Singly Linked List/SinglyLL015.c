/*
=====================================================================

Program Name    : Singly Linked List - Count Nodes Using Function
Program Number  : 015
Description     : This program demonstrates how to count the number
                  of nodes in a singly linked list using a separate
                  function. The head pointer is passed to the
                  function, which traverses the list and returns
                  the total node count.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Function Call,
                  Pointer Traversal, Node Counting

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

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    NODE obj1, obj2, obj3;
    int iRet = 0;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    iRet = Count(head);

    printf("Number of Nodes are : %d", iRet);

    return 0;
}

/*
=====================================================================

Expected Output :

Number of Nodes are : 3

Explanation :
The Count() function receives the address of the
first node through the parameter 'first'.

A local traversal pointer (first) moves through
the linked list until NULL is encountered.
For every node visited, the counter variable is
incremented.

Traversal Sequence :

11 -> Count = 1
21 -> Count = 2
51 -> Count = 3
NULL -> Stop

Function Call Flow :

head
 |
 v
Count(head)
     |
     v
Traverses all nodes and returns 3

Operations Performed :
1. Created and linked three nodes.
2. Passed head to the Count() function.
3. Traversed the linked list.
4. Counted all nodes.
5. Returned the total count.
6. Displayed the result.

Conclusion :
Passing the head pointer to a function allows
linked list operations to be performed without
modifying the original list. This is a common
approach used in modular linked list programs.

=====================================================================
*/

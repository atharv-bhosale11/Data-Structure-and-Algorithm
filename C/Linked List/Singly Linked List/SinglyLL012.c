/*
=====================================================================

Program Name    : Singly Linked List - Iterative Traversal Using While Loop
Program Number  : 012
Description     : This program demonstrates how to traverse a singly
                  linked list using a while loop. A temporary pointer
                  is used to visit each node sequentially until the
                  end of the list is reached.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Head Pointer,
                  Temporary Pointer, While Loop,
                  Linked List Traversal

Input           : None

Output          : Displays all node values in the linked list.

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
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}

/*
=====================================================================

Expected Output :
11
21
51

Explanation :
A temporary pointer named temp is initialized with
the address stored in head. The while loop continues
to execute as long as temp is not NULL.

During each iteration:
1. The current node's data is displayed.
2. temp is moved to the next node.

Traversal Flow :

head
 |
 v
11 --> 21 --> 51 --> NULL

Iteration 1 : Display 11
Iteration 2 : Display 21
Iteration 3 : Display 51
Iteration 4 : temp becomes NULL, loop terminates

Operations Performed :
1. Created and linked three nodes.
2. Assigned head to temp.
3. Traversed the linked list using a while loop.
4. Displayed data from every node.
5. Stopped traversal when NULL was encountered.

Conclusion :
Using a while loop is the standard and most common
approach for traversing a singly linked list. It
allows processing of every node until the end of
the list is reached.

=====================================================================
*/

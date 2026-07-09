/*
=====================================================================

Program Name    : Singly Linked List - Pointer Traversal and Node Access
Program Number  : 005
Description     : This program demonstrates how pointers are used to
                  connect linked list nodes. It displays node addresses,
                  pointer values, and accesses data from the next node
                  using the arrow (->) operator.

Concepts Used   : Structure, Self-Referential Structure,
                  Pointer Traversal, Arrow Operator,
                  Memory Addresses, Node Linking

Input           : None

Output          : Displays node addresses, pointer values,
                  and data from the linked node.

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

int main()
{
    struct node obj1, obj2;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = NULL;

    printf("%u\n", &obj1);     // Address of obj1
    printf("%u\n", &obj2);     // Address of obj2

    printf("%u\n", obj1.next); // Address stored in next
    printf("%u\n", obj2.next); // NULL

    printf("%d\n", obj1.next->data);

    return 0;
}

/*
=====================================================================

Expected Output :
(Address of obj1)
(Address of obj2)
(Address stored in obj1.next)
0
21

Explanation :
Two nodes are created and linked together. The next
pointer of the first node stores the address of the
second node. By using the arrow (->) operator, the
program accesses the data member of the second node
through the pointer stored in the first node.

Operations Performed :
1. Created and initialized two nodes.
2. Linked the first node to the second node.
3. Displayed memory addresses of both nodes.
4. Displayed pointer values stored in next.
5. Accessed linked node data using the arrow operator.

Conclusion :
This program demonstrates how linked list traversal
begins by following node addresses through pointers
and accessing node members using the arrow operator.

=====================================================================
*/

/*
=====================================================================

Program Name    : Singly Linked List - Linking Two Nodes
Program Number  : 004
Description     : This program demonstrates how two nodes of a singly
                  linked list can be connected using pointers. It shows
                  the basic concept of node linking, which forms the
                  foundation of a linked list data structure.

Concepts Used   : Structure, Self-Referential Structure,
                  Node Linking, Pointer Assignment,
                  Linked List Basics

Input           : None

Output          : Displays the data stored in both linked nodes.

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

    printf("%d\n", obj1.data);
    printf("%d\n", obj2.data);

    return 0;
}

/*
=====================================================================

Expected Output :
11
21

Explanation :
Two node objects are created. The first node stores
the value 11 and its next pointer contains the
address of the second node. The second node stores
the value 21 and its next pointer is assigned NULL,
indicating the end of the linked list.

Operations Performed :
1. Created two node objects.
2. Initialized the data members.
3. Linked the first node to the second node.
4. Marked the second node as the last node.
5. Displayed the data stored in both nodes.

Conclusion :
This program demonstrates the fundamental concept
of connecting nodes through pointers to form a
singly linked list.

=====================================================================
*/

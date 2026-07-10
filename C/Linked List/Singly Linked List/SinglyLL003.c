/*
=====================================================================

Program Name    : Singly Linked List - Node Initialization 
Program Number  : 003
Description     : This program demonstrates the creation of a singly
                  linked list node and the initialization of its data
                  and next members. It also illustrates how to access
                  and display node data using the dot operator.

Concepts Used   : Structure, Self-Referential Structure,
                  Node Initialization, Dot Operator,
                  Pointer Assignment

Input           : None

Output          : Displays the data stored in the node.

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
    struct node obj;

    obj.data = 11;
    obj.next = NULL;

    printf("%d\n", obj.data);

    return 0;
}

/*
=====================================================================

Expected Output :
11

Explanation :
A node object is created using a self-referential
structure. The data member is assigned the value
11 and the next pointer is initialized to NULL,
indicating that the node is not connected to any
other node.

Operations Performed :
1. Created a node object.
2. Initialized the data member.
3. Initialized the next pointer.
4. Accessed the data using the dot operator.
5. Displayed the stored value.

Conclusion :
This program demonstrates the basic creation and
initialization of a linked list node, which serves
as the foundation for all linked list operations.

=====================================================================
*/

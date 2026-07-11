/*
=====================================================================

Program Name    : Singly Linked List - Head Pointer Introduction
Program Number  : 007
Description     : This program demonstrates the use of a head pointer
                  in a singly linked list. The head pointer stores the
                  address of the first node and is used to traverse
                  the entire linked list.

Concepts Used   : Structure, Self-Referential Structure,
                  Head Pointer, Node Linking,
                  Pointer Traversal, Arrow Operator

Input           : None

Output          : Displays the data stored in all linked nodes
                  through the head pointer.

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
    struct node *head = NULL;
    struct node obj1, obj2, obj3;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    printf("%d\n", head->data);
    printf("%d\n", head->next->data);
    printf("%d\n", head->next->next->data);

    return 0;
}

/*
=====================================================================

Expected Output :
11
21
51

Explanation :
A head pointer is created and initialized with the
address of the first node. The head acts as the
entry point to the linked list.

Using the head pointer, the program accesses:

head->data                  -> First Node Data
head->next->data            -> Second Node Data
head->next->next->data      -> Third Node Data

Operations Performed :
1. Created three node objects.
2. Linked all nodes sequentially.
3. Created a head pointer.
4. Stored the address of the first node in head.
5. Traversed the linked list using head.
6. Displayed data from all nodes.

Conclusion :
The head pointer is the most important pointer in a
linked list because it provides access to the first
node and enables traversal of the entire list.

=====================================================================
*/

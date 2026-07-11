/*
=====================================================================

Program Name    : Singly Linked List - Using typedef for Node
Program Number  : 008
Description     : This program demonstrates the use of typedef to
                  create an alias for a self-referential structure.
                  It simplifies the declaration of node objects and
                  pointers, making linked list programs easier to
                  read and maintain.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Head Pointer,
                  Pointer Traversal, Node Linking

Input           : None

Output          : Displays the data stored in all linked nodes.

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

int main()
{
    NODE *head = NULL;
    NODE obj1, obj2, obj3;

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
The typedef statement creates an alias named NODE
for the structure 'struct node'. This eliminates
the need to repeatedly write 'struct node' while
declaring node objects and pointers.

Without typedef :
struct node *head;
struct node obj1, obj2, obj3;

With typedef :
NODE *head;
NODE obj1, obj2, obj3;

Operations Performed :
1. Created a typedef alias named NODE.
2. Declared node objects using NODE.
3. Created a head pointer.
4. Linked three nodes together.
5. Traversed the list using head.
6. Displayed data from all nodes.

Conclusion :
The typedef keyword improves code readability and
simplifies linked list implementation by providing
a shorter and more convenient name for the node
structure.

=====================================================================
*/

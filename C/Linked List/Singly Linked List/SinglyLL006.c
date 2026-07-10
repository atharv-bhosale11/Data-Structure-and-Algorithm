/*
=====================================================================

Program Name    : Singly Linked List - Multi Node Traversal
Program Number  : 006
Description     : This program demonstrates the creation and linking
                  of three nodes in a singly linked list. It shows
                  how node addresses are stored in pointers and how
                  multiple nodes can be accessed through chained
                  pointer traversal using the arrow (->) operator.

Concepts Used   : Structure, Self-Referential Structure,
                  Node Linking, Pointer Traversal,
                  Arrow Operator, Memory Addresses

Input           : None

Output          : Displays node addresses, pointer values,
                  and data stored in all linked nodes.

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
    struct node obj1, obj2, obj3;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    printf("%u\n", &obj1);
    printf("%u\n", &obj2);
    printf("%u\n", &obj3);

    printf("%u\n", obj1.next);
    printf("%u\n", obj2.next);
    printf("%u\n", obj3.next);

    printf("%d\n", obj1.data);
    printf("%d\n", obj1.next->data);
    printf("%d\n", obj1.next->next->data);

    return 0;
}

/*
=====================================================================

Expected Output :
(Address of obj1)
(Address of obj2)
(Address of obj3)

(Address stored in obj1.next)
(Address stored in obj2.next)
0

11
21
51

Explanation :
Three nodes are created and linked together to form
a simple singly linked list. The first node points
to the second node, and the second node points to
the third node. The third node contains NULL in its
next pointer, indicating the end of the list.

The program demonstrates chained traversal:

obj1.data                  -> Accesses first node data
obj1.next->data            -> Accesses second node data
obj1.next->next->data      -> Accesses third node data

Operations Performed :
1. Created three node objects.
2. Initialized data members.
3. Linked nodes sequentially.
4. Displayed node addresses.
5. Displayed pointer values.
6. Traversed multiple nodes using pointers.
7. Accessed data from each linked node.

Conclusion :
This program demonstrates multi-node traversal in a
singly linked list and shows how nodes can be
accessed sequentially through chained pointer
references.

Note :
For portable code on modern systems, pointers should
be printed using %p instead of %u.

=====================================================================
*/

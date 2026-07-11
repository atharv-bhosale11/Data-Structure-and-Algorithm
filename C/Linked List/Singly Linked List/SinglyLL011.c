/*
=====================================================================

Program Name    : Singly Linked List - Sequential Node Traversal
Program Number  : 011
Description     : This program demonstrates step-by-step traversal of
                  a singly linked list using a temporary pointer. The
                  pointer is moved from one node to the next using the
                  next member, illustrating the fundamental traversal
                  mechanism of linked lists.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Head Pointer,
                  Temporary Pointer, Linked List Traversal

Input           : None

Output          : Displays the data stored in each node.

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

    printf("%d\n", temp->data);

    temp = temp->next;
    printf("%d\n", temp->data);

    temp = temp->next;
    printf("%d\n", temp->data);

    temp = temp->next;

    return 0;
}

/*
=====================================================================

Expected Output :
11
21
51

Explanation :
The traversal begins from the first node pointed
to by head. A temporary pointer named temp is used
to move through the linked list one node at a time.

Traversal Sequence :

temp = head
temp->data           -> 11

temp = temp->next
temp->data           -> 21

temp = temp->next
temp->data           -> 51

temp = temp->next
temp                 -> NULL

Operations Performed :
1. Created and linked three nodes.
2. Assigned head to temp.
3. Accessed the first node data.
4. Moved temp to the second node.
5. Moved temp to the third node.
6. Reached the end of the list (NULL).

Conclusion :
Linked list traversal is performed by repeatedly
moving a temporary pointer to the next node until
NULL is encountered. This forms the basis of all
major linked list operations such as display,
searching, counting, insertion, and deletion.

=====================================================================
*/

/*
=====================================================================

Program Name    : Singly Linked List - Traversal Using Temporary Pointer
Program Number  : 010
Description     : This program demonstrates the use of a temporary
                  pointer for linked list traversal. Instead of
                  directly using the head pointer, a temporary
                  pointer is assigned the address of the first node
                  and is used to access the linked list nodes.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Head Pointer,
                  Temporary Pointer, Node Traversal

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
    printf("%d\n", temp->next->data);
    printf("%d\n", temp->next->next->data);

    return 0;
}

/*
=====================================================================

Expected Output :
11
21
51

Explanation :
A temporary pointer named temp is created and
assigned the address stored in head. The temp
pointer is then used to access the linked nodes.

This approach preserves the head pointer while
allowing traversal of the linked list.

Operations Performed :
1. Created three linked nodes.
2. Created a head pointer.
3. Created a temporary pointer.
4. Assigned head to temp.
5. Accessed node data through temp.
6. Preserved the original head pointer.

Conclusion :
A temporary pointer is commonly used during linked
list traversal because it allows navigation through
the list without modifying the head pointer.

=====================================================================
*/

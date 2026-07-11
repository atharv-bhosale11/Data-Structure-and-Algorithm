/*
=====================================================================

Program Name    : Singly Linked List - Using Pointer Alias with typedef
Program Number  : 009
Description     : This program demonstrates the use of typedef to
                  create aliases for both the node structure and
                  node pointer. It simplifies pointer declarations
                  and improves code readability in linked list
                  implementations.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Pointer Alias,
                  Head Pointer, Node Linking

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
Two typedef aliases are created:

NODE  -> Represents 'struct node'
PNODE -> Represents 'struct node *'

This allows node pointers to be declared using
PNODE instead of repeatedly writing
'struct node *'.

Without typedef :
struct node *head;

With typedef :
PNODE head;

Operations Performed :
1. Created a structure alias (NODE).
2. Created a pointer alias (PNODE).
3. Declared a head pointer using PNODE.
4. Linked three nodes together.
5. Traversed the linked list through head.
6. Displayed data from all nodes.

Conclusion :
Using typedef for pointer declarations improves
code readability, reduces complexity, and makes
linked list implementations easier to understand
and maintain.

=====================================================================
*/

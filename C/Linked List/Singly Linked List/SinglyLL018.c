/*
=====================================================================

Program Name    : Singly Linked List - Creating Head Pointer
Program Number  : 018
Description     : This program demonstrates the declaration of a
                  Singly Linked List node structure along with
                  typedef aliases. It also introduces the Head
                  pointer, which serves as the starting point
                  of a linked list.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Pointer, Head Pointer

Input           : None

Output          : No output generated.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int main()
{
    PNODE head = NULL;

    return 0;
}

/*
=====================================================================

Expected Output :

(No Output)

Explanation :

A self-referential structure named 'node' is
created to represent a Singly Linked List node.

The typedef statements improve code readability:

NODE    -> struct node
PNODE   -> struct node *
PPNODE  -> struct node **

A Head pointer is declared and initialized to
NULL. Since no nodes are currently present,
the linked list is considered empty.

Representation :

head
 |
 v
NULL

Operations Performed :

1. Created a self-referential structure.
2. Defined typedef aliases.
3. Declared a Head pointer.
4. Initialized Head to NULL.

Conclusion :

The Head pointer acts as the entry point of a
linked list. Initializing it to NULL indicates
that the linked list is empty. This serves as
the foundation for all insertion, deletion,
and traversal operations in linked lists.

=====================================================================
*/

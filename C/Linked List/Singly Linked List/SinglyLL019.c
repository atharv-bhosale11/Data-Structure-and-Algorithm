/*
=====================================================================

Program Name    : Singly Linked List - Combined typedef Declaration
Program Number  : 019
Description     : This program demonstrates a compact way of defining
                  a self-referential structure and its typedef aliases
                  in a single statement. It also introduces the Head
                  pointer used to manage a Singly Linked List.

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

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

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

This program demonstrates the combined declaration
of a structure and its typedef aliases.

typedef Declaration :

NODE    -> struct node
PNODE   -> struct node *
PPNODE  -> struct node **

Instead of writing separate typedef statements,
all aliases are created in a single declaration.

A Head pointer is declared and initialized to
NULL, indicating that the linked list currently
contains no nodes.

Representation :

head
 |
 v
NULL

Operations Performed :

1. Created a self-referential structure.
2. Defined NODE, PNODE and PPNODE aliases.
3. Declared a Head pointer.
4. Initialized Head to NULL.

Advantages :

1. Reduces code length.
2. Improves readability.
3. Keeps structure and typedef declarations
   together.
4. Commonly used in professional linked list
   implementations.

Conclusion :

This approach provides a clean and concise way
to define linked list structures and pointer
aliases. The Head pointer initialized to NULL
represents an empty Singly Linked List and
serves as the starting point for future
operations.

=====================================================================
*/

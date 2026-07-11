/*
=====================================================================

Program Name    : Singly Linked List - Function Prototypes Framework
Program Number  : 020
Description     : This program provides the basic framework for a
                  Singly Linked List implementation. All major
                  linked list operations are declared as separate
                  functions, creating a modular structure for
                  future implementation.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Function Declaration,
                  Modular Programming,
                  Linked List Operations

Functions       : Display()
                  Count()
                  InsertFirst()
                  InsertLast()
                  InsertAtPos()
                  DeleteFirst()
                  DeleteLast()
                  DeleteAtPos()

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

void Display(PNODE first)
{

}

int Count(PNODE first)
{
    return 0;
}

void InsertFirst(PPNODE first,int iNo)
{

}

void InsertLast(PPNODE first, int iNo)
{

}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{

}

void DeleteFirst(PPNODE first)
{

}

void DeleteLast(PPNODE first)
{

}

void DeleteAtPos(PPNODE first, int iPos)
{

}

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

This program serves as the skeleton structure
for a complete Singly Linked List implementation.

The node structure contains :

1. data
   Stores the value of the node.

2. next
   Stores the address of the next node.

The program declares all commonly used linked
list operations as separate functions.

Functions Overview :

1. Display()
   Used to traverse and display all nodes.

2. Count()
   Used to count the total number of nodes.

3. InsertFirst()
   Inserts a new node at the beginning.

4. InsertLast()
   Inserts a new node at the end.

5. InsertAtPos()
   Inserts a new node at a specific position.

6. DeleteFirst()
   Removes the first node.

7. DeleteLast()
   Removes the last node.

8. DeleteAtPos()
   Removes a node from a specific position.

Advantages of This Design :

1. Modular programming approach.
2. Easy maintenance and debugging.
3. Reusable linked list functions.
4. Better code organization.
5. Scalable for advanced operations.

Conclusion :

This framework establishes the foundation for a
complete Singly Linked List implementation. The
function declarations provide a clear roadmap
for developing insertion, deletion, traversal,
and counting operations in a structured manner.

=====================================================================
*/

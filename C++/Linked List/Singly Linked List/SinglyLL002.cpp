/*
=====================================================================

Program Name    : Dynamic Memory Allocation for Linked List Node
Program Number  : 002
Description     : This program demonstrates how to create
                  a node dynamically using the new operator,
                  initialize its data members, access the
                  stored data, and release the allocated
                  memory using delete.

Concepts Used   : Dynamic Memory Allocation,
                  Self-Referential Structure,
                  Pointer,
                  new Operator,
                  delete Operator

Input           : None

Output          : Displays the data stored in the node.

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int main()
{
    PNODE newn = NULL;          // Pointer

    newn = new NODE;           // Dynamic Memory Allocation

    newn->data = 11;
    newn->next = NULL;

    cout<<newn->data<<endl;

    delete(newn);              // Free Allocated Memory

    return 0;
}

/*
=====================================================================

Expected Output :

11

Explanation :

A node is created dynamically using the
new operator. Memory is allocated from
the heap section.

newn
  |
  v
+--------+--------+
|  11    | NULL   |
+--------+--------+

The pointer newn stores the address of
the dynamically allocated node.

Initialization Steps :

1. Allocate memory using new.
2. Store 11 in the data field.
3. Set next pointer to NULL.
4. Display the data value.
5. Release memory using delete.

Program Flow :

Declare Pointer
       |
       v
Allocate Memory
       |
       v
Initialize Node
       |
       v
Display Data
       |
       v
Delete Memory
       |
       v
Program Ends

Operations Performed :

1. Declared a node pointer.
2. Allocated memory dynamically.
3. Initialized node members.
4. Accessed node data using arrow operator.
5. Released allocated memory.

Conclusion :

Dynamic memory allocation allows linked
list nodes to be created at runtime.
The new operator allocates memory and
delete releases it, preventing memory leaks.

=====================================================================
*/

/*
=====================================================================

Program Name    : Size of Node in Singly Linked List
Program Number  : 001
Description     : This program demonstrates the basic node
                  structure used in a Singly Linear Linked
                  List and displays the size occupied by
                  a node in memory.

Concepts Used   : Structure,
                  Self-Referential Structure,
                  Pointer,
                  sizeof Operator

Input           : None

Output          : Displays the size of a node.

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

// Singly Linear Linked List

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
    NODE obj;

    cout<<"Size of node is : "<<sizeof(obj)<<endl;

    return 0;
}

/*
=====================================================================

Expected Output :

Size of node is : 12

(Note: Output may vary depending on compiler,
system architecture, and structure packing.)

Explanation :

A node in a Singly Linked List contains:

1. data  -> Integer value stored in the node.
2. next  -> Pointer that stores the address of
            the next node.

Node Representation :

+--------+---------+
|  data  |  next   |
+--------+---------+

Using sizeof() operator, the total memory
occupied by the node structure is displayed.

Program Flow :

Create Node Object
        |
        v
Calculate sizeof(Node)
        |
        v
Display Result
        |
        v
Program Ends

Operations Performed :

1. Defined a self-referential structure.
2. Created a node object.
3. Used sizeof() to determine memory usage.
4. Displayed the size of the node.

Conclusion :

A Singly Linked List node consists of data and
a pointer to the next node. Understanding the
memory layout of a node is the first step toward
implementing linked list data structures.

=====================================================================
*/

/*
=====================================================================

Name            : Doubly Linked List - Node Structure Size
Program Number  : 001
Description     : This program demonstrates the basic structure of a
                  Doubly Linked List node. Each node contains:
                  - Data field
                  - Pointer to next node
                  - Pointer to previous node

                  The program displays the total size occupied by
                  the node structure in memory using structure packing.

Concepts Used   : Doubly Linked List, Self-Referential Structure,
                  Structure Packing, Pointers, Memory Layout,
                  sizeof Operator

Input           : None

Output          : Size of Doubly Linked List node structure

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================

*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int main()
{
    printf("Size of NODE is : %d\n",sizeof(NODE));

    return 0;
}

/*
=====================================================================

Sample Output :

Size of NODE is : 20

=====================================================================

Memory Layout :

+--------+---------+---------+
|  data  |  next   |  prev   |
+--------+---------+---------+

=====================================================================

Note :

- Doubly Linked List node contains two pointers.
- next pointer stores address of next node.
- prev pointer stores address of previous node.
- #pragma pack(1) removes compiler-added padding.
- sizeof() is used to determine total memory occupied
  by the structure.

=====================================================================
*/

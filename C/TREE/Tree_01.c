/*
===============================================================================
Program Name    : Tree - Node Creation
Program Number  : 001
File Name       : Tree_01.c

Description     : This program demonstrates the basic structure
                  of a Tree node using Dynamic Memory Allocation.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale 
===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int main()
{
    PNODE head = NULL;

    printf("Size of Node : %d\n",sizeof(NODE));

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Size of Node : 12

===============================================================================
Memory Representation:
===============================================================================

          +--------+
head ---->| NULL   |
          +--------+

Node Structure

+--------+-----------+-----------+
|  data  |  lchild   |  rchild   |
+--------+-----------+-----------+

===============================================================================
Time Complexity:
===============================================================================

Node Creation : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates the basic structure of a Tree node
using a self-referential structure in C. Each node contains
data and two pointers, one for the left child and one for
the right child.

===============================================================================
*/

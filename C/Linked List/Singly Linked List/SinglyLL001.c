/*
=====================================================================
 
Program Name    : Singly Linked List - Node Structure & Memory Layout
Program Number  : 001
Description     : This program demonstrates the creation of a singly
                  linked list node structure in C. It explains the
                  memory layout, structure size, padding, and memory
                  alignment on a 64-bit system using the sizeof
                  operator.

Concepts Used   : Structure, Self-Referential Structure,
                  Memory Alignment, Structure Padding,
                  sizeof Operator

Input           : None

Output          : Displays the size of the node structure.

Date            : July 2026
Language        : C
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node obj;

    printf("%d\n", sizeof(obj));

    return 0;
}

/*
=====================================================================

Expected Output :
16

Explanation :
The structure contains an integer data member and
a pointer to the next node. On a 64-bit system,
the compiler inserts padding bytes to satisfy
memory alignment requirements.

Size Calculation :
int data         = 4 Bytes
Padding          = 4 Bytes
Node Pointer     = 8 Bytes

Total Size       = 16 Bytes

Conclusion :
This program demonstrates how structure padding
and memory alignment affect the overall size of a
node used in a singly linked list.

=====================================================================
*/

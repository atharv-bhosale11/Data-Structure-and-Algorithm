/*
=====================================================================

Program Name    : Singly Linked List - Structure Packing
Program Number  : 002
Description     : This program demonstrates the use of #pragma pack(1)
                  to remove compiler-added padding from a singly linked
                  list node structure. It shows how structure packing
                  affects memory consumption and overall structure size.

Concepts Used   : Structure, Self-Referential Structure,
                  Structure Packing, Memory Alignment,
                  sizeof Operator

Input           : None

Output          : Displays the packed size of the node structure.

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

int main()
{
    struct node obj;

    printf("%d\n", sizeof(obj));      // 12

    return 0;
}

/*
=====================================================================

Expected Output :
12

Explanation :
The #pragma pack(1) directive instructs the compiler
to pack structure members with 1-byte alignment.
As a result, no padding bytes are added between
the structure members.

Size Calculation :
int data         = 4 Bytes
Node Pointer     = 8 Bytes

Total Size       = 12 Bytes
 
Conclusion :
Structure packing reduces memory consumption by
eliminating compiler-added padding. This technique
is useful when memory efficiency is important.

=====================================================================
*/

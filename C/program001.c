/*
--------------------------------------------------
Program Name : Structure Size Demonstration
Description  : This program demonstrates the size
               of a self-referential structure
               (node) in C and explains the memory
               layout including padding and pointer
               size on a 64-bit system.

Concepts Used:
1. Structures
2. Self-Referential Structures
3. Memory Alignment
4. Structure Padding
5. sizeof Operator

Author       : Atharv Tushar Bhosale
Language     : C
--------------------------------------------------
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

    printf("%d\n",sizeof(obj));       // 16

    // Memory Layout (64-bit System)
    // int data        -> 4 bytes
    // Padding         -> 4 bytes
    // struct node*    -> 8 bytes
    // Total           -> 16 bytes

    return 0;
}

/*
--------------------------------------------------
Output:
16

Conclusion:
The size of the structure becomes 16 bytes due to
memory alignment and padding added by the compiler.

End of Program
--------------------------------------------------
*/

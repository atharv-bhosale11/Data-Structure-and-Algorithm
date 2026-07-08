/*
--------------------------------------------------
Program Name : Structure Packing Demonstration
Description  : This program demonstrates the use
               of #pragma pack(1) to remove padding
               bytes from a structure and reduce
               its memory size.

Concepts Used:
1. Structures
2. Self-Referential Structures
3. Structure Packing
4. Memory Alignment
5. sizeof Operator

Author       : Atharv Tushar Bhosale
Language     : C
--------------------------------------------------
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

    printf("%d\n", sizeof(obj));   // Output : 12

    return 0;
}

/*
--------------------------------------------------
Output:
12

Explanation:
Without #pragma pack(1):
    int data    -> 4 bytes
    Padding     -> 4 bytes
    Pointer     -> 8 bytes
    Total Size  -> 16 bytes

With #pragma pack(1):
    int data    -> 4 bytes
    Pointer     -> 8 bytes
    Total Size  -> 12 bytes

Conclusion:
Structure packing removes compiler-added padding
and minimizes memory consumption.

End of Program
--------------------------------------------------
*/

/*
--------------------------------------------------
Program Name : Node Initialization and Data Access
Description  : This program demonstrates the
               creation of a self-referential
               structure, initialization of its
               members, and accessing structure
               data using the dot operator.

Concepts Used:
1. Structures
2. Self-Referential Structures
3. Structure Packing
4. Member Initialization
5. Dot Operator

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

    obj.data = 11;
    obj.next = NULL;

    printf("%d\n", obj.data);

    return 0;
}

/*
--------------------------------------------------
Output:
11

Explanation:
1. A structure object named 'obj' is created.
2. The data member is initialized with value 11.
3. The next pointer is initialized to NULL.
4. The data member is accessed using the dot
   operator and displayed on the screen.

Conclusion:
This program demonstrates basic structure creation,
member initialization, and data access in a
self-referential structure.

End of Program
--------------------------------------------------
*/

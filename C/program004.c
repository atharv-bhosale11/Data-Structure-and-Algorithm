/*
--------------------------------------------------
Program Name : Linking Two Nodes Using Structures
Description  : This program demonstrates the
               creation of two self-referential
               structure objects and links them
               together to form a simple linked
               list containing two nodes.

Concepts Used:
1. Structures
2. Self-Referential Structures
3. Linked List Basics
4. Pointer Assignment
5. Node Linking

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
    struct node obj1, obj2;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = NULL;

    printf("%d\n", obj1.data);
    printf("%d\n", obj2.data);

    return 0;
}

/*
--------------------------------------------------
Output:
11
21

Explanation:
1. Two nodes (obj1 and obj2) are created.
2. The first node stores data value 11.
3. The second node stores data value 21.
4. The next pointer of obj1 points to obj2.
5. The next pointer of obj2 is set to NULL,
   indicating the end of the linked list.

Linked List Representation:

+------+------+
|  11  |   •-----> +------+------+
+------+------+\   |  21  | NULL |
                \->+------+------+

Conclusion:
This program demonstrates how nodes are connected
using pointers to form the foundation of a linked
list data structure.

End of Program
--------------------------------------------------
*/

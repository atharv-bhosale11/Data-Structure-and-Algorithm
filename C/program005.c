/*
--------------------------------------------------
Program Name : Node Address and Pointer Access
Description  : This program demonstrates how nodes
               are linked using pointers, how to
               display memory addresses, and how
               to access data from the next node
               using the arrow (->) operator.

Concepts Used:
1. Structures
2. Self-Referential Structures
3. Pointers
4. Node Linking
5. Arrow Operator (->)
6. Memory Addresses

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

    printf("%u\n", &obj1);     // Address of obj1
    printf("%u\n", &obj2);     // Address of obj2

    printf("%u\n", obj1.next); // Address stored in next
    printf("%u\n", obj2.next); // NULL

    printf("%d\n", obj1.next->data);

    return 0;
}

/*
--------------------------------------------------
Output:
(Address of obj1)
(Address of obj2)
(Address of obj2)
0
21

Explanation:
1. Two nodes are created and linked together.
2. obj1.next stores the address of obj2.
3. Printing obj1.next displays the address of
   the second node.
4. obj2.next contains NULL, indicating the end
   of the linked list.
5. The arrow operator (->) is used to access
   the data member of the next node.

Linked List Representation:

+------+------+
|  11  |   •-----> +------+------+
+------+------+\   |  21  | NULL |
                \->+------+------+

Conclusion:
This program demonstrates how pointers store node
addresses and how linked list nodes can be accessed
through pointer traversal using the arrow operator.

End of Program
--------------------------------------------------
*/

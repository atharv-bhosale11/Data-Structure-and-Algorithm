/*
=====================================================================

Program Name    : Singly Linked List - Display and Count Nodes
Program Number  : 016
Description     : This program demonstrates two fundamental linked
                  list operations: displaying all node elements and
                  counting the total number of nodes using separate
                  functions.

Concepts Used   : Structure, Self-Referential Structure,
                  typedef, Function Call,
                  Linked List Traversal,
                  Display Operation, Count Operation

Input           : None

Output          : Displays all node elements and the
                  total number of nodes.

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

typedef struct node NODE;
typedef struct node *PNODE;

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("%d\n", first->data);
        first = first->next;
    }
}

int main()
{
    PNODE head = NULL;
    NODE obj1, obj2, obj3;
    int iRet = 0;

    head = &obj1;

    obj1.data = 11;
    obj1.next = &obj2;

    obj2.data = 21;
    obj2.next = &obj3;

    obj3.data = 51;
    obj3.next = NULL;

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes are : %d", iRet);

    return 0;
}

/*
=====================================================================

Expected Output :

11
21
51
Number of Nodes are : 3

Explanation :
The program implements two separate linked list
operations.

Display() :
Traverses the linked list and displays the data
stored in each node.

Count() :
Traverses the linked list and counts the total
number of nodes present.

Function Flow :

Display(head)
      |
      v
11 -> 21 -> 51

Count(head)
      |
      v
Returns 3

Operations Performed :
1. Created and linked three nodes.
2. Displayed all node elements.
3. Counted the total number of nodes.
4. Returned the count to main().
5. Displayed the final count.

Conclusion :
Separating linked list operations into dedicated
functions improves modularity, readability, and
reusability. Display() and Count() are among the
most frequently used operations in linked lists.

=====================================================================
*/

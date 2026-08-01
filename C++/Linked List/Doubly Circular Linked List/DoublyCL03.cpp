/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertLast
Program Number  : 003
File Name       : DoublyCL03.cpp

Description     : This program demonstrates insertion of a node
                  at the end of a Doubly Circular Linked List
                  using the InsertLast() function.

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class
2. Dynamic Memory Allocation
3. Self-Referential Class
4. Doubly Circular Linked List
5. InsertFirst Operation
6. InsertLast Operation

===============================================================================
*/

#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;
};

class DoublyCL
{
    private:
        Node *First;
        Node *Last;
        int iCount;

    public:
        DoublyCL()
        {
            First = NULL;
            Last = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            Node *newn = NULL;

            newn = new Node;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((First == NULL) && (Last == NULL))
            {
                First = newn;
                Last = newn;
            }
            else
            {
                newn->next = First;
                First->prev = newn;
                First = newn;
            }

            Last->next = First;
            First->prev = Last;

            iCount++;
        }

        void InsertLast(int no)
        {
            Node *newn = NULL;

            newn = new Node;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((First == NULL) && (Last == NULL))
            {
                First = newn;
                Last = newn;
            }
            else
            {
                Last->next = newn;
                newn->prev = Last;
                Last = newn;
            }

            Last->next = First;
            First->prev = Last;

            iCount++;
        }
};

int main()
{
    DoublyCL dobj;

    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(51);
    dobj.InsertLast(101);

    return 0;
}

/*
===============================================================================
Memory Representation:
===============================================================================

After InsertFirst(21)

+----+
| 21 |
+----+

After InsertFirst(11)

+----+ <=> +----+
| 11 |     | 21 |
+----+ <=> +----+

After InsertLast(51)

+----+ <=> +----+ <=> +----+
| 11 |     | 21 |     | 51 |
+----+ <=> +----+ <=> +----+

After InsertLast(101)

+----+ <=> +----+ <=> +----+ <=> +-----+
| 11 |     | 21 |     | 51 |     | 101 |
+----+ <=> +----+ <=> +----+ <=> +-----+

Circular Connections:

First -> 11
Last  -> 101

101.next = 11
11.prev = 101

===============================================================================
Algorithm:
===============================================================================

InsertLast()

1. Create a new node.
2. Store data in the node.
3. If list is empty:
      First = Last = new node.
4. Otherwise:
      Attach new node after Last.
      Update Last.
5. Maintain circular links.
6. Increment node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

InsertLast()  : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates insertion of nodes at the end of a
Doubly Circular Linked List. The operation is performed in
constant time by updating the Last pointer and maintaining
circular connections.

===============================================================================
*/

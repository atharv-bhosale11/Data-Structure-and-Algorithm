/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertFirst
Program Number  : 002
File Name       : DoublyCL02.cpp

Description     : This program demonstrates insertion of a node
                  at the beginning of a Doubly Circular Linked
                  List using the InsertFirst() function.

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

                First->next = First;
                First->prev = First;
            }
            else
            {
                newn->next = First;
                First->prev = newn;

                First = newn;

                First->prev = Last;
                Last->next = First;
            }

            iCount++;
        }
};

int main()
{
    DoublyCL dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    return 0;
}

/*
===============================================================================
Memory Representation:
===============================================================================

After InsertFirst(51)

+----+
| 51 |
+----+

After InsertFirst(21)

+----+ <=> +----+
| 21 |     | 51 |
+----+ <=> +----+

After InsertFirst(11)

+----+ <=> +----+ <=> +----+
| 11 |     | 21 |     | 51 |
+----+ <=> +----+ <=> +----+

Circular Connections:

First -> 11
Last  -> 51

51.next = 11
11.prev = 51

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the data in the node.
3. If list is empty:
      First = Last = new node
      Connect node to itself.
4. Otherwise:
      Connect new node before First.
      Update First.
      Maintain circular links.
5. Increment node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates insertion of nodes at the beginning
of a Doubly Circular Linked List. The operation is performed
in constant time by updating First, Last and circular links.

===============================================================================
*/

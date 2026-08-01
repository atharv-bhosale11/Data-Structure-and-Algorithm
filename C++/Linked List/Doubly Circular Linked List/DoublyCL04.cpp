/*
===============================================================================
Program Name    : Doubly Circular Linked List - Display
Program Number  : 004
File Name       : DoublyCL04.cpp

Description     : This program demonstrates how to display all
                  elements of a Doubly Circular Linked List using
                  the Display() function.

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
7. Display Operation

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
            Node *newn = new Node;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((First == NULL) && (Last == NULL))
            {
                First = Last = newn;
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
            Node *newn = new Node;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if((First == NULL) && (Last == NULL))
            {
                First = Last = newn;
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

        void Display()
        {
            if((First == NULL) && (Last == NULL))
            {
                cout<<"Linked List is Empty\n";
                return;
            }

            Node *temp = First;

            cout<<"<=> ";

            do
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            }while(temp != First);

            cout<<"\n";
        }
};

int main()
{
    DoublyCL dobj;

    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(51);
    dobj.InsertLast(101);

    cout<<"Elements of Doubly Circular Linked List are:\n";
    dobj.Display();

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements of Doubly Circular Linked List are:

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=>

===============================================================================
Memory Representation:
===============================================================================

+----+ <=> +----+ <=> +----+ <=> +-----+
| 11 |     | 21 |     | 51 |     | 101 |
+----+ <=> +----+ <=> +----+ <=> +-----+

First = 11
Last  = 101

101.next = 11
11.prev = 101

===============================================================================
Algorithm:
===============================================================================

Display()

1. Check whether the list is empty.
2. Create a temporary pointer and initialize it to First.
3. Display node data.
4. Move temp to next node.
5. Repeat until temp reaches First again.
6. Stop traversal.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

InsertLast()  : O(1)

Display()     : O(n)

Space Complexity : O(1)

where,
n = Number of Nodes

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates traversal and display of all nodes
present in a Doubly Circular Linked List. Since the list is
circular, traversal continues until the First node is reached
again.

===============================================================================
*/

/*
===============================================================================
Program Name    : Doubly Circular Linked List - Count Nodes
Program Number  : 006
File Name       : DoublyCL06.cpp

Description     : This program demonstrates how to count the
                  total number of nodes present in a Doubly
                  Circular Linked List using the Count()
                  function.

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
8. Count Operation

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

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyCL dobj;
    int iRet = 0;

    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(51);
    dobj.InsertLast(101);

    cout<<"Elements of Doubly Circular Linked List are:\n";
    dobj.Display();

    iRet = dobj.Count();

    cout<<"Number of Nodes are : "<<iRet<<"\n";

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements of Doubly Circular Linked List are:

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=>

Number of Nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

+----+ <=> +----+ <=> +----+ <=> +-----+
| 11 |     | 21 |     | 51 |     | 101 |
+----+ <=> +----+ <=> +----+ <=> +-----+

First = 11
Last  = 101

===============================================================================
Algorithm:
===============================================================================

Count()

1. Maintain a variable named iCount.
2. Increment iCount after every insertion.
3. Decrement iCount after every deletion.
4. Return iCount whenever Count() is called.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

InsertLast()  : O(1)

Display()     : O(n)

Count()       : O(1)

Space Complexity : O(1)

where,
n = Number of Nodes

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates counting the total number of nodes
present in a Doubly Circular Linked List. By maintaining a
counter variable, the count operation is performed in constant
time.

===============================================================================
*/

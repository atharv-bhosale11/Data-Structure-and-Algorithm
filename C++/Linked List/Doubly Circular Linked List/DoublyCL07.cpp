/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteLast
Program Number  : 007
File Name       : DoublyCL07.cpp

Description     : This program demonstrates deletion of the
                  last node from a Doubly Circular Linked
                  List using the DeleteLast() function.

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
9. DeleteLast Operation

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

           void Display()
        {
            if(First == NULL && Last == NULL)
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

        void InsertFirst(int no)
        {
            Node *newn = new Node;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(First == NULL && Last == NULL)
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

            if(First == NULL && Last == NULL)
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

        void DeleteLast()
        {
            if(First == NULL && Last == NULL)
            {
                return;
            }
            else if(First == Last)
            {
                delete First;
                First = NULL;
                Last = NULL;
            }
            else
            {
                Last = Last->prev;
                delete Last->next;

                Last->next = First;
                First->prev = Last;
            }

            iCount--;
        }
};

int main()
{
    DoublyCL dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);

    cout<<"Linked List Before DeleteLast():\n";
    dobj.Display();

    dobj.DeleteLast();

    cout<<"\nLinked List After DeleteLast():\n";
    dobj.Display();

    cout<<"\nNumber of Nodes : "<<dobj.Count()<<"\n";

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Linked List Before DeleteLast():

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=>

Linked List After DeleteLast():

<=> | 11 | <=> | 21 | <=> | 51 | <=>

Number of Nodes : 3

===============================================================================
Memory Representation:
===============================================================================

Before:

11 <=> 21 <=> 51 <=> 101

After:

11 <=> 21 <=> 51

===============================================================================
Algorithm:
===============================================================================

1. Check whether the list is empty.
2. If only one node exists:
      Delete the node.
      Set First and Last to NULL.
3. Otherwise:
      Move Last to previous node.
      Delete old Last node.
      Maintain circular links.
4. Decrement node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

InsertLast()  : O(1)

DeleteLast()  : O(1)

Display()     : O(n)

Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates deletion of the last node from a
Doubly Circular Linked List. The operation is performed in
constant time by updating the Last pointer and maintaining
circular links.

===============================================================================
*/

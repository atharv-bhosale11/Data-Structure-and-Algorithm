/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteFirst
Program Number  : 006
File Name       : DoublyCL06.cpp

Description     : This program demonstrates deletion of the
                  first node from a Doubly Circular Linked
                  List using the DeleteFirst() function.

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
9. DeleteFirst Operation

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

        void DeleteFirst()
        {
            if((First == NULL) && (Last == NULL))
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
                First = First->next;
                delete Last->next;

                First->prev = Last;
                Last->next = First;
            }

            iCount--;
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

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);

    cout<<"Linked List Before DeleteFirst():\n";
    dobj.Display();

    dobj.DeleteFirst();

    cout<<"\nLinked List After DeleteFirst():\n";
    dobj.Display();

    cout<<"\nNumber of Nodes : "<<dobj.Count()<<"\n";

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Linked List Before DeleteFirst():

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=>

Linked List After DeleteFirst():

<=> | 21 | <=> | 51 | <=> | 101 | <=>

Number of Nodes : 3

===============================================================================
Memory Representation:
===============================================================================

Before:

11 <=> 21 <=> 51 <=> 101

After:

21 <=> 51 <=> 101

===============================================================================
Algorithm:
===============================================================================

1. Check whether the list is empty.
2. If only one node exists:
      Delete the node.
      Set First and Last to NULL.
3. Otherwise:
      Move First to next node.
      Delete old First node.
      Maintain circular links.
4. Decrement node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

InsertLast()  : O(1)

DeleteFirst() : O(1)

Display()     : O(n)

Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates deletion of the first node from a
Doubly Circular Linked List. The operation is performed in
constant time while preserving circular connections.

===============================================================================
*/

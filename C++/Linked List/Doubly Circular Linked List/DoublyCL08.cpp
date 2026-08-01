/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertAtPos
Program Number  : 008
File Name       : DoublyCL08.cpp

Description     : This program demonstrates insertion of a node
                  at a specified position in a Doubly Circular
                  Linked List using InsertAtPos() function.

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
7. InsertAtPos Operation
8. Display Operation
9. Count Operation

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

        void InsertAtPos(int no, int iPos)
        {
            if((iPos < 1) || (iPos > iCount + 1))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(iPos == 1)
            {
                InsertFirst(no);
            }
            else if(iPos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                Node *newn = new Node;
                Node *temp = First;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                for(int i = 1; i < iPos - 1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                newn->prev = temp;

                temp->next->prev = newn;
                temp->next = newn;

                iCount++;
            }
        }
};

int main()
{
    DoublyCL dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);

    cout<<"Linked List Before InsertAtPos():\n";
    dobj.Display();

    dobj.InsertAtPos(75,4);

    cout<<"\nLinked List After InsertAtPos():\n";
    dobj.Display();

    cout<<"\nNumber of Nodes : "<<dobj.Count()<<"\n";

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Linked List Before InsertAtPos():

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=>

Linked List After InsertAtPos():

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 75 | <=> | 101 | <=>

Number of Nodes : 5

===============================================================================
Memory Representation:
===============================================================================

Before:

11 <=> 21 <=> 51 <=> 101

After InsertAtPos(75,4):

11 <=> 21 <=> 51 <=> 75 <=> 101

===============================================================================
Algorithm:
===============================================================================

1. Validate the position.
2. If position is 1:
      Call InsertFirst().
3. If position is Count()+1:
      Call InsertLast().
4. Otherwise:
      Traverse up to (Position - 1).
      Create a new node.
      Adjust next and prev links.
      Increment node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)

InsertLast()  : O(1)

InsertAtPos() : O(n)

Display()     : O(n)

Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates insertion of a node at a specified
position in a Doubly Circular Linked List. The operation
maintains proper next and prev links while preserving the
circular structure of the list.

===============================================================================
*/

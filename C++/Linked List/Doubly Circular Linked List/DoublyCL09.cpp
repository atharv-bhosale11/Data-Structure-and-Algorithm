/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteAtPos
Program Number  : 009
File Name       : DoublyCL09.cpp

Description     : This program demonstrates deletion of a node
                  from a specified position in a Doubly Circular
                  Linked List using DeleteAtPos() function.

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class
2. Dynamic Memory Allocation
3. Self-Referential Class
4. Doubly Circular Linked List
5. DeleteFirst Operation
6. DeleteLast Operation
7. DeleteAtPos Operation
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

        void DeleteFirst()
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
                First = First->next;
                delete Last->next;

                First->prev = Last;
                Last->next = First;
            }

            iCount--;
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

        void DeleteAtPos(int iPos)
        {
            if((iPos < 1) || (iPos > iCount))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(iPos == 1)
            {
                DeleteFirst();
            }
            else if(iPos == iCount)
            {
                DeleteLast();
            }
            else
            {
                Node *temp = First;

                for(int i = 1; i < iPos-1; i++)
                {
                    temp = temp->next;
                }

                Node *target = temp->next;

                temp->next = target->next;
                target->next->prev = temp;

                delete target;

                iCount--;
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
    dobj.InsertLast(111);

    cout<<"Linked List Before DeleteAtPos():\n";
    dobj.Display();

    dobj.DeleteAtPos(3);

    cout<<"\nLinked List After DeleteAtPos():\n";
    dobj.Display();

    cout<<"\nNumber of Nodes : "<<dobj.Count()<<"\n";

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Linked List Before DeleteAtPos():

<=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Linked List After DeleteAtPos():

<=> | 11 | <=> | 21 | <=> | 101 | <=> | 111 | <=>

Number of Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

Before:

11 <=> 21 <=> 51 <=> 101 <=> 111

DeleteAtPos(3)

After:

11 <=> 21 <=> 101 <=> 111

===============================================================================
Algorithm:
===============================================================================

1. Validate the position.
2. If position is 1:
      Call DeleteFirst().
3. If position is Count():
      Call DeleteLast().
4. Otherwise:
      Traverse up to Position-1.
      Store node to delete.
      Adjust next and prev links.
      Delete node.
      Decrement node count.

===============================================================================
Time Complexity:
===============================================================================

DeleteFirst() : O(1)

DeleteLast()  : O(1)

DeleteAtPos() : O(n)

Display()     : O(n)

Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates deletion of a node from a specified
position in a Doubly Circular Linked List while maintaining
the circular and doubly linked structure correctly.

===============================================================================
*/

/*
===============================================================================
Program Name    : Doubly Linear Linked List - Insert At Position
Program Number  : 008
File Name       : DoublyLL08.cpp

Description     : This program demonstrates insertion of a node
                  at a specific position in a Doubly Linear
                  Linked List using C++.

                  The InsertAtPos() function inserts a new node
                  at the desired position while maintaining
                  proper next and previous links.

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Memory Deallocation using delete
6. Pointer Manipulation
7. Position Validation
8. Doubly Linked List

Key Learning Points:
- Insert nodes at beginning.
- Insert nodes at end.
- Insert nodes at a specific position.
- Validate positions.
- Update next and previous links.
- Count total nodes.

===============================================================================
*/

#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

typedef class node NODE;
typedef class node *PNODE;

class DoublyLL
{
private:
    PNODE first;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);

    void DeleteFirst();
    void DeleteLast();
};

DoublyLL::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

void DoublyLL::Display()
{
    PNODE temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

int DoublyLL::Count()
{
    return iCount;
}

void DoublyLL::InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

void DoublyLL::InsertLast(int no)
{
    PNODE newn = new NODE;
    PNODE temp = first;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

void DoublyLL::InsertAtPos(int no, int iPos)
{
    int i = 0;
    PNODE temp = NULL;
    PNODE newn = NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
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
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

void DoublyLL::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;

        first = first->next;
        first->prev = NULL;

        delete temp;
    }

    iCount--;
}

void DoublyLL::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        PNODE temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

int main()
{
    DoublyLL dobj;

    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);

    dobj.Display();

    dobj.InsertAtPos(51,3);

    cout<<"\nAfter InsertAtPos:\n";

    dobj.Display();

    cout<<"Number of nodes are : "
        <<dobj.Count()<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 101 | <=> | 111 | <=> NULL

After InsertAtPos:

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

Before InsertAtPos()

NULL <- [11] <=> [21] <=> [101] <=> [111] -> NULL

After InsertAtPos(51,3)

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

===============================================================================
Algorithm:
===============================================================================

InsertAtPos()

1. Validate the position.
2. If position is 1, call InsertFirst().
3. If position is Count()+1, call InsertLast().
4. Otherwise:
      Traverse to (position - 1) node.
      Create a new node.
      Connect new node with next node.
      Connect previous node with new node.
5. Increment node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)
InsertLast()  : O(n)
InsertAtPos() : O(n)
DeleteFirst() : O(1)
DeleteLast()  : O(n)
Display()     : O(n)
Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates insertion of a node at a specific
position in a Doubly Linear Linked List. The InsertAtPos()
function validates the position and correctly updates both
next and previous links to maintain the structure of the list.

===============================================================================
*/

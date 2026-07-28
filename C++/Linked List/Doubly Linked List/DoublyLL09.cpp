/*
===============================================================================
Program Name    : Doubly Linear Linked List - Delete At Position
Program Number  : 009
File Name       : DoublyLL_09.cpp

Description     : This program demonstrates deletion of a node
                  from a specific position in a Doubly Linear
                  Linked List using C++.

                  The DeleteAtPos() function removes the node
                  from the desired position while maintaining
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
- Delete nodes from beginning.
- Delete nodes from end.
- Delete nodes from a specific position.
- Validate positions.
- Update next and previous links.
- Maintain linked list integrity.

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
    void DeleteAtPos(int);
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

void InsertAtPos(int no, int iPos);     // Previously Implemented

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

void DoublyLL::DeleteAtPos(int iPos)
{
    PNODE temp = first;
    int i = 0;

    if((iPos < 1) || (iPos > iCount))
    {
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
        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

int main()
{
    DoublyLL dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);

    dobj.Display();

    dobj.DeleteAtPos(3);

    cout<<"\nAfter DeleteAtPos:\n";

    dobj.Display();

    cout<<"Number of nodes are : "
        <<dobj.Count()<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

After DeleteAtPos:

| 11 | <=> | 21 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

Before DeleteAtPos(3)

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

After DeleteAtPos(3)

NULL <- [11] <=> [21] <=> [101] <=> [111] -> NULL

===============================================================================
Algorithm:
===============================================================================

DeleteAtPos()

1. Validate the position.
2. If position is 1, call DeleteFirst().
3. If position is Count(), call DeleteLast().
4. Otherwise:
      Traverse to (position - 1) node.
      Bypass the target node.
      Update next and previous links.
      Delete the target node.
5. Decrement node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)
InsertLast()  : O(n)
InsertAtPos() : O(n)
DeleteFirst() : O(1)
DeleteLast()  : O(n)
DeleteAtPos() : O(n)
Display()     : O(n)
Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates deletion of a node from a specific
position in a Doubly Linear Linked List. The DeleteAtPos()
function validates the position, removes the target node,
and correctly maintains both next and previous links.

===============================================================================
*/

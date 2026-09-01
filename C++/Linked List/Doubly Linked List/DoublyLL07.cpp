/*
===============================================================================
Program Name    : Doubly Linear Linked List - Delete Last
Program Number  : 007
File Name       : DoublyLL07.cpp

Description     : This program demonstrates deletion of the
                  last node from a Doubly Linear Linked List 
                  using C++.

                  The DeleteLast() function removes the last
                  node and updates the link of the second last
                  node while maintaining proper next and
                  previous connections.

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
7. Doubly Linked List
8. Traversal

Key Learning Points:
- Insert nodes at beginning.
- Insert nodes at end.
- Delete first node.
- Delete last node.
- Handle empty and single node cases.
- Maintain proper links.
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

    dobj.InsertLast(51);
    dobj.InsertLast(101);
    dobj.InsertLast(111);

    dobj.Display();

    dobj.DeleteLast();

    cout<<"\nAfter deleting last node:\n";

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

After deleting last node:

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> NULL

Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

Before DeleteLast()

first
  |
  v

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

After DeleteLast()

first
  |
  v

NULL <- [11] <=> [21] <=> [51] <=> [101] -> NULL

===============================================================================
Algorithm:
===============================================================================

DeleteLast()

1. Check if linked list is empty.
2. If only one node exists:
      Delete the node.
      Set first to NULL.
3. Otherwise:
      Traverse to second last node.
      Delete last node.
      Set second last node's next to NULL.
4. Decrement node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)
InsertLast()  : O(n)
DeleteFirst() : O(1)
DeleteLast()  : O(n)
Display()     : O(n)
Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates deletion of the last node from a
Doubly Linear Linked List. The DeleteLast() function traverses
to the second last node, removes the last node, and maintains
the integrity of the linked list.

===============================================================================
*/

/*
===============================================================================
Program Name    : Doubly Linear Linked List - Delete First
Program Number  : 006
File Name       : DoublyLL06.cpp

Description     : This program demonstrates deletion of the
                  first node from a Doubly Linear Linked List
                  using C++.

                  The DeleteFirst() function removes the first
                  node and updates the head pointer while
                  maintaining proper next and previous links.

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

Key Learning Points:
- Insert nodes at beginning.
- Insert nodes at end.
- Delete first node.
- Update next and previous links.
- Handle empty and single node cases.
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

int main()
{
    DoublyLL dobj;

    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(51);
    dobj.InsertLast(101);
    dobj.InsertLast(111);

    dobj.Display();

    dobj.DeleteFirst();

    cout<<"\nAfter deleting first node:\n";

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

After deleting first node:

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

Number of nodes are : 4

===============================================================================
Memory Representation:
===============================================================================

Before DeleteFirst()

first
  |
  v

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

After DeleteFirst()

first
  |
  v

NULL <- [21] <=> [51] <=> [101] <=> [111] -> NULL

===============================================================================
Algorithm:
===============================================================================

DeleteFirst()

1. Check if linked list is empty.
2. If only one node exists:
      Delete that node.
      Set first to NULL.
3. Otherwise:
      Store first node in temp.
      Move first to next node.
      Set first->prev to NULL.
      Delete temp node.
4. Decrement node count.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)
InsertLast()  : O(n)
DeleteFirst() : O(1)
Display()     : O(n)
Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates deletion of the first node from a
Doubly Linear Linked List. The DeleteFirst() function safely
removes the first node and updates the head pointer while
maintaining proper previous and next links.

===============================================================================
*/

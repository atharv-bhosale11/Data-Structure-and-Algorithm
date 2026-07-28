/*
===============================================================================
Program Name    : Doubly Linear Linked List - Insert Last
Program Number  : 005
File Name       : DoublyLL05.cpp

Description     : This program demonstrates insertion of a node
                  at the end of a Doubly Linear Linked List
                  using C++.

                  The InsertLast() function creates a new node
                  and inserts it as the last node of the linked
                  list while maintaining proper next and previous
                  links.

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Dynamic Memory Allocation using new
5. Pointer Manipulation
6. Doubly Linked List
7. Traversal

Key Learning Points:
- Create nodes dynamically.
- Insert node at the beginning.
- Insert node at the end.
- Traverse the linked list.
- Maintain next and previous links.
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

int main()
{
    DoublyLL dobj;

    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(51);
    dobj.InsertLast(101);
    dobj.InsertLast(111);

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

Number of nodes are : 5

===============================================================================
Memory Representation:
===============================================================================

first
  |
  v

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

===============================================================================
Algorithm:
===============================================================================

InsertLast()

1. Create a new node.
2. Store data in the node.
3. If linked list is empty:
      Make new node as first.
4. Otherwise:
      Traverse till the last node.
      Connect last node to new node.
      Set previous link of new node.
5. Increment node count.
6. Display the linked list.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)
InsertLast()  : O(n)
Display()     : O(n)
Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates insertion at the end of a Doubly
Linear Linked List. The InsertLast() function traverses the
linked list to reach the last node and attaches a new node
while maintaining proper next and previous links.

===============================================================================
*/

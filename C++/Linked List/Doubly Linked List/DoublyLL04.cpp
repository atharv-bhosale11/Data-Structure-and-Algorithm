/*
===============================================================================
Program Name    : Doubly Linear Linked List - Insert First
Program Number  : 004
File Name       : DoublyLL04.cpp

Description     : This program demonstrates insertion of a node
                  at the beginning of a Doubly Linear Linked List
                  using C++.

                  The InsertFirst() function creates a new node
                  and inserts it as the first node of the linked
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
7. Constructor

Key Learning Points:
- Create nodes dynamically.
- Insert node at the beginning.
- Update next and previous links.
- Maintain head pointer.
- Display linked list.
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
        cout<<"NULL <=> | "<<temp->data<<" | <=> ";
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

int main()
{
    DoublyLL dobj;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();

    cout<<"Number of nodes are : "
        <<dobj.Count()<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

NULL <=> | 11 | <=> NULL <=> | 21 | <=> NULL <=> | 51 | <=> NULL

Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

first
  |
  v

NULL <- [11] <=> [21] <=> [51] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store data in the node.
3. If linked list is empty, make new node as first.
4. Otherwise:
   - Connect new node to current first node.
   - Update previous link of first node.
   - Move first pointer to new node.
5. Increment node count.
6. Display the linked list.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst() : O(1)
Display()     : O(n)
Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates insertion at the beginning of a Doubly
Linear Linked List. The InsertFirst() function efficiently inserts
a node in constant time by updating the first pointer and maintaining
proper next and previous links.

===============================================================================
*/

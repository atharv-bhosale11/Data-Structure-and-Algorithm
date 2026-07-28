/*

Program Name    : Doubly Linear Linked List - Complete Implementation
Program Number  : 010
File Name       : DoublyLL10.cpp

Description     : This program demonstrates a complete implementation
of Doubly Linear Linked List using C++.

```
              Operations Included:
              1. Insert First
              2. Insert Last
              3. Insert At Position
              4. Delete First
              5. Delete Last
              6. Delete At Position
              7. Display
              8. Count
```

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale
=======================================
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

void DoublyLL::InsertAtPos(int no, int iPos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int i = 0;

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
    dobj.InsertLast(121);

    dobj.Display();

    cout<<"Count : "<<dobj.Count()<<"\n";

    dobj.DeleteFirst();
    dobj.Display();

    dobj.DeleteLast();
    dobj.Display();

    dobj.InsertAtPos(75,3);
    dobj.Display();

    dobj.DeleteAtPos(3);
    dobj.Display();

    cout<<"Count : "<<dobj.Count()<<"\n";

    return 0;
}

/*

# Expected Output:

Linked List after Insert Operations:
| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Node Count : 6

After DeleteFirst:
| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

After DeleteLast:
| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

After InsertAtPos(75,3):
| 21 | <=> | 51 | <=> | 75 | <=> | 101 | <=> | 111 | <=> NULL

After DeleteAtPos(3):
| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL

Final Node Count : 4

===============================================================================
Time Complexity:
================

InsertFirst()      : O(1)
InsertLast()       : O(n)
InsertAtPos()      : O(n)

DeleteFirst()      : O(1)
DeleteLast()       : O(n)
DeleteAtPos()      : O(n)

Display()          : O(n)
Count()            : O(1)

Space Complexity   : O(1)

===============================================================================
Conclusion:
===========

This program demonstrates all basic operations of a Doubly Linear Linked
List using C++. It covers insertion, deletion, traversal, counting of
nodes, and proper maintenance of next and previous links.

===============================================================================
*/

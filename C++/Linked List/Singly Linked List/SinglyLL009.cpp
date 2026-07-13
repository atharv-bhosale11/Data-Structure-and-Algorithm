/*
=====================================================================

Program Name    : Singly Linked List - Display Function (C++)
Program Number  : 009
Description     : This program demonstrates the creation of a
                  Singly Linked List class in C++ and implements
                  the Display() member function. The Display()
                  function traverses the linked list from the
                  first node and prints all node elements.

Concepts Used   : C++, Class, Constructor,
                  Self-Referential Structure,
                  Dynamic Data Structure,
                  Encapsulation, Traversal

Input           : None

Output          : Displays all nodes present in the linked list.
                  Since no nodes are inserted, only NULL is shown.

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        SinglyLL();
        void Display();
        int Count();
        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

SinglyLL::SinglyLL()
{
    this -> first = NULL;
    this -> iCount = 0;
}

void SinglyLL::Display()
{
    PNODE temp = NULL;
    temp = this -> first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

int SinglyLL::Count()
{
    return this->iCount;
}

void SinglyLL::InsertFirst(int iNo)
{}

void SinglyLL::InsertLast(int iNo)
{}

void SinglyLL::InsertAtPos(int iNo, int iPos)
{}

void SinglyLL::DeleteFirst()
{}

void SinglyLL::DeleteLast()
{}

void SinglyLL::DeleteAtPos(int iPos)
{}

int main()
{
    SinglyLL sobj;

    sobj.Display();

    return 0;
}

/*
=====================================================================

Expected Output :

NULL

Explanation :
The constructor initializes the linked list by
setting the first pointer to NULL and node count
(iCount) to 0.

The Display() function creates a temporary pointer
(temp) and starts traversal from the first node.

Since no nodes are inserted into the linked list,
the first pointer remains NULL.

Traversal Flow :

first
  |
  v
 NULL

As the while condition fails immediately,
the loop does not execute and only NULL is printed.

Operations Performed :
1. Created SinglyLL object.
2. Constructor initialized first = NULL.
3. Called Display() function.
4. Traversal started from first.
5. No nodes found in the linked list.
6. Displayed NULL.

Conclusion :
The Display() function successfully handles an
empty linked list and safely terminates traversal
when the first pointer is NULL.

=====================================================================
*/

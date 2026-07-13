/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst() and InsertLast()
Program Number  : 011
Description     : This program demonstrates the implementation of
                  InsertFirst() and InsertLast() member functions
                  in a Singly Linked List using C++ classes.

                  InsertFirst() inserts a new node at the beginning
                  of the linked list, while InsertLast() inserts a
                  new node at the end of the linked list.

                  The program also demonstrates traversal using
                  Display() and node counting using Count().

Concepts Used   : C++, Classes, Objects, Constructor,
                  Self-Referential Structure,
                  Dynamic Memory Allocation (new),
                  Encapsulation, Traversal,
                  Insertion Operations

Input           : Node values inserted through function calls.

Output          : Displays linked list contents after insertion
                  operations and total number of nodes.

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

void SinglyLL:: Display()
{
    PNODE temp = NULL;
    temp = this -> first;

    while(temp != NULL)
    {
        cout<<"| "<<temp -> data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

int SinglyLL:: Count()
{
    return this -> iCount;
}

void  SinglyLL:: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if(this -> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
    }

    this -> iCount++;
}

void  SinglyLL:: InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if(this -> first == NULL)
    {
        this -> first = newn;
    }
    else
    {
        temp = this -> first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }

    this -> iCount++;
}

void  SinglyLL:: InsertAtPos(int iNo, int iPos)
{}

void  SinglyLL:: DeleteFirst()
{}

void  SinglyLL:: DeleteLast()
{}

void  SinglyLL:: DeleteAtPos(int iPos)
{}

int main()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();

    iRet = sobj.Count();
    cout<<"Number of Elements are: "<<iRet<<endl;

    return 0;
}

/*
=====================================================================

Expected Output :

| 11 |-> | 21 |-> | 51 |-> NULL
Number of Elements are: 3

| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL
Number of Elements are: 6

Explanation :

InsertFirst() Operation :

1. InsertFirst(51)
   NULL
     |
     v
   [51|NULL]

2. InsertFirst(21)
   [21|*] -> [51|NULL]

3. InsertFirst(11)
   [11|*] -> [21|*] -> [51|NULL]

InsertLast() Operation :

4. InsertLast(101)
   [11] -> [21] -> [51] -> [101|NULL]

5. InsertLast(111)
   [11] -> [21] -> [51] -> [101] -> [111|NULL]

6. InsertLast(121)
   [11] -> [21] -> [51] -> [101] -> [111] -> [121|NULL]

Count Tracking :

After InsertFirst operations :
iCount = 3

After InsertLast operations :
iCount = 6

Operations Performed :

1. Created Singly Linked List object.
2. Inserted nodes at the beginning using InsertFirst().
3. Displayed linked list contents.
4. Counted total nodes using Count().
5. Inserted nodes at the end using InsertLast().
6. Displayed updated linked list.
7. Verified node count after insertions.

Conclusion :

This program successfully demonstrates insertion at
both the beginning and end of a Singly Linked List
using object-oriented programming in C++. The node
count is maintained efficiently using the iCount
member variable.

=====================================================================
*/

/*
=====================================================================

Program Name    : Singly Linked List - Using iCount for Empty List Check
Program Number  : 012
Description     : This program demonstrates insertion operations in a
                  Singly Linked List using C++.

                  Instead of checking whether the first pointer is
                  NULL, the program uses the iCount member variable
                  to determine whether the linked list is empty.

                  InsertFirst() inserts nodes at the beginning,
                  while InsertLast() inserts nodes at the end of
                  the linked list.

Concepts Used   : C++, Classes, Objects, Constructor,
                  Self-Referential Structure,
                  Dynamic Memory Allocation,
                  Encapsulation,
                  Traversal,
                  InsertFirst(),
                  InsertLast(),
                  Node Counter (iCount)

Input           : Node values inserted through function calls.

Output          : Displays linked list contents after insertion
                  operations and total node count.

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

    if(iCount == 0)                         // 2nd Approach
    {
        this -> first = newn;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
    }
    this -> iCount++;                               // Important
}

void  SinglyLL:: InsertLast(int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if(iCount == 0)                         // 2nd Approach
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
    this -> iCount++;                              // Important
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

    sobj.InsertFirst(51);                // InsertFirst(sobj,51)
    sobj.InsertFirst(21);                // InsertFirst(sobj,21)
    sobj.InsertFirst(11);                // InsertFirst(sobj,11)

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

Initially :

first = NULL
iCount = 0

InsertFirst() Operations :

1. InsertFirst(51)

first
  |
  v
[51|NULL]

iCount = 1

2. InsertFirst(21)

first
  |
  v
[21|*] -> [51|NULL]

iCount = 2

3. InsertFirst(11)

first
  |
  v
[11|*] -> [21|*] -> [51|NULL]

iCount = 3

InsertLast() Operations :

4. InsertLast(101)

[11] -> [21] -> [51] -> [101|NULL]

iCount = 4

5. InsertLast(111)

[11] -> [21] -> [51] -> [101] -> [111|NULL]

iCount = 5

6. InsertLast(121)

[11] -> [21] -> [51] -> [101] -> [111] -> [121|NULL]

iCount = 6

Important Concept :

Instead of checking

if(this->first == NULL)

the program uses

if(iCount == 0)

to determine whether the linked list is empty.

Advantages :

1. Logical representation of list size.
2. Directly indicates whether list contains nodes.
3. Useful for future insertion and deletion operations.
4. Eliminates repeated pointer comparison.

Operations Performed :

1. Created Singly Linked List object.
2. Inserted three nodes using InsertFirst().
3. Displayed linked list contents.
4. Counted total nodes.
5. Inserted three nodes using InsertLast().
6. Displayed updated linked list.
7. Verified node count after all insertions.

Conclusion :

This program demonstrates how the iCount member
variable can be used to identify an empty linked
list instead of checking the first pointer directly.
The linked list supports insertion at both beginning
and end while maintaining an accurate node count.

=====================================================================
*/

/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst Operation (C++)
Program Number  : 010
Description     : This program demonstrates the implementation
                  of the InsertFirst() member function in a
                  Singly Linked List using a C++ class.

                  New nodes are dynamically allocated using
                  the new operator and inserted at the
                  beginning of the linked list.

                  The program also maintains the total
                  number of nodes using the iCount variable.

Concepts Used   : C++, Classes, Constructor,
                  Dynamic Memory Allocation,
                  Self-Referential Structure,
                  Encapsulation,
                  InsertFirst Operation,
                  Node Counting

Input           : Node values (11, 21, 51)

Output          : Displays the linked list after insertion
                  and prints the total number of nodes.

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
    this -> iCount++;                               // Important
}

void  SinglyLL:: InsertLast(int iNo)
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

    return 0;
}

/*
=====================================================================

Expected Output :

| 11 |-> | 21 |-> | 51 |-> NULL
Number of Elements are: 3

Explanation :

Initially :

first  = NULL
iCount = 0

--------------------------------------------------

InsertFirst(51)

first
 |
 v
+----+------+
| 51 | NULL |
+----+------+

iCount = 1

--------------------------------------------------

InsertFirst(21)

first
 |
 v
+----+------+    +----+------+
| 21 |   o------>| 51 | NULL |
+----+------+    +----+------+

iCount = 2

--------------------------------------------------

InsertFirst(11)

first
 |
 v
+----+------+    +----+------+    +----+------+
| 11 |   o------>| 21 |   o------>| 51 | NULL |
+----+------+    +----+------+    +----+------+

iCount = 3

--------------------------------------------------

Display Traversal :

11 -> 21 -> 51 -> NULL

--------------------------------------------------

Count Function :

The Count() function returns the value of iCount.

iCount = 3

--------------------------------------------------

Operations Performed :

1. Created SinglyLL object.
2. Constructor initialized first to NULL.
3. Constructor initialized iCount to 0.
4. Inserted node 51 at first position.
5. Inserted node 21 at first position.
6. Inserted node 11 at first position.
7. Incremented iCount after every insertion.
8. Displayed all nodes.
9. Returned total node count.

Time Complexity :

InsertFirst() : O(1)
Display()     : O(N)
Count()       : O(1)

Conclusion :

InsertFirst() is one of the most efficient
linked list operations because insertion
occurs directly at the beginning of the list.

No traversal is required, resulting in
constant time complexity O(1).

=====================================================================
*/

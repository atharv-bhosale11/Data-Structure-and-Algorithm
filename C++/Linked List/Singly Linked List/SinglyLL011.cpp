/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst and InsertLast
Program Number  : 007
Description     : This program demonstrates the implementation
                  of InsertFirst() and InsertLast() operations
                  in a Singly Linked List using C++ classes.

                  InsertFirst() inserts a new node at the
                  beginning of the linked list, while
                  InsertLast() inserts a new node at the
                  end of the linked list.

Concepts Used   : C++, Classes, Constructor,
                  Dynamic Memory Allocation,
                  Encapsulation,
                  Self-Referential Structure,
                  Linked List Traversal,
                  Insert Operations

Input           : Node values
                  (11, 21, 51, 101, 111, 121)

Output          : Displays the linked list after
                  insertion operations and shows
                  the total node count.

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

Initially the linked list is empty.

InsertFirst Operations :

InsertFirst(51)

11st Step:
first
  |
  v
+----+------+
| 51 | NULL |
+----+------+

InsertFirst(21)

first
  |
  v
+----+------+    +----+------+
| 21 |   o------>| 51 | NULL |
+----+------+    +----+------+

InsertFirst(11)

first
  |
  v
+----+------+    +----+------+    +----+------+
| 11 |   o------>| 21 |   o------>| 51 | NULL |
+----+------+    +----+------+    +----+------+

Node Count = 3

--------------------------------------------------

InsertLast Operations :

InsertLast(101)

| 11 |-> | 21 |-> | 51 |-> | 101 |-> NULL

InsertLast(111)

| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 111 |-> NULL

InsertLast(121)

| 11 |-> | 21 |-> | 51 |-> | 101 |-> | 111 |-> | 121 |-> NULL

Node Count = 6

Traversal of InsertLast :

first
  |
  v
11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

For every InsertLast() call:
1. Temporary pointer starts from first.
2. Traverses up to the last node.
3. New node is attached to the last node.
4. iCount is incremented.

Operations Performed :

1. Created Singly Linked List object.
2. Inserted three nodes using InsertFirst().
3. Displayed linked list.
4. Counted total nodes.
5. Inserted three nodes using InsertLast().
6. Traversed list to locate last node.
7. Attached new nodes at the end.
8. Updated node count.
9. Displayed final linked list.

Time Complexity :

InsertFirst() : O(1)
InsertLast()  : O(N)

Conclusion :

InsertFirst() is a constant-time operation because
the first pointer is directly updated.

InsertLast() requires traversal to locate the last
node before attaching the new node, making it a
linear-time operation.

=====================================================================
*/

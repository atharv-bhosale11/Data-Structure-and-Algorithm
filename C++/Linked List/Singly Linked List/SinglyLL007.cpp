/*
=====================================================================

Program Name    : Singly Linked List Class Skeleton
Program Number  : 007
Description     : This program demonstrates the basic
                  structure of a Singly Linked List
                  class. It introduces data hiding,
                  member functions, and the overall
                  framework required for implementing
                  linked list operations in C++.

Concepts Used   : Class,
                  Object,
                  Constructor,
                  Encapsulation,
                  Data Hiding,
                  Member Functions,
                  Self-Referential Structure

Input           : None

Output          : Displays a constructor message.

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
        SinglyLL()
        {
            cout<<"Inside Constructor\n";

            this->first = NULL;
            this->iCount = 0;
        }

        void Display()
        {}

        int Count()
        {
            return this->iCount;
        }

        void InsertFirst(int iNo)
        {}

        void InsertLast(int iNo)
        {}

        void InsertAtPos(int iNo, int iPos)
        {}

        void DeleteFirst()
        {}

        void DeleteLast()
        {}

        void DeleteAtPos(int iPos)
        {}
};

int main()
{
    SinglyLL sobj;

    return 0;
}

/*
=====================================================================

Expected Output :

Inside Constructor

Explanation :

This program creates a blueprint for a
Singly Linked List using a class.

Private Data Members :

1. first
   - Stores the address of the first node.

2. iCount
   - Stores the total number of nodes.

Public Member Functions :

Display()
    Displays all nodes of the linked list.

Count()
    Returns the number of nodes.

InsertFirst()
    Inserts a node at the beginning.

InsertLast()
    Inserts a node at the end.

InsertAtPos()
    Inserts a node at a specified position.

DeleteFirst()
    Deletes the first node.

DeleteLast()
    Deletes the last node.

DeleteAtPos()
    Deletes a node from a specified position.

Class Layout :

+---------------------------+
|         SinglyLL          |
+---------------------------+
| first     (private)       |
| iCount    (private)       |
+---------------------------+
| Display()                |
| Count()                  |
| InsertFirst()            |
| InsertLast()             |
| InsertAtPos()            |
| DeleteFirst()            |
| DeleteLast()             |
| DeleteAtPos()            |
+---------------------------+

Program Flow :

Create Object
      |
      v
Constructor Called
      |
      v
Initialize first = NULL
Initialize iCount = 0
      |
      v
Object Ready for Operations

Operations Performed :

1. Defined a node structure.
2. Created a Singly Linked List class.
3. Applied data hiding using private members.
4. Declared all linked list operations.
5. Initialized class members in constructor.
6. Created an object of the class.

Conclusion :

This program provides the complete skeleton
for implementing a Singly Linked List in C++.
The actual logic for insertion, deletion,
display, and counting will be implemented
in subsequent programs.

=====================================================================
*/

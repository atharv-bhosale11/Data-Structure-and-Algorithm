/*
=====================================================================

Program Name    : Singly Linked List - Separate Member Function
                  Definitions Using Scope Resolution Operator
Program Number  : 008
Description     : This program demonstrates how to declare
                  member functions inside a class and define
                  them outside the class using the Scope
                  Resolution Operator (::). This approach
                  improves code organization and readability.

Concepts Used   : Class,
                  Object,
                  Constructor,
                  Scope Resolution Operator,
                  Function Declaration,
                  Function Definition,
                  Encapsulation

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
    cout<<"Inside Constructor\n";
    this->first = NULL;
    this->iCount = 0;
}

void SinglyLL::Display()
{}

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

    return 0;
}

/*
=====================================================================

Expected Output :

Inside Constructor

Explanation :

In this program, only function declarations
are written inside the class definition.

Actual function implementations are written
outside the class using the Scope Resolution
Operator (::).

Example :

Class Declaration :

class SinglyLL
{
    public:
        void Display();
};

Function Definition :

void SinglyLL::Display()
{
}

Advantages :

1. Improves code readability.
2. Separates interface from implementation.
3. Makes large programs easier to maintain.
4. Follows standard Object-Oriented design.

Class Structure :

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
first = NULL
iCount = 0
      |
      v
Object Ready for Operations
      |
      v
Program Ends

Operations Performed :

1. Defined node structure.
2. Created Singly Linked List class.
3. Declared member functions inside class.
4. Defined member functions outside class.
5. Used Scope Resolution Operator (::).
6. Created an object of the class.

Conclusion :

The Scope Resolution Operator allows member
functions to be implemented outside the class,
resulting in cleaner and more maintainable
Object-Oriented code.

=====================================================================
*/

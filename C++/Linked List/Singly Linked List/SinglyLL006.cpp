/*
=====================================================================

Program Name    : Data Hiding Using Private Members
Program Number  : 006
Description     : This program demonstrates the concept
                  of Data Hiding in Object-Oriented
                  Programming. The linked list data
                  members are declared as private,
                  preventing direct access from outside
                  the class.

Concepts Used   : Class,
                  Object,
                  Constructor,
                  Access Specifiers,
                  Data Hiding,
                  Encapsulation,
                  Private Members

Input           : None

Output          : Compilation Error

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
typedef struct node **PPNODE;

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
};

int main()
{
    SinglyLL sobj;

    // Assume Linked List contains 5 nodes

    sobj.first = NULL;      // Error
    sobj.iCount = 15;       // Error

    return 0;
}

/*
=====================================================================

Expected Output :

Compilation Error

Example Error :

error: 'node* SinglyLL::first' is private
within this context

error: 'int SinglyLL::iCount' is private
within this context

Explanation :

The members first and iCount are declared
inside the private section of the class.

Private members can only be accessed by:

1. Member functions of the same class.
2. Friend functions (if declared).
3. Friend classes (if declared).

They cannot be accessed directly using
an object outside the class.

Incorrect Statements :

sobj.first = NULL;
sobj.iCount = 15;

These statements generate compilation
errors because both members are private.

Class Layout :

+-----------------------+
|      SinglyLL         |
+-----------------------+
| first   (private)     |
| iCount  (private)     |
+-----------------------+
| Constructor()         |
+-----------------------+

Benefits of Private Members :

1. Prevents accidental modification.
2. Protects internal data.
3. Maintains data integrity.
4. Implements Encapsulation.
5. Improves software reliability.

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
Attempt Direct Access
      |
      v
Compilation Error

Operations Performed :

1. Created a linked list class.
2. Declared first and iCount as private.
3. Initialized them in the constructor.
4. Attempted direct access from main().
5. Compiler prevented unauthorized access.

Conclusion :

Declaring important data members as private
protects the internal state of the linked
list. This is one of the fundamental principles
of Object-Oriented Programming known as
Data Hiding or Encapsulation.

=====================================================================
*/

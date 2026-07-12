/*
=====================================================================

Program Name    : Introduction to Singly Linked List Class
Program Number  : 003
Description     : This program demonstrates the creation
                  of a Singly Linked List class. It
                  introduces the constructor concept and
                  initializes the head pointer of the
                  linked list to NULL.

Concepts Used   : Class,
                  Object,
                  Constructor,
                  Self-Referential Structure,
                  Pointer Initialization

Input           : None

Output          : Displays a message indicating that the
                  constructor has been executed.

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
    public:
        PNODE first;

        SinglyLL()
        {
            cout<<"Inside Constructor\n";
            this->first = NULL;
        }
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

A class named SinglyLL is created to
represent a Singly Linked List.

The class contains:

1. first
   - Head pointer of the linked list.
   - Stores the address of the first node.

2. Constructor
   - Automatically called when an object
     of the class is created.
   - Initializes first to NULL.

Memory Representation :

sobj
 |
 +------------------+
 | first = NULL     |
 +------------------+

Since no nodes are created yet, the linked
list is empty and the head pointer points
to NULL.

Program Flow :

Create Object
      |
      v
Constructor Called
      |
      v
first = NULL
      |
      v
Display Message
      |
      v
Program Ends

Operations Performed :

1. Defined a node structure.
2. Created a SinglyLL class.
3. Added a head pointer as a data member.
4. Initialized the head pointer in the constructor.
5. Created an object of the class.
6. Executed the constructor automatically.

Conclusion :

The constructor is used to initialize the
linked list object. Setting the head pointer
to NULL ensures that the list starts in an
empty state before any nodes are inserted.

=====================================================================
*/

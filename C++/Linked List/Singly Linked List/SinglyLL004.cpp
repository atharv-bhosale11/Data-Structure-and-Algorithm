/*
=====================================================================

Program Name    : Singly Linked List Class with Node Counter
Program Number  : 004
Description     : This program demonstrates the creation
                  of a Singly Linked List class containing
                  a head pointer and a node counter.
                  The constructor initializes the linked
                  list to an empty state and the values
                  are displayed to verify initialization.

Concepts Used   : Class,
                  Object,
                  Constructor,
                  Self-Referential Structure,
                  Pointer Initialization,
                  Data Members

Input           : None

Output          : Displays the initial values of the
                  head pointer and node count.

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
        int iCount;

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

    cout<<sobj.first<<endl;
    cout<<sobj.iCount<<endl;

    return 0;
}

/*
=====================================================================

Expected Output :

Inside Constructor
0
0

(Note: The NULL pointer may appear as 0,
0x0, or nullptr depending on the compiler.)

Explanation :

The SinglyLL class contains two data members:

1. first
   - Head pointer of the linked list.
   - Initially set to NULL because the
     linked list is empty.

2. iCount
   - Stores the number of nodes present
     in the linked list.
   - Initially set to 0.

Memory Representation :

sobj
 |
 +----------------------+
 | first  = NULL        |
 | iCount = 0           |
 +----------------------+

When the object is created:

1. Constructor is called automatically.
2. first is initialized to NULL.
3. iCount is initialized to 0.
4. Values are displayed on the screen.

Program Flow :

Create Object
      |
      v
Constructor Called
      |
      +--> first = NULL
      |
      +--> iCount = 0
      |
      v
Display Values
      |
      v
Program Ends

Operations Performed :

1. Defined a node structure.
2. Created a Singly Linked List class.
3. Added head pointer and node counter.
4. Initialized members using constructor.
5. Created an object of the class.
6. Displayed initialized values.

Conclusion :

Every linked list object should maintain a
head pointer and a node counter. Initializing
them in the constructor ensures that the list
starts in a valid and predictable state.

=====================================================================
*/

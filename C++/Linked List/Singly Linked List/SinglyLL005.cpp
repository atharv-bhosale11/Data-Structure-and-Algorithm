/*
=====================================================================

Program Name    : Drawback of Public Data Members in Linked List
Program Number  : 005
Description     : This program demonstrates the drawback of
                  declaring linked list data members as
                  public. Since the members are directly
                  accessible from outside the class, they
                  can be modified unintentionally, leading
                  to loss of data integrity.

Concepts Used   : Class,
                  Object,
                  Constructor,
                  Access Specifiers,
                  Encapsulation,
                  Data Hiding

Input           : None

Output          : No Output

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
            this->first = NULL;
            this->iCount = 0;
        }
};

int main()
{
    SinglyLL sobj;

    // Assume Linked List contains 5 nodes

    sobj.first = NULL;      // Drawback
    sobj.iCount = 15;       // Drawback

    return 0;
}

/*
=====================================================================

Expected Output :

(No Output)

Explanation :

The data members first and iCount are
declared as public.

Because of this, they can be directly
accessed and modified from outside the class.

Example :

sobj.first = NULL;
sobj.iCount = 15;

Problems :

1. first stores the address of the first node.
   Setting it to NULL disconnects the entire
   linked list.

2. iCount stores the number of nodes.
   Assigning an arbitrary value such as 15
   makes the count incorrect.

Suppose Actual State :

Linked List :
11 -> 21 -> 51 -> 101 -> 111 -> NULL

iCount = 5

After Modification :

sobj.first = NULL;
sobj.iCount = 15;

Linked List :
NULL

iCount = 15

The actual nodes still exist in memory,
but the list can no longer access them.

Program Flow :

Create Object
      |
      v
Constructor Executes
      |
      v
first = NULL
iCount = 0
      |
      v
External Modification
      |
      +--> first = NULL
      |
      +--> iCount = 15
      |
      v
Data Integrity Lost

Operations Performed :

1. Created a linked list class.
2. Declared data members as public.
3. Created an object.
4. Modified internal members directly.
5. Demonstrated the drawback of public access.

Conclusion :

Important data members such as first and
iCount should not be public. They should be
declared private and accessed only through
member functions. This concept is known as
Encapsulation and helps protect the internal
state of the linked list.

=====================================================================
*/

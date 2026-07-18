/*
=====================================================================

Name            : Singly Circular Linked List - Constructor Initialization
Program Number  : 009
Description     : This program demonstrates the creation of a
                  Singly Circular Linked List class with a
                  parameterized node constructor and a list
                  constructor.

                  The constructor initializes the first pointer,
                  last pointer, and node count to their default
                  values.

Concepts Used   : Singly Circular Linked List,
                  Constructor,
                  Parameterized Constructor,
                  Object-Oriented Programming,
                  Reference Variables,
                  Class Initialization

Input           : None

Output          : Object creation of Singly Circular Linked List

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale

=====================================================================
*/

class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    public node first;
    public node last;
    public int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }
}

class SinglyCL09
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();
    }
}

/*
=====================================================================

Sample Output :

(No Output)

=====================================================================

Observation :

- Node class contains a parameterized constructor.
- SinglyCL class contains first and last references.
- Constructor initializes list to empty state.
- Node count is initialized to zero.
- Linked List object is created successfully.

=====================================================================
*/

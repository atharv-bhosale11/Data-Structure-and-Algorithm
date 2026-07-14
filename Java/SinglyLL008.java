/*
=====================================================================

Program Name    : Singly Linked List Constructor (Java)
Program Number  : 008
Description     : This program demonstrates creation of a
                  Singly Linked List class and initialization
                  of its data members using a constructor.
                  The constructor is automatically invoked
                  when an object of the linked list class
                  is created.

Concepts Used   : Java, Class, Object,
                  Constructor,
                  Self-Referential Class,
                  Linked List Initialization

Input           : None

Output          : Displays constructor invocation message.

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

class SinglyLL
{
    public node first;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Inside Constructor");

        this.first = null;
        this.iCount = 0;
    }
}

class SinglyLL008
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();
    }
}

/*
=====================================================================

Expected Output :

Inside Constructor

Explanation :

The node class represents a single node
of the linked list.

The SinglyLL class contains:

1. first  -> Reference to the first node.
2. iCount -> Stores number of nodes.

Constructor :

public SinglyLL()
{
    this.first = null;
    this.iCount = 0;
}

When the statement

SinglyLL sobj = new SinglyLL();

is executed:

1. Memory is allocated for the object.
2. SinglyLL constructor is invoked automatically.
3. first is initialized to null.
4. iCount is initialized to 0.
5. Message "Inside Constructor" is displayed.

Object State After Initialization :

first  -> null
iCount -> 0

Operations Performed :

1. Defined node class.
2. Defined SinglyLL class.
3. Created constructor for SinglyLL.
4. Initialized linked list members.
5. Created linked list object.
6. Executed constructor automatically.

Conclusion :

The constructor ensures that every
Singly Linked List object starts in a
valid empty state before any node
operations are performed.

=====================================================================
*/

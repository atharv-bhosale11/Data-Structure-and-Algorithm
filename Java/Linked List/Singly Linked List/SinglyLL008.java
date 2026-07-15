/*
=====================================================================

Name            : Singly Linked List - Class Constructor Initialization
Program Number  : 008

Description     : This program demonstrates the creation of a
                  Singly Linked List class. The constructor is
                  used to initialize the first pointer to NULL
                  and node count to zero when an object of the
                  linked list class is created.

Concepts Used   : Class, Object Creation, Constructor,
                  Self-Referential Class,
                  Linked List Initialization,
                  this Keyword

Input           : None

Output          : Inside Constructor

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

Summary         : Created a Singly Linked List class and
                  initialized its members through a constructor.

Initial State   : First = NULL
                  Node Count = 0

Learning        : Constructors are automatically invoked when
                  objects are created and are commonly used for
                  initialization of class members.

=====================================================================
*/

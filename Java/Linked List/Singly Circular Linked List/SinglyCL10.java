/*
=====================================================================

Name            : Singly Circular Linked List - Function Declarations
Program Number  : 010
Description     : This program demonstrates the basic framework of
                  a Singly Circular Linked List class.

                  The class contains declarations of all major
                  linked list operations such as insertion,
                  deletion, display, and count. Function bodies
                  are kept empty and will be implemented in
                  subsequent programs.

Concepts Used   : Singly Circular Linked List,
                  Class Design,
                  Method Declaration,
                  Constructor,
                  Object-Oriented Programming

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

    public void Disply()
    {}

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int no)
    {}

    public void InsertLast(int no)
    {}

    public void InsertAtPos(int no, int iPos)
    {}

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int iPos)
    {}
}

class SinglyCL10
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

- Singly Circular Linked List class is created.
- Constructor initializes linked list members.
- Display, Count, Insert and Delete methods are declared.
- Count method returns current node count.
- Method implementations will be added later.

=====================================================================
*/

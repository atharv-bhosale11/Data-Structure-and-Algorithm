/*
=====================================================================

Name            : Singly Linked List - Constructor Demonstration
Program Number  : 004
Description     : This program demonstrates the constructor of
                  Singly Linked List class.

                  The constructor initializes:
                  - First reference to null
                  - Node count to zero

Concepts Used   : Constructor, Class, Object Creation,
                  Reference Initialization, Linked List

Input           : None

Output          : Constructor execution message

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

class SinglyCL04
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();
    }
}

/*
=====================================================================

Sample Output :

Inside Constructor

=====================================================================

Observation :

- Singly Linked List object gets created.
- Constructor executes automatically.
- First pointer is initialized to null.
- Node count is initialized to zero.
- Constructor prepares the linked list for use.

=====================================================================
*/

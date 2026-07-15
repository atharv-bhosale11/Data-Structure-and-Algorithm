/*
=====================================================================

Name            : Singly Linked List - Parameterized Constructor
Program Number  : 007

Description     : This program demonstrates the use of a
                  parameterized constructor in a node class.
                  The constructor initializes the data member
                  and sets the next reference to NULL during
                  object creation.

Concepts Used   : Class, Object Creation, Constructor,
                  Parameterized Constructor,
                  Self-Referential Class,
                  Reference Variables

Input           : 11

Output          : 11
                  null

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

class program450
{
    public static void main(String A[])
    {
        node newn = new node(11);

        System.out.println(newn.data);
        System.out.println(newn.next);
    }
}

/*
=====================================================================

Summary         : Created a node object using a parameterized
                  constructor and displayed its data and next
                  reference.

Node Structure  : | 11 | -> NULL

Learning        : Constructors can be used to initialize object
                  members automatically at the time of object
                  creation, reducing manual assignments.

=====================================================================
*/

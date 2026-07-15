/*
=====================================================================

Name            : Singly Linked List - Manual Node Creation
Program Number  : 001

Description     : This program demonstrates the basic creation of a
                  Singly Linked List in Java. Multiple nodes are
                  created manually, data values are assigned, and
                  nodes are connected using reference variables.
                  A Head pointer is used to store the reference of
                  the first node in the linked list.

Concepts Used   : Class, Object Creation, Reference Variables,
                  Self-Referential Class, Linked List Node,
                  Head Pointer, Node Linking, Memory Allocation

Input           : None

Output          : Singly Linked List Created Successfully

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale

=====================================================================
*/

class node
{
    public int data;
    public node next;
}

class SinglyLL001
{
    public static void main(String A[])
    {
        node head = null;
        node obj1 = null;
        node obj2 = null;
        node obj3 = null;

        obj1 = new node();
        obj2 = new node();
        obj3 = new node();

        obj1.data = 11;
        obj2.data = 21;
        obj3.data = 51;

        obj1.next = obj2;
        obj2.next = obj3;
        obj3.next = null;

        head = obj1;
    }
}

/*
=====================================================================

Summary         : Created three nodes manually and connected them
                  using next references to form a Singly Linked List.

Linked List     : 11 -> 21 -> 51 -> NULL

Learning        : Understanding node creation, memory allocation,
                  reference linking, and Head pointer initialization
                  in Java Linked Lists.

=====================================================================
*/

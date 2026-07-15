/*
=====================================================================

Name            : Singly Linked List - Node Access Using Head Pointer
Program Number  : 003

Description     : This program demonstrates how to create a Singly
                  Linked List manually and access node data using
                  the Head pointer. Three nodes are created,
                  connected together, and their data is displayed
                  through linked references.

Concepts Used   : Class, Object Creation, Self-Referential Class,
                  Head Pointer, Node Linking, Reference Traversal,
                  Linked List Basics

Input           : None

Output          : 11
                  21
                  51

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

class SinglyLL003
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

        System.out.println(head.data);
        System.out.println(head.next.data);
        System.out.println(head.next.next.data);
    }
}

/*
=====================================================================

Summary         : Created three nodes, linked them together, and
                  accessed each node using the Head pointer.

Linked List     : 11 -> 21 -> 51 -> NULL

Learning        : Understanding how Head stores the reference of
                  the first node and how linked references are used
                  to access subsequent nodes.

=====================================================================
*/

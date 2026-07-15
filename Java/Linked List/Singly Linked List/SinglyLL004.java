/*
=====================================================================
 
Name            : Singly Linked List - Head Pointer Traversal
Program Number  : 004

Description     : This program demonstrates traversal of a Singly
                  Linked List using the Head pointer. The Head
                  pointer is moved from one node to the next using
                  the next reference, allowing sequential access to
                  all nodes in the linked list.

Concepts Used   : Class, Object Creation, Self-Referential Class,
                  Head Pointer, Node Traversal, Reference Movement,
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

class SinglyLL004
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

        head = head.next;

        System.out.println(head.data);

        head = head.next;

        System.out.println(head.data);
    }
}

/*
=====================================================================

Summary         : Traversed the linked list by moving the Head
                  pointer from one node to the next node.

Linked List     : 11 -> 21 -> 51 -> NULL

Learning        : Understanding how traversal works in a Singly
                  Linked List by following next references from
                  one node to another.

=====================================================================
*/

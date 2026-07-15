/*
=====================================================================

Name            : Singly Linked List - Traversal Using Temporary Pointer
Program Number  : 005

Description     : This program demonstrates traversal of a Singly
                  Linked List using a temporary pointer. Instead of
                  moving the Head pointer directly, a temporary
                  reference variable is used to traverse the list,
                  preserving the original Head pointer.

Concepts Used   : Class, Object Creation, Self-Referential Class,
                  Head Pointer, Temporary Pointer, Node Traversal,
                  Reference Variables, Linked List Basics

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

class SinglyLL005
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

        node temp = head;

        System.out.println(temp.data);

        temp = temp.next;

        System.out.println(temp.data);

        temp = temp.next;

        System.out.println(temp.data);
    }
}

/*
=====================================================================

Summary         : Traversed the linked list using a temporary
                  pointer while preserving the Head pointer.

Linked List     : 11 -> 21 -> 51 -> NULL

Learning        : Understanding why a temporary pointer is used
                  during traversal so that the Head pointer remains
                  unchanged and continues to reference the first node.

=====================================================================
*/

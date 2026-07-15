/*
=====================================================================

Name            : Singly Linked List - Node Creation and Initialization
Program Number  : 001

Description     : This program demonstrates the creation of a single
                  node object in a Singly Linked List. Memory is
                  allocated dynamically using the new keyword, data
                  is assigned to the node, and the next reference is
                  initialized to null.

Concepts Used   : Class, Object Creation, Self-Referential Class,
                  Dynamic Memory Allocation, Reference Variables,
                  Node Initialization, Linked List Basics

Input           : None

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
}

class SinglyLL001
{
    public static void main(String A[])
    {
        node newn = null;

        newn = new node();
        newn.data = 11;
        newn.next = null;

        System.out.println(newn.data);
        System.out.println(newn.next);
    }
}

/*
=====================================================================

Summary         : Created a single node object and initialized its
                  data and next members.

Node State      : Data = 11
                  Next = null

Learning        : Understanding how nodes are created and initialized
                  before building a complete Singly Linked List.

=====================================================================
*/

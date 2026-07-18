/*
=====================================================================

Name            : Singly Linked List - Node Creation and Linking
Program Number  : 001
Description     : This program demonstrates the creation of two
                  nodes in a Singly Linked List and links them
                  together using the next reference.

                  The program:
                  - Creates two nodes
                  - Stores data in each node
                  - Connects first node to second node
                  - Displays node data

Concepts Used   : Singly Linked List, Node Creation,
                  Object Instantiation, Reference Variables,
                  Data Members, Link Establishment

Input           : None

Output          : Data stored in linked list nodes

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

class SinglyCL01
{
    public static void main(String A[])
    {
        node first = null;
        node second = null;

        first = new node();
        second = new node();

        first.data = 11;
        first.next = second;

        second.data = 21;
        second.next = null;

        System.out.println(first.data);
        System.out.println(second.data);
    }
}

/*
=====================================================================

Sample Output :

11
21

=====================================================================

Classes Used :

1. node
2. SinglyCL01

=====================================================================

Observation :

- Two nodes are created dynamically.
- First node is linked to second node.
- Data can be accessed using object references.
- This is the basic foundation of a Singly Linked List.

=====================================================================
*/

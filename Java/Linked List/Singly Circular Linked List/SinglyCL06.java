/*
=====================================================================

Name            : Singly Circular Linked List - Basic Circular Link
Program Number  : 006
Description     : This program demonstrates the creation of a
                  Singly Circular Linked List using three nodes.

                  The last node is connected back to the first node
                  to form a circular structure. The program displays
                  node data and reference values.

Concepts Used   : Singly Circular Linked List,
                  Self-Referential Class,
                  Object Creation,
                  Circular Connection,
                  Reference Manipulation

Input           : None

Output          : Node data and reference addresses

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

class SinglyCL06
{
    public static void main(String A[])
    {
        node head = null;
        node second = null;
        node third = null;

        head = new node();
        second = new node();
        third = new node();

        head.data = 11;
        head.next = second;

        second.data = 21;
        second.next = third;

        third.data = 51;
        third.next = head;

        System.out.println(head.data);
        System.out.println(second.data);
        System.out.println(third.data);

        System.out.println(head.next);
        System.out.println(second.next);
        System.out.println(third.next);
    }
}

/*
=====================================================================

Sample Output :

11
21
51

=====================================================================

Observation :

- Three nodes are created dynamically.
- Nodes are connected in circular format.
- Last node points back to the first node.
- No node contains NULL in next reference.
- Object references are displayed by Java.

=====================================================================
*/

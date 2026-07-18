/*
=====================================================================

Name            : Singly Circular Linked List - Basic Creation
Program Number  : 005
Description     : This program demonstrates the creation of a
                  Singly Circular Linked List containing three nodes.

                  The last node points back to the first node,
                  forming a circular structure.

Concepts Used   : Singly Circular Linked List,
                  Self-Referential Class,
                  Object Creation,
                  Reference Linking,
                  Circular Connection

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

class SinglyCL05
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
node@xxxxxx
node@xxxxxx
node@xxxxxx

=====================================================================

Observation :

- Three nodes are created successfully.
- Nodes are connected in circular fashion.
- Last node points to the first node.
- Circular Linked List does not contain NULL link.
- References are displayed as object addresses.

=====================================================================
*/

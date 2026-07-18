/*
=====================================================================

Name            : Singly Linked List - Three Node Creation
Program Number  : 002
Description     : This program demonstrates creation of three
                  nodes and linking them together to form a
                  simple Singly Linked List.

Concepts Used   : Node Creation, Object References,
                  Link Establishment, Singly Linked List

Input           : None

Output          : Data of all nodes

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

class SinglyCL02
{
    public static void main(String A[])
    {
        node first = new node();
        node second = new node();
        node third = new node();

        first.data = 11;
        second.data = 21;
        third.data = 51;

        first.next = second;
        second.next = third;
        third.next = null;

        System.out.println(first.data);
        System.out.println(second.data);
        System.out.println(third.data);
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

- Three nodes are created.
- Nodes are connected using next reference.
- Last node points to NULL.

=====================================================================
*/

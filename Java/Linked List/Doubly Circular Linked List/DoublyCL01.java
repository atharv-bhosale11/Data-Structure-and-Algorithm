/*
===============================================================================
Program Name    : Doubly Circular Linked List - Node Creation
Program Number  : 001
File Name       : DoublyCL01.java

Description     : This program demonstrates the creation of nodes and
                  establishing circular connections in a Doubly Circular
                  Linked List using Java.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================
*/

class node
{
    public int data;
    public node next;
    public node prev;

    node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL01
{
    public static void main(String A[])
    {
        node first = new node(11);
        node second = new node(21);
        node third = new node(51);

        // Forward Links
        first.next = second;
        second.next = third;
        third.next = first;

        // Backward Links
        first.prev = third;
        second.prev = first;
        third.prev = second;

        System.out.println("First Node  : " + first.data);
        System.out.println("Second Node : " + second.data);
        System.out.println("Third Node  : " + third.data);
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

First Node  : 11
Second Node : 21
Third Node  : 51

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates how nodes are created and connected
in both forward and backward directions to form a Doubly
Circular Linked List.

===============================================================================
*/

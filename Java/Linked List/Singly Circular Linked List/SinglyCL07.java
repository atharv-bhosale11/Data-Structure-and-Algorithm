/*
=====================================================================

Name            : Singly Circular Linked List - Traversal Using Temp
Program Number  : 007
Description     : This program demonstrates traversal of a
                  Singly Circular Linked List using a temporary
                  reference variable.

                  Since the last node points back to the first node,
                  traversal continues in a circular manner.

Concepts Used   : Singly Circular Linked List,
                  Circular Traversal,
                  Temporary Reference Variable,
                  Object Linking,
                  Reference Manipulation

Input           : None

Output          : Displays node data while traversing the
                  circular linked list

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

class SinglyCL07
{
    public static void main(String A[])
    {
        node head = null;
        node obj1 = null;
        node obj2 = null;
        node temp = null;

        head = new node();
        obj1 = new node();
        obj2 = new node();

        head.data = 11;
        head.next = obj1;

        obj1.data = 21;
        obj1.next = obj2;

        obj2.data = 51;
        obj2.next = head;

        temp = head;

        System.out.println(temp.data);

        temp = temp.next;
        System.out.println(temp.data);

        temp = temp.next;
        System.out.println(temp.data);

        temp = temp.next;
        System.out.println(temp.data);
    }
}

/*
=====================================================================

Sample Output :

11
21
51
11

=====================================================================

Observation :

- Three nodes are connected circularly.
- Temp pointer starts from first node.
- After reaching last node, traversal returns to first node.
- Circular Linked List can be traversed repeatedly.
- Fourth output is again the first node data.

=====================================================================
*/

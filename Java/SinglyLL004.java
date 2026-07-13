/*
=====================================================================

Program Name    : Java Singly Linked List - Traversing Using Head
Program Number  : 004
Description     : This program demonstrates how a linked list can
                  be traversed by moving the head reference from
                  one node to the next.

                  The head reference initially points to the first
                  node. By assigning head = head.next, the head
                  reference moves forward through the linked list.

                  This technique forms the basis of linked list
                  traversal algorithms.

Concepts Used   : Java Classes,
                  Objects,
                  References,
                  Self-Referential Class,
                  Head Pointer,
                  Linked List Traversal

Input           : None

Output          : Displays node data while moving through the
                  linked list.

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

Expected Output :

11
21
51

Explanation :

Initial Linked List :

head
 |
 v
[11|*] -> [21|*] -> [51|NULL]

-----------------------------------------------------

Step 1 :

System.out.println(head.data);

head points to first node.

head
 |
 v
[11]

Output : 11

-----------------------------------------------------

Step 2 :

head = head.next;

head
 |
 v
[21|*] -> [51|NULL]

System.out.println(head.data);

Output : 21

-----------------------------------------------------

Step 3 :

head = head.next;

head
 |
 v
[51|NULL]

System.out.println(head.data);

Output : 51

-----------------------------------------------------

Traversal Flow :

Before Traversal

head
 |
 v
[11] -> [21] -> [51] -> NULL

After First Move

head
 |
 v
[21] -> [51] -> NULL

After Second Move

head
 |
 v
[51] -> NULL

-----------------------------------------------------

Important Observation :

This program moves the actual head reference.

After traversal completes :

head
 |
 v
[51] -> NULL

The addresses of the previous nodes are lost
through the head reference.

For this reason, actual linked list traversal
is usually performed using a temporary reference.

Example :

node temp = head;

while(temp != null)
{
    System.out.println(temp.data);
    temp = temp.next;
}

This preserves the original head reference.

Operations Performed :

1. Created three nodes.
2. Stored data in nodes.
3. Linked all nodes together.
4. Assigned first node address to head.
5. Printed first node data.
6. Moved head to second node.
7. Printed second node data.
8. Moved head to third node.
9. Printed third node data.

Conclusion :

This program demonstrates how node traversal
works internally in a Singly Linked List by
moving from one node to the next using the
next reference. It also highlights why a
temporary pointer is preferred for traversal.

=====================================================================
*/

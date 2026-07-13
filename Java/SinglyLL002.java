/*
=====================================================================

Program Name    : Java Singly Linked List - Manual Node Linking
Program Number  : 002
Description     : This program demonstrates the manual creation
                  and linking of multiple nodes in a Singly
                  Linked List using Java.

                  Three node objects are dynamically created and
                  connected together using their next references.
                  A head reference is used to store the address
                  of the first node in the linked list.

Concepts Used   : Java Classes,
                  Objects,
                  References,
                  Self-Referential Class,
                  Dynamic Memory Allocation,
                  Singly Linked List

Input           : None

Output          : No direct output.
                  Demonstrates linked list creation in memory.

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

class program445
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
    }
}

/*
=====================================================================

Explanation :

Step 1 :
Three node objects are created.

obj1 = new node();
obj2 = new node();
obj3 = new node();

Step 2 :
Data values are assigned.

obj1.data = 11;
obj2.data = 21;
obj3.data = 51;

Step 3 :
Nodes are linked together.

obj1.next = obj2;
obj2.next = obj3;
obj3.next = null;

Step 4 :
Head stores the address of the first node.

head = obj1;

Final Linked List :

head
 |
 v
[11|*] -> [21|*] -> [51|NULL]

Operations Performed :

1. Created three node objects.
2. Stored data inside each node.
3. Linked nodes using next references.
4. Assigned first node address to head.
5. Formed a complete Singly Linked List.

Important Note :

Original code contained :

obj2.data = 21;
obj2.data = 51;

which overwrites the value 21.

Correct statement should be :

obj3.data = 51;

Conclusion :

This program demonstrates how a Singly Linked List
is formed by connecting multiple node objects through
their next references and storing the first node
address in the head reference.

=====================================================================
*/

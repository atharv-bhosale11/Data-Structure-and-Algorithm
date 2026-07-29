/*
===============================================================================

Program Name    : Doubly Linked List - Node Creation
Program Number  : 001
File Name       : DoublyLL01.java

Description     : This program demonstrates the basic creation of nodes in a
                  Doubly Linked List using Java. It introduces the
                  self-referential node structure, constructor initialization,
                  and manual linking of nodes using next and prev references.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale

===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Object Creation using new
6. Reference Variables
7. Manual Node Linking

Key Learning Points:
- Understand the structure of a Doubly Linked List node.
- Learn how objects are created in Java.
- Learn how next and prev references are connected.
- Understand forward and backward links.
- Build the foundation for linked list operations.

===============================================================================
*/

// Doubly Linked List

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

class DoublyLL01
{
    public static void main(String A[])
    {
        node first = new node(11);
        node second = new node(21);
        node third = new node(51);

        // Forward Connections
        first.next = second;
        second.next = third;

        // Backward Connections
        second.prev = first;
        third.prev = second;

        System.out.println("Forward Traversal");

        node temp = first;

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }

        System.out.println("NULL");

        System.out.println();

        System.out.println("Backward Traversal");

        temp = third;

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.prev;
        }

        System.out.println("NULL");
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Forward Traversal
| 11 | <=> | 21 | <=> | 51 | <=> NULL

Backward Traversal
| 51 | <=> | 21 | <=> | 11 | <=> NULL

===============================================================================
Memory Representation:
===============================================================================

NULL <- [11] <=> [21] <=> [51] -> NULL

Forward Links:
11 ----> 21 ----> 51

Backward Links:
11 <---- 21 <---- 51

===============================================================================
Algorithm:
===============================================================================

1. Create three node objects.
2. Initialize each node using the constructor.
3. Connect nodes using next references.
4. Connect nodes using prev references.
5. Traverse in the forward direction.
6. Traverse in the backward direction.
7. Stop.

===============================================================================
Program Flow:
===============================================================================

        Start
          │
          ▼
   Create Three Nodes
          │
          ▼
 Connect next References
          │
          ▼
 Connect prev References
          │
          ▼
 Display Forward List
          │
          ▼
 Display Backward List
          │
          ▼
         Stop

===============================================================================
Time Complexity:
===============================================================================

Node Creation         : O(1)
Forward Traversal     : O(n)
Backward Traversal    : O(n)

Space Complexity      : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 001 demonstrates the basic structure of a Doubly Linked List in Java.
It shows how nodes are created using constructors and how next and prev
references are manually connected to enable bidirectional traversal.

===============================================================================
*/


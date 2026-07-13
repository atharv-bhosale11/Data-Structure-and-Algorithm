/*
=====================================================================

Program Name    : Singly Linked List Node Creation in Java
Program Number  : 001
Description     : This program demonstrates how to create a node
                  for a Singly Linked List in Java.

                  A node object is dynamically created using the
                  new keyword. The data field is initialized with
                  an integer value and the next reference is set
                  to null, indicating that the node is not linked
                  to any other node.

Concepts Used   : Java Classes,
                  Object Creation,
                  Reference Variables,
                  Self-Referential Class,
                  Dynamic Memory Allocation

Input           : None

Output          : Displays the data stored in the node and the
                  value of the next reference.

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

Expected Output :

11
null

Explanation :

Node Structure :

+-------+--------+
| Data  | Next   |
+-------+--------+
|  11   | null   |
+-------+--------+

Step-by-Step Execution :

1. A reference variable newn is declared and
   initialized to null.

       newn
         |
         v
       null

2. Memory is allocated using :

       newn = new node();

3. Data member is initialized.

       newn.data = 11;

4. Next reference is initialized.

       newn.next = null;

5. Printing node data displays :

       11

6. Printing next reference displays :

       null

Memory Representation :

       newn
         |
         v
     +---------+
     | data=11 |
     | next ---|----> null
     +---------+

Operations Performed :

1. Created node class.
2. Declared node reference.
3. Allocated memory for node object.
4. Stored data in node.
5. Initialized next reference.
6. Displayed node contents.

Conclusion :

This program demonstrates the basic building block
of a Singly Linked List in Java. Each node contains
data and a reference to the next node, forming the
foundation for dynamic linked data structures.

=====================================================================
*/

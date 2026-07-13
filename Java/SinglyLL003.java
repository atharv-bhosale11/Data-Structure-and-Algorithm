/*
=====================================================================

Program Name    : Java Singly Linked List - Accessing Node Data
Program Number  : 003
Description     : This program demonstrates how to access the
                  data stored in linked list nodes using the
                  head reference and next links.

                  Three nodes are created, linked together,
                  and accessed sequentially using chained
                  next references.

Concepts Used   : Java Classes,
                  Objects,
                  References,
                  Self-Referential Class,
                  Head Pointer,
                  Linked List Traversal

Input           : None

Output          : Displays the data stored in all nodes.

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

class program446
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
        System.out.println(head.next.data);
        System.out.println(head.next.next.data);
    }
}

/*
=====================================================================

Expected Output :

11
21
51

Explanation :

Linked List Structure :

head
 |
 v
+----+----+     +----+----+     +----+------+
| 11 |  o-----> | 21 |  o-----> | 51 | NULL |
+----+----+     +----+----+     +----+------+

Accessing Data :

1. First Node

   head.data

   head
    |
    v
   [11]

   Output : 11

-----------------------------------------------------

2. Second Node

   head.next.data

   head
    |
    v
   [11] -> [21]

   Output : 21

-----------------------------------------------------

3. Third Node

   head.next.next.data

   head
    |
    v
   [11] -> [21] -> [51]

   Output : 51

-----------------------------------------------------

Reference Flow :

head
 |
 v
obj1 ---> obj2 ---> obj3 ---> null

Operations Performed :

1. Created three node objects.
2. Stored data in each node.
3. Linked all nodes together.
4. Assigned first node address to head.
5. Accessed first node using head.
6. Accessed second node using head.next.
7. Accessed third node using head.next.next.

Conclusion :

This program demonstrates how linked list nodes
can be accessed through chained next references.
The head reference acts as the entry point to
the entire linked list.

=====================================================================
*/

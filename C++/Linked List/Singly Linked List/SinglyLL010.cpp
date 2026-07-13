/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst Operation (C++)
Program Number  : 006
Description     : This program demonstrates the implementation
                  of the InsertFirst() member function in a
                  Singly Linked List using C++ classes.

                  New nodes are dynamically created using
                  the new operator and inserted at the
                  beginning of the linked list.

Concepts Used   : C++, Classes, Constructor,
                  Dynamic Memory Allocation,
                  Encapsulation,
                  Self-Referential Structure,
                  InsertFirst Operation

Input           : Node values (11, 21, 51)

Output          : Displays the linked list and
                  total number of nodes.

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

/*
=====================================================================

Program Name    : Singly Linked List - InsertFirst Operation (C++)
Program Number  : 006
Description     : This program demonstrates the implementation
                  of the InsertFirst() member function in a
                  Singly Linked List using C++ classes.

                  New nodes are dynamically created using
                  the new operator and inserted at the
                  beginning of the linked list.

Concepts Used   : C++, Classes, Constructor,
                  Dynamic Memory Allocation,
                  Encapsulation,
                  Self-Referential Structure,
                  InsertFirst Operation

Input           : Node values (11, 21, 51)

Output          : Displays the linked list and
                  total number of nodes.

Date            : July 2026
Language        : C++
Author          : Atharv Tushar Bhosale

=====================================================================
*/

/*
=====================================================================

Expected Output :

| 11 |-> | 21 |-> | 51 |-> NULL
Number of Elements are: 3

Explanation :

Initially the linked list is empty.

Insertion Sequence :

InsertFirst(51)

first
  |
  v
+----+------+ 
| 51 | NULL |
+----+------+

InsertFirst(21)

first
  |
  v
+----+------+    +----+------+
| 21 |   o------>| 51 | NULL |
+----+------+    +----+------+

InsertFirst(11)

first
  |
  v
+----+------+    +----+------+    +----+------+
| 11 |   o------>| 21 |   o------>| 51 | NULL |
+----+------+    +----+------+    +----+------+

Display Traversal :

11 -> 21 -> 51 -> NULL

Count :

iCount = 3

Operations Performed :

1. Created Singly Linked List object.
2. Initialized first to NULL.
3. Inserted node 51 at first position.
4. Inserted node 21 at first position.
5. Inserted node 11 at first position.
6. Incremented iCount after every insertion.
7. Displayed all nodes.
8. Returned total node count.

Conclusion :

InsertFirst() inserts a new node at the beginning
of the linked list in constant time O(1).
The newly inserted node always becomes the first node
of the linked list.

=====================================================================
*/

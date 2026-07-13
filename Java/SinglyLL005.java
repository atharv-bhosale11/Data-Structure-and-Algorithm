/*
=====================================================================

Program Name    : Singly Linked List Traversal Using Temp Pointer 
Program Number  : 005
Description     : This program demonstrates traversal of a Singly
                  Linked List using a temporary pointer (temp).
                  The head pointer remains unchanged while temp
                  moves from one node to the next node.

Concepts Used   : Java, Class, Object Creation,
                  Reference Variables,
                  Singly Linked List Traversal

Input           : None

Output          : Displays all node elements using temp pointer.

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

class SinglyLL005
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

        node temp = head;

        System.out.println(temp.data);

        temp = temp.next;

        System.out.println(temp.data);

        temp = temp.next;

        System.out.println(temp.data);
    }
}

/*
=====================================================================

Expected Output :

11
21
51

Explanation :

Linked List Created :

head
 |
 v
+----+------+    +----+------+    +----+------+
| 11 |   o------>| 21 |   o------>| 51 | NULL |
+----+------+    +----+------+    +----+------+

Step 1 :
temp = head
temp points to first node (11)

Output :
11

Step 2 :
temp = temp.next

temp now points to second node (21)

Output :
21

Step 3 :
temp = temp.next

temp now points to third node (51)

Output :
51

Important Observation :

The head pointer never moves.

head ---> 11 ---> 21 ---> 51 ---> NULL

Only temp is used for traversal.

This is the standard traversal technique used in
Display(), Count(), Search(), Frequency(), and
many other Linked List operations.

Conclusion :

Using a temporary pointer allows traversal of the
linked list without losing the original head pointer.
This is the safest and most commonly used approach
for Linked List traversal.

=====================================================================
*/

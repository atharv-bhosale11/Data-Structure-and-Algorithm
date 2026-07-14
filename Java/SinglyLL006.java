/*
=====================================================================

Program Name    : Singly Linked List Traversal using While Loop (Java)
Program Number  : 006
Description     : This program demonstrates traversal of a
                  Singly Linked List using a temporary
                  reference variable and a while loop.
                  All node elements are displayed
                  sequentially from the first node
                  to the last node.

Concepts Used   : Java, Class, Object,
                  Reference Variables,
                  Self-Referential Class,
                  Linked List Traversal,
                  While Loop

Input           : None

Output          : Displays all elements present
                  in the linked list.

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

class SinglyLL006
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

        while(temp != null)
        {
            System.out.println(temp.data);
            temp = temp.next;
        }

    }
}

/*
=====================================================================

Expected Output :

11
21
51

Explanation :

Three node objects are created dynamically.

obj1 contains data 11
obj2 contains data 21
obj3 contains data 51

Links are established as:

head
 |
 v

+----+------+     +----+------+     +----+------+
| 11 |   o----->  | 21 |   o----->  | 51 | NULL |
+----+------+     +----+------+     +----+------+

A temporary reference variable temp is
initialized with the address stored in head.

Traversal Process :

Iteration 1:
temp -> 11
Display 11
Move temp to next node

Iteration 2:
temp -> 21
Display 21
Move temp to next node

Iteration 3:
temp -> 51
Display 51
Move temp to next node

Iteration 4:
temp becomes null
Loop terminates

Operations Performed :

1. Created three node objects.
2. Stored data in each node.
3. Linked all nodes together.
4. Assigned head to first node.
5. Created temporary reference temp.
6. Traversed linked list using while loop.
7. Displayed all node elements.

Conclusion :

The while loop successfully traverses
the Singly Linked List from the first
node to the last node and displays
all stored values.

=====================================================================
*/

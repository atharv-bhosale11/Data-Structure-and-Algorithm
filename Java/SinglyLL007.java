/*
=====================================================================

Program Name    : Constructor in Node Class (Java)
Program Number  : 007
Description     : This program demonstrates the use of a
                  parameterized constructor in a node class.
                  The constructor initializes the data field
                  and sets the next reference to null when
                  a node object is created.

Concepts Used   : Java, Class, Object,
                  Constructor,
                  Self-Referential Class,
                  Dynamic Object Creation

Input           : Integer value passed to constructor

Output          : Displays node data and next reference.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale

=====================================================================
*/

class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL007
{
    public static void main(String A[])
    {
        node newn = new node(11);

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

A self-referential class named node is created.

The node class contains:

1. data  -> Stores integer data.
2. next  -> Stores reference of next node.

A parameterized constructor is defined:

node(int no)
{
    this.data = no;
    this.next = null;
}

When the statement

node newn = new node(11);

is executed:

1. Memory is allocated for the object.
2. Constructor is called automatically.
3. data gets initialized with 11.
4. next gets initialized with null.

Object Layout :

+------+------+
|  11  | null |
+------+------+

Output :

newn.data  -> 11
newn.next  -> null

Operations Performed :

1. Defined node class.
2. Created parameterized constructor.
3. Allocated memory for node object.
4. Initialized data and next members.
5. Displayed object contents.

Conclusion :

Constructors simplify object initialization
by automatically assigning values during
object creation, reducing repetitive code.

=====================================================================
*/

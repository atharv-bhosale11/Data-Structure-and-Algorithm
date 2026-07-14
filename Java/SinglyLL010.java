/*
=====================================================================

Program Name    : InsertFirst with Node Count
Program Number  : 010
Description     : This program demonstrates insertion of
                  nodes at the beginning of a Singly Linked
                  List while maintaining the count of nodes
                  using the iCount variable.

Concepts Used   : Java, Classes, Objects,
                  Constructor,
                  Linked List,
                  InsertFirst(),
                  Node Counter

Input           : Integer values

Output          : Nodes are inserted into the linked list.

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

class SinglyLL
{
    private node first;
    private int iCount;

    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {}

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);
        node temp = null;

        newn.data = iNo;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {

        }

        iCount++;
    }

    public void InsertAtPos(int iNo, int iPos)
    {}

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int iPos)
    {}
}

class SinglyLL010
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);
    }
}

/*
=====================================================================

Explanation :

Initially :

first = null
iCount = 0

-----------------------------------------------------

InsertFirst(51)

Linked List is empty.

first
 |
 v
+----+------+
| 51 | null |
+----+------+

iCount = 1

-----------------------------------------------------

InsertFirst(21)

newn.next = first
first = newn

first
 |
 v
+----+----+    +----+------+
| 21 | ---|--->| 51 | null |
+----+----+    +----+------+

iCount = 2

-----------------------------------------------------

InsertFirst(11)

newn.next = first
first = newn

first
 |
 v
+----+----+    +----+----+    +----+------+
| 11 | ---|--->| 21 | ---|--->| 51 | null |
+----+----+    +----+----+    +----+------+

iCount = 3

-----------------------------------------------------

Count Function :

public int Count()
{
    return iCount;
}

Since iCount is updated during every
insertion and deletion operation,
there is no need to traverse the list
for counting nodes.

Advantages :

1. Faster Count() operation.
2. O(1) Time Complexity.
3. No traversal required.

Final Linked List :

11 -> 21 -> 51 -> NULL

Node Count :

3

Operations Performed :

1. Created node class.
2. Created SinglyLL class.
3. Implemented InsertFirst().
4. Maintained node count using iCount.
5. Added Count() functionality.

Conclusion :

Using iCount improves efficiency by
keeping track of the number of nodes
without traversing the linked list.

=====================================================================
*/

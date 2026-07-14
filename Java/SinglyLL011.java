/*
=====================================================================

Program Name    : InsertFirst and InsertLast with Node Counter
Program Number  : 011
Description     : This program demonstrates insertion of
                  nodes at the beginning and end of a
                  Singly Linked List while maintaining
                  the total node count using iCount.

Concepts Used   : Java, Classes, Objects,
                  Constructor,
                  Linked List,
                  InsertFirst(),
                  InsertLast(),
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

        if(first == null)
        {
            first = newn;
        }
        else
        {
            node temp = null;
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
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

class SinglyLL011
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);
    }
}

/*
=====================================================================

Explanation :

InsertFirst Operations

InsertFirst(51)

first
 |
 v
+----+------+
| 51 | null |
+----+------+

iCount = 1

-----------------------------------------------------

InsertFirst(21)

first
 |
 v
+----+----+    +----+------+
| 21 | ---|--->| 51 | null |
+----+----+    +----+------+

iCount = 2

-----------------------------------------------------

InsertFirst(11)

first
 |
 v
+----+----+    +----+----+    +----+------+
| 11 | ---|--->| 21 | ---|--->| 51 | null |
+----+----+    +----+----+    +----+------+

iCount = 3

-----------------------------------------------------

InsertLast Operations

InsertLast(101)

11 -> 21 -> 51 -> 101 -> NULL

iCount = 4

-----------------------------------------------------

InsertLast(111)

11 -> 21 -> 51 -> 101 -> 111 -> NULL

iCount = 5

-----------------------------------------------------

InsertLast(121)

11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

iCount = 6

-----------------------------------------------------

Final Linked List

first
 |
 v
+----+----+    +----+----+    +----+----+
| 11 | ---|--->| 21 | ---|--->| 51 | ---|
+----+----+    +----+----+    +----+----+
                                        |
                                        v
+-----+----+    +-----+----+    +-----+------+
| 101 | ---|--->| 111 | ---|--->| 121 | null |
+-----+----+    +-----+----+    +-----+------+

Final Output :

11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

Total Nodes :

6

Operations Performed :

1. Created node class with constructor.
2. Implemented InsertFirst().
3. Implemented InsertLast().
4. Maintained node count using iCount.
5. Created six linked list nodes.
6. Connected nodes dynamically.

Time Complexity :

InsertFirst() : O(1)
InsertLast()  : O(N)
Count()       : O(1)

Conclusion :

InsertFirst inserts a node at the beginning,
InsertLast inserts a node at the end,
and iCount maintains the total number of
nodes efficiently.

=====================================================================
*/

/*
=====================================================================

Program Name    : InsertFirst and InsertLast Operations
Program Number  : 009
Description     : This program demonstrates insertion of
                  nodes at the beginning and end of a
                  Singly Linked List using Java classes.

Concepts Used   : Java, Classes, Objects,
                  Constructor,
                  Linked List,
                  InsertFirst(),
                  InsertLast()

Input           : Integer values

Output          : Linked List is created internally.

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

        newn.data = iNo;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
    }

    public void InsertLast(int No)
    {
        node newn = new node(No);
        node temp = null;

        newn.data = No;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }
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

class SinglyLL009
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

InsertFirst() Logic :

Step 1 :
Create a new node.

Step 2 :
If Linked List is empty,
make first point to new node.

Step 3 :
Otherwise connect new node
before the current first node.

Example :

InsertFirst(51)

first
  |
  v
+----+------+
| 51 | null |
+----+------+

InsertFirst(21)

first
  |
  v
+----+----+    +----+------+
| 21 | ---|--->| 51 | null |
+----+----+    +----+------+

InsertFirst(11)

first
  |
  v
+----+----+    +----+----+    +----+------+
| 11 | ---|--->| 21 | ---|--->| 51 | null |
+----+----+    +----+----+    +----+------+

-----------------------------------------------------

InsertLast() Logic :

Traverse up to the last node.

Connect the new node at the end.

InsertLast(101)

+----+----+    +----+----+    +----+----+    +-----+------+
| 11 | ---|--->| 21 | ---|--->| 51 | ---|--->| 101 | null |
+----+----+    +----+----+    +----+----+    +-----+------+

InsertLast(111)

+----+----+    +----+----+    +----+----+    +-----+----+    +-----+------+
| 11 | ---|--->| 21 | ---|--->| 51 | ---|--->| 101 | ---|--->| 111 | null |
+----+----+    +----+----+    +----+----+    +-----+----+    +-----+------+

InsertLast(121)

+----+----+    +----+----+    +----+----+    +-----+----+    +-----+----+    +-----+------+
| 11 | ---|--->| 21 | ---|--->| 51 | ---|--->| 101 | ---|--->| 111 | ---|--->| 121 | null |
+----+----+    +----+----+    +----+----+    +-----+----+    +-----+----+    +-----+------+

Final Linked List :

11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

Operations Performed :

1. Created Singly Linked List class.
2. Implemented InsertFirst().
3. Implemented InsertLast().
4. Created six nodes dynamically.
5. Connected nodes using next references.

Conclusion :

InsertFirst inserts nodes at the beginning
of the Linked List while InsertLast inserts
nodes at the end of the Linked List.

=====================================================================
*/

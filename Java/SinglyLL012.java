/*
=====================================================================

Program Name    : Display and Count in Singly Linked List
Program Number  : 012
Description     : This program demonstrates insertion of
                  nodes in a Singly Linked List and
                  displays all nodes along with the
                  total node count.

Concepts Used   : Java, Classes, Objects,
                  Constructor,
                  Linked List,
                  InsertFirst(),
                  InsertLast(),
                  Display(),
                  Count()

Input           : Integer values

Output          : Displays linked list elements and
                  total number of nodes.

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
    {
        node temp = first;

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }

        System.out.print("NULL");
        System.out.println();
    }

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
            node temp = first;

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

class SinglyLL012
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Nodes : " + iRet);
    }
}

/*
=====================================================================

Expected Output :

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> NULL
Number of Nodes : 6

=====================================================================

Explanation :

InsertFirst Operations :

InsertFirst(51)
InsertFirst(21)
InsertFirst(11)

Linked List :

11 -> 21 -> 51 -> NULL

-----------------------------------------------------

InsertLast Operations :

InsertLast(101)
InsertLast(111)
InsertLast(121)

Linked List :

11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

-----------------------------------------------------

Display Function :

Uses a temporary reference variable
to traverse the linked list.

node temp = first;

while(temp != null)
{
    System.out.print(temp.data);
    temp = temp.next;
}

Traversal Path :

temp
 |
 v
11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

-----------------------------------------------------

Count Function :

public int Count()
{
    return iCount;
}

Returns the current number of nodes
without traversing the linked list.

-----------------------------------------------------

Final Linked List :

first
 |
 v
11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

Node Count :

6

Time Complexity :

InsertFirst() : O(1)
InsertLast()  : O(N)
Display()     : O(N)
Count()       : O(1)

Operations Performed :

1. Inserted nodes at beginning.
2. Inserted nodes at end.
3. Displayed all nodes.
4. Counted total nodes.
5. Traversed linked list using temp.

Conclusion :

Display() is used to traverse and
print all nodes, while Count()
returns the total number of nodes
efficiently using iCount.

=====================================================================
*/

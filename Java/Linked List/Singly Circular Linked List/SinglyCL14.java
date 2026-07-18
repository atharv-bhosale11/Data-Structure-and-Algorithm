/*
=====================================================================

Name            : Singly Circular Linked List - Count Operation
Program Number  : 014
Description     : This program demonstrates the Count() operation
                  in a Singly Circular Linked List.

                  The Count() method returns the total number of
                  nodes currently present in the linked list.
                  The node count is maintained using the iCount
                  variable and is updated whenever insertion or
                  deletion operations are performed.

Concepts Used   : Singly Circular Linked List,
                  Count Operation,
                  Display Operation,
                  Circular Traversal,
                  Constructor,
                  Node Counter

Input           : Node values for insertion

Output          : Displays linked list elements and total number
                  of nodes present in the list

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

class SinglyCL
{
    public node first;
    public node last;
    public int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void Display()
    {
        node temp = null;
        temp = first;

        if(first == null && last == null)
        {
            return;
        }

        System.out.print("->");
        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        last.next = first;
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }

        last.next = first;
        iCount++;
    }

    public void InsertAtPos(int no, int iPos)
    {}

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int iPos)
    {}
}

class SinglyCL14
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();
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

Sample Output :

->| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of Nodes : 6

=====================================================================

Observation :

- Count() returns the value of iCount.
- iCount stores the total number of nodes.
- Count operation executes in O(1) time.
- Display() shows all nodes in circular order.
- Six nodes are present in the linked list.

=====================================================================
*/

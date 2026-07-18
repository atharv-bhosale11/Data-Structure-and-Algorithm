/*
=====================================================================

Name            : Singly Circular Linked List - Insert At Position
Program Number  : 017
Description     : This program demonstrates insertion of a new node
                  at a specific position in a Singly Circular
                  Linked List.

                  The program validates the position before
                  insertion. If the position is the first or
                  last position, InsertFirst() or InsertLast()
                  is called respectively.

                  For middle positions, the list is traversed
                  to the desired location and the new node is
                  inserted without disturbing the circular
                  structure.

Concepts Used   : Singly Circular Linked List,
                  InsertAtPos Operation,
                  Position Validation,
                  Traversal,
                  Circular Linking,
                  Dynamic Memory Allocation

Input           : Node data and insertion position

Output          : Displays the linked list after insertion

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
    {
        int i = 0;
        node temp = null;
        node newn = new node(no);

        if(iPos < 1 || iPos > iCount + 1)
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(no);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            last.next = first;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            node temp = first;

            while(temp.next != last)
            {
                temp = temp.next;
            }

            last = temp;
            last.next = first;
        }

        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        int i = 0;
        node temp = null;

        if(iPos < 1 || iPos > iCount)
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {

        }
    }
}

class SinglyCL17
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

        sobj.DeleteFirst();
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Nodes : " + iRet);

        sobj.DeleteLast();
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Nodes : " + iRet);

        sobj.InsertAtPos(105,4);
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

->| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of Nodes : 5

->| 21 | -> | 51 | -> | 101 | -> | 111 | ->

Number of Nodes : 4

->| 21 | -> | 51 | -> | 101 | -> | 105 | -> | 111 | ->

Number of Nodes : 5

=====================================================================

Observation :

- InsertAtPos() inserts a node at the specified position.
- Position validation prevents invalid insertion.
- InsertFirst() handles position 1.
- InsertLast() handles insertion at the end.
- Middle insertion is performed using traversal.
- Circular linked list structure remains unchanged.
- Node count increases after insertion.

=====================================================================
*/

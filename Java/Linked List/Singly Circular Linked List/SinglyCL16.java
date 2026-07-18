/*
=====================================================================

Name            : Singly Circular Linked List - Delete Last
Program Number  : 016
Description     : This program demonstrates deletion of the last
                  node from a Singly Circular Linked List.

                  If the list is empty, deletion is not performed.
                  If only one node exists, both first and last
                  references are set to null.

                  Otherwise, the second last node is located,
                  the last reference is updated, and the circular
                  link is maintained by connecting the new last
                  node to the first node.

Concepts Used   : Singly Circular Linked List,
                  DeleteLast Operation,
                  Circular Linking,
                  Traversal,
                  Reference Manipulation,
                  Node Count Management

Input           : Node values for insertion

Output          : Displays linked list before and after deletion

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
            node temp = null;

            temp = first;

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
    {}
}

class SinglyCL16
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

=====================================================================

Observation :

- DeleteLast() removes the last node.
- Empty list condition is handled.
- Single node deletion is handled separately.
- Second last node is located using traversal.
- last reference is updated.
- Circular link is maintained using last.next = first.
- Node count decreases after deletion.

=====================================================================
*/

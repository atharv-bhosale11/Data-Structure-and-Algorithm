/*
=====================================================================

Name            : Singly Circular Linked List - Delete First
Program Number  : 015
Description     : This program demonstrates deletion of the first
                  node from a Singly Circular Linked List.

                  If the list is empty, deletion is not performed.
                  If only one node is present, both first and last
                  references are set to null.

                  Otherwise, the first node is removed and the
                  circular link is maintained by updating
                  last.next to the new first node.

Concepts Used   : Singly Circular Linked List,
                  DeleteFirst Operation,
                  Circular Linking,
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
        node temp = first;

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

        }

        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {}
}

class SinglyCL15
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
    }
}

/*
=====================================================================

Sample Output :

->| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of Nodes : 6

->| 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

Number of Nodes : 5

=====================================================================

Observation :

- DeleteFirst() removes the first node.
- Empty list condition is handled.
- Single node deletion is handled separately.
- first is moved to the next node.
- last.next is updated to maintain circularity.
- Node count decreases after deletion.

=====================================================================
*/

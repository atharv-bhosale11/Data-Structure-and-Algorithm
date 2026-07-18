/*
=====================================================================

Name            : Singly Circular Linked List - Insert First
Program Number  : 011
Description     : This program demonstrates insertion of a new node
                  at the beginning of a Singly Circular Linked List.

                  If the list is empty, the new node becomes both
                  the first and last node. Otherwise, the new node
                  is linked before the existing first node.

                  The circular link between the last node and the
                  first node is maintained after insertion.

Concepts Used   : Singly Circular Linked List,
                  InsertFirst Operation,
                  Constructor,
                  Circular Linking,
                  Node Creation,
                  Reference Manipulation

Input           : Node values for insertion

Output          : Nodes inserted at the beginning of the list

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

    public void Disply()
    {}

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

class SinglyCL11
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);
    }
}

/*
=====================================================================

Sample Output :

(No Output)

=====================================================================

Observation :

- InsertFirst() creates a new node.
- First insertion creates both first and last nodes.
- Subsequent insertions occur at the beginning.
- last.next always points to first node.
- Circular nature of the list is preserved.
- Node count increases after every insertion.

=====================================================================
*/

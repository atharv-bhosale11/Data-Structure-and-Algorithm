/*
=====================================================================

Name            : Singly Linked List - InsertFirst with Node Counter
Program Number  : 010

Description     : This program demonstrates the InsertFirst()
                  operation in a Singly Linked List along with
                  maintaining a node count. Each insertion at
                  the beginning updates the head pointer and
                  increments the node counter.

Concepts Used   : Class, Object Creation, Constructor,
                  Self-Referential Class,
                  InsertFirst Operation,
                  Head Pointer Manipulation,
                  Node Counter Management

Input           : 51, 21, 11

Output          : Nodes inserted successfully at the
                  beginning of the linked list

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

    public void InsertAtPos(int iNo,int iPos)
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

Summary         : Implemented InsertFirst() operation with
                  automatic node count maintenance.

Linked List     : 11 -> 21 -> 51 -> NULL

Node Count      : 3

Learning        : Insertion at the beginning is the most
                  efficient linked list operation as it
                  requires only head pointer modification.

=====================================================================
*/

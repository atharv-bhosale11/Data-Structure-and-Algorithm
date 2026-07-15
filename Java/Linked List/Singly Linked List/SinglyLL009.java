/*
=====================================================================

Name            : Singly Linked List - InsertFirst and InsertLast
Program Number  : 009

Description     : This program demonstrates the implementation of
                  InsertFirst() and InsertLast() operations in a
                  Singly Linked List. Nodes can be inserted at the
                  beginning and at the end of the linked list.

Concepts Used   : Class, Object Creation, Constructor,
                  Self-Referential Class,
                  Dynamic Memory Allocation,
                  InsertFirst Operation,
                  InsertLast Operation,
                  Linked List Traversal

Input           : 11, 21, 51, 101, 111, 121

Output          : Nodes inserted successfully in the
                  Singly Linked List

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

    public void InsertAtPos(int iNo,int iPos)
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

Summary         : Implemented insertion operations at the
                  beginning and end of the linked list.

Linked List     : 11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

Learning        : InsertFirst requires only head manipulation,
                  whereas InsertLast requires traversal up to
                  the last node before attaching the new node.

=====================================================================
*/

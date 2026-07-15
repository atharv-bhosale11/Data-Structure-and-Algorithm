/*
=====================================================================

Name            : Singly Linked List - InsertLast Operation
Program Number  : 011

Description     : This program demonstrates insertion of nodes
                  at both the beginning and end of a Singly
                  Linked List. The InsertLast() function
                  traverses the list and attaches the new node
                  at the last position.

Concepts Used   : Class, Constructor,
                  Self-Referential Class,
                  Dynamic Memory Allocation,
                  InsertFirst Operation,
                  InsertLast Operation,
                  Linked List Traversal,
                  Node Counter Management

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

    public void InsertAtPos(int iNo,int iPos)
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

Summary         : Implemented InsertLast() operation using
                  traversal technique and node counter update.

Linked List     : 11 -> 21 -> 51 -> 101 -> 111 -> 121 -> NULL

Node Count      : 6

Learning        : InsertLast() requires traversal from the
                  first node to the last node before linking
                  the new node at the end.

=====================================================================
*/

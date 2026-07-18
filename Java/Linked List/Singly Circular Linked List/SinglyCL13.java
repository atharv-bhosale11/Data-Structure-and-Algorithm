/*
=====================================================================

Name            : Singly Circular Linked List - Display Operation
Program Number  : 013
Description     : This program demonstrates how to display all nodes
                  of a Singly Circular Linked List.

                  A temporary pointer is used to traverse the list.
                  Since the list is circular, a do-while loop is
                  used to ensure that every node is displayed exactly
                  once.

Concepts Used   : Singly Circular Linked List,
                  Display Operation,
                  Circular Traversal,
                  do-while Loop,
                  Temporary Reference Variable

Input           : Node values inserted in the linked list

Output          : Displays all elements of the circular linked list

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

class SinglyCL13
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();
    }
}

/*
=====================================================================

Sample Output :

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

=====================================================================

Observation :

- Display() traverses the circular linked list.
- do-while loop is used for circular traversal.
- Traversal starts from first node.
- Traversal stops when temp again reaches first node.
- Every node is displayed exactly once.

=====================================================================
*/

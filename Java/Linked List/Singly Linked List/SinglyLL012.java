/*
=====================================================================

Name            : Singly Linked List - Display and Count Operations
Program Number  : 012

Description     : This program demonstrates insertion of nodes
                  at the beginning and end of a Singly Linked
                  List. It also implements Display() to traverse
                  and print all nodes, and Count() to return
                  the total number of nodes present in the list.

Concepts Used   : Class, Constructor,
                  Self-Referential Class,
                  Dynamic Memory Allocation,
                  InsertFirst Operation,
                  InsertLast Operation,
                  Linked List Traversal,
                  Display Operation,
                  Count Operation,
                  Node Counter Management

Input           : 11, 21, 51, 101, 111, 121

Output          : Displays all nodes and total node count

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
            System.out.print("| "+temp.data+"| -> ");
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
        System.out.println("Number of Nodes : "+iRet);
    }
}

/*
=====================================================================

Output :

| 11| -> | 21| -> | 51| -> | 101| -> | 111| -> | 121| -> NULL
Number of Nodes : 6

Summary         : Successfully implemented Display() and Count()
                  operations for Singly Linked List.

Learning        : Display() traverses the list node by node
                  using a temporary pointer, while Count()
                  returns the maintained node count.

=====================================================================
*/

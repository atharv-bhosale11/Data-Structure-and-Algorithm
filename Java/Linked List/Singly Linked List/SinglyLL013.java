/*
=====================================================================

Name            : Singly Linked List - DeleteFirst and DeleteLast
Program Number  : 013
Description     : This program demonstrates deletion operations in
                  a Singly Linked List. It implements DeleteFirst()
                  and DeleteLast() methods along with insertion,
                  display, and count functionalities.

Concepts Used   : Class, Object, Constructor,
                  Singly Linked List, Node Creation,
                  InsertFirst(), InsertLast(),
                  DeleteFirst(), DeleteLast(),
                  Traversal, Encapsulation

Input           : None

Output          : Displays Linked List before and after deletion
                  operations along with total node count.

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
    private  node first;
    private  int iCount;

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
    {
        if(first == null)
        {
            first = null;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            first = null;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            node temp = first;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {}

}


class SinglyLL013
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

        sobj.DeleteFirst();
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of Nodes : "+iRet);

        sobj.DeleteLast();
        sobj.Display();
        iRet = sobj.Count();
        System.out.println("Number of Nodes : "+iRet);

    }
}

/*
=====================================================================

Sample Output :

| 11| -> | 21| -> | 51| -> | 101| -> | 111| -> | 121| -> NULL
Number of Nodes : 6

| 21| -> | 51| -> | 101| -> | 111| -> | 121| -> NULL
Number of Nodes : 5

| 21| -> | 51| -> | 101| -> | 111| -> NULL
Number of Nodes : 4

=====================================================================
*/

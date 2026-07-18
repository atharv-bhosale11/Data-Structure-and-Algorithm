/*
=====================================================================

Name            : Singly Circular Linked List - DeleteAtPos Operation
Program Number  : 018

Description     : This program demonstrates all basic operations of
                  Singly Circular Linked List including:

                  - InsertFirst()
                  - InsertLast()
                  - InsertAtPos()
                  - DeleteFirst()
                  - DeleteLast()
                  - DeleteAtPos()
                  - Display()
                  - Count()

                  The DeleteAtPos() function removes a node from any
                  valid position while maintaining the circular link
                  between first and last nodes.

Concepts Used   : Singly Circular Linked List, Dynamic Memory
                  Allocation, Node Deletion, Position Based
                  Operations, Circular Traversal

Input           : Node values and position values

Output          : Linked List after insertion and deletion operations

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
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;
        }while(temp != last.next);
        System.out.println();
    }

    public int Count()
    {
        return  iCount;
    }

    public void InsertFirst(int no)
    {
        node newn= new node(no);

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
        node newn= new node(no);

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
    {
        int i = 0;
        node temp = null;
        node target = null;

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
            temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }
            target = temp.next;
            temp.next = target.next;
            iCount--;
        }
    }
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
        System.out.println("Number of Nodes: "+iRet);

        sobj.DeleteFirst();
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Nodes: "+iRet);

        sobj.DeleteLast();
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Nodes: "+iRet);

        sobj.InsertAtPos(105,4);
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Nodes: "+iRet);

        sobj.DeleteAtPos(4);
        sobj.Display();

        iRet = sobj.Count();
        System.out.println("Number of Nodes: "+iRet);
        
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

->| 21 | -> | 51 | -> | 101 | -> | 111 | ->
Number of Nodes : 4

=====================================================================
End of Program 018
=====================================================================
*/

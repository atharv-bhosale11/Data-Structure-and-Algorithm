/*
===============================================================================
Program Name    : Doubly Circular Linked List - InsertFirst
Program Number  : 002
File Name       : DoublyCL02.java

Description     : This program demonstrates the InsertFirst()
                  operation in a Doubly Circular Linked List 
                  using Java.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================
*/

class node
{
    public int data;
    public node next;
    public node prev;

    node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        last.next = first;
        first.prev = last;

        iCount++;
    }
}

class DoublyCL02
{
    public static void main(String A[])
    {
        DoublyCL dobj = new DoublyCL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

    }
}

/*
===============================================================================
Conclusion:
===============================================================================

Program 002 demonstrates insertion of nodes at the beginning
of a Doubly Circular Linked List using Java.

===============================================================================
*/ 

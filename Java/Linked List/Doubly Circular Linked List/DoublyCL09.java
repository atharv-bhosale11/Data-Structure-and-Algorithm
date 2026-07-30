/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteAtPos Function
Program Number  : 009
File Name       : DoublyCL09.java

Description     : This program demonstrates the DeleteAtPos()
                  operation in a Doubly Circular Linked List.
                  A node can be deleted from any valid position
                  while maintaining circular links.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Doubly Circular Linked List
4. Dynamic Memory Allocation
5. Position Validation
6. Node Deletion

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

    public void Display()
    {
        if(first == null && last == null)
        {
            return;
        }

        node temp = first;

        do
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    public int Count()
    {
        return iCount;
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

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            last = newn;
        }

        last.next = first;
        first.prev = last;

        iCount++;
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
            first.prev = last;
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
            last = last.prev;
            last.next = first;
            first.prev = last;
        }

        iCount--;
    }

    public void InsertAtPos(int iNo, int iPos)
    {
        int i = 0;

        if(iPos < 1 || iPos > iCount + 1)
        {
            return;
        }

        if(iPos == 1)
        {
            InsertFirst(iNo);
        }
        else if(iPos == iCount + 1)
        {
            InsertLast(iNo);
        }
        else
        {
            node newn = new node(iNo);
            node temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;

            temp.next = newn;
            newn.prev = temp;

            iCount++;
        }
    }

    public void DeleteAtPos(int iPos)
    {
        int i = 0;

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
            node temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }
}

class DoublyCL09
{
    public static void main(String A[])
    {
        DoublyCL dobj = new DoublyCL();
        int iRet = 0;

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);

        dobj.InsertAtPos(75,4);

        System.out.println("Data after insertion:");
        dobj.Display();

        dobj.DeleteAtPos(4);

        System.out.println("\nAfter DeleteAtPos:");
        dobj.Display();

        iRet = dobj.Count();

        System.out.println("\nNumber of Nodes : " + iRet);
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Data after insertion:
| 11 | <=> | 21 | <=> | 51 | <=> | 75 | <=> | 101 | <=> | 111 | <=>

After DeleteAtPos:
| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of Nodes : 5

===============================================================================
Memory Representation:
===============================================================================

Before Deletion

| 11 | <=> | 21 | <=> | 51 | <=> | 75 | <=> | 101 | <=> | 111 |
   ^                                                           |
   |___________________________________________________________|

After DeleteAtPos(4)

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 |
   ^                                                 |
   |_________________________________________________|

===============================================================================
Time Complexity:
===============================================================================

Display()      : O(n)

Count()        : O(1)

InsertFirst()  : O(1)

InsertLast()   : O(1)

DeleteFirst()  : O(1)

DeleteLast()   : O(1)

InsertAtPos()  : O(n)

DeleteAtPos()  : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates all basic operations of a Doubly
Circular Linked List in Java. The DeleteAtPos() function
removes a node from any valid position while preserving
both forward and backward circular links.

===============================================================================
*/

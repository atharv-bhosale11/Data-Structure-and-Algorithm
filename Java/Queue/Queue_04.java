/*
===============================================================================
Program Name    : Queue Count Operation
Program Number  : 004
File Name       : Queue_04.java

Description     : This program demonstrates insertion,
                  display and counting number of elements
                  in Queue using Singly Linear Linked List.

Concepts Used:
1. Class and Object
2. Linked List
3. Queue Data Structure
4. Dynamic Memory Allocation

Date            : August 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================
*/

class node
{
    public int data;
    public node next;
}

class Queue
{
    private node first;
    private int iCount;

    public Queue()
    {
        first = null;
        iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Enqueue
    // Description   : Insert element at Last
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Enqueue(int iNo)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = iNo;
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

        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Display Queue
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = first;

        System.out.println("\nElements of Queue are : ");

        while(temp != null)
        {
            System.out.print("|"+temp.data+"| -> ");
            temp = temp.next;
        }

        System.out.println("NULL");
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Count number of elements
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Count()
    {
        return iCount;
    }
}

class Queue_04
{
    public static void main(String A[])
    {
        Queue qobj = new Queue();

        int iRet = 0;

        qobj.Enqueue(11);
        qobj.Enqueue(21);
        qobj.Enqueue(51);
        qobj.Enqueue(101);

        qobj.Display();

        iRet = qobj.Count();

        System.out.println("\nNumber of Elements : "+iRet);
    }
}

/*
===============================================================================
Sample Output

Elements of Queue are :

|11| -> |21| -> |51| -> |101| -> NULL

Number of Elements : 4

===============================================================================
End of Program
===============================================================================
*/

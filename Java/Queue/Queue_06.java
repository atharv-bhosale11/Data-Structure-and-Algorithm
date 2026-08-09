/*
===============================================================================
Program Name    : Complete Queue Application
Program Number  : 006
File Name       : Queue_06.java

Description     : This program demonstrates all Queue
                  operations using Singly Linear Linked
                  List.

                  Operations:
                  1. Enqueue
                  2. Dequeue
                  3. Display
                  4. Count

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
    // Function Name : Dequeue
    // Description   : Delete element from First
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Dequeue()
    {
        int iValue = 0;
        node temp = null;

        if(first == null)
        {
            System.out.println("Queue is Empty");
            return -1;
        }

        iValue = first.data;

        temp = first;
        first = first.next;
        temp = null;

        iCount--;

        return iValue;
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

class Queue_06
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

        iRet = qobj.Dequeue();
        System.out.println("\nRemoved Element : "+iRet);

        qobj.Display();

        iRet = qobj.Count();
        System.out.println("\nNumber of Elements : "+iRet);

        iRet = qobj.Dequeue();
        System.out.println("\nRemoved Element : "+iRet);

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

Removed Element : 11

Elements of Queue are :

|21| -> |51| -> |101| -> NULL

Number of Elements : 3

Removed Element : 21

Elements of Queue are :

|51| -> |101| -> NULL

Number of Elements : 2

===============================================================================
End of Program
===============================================================================
*/

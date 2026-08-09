/*
===============================================================================
Program Name    : Queue Enqueue Operation
Program Number  : 002
File Name       : Queue_02.java

Description     : This program demonstrates insertion
                  of elements into Queue using
                  Enqueue operation.

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
}

class Queue_02
{
    public static void main(String A[])
    {
        Queue qobj = new Queue();

        qobj.Enqueue(11);
        qobj.Enqueue(21);
        qobj.Enqueue(51);
        qobj.Enqueue(101);

        System.out.println("Elements inserted successfully");
    }
}

/*
===============================================================================
Sample Output

Elements inserted successfully

Queue:
11
21
51
101

===============================================================================
End of Program
===============================================================================
*/

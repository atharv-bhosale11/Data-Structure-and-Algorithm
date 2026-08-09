/*
===============================================================================
Program Name    : Queue Menu Driven Application
Program Number  : 007
File Name       : Queue_07.java

Description     : This program demonstrates a complete
                  Menu Driven Queue using Singly Linear
                  Linked List.

                  Operations:
                  1. Enqueue
                  2. Dequeue
                  3. Display
                  4. Count
                  5. Exit

Concepts Used:
1. Class and Object
2. Linked List
3. Queue Data Structure
4. Dynamic Memory Allocation
5. Menu Driven Programming

Date            : August 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================
*/

import java.util.*;

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

class Queue_07
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        Queue qobj = new Queue();

        int iChoice = 0;
        int iValue = 0;
        int iRet = 0;

        System.out.println("-------------------------------------------------");
        System.out.println("        Queue Menu Driven Application");
        System.out.println("-------------------------------------------------");

        while(true)
        {
            System.out.println("\n-------------------------------------------------");
            System.out.println("---------------------QUEUE------------------------");
            System.out.println("-------------------------------------------------");

            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Display");
            System.out.println("4. Count");
            System.out.println("5. Exit");

            System.out.println("-------------------------------------------------");

            System.out.print("Enter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:

                    System.out.print("Enter the data : ");
                    iValue = sobj.nextInt();

                    qobj.Enqueue(iValue);

                    System.out.println("Element inserted successfully");
                    break;

                case 2:

                    iRet = qobj.Dequeue();

                    if(iRet != -1)
                    {
                        System.out.println("Removed Element : "+iRet);
                    }
                    break;

                case 3:

                    qobj.Display();
                    break;

                case 4:

                    iRet = qobj.Count();

                    System.out.println("Number of Elements : "+iRet);
                    break;

                case 5:

                    System.out.println("Thank you for using Queue Application");
                    System.exit(0);

                default:

                    System.out.println("Invalid Choice");
                    break;
            }
        }
    }
}

/*
===============================================================================
Sample Output

1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit

Enter your choice : 1
Enter the data : 11

Enter your choice : 1
Enter the data : 21

Enter your choice : 1
Enter the data : 51

Enter your choice : 3

Elements of Queue are :

|11| -> |21| -> |51| -> NULL

Enter your choice : 2

Removed Element : 11

Elements of Queue are :

|21| -> |51| -> NULL

Enter your choice : 4

Number of Elements : 2

===============================================================================
End of Program
===============================================================================
*/

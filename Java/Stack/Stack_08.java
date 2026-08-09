/*
===============================================================================
Program Name    : Stack Menu Driven Application
Program Number  : 008
File Name       : Stack_08.java

Description     : This program demonstrates a complete
                  Menu Driven Stack using Singly Linear
                  Linked List.

                  Operations:
                  1. Push
                  2. Pop
                  3. Peep
                  4. Display
                  5. Count
                  6. Exit

Concepts Used:
1. Class and Object
2. Linked List
3. Stack Data Structure
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

class Stack
{
    private node first;
    private int iCount;

    public Stack()
    {
        first = null;
        iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Push
    // Description   : Insert element at First
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Push(int iNo)
    {
        node newn = null;

        newn = new node();

        newn.data = iNo;
        newn.next = null;

        newn.next = first;
        first = newn;

        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Pop
    // Description   : Delete element from First
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Pop()
    {
        int iValue = 0;
        node temp = null;

        if(first == null)
        {
            System.out.println("Stack is Empty");
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
    // Function Name : Peep
    // Description   : Return topmost element
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Peep()
    {
        if(first == null)
        {
            System.out.println("Stack is Empty");
            return -1;
        }

        return first.data;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Display Stack
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = first;

        System.out.println("\nElements of Stack are : ");

        while(temp != null)
        {
            System.out.println("| " + temp.data + " |");
            temp = temp.next;
        }
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

class Stack_08
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        Stack stobj = new Stack();

        int iChoice = 0;
        int iValue = 0;
        int iRet = 0;

        System.out.println("-------------------------------------------------");
        System.out.println("        Stack Menu Driven Application");
        System.out.println("-------------------------------------------------");

        while(true)
        {
            System.out.println("\n-------------------------------------------------");
            System.out.println("---------------------STACK------------------------");
            System.out.println("-------------------------------------------------");

            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peep");
            System.out.println("4. Display");
            System.out.println("5. Count");
            System.out.println("6. Exit");

            System.out.println("-------------------------------------------------");

            System.out.print("Enter your choice : ");
            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                case 1:

                    System.out.print("Enter the data : ");
                    iValue = sobj.nextInt();

                    stobj.Push(iValue);

                    System.out.println("Element inserted successfully");
                    break;

                case 2:

                    iRet = stobj.Pop();

                    if(iRet != -1)
                    {
                        System.out.println("Removed Element : "+iRet);
                    }
                    break;

                case 3:

                    iRet = stobj.Peep();

                    if(iRet != -1)
                    {
                        System.out.println("Topmost Element : "+iRet);
                    }
                    break;

                case 4:

                    stobj.Display();
                    break;

                case 5:

                    iRet = stobj.Count();

                    System.out.println("Number of Elements : "+iRet);
                    break;

                case 6:

                    System.out.println("Thank you for using Stack Application");
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

1. Push
2. Pop
3. Peep
4. Display
5. Count
6. Exit

Enter your choice : 1
Enter the data : 11

Enter your choice : 1
Enter the data : 21

Enter your choice : 1
Enter the data : 51

Enter your choice : 4

Elements of Stack are :

| 51 |
| 21 |
| 11 |

Enter your choice : 3

Topmost Element : 51

Enter your choice : 2

Removed Element : 51

Elements of Stack are :

| 21 |
| 11 |

Enter your choice : 5

Number of Elements : 2

===============================================================================
End of Program
===============================================================================
*/

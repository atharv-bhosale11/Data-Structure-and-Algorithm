/*
===============================================================================
Program Name    : Complete Stack Application
Program Number  : 007
File Name       : Stack_07.java

Description     : This program demonstrates all Stack
                  operations using Singly Linear Linked
                  List.

                  Operations:
                  1. Push
                  2. Pop
                  3. Peep
                  4. Display
                  5. Count

Concepts Used:
1. Class and Object
2. Linked List
3. Stack Data Structure
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

class Stack_07
{
    public static void main(String A[])
    {
        Stack sobj = new Stack();

        int iRet = 0;

        sobj.Push(11);
        sobj.Push(21);
        sobj.Push(51);
        sobj.Push(101);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("\nNumber of Elements : " + iRet);

        iRet = sobj.Pop();
        System.out.println("\nRemoved Element : " + iRet);

        sobj.Display();

        iRet = sobj.Count();
        System.out.println("\nNumber of Elements : " + iRet);

        iRet = sobj.Peep();
        System.out.println("\nTopmost Element : " + iRet);

        iRet = sobj.Count();
        System.out.println("\nNumber of Elements : " + iRet);

        sobj.Display();
    }
}

/*
===============================================================================
Sample Output

Elements of Stack are :

| 101 |
| 51 |
| 21 |
| 11 |

Number of Elements : 4

Removed Element : 101

Elements of Stack are :

| 51 |
| 21 |
| 11 |

Number of Elements : 3

Topmost Element : 51

Number of Elements : 3

Elements of Stack are :

| 51 |
| 21 |
| 11 |

===============================================================================
End of Program
===============================================================================
*/

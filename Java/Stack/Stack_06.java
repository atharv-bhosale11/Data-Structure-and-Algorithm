/*
===============================================================================
Program Name    : Stack Peep Operation
Program Number  : 006
File Name       : Stack_06.java

Description     : This program demonstrates insertion,
                  display, count, pop and peep operation
                  of Stack using Singly Linear Linked List.

                  Peep returns the topmost element
                  without deleting it.

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

class Stack_06
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

Topmost Element : 101

Number of Elements : 4

Elements of Stack are :

| 101 |
| 51 |
| 21 |
| 11 |

===============================================================================
End of Program
===============================================================================
*/

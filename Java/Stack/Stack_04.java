/*
===============================================================================
Program Name    : Stack Count Operation
Program Number  : 004
File Name       : Stack_04.java

Description     : This program demonstrates insertion,
                  display and counting number of elements
                  in Stack using Singly Linear Linked List.

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

class Stack_04
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

===============================================================================
End of Program
===============================================================================
*/

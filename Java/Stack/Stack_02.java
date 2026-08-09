/*
===============================================================================
Program Name    : Stack Push Operation
Program Number  : 002
File Name       : Stack_02.java

Description     : This program demonstrates insertion
                  of elements into Stack using
                  Push operation.

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
}

class Stack_02
{
    public static void main(String A[])
    {
        Stack sobj = new Stack();

        sobj.Push(11);
        sobj.Push(21);
        sobj.Push(51);
        sobj.Push(101);

        System.out.println("Elements inserted successfully");
    }
}

/*
===============================================================================
Sample Output

Elements inserted successfully

Stack :

|101|
|51|
|21|
|11|

===============================================================================
End of Program
===============================================================================
*/

/*
===============================================================================
Program Name    : Stack Skeleton
Program Number  : 001
File Name       : Stack_01.java

Description     : This program demonstrates the basic
                  structure of Stack using Singly
                  Linear Linked List.

Concepts Used:
1. Class and Object
2. Linked List
3. Stack Data Structure

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
}

class Stack_01
{
    public static void main(String A[])
    {
        Stack sobj = new Stack();

        System.out.println("Stack created successfully");
    }
}

/*
===============================================================================
Sample Output

Stack created successfully

===============================================================================
End of Program
===============================================================================
*/

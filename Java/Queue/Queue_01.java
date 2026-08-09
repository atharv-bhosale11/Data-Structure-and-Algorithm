/*
===============================================================================
Program Name    : Queue Skeleton
Program Number  : 001
File Name       : Queue_01.java

Description     : This program demonstrates the basic
                  structure of Queue using Singly
                  Linear Linked List.

Concepts Used:
1. Class and Object
2. Linked List
3. Queue Data Structure

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
}

class Queue_01
{
    public static void main(String A[])
    {
        Queue qobj = new Queue();

        System.out.println("Queue created successfully");
    }
}

/*
===============================================================================
Sample Output

Queue created successfully

===============================================================================
End of Program
===============================================================================
*/

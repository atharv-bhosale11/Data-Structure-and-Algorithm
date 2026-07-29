/*
===============================================================================
Program Name    : Doubly Linear Linked List - Count
Program Number  : 005
File Name       : DoublyLL05.java

Description     : This program demonstrates the implementation of the
                  Count() operation in a Doubly Linear Linked List
                  using Java. The Count() function returns the total
                  number of nodes present in the linked list.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Doubly Linear Linked List
4. Traversing Linked List
5. Count Function
6. Encapsulation

Key Learning Points:
- Traverse the linked list.
- Count total nodes.
- Return the total count.
- Display number of nodes.

===============================================================================
*/

class node
{
    public int data;
    public node next;
    public node prev;

    node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLL
{
    private node first;
    private int iCount;

    public DoublyLL()
    {
        first = null;
        iCount = 0;
    }

    public void Display()
    {
        node temp = first;

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }

        System.out.println("NULL");
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);
        node temp = first;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
            newn.prev = temp;
        }

        iCount++;
    }
}

class DoublyLL05
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);

        dobj.Display();

        System.out.println("Number of Nodes : " + dobj.Count());
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL
Number of Nodes : 5

===============================================================================
Memory Representation:
===============================================================================

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a linked list.
2. Insert nodes using InsertFirst() and InsertLast().
3. Display all nodes.
4. Return the value of iCount.
5. Display the total number of nodes.

===============================================================================
Time Complexity:
===============================================================================

Display()      : O(n)

Count()        : O(1)

InsertFirst()  : O(1)

InsertLast()   : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Count() operation in a Doubly Linear Linked
List using Java. The program maintains the total number of nodes using
the iCount variable and returns it through the Count() function.

===============================================================================
*/

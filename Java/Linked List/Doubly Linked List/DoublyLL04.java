/*
===============================================================================
Program Name    : Doubly Linear Linked List - Display
Program Number  : 004
File Name       : DoublyLL04.java

Description     : This program demonstrates the implementation of the
                  Display() operation in a Doubly Linear Linked List
                  using Java. The Display() function traverses the
                  linked list from the first node to the last node
                  and displays each element.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Doubly Linear Linked List
4. Traversing Linked List
5. while Loop
6. Pointer Manipulation
7. Encapsulation

Key Learning Points:
- Traverse the linked list.
- Display each node's data.
- Stop traversal when NULL is reached.
- Understand sequential node access.

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

class DoublyLL04
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertLast(11);
        dobj.InsertLast(21);
        dobj.InsertLast(51);
        dobj.InsertLast(101);

        dobj.Display();
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> NULL

===============================================================================
Memory Representation:
===============================================================================

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Create a temporary pointer.
2. Point it to the first node.
3. Traverse while the pointer is not NULL.
4. Display each node's data.
5. Move to the next node.
6. Stop when NULL is reached.

===============================================================================
Time Complexity:
===============================================================================

Display() : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation in a Doubly Linear
Linked List using Java. It traverses the linked list from beginning
to end and displays all node values in sequence.

===============================================================================
*/

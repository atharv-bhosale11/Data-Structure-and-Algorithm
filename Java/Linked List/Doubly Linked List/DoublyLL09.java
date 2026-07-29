/*
===============================================================================
Program Name    : Doubly Linear Linked List - Delete At Position
Program Number  : 009
File Name       : DoublyLL09.java

Description     : This program demonstrates the implementation of the
                  DeleteAtPos() operation in a Doubly Linear Linked List
                  using Java. A node is deleted from the specified
                  position while maintaining proper next and previous
                  links.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Doubly Linear Linked List
4. Delete At Position
5. Pointer Manipulation
6. Position Validation
7. Encapsulation

Key Learning Points:
- Validate the deletion position.
- Delete from beginning, end, or middle.
- Update next and previous links.
- Maintain node count.

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

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
            first.prev = null;
        }

        iCount--;
    }

    public void DeleteLast()
    {
        node temp = first;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        iCount--;
    }

    public void DeleteAtPos(int iPos)
    {
        int i = 0;

        if((iPos < 1) || (iPos > iCount))
        {
            return;
        }

        if(iPos == 1)
        {
            DeleteFirst();
        }
        else if(iPos == iCount)
        {
            DeleteLast();
        }
        else
        {
            node temp = first;

            for(i = 1; i < iPos - 1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            iCount--;
        }
    }
}

class DoublyLL09
{
    public static void main(String A[])
    {
        DoublyLL dobj = new DoublyLL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);

        System.out.println("Before DeleteAtPos()");
        dobj.Display();
        System.out.println("Number of Nodes : " + dobj.Count());

        dobj.DeleteAtPos(4);

        System.out.println("After DeleteAtPos()");
        dobj.Display();
        System.out.println("Number of Nodes : " + dobj.Count());
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Before DeleteAtPos()

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> NULL
Number of Nodes : 5

After DeleteAtPos()

| 11 | <=> | 21 | <=> | 101 | <=> | 111 | <=> NULL
Number of Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

Before Deletion

first
 │
 ▼

NULL <- [11] <=> [21] <=> [51] <=> [101] <=> [111] -> NULL

After Deletion

first
 │
 ▼

NULL <- [11] <=> [21] <=> [101] <=> [111] -> NULL

===============================================================================
Algorithm:
===============================================================================

1. Validate the given position.
2. If position is 1, call DeleteFirst().
3. If position is Count(), call DeleteLast().
4. Otherwise traverse to (Position-1).
5. Bypass the node to be deleted.
6. Update next and previous links.
7. Decrement node count.

===============================================================================
Time Complexity:
===============================================================================

DeleteAtPos() : O(n)

Display()     : O(n)

Count()       : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the DeleteAtPos() operation in a Doubly Linear
Linked List using Java. It removes a node from the specified position
while preserving the integrity of the previous and next links and
maintaining the correct node count.

===============================================================================
*/

/*
===============================================================================
Program Name    : Doubly Circular Linked List - Display Function
Program Number  : 004
File Name       : DoublyCL04.java

Description     : This program demonstrates the Display()
                  operation in a Doubly Circular Linked List
                  using Java. The linked list is traversed
                  from the first node to the last node and
                  all elements are displayed. 

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Doubly Circular Linked List
4. Dynamic Memory Allocation
5. do-while Loop
6. Circular Traversal

Key Learning Points:
- Traverse a Doubly Circular Linked List.
- Display all nodes sequentially.
- Use do-while loop for circular traversal.
- Maintain circular links between first and last nodes.

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

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        first = null;
        last = null;
        iCount = 0;
    }

    public void Display()
    {
        if(first == null && last == null)
        {
            return;
        }

        node temp = first;

        do
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first.prev = newn;
            first = newn;
        }

        last.next = first;
        first.prev = last;

        iCount++;
    }

    public void InsertLast(int iNo)
    {
        node newn = new node(iNo);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            last = newn;
        }

        last.next = first;
        first.prev = last;

        iCount++;
    }
}

class DoublyCL04
{
    public static void main(String A[])
    {
        DoublyCL dobj = new DoublyCL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);

        dobj.Display();
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

===============================================================================
Memory Representation:
===============================================================================

 first
   |
   v

+----+ <=> +----+ <=> +----+ <=> +-----+ <=> +-----+
| 11 |     | 21 |     | 51 |     | 101 |     | 111 |
+----+ <=> +----+ <=> +----+ <=> +-----+ <=> +-----+
   ^                                                 |
   |_________________________________________________|

===============================================================================
Algorithm:
===============================================================================

1. Start from the first node.
2. Display node data.
3. Move to the next node.
4. Repeat until traversal reaches first node again.
5. Stop.

===============================================================================
Time Complexity:
===============================================================================

Display()     : O(n)

InsertFirst() : O(1)

InsertLast()  : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Display() operation of a Doubly
Circular Linked List. The do-while loop ensures that every
node is displayed exactly once while preserving the circular
nature of the linked list.

===============================================================================
*/

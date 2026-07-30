/*
===============================================================================
Program Name    : Doubly Circular Linked List - DeleteFirst Function
Program Number  : 006
File Name       : DoublyCL06.java

Description     : This program demonstrates the DeleteFirst()
                  operation in a Doubly Circular Linked List
                  using Java. The first node of the linked list
                  is deleted while maintaining the circular
                  connections between the remaining nodes.

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Self-Referential Class
3. Doubly Circular Linked List
4. Dynamic Memory Allocation
5. Circular Link Maintenance
6. Node Deletion

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

    public int Count()
    {
        return iCount;
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

    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = last;
            last.next = first;
        }

        iCount--;
    }
}

class DoublyCL06
{
    public static void main(String A[])
    {
        DoublyCL dobj = new DoublyCL();
        int iRet = 0;

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);

        dobj.Display();

        dobj.DeleteFirst();

        dobj.Display();

        iRet = dobj.Count();
        System.out.println("Number of Nodes : " + iRet);
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

| 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of Nodes : 4

===============================================================================
Time Complexity:
===============================================================================

Display()      : O(n)

Count()        : O(1)

InsertFirst()  : O(1)

InsertLast()   : O(1)

DeleteFirst()  : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the DeleteFirst() operation in a
Doubly Circular Linked List. After deletion, the first node
is removed and the circular links between the new first node
and the last node are updated correctly.

===============================================================================
*/

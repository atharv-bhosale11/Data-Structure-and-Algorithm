/*
===============================================================================
Program Name    : Doubly Circular Linked List - Count Function
Program Number  : 005
File Name       : DoublyCL05.java

Description     : This program demonstrates the Count()
                  operation in a Doubly Circular Linked List
                  using Java. The function traverses the 
                  linked list and returns the total number
                  of nodes present in the list.

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
6. Node Counting

Key Learning Points:
- Traverse a Doubly Circular Linked List.
- Count total nodes in the list.
- Use do-while loop for circular traversal.
- Return the count of nodes.

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
}

class DoublyCL04
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

        iRet = dobj.Count();
        System.out.println("Number of Nodes: "+iRet);
    }
}

/*

EXPECTED OUTPUT:-

| 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=>

Number of Nodes : 5
*/

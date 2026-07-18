/*
=====================================================================

Name            : Singly Linked List - Node Constructor 
Program Number  : 003
Description     : This program demonstrates the use of a
                  parameterized constructor in a node class.

                  The constructor initializes:
                  - Data field
                  - Next reference

Concepts Used   : Constructor, Object Initialization,
                  this Keyword, Node Creation

Input           : Integer value passed to constructor

Output          : Data and next reference value

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale

=====================================================================
*/

class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL03
{
    public static void main(String A[])
    {
        node newn = new node(11);

        System.out.println(newn.data);
        System.out.println(newn.next);
    }
}

/*
=====================================================================

Sample Output :

11
null

=====================================================================

Observation :

- Constructor initializes node automatically.
- Data is assigned during object creation.
- Next reference is initialized to null.
- Reduces manual initialization code.

=====================================================================
*/

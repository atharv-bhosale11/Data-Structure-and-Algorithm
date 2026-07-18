/*
=====================================================================

Name            : Singly Circular Linked List - Display Using do-while
Program Number  : 008
Description     : This program demonstrates traversal and display of
                  a Singly Circular Linked List using a do-while loop.

                  Since the last node points back to the first node,
                  the traversal continues until the temporary pointer
                  again reaches the head node.

Concepts Used   : Singly Circular Linked List,
                  Circular Traversal,
                  do-while Loop,
                  Self-Referential Class,
                  Temporary Reference Variable

Input           : None

Output          : Displays all node elements of the
                  circular linked list

Date            : July 2026
Language        : Java
Author          : Atharv Tushar Bhosale

=====================================================================
*/

class node
{
    public int data;
    public node next;
}

class SinglyCL08
{
    public static void main(String A[])
    {
        node head = null;
        node obj1 = null;
        node obj2 = null;
        node temp = null;

        head = new node();
        obj1 = new node();
        obj2 = new node();

        head.data = 11;
        head.next = obj1;

        obj1.data = 21;
        obj1.next = obj2;

        obj2.data = 51;
        obj2.next = head;

        temp = head;

        do
        {
            System.out.println(temp.data);
            temp = temp.next;
        }while(temp != head);

        System.out.println(temp.data);
    }
}

/*
=====================================================================

Sample Output :

11
21
51
11

=====================================================================

Observation :

- Nodes are connected in circular format.
- do-while loop traverses all nodes exactly once.
- Traversal stops when temp again reaches head.
- Final print statement displays head node again.
- Output confirms the circular nature of the list.

=====================================================================
*/

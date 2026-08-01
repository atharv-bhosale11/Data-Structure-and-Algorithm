/*
===============================================================================
Program Name    : Doubly Circular Linked List - Menu Driven Application
Program Number  : 010
File Name       : DoublyCL10.cpp

Description     : This program demonstrates a complete Menu
                  Driven Doubly Circular Linked List which
                  supports all major operations.

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================

Concepts Used:
1. Class and Object
2. Dynamic Memory Allocation
3. Self-Referential Class
4. Doubly Circular Linked List
5. Menu Driven Programming
6. Position Based Operations

Operations:
1. InsertFirst()
2. InsertLast()
3. DeleteFirst()
4. DeleteLast()
5. InsertAtPos()
6. DeleteAtPos()
7. Display()
8. Count()

===============================================================================
*/

#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;
};

class DoublyCL
{
    private:
        Node *First;
        Node *Last;
        int iCount;

    public:
        DoublyCL()
        {
            First = NULL;
            Last = NULL;
            iCount = 0;
        }

          void Display()
        {
            if(First == NULL && Last == NULL)
            {
                cout<<"Linked List is Empty\n";
                return;
            }

            Node *temp = First;

            cout<<"\n<=> ";

            do
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            }while(temp != First);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
        void InsertFirst(int no)
        {
            Node *newn = new Node;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(First == NULL && Last == NULL)
            {
                First = Last = newn;
            }
            else
            {
                newn->next = First;
                First->prev = newn;
                First = newn;
            }

            Last->next = First;
            First->prev = Last;

            iCount++;
        }

        void InsertLast(int no)
        {
            Node *newn = new Node;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(First == NULL && Last == NULL)
            {
                First = Last = newn;
            }
            else
            {
                Last->next = newn;
                newn->prev = Last;
                Last = newn;
            }

            Last->next = First;
            First->prev = Last;

            iCount++;
        }

        void DeleteFirst()
        {
            if(First == NULL && Last == NULL)
            {
                return;
            }
            else if(First == Last)
            {
                delete First;
                First = NULL;
                Last = NULL;
            }
            else
            {
                First = First->next;
                delete Last->next;

                First->prev = Last;
                Last->next = First;
            }

            iCount--;
        }

        void DeleteLast()
        {
            if(First == NULL && Last == NULL)
            {
                return;
            }
            else if(First == Last)
            {
                delete First;
                First = NULL;
                Last = NULL;
            }
            else
            {
                Last = Last->prev;
                delete Last->next;

                Last->next = First;
                First->prev = Last;
            }

            iCount--;
        }

        void InsertAtPos(int no, int iPos)
        {
            if((iPos < 1) || (iPos > iCount + 1))
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(iPos == 1)
            {
                InsertFirst(no);
            }
            else if(iPos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                Node *newn = new Node;
                Node *temp = First;

                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                for(int i = 1; i < iPos-1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                newn->prev = temp;

                temp->next->prev = newn;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int iPos)
        {
            if((iPos < 1) || (iPos > iCount))
            {
                cout<<"Invalid Position\n";
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
                Node *temp = First;

                for(int i = 1; i < iPos-1; i++)
                {
                    temp = temp->next;
                }

                Node *target = temp->next;

                temp->next = target->next;
                target->next->prev = temp;

                delete target;

                iCount--;
            }
        }
};

int main()
{
    DoublyCL dobj;

    int iChoice = 1;
    int iNo = 0;
    int iPos = 0;

    while(iChoice != 0)
    {
        cout<<"\n=================================================\n";
        cout<<"      Doubly Circular Linked List\n";
        cout<<"=================================================\n";

        cout<<"1. Insert First\n";
        cout<<"2. Insert Last\n";
        cout<<"3. Delete First\n";
        cout<<"4. Delete Last\n";
        cout<<"5. Insert At Position\n";
        cout<<"6. Delete At Position\n";
        cout<<"7. Display\n";
        cout<<"8. Count\n";
        cout<<"0. Exit\n";

        cout<<"\nEnter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter data : ";
                cin>>iNo;
                dobj.InsertFirst(iNo);
                break;

            case 2:
                cout<<"Enter data : ";
                cin>>iNo;
                dobj.InsertLast(iNo);
                break;

            case 3:
                dobj.DeleteFirst();
                break;

            case 4:
                dobj.DeleteLast();
                break;

            case 5:
                cout<<"Enter data : ";
                cin>>iNo;

                cout<<"Enter position : ";
                cin>>iPos;

                dobj.InsertAtPos(iNo,iPos);
                break;

            case 6:
                cout<<"Enter position : ";
                cin>>iPos;

                dobj.DeleteAtPos(iPos);
                break;

            case 7:
                dobj.Display();
                break;

            case 8:
                cout<<"Number of Nodes : "
                    <<dobj.Count()<<"\n";
                break;

            case 0:
                cout<<"Thank you for using application\n";
                break;

            default:
                cout<<"Invalid Choice\n";
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Expected Operations:
===============================================================================

Insert First
Insert Last
Delete First
Delete Last
Insert At Position
Delete At Position
Display List
Count Nodes

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)
InsertLast()    : O(1)

DeleteFirst()   : O(1)
DeleteLast()    : O(1)

InsertAtPos()   : O(n)
DeleteAtPos()   : O(n)

Display()       : O(n)
Count()         : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates a complete Menu Driven Doubly
Circular Linked List implementation using C++ classes.
It supports all major insertion, deletion, display,
and counting operations efficiently.

===============================================================================
*/

/*
===============================================================================
Program Name    : Menu Driven Searching Application
Program Number  : 006    
File Name       : Searching06.cpp

Description     : This program demonstrates Menu Driven
                  Searching Techniques using Array.
                  Supported Operations:
                  1. Accept Elements
                  2. Display Elements
                  3. Linear Search
                  4. Bi-Directional Search

Date            : August 2026
Language        : C++
Author          : Atharv Tushar Bhosale
===============================================================================
*/

#include<iostream>
using namespace std;

class Searching
{
    private:
        int *Arr;
        int iSize;

    public:
        Searching(int iNo);
        ~Searching();

        void Accept();
        void Display();

        bool LinearSearch(int iNo);
        bool BiDirectionalSearch(int iNo);
};

///////////////////////////////////////////////////////////////////////////////
//
// Constructor
//
///////////////////////////////////////////////////////////////////////////////

Searching :: Searching(int iNo)
{
    iSize = iNo;
    Arr = new int[iSize];
}

///////////////////////////////////////////////////////////////////////////////
//
// Destructor
//
///////////////////////////////////////////////////////////////////////////////

Searching :: ~Searching()
{
    delete []Arr;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Accept
//
///////////////////////////////////////////////////////////////////////////////

void Searching :: Accept()
{
    int i = 0;

    cout<<"Enter the Elements:\n";

    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
//
///////////////////////////////////////////////////////////////////////////////

void Searching :: Display()
{
    int i = 0;

    cout<<"\nElements of the Array are:\n";

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }

    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinearSearch
//
///////////////////////////////////////////////////////////////////////////////

bool Searching :: LinearSearch(int iNo)
{
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == iNo)
        {
            return true;
        }
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : BiDirectionalSearch
//
///////////////////////////////////////////////////////////////////////////////

bool Searching :: BiDirectionalSearch(int iNo)
{
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            return true;
        }

        iStart++;
        iEnd--;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    int iSize = 0;
    int iChoice = 0;
    int iValue = 0;

    cout<<"Enter Number of Elements : ";
    cin>>iSize;

    Searching sobj(iSize);

    while(1)
    {
        cout<<"\n=================================================\n";
        cout<<"              Searching Application\n";
        cout<<"=================================================\n";

        cout<<"1. Accept Elements\n";
        cout<<"2. Display Elements\n";
        cout<<"3. Linear Search\n";
        cout<<"4. Bi-Directional Search\n";
        cout<<"5. Exit\n";

        cout<<"Enter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:

                sobj.Accept();
                break;

            case 2:

                sobj.Display();
                break;

            case 3:

                cout<<"Enter element to search : ";
                cin>>iValue;

                if(sobj.LinearSearch(iValue))
                {
                    cout<<"Element is Present\n";
                }
                else
                {
                    cout<<"Element is Absent\n";
                }
                break;

            case 4:

                cout<<"Enter element to search : ";
                cin>>iValue;

                if(sobj.BiDirectionalSearch(iValue))
                {
                    cout<<"Element is Present\n";
                }
                else
                {
                    cout<<"Element is Absent\n";
                }
                break;

            case 5:

                cout<<"Thank you for using Searching Application\n";
                return 0;

            default:

                cout<<"Invalid Choice\n";
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Sample Output

Enter Number of Elements : 5

1. Accept Elements
Enter the Elements:
10
20
30
40
50

2. Display Elements
10      20      30      40      50

3. Linear Search
Enter element to search : 30
Element is Present

4. Bi-Directional Search
Enter element to search : 40
Element is Present

5. Exit
Thank you for using Searching Application

===============================================================================
End of Program
===============================================================================
*/

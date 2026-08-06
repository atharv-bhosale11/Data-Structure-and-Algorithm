/*
===============================================================================
Program Name    : Accept and Display Array Elements
Program Number  : 002
File Name       : Searching02.cpp

Description     : This program accepts elements from user
                  and displays them using Array.

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
// Description   : Accept elements from user
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
// Description   : Display elements of array
//
///////////////////////////////////////////////////////////////////////////////

void Searching :: Display()
{
    int i = 0;

    cout<<"Elements of the Array are:\n";

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    Searching sobj(5);

    sobj.Accept();
    sobj.Display();

    return 0;
}

/*
===============================================================================
Sample Output

Enter the Elements:
10
20
30
40
50

Elements of the Array are:
10
20
30
40
50

===============================================================================
End of Program
===============================================================================
*/

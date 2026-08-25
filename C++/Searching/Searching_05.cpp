/*
===============================================================================
Program Name    : Complete Searching Application
Program Number  : 005
File Name       : Searching05.cpp

Description     : This program accepts elements from user,  
                  displays them and performs both
                  Linear Search and Bi-Directional Search.

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
// Function Name : LinearSearch
// Description   : Search element using Linear Search
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
// Description   : Search element using Bi-Directional Search
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
    Searching sobj(5);

    sobj.Accept();
    sobj.Display();

    if(sobj.LinearSearch(30) == true)
    {
        cout<<"\nLinear Search : Element is Present\n";
    }
    else
    {
        cout<<"\nLinear Search : Element is Absent\n";
    }

    if(sobj.BiDirectionalSearch(30) == true)
    {
        cout<<"Bi-Directional Search : Element is Present\n";
    }
    else
    {
        cout<<"Bi-Directional Search : Element is Absent\n";
    }

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

Linear Search : Element is Present
Bi-Directional Search : Element is Present

===============================================================================
End of Program
===============================================================================
*/

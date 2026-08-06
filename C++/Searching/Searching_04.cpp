/*
===============================================================================
Program Name    : Bi-Directional Search
Program Number  : 004
File Name       : Searching04.cpp

Description     : This program accepts elements from user,
                  displays them and performs
                  Bi-Directional Search.

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
// Function Name : BiDirectionalSearch
// Description   : Search element using Bi-Directional Search
//
///////////////////////////////////////////////////////////////////////////////

bool Searching :: BiDirectionalSearch(int iNo)
{
    int iStart = 0;
    int iEnd = iSize - 1;

    bool bFlag = false;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            bFlag = true;
            break;
        }

        iStart++;
        iEnd--;
    }

    return bFlag;
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

    if(sobj.BiDirectionalSearch(30) == true)
    {
        cout<<"Element is Present\n";
    }
    else
    {
        cout<<"There is no such element\n";
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

Element is Present

===============================================================================
End of Program
===============================================================================
*/

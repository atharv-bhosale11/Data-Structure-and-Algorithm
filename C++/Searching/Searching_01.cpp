/*
===============================================================================
Program Name    : Searching Skeleton
Program Number  : 001
File Name       : Searching01.cpp
        
Description     : Basic Skeleton Program for Searching Techniques.

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

Searching :: Searching(int iNo)
{
    iSize = iNo;
    Arr = new int[iSize];
}

Searching :: ~Searching()
{
    delete []Arr;
}

void Searching :: Accept()
{
}

void Searching :: Display()
{
}

int main()
{
    Searching sobj(5);

    return 0;
}

/*
===============================================================================
Output :

(No Output)

===============================================================================
End of Program
===============================================================================
*/

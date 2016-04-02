// classH.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class H
{
private:
    int a, b;

public:
    H(int = 1, int = 1);
    H(H const &);
    void display() const;
};

H::H(int x, int y)
{
    a = x;
    b = y;
}

H::H(H const &r)
{
    a = r.a;
    b = r.b;
}

void H::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    H e1;           // инициализираме обект е1 от клас Н с неговите дефолтни стойности в куструктора (т.е. 1 1).   
	H e2(6);		// инициализираме обект е2 от клас Н, като подаваме стойност само на първия му параметър (т.е. а).
	H e3(3, 8);		// инициализираме обект е3 от клас Н, като подаваме стойност и на двата му параметъра (т.е. а и b).

    e1.display();     // 1 1      
    e2.display();     // 6 1
    e3.display();	  // 3 8

    H e4 = e3;      // инициализираме обект е4 от клас Н, чиито полета имат същите стойности като е3

    e4.display();     // 3 8
    return 0;
}
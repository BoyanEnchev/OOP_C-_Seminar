// classK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class K
{
private:
    int a;
    double b;

public:
    K(int, double);
    K(K const &);
    void display() const;
};

K::K(int x, double y)
{
    a = x;
    b = y;
}

K::K(K const &r)
{
    a = r.a;
    b = r.b;
}

void K::display() const
{
    cout << a << " " << b << endl;
}

int main()
{
    K e1(4, 1.8), *e2 = &e1;   // e1 e ����� �� ���� �. �2 � ��������, ����� ���� ��� ������ �� �1
    e1.display();		// 4  1.8
    e2->display();		// 4  1.8
    K e3 = *e2;			// ��������� ����� �3 �� ���� � ��������� �� ��������� �2, ����� ���� ��� �1
    e3.display();		// 4  1.8
    return 0;
}
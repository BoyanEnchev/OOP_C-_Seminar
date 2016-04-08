// PersonStruct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


struct Person 
{
	char firstname[100];
	char lastname[100];
};

void initPerson(Person& p)
{
	cout << "First name: ";
	cin >> p.firstname;
	cout << "Last name: ";
	cin >> p.lastname;
}



Person read_person()
{
	Person p;
	cout << "First name: ";
	cin >> p.firstname;
	cout << "Last name: ";
	cin >> p.lastname;
	return p;
}


void printPerson(Person p)
{
	cout << p.firstname;
	cout << p.lastname;
}

struct Client
{
	Person per;
	double bankAccount;
};

void initClient(Person& per, Client& cl, double money)
{
	cl.per = per;
	cl.bankAccount = money;
}

 

Client read_client()
{
	Client cl;
	cl.per = read_person();
	cout << "Money in the bank account: ";
	cin >> cl.bankAccount;
	return cl;
}

void printClient(Client cl)
{
	cout << "Person: " << cl.per.firstname << " " << cl.per.lastname;
	cout << "Money in the bank account: " << cl.bankAccount;
}


void initClients(Client *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "Client number: " << i << endl;
		cout << "First name: ";
		cin >> arr[i].per.firstname;
		cout << "Last name: ";
		cin >> arr[i].per.lastname;
		cout << "Money in the bank account: ";
		cin >> arr[i].bankAccount;
	}
}



void PrintClients(Client *arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i].per = read_person();
		cout << "Clients: " << read_person << arr[i].bankAccount << endl;
	}
}



double SumOfMoney(Client *arr, int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i].bankAccount;
	}
	return sum;
}




int _tmain(int argc, _TCHAR* argv[])
{
	Client arr[100];
	initClients(arr, 5);
	PrintClients(arr, 5);
	cout << SumOfMoney(arr, 5) << endl;

	return 0;
}


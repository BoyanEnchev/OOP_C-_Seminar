// BankAccount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Person{
	char *name;
	char ID[11];

public:
	Person(char*Name, char*id){
		name = new char[strlen(Name)+1];
		strcpy_s(name, strlen(Name)+1, Name);
		strcpy_s(ID, id);
	}
	char* getName();
	void setName(char* Name);
};

class BankAccount{
	char clientName[23];
	char IBAN[15];
	int balance;

public: BankAccount(char* name, char* iban, int Balance){
			strcpy_s(clientName, name);
			strcpy_s(IBAN, iban);
			balance = Balance;
		}
		char* getName();
		void setName(char*name);
		char* getIBAN();
		void setIBAN(char*iban);
		int getBalance();
		void setBalance(int);

		void printAccount();
		void Deposit(int money);
		void Withdraw(int money);
};

char* Person:: getName(){
	return name;
}
void Person:: setName(char*Name){
	name = new char[strlen(name)+1];
	strcpy_s(name, strlen(Name+1), Name);
}

char* BankAccount:: getName(){
	return clientName;
}
void BankAccount:: setName(char*name){
	strcpy_s(clientName,name);
}
char* BankAccount:: getIBAN(){
	return IBAN;
}
void BankAccount:: setIBAN(char*iban){
	strcpy_s(IBAN,iban);
}
int BankAccount:: getBalance(){
	return balance;
}
void BankAccount:: setBalance(int Balance){
	balance = Balance;
}

void BankAccount:: printAccount(){
	cout<<"Client'name"<<clientName<<endl;
	cout<<"IBAN: "<<IBAN<<endl;
	cout<<"Balance: "<<balance<<endl;
}
void BankAccount:: Deposit(int money){
	if(money <=0) cout<<"Invalid input! You must cin a possitive sum of money"<<endl;
	else{
		balance += money;
		cout<<"You deposit "<<money<<" leva in your account"<<endl; 
		}
}

void BankAccount:: Withdraw(int money){
	if(money <=0) cout<<"Invalid input! You must cin a possitive sum of money"<<endl;
	else{
		if(balance<money){
			cout<<"Invalid withdraw! You money is not enoght to make withdraw!"<<endl;
		}
		else{
			balance -= money;
			cout<<"You withdraw "<<money<<" leva of your account"<<endl; }
}
}


int _tmain(int argc, _TCHAR* argv[])
{
	char pesho[] = "Petar Ivanov";
	char peshoIban[] = "BG762685937282";

	BankAccount gosho("Gosho Petkov","BG544445937282", 1500);

	cout<<"Georgi's balance: "<<gosho.getBalance()<<endl;
	gosho.Deposit(500);
	cout<<"Georgi's balance: "<<gosho.getBalance()<<endl;
	gosho.Withdraw(3000);
	gosho.Withdraw(100);

	Person maya("Maya Angelova", "9305067777");
	cout<<maya.getName()<<endl;

	maya.setName("Petya");
	cout<<maya.getName()<<endl;


	
	return 0;
}


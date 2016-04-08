// Destination.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


struct Destination{
	char city[100];
	int km;
	};


Destination read_destination(){
	Destination dest;
	cout<<"Enter city: ";
	cin>>dest.city;
	cout<<"Enter km :";
	cin>>dest.km;
	return dest;
}
void init_destination(Destination &dest, char* city, int km){
	strcpy_s(dest.city,city);
	dest.km = km;
	
	cout<<"You initialized destination:  "<<dest.city<<" and distance from Sofia to it is: "<<dest.km<<endl;

}

void init_ArrayByDefault(Destination *arr){
	for(int i=0; i<30; i++){
		
		arr[i].km = 0;
		*arr[i].city = NULL;
	}
}

void testInit_Destination(Destination *arr){
	
	 Destination dest1, dest2, dest3, dest4, dest5;
		
	 char Varna[32] = "Varna";
	 char Plovdiv[32] = "Plovdiv";
	 char Burgas[32] = "Burgas";
	 char Vidin[32] = "Vidin";
	 char Dobrich[32] = "Dobrich";

	 init_destination(dest1, Varna, 469);
	 init_destination(dest2, Plovdiv, 165);
	 init_destination(dest3, Burgas, 393);
	 init_destination(dest4, Vidin, 199);
	 init_destination(dest5, Dobrich, 512);

	 arr[0] = dest1;
	 arr[1] = dest2;
	 arr[2] = dest3;
	 arr[3] = dest4;
	 arr[4] = dest5;
	
}

void print_testArr(Destination* arr){
	cout<<endl<<"Printing test array:"<<endl;

	for(int i=0; i<5; i++){
		cout<<arr[i].city<<" "<<arr[i].km<<" km"<<endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	Destination firstDest;
	Destination secondDest;  
	char Varna[32] = "Varna";
	char Plovdiv[32] = "Plovdiv";

	init_destination(firstDest, Varna, 469);     //Инициализиране на структурите (Варна и Пловдив)
	init_destination(secondDest, Plovdiv, 355);

	cout<<endl;
	
	Destination defineArr[30];             //Дефиниране на масив от 30 структури
	init_ArrayByDefault(defineArr);		//Инициализиране на масива с дефолтните стойности на полетата от структурата
		

	Destination test_initArr[5];
	testInit_Destination(test_initArr);    //Тестване функционалността на масив от 5 структури и принтиране на екрана
	print_testArr(test_initArr);



	return 0;
}


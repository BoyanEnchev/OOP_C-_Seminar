// 7.DeleteIntFromString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool CutString(int* arr, int length,int number, int& counter);
void ReadString(int*arr, int n);
void WriteString(int*arr, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int n, counter=0, number;
	cout<<"Enter n: "; cin>>n;
	int arr[100];
	cout<<"Enter char array with "<<n<<" numbers:"<<endl;
	ReadString(arr,n);

	cout<<"Enter the element that you want to delete: "; cin>>number;
	cout<<endl;

	cout<<boolalpha<<CutString(arr,n,number,counter)<<" ";
	WriteString (arr,n-counter);
	
	return 0;
}
void ReadString(int*arr, int n)
{
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
}

bool CutString(int* arr,int lenght,int number, int& counter)     //приемаме стойноста на counter по псевдоним, т.е. на копираме стойността му,
{                                                      //а директно работим със самата променлива.
	int index = lenght;
	for(int i=0; i<lenght; i++)
	{
		if(arr[i]==arr[i+1]) //провер€ваме за повтар€щи се поредни елементи в масива
		{
			if(arr[i]==number) 
			{
				for(int j=i; j<index-1; j++) 
				{
					arr[j]=arr[j+1];
				}
				arr[index-1]=0; //на вече празните позиции в кра€ на масива записваме 0-ли
				index--;
				counter++; //избро€ваме колко елементи ще махнем от масива
				i--;
			}
		}	
		else
		{
			if(arr[i]==number) 
			{
				for(int j=i; j<index-1; j++) 
				{
					arr[j]=arr[j+1];
				}
				arr[index-1]=0;
				index--;
				counter++;
			}
		}
	}
	if(counter==0) return false;
	else return true;
}

void WriteString(int*arr, int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
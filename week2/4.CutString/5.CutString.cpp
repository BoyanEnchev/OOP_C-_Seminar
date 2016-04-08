// 4.CutString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void CutString(char* arr, int length, int& counter);
void ReadString(char*arr, int n);
void WriteString(char*arr, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int n, counter=0;
	cout<<"Enter n: "; cin>>n;
	char arr[100];
	cout<<"Enter char array with n symbols:"<<endl;
	cout<<endl;

	
	ReadString(arr,n);
	CutString(arr,n,counter);
	WriteString (arr,n-counter); 
	cout<<endl;
	
	
	return 0;

}
void ReadString(char*arr, int n)
{
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
}

void CutString(char* arr,int lenght, int& counter)     //приемаме стойноста на counter по псевдоним, т.е. на копираме стойността му,
{                                                      //а директно работим със самата променлива.
	int index = lenght;
	for(int i=0; i<lenght; i++)
	{
		char x=arr[i];
		
		if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') 
		{
			for(int j=i; j<index-1; j++) 
			{
				arr[j]=arr[j+1];
			}
			arr[index-1]=0; //на вече празните позиции в края на масива записваме 0-ли
			index--;
			counter++; //изброяваме колко елементи ще махнем от масива
			i--;
		}
	}
	
}
void WriteString(char*arr, int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
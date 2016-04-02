// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Point3{
private:
	int x,y,z;
public:
	Point3(int,int,int);
	const int getX() const;
	const int getY() const;
	const int getZ() const;
	void setX(int);
	void setY(int);
	void setZ(int);
	void Print();

};

Point3 :: Point3(int x=0, int y=0, int z=0){
	this->x = x;
	this->y = y;
	this->z = z;
}
const int Point3 :: getX() const{
	return this->x;
}
const int Point3 ::  getY() const{
	return this->y;
}
const int Point3 :: getZ() const{
	return this->z;
}
void Point3 :: setX(int x){
	this->x = x;
}
void Point3 :: setY(int y){
	this->y = y;
}
void Point3 :: setZ(int z){
	this->z = z;
}
void Point3 :: Print(){
	cout<<"x = "<<x<<" y = "<<y<<" z = "<<z<<endl;
}

bool cmp(Point3 a, Point3 b){
	if(a.getX() > b.getX()) return true;
	else if (a.getX() < b.getX()) return false;
	else{
		if(a.getY() > b.getY()) return true;
		else if (a.getY() < b.getY()) return false;
		else{
			if(a.getZ() > b.getZ()) return true;
			else if (a.getZ() < b.getZ()) return false;
			else return true;    //ако стигне дотук => двете точки са равни, т.е. връщаме една от тях;
		}
	}
}

void sort(Point3* arrP3, int size){
	for(int i=0; i<size-1; ++i){
		for(int j=i; j<size; ++j){
			if(cmp(arrP3[i],arrP3[j])){
				Point3 temp;
				temp = arrP3[i];
				arrP3[i] = arrP3[j];
				arrP3[j] = temp;
			}
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{

	Point3 a(3,4,5);
	Point3 b(3,2,6);
	Point3 c(2,7,8);
	Point3 arr[10];
	arr[0] = a; arr[1] = b; arr[2] = c;

	for(int i = 0; i < 3; i++) arr[i].Print();
	sort(arr,3);
	cout<<endl;
	for(int i = 0; i < 3; i++) arr[i].Print();

	return 0;
}


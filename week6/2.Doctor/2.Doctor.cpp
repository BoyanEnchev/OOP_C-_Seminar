// Doctor2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;



class Date{
public:
	int year, month, day; 
	Date(int, int, int);
};
Date :: Date(int year=0, int month = 0, int day = 0){
	this->year = year;
	this->month = month;
	this->day = day;
}

class Patient{

	char name[100];
	Date date;
	int numVisits;
public:
	Patient(char*,int);
	char* getName();
	Date getDate();
	int getNumVisits();
	void setName(char*);
	void setDate(Date);
	void setNumVisits(int);

};
Patient :: Patient(char* name = "", int visits=0){
	
	strcpy_s(this->name, name);
	this->numVisits = visits;

}
char* Patient :: getName(){
	return this->name;
}
Date Patient :: getDate(){
	return this->date;
}
int Patient :: getNumVisits(){
	return this->numVisits;
}
void Patient :: setName(char* name){
	strcpy_s(this->name, name);
}
void Patient :: setDate(Date date){
	this->date.year = date.year;
	this->date.month = date.month;
	this->date.day = date.day;
}
void Patient :: setNumVisits(int visits){
	this->numVisits = visits;
}

Patient Read_Patient(){							//Въвеждаме пациента от конзолата
	Patient p;
	int _year,_month,_day;
	cout<<"Enter patient year of born: "; cin>>_year;
	cout<<"Enter patient month of born: "; cin>>_month;
	cout<<"Enter patient day of born: "; cin>>_day;
	Date _date(_year,_month,_day);
	p.setDate(_date); 

	char Name[100];
	cout<<"Enter patient' name: ";
	cin.getline(Name,100,'#');
	p.setName(Name);

	int _visits;
	cout<<"Enter number of visits: "; cin>>_visits;
	p.setNumVisits(_visits);

	return p;
}

class Doctor{
	char* name;
	int numPatients;
public:
	Patient* patients;
	Doctor(Patient*, char*, int);
	~Doctor();
	char* getName();
	void setName(char*);
	void printPatients();
	void printPatients(int overNumVisits);
};

Doctor :: Doctor(Patient* _patients = NULL , char* _name = "", int sizePatients = 0){
	this->name = new char[strlen(_name)+1];
	strcpy_s(name, strlen(_name)+1, _name);

	this->patients = new Patient[2*sizePatients];
	for(int i=0; i<sizePatients; ++i){                          //"Прехвърляме" пациентите (техните данни) в масива на Доктор-а
		this->patients[i].setName(_patients[i].getName());
		this->patients[i].setDate(_patients[i].getDate());
		this->patients[i].setNumVisits(_patients[i].getNumVisits());
	}
	numPatients = sizePatients;
}
Doctor :: ~Doctor(){
	delete[] this->name;
	delete[] this->patients;
}
char* Doctor :: getName(){
	return this->name;
}
void Doctor :: setName(char* name){
	strcpy_s(this->name, strlen(name)+1, name);
}
void Doctor :: printPatients(){                           // Принтираме всички пациенти на даден лекар
	for(int i=0; i<numPatients; i++){
		cout<<"name: "<<patients[i].getName()<<endl;
		cout<<"date: "<<patients[i].getDate().year<<" "<<patients[i].getDate().month<<" "<<patients[i].getDate().day<<endl;
		cout<<"number of visits: "<<patients[i].getNumVisits()<<endl;
	}
}
void Doctor :: printPatients(int overNumVisits){          //Принтираме само пациентите, чиито брой посещения е по-голям от зададения от нас
	for(int i=0; i<numPatients; i++){
		if(patients[i].getNumVisits() > overNumVisits){
			cout<<"name: "<<patients[i].getName()<<endl;
			cout<<"date: "<<patients[i].getDate().year<<" "<<patients[i].getDate().month<<" "<<patients[i].getDate().day<<endl;
			cout<<"number of visits: "<<patients[i].getNumVisits()<<endl;
		}
	}
	cout<<endl;
}


int main(int argc, _TCHAR* argv[])
{
	Patient pesho = Read_Patient();   //Може да четем пациент от конзолата
	Patient gesho = Read_Patient();
	Patient mesho = Read_Patient();

	Patient PetkovPacients[10];
	PetkovPacients[0] = pesho; 
	PetkovPacients[1] = gesho; 
	PetkovPacients[2] = mesho; 
	
	Doctor drPetkov( PetkovPacients, "Petko Petkov", 3);
	drPetkov.printPatients(2);           // Принтираме пациентите, които са посетили д-р Петков повече от 2 пъти

	
	return 0;
}


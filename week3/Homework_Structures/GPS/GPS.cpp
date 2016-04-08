#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

struct City
{
	char *name;
	int population; // в хиляди 
	bool hasMuseum;	
};

void initCity(City &City, char* Name, int Population, bool HasMuseum)
{
	City.name = new char[strlen(Name) + 1];

	strcpy_s(City.name, strlen(Name) + 1, Name);
	City.population = Population;
	City.hasMuseum = HasMuseum;

	cout << City.name << " | " << City.population << " | " << City.hasMuseum << endl;
}

struct Destination
{
	City city;
	int kilometers;

};

struct GPS
{
	City currentCity;
	Destination path[10];
};

void initDest(Destination &dest, City City, int km, Destination *arr, int &index)
{
	dest.city = City;
	dest.kilometers = km;
	arr[index] = dest;
	index++;
}

void initGPS(GPS &gps, City curr, Destination *arr, int &index)
{
	
	gps.currentCity = curr;
	

	for (int i = 0; i < index; i++)
	{
		gps.path[i] = arr[i];
	}
}

void searchForMuseum(GPS &gps,int index)
{
	for (int i = 0; i < index; i++)
	{
		if (gps.path[i].city.hasMuseum == true)
		{
			cout << "There is a museum in " << gps.path[i].city.name << "." << endl;
		}
		else
		{
			cout << "There is no museum in " << gps.path[i].city.name << "." << endl;
		}
	}
}

void distanceToCity(GPS &gps, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (gps.currentCity.name != gps.path[i].city.name)
		{
			if (gps.path[i].kilometers <= 100)
			{
				cout << gps.path[i].city.name << " is close to " << gps.currentCity.name << "." << endl;
			}
			else if (gps.path[i].kilometers > 100 && gps.path[i].kilometers <= 200)
			{
				cout << gps.path[i].city.name << " is not so close to " << gps.currentCity.name << "." << endl;
			}
			else
			{
				cout << gps.path[i].city.name << " is far away from " << gps.currentCity.name << "." << endl;
			}
		}
	}
}

void sortByName(GPS &GPSRoad, int size)
{
	for (int i = 0; i < size - 1; i++){
		for (int j = i+1; j < size; j++){
			if (strcmp(GPSRoad.path[j].city.name, GPSRoad.path[j + 1].city.name) > 0)
			{
				Destination swap = GPSRoad.path[j];
				GPSRoad.path[j] = GPSRoad.path[j + 1];
				GPSRoad.path[j + 1] = swap;
			}
		}
	}
			for(int i=0; i<size; i++){
			cout<<GPSRoad.path[i].city.name;
			}
}


int _tmain(int argc, _TCHAR* argv[])
{
	City Varna = { "Vraca", 100, true };
	City Sofia = { "Sofia", 2000, true };
	City Plovdiv = { "Sliven", 300, false };
	City Lovech = { "Burgas", 500, true };

	Destination vraca, sofia, sliven, burgas;

	int index = 0;
	Destination arr[10];

	initDest(vraca, Varna, 100, arr, index);
	initDest(sofia, Sofia, 0,arr, index);
	initDest(sliven, Plovdiv, 300, arr, index);
	initDest(burgas, Lovech, 400, arr, index);

	GPS gps;

	initGPS(gps, Sofia, arr, index);

	searchForMuseum(gps, index);
	cout << endl;

	distanceToCity(gps, index);
	cout << endl;
	sortByName(gps,3);
	

	
	cout << endl;


	return 0;
}

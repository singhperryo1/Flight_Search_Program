#include "Node.h"
#include "Stack.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct city
{
	char cityName;
	bool visited;
	Node <char> *adjacent;
};
int const MAX = 9; //currently the company serves 9 cities
city flightMap[MAX]; //declare a global array for flight map 

void createMap();
void displayMap();
bool isInMap(char aCity);
void displayMap();
void displayAllCities();
void markVisited(char aCity);
void unVisitedAll();
bool isVisited(char aCity);
void addAdjacentCity(char aCity, char adjCity);
bool getNextUnvisitedAdjCity(char aCity, char &adjCity);
bool inPath(char origin, char destination);
int main()
{
	createMap();
	displayMap();
	if (inPath('F', 'A'))
	{
		cout << "Yes" << endl; 
	}
	else
	{
		cout << "No!" << endl; 
	}
}

void createMap()
{
	Node<char> *newNode;
	flightMap[0].cityName = 'A';
	flightMap[1].cityName = 'B';
	flightMap[2].cityName = 'C';
	flightMap[3].cityName = 'D';
	flightMap[4].cityName = 'E';
	flightMap[5].cityName = 'F';
	flightMap[6].cityName = 'G';
	flightMap[7].cityName = 'H';
	flightMap[8].cityName = 'I';
	//-----------------------------------//
	flightMap[0].visited = false;
	flightMap[1].visited = false;
	flightMap[2].visited = false;
	flightMap[3].visited = false;
	flightMap[4].visited = false;
	flightMap[5].visited = false;
	flightMap[6].visited = false;
	flightMap[7].visited = false;
	flightMap[8].visited = false;
	//---------------------------------//
	flightMap[0].adjacent = new Node <char>('B', NULL);
	flightMap[2].adjacent = new Node <char>('B', NULL);
	flightMap[3].adjacent = new Node <char>('E', NULL);
	newNode = new Node <char>('C', flightMap[3].adjacent);
	flightMap[3].adjacent = newNode;
	flightMap[4].adjacent = new Node <char>('H', NULL);
	newNode = new Node <char>('F', flightMap[4].adjacent);
	flightMap[4].adjacent = newNode;
	flightMap[5].adjacent = new Node <char>('G', NULL);
	flightMap[6].adjacent = new Node <char>('E', NULL);
	flightMap[7].adjacent = new Node <char>('I', NULL);
	newNode = new Node <char>('C', flightMap[7].adjacent);
	flightMap[7].adjacent = newNode;
}

void displayMap()
{
	int i = 0;

	cout << "City Name     Visited     Adjacent City" << endl;
	while (i < MAX)
	{
		cout << flightMap[i].cityName;
		{
			if (flightMap[i].visited)
				cout << "             True";
			else
				cout << "             False";

		}
		if (flightMap[i].adjacent == NULL)
		{
			cout << "          None";
		}
		else
		{

			Node <char> *curro = flightMap[i].adjacent;

			while (curro != NULL)
			{
				cout << "          " << curro->getItem();
				curro = curro->getNext();
			}
		}


		cout << endl;
		i++;
	}
}

bool isInMap(char aCity)
{
	for (int i = 0; i < MAX; i++)
	{
		if (flightMap[i].cityName == aCity)
			return true;
	}
	return false;
}
void displayAllCities()
{
	cout << "The company serves the following cities:" << endl;
	int count = 1;
	for (int i = 0; i < MAX; i++)
	{
		cout << count << ") ";
		cout << flightMap[i].cityName;
		cout << endl;
		count++;
	}
}
void markVisited(char aCity)
{
	if (isInMap(aCity))
	{
		cout << "City marked visited" << endl;
		for (int i = 0; i <MAX; i++)
		{
			if (flightMap[i].cityName == aCity)
			{
				flightMap[i].visited = true;
			}
		}
	}
	else {
		cout << "The city is not found" << endl;
	}

}
void unVisitedAll()
{
	for (int i = 0; i < MAX; i++)
	{
		flightMap[i].visited = false;
	}
}
bool isVisited(char aCity)
{
	int index;
	for (int i = 0; i < MAX; i++)
	{
		if (flightMap[i].cityName == aCity)
		{
			index = i;
			if (flightMap[index].visited == true)
			{
				return true;
			}
		}
	}
	return false;
}
void addAdjacentCity(char aCity, char adjCity)
{
	if (!isInMap(aCity) || !isInMap(adjCity))
	{
		cout << "Invalid Inputs! \n" << endl;
		cout << "The Program aborted!" << endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < MAX; i++)
		{
			if (flightMap[i].cityName == aCity)
			{
				Node <char> *add;
				add = new Node <char>(adjCity, flightMap[i].adjacent);
				flightMap[i].adjacent = add;
			}
		}
	}
}
bool getNextUnvisitedAdjCity(char aCity, char &adjCity)
{
	if (!isInMap(aCity))
	{
		cout << "Program aborted" << endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < MAX; i++)
		{
			if (flightMap[i].cityName == aCity)
			{
				Node<char> *curo = flightMap[i].adjacent;

				while (curo != NULL)
				{
					if (!isVisited(curo->getItem()))
					{
						adjCity = curo->getItem();
						return true;
					}
					curo = curo->getNext();
				}

				return false;
			}

		}
	}
}
bool inPath(char origin, char destination)
{
	Stack <char> myStack; 
	char topCity, nextCity; 
	bool success; 
	unVisitedAll();
	markVisited(origin); 
	myStack.push(origin); 
	topCity = myStack.peek();
	while (!myStack.isEmpty() && topCity != destination)
	{
		success = getNextUnvisitedAdjCity(topCity, nextCity);
		if (!success)
		{
			myStack.pop();
		}
		else
		{
			markVisited(nextCity);
			myStack.push(nextCity);
		}
		topCity = myStack.peek();
	}

		if (myStack.isEmpty())
		{
			return false;
		}
		else
		{
			return true;
		}
	
}
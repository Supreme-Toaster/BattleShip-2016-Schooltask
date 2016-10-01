#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//get row and collumn values and puts them into a array and then return the result.
int mapShipArray(int seaArray[5][5], int rowTarget, int collumnTarget);
//get playername and inserts it into a string array
string playerArray(string nameInput[2], int i, string nameHolder);
//get user input and process the information before sending it to mapShipArray
int boatPlacement(int seaArray[5][5], int valueInput, int rowTarget, int collumnTarget);

int main()
{

	srand(time(NULL));
	int valueInput = 0, playerId = 0, rowTarget = 0, collumnTarget = 0;
	const int COLLUMN = 5;
	const int ROW = 5;
	const int NAME = 2;
	string nameInput[NAME], nameHolder;
	//layout for boatplacement. (two dimensional)
	int seaArray[ROW][COLLUMN] = { { 0 }, { 0 } };
	// layout for boatplacement (contains both opponent and user arrray: three dimensional array)
	int boardArray[NAME][ROW][COLLUMN] = { {0} ,{0} };



	cout << "Welcome to the game of battleships, please enter your names and then proceed with the game." << endl;

	while ((playerId < 2))
	{
		cout << "Player " << playerId + 1 << ":";
		getline(cin, nameHolder);
		playerArray(nameInput, playerId, nameHolder);
		playerId++;
	}


	system("CLS");
	playerId = rand() % 2 + 1;
	cout << "Player " << playerId << " get's to play first." << endl << endl;
	cout << "Each player get to place three ships and fire your cannon continuously until you miss your target!" << endl;

	cout << "Press Enter and the game can commence." << endl;
	system("PAUSE");
	system("CLS");

	for (int j = 0;j < 2;j++)
	{
		cout << nameInput[playerId - 1] << ": Place your three ships!" << endl;

		boatPlacement(seaArray, valueInput, rowTarget, collumnTarget);

		boardArray[playerId - 1][ROW][COLLUMN] = seaArray[ROW][COLLUMN] = {1};
		system("CLS");
		if (playerId > 1)
		{
			playerId--;
		}

	}



	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << " " << seaArray[i][j] << " ";
		}
		cout << endl;
	}



	system("PAUSE");
	cout << "Time to switch players";




	return 0;
}





int mapShipArray(int seaArray[5][5], int rowTarget, int collumnTarget)
{
	seaArray[rowTarget][collumnTarget] = { 1 };
	return seaArray[5][5];
}

string playerArray(string nameInput[2], int i, string nameHolder)
{
	nameInput[i] = { nameHolder };
	return nameInput[i];
}

int boatPlacement(int seaArray[5][5], int valueInput, int rowTarget, int collumnTarget)
{
	for (int i = 0;i < 3;i++)
	{
		cout << "Ship location row: ";
		cin >> valueInput;

		while (cin.fail() || valueInput < 0 || valueInput > 5)
		{
			cin.clear();
			cout << "Please enter a numeric number!" << endl << endl;
			cout << "Target location row:: ";
			cin.get();
			cin >> valueInput;
		}

		rowTarget = valueInput - 1;
		cin.clear();
		cout << "Target location collumn: ";
		cin.get();
		cin >> valueInput;

		while (cin.fail() || valueInput < 0 || valueInput > 5)
		{
			cin.clear();
			cout << "Please enter a numeric number!" << endl << endl;
			cout << "Target location collumn: ";
			cin.get();
			cin >> valueInput;
		}

		collumnTarget = valueInput - 1;

		mapShipArray(seaArray, rowTarget, collumnTarget);

	}
	return rowTarget, collumnTarget;
}




/*for (int i = 0;i < 3;i++)
{
cout << "Ship location row: ";
cin >> valueInput;

while (cin.fail() || valueInput < 0 || valueInput > 5)
{
cin.clear();
cout << "Please enter a numeric number!" << endl << endl;
cout << "Target location row:: ";
cin.get();
cin >> valueInput;
}

rowTarget = valueInput - 1;
cin.clear();
cout << "Target location collumn: ";
cin.get();
cin >> valueInput;

while (cin.fail() || valueInput < 0 || valueInput > 5)
{
cin.clear();
cout << "Please enter a numeric number!" << endl << endl;
cout << "Target location collumn: ";
cin.get();
cin >> valueInput;
}

collumnTarget = valueInput - 1;*/
/*	for (int i = 0;i < 3;i++)
{
seaArray[ROW][COLLUMN] = mapShipArray(seaArray, rowTarget, collumnTarget);*/
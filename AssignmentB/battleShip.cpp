#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//get row and collumn values and puts them into a array and then return the result.
int mapShipArray(int seaArray[2][5][5], int rowTarget, int collumnTarget, int playerId);
//get playername and inserts it into a string array
string playerArray(string nameInput[2], int i, string nameHolder);
//get user input and process the information before sending it too mapShipArray
int boatPlacement(int seaArray[2][5][5], int valueInput, int rowTarget, int collumnTarget, int playerId);
//Display player boat selection map before switching players.
int boatArrayDisplay(int seaArray[2][5][5], int playerId);
//Compare target with opponent array.
int commenceFire(int seaArray[2][5][5], int valueInput, int rowTarget, int collumnTarget, int playerId, string nameInput[2]);
//Display both players boards and who is the winner.
int endGame(string nameInput[2], string nameHolder, int playerId, int seaArray[2][5][5]);
//Function for comparing players boat layout and see if a hit was triggerd.
int hitShipArray(int seaArray[2][5][5], int rowTarget, int collumnTarget, int playerId);


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));
	int valueInput = 0, playerId = 0, rowTarget = 0, collumnTarget = 0;
	const int COLLUMN = 5;
	const int ROW = 5;
	const int NAME = 2;
	string nameInput[NAME], nameHolder;
	int seaArray[NAME][ROW][COLLUMN] = { { 0 }, { 0 } };




	cout << "Welcome to the game of battleships, please enter your names and then proceed with the game." << endl;
	//Inserting playernames to an array and executes it with function.
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

	cout << "Game can now commence:" << endl;
	system("PAUSE");
	system("CLS");

	for (int j = 0;j < 2;j++)
	{
		cout << nameInput[playerId - 1] << ": Place your three ships!" << endl;
		//User inputs boat location.
		boatPlacement(seaArray, valueInput, rowTarget, collumnTarget, playerId);
		system("CLS");
		if (playerId > 1)
		{
			playerId--;
		}
		else
		{
			if (j < 1)
			{
				playerId++;
			}
		}
		system("CLS");
	}

	cout << "The battle will now begin and player: " << nameInput[playerId] << " will get the first shot.  " << endl << "Good luck!";
	system("pause");

	//Take the information we know and compare it with the players arrays en return the new value after game end.
	commenceFire(seaArray, valueInput, rowTarget, collumnTarget, playerId, nameInput);


	//Outputs the results and who won the game.
	endGame(nameInput, nameHolder, playerId, seaArray);
	cout << "If you want to play again, type (rematch): ";
	cin.ignore();
	getline(cin, nameHolder);
	if (nameHolder == "rematch")
	{
		system("cls");
		main();

	}
	else
	{
		cout << "Thanks for playing and better luck next time!" << endl;
		system("pause");
	}
	return 0;
}





int mapShipArray(int seaArray[2][5][5], int rowTarget, int collumnTarget, int playerId)
{
	seaArray[playerId][collumnTarget][rowTarget] = { 1 };
	return seaArray[playerId][5][5];
}

int hitShipArray(int seaArray[2][5][5], int rowTarget, int collumnTarget, int playerId)
{
	seaArray[playerId][collumnTarget][rowTarget] = { 2 };
	return seaArray[playerId][5][5];
}

string playerArray(string nameInput[2], int i, string nameHolder)
{
	nameInput[i] = { nameHolder };
	return nameInput[i];
}

int boatPlacement(int seaArray[2][5][5], int valueInput, int rowTarget, int collumnTarget, int playerId)
{
	for (int i = 0;i < 3;i++)
	{
		cout << "Ship location row: ";
		cin >> valueInput;
		//Errorhandler
		while (cin.fail() || valueInput < 0 || valueInput > 5)
		{
			cin.clear();
			cout << "Please enter a different numeric number!" << endl << endl;
			cout << "Target location row:: ";
			cin.get();
			cin >> valueInput;
		}

		rowTarget = valueInput - 1;
		cin.clear();
		cout << "Target location collumn: ";
		cin.get();
		cin >> valueInput;
		collumnTarget = valueInput - 1;
		//Errorhandler with overlap controller
		while (cin.fail() || valueInput < 0 || valueInput > 5 || seaArray[playerId - 1][collumnTarget][rowTarget] != 0)
		{
			cin.clear();
			cout << "Please enter a different numeric number!" << endl << endl;
			cout << "Target location collumn: ";
			cin.get();
			cin >> valueInput;
			collumnTarget = valueInput - 1;
		}



		mapShipArray(seaArray, rowTarget, collumnTarget, playerId - 1);

	}
	return rowTarget, collumnTarget;
}

int boatArrayDisplay(int seaArray[2][5][5], int playerId)
{
	//Simple loop for displaying results.
	for (int h = 0;h < 1;h++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << " " << seaArray[playerId - 1][i][j] << " ";
			}
			cout << endl;
		}
	}
	return seaArray[2][5][5];
}

int commenceFire(int seaArray[2][5][5], int valueInput, int rowTarget, int collumnTarget, int playerId, string nameInput[2])
{
	//Similar to boatPlacement() with some exceptions.

	int i = 0, j = 0, h = 0,hit1=0,hit2=0;
	while (h < 1)
	{
		system("CLS");
		cout << "Player: " << nameInput[playerId] << " at the command." << endl;
		cout << "Target location row: ";
		cin >> valueInput;

		while (cin.fail() || valueInput < 0 || valueInput > 5)
		{
			system("CLS");
			cout << "Player: " << nameInput[playerId] << " at the command." << endl;
			cin.clear();
			cout << "Cannon missalignment!" << endl << endl;
			cout << "Target location row:: ";
			cin.get();
			cin >> valueInput;
		}

		rowTarget = valueInput - 1;
		cin.clear();
		cout << "Target location collumn: ";
		cin.get();
		cin >> valueInput;
		collumnTarget = valueInput - 1;

		while (cin.fail() || valueInput < 0 || valueInput > 5)
		{
			system("CLS");
			cout << "Player: " << nameInput[playerId] << " at the command." << endl;
			cin.clear();
			cout << "Cannon missalignment " << endl << endl;
			cout << "Target location collumn: ";
			cin.get();
			cin >> valueInput;
			collumnTarget = valueInput - 1;
		}

		if (playerId < 1)
		{
			playerId++;
		}
		else
		{
			playerId--;
		}

		if (seaArray[playerId][collumnTarget][rowTarget] != 1)
		{
			system("CLS");
			cout << "Cannon round missed it's target and the enemy have been given the opportunity to fire back." << endl << endl;
			cout << "Switch players and then press enter.";
			cin.ignore();
			system("pause");
		}

		if (seaArray[playerId][collumnTarget][rowTarget] == 1)
		{
			if (playerId == 1)
			{
				hit1++;
				hitShipArray(seaArray, rowTarget, collumnTarget, playerId);
				cout << endl << "Hit " << hit1 << "!!";
				system("pause");

				if (playerId < 1)
				{
					playerId++;
				}

				else
				{
					playerId--;
				}

				i++;

				if (i == 3)
				{
					h++;
				}
			}
			else if (playerId == 0)
			{
				hit2++;
				hitShipArray(seaArray, rowTarget, collumnTarget, playerId);
				cout << endl << "Hit " << hit2<<"!!";
				system("pause");

				if (playerId < 1)
				{
					playerId++;
				}

				else
				{
					playerId--;
				}

				j++;

				if (j == 3)
				{

					h++;

				}
			}

		}

	}
	return seaArray[2][5][5], playerId;
}

int endGame(string nameInput[2], string nameHolder, int playerId, int seaArray[2][5][5])
{
	system("cls");
	int winnerCheck = 0;
	//Loop through updated board and display both players results.
	for (int h = 0;h < 2;h++)
	{
		cout << nameInput[h] << endl;
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << " " << seaArray[h][i][j] << " ";
				if (seaArray[h][i][j] == 2)
				{
					winnerCheck++;
				}

			}
			cout << endl;
		}
		cout << endl << endl;
		if (winnerCheck == 3)
		{
			winnerCheck = 0;
		}
		else if (winnerCheck < 3)
		{
			cout << "Winner is :" << nameInput[h] << endl << endl;
		}
	}
	return 0;
}



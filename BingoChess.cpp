#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 
string asterisk(76, '*');
char mainMenu;
char goToMainMenu;
char gameMode;
string playerSymbol = "X";
string playerInput;
int NumberOfTurn;
int NumberOfPlayerOneTurn;
int NumberOfPlayerTwoTurn;
string matrix[6][7] = {
	{"36", "37", "38", "39", "40", "41", "42"},
	{"29", "30", "31", "32", "33", "34", "35"},
	{"22", "23", "24", "25", "26", "27", "28"},
	{"15", "16", "17", "18", "19", "20", "21"},
	{"8", "9", "10", "11", "12", "13", "14"},
	{"1", "2", "3", "4", "5", "6", "7"},
};

// Display header information
void HeaderPrompt()
{
	SetConsoleTextAttribute(h, 10); // set text-color to green
	cout << "\n\t\t      B - I - N - G - O     C - H - E - S - S " << endl;
	SetConsoleTextAttribute(h, 14); // set text-color to yellow
	cout << "\n\t\t\t\t   CONSOLE GAME\n\n";
	SetConsoleTextAttribute(h, 10); // set text-color to green
	cout << "  " << asterisk << endl;
}

// Display Main Menu
void MainPrompt()
{
	SetConsoleTextAttribute(h, 14); // set text-color to yellow
	cout << "\n\n\n\t\t\t\t    MAIN MENU\n";
	cout << "\n\t\t\t  A. Read Tutorial \n";
	cout << "\n\t\t\t  B. Play the game (Skip Tutorial)\n\n";
}

// Check user input from main menu 
void CheckMenu()
{
	cout << endl;
	do
	{
		SetConsoleTextAttribute(h, 14);
		cout << "\n\tPress specified key: ";
		cin >> mainMenu;
		mainMenu = toupper(mainMenu);
		if (mainMenu != 'A' && mainMenu != 'B')
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n\t[ Invalid input ! ]\n";
		}
	} while (mainMenu != 'A' && mainMenu != 'B');
}

// Edit main menu after reading tutorial
void PlayGamePrompt()
{
	SetConsoleTextAttribute(h, 14); // set text-color to yellow
	cout << "\n\n\n\t\t\t\t    MAIN MENU\n";
	cout << "\n\t\t\t  A. (TUTORIAL COMPLETED)\n";
	cout << "\n\t\t\t  B. Play the game\n\n";
}

// Check input and displays prompt message after completing the tutorial
void PlayGameMenu()
{
	cout << endl;
	do
	{
		SetConsoleTextAttribute(h, 14);
		cout << "\n\tPress specified key: ";
		cin >> mainMenu;
		mainMenu = toupper(mainMenu);
		if (mainMenu != 'A' && mainMenu != 'B')
		{
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t[ Invalid input ! ]\n";
		}

		if (mainMenu == 'A')
		{
			SetConsoleTextAttribute(h, 10); // set text-color to green
			cout << "\n\t[ You are already done reading the tutorial ! ]\n";
			cout << "\n\t[ You can now play the game :) ]\n";
			cout << "\n\t[ Press B to play the Game ]\n";
		}
		continue;
	} while (mainMenu != 'B');
}

// Display content of Tutorial Section
void GoToTutorial()
{
	if (mainMenu == 'A')
	{
		system("cls");
		HeaderPrompt();
		SetConsoleTextAttribute(h, 14); // set text-color to yellow
		cout << "\n\t\t\t\t     Tutorial\n";
		cout << "\n\n\n\t\t\t\t [ In progress ]";
		cout << "\n\n\n\n";
		do
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n\tPress M to go main menu: ";
			cin >> goToMainMenu;
			goToMainMenu = toupper(goToMainMenu);
			if (goToMainMenu != 'M')
			{
				SetConsoleTextAttribute(h, 12); // set text-color to reading
				cout << "\n\t[ Invalid input ! ]\n";
			}

		} while (goToMainMenu != 'M');
	}
}

// Display content of Game Mode section
void GoToGameMode()
{
	if (mainMenu == 'B')
	{
		system("cls");
		HeaderPrompt();
		SetConsoleTextAttribute(h, 14); // set text-color to yellow
		cout << "\n\t\t\t\t   GAME MODE\n";
		cout << "\n\n\t\t\t  A. Multiplayer (2 players)\n";
		cout << "\n\t\t\t  B. Versus AI\n";
		cout << "\n\n\n";
		do
		{
			SetConsoleTextAttribute(h, 14);
			cout << "\n\tChoose game mode: ";
			cin >> gameMode;
			gameMode = toupper(gameMode);
			if (gameMode != 'A' && gameMode != 'B')
			{
				SetConsoleTextAttribute(h, 12);
				cout << "\n\t[ Invalid input ! ]\n";
			}
		} while (gameMode != 'A' && gameMode != 'B');
	}
}

// Display matrix
void MultiplayerDrawMatrix()
{
	cout << "\n\n";
	SetConsoleTextAttribute(h, 14); // set text-color to yellow
	cout << "\t\t\t      Player 1 ";
	SetConsoleTextAttribute(h, 10); // set text-color to green
	cout << "VS. ";
	SetConsoleTextAttribute(h, 12); // set text - color red
	cout << "Player 2\n\n\n";
	SetConsoleTextAttribute(h, 10); // set text-color to green
	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 7; column++)
		{
			cout << "\t     " << matrix[row][column];
		}
		cout << "\n\n";
	}
}

// Display input prompt for both players
void InputPrompt()
{
	do
	{
		if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  Player 1 Turn [ X ] : " << NumberOfPlayerOneTurn;
			cout << "\n\n  Press the number of the field you want to place your move: ";
			cin >> playerInput;
			if (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7" && playerInput != "8" && playerInput != "9" && playerInput != "10" && playerInput != "11" && playerInput != "12" && playerInput != "13" && playerInput != "14" && playerInput != "15" && playerInput != "16" && playerInput != "17" && playerInput != "18" && playerInput != "19" && playerInput != "20" && playerInput != "21" && playerInput != "22" && playerInput != "23" && playerInput != "24" && playerInput != "25" && playerInput != "26" && playerInput != "27" && playerInput != "28" && playerInput != "29" && playerInput != "30" && playerInput != "31" && playerInput != "32" && playerInput != "33" && playerInput != "34" && playerInput != "35" && playerInput != "36" && playerInput != "37" && playerInput != "38" && playerInput != "39" && playerInput != "40" && playerInput != "41" && playerInput != "42")
			{
				SetConsoleTextAttribute(h, 10); // set text-color to green
				cout << "\n  [ Invalid Input ] " << endl;
			}
		}
		else if (playerSymbol == "O")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  Player 2 Turn [ O ] : " << NumberOfPlayerTwoTurn;
			cout << "\n\n  Press the number of the field you want to place your move: ";
			cin >> playerInput;
			if (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7" && playerInput != "8" && playerInput != "9" && playerInput != "10" && playerInput != "11" && playerInput != "12" && playerInput != "13" && playerInput != "14" && playerInput != "15" && playerInput != "16" && playerInput != "17" && playerInput != "18" && playerInput != "19" && playerInput != "20" && playerInput != "21" && playerInput != "22" && playerInput != "23" && playerInput != "24" && playerInput != "25" && playerInput != "26" && playerInput != "27" && playerInput != "28" && playerInput != "29" && playerInput != "30" && playerInput != "31" && playerInput != "32" && playerInput != "33" && playerInput != "34" && playerInput != "35" && playerInput != "36" && playerInput != "37" && playerInput != "38" && playerInput != "39" && playerInput != "40" && playerInput != "41" && playerInput != "42")
			{
				SetConsoleTextAttribute(h, 10); // set text-color to green
				cout << "\n  [ Invalid Input ] " << endl;
			}
		}
	} while (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7" && playerInput != "8" && playerInput != "9" && playerInput != "10" && playerInput != "11" && playerInput != "12" && playerInput != "13" && playerInput != "14" && playerInput != "15" && playerInput != "16" && playerInput != "17" && playerInput != "18" && playerInput != "19" && playerInput != "20" && playerInput != "21" && playerInput != "22" && playerInput != "23" && playerInput != "24" && playerInput != "25" && playerInput != "26" && playerInput != "27" && playerInput != "28" && playerInput != "29" && playerInput != "30" && playerInput != "31" && playerInput != "32" && playerInput != "33" && playerInput != "34" && playerInput != "35" && playerInput != "36" && playerInput != "37" && playerInput != "38" && playerInput != "39" && playerInput != "40" && playerInput != "41" && playerInput != "42");

// Change the content of 2D arrays based on input of user
	if (playerInput == "1")
	{
		if (matrix[5][0] == "1")
		{
			matrix[5][0] = playerSymbol;
		}
		else if (playerSymbol == "X") // Check if user input is already used
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "2")
	{
		if (matrix[5][1] == "2")
		{
			matrix[5][1] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "3")
	{
		if (matrix[5][2] == "3")
		{
			matrix[5][2] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "4")
	{
		if (matrix[5][3] == "4")
		{
			matrix[5][3] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "5")
	{
		if (matrix[5][4] == "5")
		{
			matrix[5][4] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "6")
	{
		if (matrix[5][5] == "6")
		{
			matrix[5][5] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "7")
	{
		if (matrix[5][6] == "7")
		{
			matrix[5][6] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "8")
	{
		if (matrix[4][0] == "8")
		{
			matrix[4][0] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "9")
	{
		if (matrix[4][1] == "9")
		{
			matrix[4][1] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "10")
	{
		if (matrix[4][2] == "10")
		{
			matrix[4][2] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "11")
	{
		if (matrix[4][3] == "11")
		{
			matrix[4][3] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "12")
	{
		if (matrix[4][4] == "12")
		{
			matrix[4][4] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "13")
	{
		if (matrix[4][5] == "13")
		{
			matrix[4][5] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "14")
	{
		if (matrix[4][6] == "14")
		{
			matrix[4][6] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "15")
	{
		if (matrix[3][0] == "15")
		{
			matrix[3][0] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "16")
	{
		if (matrix[3][1] == "16")
		{
			matrix[3][1] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "17")
	{
		if (matrix[3][2] == "17")
		{
			matrix[3][2] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "18")
	{
		if (matrix[3][3] == "18")
		{
			matrix[3][3] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "19")
	{
		if (matrix[3][4] == "19")
		{
			matrix[3][4] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "20")
	{
		if (matrix[3][5] == "20")
		{
			matrix[3][5] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "21")
	{
		if (matrix[3][6] == "21")
		{
			matrix[3][6] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "22")
	{
		if (matrix[2][0] == "22")
		{
			matrix[2][0] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "23")
	{
		if (matrix[2][1] == "23")
		{
			matrix[2][1] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "24")
	{
		if (matrix[2][2] == "24")
		{
			matrix[2][2] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "25")
	{
		if (matrix[2][3] == "25")
		{
			matrix[2][3] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "26")
	{
		if (matrix[2][4] == "26")
		{
			matrix[2][4] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "27")
	{
		if (matrix[2][5] == "27")
		{
			matrix[2][5] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "28")
	{
		if (matrix[2][6] == "28")
		{
			matrix[2][6] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "29")
	{
		if (matrix[1][0] == "29")
		{
			matrix[1][0] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "30")
	{
		if (matrix[1][1] == "30")
		{
			matrix[1][1] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "31")
	{
		if (matrix[1][2] == "31")
		{
			matrix[1][2] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "32")
	{
		if (matrix[1][3] == "32")
		{
			matrix[1][3] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "33")
	{
		if (matrix[1][4] == "33")
		{
			matrix[1][4] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "34")
	{
		if (matrix[1][5] == "34")
		{
			matrix[1][5] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "35")
	{
		if (matrix[1][6] == "35")
		{
			matrix[1][6] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "36")
	{
		if (matrix[0][0] == "36")
		{
			matrix[0][0] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "37")
	{
		if (matrix[0][1] == "37")
		{
			matrix[0][1] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "38")
	{
		if (matrix[0][2] == "38")
		{
			matrix[0][2] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "39")
	{
		if (matrix[0][3] == "39")
		{
			matrix[0][3] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "40")
	{
		if (matrix[0][4] == "40")
		{
			matrix[0][4] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "41")
	{
		if (matrix[0][5] == "41")
		{
			matrix[0][5] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
	else if (playerInput == "42")
	{
		if (matrix[0][6] == "42")
		{
			matrix[0][6] = playerSymbol;
		}
		else if (playerSymbol == "X")
		{
			SetConsoleTextAttribute(h, 12); // set text - color red
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
		else
		{
			SetConsoleTextAttribute(h, 14); // set text-color to yellow
			cout << "\n  [ Field is already in use ! ]" << endl;
			InputPrompt();
		}
	}
}

// Change Player Symbol
void ChangePlayerTurn()
{
	if (playerSymbol == "X")
	{
		playerSymbol = "O";
	}
	else
		playerSymbol = "X";
}

// Check winner per player
char CheckWinner()
{
	// Horizontal [ Player 1 ]
	// Row 1
	if (matrix[5][0] == "X" && matrix[5][1] == "X" && matrix[5][2] == "X" && matrix[5][3] == "X")
		return 'X';
	if (matrix[5][1] == "X" && matrix[5][2] == "X" && matrix[5][3] == "X" && matrix[5][4] == "X")
		return 'X';
	if (matrix[5][2] == "X" && matrix[5][3] == "X" && matrix[5][4] == "X" && matrix[5][5] == "X")
		return 'X';
	if (matrix[5][3] == "X" && matrix[5][4] == "X" && matrix[5][5] == "X" && matrix[5][6] == "X")
		return 'X';
	// Row 2
	if (matrix[4][0] == "X" && matrix[4][1] == "X" && matrix[4][2] == "X" && matrix[4][3] == "X")
		return 'X';
	if (matrix[4][1] == "X" && matrix[4][2] == "X" && matrix[4][3] == "X" && matrix[4][4] == "X")
		return 'X';
	if (matrix[4][2] == "X" && matrix[4][3] == "X" && matrix[4][4] == "X" && matrix[4][5] == "X")
		return 'X';
	if (matrix[4][3] == "X" && matrix[4][4] == "X" && matrix[4][5] == "X" && matrix[4][6] == "X")
		return 'X';
	// Row 3
	if (matrix[3][0] == "X" && matrix[3][1] == "X" && matrix[3][2] == "X" && matrix[3][3] == "X")
		return 'X';
	if (matrix[3][1] == "X" && matrix[3][2] == "X" && matrix[3][3] == "X" && matrix[3][4] == "X")
		return 'X';
	if (matrix[3][2] == "X" && matrix[3][3] == "X" && matrix[3][4] == "X" && matrix[3][5] == "X")
		return 'X';
	if (matrix[3][3] == "X" && matrix[3][4] == "X" && matrix[3][5] == "X" && matrix[3][6] == "X")
		return 'X';
	// Row 4
	if (matrix[2][0] == "X" && matrix[2][1] == "X" && matrix[2][2] == "X" && matrix[2][3] == "X")
		return 'X';
	if (matrix[2][1] == "X" && matrix[2][2] == "X" && matrix[2][3] == "X" && matrix[2][4] == "X")
		return 'X';
	if (matrix[2][2] == "X" && matrix[2][3] == "X" && matrix[2][4] == "X" && matrix[2][5] == "X")
		return 'X';
	if (matrix[2][3] == "X" && matrix[2][4] == "X" && matrix[2][5] == "X" && matrix[2][6] == "X")
		return 'X';
	// Row 5
	if (matrix[1][0] == "X" && matrix[1][1] == "X" && matrix[1][2] == "X" && matrix[1][3] == "X")
		return 'X';
	if (matrix[1][1] == "X" && matrix[1][2] == "X" && matrix[1][3] == "X" && matrix[1][4] == "X")
		return 'X';
	if (matrix[1][2] == "X" && matrix[1][3] == "X" && matrix[1][4] == "X" && matrix[1][5] == "X")
		return 'X';
	if (matrix[1][3] == "X" && matrix[1][4] == "X" && matrix[1][5] == "X" && matrix[1][6] == "X")
		return 'X';
	// Row 6
	if (matrix[0][0] == "X" && matrix[0][1] == "X" && matrix[0][2] == "X" && matrix[0][3] == "X")
		return 'X';
	if (matrix[0][1] == "X" && matrix[0][2] == "X" && matrix[0][3] == "X" && matrix[0][4] == "X")
		return 'X';
	if (matrix[0][2] == "X" && matrix[0][3] == "X" && matrix[0][4] == "X" && matrix[0][5] == "X")
		return 'X';
	if (matrix[0][3] == "X" && matrix[0][4] == "X" && matrix[0][5] == "X" && matrix[0][6] == "X")
		return 'X';

	// Vertical [ Player 1 ]
	// Column 1
	if (matrix[5][0] == "X" && matrix[4][0] == "X" && matrix[3][0] == "X" && matrix[2][0] == "X")
		return 'X';
	if (matrix[4][0] == "X" && matrix[3][0] == "X" && matrix[2][0] == "X" && matrix[1][0] == "X")
		return 'X';
	if (matrix[3][0] == "X" && matrix[2][0] == "X" && matrix[1][0] == "X" && matrix[0][0] == "X")
		return 'X';
	// Column 2
	if (matrix[5][1] == "X" && matrix[4][1] == "X" && matrix[3][1] == "X" && matrix[2][1] == "X")
		return 'X';
	if (matrix[4][1] == "X" && matrix[3][1] == "X" && matrix[2][1] == "X" && matrix[1][1] == "X")
		return 'X';
	if (matrix[3][1] == "X" && matrix[2][1] == "X" && matrix[1][1] == "X" && matrix[0][1] == "X")
		return 'X';
	// Column 3
	if (matrix[5][2] == "X" && matrix[4][2] == "X" && matrix[3][2] == "X" && matrix[2][2] == "X")
		return 'X';
	if (matrix[4][2] == "X" && matrix[3][2] == "X" && matrix[2][2] == "X" && matrix[1][2] == "X")
		return 'X';
	if (matrix[3][2] == "X" && matrix[2][2] == "X" && matrix[1][2] == "X" && matrix[0][2] == "X")
		return 'X';
	// Column 4
	if (matrix[5][3] == "X" && matrix[4][3] == "X" && matrix[3][3] == "X" && matrix[2][3] == "X")
		return 'X';
	if (matrix[4][3] == "X" && matrix[3][3] == "X" && matrix[2][3] == "X" && matrix[1][3] == "X")
		return 'X';
	if (matrix[3][3] == "X" && matrix[2][3] == "X" && matrix[1][3] == "X" && matrix[0][3] == "X")
		return 'X';
	// Column 5
	if (matrix[5][4] == "X" && matrix[4][4] == "X" && matrix[3][4] == "X" && matrix[2][4] == "X")
		return 'X';
	if (matrix[4][4] == "X" && matrix[3][4] == "X" && matrix[2][4] == "X" && matrix[1][4] == "X")
		return 'X';
	if (matrix[3][4] == "X" && matrix[2][4] == "X" && matrix[1][4] == "X" && matrix[0][4] == "X")
		return 'X';
	// Column 6
	if (matrix[5][5] == "X" && matrix[4][5] == "X" && matrix[3][5] == "X" && matrix[2][5] == "X")
		return 'X';
	if (matrix[4][5] == "X" && matrix[3][5] == "X" && matrix[2][5] == "X" && matrix[1][5] == "X")
		return 'X';
	if (matrix[3][5] == "X" && matrix[2][5] == "X" && matrix[1][5] == "X" && matrix[0][5] == "X")
		return 'X';
	// Column 7
	if (matrix[5][6] == "X" && matrix[4][6] == "X" && matrix[3][6] == "X" && matrix[2][6] == "X")
		return 'X';
	if (matrix[4][6] == "X" && matrix[3][6] == "X" && matrix[2][6] == "X" && matrix[1][6] == "X")
		return 'X';
	if (matrix[3][6] == "X" && matrix[2][6] == "X" && matrix[1][6] == "X" && matrix[0][6] == "X")
		return 'X';

	// Diagonal [ Player 1 ] Starting from left side
	// Case 1
	if (matrix[3][0] == "X" && matrix[2][1] == "X" && matrix[1][2] == "X" && matrix[0][3] == "X")
		return 'X';
	// Case 2
	if (matrix[4][0] == "X" && matrix[3][1] == "X" && matrix[2][2] == "X" && matrix[1][3] == "X")
		return 'X';
	if (matrix[3][1] == "X" && matrix[2][2] == "X" && matrix[1][3] == "X" && matrix[0][4] == "X")
		return 'X';
	// 	Case 3
	if (matrix[5][0] == "X" && matrix[4][1] == "X" && matrix[3][2] == "X" && matrix[2][3] == "X")
		return 'X';
	if (matrix[4][1] == "X" && matrix[3][2] == "X" && matrix[2][3] == "X" && matrix[1][4] == "X")
		return 'X';
	if (matrix[3][2] == "X" && matrix[2][3] == "X" && matrix[1][4] == "X" && matrix[0][5] == "X")
		return 'X';
	// Case 4
	if (matrix[5][1] == "X" && matrix[4][2] == "X" && matrix[3][3] == "X" && matrix[2][4] == "X")
		return 'X';
	if (matrix[4][2] == "X" && matrix[3][3] == "X" && matrix[2][4] == "X" && matrix[1][5] == "X")
		return 'X';
	if (matrix[3][3] == "X" && matrix[2][4] == "X" && matrix[1][5] == "X" && matrix[0][6] == "X")
		return 'X';
	// Case 5
	if (matrix[5][2] == "X" && matrix[4][3] == "X" && matrix[3][4] == "X" && matrix[2][5] == "X")
		return 'X';
	if (matrix[4][3] == "X" && matrix[3][4] == "X" && matrix[2][5] == "X" && matrix[1][6] == "X")
		return 'X';
	// Case 6
	if (matrix[5][3] == "X" && matrix[4][4] == "X" && matrix[3][5] == "X" && matrix[2][6] == "X")
		return 'X';

	// Diagonal [ Player 1 ] Starting from right side
	if (matrix[3][6] == "X" && matrix[2][5] == "X" && matrix[1][4] == "X" && matrix[0][3] == "X")
		return 'X';
	// Case 2
	if (matrix[4][6] == "X" && matrix[3][5] == "X" && matrix[2][4] == "X" && matrix[1][3] == "X")
		return 'X';
	if (matrix[3][5] == "X" && matrix[2][4] == "X" && matrix[1][3] == "X" && matrix[0][2] == "X")
		return 'X';
	// 	Case 3
	if (matrix[5][6] == "X" && matrix[4][5] == "X" && matrix[3][4] == "X" && matrix[2][3] == "X")
		return 'X';
	if (matrix[4][5] == "X" && matrix[3][4] == "X" && matrix[2][3] == "X" && matrix[1][2] == "X")
		return 'X';
	if (matrix[3][4] == "X" && matrix[2][3] == "X" && matrix[1][2] == "X" && matrix[0][1] == "X")
		return 'X';
	// Case 4
	if (matrix[5][5] == "X" && matrix[4][4] == "X" && matrix[3][3] == "X" && matrix[2][2] == "X")
		return 'X';
	if (matrix[4][4] == "X" && matrix[3][3] == "X" && matrix[2][2] == "X" && matrix[1][1] == "X")
		return 'X';
	if (matrix[3][3] == "X" && matrix[2][2] == "X" && matrix[1][1] == "X" && matrix[0][0] == "X")
		return 'X';
	// Case 5
	if (matrix[5][4] == "X" && matrix[4][3] == "X" && matrix[3][2] == "X" && matrix[2][1] == "X")
		return 'X';
	if (matrix[4][3] == "X" && matrix[3][2] == "X" && matrix[2][1] == "X" && matrix[1][0] == "X")
		return 'X';
	// Case 6
	if (matrix[5][3] == "X" && matrix[4][2] == "X" && matrix[3][1] == "X" && matrix[2][0] == "X")
		return 'X';

	// Horizontal [ Player 2 ]
	// Row 1
	if (matrix[5][0] == "O" && matrix[5][1] == "O" && matrix[5][2] == "O" && matrix[5][3] == "O")
		return 'O';
	if (matrix[5][1] == "O" && matrix[5][2] == "O" && matrix[5][3] == "O" && matrix[5][4] == "O")
		return 'O';
	if (matrix[5][2] == "O" && matrix[5][3] == "O" && matrix[5][4] == "O" && matrix[5][5] == "O")
		return 'O';
	if (matrix[5][3] == "O" && matrix[5][4] == "O" && matrix[5][5] == "O" && matrix[5][6] == "O")
		return 'O';
	// Row 2
	if (matrix[4][0] == "O" && matrix[4][1] == "O" && matrix[4][2] == "O" && matrix[4][3] == "O")
		return 'O';
	if (matrix[4][1] == "O" && matrix[4][2] == "O" && matrix[4][3] == "O" && matrix[4][4] == "O")
		return 'O';
	if (matrix[4][2] == "O" && matrix[4][3] == "O" && matrix[4][4] == "O" && matrix[4][5] == "O")
		return 'O';
	if (matrix[4][3] == "O" && matrix[4][4] == "O" && matrix[4][5] == "O" && matrix[4][6] == "O")
		return 'O';
	// Row 3
	if (matrix[3][0] == "O" && matrix[3][1] == "O" && matrix[3][2] == "O" && matrix[3][3] == "O")
		return 'O';
	if (matrix[3][1] == "O" && matrix[3][2] == "O" && matrix[3][3] == "O" && matrix[3][4] == "O")
		return 'O';
	if (matrix[3][2] == "O" && matrix[3][3] == "O" && matrix[3][4] == "O" && matrix[3][5] == "O")
		return 'O';
	if (matrix[3][3] == "O" && matrix[3][4] == "O" && matrix[3][5] == "O" && matrix[3][6] == "O")
		return 'O';
	// Row 4
	if (matrix[2][0] == "O" && matrix[2][1] == "O" && matrix[2][2] == "O" && matrix[2][3] == "O")
		return 'O';
	if (matrix[2][1] == "O" && matrix[2][2] == "O" && matrix[2][3] == "O" && matrix[2][4] == "O")
		return 'O';
	if (matrix[2][2] == "O" && matrix[2][3] == "O" && matrix[2][4] == "O" && matrix[2][5] == "O")
		return 'O';
	if (matrix[2][3] == "O" && matrix[2][4] == "O" && matrix[2][5] == "O" && matrix[2][6] == "O")
		return 'O';
	// Row 5
	if (matrix[1][0] == "O" && matrix[1][1] == "O" && matrix[1][2] == "O" && matrix[1][3] == "O")
		return 'O';
	if (matrix[1][1] == "O" && matrix[1][2] == "O" && matrix[1][3] == "O" && matrix[1][4] == "O")
		return 'O';
	if (matrix[1][2] == "O" && matrix[1][3] == "O" && matrix[1][4] == "O" && matrix[1][5] == "O")
		return 'O';
	if (matrix[1][3] == "O" && matrix[1][4] == "O" && matrix[1][5] == "O" && matrix[1][6] == "O")
		return 'O';
	// Row 6
	if (matrix[0][0] == "O" && matrix[0][1] == "O" && matrix[0][2] == "O" && matrix[0][3] == "O")
		return 'O';
	if (matrix[0][1] == "O" && matrix[0][2] == "O" && matrix[0][3] == "O" && matrix[0][4] == "O")
		return 'O';
	if (matrix[0][2] == "O" && matrix[0][3] == "O" && matrix[0][4] == "O" && matrix[0][5] == "O")
		return 'O';
	if (matrix[0][3] == "O" && matrix[0][4] == "O" && matrix[0][5] == "O" && matrix[0][6] == "O")
		return 'O';

	// Vertical [ Player 2 ]
	// Column 1
	if (matrix[5][0] == "O" && matrix[4][0] == "O" && matrix[3][0] == "O" && matrix[2][0] == "O")
		return 'O';
	if (matrix[4][0] == "O" && matrix[3][0] == "O" && matrix[2][0] == "O" && matrix[1][0] == "O")
		return 'O';
	if (matrix[3][0] == "O" && matrix[2][0] == "O" && matrix[1][0] == "O" && matrix[0][0] == "O")
		return 'O';
	// Column 2
	if (matrix[5][1] == "O" && matrix[4][1] == "O" && matrix[3][1] == "O" && matrix[2][1] == "O")
		return 'O';
	if (matrix[4][1] == "O" && matrix[3][1] == "O" && matrix[2][1] == "O" && matrix[1][1] == "O")
		return 'O';
	if (matrix[3][1] == "O" && matrix[2][1] == "O" && matrix[1][1] == "O" && matrix[0][1] == "O")
		return 'O';
	// Column 3
	if (matrix[5][2] == "O" && matrix[4][2] == "O" && matrix[3][2] == "O" && matrix[2][2] == "O")
		return 'O';
	if (matrix[4][2] == "O" && matrix[3][2] == "O" && matrix[2][2] == "O" && matrix[1][2] == "O")
		return 'O';
	if (matrix[3][2] == "O" && matrix[2][2] == "O" && matrix[1][2] == "O" && matrix[0][2] == "O")
		return 'O';
	// Column 4
	if (matrix[5][3] == "O" && matrix[4][3] == "O" && matrix[3][3] == "O" && matrix[2][3] == "O")
		return 'O';
	if (matrix[4][3] == "O" && matrix[3][3] == "O" && matrix[2][3] == "O" && matrix[1][3] == "O")
		return 'O';
	if (matrix[3][3] == "O" && matrix[2][3] == "O" && matrix[1][3] == "O" && matrix[0][3] == "O")
		return 'O';
	// Column 5
	if (matrix[5][4] == "O" && matrix[4][4] == "O" && matrix[3][4] == "O" && matrix[2][4] == "O")
		return 'O';
	if (matrix[4][4] == "O" && matrix[3][4] == "O" && matrix[2][4] == "O" && matrix[1][4] == "O")
		return 'O';
	if (matrix[3][4] == "O" && matrix[2][4] == "O" && matrix[1][4] == "O" && matrix[0][4] == "O")
		return 'O';
	// Column 6
	if (matrix[5][5] == "O" && matrix[4][5] == "O" && matrix[3][5] == "O" && matrix[2][5] == "O")
		return 'O';
	if (matrix[4][5] == "O" && matrix[3][5] == "O" && matrix[2][5] == "O" && matrix[1][5] == "O")
		return 'O';
	if (matrix[3][5] == "O" && matrix[2][5] == "O" && matrix[1][5] == "O" && matrix[0][5] == "O")
		return 'O';
	// Column 7
	if (matrix[5][6] == "O" && matrix[4][6] == "O" && matrix[3][6] == "O" && matrix[2][6] == "O")
		return 'O';
	if (matrix[4][6] == "O" && matrix[3][6] == "O" && matrix[2][6] == "O" && matrix[1][6] == "O")
		return 'O';
	if (matrix[3][6] == "O" && matrix[2][6] == "O" && matrix[1][6] == "O" && matrix[0][6] == "O")
		return 'O';

	// Diagonal [ Player 2 ] Starting from left side
	// Case 1
	if (matrix[3][0] == "O" && matrix[2][1] == "O" && matrix[1][2] == "O" && matrix[0][3] == "O")
		return 'O';
	// Case 2
	if (matrix[4][0] == "O" && matrix[3][1] == "O" && matrix[2][2] == "O" && matrix[1][3] == "O")
		return 'O';
	if (matrix[3][1] == "O" && matrix[2][2] == "O" && matrix[1][3] == "O" && matrix[0][4] == "O")
		return 'O';
	// 	Case 3
	if (matrix[5][0] == "O" && matrix[4][1] == "O" && matrix[3][2] == "O" && matrix[2][3] == "O")
		return 'O';
	if (matrix[4][1] == "O" && matrix[3][2] == "O" && matrix[2][3] == "O" && matrix[1][4] == "O")
		return 'O';
	if (matrix[3][2] == "O" && matrix[2][3] == "O" && matrix[1][4] == "O" && matrix[0][5] == "O")
		return 'O';
	// Case 4
	if (matrix[5][1] == "O" && matrix[4][2] == "O" && matrix[3][3] == "O" && matrix[2][4] == "O")
		return 'O';
	if (matrix[4][2] == "O" && matrix[3][3] == "O" && matrix[2][4] == "O" && matrix[1][5] == "O")
		return 'O';
	if (matrix[3][3] == "O" && matrix[2][4] == "O" && matrix[1][5] == "O" && matrix[0][6] == "O")
		return 'O';
	// Case 5
	if (matrix[5][2] == "O" && matrix[4][3] == "O" && matrix[3][4] == "O" && matrix[2][5] == "O")
		return 'O';
	if (matrix[4][3] == "O" && matrix[3][4] == "O" && matrix[2][5] == "O" && matrix[1][6] == "O")
		return 'O';
	// Case 6
	if (matrix[5][3] == "O" && matrix[4][4] == "O" && matrix[3][5] == "O" && matrix[2][6] == "O")
		return 'O';

	// Diagonal [ Player 2 ] Starting from right side
	if (matrix[3][6] == "O" && matrix[2][5] == "O" && matrix[1][4] == "O" && matrix[0][3] == "O")
		return 'O';
	// Case 2
	if (matrix[4][6] == "O" && matrix[3][5] == "O" && matrix[2][4] == "O" && matrix[1][3] == "O")
		return 'O';
	if (matrix[3][5] == "O" && matrix[2][4] == "O" && matrix[1][3] == "O" && matrix[0][2] == "O")
		return 'O';
	// 	Case 3
	if (matrix[5][6] == "O" && matrix[4][5] == "O" && matrix[3][4] == "O" && matrix[2][3] == "O")
		return 'O';
	if (matrix[4][5] == "O" && matrix[3][4] == "O" && matrix[2][3] == "O" && matrix[1][2] == "O")
		return 'O';
	if (matrix[3][4] == "O" && matrix[2][3] == "O" && matrix[1][2] == "O" && matrix[0][1] == "O")
		return 'O';
	// Case 4
	if (matrix[5][5] == "O" && matrix[4][4] == "O" && matrix[3][3] == "O" && matrix[2][2] == "O")
		return 'O';
	if (matrix[4][4] == "O" && matrix[3][3] == "O" && matrix[2][2] == "O" && matrix[1][1] == "O")
		return 'O';
	if (matrix[3][3] == "O" && matrix[2][2] == "O" && matrix[1][1] == "O" && matrix[0][0] == "O")
		return 'O';
	// Case 5
	if (matrix[5][4] == "O" && matrix[4][3] == "O" && matrix[3][2] == "O" && matrix[2][1] == "O")
		return 'O';
	if (matrix[4][3] == "O" && matrix[3][2] == "O" && matrix[2][1] == "O" && matrix[1][0] == "O")
		return 'O';
	// Case 6
	if (matrix[5][3] == "O" && matrix[4][2] == "O" && matrix[3][1] == "O" && matrix[2][0] == "O")
		return 'O';
	return '/';
}

int main()
{
	NumberOfTurn = 43;
	NumberOfPlayerOneTurn = 22;
	NumberOfPlayerTwoTurn = 22;
	HeaderPrompt();
	MainPrompt();
	CheckMenu();
	GoToTutorial();
	GoToGameMode();

	if (goToMainMenu == 'M')
	{
		system("cls");
		HeaderPrompt();
		PlayGamePrompt();
		PlayGameMenu();
		GoToGameMode();
	}

	switch (gameMode)
	{
	case 'A':
		system("cls");
		HeaderPrompt();
		MultiplayerDrawMatrix();
		while (true)
		{
			NumberOfTurn--;
			cout << "\n\t\t\t   Number of Turns Left: " << NumberOfTurn << "\n\n";
			if (playerSymbol == "X")
			{
				NumberOfPlayerOneTurn--;
			}
			else if (playerSymbol == "O")
			{
				NumberOfPlayerTwoTurn--;
			}
			InputPrompt();
			system("cls"); // updating screen for input
			HeaderPrompt();
			MultiplayerDrawMatrix();
			if (CheckWinner() == 'X')
			{
				SetConsoleTextAttribute(h, 14); // set text-color to yellow
				cout << "\n\t\t\t      [ Player 1 Wins ! ]\n";
				break;
			}
			else if (CheckWinner() == 'O')
			{
				SetConsoleTextAttribute(h, 12); // set text - color red
				cout << "\n\t\t\t      [ Player 2 Wins ! ]\n";
				break;
			}
			else if (CheckWinner() == '/' && NumberOfTurn == 1)
			{
				SetConsoleTextAttribute(h, 10); // set text-color to green
				cout << "\n\t\t\t      [ It's a Draw ! ]\n";
				break;
			}
			ChangePlayerTurn();
		}

		SetConsoleTextAttribute(h, 14); // set text-color to yellow
		break;
	case 'B':
		cout << "Your Turn: ";
		cout << "AI Turn: ";
	}
	system("pause");
	return 0;
}

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <ctime>
#include <unistd.h>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
string asterisk(76, '*');
string mainMenu;
string goToMainMenu;
string gameMode;
string playerSymbol = "X";
string playerInput;
int NumberOfTurn;
int NumberOfPlayerOneTurn;
int NumberOfPlayerTwoTurn;
string matrix[6][7] = {
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " "},
};
string columnIndicator[7] = {"1", "2", "3", "4", "5", "6", "7"};
string playAgain;
string Difficulty;
string mainMenu_quitGame;
int computerChoice;
// Display header information
void HeaderPrompt()
{
    SetConsoleTextAttribute(h, 10); // set text-color to green
    cout << "\n\t\t B - I - N - G - O     C - H - E - S - S [ver.2.0] " << endl;
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
        cout << "\n\tPress [A] or [B]: ";
        cin >> mainMenu;
        if (mainMenu != "A" && mainMenu != "a" && mainMenu != "B" && mainMenu != "b")
        {
            SetConsoleTextAttribute(h, 12); // set text - color red
            cout << "\n\t[ Invalid input ! ]\n";
        }
    } while (mainMenu != "A" && mainMenu != "a" && mainMenu != "B" && mainMenu != "b");
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
        cout << "\n\tPress [A] or [B]: ";
        cin >> mainMenu;
        if (mainMenu != "A" && mainMenu != "a" && mainMenu != "B" && mainMenu != "b")
        {
            SetConsoleTextAttribute(h, 12);
            cout << "\n\t[ Invalid input ! ]\n";
        }

        if (mainMenu == "A" || mainMenu == "a")
        {
            SetConsoleTextAttribute(h, 10); // set text-color to green
            cout << "\n\t[ You are already done reading the tutorial ! ]\n";
            cout << "\n\t[ You can now play the game :) ]\n";
            cout << "\n\t[ Press B to play the Game ]\n";
        }
        continue;
    } while (mainMenu != "B" && mainMenu != "b");
}

// Display content of Tutorial Section
void GoToTutorial()
{
    if (mainMenu == "A" || mainMenu == "a")
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
            cout << "\n\tPress [M] to go main menu: ";
            cin >> goToMainMenu;
            if (goToMainMenu != "M" && goToMainMenu != "m")
            {
                SetConsoleTextAttribute(h, 12); // set text-color to reading
                cout << "\n\t[ Invalid input ! ]\n";
            }

        } while (goToMainMenu != "M" && goToMainMenu != "m");
    }
}

// Display content of Game Mode section
void GoToGameMode()
{
    if (mainMenu == "B" || mainMenu == "b")
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
            cout << "\n\tPress [A] or [B]: ";
            cin >> gameMode;
            if (gameMode != "A" && gameMode != "a" && gameMode != "B" && gameMode != "b")
            {
                SetConsoleTextAttribute(h, 12);
                cout << "\n\t[ Invalid input ! ]\n";
            }
        } while (gameMode != "A" && gameMode != "a" && gameMode != "B" && gameMode != "b");
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
    // Row 1
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[0][0] << "  |"
         << "  " << matrix[0][1] << "  |"
         << "  " << matrix[0][2] << "  |"
         << "  " << matrix[0][3] << "  |"
         << "  " << matrix[0][4] << "  |"
         << "  " << matrix[0][5] << "  |"
         << "  " << matrix[0][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 2
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[1][0] << "  |"
         << "  " << matrix[1][1] << "  |"
         << "  " << matrix[1][2] << "  |"
         << "  " << matrix[1][3] << "  |"
         << "  " << matrix[1][4] << "  |"
         << "  " << matrix[1][5] << "  |"
         << "  " << matrix[1][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 3
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[2][0] << "  |"
         << "  " << matrix[2][1] << "  |"
         << "  " << matrix[2][2] << "  |"
         << "  " << matrix[2][3] << "  |"
         << "  " << matrix[2][4] << "  |"
         << "  " << matrix[2][5] << "  |"
         << "  " << matrix[2][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 4
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[3][0] << "  |"
         << "  " << matrix[3][1] << "  |"
         << "  " << matrix[3][2] << "  |"
         << "  " << matrix[3][3] << "  |"
         << "  " << matrix[3][4] << "  |"
         << "  " << matrix[3][5] << "  |"
         << "  " << matrix[3][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 5
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[4][0] << "  |"
         << "  " << matrix[4][1] << "  |"
         << "  " << matrix[4][2] << "  |"
         << "  " << matrix[4][3] << "  |"
         << "  " << matrix[4][4] << "  |"
         << "  " << matrix[4][5] << "  |"
         << "  " << matrix[4][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 6
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[5][0] << "  |"
         << "  " << matrix[5][1] << "  |"
         << "  " << matrix[5][2] << "  |"
         << "  " << matrix[5][3] << "  |"
         << "  " << matrix[5][4] << "  |"
         << "  " << matrix[5][5] << "  |"
         << "  " << matrix[5][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Column Indicator
    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t\t       Column Indicator\n";
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << columnIndicator[0] << "  |"
         << "  " << columnIndicator[1] << "  |"
         << "  " << columnIndicator[2] << "  |"
         << "  " << columnIndicator[3] << "  |"
         << "  " << columnIndicator[4] << "  |"
         << "  " << columnIndicator[5] << "  |"
         << "  " << columnIndicator[6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
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
            cout << "\n\n  Press the number of column you want to place your move: ";
            cin >> playerInput;
            if (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7")
            {
                SetConsoleTextAttribute(h, 10); // set text-color to green
                cout << "\n  [ Invalid Input ] " << endl;
            }
        }
        else if (playerSymbol == "O")
        {
            SetConsoleTextAttribute(h, 12); // set text - color red
            cout << "\n  Player 2 Turn [ O ] : " << NumberOfPlayerTwoTurn;
            cout << "\n\n  Press the number of column you want to place your move: ";
            cin >> playerInput;
            if (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7")
            {
                SetConsoleTextAttribute(h, 10); // set text-color to green
                cout << "\n  [ Invalid Input ] " << endl;
            }
        }
    } while (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7");

    // Change the content of 2D arrays based on input of user
    if (playerInput == "1")
    {
        if (matrix[5][0] == " ")
        {
            matrix[5][0] = playerSymbol;
        }
        else if (matrix[4][0] == " ")
        {
            matrix[4][0] = playerSymbol;
        }
        else if (matrix[3][0] == " ")
        {
            matrix[3][0] = playerSymbol;
        }
        else if (matrix[2][0] == " ")
        {
            matrix[2][0] = playerSymbol;
        }
        else if (matrix[1][0] == " ")
        {
            matrix[1][0] = playerSymbol;
        }
        else if (matrix[0][0] == " ")
        {
            matrix[0][0] = playerSymbol;
        }
        else if (matrix[0][0] == "X" || matrix[0][0] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
        }
    }
    else if (playerInput == "2")
    {
        if (matrix[5][1] == " ")
        {
            matrix[5][1] = playerSymbol;
        }
        else if (matrix[4][1] == " ")
        {
            matrix[4][1] = playerSymbol;
        }
        else if (matrix[3][1] == " ")
        {
            matrix[3][1] = playerSymbol;
        }
        else if (matrix[2][1] == " ")
        {
            matrix[2][1] = playerSymbol;
        }
        else if (matrix[1][1] == " ")
        {
            matrix[1][1] = playerSymbol;
        }
        else if (matrix[0][1] == " ")
        {
            matrix[0][1] = playerSymbol;
        }
        else if (matrix[0][1] == "X" || matrix[0][1] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
        }
    }
    else if (playerInput == "3")
    {
        if (matrix[5][2] == " ")
        {
            matrix[5][2] = playerSymbol;
        }
        else if (matrix[4][2] == " ")
        {
            matrix[4][2] = playerSymbol;
        }
        else if (matrix[3][2] == " ")
        {
            matrix[3][2] = playerSymbol;
        }
        else if (matrix[2][2] == " ")
        {
            matrix[2][2] = playerSymbol;
        }
        else if (matrix[1][2] == " ")
        {
            matrix[1][2] = playerSymbol;
        }
        else if (matrix[0][2] == " ")
        {
            matrix[0][2] = playerSymbol;
        }
        else if (matrix[0][2] == "X" || matrix[0][2] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
        }
    }
    else if (playerInput == "4")
    {
        if (matrix[5][3] == " ")
        {
            matrix[5][3] = playerSymbol;
        }
        else if (matrix[4][3] == " ")
        {
            matrix[4][3] = playerSymbol;
        }
        else if (matrix[3][3] == " ")
        {
            matrix[3][3] = playerSymbol;
        }
        else if (matrix[2][3] == " ")
        {
            matrix[2][3] = playerSymbol;
        }
        else if (matrix[1][3] == " ")
        {
            matrix[1][3] = playerSymbol;
        }
        else if (matrix[0][3] == " ")
        {
            matrix[0][3] = playerSymbol;
        }
        else if (matrix[0][3] == "X" || matrix[0][3] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
        }
    }
    else if (playerInput == "5")
    {
        if (matrix[5][4] == " ")
        {
            matrix[5][4] = playerSymbol;
        }
        else if (matrix[4][4] == " ")
        {
            matrix[4][4] = playerSymbol;
        }
        else if (matrix[3][4] == " ")
        {
            matrix[3][4] = playerSymbol;
        }
        else if (matrix[2][4] == " ")
        {
            matrix[2][4] = playerSymbol;
        }
        else if (matrix[1][4] == " ")
        {
            matrix[1][4] = playerSymbol;
        }
        else if (matrix[0][4] == " ")
        {
            matrix[0][4] = playerSymbol;
        }
        else if (matrix[0][4] == "X" || matrix[0][4] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
        }
    }
    else if (playerInput == "6")
    {
        if (matrix[5][5] == " ")
        {
            matrix[5][5] = playerSymbol;
        }
        else if (matrix[4][5] == " ")
        {
            matrix[4][5] = playerSymbol;
        }
        else if (matrix[3][5] == " ")
        {
            matrix[3][5] = playerSymbol;
        }
        else if (matrix[2][5] == " ")
        {
            matrix[2][5] = playerSymbol;
        }
        else if (matrix[1][5] == " ")
        {
            matrix[1][5] = playerSymbol;
        }
        else if (matrix[0][5] == " ")
        {
            matrix[0][5] = playerSymbol;
        }
        else if (matrix[0][5] == "X" || matrix[0][5] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
        }
    }
    else if (playerInput == "7")
    {
        if (matrix[5][6] == " ")
        {
            matrix[5][6] = playerSymbol;
        }
        else if (matrix[4][6] == " ")
        {
            matrix[4][6] = playerSymbol;
        }
        else if (matrix[3][6] == " ")
        {
            matrix[3][6] = playerSymbol;
        }
        else if (matrix[2][6] == " ")
        {
            matrix[2][6] = playerSymbol;
        }
        else if (matrix[1][6] == " ")
        {
            matrix[1][6] = playerSymbol;
        }
        else if (matrix[0][6] == " ")
        {
            matrix[0][6] = playerSymbol;
        }
        else if (matrix[0][6] == "X" || matrix[0][6] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputPrompt();
            }
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
void ClearArrayContent()
{
    // Row 1
    if (matrix[5][0] == "X" || matrix[5][0] == "O")
    {
        matrix[5][0] = " ";
    }
    if (matrix[5][1] == "X" || matrix[5][1] == "O")
    {
        matrix[5][1] = " ";
    }
    if (matrix[5][2] == "X" || matrix[5][2] == "O")
    {
        matrix[5][2] = " ";
    }
    if (matrix[5][3] == "X" || matrix[5][3] == "O")
    {
        matrix[5][3] = " ";
    }
    if (matrix[5][4] == "X" || matrix[5][4] == "O")
    {
        matrix[5][4] = " ";
    }
    if (matrix[5][5] == "X" || matrix[5][5] == "O")
    {
        matrix[5][5] = " ";
    }
    if (matrix[5][6] == "X" || matrix[5][6] == "O")
    {
        matrix[5][6] = " ";
    }
    // Row 2
    if (matrix[4][0] == "X" || matrix[4][0] == "O")
    {
        matrix[4][0] = " ";
    }
    if (matrix[4][1] == "X" || matrix[4][1] == "O")
    {
        matrix[4][1] = " ";
    }
    if (matrix[4][2] == "X" || matrix[4][2] == "O")
    {
        matrix[4][2] = " ";
    }
    if (matrix[4][3] == "X" || matrix[4][3] == "O")
    {
        matrix[4][3] = " ";
    }
    if (matrix[4][4] == "X" || matrix[4][4] == "O")
    {
        matrix[4][4] = " ";
    }
    if (matrix[4][5] == "X" || matrix[4][5] == "O")
    {
        matrix[4][5] = " ";
    }
    if (matrix[4][6] == "X" || matrix[4][6] == "O")
    {
        matrix[4][6] = " ";
    }
    // Row 3
    if (matrix[3][0] == "X" || matrix[3][0] == "O")
    {
        matrix[3][0] = " ";
    }
    if (matrix[3][1] == "X" || matrix[3][1] == "O")
    {
        matrix[3][1] = " ";
    }
    if (matrix[3][2] == "X" || matrix[3][2] == "O")
    {
        matrix[3][2] = " ";
    }
    if (matrix[3][3] == "X" || matrix[3][3] == "O")
    {
        matrix[3][3] = " ";
    }
    if (matrix[3][4] == "X" || matrix[3][4] == "O")
    {
        matrix[3][4] = " ";
    }
    if (matrix[3][5] == "X" || matrix[3][5] == "O")
    {
        matrix[3][5] = " ";
    }
    if (matrix[3][6] == "X" || matrix[3][6] == "O")
    {
        matrix[3][6] = " ";
    }
    // Row 4
    if (matrix[2][0] == "X" || matrix[2][0] == "O")
    {
        matrix[2][0] = " ";
    }
    if (matrix[2][1] == "X" || matrix[2][1] == "O")
    {
        matrix[2][1] = " ";
    }
    if (matrix[2][2] == "X" || matrix[2][2] == "O")
    {
        matrix[2][2] = " ";
    }
    if (matrix[2][3] == "X" || matrix[2][3] == "O")
    {
        matrix[2][3] = " ";
    }
    if (matrix[2][4] == "X" || matrix[2][4] == "O")
    {
        matrix[2][4] = " ";
    }
    if (matrix[2][5] == "X" || matrix[2][5] == "O")
    {
        matrix[2][5] = " ";
    }
    if (matrix[2][6] == "X" || matrix[2][6] == "O")
    {
        matrix[2][6] = " ";
    }
    // Row 5
    if (matrix[1][0] == "X" || matrix[1][0] == "O")
    {
        matrix[1][0] = " ";
    }
    if (matrix[1][1] == "X" || matrix[1][1] == "O")
    {
        matrix[1][1] = " ";
    }
    if (matrix[1][2] == "X" || matrix[1][2] == "O")
    {
        matrix[1][2] = " ";
    }
    if (matrix[1][3] == "X" || matrix[1][3] == "O")
    {
        matrix[1][3] = " ";
    }
    if (matrix[1][4] == "X" || matrix[1][4] == "O")
    {
        matrix[1][4] = " ";
    }
    if (matrix[1][5] == "X" || matrix[1][5] == "O")
    {
        matrix[1][5] = " ";
    }
    if (matrix[1][6] == "X" || matrix[1][6] == "O")
    {
        matrix[1][6] = " ";
    }
    // Row 6
    if (matrix[0][0] == "X" || matrix[0][0] == "O")
    {
        matrix[0][0] = " ";
    }
    if (matrix[0][1] == "X" || matrix[0][1] == "O")
    {
        matrix[0][1] = " ";
    }
    if (matrix[0][2] == "X" || matrix[0][2] == "O")
    {
        matrix[0][2] = " ";
    }
    if (matrix[0][3] == "X" || matrix[0][3] == "O")
    {
        matrix[0][3] = " ";
    }
    if (matrix[0][4] == "X" || matrix[0][4] == "O")
    {
        matrix[0][4] = " ";
    }
    if (matrix[0][5] == "X" || matrix[0][5] == "O")
    {
        matrix[0][5] = " ";
    }
    if (matrix[0][6] == "X" || matrix[0][6] == "O")
    {
        matrix[0][6] = " ";
    }
}
void MatrixForAI()
{
    cout << "\n\n";
    SetConsoleTextAttribute(h, 14); // set text-color to yellow
    cout << "\t\t\t      Player 1 ";
    SetConsoleTextAttribute(h, 10); // set text-color to green
    cout << "VS. ";
    SetConsoleTextAttribute(h, 12); // set text - color red
    cout << "Computer\n\n\n";
    SetConsoleTextAttribute(h, 10); // set text-color to green
    // Row 1
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[0][0] << "  |"
         << "  " << matrix[0][1] << "  |"
         << "  " << matrix[0][2] << "  |"
         << "  " << matrix[0][3] << "  |"
         << "  " << matrix[0][4] << "  |"
         << "  " << matrix[0][5] << "  |"
         << "  " << matrix[0][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 2
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[1][0] << "  |"
         << "  " << matrix[1][1] << "  |"
         << "  " << matrix[1][2] << "  |"
         << "  " << matrix[1][3] << "  |"
         << "  " << matrix[1][4] << "  |"
         << "  " << matrix[1][5] << "  |"
         << "  " << matrix[1][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 3
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[2][0] << "  |"
         << "  " << matrix[2][1] << "  |"
         << "  " << matrix[2][2] << "  |"
         << "  " << matrix[2][3] << "  |"
         << "  " << matrix[2][4] << "  |"
         << "  " << matrix[2][5] << "  |"
         << "  " << matrix[2][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 4
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[3][0] << "  |"
         << "  " << matrix[3][1] << "  |"
         << "  " << matrix[3][2] << "  |"
         << "  " << matrix[3][3] << "  |"
         << "  " << matrix[3][4] << "  |"
         << "  " << matrix[3][5] << "  |"
         << "  " << matrix[3][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 5
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[4][0] << "  |"
         << "  " << matrix[4][1] << "  |"
         << "  " << matrix[4][2] << "  |"
         << "  " << matrix[4][3] << "  |"
         << "  " << matrix[4][4] << "  |"
         << "  " << matrix[4][5] << "  |"
         << "  " << matrix[4][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Row 6
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << matrix[5][0] << "  |"
         << "  " << matrix[5][1] << "  |"
         << "  " << matrix[5][2] << "  |"
         << "  " << matrix[5][3] << "  |"
         << "  " << matrix[5][4] << "  |"
         << "  " << matrix[5][5] << "  |"
         << "  " << matrix[5][6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    // Column Indicator
    SetConsoleTextAttribute(h, 9);
    cout << "\n\t\t\t       Column Indicator\n";
    cout << "\t\t   _____ _____ _____ _____ _____ _____ _____\n";
    cout << "\t\t  |     |     |     |     |     |     |     |\n";
    cout << "\t\t  |  " << columnIndicator[0] << "  |"
         << "  " << columnIndicator[1] << "  |"
         << "  " << columnIndicator[2] << "  |"
         << "  " << columnIndicator[3] << "  |"
         << "  " << columnIndicator[4] << "  |"
         << "  " << columnIndicator[5] << "  |"
         << "  " << columnIndicator[6] << "  |" << endl;
    cout << "\t\t  |_____|_____|_____|_____|_____|_____|_____|\n";
    SetConsoleTextAttribute(h, 10);
}

void DifficultyLevel()
{
    SetConsoleTextAttribute(h, 14); // set text-color to yellow
    cout << "\n\t\t\t       Levels of Difficulty\n";
    cout << "\n\n\t\t\t     A. Easy\n";
    cout << "\n\t\t\t     B. Intermediate\n";
    cout << "\n\t\t\t     C. Advance\n";
    cout << "\n\n\n";

    do
    {
        SetConsoleTextAttribute(h, 14);
        cout << "\n\tPress [A], [B], or [C]: ";
        cin >> Difficulty;
        if (Difficulty != "A" && Difficulty != "a" && Difficulty != "B" && Difficulty != "b" && Difficulty != "C" && Difficulty != "c")
        {
            SetConsoleTextAttribute(h, 12);
            cout << "\n\t[ Invalid input ! ]\n";
        }
    } while (Difficulty != "A" && Difficulty != "a" && Difficulty != "B" && Difficulty != "b" && Difficulty != "C" && Difficulty != "c");
}

void MultiplayerMode()
{
    while (true)
    {
        NumberOfTurn--;
        SetConsoleTextAttribute(h, 10); // set text-color to green
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
            playerSymbol = "O"; // change symbol to O for next turn
            ChangePlayerTurn();
            ClearArrayContent(); // to reset matrix content
            break;
        }
        else if (CheckWinner() == 'O')
        {
            SetConsoleTextAttribute(h, 12); // set text - color red
            cout << "\n\t\t\t      [ Player 2 Wins ! ]\n";
            ChangePlayerTurn();  // to reset player turn
            ClearArrayContent(); // to reset matrix content
            break;
        }
        else if (CheckWinner() == '/' && NumberOfTurn == 1)
        {
            SetConsoleTextAttribute(h, 10); // set text-color to green
            cout << "\n\t\t\t      [ It's a Draw ! ]\n";
            if (playerSymbol == "O")
            {
                ChangePlayerTurn();
            }
            else if (playerSymbol == "X")
            {
                playerSymbol == "O";
                ChangePlayerTurn();
            }
            ClearArrayContent(); // to reset matrix content
            break;
        }
        ChangePlayerTurn();
    }
    SetConsoleTextAttribute(h, 14); // set text-color to yellow
}

void GoToMainMenuOrQuitGame()
{
    system("cls");
    HeaderPrompt();
    SetConsoleTextAttribute(h, 14); // set text-color to yellow
    cout << "\n\n\n\n\t\t   Go To Main Menu [M] or Quit Game [Q]: ";
    cin >> mainMenu_quitGame;
}

void GenerateComputerChoice()
{
    srand(time(NULL));
    computerChoice = rand() % 7 + 1;
    SetConsoleTextAttribute(h, 12); // set text - color red
    cout << "\n  Computer Turn [O] : ";
    cout << "\n\n  Computer Choose Column : " << computerChoice << endl;
    sleep(1);
}

void InputForEasyAI()
{
    cout << endl;
    do
    {
        if (playerSymbol == "X")
        {
            SetConsoleTextAttribute(h, 14); // set text-color to yellow
            cout << "\n  Player 1 Turn [ X ] : ";
            cout << "\n\n  Press the number of column you want to place your move: ";
            cin >> playerInput;
            if (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7")
            {
                SetConsoleTextAttribute(h, 10); // set text-color to green
                cout << "\n  [ Invalid Input ] " << endl;
            }
        }

    } while (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7");

    ChangePlayerTurn();
    if (playerSymbol == "O")
    {
        GenerateComputerChoice();
        if (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7")
        {
            SetConsoleTextAttribute(h, 10); // set text-color to green
            cout << "\n  [ Invalid Input ] " << endl;
        }
        ChangePlayerTurn();
    }
    // Change the content of 2D arrays based on input of user
    if (playerInput == "1")
    {
        if (matrix[5][0] == " ")
        {
            matrix[5][0] = playerSymbol;
        }
        else if (matrix[4][0] == " ")
        {
            matrix[4][0] = playerSymbol;
        }
        else if (matrix[3][0] == " ")
        {
            matrix[3][0] = playerSymbol;
        }
        else if (matrix[2][0] == " ")
        {
            matrix[2][0] = playerSymbol;
        }
        else if (matrix[1][0] == " ")
        {
            matrix[1][0] = playerSymbol;
        }
        else if (matrix[0][0] == " ")
        {
            matrix[0][0] = playerSymbol;
        }
        else if (matrix[0][0] == "X" || matrix[0][0] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
        }
    }
    else if (playerInput == "2")
    {
        if (matrix[5][1] == " ")
        {
            matrix[5][1] = playerSymbol;
        }
        else if (matrix[4][1] == " ")
        {
            matrix[4][1] = playerSymbol;
        }
        else if (matrix[3][1] == " ")
        {
            matrix[3][1] = playerSymbol;
        }
        else if (matrix[2][1] == " ")
        {
            matrix[2][1] = playerSymbol;
        }
        else if (matrix[1][1] == " ")
        {
            matrix[1][1] = playerSymbol;
        }
        else if (matrix[0][1] == " ")
        {
            matrix[0][1] = playerSymbol;
        }
        else if (matrix[0][1] == "X" || matrix[0][1] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
        }
    }
    else if (playerInput == "3")
    {
        if (matrix[5][2] == " ")
        {
            matrix[5][2] = playerSymbol;
        }
        else if (matrix[4][2] == " ")
        {
            matrix[4][2] = playerSymbol;
        }
        else if (matrix[3][2] == " ")
        {
            matrix[3][2] = playerSymbol;
        }
        else if (matrix[2][2] == " ")
        {
            matrix[2][2] = playerSymbol;
        }
        else if (matrix[1][2] == " ")
        {
            matrix[1][2] = playerSymbol;
        }
        else if (matrix[0][2] == " ")
        {
            matrix[0][2] = playerSymbol;
        }
        else if (matrix[0][2] == "X" || matrix[0][2] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
        }
    }
    else if (playerInput == "4")
    {
        if (matrix[5][3] == " ")
        {
            matrix[5][3] = playerSymbol;
        }
        else if (matrix[4][3] == " ")
        {
            matrix[4][3] = playerSymbol;
        }
        else if (matrix[3][3] == " ")
        {
            matrix[3][3] = playerSymbol;
        }
        else if (matrix[2][3] == " ")
        {
            matrix[2][3] = playerSymbol;
        }
        else if (matrix[1][3] == " ")
        {
            matrix[1][3] = playerSymbol;
        }
        else if (matrix[0][3] == " ")
        {
            matrix[0][3] = playerSymbol;
        }
        else if (matrix[0][3] == "X" || matrix[0][3] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
        }
    }
    else if (playerInput == "5")
    {
        if (matrix[5][4] == " ")
        {
            matrix[5][4] = playerSymbol;
        }
        else if (matrix[4][4] == " ")
        {
            matrix[4][4] = playerSymbol;
        }
        else if (matrix[3][4] == " ")
        {
            matrix[3][4] = playerSymbol;
        }
        else if (matrix[2][4] == " ")
        {
            matrix[2][4] = playerSymbol;
        }
        else if (matrix[1][4] == " ")
        {
            matrix[1][4] = playerSymbol;
        }
        else if (matrix[0][4] == " ")
        {
            matrix[0][4] = playerSymbol;
        }
        else if (matrix[0][4] == "X" || matrix[0][4] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
        }
    }
    else if (playerInput == "6")
    {
        if (matrix[5][5] == " ")
        {
            matrix[5][5] = playerSymbol;
        }
        else if (matrix[4][5] == " ")
        {
            matrix[4][5] = playerSymbol;
        }
        else if (matrix[3][5] == " ")
        {
            matrix[3][5] = playerSymbol;
        }
        else if (matrix[2][5] == " ")
        {
            matrix[2][5] = playerSymbol;
        }
        else if (matrix[1][5] == " ")
        {
            matrix[1][5] = playerSymbol;
        }
        else if (matrix[0][5] == " ")
        {
            matrix[0][5] = playerSymbol;
        }
        else if (matrix[0][5] == "X" || matrix[0][5] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
        }
    }
    else if (playerInput == "7")
    {
        if (matrix[5][6] == " ")
        {
            matrix[5][6] = playerSymbol;
        }
        else if (matrix[4][6] == " ")
        {
            matrix[4][6] = playerSymbol;
        }
        else if (matrix[3][6] == " ")
        {
            matrix[3][6] = playerSymbol;
        }
        else if (matrix[2][6] == " ")
        {
            matrix[2][6] = playerSymbol;
        }
        else if (matrix[1][6] == " ")
        {
            matrix[1][6] = playerSymbol;
        }
        else if (matrix[0][6] == " ")
        {
            matrix[0][6] = playerSymbol;
        }
        else if (matrix[0][6] == "X" || matrix[0][6] == "O")
        {
            if (playerSymbol == "X")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
            else
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                InputForEasyAI();
            }
        }
    }

    playerSymbol = "O";
    if (computerChoice == 1)
    {
        if (matrix[5][0] == " ")
        {
            matrix[5][0] = playerSymbol;
        }
        else if (matrix[4][0] == " ")
        {
            matrix[4][0] = playerSymbol;
        }
        else if (matrix[3][0] == " ")
        {
            matrix[3][0] = playerSymbol;
        }
        else if (matrix[2][0] == " ")
        {
            matrix[2][0] = playerSymbol;
        }
        else if (matrix[1][0] == " ")
        {
            matrix[1][0] = playerSymbol;
        }
        else if (matrix[0][0] == " ")
        {
            matrix[0][0] = playerSymbol;
        }
        else if (matrix[0][0] == "X" || matrix[0][0] == "O")
        {
            if (playerSymbol == "O")
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                GenerateComputerChoice();
                InputForEasyAI();
            }
        }
    }
    else if (computerChoice == 2)
    {
        if (matrix[5][1] == " ")
        {
            matrix[5][1] = playerSymbol;
        }
        else if (matrix[4][1] == " ")
        {
            matrix[4][1] = playerSymbol;
        }
        else if (matrix[3][1] == " ")
        {
            matrix[3][1] = playerSymbol;
        }
        else if (matrix[2][1] == " ")
        {
            matrix[2][1] = playerSymbol;
        }
        else if (matrix[1][1] == " ")
        {
            matrix[1][1] = playerSymbol;
        }
        else if (matrix[0][1] == " ")
        {
            matrix[0][1] = playerSymbol;
        }
        else if (matrix[0][1] == "X" || matrix[0][1] == "O")
        {
            if (playerSymbol == "O")
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                GenerateComputerChoice();
                InputForEasyAI();
            }
        }
    }
    else if (computerChoice == 3)
    {
        if (matrix[5][2] == " ")
        {
            matrix[5][2] = playerSymbol;
        }
        else if (matrix[4][2] == " ")
        {
            matrix[4][2] = playerSymbol;
        }
        else if (matrix[3][2] == " ")
        {
            matrix[3][2] = playerSymbol;
        }
        else if (matrix[2][2] == " ")
        {
            matrix[2][2] = playerSymbol;
        }
        else if (matrix[1][2] == " ")
        {
            matrix[1][2] = playerSymbol;
        }
        else if (matrix[0][2] == " ")
        {
            matrix[0][2] = playerSymbol;
        }
        else if (matrix[0][2] == "X" || matrix[0][2] == "O")
        {
            if (playerSymbol == "O")
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                GenerateComputerChoice();
                InputForEasyAI();
            }
        }
    }
    else if (computerChoice == 4)
    {
        if (matrix[5][3] == " ")
        {
            matrix[5][3] = playerSymbol;
        }
        else if (matrix[4][3] == " ")
        {
            matrix[4][3] = playerSymbol;
        }
        else if (matrix[3][3] == " ")
        {
            matrix[3][3] = playerSymbol;
        }
        else if (matrix[2][3] == " ")
        {
            matrix[2][3] = playerSymbol;
        }
        else if (matrix[1][3] == " ")
        {
            matrix[1][3] = playerSymbol;
        }
        else if (matrix[0][3] == " ")
        {
            matrix[0][3] = playerSymbol;
        }
        else if (matrix[0][3] == "X" || matrix[0][3] == "O")
        {
            if (playerSymbol == "O")
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                GenerateComputerChoice();
                InputForEasyAI();
            }
        }
    }
    else if (computerChoice == 5)
    {
        if (matrix[5][4] == " ")
        {
            matrix[5][4] = playerSymbol;
        }
        else if (matrix[4][4] == " ")
        {
            matrix[4][4] = playerSymbol;
        }
        else if (matrix[3][4] == " ")
        {
            matrix[3][4] = playerSymbol;
        }
        else if (matrix[2][4] == " ")
        {
            matrix[2][4] = playerSymbol;
        }
        else if (matrix[1][4] == " ")
        {
            matrix[1][4] = playerSymbol;
        }
        else if (matrix[0][4] == " ")
        {
            matrix[0][4] = playerSymbol;
        }
        else if (matrix[0][4] == "X" || matrix[0][4] == "O")
        {
            if (playerSymbol == "O")
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                GenerateComputerChoice();
                InputForEasyAI();
            }
        }
    }
    else if (computerChoice == 6)
    {
        if (matrix[5][5] == " ")
        {
            matrix[5][5] = playerSymbol;
        }
        else if (matrix[4][5] == " ")
        {
            matrix[4][5] = playerSymbol;
        }
        else if (matrix[3][5] == " ")
        {
            matrix[3][5] = playerSymbol;
        }
        else if (matrix[2][5] == " ")
        {
            matrix[2][5] = playerSymbol;
        }
        else if (matrix[1][5] == " ")
        {
            matrix[1][5] = playerSymbol;
        }
        else if (matrix[0][5] == " ")
        {
            matrix[0][5] = playerSymbol;
        }
        else if (matrix[0][5] == "X" || matrix[0][5] == "O")
        {
            if (playerSymbol == "O")
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                GenerateComputerChoice();
                InputForEasyAI();
            }
        }
    }
    else if (computerChoice == 7)
    {
        if (matrix[5][6] == " ")
        {
            matrix[5][6] = playerSymbol;
        }
        else if (matrix[4][6] == " ")
        {
            matrix[4][6] = playerSymbol;
        }
        else if (matrix[3][6] == " ")
        {
            matrix[3][6] = playerSymbol;
        }
        else if (matrix[2][6] == " ")
        {
            matrix[2][6] = playerSymbol;
        }
        else if (matrix[1][6] == " ")
        {
            matrix[1][6] = playerSymbol;
        }
        else if (matrix[0][6] == " ")
        {
            matrix[0][6] = playerSymbol;
        }
        else if (matrix[0][6] == "X" || matrix[0][6] == "O")
        {
            if (playerSymbol == "O")
            {
                SetConsoleTextAttribute(h, 14); // set text-color to yellow
                cout << "\n  [ Column is already filled ! ]" << endl;
                GenerateComputerChoice();
                InputForEasyAI();
            }
        }
    }
}

void EasyAI_Mode()
{
    while (true)
    {
        NumberOfTurn--;
        SetConsoleTextAttribute(h, 10); // set text-color to green
        InputForEasyAI();
        system("cls"); // updating screen for input
        HeaderPrompt();
        MatrixForAI();
        if (CheckWinner() == 'X')
        {
            SetConsoleTextAttribute(h, 14); // set text-color to yellow
            cout << "\n\t\t\t      [ Player 1 Wins ! ]\n";
            playerSymbol = "O";
            ChangePlayerTurn();
            ClearArrayContent(); // to reset matrix content
            break;
        }
        else if (CheckWinner() == 'O')
        {
            SetConsoleTextAttribute(h, 12); // set text - color red
            cout << "\n\t\t\t      [ Computer Wins ! ]\n";
            ChangePlayerTurn();  // to reset player turn
            ClearArrayContent(); // to reset matrix content
            break;
        }
        else if (CheckWinner() == '/' && NumberOfTurn == 1)
        {
            SetConsoleTextAttribute(h, 10); // set text-color to green
            cout << "\n\t\t\t      [ It's a Draw ! ]\n";
            if (playerSymbol == "O")
            {
                ChangePlayerTurn();
            }
            else if (playerSymbol == "X")
            {
                playerSymbol == "O";
                ChangePlayerTurn();
            }
            ClearArrayContent(); // to reset matrix content
            break;
        }
        ChangePlayerTurn();
    }
    SetConsoleTextAttribute(h, 14); // set text-color to yellow
}

void InputForInterAI()
{
    cout << endl;
    do
    {
        if (playerSymbol == "X")
        {
            SetConsoleTextAttribute(h, 14); // set text-color to yellow
            cout << "\n  Player 1 Turn [ X ] : ";
            cout << "\n\n  Press the number of column you want to place your move: ";
            cin >> playerInput;
            if (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7")
            {
                SetConsoleTextAttribute(h, 10); // set text-color to green
                cout << "\n  [ Invalid Input ] " << endl;
            }
        }
    } while (playerInput != "1" && playerInput != "2" && playerInput != "3" && playerInput != "4" && playerInput != "5" && playerInput != "6" && playerInput != "7");
}

int main()
{
    do
    {
        mainMenu = "";
        goToMainMenu = "";
        gameMode = "";
        Difficulty = "";
        HeaderPrompt();
        MainPrompt();
        CheckMenu();
        GoToTutorial();
        GoToGameMode();

        if (goToMainMenu == "M" || goToMainMenu == "m")
        {
            system("cls");
            HeaderPrompt();
            PlayGamePrompt();
            PlayGameMenu();
            GoToGameMode();
        }
        // Multiplayer Game
        do
        {
            NumberOfTurn = 43;
            NumberOfPlayerOneTurn = 22;
            NumberOfPlayerTwoTurn = 22;
            system("cls");
            if (gameMode == "A" || gameMode == "a")
            {
                system("cls");
                HeaderPrompt();
                MultiplayerDrawMatrix();
                MultiplayerMode();
                do
                {
                    SetConsoleTextAttribute(h, 14); // set text-color to yellow
                    cout << "\n\n Play Again [Y/N]: ";
                    cin >> playAgain;
                    if (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n")
                    {
                        SetConsoleTextAttribute(h, 12); // set text - color red
                        cout << "\n [ Invalid input ! ]";
                    }
                    if (playAgain == "N" || playAgain == "n")
                    {
                        break;
                    }
                } while (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n");
            }
        } while (playAgain == "Y" || playAgain == "y");

        // Versus AI

        if (gameMode == "B" || gameMode == "b")
        {
            system("cls");
            HeaderPrompt();
            DifficultyLevel();
            do
            {
                NumberOfTurn = 43;
                system("cls");
                if (Difficulty == "A" || Difficulty == "a")
                {
                    system("cls");
                    HeaderPrompt();
                    MatrixForAI();
                    EasyAI_Mode();

                    do
                    {
                        SetConsoleTextAttribute(h, 14); // set text-color to yellow
                        cout << "\n Play Again [Y/N]: ";
                        cin >> playAgain;

                        if (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n")
                        {
                            SetConsoleTextAttribute(h, 12); // set text - color red
                            cout << "\n [ Invalid input ! ]\n";
                        }
                        if (playAgain == "N" || playAgain == "n")
                        {
                            break;
                        }
                    } while (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n");
                }
            } while (playAgain == "Y" || playAgain == "y");

            do
            {
                NumberOfTurn = 43;
                system("cls");
                if (Difficulty == "B" || Difficulty == "b")
                {
                    system("cls");
                    HeaderPrompt();
                    MatrixForAI();
                    while (true)
                    {
                        NumberOfTurn--;
                        SetConsoleTextAttribute(h, 10); // set text-color to green
                        InputForInterAI();
                        system("cls"); // updating screen for input
                        HeaderPrompt();
                        MatrixForAI();
                        if (CheckWinner() == 'X')
                        {
                            SetConsoleTextAttribute(h, 14); // set text-color to yellow
                            cout << "\n\t\t\t      [ Player 1 Wins ! ]\n";
                            playerSymbol = "O";
                            ChangePlayerTurn();
                            ClearArrayContent(); // to reset matrix content
                            break;
                        }
                        else if (CheckWinner() == 'O')
                        {
                            SetConsoleTextAttribute(h, 12); // set text - color red
                            cout << "\n\t\t\t      [ Computer Wins ! ]\n";
                            ChangePlayerTurn();  // to reset player turn
                            ClearArrayContent(); // to reset matrix content
                            break;
                        }
                        else if (CheckWinner() == '/' && NumberOfTurn == 1)
                        {
                            SetConsoleTextAttribute(h, 10); // set text-color to green
                            cout << "\n\t\t\t      [ It's a Draw ! ]\n";
                            if (playerSymbol == "O")
                            {
                                ChangePlayerTurn();
                            }
                            else if (playerSymbol == "X")
                            {
                                playerSymbol == "O";
                                ChangePlayerTurn();
                            }
                            ClearArrayContent(); // to reset matrix content
                            break;
                        }
                        ChangePlayerTurn();
                    }
                    SetConsoleTextAttribute(h, 14); // set text-color to yellow
                    do
                    {
                        SetConsoleTextAttribute(h, 14); // set text-color to yellow
                        cout << "\n Play Again [Y/N]: ";
                        cin >> playAgain;

                        if (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n")
                        {
                            SetConsoleTextAttribute(h, 12); // set text - color red
                            cout << "\n [ Invalid input ! ]\n";
                        }
                        if (playAgain == "N" || playAgain == "n")
                        {
                            break;
                        }
                    } while (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n");
                }
            } while (playAgain == "Y" || playAgain == "y");

            do
            {
                if (Difficulty == "C" || Difficulty == "c")
                {
                    system("cls");
                    HeaderPrompt();
                    MatrixForAI();
                    do
                    {
                        SetConsoleTextAttribute(h, 14); // set text-color to yellow
                        cout << "\n Play Again [Y/N]: ";
                        cin >> playAgain;

                        if (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n")
                        {
                            SetConsoleTextAttribute(h, 12); // set text - color red
                            cout << "\n [ Invalid input ! ]\n";
                        }
                        if (playAgain == "N" || playAgain == "n")
                        {
                            break;
                        }
                    } while (playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n");
                }
            } while (playAgain == "Y" || playAgain == "y");
            SetConsoleTextAttribute(h, 14); // set text-color to yellow
        }

        do
        {
            GoToMainMenuOrQuitGame();
            if (mainMenu_quitGame != "M" && mainMenu_quitGame != "m" && mainMenu_quitGame != "Q" && mainMenu_quitGame != "q")
            {
                SetConsoleTextAttribute(h, 12); // set text - color red
                cout << "\n [ Invalid input ! ]\n";
            }
            if (mainMenu_quitGame == "M" || mainMenu_quitGame == "m")
            {
                system("cls");
            }
            else if (mainMenu_quitGame == "Q" || mainMenu_quitGame == "q")
            {
                break;
            }
        } while (mainMenu_quitGame != "M" && mainMenu_quitGame != "m" && mainMenu_quitGame != "Q" && mainMenu_quitGame != "q");

    } while (mainMenu_quitGame == "M" || mainMenu_quitGame == "m");

    system("cls");
    HeaderPrompt();
    SetConsoleTextAttribute(h, 14); // set text-color to yellow
    cout << "\n\n\n\n\t\t\t     THANK YOU FOR PLAYING :)\n";
    system("pause");
    return 0;
}

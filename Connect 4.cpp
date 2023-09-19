
#include <iostream>
#include <string>

void checkWin(char board[6][7]);

using namespace std;
int main()
{

    char board[6][7] =
    {
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
        {'_','_','_','_','_','_','_'},
    };

    int xAmount = 0;
    int oAmount = 0;
    int row = 0;             
    int column = 0;
    bool winner = false;

    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 7; b++)
        {
            cout << " | " << board[a][b];
        }
        cout << endl;
    }
    cout << "   1   2   3   4   5   6   7\n";

    while (winner != true)
    {
        cout << "Enter the column: ";
        cin >> column;

        column -= 1;

        for (int row = 5; row >= 0; row--)
        {
            if (board[row][column] != 'X' && board[row][column] != 'O')
            {

                board[row][column] = 'O';

                row = -1;
            }

        }

        system("cls");

        for (int a = 0; a < 6; a++)
        {
            for (int b = 0; b < 7; b++)
            {
                if (a == row && b == column)
                {
                    cout << " |" << board[a][b];
                }
                else
                {
                    cout << " | " << board[a][b];
                }
            }
            cout << endl;
        }
        cout << "   1   2   3   4   5   6   7\n";

        checkWin(board);

        cout << "Enter the column: ";
        cin >> column;

        column -= 1;

        for (int row = 5; row >= 0; row--)
        {
            if (board[row][column] != 'X' && board[row][column] != 'O')
            {

                board[row][column] = 'X';

                row = -1;
            }

        }

        system("cls");

        for (int a = 0; a < 6; a++)
        {
            for (int b = 0; b < 7; b++)
            {
                if (a == row && b == column)
                {
                    cout << " |" << board[a][b];
                }
                else
                {
                    cout << " | " << board[a][b];
                }
            }
            cout << endl;
        }

        cout << "   1   2   3   4   5   6   7\n";

         checkWin(board);

    }
}


void checkWin(char board[6][7])
{

    int xAmountH = 0;
    int oAmountH = 0;
    int xAmountV = 0;
    int oAmountV = 0;
    int xAmountDL = 0;
    int oAmountDL = 0;
    int xAmountDR = 0;
    int oAmountDR = 0;


for (int checkV = 0; checkV <= 5; checkV++)
    {
        if (xAmountH >= 4 || oAmountH >= 4)
        {

            checkV = 6;

            if (xAmountH >= 4)
            {

                cout << "X Won!!!!\n";

            }

            if (oAmountH >= 4)
            {

                cout << "O Won!!!!\n";

            }

        }
        else
        {

            xAmountH = 0;
            oAmountH = 0;

            for (int checkH = 0; checkH <= 6; checkH++)
            {

                if (board[checkV][checkH] == 'X')
                {

                    xAmountH += 1;

                    oAmountH = 0;

                }
                else if (board[checkV][checkH] == 'O')
                {

                    oAmountH += 1;

                    xAmountH = 0;

                }

            }

        }

    }

    for (int checkH = 0; checkH <= 6; checkH++)
    {

        if (xAmountV >= 4 || oAmountV >= 4)
        {

            checkH = 7;

            if (xAmountV >= 4)
            {

                cout << "X Won!!!!\n";

            }

            if (oAmountV >= 4)
            {

                cout << "O Won!!!!\n";

            }

        }

        else
        {

            xAmountV = 0;
            oAmountV = 0;

            for (int checkV = 0; checkV <= 5; checkV++)
            {

                if (board[checkV][checkH] == 'X')
                {

                    xAmountV += 1;

                    oAmountV = 0;

                }
                else if (board[checkV][checkH] == 'O')
                {

                    oAmountV += 1;

                    xAmountV = 0;

                }

            }

        }
    }

    bool running = true;
    int loopTimes = 0;
    int startingRow = 5;
    int startingCol = 3;
    int increment = 4;

    while (running)
    {

        loopTimes += 1;

        if (loopTimes < 3)
        {

            increment += 1;

        }
        else if (loopTimes >= 3 && loopTimes <= 4)
        {

            increment = 6;

        }
        else if (loopTimes < 6)
        {

            increment -= 1;

        }
        else
        {

            running = false;

        }

        if (board[startingRow][startingCol] == 'X' || board[startingRow][startingCol] == 'O')
        {

            if (board[startingRow][startingCol] == 'X')
            {

                xAmountDL += 1;

            }

            else
            {

                oAmountDL += 1;

            }

            for (int i = 0; i >= increment; i++)
            {



            }
        }

    }

}


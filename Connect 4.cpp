
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
            cout << board[a][b] << " | ";
        }
        cout << endl;
    }

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

         checkWin(board);

    }
}


void checkWin(char board[6][7])
{

    int xAmountH = 0;
    int oAmountH = 0;
    int xAmountV = 0;
    int oAmountV = 0;
    int xAmountD = 0;
    int oAmountD = 0;

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
}


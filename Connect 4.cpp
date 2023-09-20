
#include <iostream>
#include <string>

bool checkWin(char board[6][7]);
void printBoard(char board[6][7]);

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

        printBoard(board);

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

            printBoard(board);

            winner = checkWin(board);
            if (winner != true)
            {

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

                printBoard(board);

                winner = checkWin(board);

            }

        }
}

void printBoard(char board[6][7])
{

    for (int a = 0; a < 6; a++)
    {
        for (int b = 0; b < 7; b++)
        {
            cout << " | " << board[a][b];
        }
        cout << endl;
    }
    cout << "   1   2   3   4   5   6   7\n";

}

bool checkWin(char board[6][7])
{

    int xAmountH = 0;
    int oAmountH = 0;
    int xAmountV = 0;
    int oAmountV = 0;
    int xAmountDL = 0;
    int oAmountDL = 0;
    int xAmountDR = 0;
    int oAmountDR = 0;


for (int checkV = 0; checkV <= 6; checkV++)
    {
        if (xAmountH >= 4 || oAmountH >= 4)
        {

            checkV = 6;

            if (xAmountH >= 4)
            {

                cout << "X Won!!!!\n";

                return(true);

            }

            if (oAmountH >= 4)
            {

                cout << "O Won!!!!\n";

                return(true);

            }

        }
        else
        {

            xAmountH = 0;
            oAmountH = 0;

            for (int checkH = 0; checkH <= 7; checkH++)
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

    for (int checkH = 0; checkH <= 7; checkH++)
    {

        if (xAmountV >= 4 || oAmountV >= 4)
        {

            checkH = 7;

            if (xAmountV >= 4)
            {

                cout << "X Won!!!!\n";
                return(true);

            }

            if (oAmountV >= 4)
            {

                cout << "O Won!!!!\n";
                return(true);

            }

        }

        else
        {

            xAmountV = 0;
            oAmountV = 0;

            for (int checkV = 0; checkV <= 6; checkV++)
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
    int startingCol = 2;
    int increment = 4;

    while (running)
    {

        loopTimes += 1;

        if (loopTimes < 3)
        {

            increment += 1;
            startingCol += 1;

        }
        else if (loopTimes >= 3 && loopTimes <= 4)
        {

            increment = 6;

        }
        else if (loopTimes < 6)
        {

            increment -= 1;
            startingRow -= 1;

        }
        else
        {

            running = false;

        }

        xAmountDL = 0;
        oAmountDL = 0;
            for (int i = 0; i <= increment; i++)
            {

                if (board[startingRow - i][startingCol - i] == 'X' || board[startingRow - i][startingCol - i] == 'O')
                {

                    if (board[startingRow - i][startingCol - i] == 'X')
                    {

                        xAmountDL += 1;
                        oAmountDL = 0;

                    }

                    else
                    {

                        oAmountDL += 1;
                        xAmountDL = 0;

                    }
                }
                
                if (xAmountDL == 4 || oAmountDL == 4)
                {

                    if (xAmountDL == 4)
                    {

                        cout << "X Won!!!!\n";
                        return(true);
                        running = false;
                        i = 10;

                    }
                    else
                    {

                        cout << "O Won!!!!\n";
                        return(true);
                        running = false;
                        i = 10;

                    }
                }

            }

    }
    running = true;
    loopTimes = 0;
    startingRow = 5;
    startingCol = 2;
    increment = 4;

    while (running)
    {

        loopTimes += 1;

        if (loopTimes < 3)
        {

            increment += 1;
            startingCol += 1;

        }
        else if (loopTimes >= 3 && loopTimes <= 4)
        {

            increment = 6;

        }
        else if (loopTimes < 6)
        {

            increment -= 1;
            startingRow -= 1;

        }
        else
        {

            running = false;

        }

        xAmountDR = 0;
        oAmountDR = 0;
        for (int i = 0; i <= increment; i++)
        {

            if (board[startingRow - i][startingCol + i] == 'X' || board[startingRow - i][startingCol + i] == 'O')
            {

                if (board[startingRow - i][startingCol + i] == 'X')
                {

                    xAmountDR += 1;
                    oAmountDR = 0;

                }

                else
                {

                    oAmountDR += 1;
                    xAmountDR = 0;

                }
            }

            if (xAmountDR == 4 || oAmountDR == 4)
            {

                if (xAmountDR == 4)
                {

                    cout << "X Won!!!!\n";
                    return(true);
                    running = false;
                    i = 10;

                }
                else
                {

                    cout << "O Won!!!!\n";
                    return(true);
                    running = false;
                    i = 10;

                }
            }

        }

    }
}


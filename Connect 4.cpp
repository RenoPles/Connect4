
#include <iostream>
#include <string>
#include <random>

bool checkWin(char board[6][7]);
void printBoard(char board[6][7]);
int aiInput(char board[6][7]);

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
    bool noError = true;
    bool ai = false;
    bool correctlyEntered = false;
    string aiQuestion = "";


    while (correctlyEntered != true)
    {
        system("cls");

        cout << "1.   Play against AI\n";
        cout << "2.   Play against person\n";

        cout << "Which would you like to do? ";
        cin >> aiQuestion;

        if (aiQuestion == "1")
        {

            ai = true;
            correctlyEntered = true;

        }
        else if (aiQuestion == "2")
        {

            correctlyEntered = true;

        }
        else
        {

            cout << "Enter 1 or 2!!\n";

        }

    }

    system("cls");

    printBoard(board);

    while (winner != true)
    {

        noError = true;

        while (noError == true)
        {
            cout << "Enter the column: ";
            cin >> column;

            if (column > 7 || column < 0)
            {

                cout << "You can only enter number #1 - #7!!\n";

            }
            else
            {
                column -= 1;

                if (board[0][column] == 'O' || board[0][column] == 'X')
                {

                    cout << "The column is already full!!\n";

                }
                else
                {

                    noError = false;

                    for (int row = 5; row >= 0; row--)
                    {
                        if (board[row][column] != 'X' && board[row][column] != 'O')
                        {

                            board[row][column] = 'O';

                            row = -1;
                        }

                    }
                }
            }
        }

        system("cls");


        printBoard(board);

        winner = checkWin(board);

        if (winner != true)
        {


            noError = true;

            while (noError == true)
            {

                if (ai != true)
                {
                    cout << "Enter the column: ";
                    cin >> column;
                    column -= 1;
                }
                else
                {

                    column = aiInput(board);

                }
                if (column > 7 || column < 0)
                {

                    cout << "You can only enter number #1 - #7!!\n";

                }
                else
                {

                    if (board[0][column] == 'O' || board[0][column] == 'X')
                    {

                        cout << "The column is already full!!\n";

                    }
                    else
                    {

                        noError = false;
                        for (int row = 5; row >= 0; row--)
                        {
                            if (board[row][column] != 'X' && board[row][column] != 'O')
                            {


                                board[row][column] = 'X';

                                row = -1;
                            }

                        }

                    }

                }
            }
            system("cls");

            printBoard(board);

            winner = checkWin(board);

        }

    }
}

int aiInput(char board[6][7])
{

    int randomNumber = 0;

    int xAmount = 0;
    int oAmount = 0;
    bool almostWin = false;
    bool leftSide = false;


    for (int checkV = 5; checkV >= 0; checkV--)
    {

        xAmount = 0;
        oAmount = 0;


        for (int checkH = 0; checkH <= 6; checkH++)
        {

            if (board[checkV][checkH] == 'X')
            {

                xAmount += 1;

                oAmount = 0;

            }
            else if (board[checkV][checkH] == 'O')
            {

                oAmount += 1;

                xAmount = 0;

            }
            else if (board[checkV][checkH] == '_')
            {

                xAmount = 0;
                oAmount = 0;

            }
            if (xAmount >= 3 || oAmount >= 3)
            {

                if (xAmount >= 3)
                {

                    if ((checkH + 1) < 7)
                    {

                        if (board[checkV][checkH + 1] != 'O' && board[checkV][checkH + 1] != 'X')
                        {
                            checkH += 1;
                            return (checkH);
                            
                        }

                    }
                    else
                    {

                        if (board[checkV][checkH - 3] != 'O' && board[checkV][checkH - 3] != 'X')
                        {

                            checkH -= 3;
                            return (checkH);
                            

                        }

                    }

                }

                if (oAmount >= 3)
                {
                    if ((checkH + 1) < 7)
                    {
                    
                        if (board[checkV][checkH + 1] != 'O' && board[checkV][checkH + 1] != 'X')
                        {
                            checkH += 1;
                            return (checkH);
                            
                        }

                    }
                    else
                    {

                        if (board[checkV][checkH - 3] != 'O' && board[checkV][checkH - 3] != 'X')
                        {

                            checkH -= 3;
                            return (checkH);
                            

                        }

                    }
                    

                }



            }
        }


    }

    xAmount = 0;
    oAmount = 0;

    for (int checkH = 0; checkH <= 6; checkH++)
    {

            xAmount = 0;
            oAmount = 0;

            for (int checkV = 5; checkV >= 0; checkV--)
            {

                if (board[checkV][checkH] == 'X')
                {

                    xAmount += 1;

                    oAmount = 0;

                }
                else if (board[checkV][checkH] == 'O')
                {

                    oAmount += 1;

                    xAmount = 0;

                }
                else if (board[checkV][checkH] == '_')
                {

                    xAmount = 0;
                    oAmount = 0;

                }
                if (xAmount >= 3 || oAmount >= 3)
                {
                    
                    if (xAmount >= 3)
                    {
                        
                        if ((checkV - 1) != -1)
                        {
                            if (board[checkV - 1][checkH] != 'O' && board[checkV - 1][checkH] != 'X')
                            {
                                checkH;
                                return (checkH);
                                
                            }
                        }

                    }

                    if (oAmount >= 3)
                    {

                        if ((checkV - 1) >= 0)
                        {
                            if (board[checkV - 1][checkH] != 'O' && board[checkV - 1][checkH] != 'X')
                            {
                                checkH;
                                return (checkH);
                                
                            }
                        }

                    }

                }

            }
    }

    if (almostWin != true)
    {


        randomNumber = (rand() % (7 - 0 + 1)) + 0;
        return(randomNumber);

    }

    bool running = true;
    int loopTimes = 0;
    int startingRow = 5;
    int startingCol = 2;
    int increment = 4;
    xAmount = 0;
    oAmount = 0;

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

        xAmount = 0;
        oAmount = 0;
        for (int i = 0; i <= increment; i++)
        {

            if (board[startingRow - i][startingCol - i] == 'X' || board[startingRow - i][startingCol - i] == 'O')
            {

                if (board[startingRow - i][startingCol - i] == 'X')
                {

                    xAmount += 1;
                    oAmount = 0;

                }

                else if (board[startingRow - i][startingCol - i] == 'O')
                {

                    oAmount += 1;
                    xAmount = 0;

                }
                else if (board[startingRow - i][startingCol - i] == '_')
                {

                    oAmount = 0;
                    xAmount = 0;

                }
            }

            if (xAmount == 3 || oAmount == 3)
            {

                if (((startingRow - i) - 1 != -1 || (startingCol - i) - 1 != -1) || (((startingRow - i) + 3)  != 5 || (startingCol - i) + 3 != 6))
                {

                    if ((board[(startingRow - i) - 1][(startingCol - i) - 1] != 'X' || board[(startingRow - i) - 1][(startingCol - i) - 1] != 'O') && (board[(startingRow - i) + 4][(startingCol - i) + 4]) != 'X' || board[(startingRow - i) + 4][(startingCol - i) + 4])
                    {

                        if (board[startingRow - i][(startingCol - i) - 1] != '_' || board[(startingRow - i) + 5][(startingCol - i) + 4] != '_')
                        {

                            if (xAmount == 3)
                            {
                                if (board[(startingRow - i) - 1][(startingCol - i) - 1] != 'X' || board[(startingRow - i) - 1][(startingCol - i) - 1] != 'O' || board[startingRow - i][(startingCol - i) - 1] != '_')
                                {

                                    startingCol += 4;
                                    return (startingCol);

                                }
                                else
                                {

                                    if (board[(startingRow - i) + 4][(startingCol - i) + 4] != 'X' || board[(startingRow - i) + 4][(startingCol - i) + 4] != 'O' || board[(startingRow - i) + 5][(startingCol - i) + 4] != '_')
                                    startingCol -= 1;
                                    return (startingCol);

                                }

                            }
                            else
                            {

                                if (board[(startingRow - i) - 1][(startingCol - i) - 1] != 'X' || board[(startingRow - i) - 1][(startingCol - i) - 1] != 'O' || board[startingRow - i][(startingCol - i) - 1] != '_')
                                {

                                    startingCol += 4;
                                    return (startingCol);

                                }
                                else
                                {

                                    if (board[(startingRow - i) + 4][(startingCol - i) + 4] != 'X' || board[(startingRow - i) + 4][(startingCol - i) + 4] != 'O' || board[(startingRow - i) + 5][(startingCol - i) + 4] != '_')
                                        startingCol -= 1;
                                    return (startingCol);

                                }
                            }

                        }                        

                    }

                }

            }

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


    for (int checkV = 6; checkV >= 0; checkV--)
    {
        if (xAmountH >= 4 || oAmountH >= 4)
        {

            checkV = -1;

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


            for (int checkH = 7; checkH >= 0; checkH--)
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
                else if (board[checkV][checkH] == '_')
                {

                    xAmountH = 0;
                    oAmountH = 0;

                }

            }

        }

    }

    if (xAmountH >= 4 || oAmountH >= 4)
    {

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
                else if (board[checkV][checkH] == '_')
                {

                    xAmountV = 0;
                    oAmountV = 0;

                }

            }

        }
    }

    if (xAmountV >= 4 || oAmountV >= 4)
    {

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

                else if (board[startingRow - i][startingCol - i] == 'O')
                {

                    oAmountDL += 1;
                    xAmountDL = 0;

                }
                else if (board[startingRow - i][startingCol - i] == '_')
                {

                    oAmountDL = 0;
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

                else if (board[startingRow - i][startingCol - i] == 'O')
                {

                    oAmountDR += 1;
                    xAmountDR = 0;

                }
                else if (board[startingRow - i][startingCol - i] == '_')
                {

                    oAmountDR = 0;
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

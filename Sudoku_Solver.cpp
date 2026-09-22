#include <iostream>
using namespace std;

void printBoard(int board[9][9])
{
    cout << "\nSolved Sudoku:\n\n";
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
            cout << board[row][col] << " ";
        cout << endl;
    }
}

bool isSafe(int board[9][9], int row, int col, int num)
{
    for (int x = 0; x < 9; x++)
        if (board[row][x] == num) return false;

    for (int x = 0; x < 9; x++)
        if (board[x][col] == num) return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku(int board[9][9])
{
    int row = -1, col = -1;
    bool emptyCell = false;

    for (int i = 0; i < 9 && !emptyCell; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                emptyCell = true;
                break;
            }
        }
    }

    if (!emptyCell) return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int board[9][9] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "==============================\n";
    cout << "       SUDOKU SOLVER\n";
    cout << "   CodeAlpha C++ Task 3\n";
    cout << "==============================\n";

    cout << "\nOriginal Sudoku:\n\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }

    if (solveSudoku(board))
        printBoard(board);
    else
        cout << "\nNo solution exists for this Sudoku.\n";

    return 0;
}

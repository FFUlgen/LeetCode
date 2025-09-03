#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>

/*
36. Valid Sudoku - Explanation
    
    Description:
        You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

        Each row must contain the digits 1-9 without duplicates.
        Each column must contain the digits 1-9 without duplicates.
        Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
        Return true if the Sudoku board is valid, otherwise return false

        Note: A board does not need to be full or be solvable to be valid.

    Constraints:

        board.length == 9
        board[i].length == 9
        board[i][j] is a digit 1-9 or '.'.
*/

// Hash Set - One Pass
// Time complexity :O(n^2) Space complexity : O(n^2)
bool isValidSudoku1(std::vector<std::vector<char>>& board) {
    std::unordered_map<int, std::unordered_set<char>> rows, columns;
    std::map<std::pair<int, int>, std::unordered_set<char>> squares;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.') continue;
            
            std::pair<int, int> squareKey = { i / 3, j / 3 };

            if (rows[i].contains(board[i][j]) || columns[j].contains(board[i][j]) || squares[squareKey].contains(board[i][j])) return false;

            rows[i].insert(board[i][j]);
            columns[j].insert(board[i][j]);
            squares[squareKey].insert(board[i][j]);
        }
    }
    return true;
}

// Bitmask
// Time complexity :O(n^2) Space complexity : O(n)
bool isValidSudoku2(std::vector<std::vector<char>>& board) {
    int rows[9] = { 0 };
    int cols[9] = { 0 };
    int squares[9] = { 0 };

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') continue;

            int val = board[r][c] - '1';

            if ((rows[r] & (1 << val)) || (cols[c] & (1 << val)) ||
                (squares[(r / 3) * 3 + (c / 3)] & (1 << val))) {
                return false;
            }

            rows[r] |= (1 << val);
            cols[c] |= (1 << val);
            squares[(r / 3) * 3 + (c / 3)] |= (1 << val);
        }
    }
    return true;
}


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<bool>> rowUsed, colUsed, boxUsed;

    int getBoxIndex(int row, int col) {
        return (row / 3) * 3 + col / 3;
    }

    bool solve(vector<vector<char>>& board, int pos, vector<pair<int, int>>& emptyCells) {
        if (pos >= emptyCells.size()) return true;

        int row = emptyCells[pos].first;
        int col = emptyCells[pos].second;
        for (char num = '1'; num <= '9'; num++) {
            int numVal = num - '0';
            int boxIdx = getBoxIndex(row, col);

            if (!rowUsed[row][numVal] && !colUsed[col][numVal] && !boxUsed[boxIdx][numVal]) {
                board[row][col] = num;
                rowUsed[row][numVal] = colUsed[col][numVal] = boxUsed[boxIdx][numVal] = true;

                if (solve(board, pos + 1, emptyCells)) return true;

                board[row][col] = '.';
                rowUsed[row][numVal] = colUsed[col][numVal] = boxUsed[boxIdx][numVal] = false;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rowUsed.assign(9, vector<bool>(10, false));
        colUsed.assign(9, vector<bool>(10, false));
        boxUsed.assign(9, vector<bool>(10, false));

        vector<pair<int, int>> emptyCells;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.emplace_back(i, j);
                } else {
                    int num = board[i][j] - '0';
                    rowUsed[i][num] = true;
                    colUsed[j][num] = true;
                    boxUsed[getBoxIndex(i, j)][num] = true;
                }
            }
        }

        solve(board, 0, emptyCells);
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    s.solveSudoku(board);
    for (const auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
}

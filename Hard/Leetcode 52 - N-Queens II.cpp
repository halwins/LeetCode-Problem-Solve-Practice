#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Kiểm tra xem có thể đặt hậu tại (row, col) không
    bool isValid(const vector<vector<int>> &board, int row, int col)
    {
        int n = board.size();

        // Kiểm tra cột
        for (int i = 0; i < row; i++)
            if (board[i][col] == 1)
                return false;

        // Kiểm tra chéo trái trên
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;

        // Kiểm tra chéo phải trên
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    void backtrack(vector<vector<int>> &board, vector<vector<vector<int>>> &result, int row)
    {
        int n = board.size();
        if (row == n)
        {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(board, row, col))
            {
                board[row][col] = 1;
                backtrack(board, result, row + 1);
                board[row][col] = 0;
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        vector<vector<vector<int>>> result;
        vector<vector<int>> board(n, vector<int>(n, 0));
        backtrack(board, result, 0);
        return result.size();
    }
};


int main() {
    return 0;
}
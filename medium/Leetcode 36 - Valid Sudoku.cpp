#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check valid in row
        for (int i = 0; i < board.size(); i++) {
            vector<char> map;
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.')
                    continue;
                if (find(map.begin(), map.end(), board[i][j]) != map.end())
                    return false;
                map.push_back(board[i][j]);
            }
        }

        // check valid column
        for (int i = 0; i < board.size(); i++) {
            vector<char> map;

            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] == '.')
                    continue;
                if (find(map.begin(), map.end(), board[j][i]) != map.end())
                    return false;
                map.push_back(board[j][i]);
            }
        }

        // check valid sub-boxes
        for (int i = 0; i < 9; i++) {
            vector<char> map;
            int start_r = (i / 3) * 3;
            int start_c = i % 3 * 3;
            for (int j = start_r; j < start_r + 3; j++) {
                for (int k = start_c; k < start_c + 3; k++) {
                    if (board[j][k] == '.')
                        continue;
                    if (find(map.begin(), map.end(), board[j][k]) != map.end())
                        return false;
                    map.push_back(board[j][k]);
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
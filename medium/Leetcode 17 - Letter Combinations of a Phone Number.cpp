#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, vector<char>> num_digit_map = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9',
             {'w', 'x', 'y', 'z'}}};

        vector<string> result;
        for (char c : digits)
        {
            vector<string> tmp = result;
            if (tmp.empty())
                tmp.push_back("");
            result.clear();
            for (char c1 : num_digit_map[c])
            {
                for (string s : tmp)
                    result.push_back(s + c1);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    string input;
    cin >> input;
    vector<string> result = s.letterCombinations(input);
    for (auto s : result)
        cout << s << "\t";
    return 0;
}
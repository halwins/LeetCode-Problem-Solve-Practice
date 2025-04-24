#include <iostream>
#include <vector>
using namespace std;

/**
 * Problem: Zigzag Conversion
 *
 * Given a string `s` and an integer `numRows`, rearrange `s` into a zigzag pattern on a given number of rows.
 * Then read the pattern line by line and return the concatenated result.
 *
 * Example:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Explanation:
 * The zigzag pattern for 3 rows is:
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * Assumptions:
 * - The input string `s` consists of only printable ASCII characters.
 * - 1 <= numRows <= 1000
 * - 1 <= s.length() <= 1000
 *
 * Return:
 * - A string representing the zigzag-converted version of the input string.
 */

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
            return s;
        string result = "";
        vector<int> map(s.size(), 0);
        bool isInc = true;
        int index = 1;
        for (int i = 0; i < s.size(); i++)
        {
            map[i] = index;
            if (isInc)
            {
                index++;
                if (index == numRows)
                {
                    isInc = !isInc;
                }
            }
            else
            {
                index--;
                if (index == 1)
                {
                    isInc = !isInc;
                }
            }
        }
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < s.size(); j++)
                if (i == map[j])
                    result += s[j];
        }
        return result;
    }
    // Solution 1:
    // Simulate the zigzag pattern by storing characters row-by-row in a vector of strings.
    // Traverse the string while moving the current row index up and down as needed to simulate zigzag motion.
    // Time complexity: O(n), where n is the length of the input string.
    // Space complexity: O(n), to store the intermediate rows.
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(min(numRows, int(s.length())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string &row : rows)
            result += row;

        return result;
    }
};

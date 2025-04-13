#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * Problem: Roman to Integer
 *
 * Given a string s representing a Roman numeral, convert it to an integer.
 *
 * Roman numerals are represented by seven symbols: I, V, X, L, C, D, and M.
 * Each symbol has a fixed integer value:
 *   I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
 *
 * Rules:
 * - Numerals are usually written largest to smallest from left to right.
 * - However, if a smaller numeral comes before a larger one, it is subtracted.
 *   For example: IV = 4 (5 - 1), IX = 9 (10 - 1)
 *
 * Assumptions:
 * - The input is guaranteed to be a valid Roman numeral within the range [1, 3999].
 *
 * Return:
 * - An integer corresponding to the Roman numeral.
 */

class Solution
{
public:
    // Solution 1:
    // Use a hash map to store the integer values of Roman numeral characters.
    // Traverse the string from left to right. For each character:
    // - If the current value is less than the next value, subtract it from the result (e.g., IV = 5 - 1).
    // - Otherwise, add the value to the result.
    // This logic handles both regular and subtractive notation in Roman numerals.
    // Time complexity: O(n), where n is the length of the input string.
    // Space complexity: O(1), using only a fixed-size hash map.
    int romanToInt(string s)
    {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (i < s.length() - 1)
            {
                if (roman[s[i]] < roman[s[i + 1]])
                {
                    result -= roman[s[i]];
                }
                else
                    result += roman[s[i]];
            }
            else
                result += roman[s[i]];
        }
        return result;
    }
};
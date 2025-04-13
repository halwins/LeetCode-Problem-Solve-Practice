#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Problem: Longest Palindromic Substring
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 * Assumptions:
 * - The input string s consists of only printable ASCII characters.
 * - The length of s is between 1 and 1000.
 *
 * Return:
 * - A string representing the longest substring of s that is a palindrome.
 */

class Solution
{
public:
    // Solution 1:
    // Expand Around Center approach to find the longest palindromic substring.
    // For each character in the string, expand outward to check for both odd and even length palindromes.
    // This approach considers each character (and pair) as the potential center of a palindrome.
    // Time complexity: O(n^2) due to nested expansions for each character.
    // Space complexity: O(1) since it uses a constant amount of extra space.
    string longestPalindrome(string s)
    {
        if (s.empty() || s.length() == 1)
            return s;
        int left, right;
        string result = "";
        int result_len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            left = right = i;
            while (left > 0 && s[left] == s[i])
                left--;
            while (right < s.length() && s[right] == s[i])
                right++;
            while (left > 0 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (right - left - 1 >= result_len)
            {
                result_len = right - left - 1;
                result = s.substr(left + 1, right - left - 1);
            }
        }
        return result;
    }
};
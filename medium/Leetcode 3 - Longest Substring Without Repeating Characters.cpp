#include <iostream>
#include <string>
#include <set>
using namespace std;

/**
 * Problem: Longest Substring Without Repeating Characters
 *
 * Description:
 *   Given a string `s`, return the length of the longest substring
 *   that contains no repeating characters.
 *
 * Constraints:
 *   - The input string may contain any printable ASCII characters.
 *   - The string length can range from 0 to 10^5.
 *
 * Return:
 *   An integer representing the length of the longest substring
 *   without duplicate characters.
 */

class Solution
{
public:
    // Brute Force
    //   Iterate through all possible substrings starting from index i.
    //   Use a set to keep track of characters we've seen so far.
    //   If a duplicate character is found, break the inner loop.
    //   Otherwise, update the result with the current substring length.
    // Time Complexity: O(n^2)
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            set<char> seen;
            for (int j = i; j < n; j++)
            {
                if (seen.count(s[j]))
                    break;
                seen.insert(s[j]);
                result = max(result, j - i + 1);
            }
        }

        return result;
    }
    // Sliding Window
    //   Use two pointers (left and right) to define a sliding window
    //   that contains only unique characters.
    //   If a duplicate character is found, move the left pointer
    //   to shrink the window until the character is removed.
    //   Update the result with the size of the current window.
    // Time Complexity: O(n)
    int lengthOfLongestSubstring1(string s)
    {
        set<char> charset;
        int left = 0;
        int result = 0;

        for (int right = 0; right < s.length(); right++)
        {
            while (charset.count(s[right]))
            {
                charset.erase(s[left]);
                left++;
            }
            charset.insert(s[right]);
            result = max(result, right - left + 1);
        }

        return result;
    }
};
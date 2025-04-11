#include <iostream>
#include <string>
#include <set>
using namespace std;

/**
 * Problem: Palindrome Number
 *
 * Description:
 *   Given an integer x, return true if x is a palindrome, and false otherwise.
 *   An integer is a palindrome when it reads the same forward and backward.
 *
 *   For example:
 *     - 121 is a palindrome
 *     - -121 is not a palindrome (reads 121- backward)
 *     - 10 is not a palindrome (reads 01 backward)
 *
 * Constraints:
 *   - -2^31 <= x <= 2^31 - 1
 *
 * Return:
 *   A boolean value:
 *     - true if x is a palindrome
 *     - false otherwise
 */

class Solution
{
public:
    // Two-pointer
    // If the input number is negative, return false because negative numbers cannot be palindromes (due to the '-' sign)
    // Convert the integer to a string for easy character comparison
    // Initialize two pointers: one at the start and one at the end of the string
    // Move both pointers toward the center, comparing characters at each step
    // If any pair of characters differ, return false
    // If all characters match (or pointers cross), return true

    bool isPalindrome(int x)
    {
        if (x < 0 || x % 10 == 0)
            return false;
        string s = to_string(x);
        int l = 0, r = s.length() - 1;
        while (l < r)
        {
            if (s[l] & s[r])

                return false;

            l--;
            r--;
        }
        return true;
    }

    // Reverse half of number
    // If the input number is negative, return false because negative numbers cannot be palindromes (due to the '-' sign)
    // Reverse the last half of number
    // If the first half == the last halft or the first half == the last half / 10 so return true else false
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }
        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return (x == sum || x == sum / 10);
    }
};
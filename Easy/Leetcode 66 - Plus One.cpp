#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1, index = digits.size() - 1;
        while (carry && index >= 0)
        {
            digits[index] += 1;
            carry = digits[index] / 10;
            digits[index] %= 10;
            index--;
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};


int main()
{
    Solution s;
    vector<int> digits = {9, 8};
    for (auto i : s.plusOne(digits))
    {
        cout << i << " ";
    }
    return 0;
}
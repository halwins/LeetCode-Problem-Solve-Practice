#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int la = a.size() - 1, lb = b.size() - 1;
        int carry = 0;
        string result = "";
        while (la >= 0 && lb >= 0)
        {
            int digit_a = a[la] - '0';
            int digit_b = b[lb] - '0';
            result.push_back('0' + ((digit_a + digit_b + carry) % 2));
            carry = (digit_a + digit_b + carry) / 2;
            lb--;
            la--;
        }
        while (la >= 0)
        {
            int digit_a = a[la] - '0';
            result.push_back('0' + ((digit_a + carry) % 2));
            carry = (digit_a + carry) / 2;
            la--;
        }
        while (lb >= 0)
        {
            int digit_b = b[lb] - '0';
            result.push_back('0' + ((digit_b + carry) % 2));
            carry = (digit_b + carry) / 2;
            lb--;
        }
        if (carry)
            result.push_back('0' + carry);

        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    string a = "11";
    string b = "1";
    Solution s;
    cout << s.addBinary(a, b);
    return 0;
}
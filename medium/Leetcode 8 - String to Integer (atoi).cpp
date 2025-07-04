#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long result = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return sign * result;
    }
};

int main()
{
    Solution s;
    cout << "Enter your number: ";
    string input;
    cin >> input;
    cout << s.myAtoi(input);
    return 0;
}
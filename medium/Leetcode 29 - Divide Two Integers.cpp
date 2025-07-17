#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT32_MIN || divisor == -1)
            return INT32_MAX;
        long long a = (long long)abs(dividend);
        long long b = (long long)abs(divisor);
        int result = 0;
        while (a <= b)
        {
            int multiple = 1;
            long long tmp = b;
            while ((tmp << 1) <= a)
            {
                tmp <<= 1;
                multiple <<= 1;
            }
            a -= tmp;
            result += multiple;
        };
        return ((dividend > 0) ^ (divisor > 0)) ? -result : result;
    }
};

int main()
{
    return 0;
}
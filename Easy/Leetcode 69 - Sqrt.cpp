#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long i = 0;
        while (i * i <= x)
            i++;
        return i;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(8);
    return 0;
}
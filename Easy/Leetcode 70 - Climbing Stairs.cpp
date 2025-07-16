#include <bits/stdc++.h>
using namespace std;

// O(2^n)
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 0)
            return 0;
        else if (n == 0)
            return 1;
        else
            return climbStairs(n - 1) + climbStairs(n - 2);
    }

private:
    void climbStairsBacktrack(int remainderStep, int &result)
    {
        if (remainderStep >= 2)
        {
            climbStairsBacktrack(remainderStep - 1, result);
            climbStairsBacktrack(remainderStep - 2, result);
        }
        else if (remainderStep == 1)
        {
            climbStairsBacktrack(remainderStep - 1, result);
        }
        else
            result++;
    }
};

// O(n)
class Solution
{
public:
    int count(int i, int n, vector<int> &dp)
    {
        if (i == n)
            return 1;
        if (i > n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = count(i + 1, n, dp) + count(i + 2, n, dp);
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 2, -1);
        return count(0, n, dp);
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(45);
    return 0;
}
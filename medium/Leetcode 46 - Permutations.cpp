#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void backtrack(vector<vector<int>> &result, vector<int> &current, const vector<int> &nums)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (find(current.begin(), current.end(), nums[i]) == current.end())
            {
                current.push_back(nums[i]);
                backtrack(result, current, nums);
                current.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current, nums);
        return result;
    }
};

int main()
{
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#include <vector>
using namespace std;

class Solution
{
private:
    void backtrack(vector<int> &candidates, int target, vector<int> &current, vector<vector<int>> &result, int start)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] <= target)
            {
                current.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], current, result, i);
                current.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, current, result, 0);
        return result;
    }
};

int main()
{
    return 0;
}
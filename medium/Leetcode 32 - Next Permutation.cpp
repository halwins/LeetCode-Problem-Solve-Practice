#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = -1;
        for (int j = nums.size() - 2; j >= 0; j--)
            if (nums[j] < nums[j + 1])
            {
                i = j;
                break;
            }
        if (i == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int j = nums.size() - 1; j > i; j--)
        {
            if (nums[j] > nums[i])
            {
                swap(nums[j], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
int main()
{
    Solution s;
    vector<int> nums = {4, 2, 0, 2, 3, 2, 0};
    s.nextPermutation(nums);
    for (auto i : nums)
        cout << i << "\t";
    return 0;
}
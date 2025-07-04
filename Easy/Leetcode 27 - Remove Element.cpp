#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // solution 1: Time: O(n) - Space : O(k)
    int removeElement(vector<int> &nums, int val)
    {
        vector<int> result;
        for (int num : nums)
            if (num != val)
                result.push_back(num);
        nums = result;
        return nums.size();
    }
    // Solution 2: Time: O(n) - Space: O(1)
    int removeElement(vector<int> &nums, int val)
    {
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[index++] = nums[i];
        return index + 1;
    }
};

int main()
{
    return 0;
}
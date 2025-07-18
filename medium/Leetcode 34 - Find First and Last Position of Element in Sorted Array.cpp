#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                int l = mid, h = mid;
                while (nums[l] == nums[mid])
                    l--;
                while (nums[h] == nums[mid])
                    h--;
                return {l + 1, h - 1};
            }
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return {-1, -1};
    }
};

int main()
{
    return 0;
}
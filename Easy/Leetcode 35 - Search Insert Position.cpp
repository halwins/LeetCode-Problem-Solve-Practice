#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int tail = nums.size() - 1, head = 0, mid = 0;
        while (head < tail)
        {
            mid = head + (tail - head) / 2;
            if (nums[mid] > target)
                tail = mid;
            else if (nums[mid] < target)
                head = mid + 1;
            else
                break;
        }
        return mid + 1;
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    Solution s;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}
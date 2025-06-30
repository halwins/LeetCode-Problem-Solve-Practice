#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int read = 1, write = 0;
        while (read < nums.size())
        {
            if (nums[read] != nums[write])
            {
                nums[++write] = nums[read];
            }
            read++;
        }
        return write + 1;
    }
};

int main()
{
    Solution s;
    vector<int> numbers = {1, 2, 4, 6, 6, 9};
    cout << s.removeDuplicates(numbers);
    return 0;
}
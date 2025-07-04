#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int head = 0, tail = height.size() - 1;
        int max = 0, curr_amount = 0;
        while (head < tail)
        {
            curr_amount = (tail - head) * min(height[head], height[tail]);
            max = (max < curr_amount) ? curr_amount : max;
            cout << "Head: " << head << " - Tail: " << tail << " - Result: " << max << endl;
            if (height[head] < height[tail])
                head++;
            else
                tail--;
        }
        return max;
    }
};

int main()
{
    vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << "Input is: ";
    for (int i = 0; i < input.size(); i++)
        cout << input[i] << "\t";
    cout << endl
         << "Result is: " << s.maxArea(input);
    return 0;
}
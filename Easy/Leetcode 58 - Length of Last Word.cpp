#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int last = s.size() - 1;
        while (s[last] == ' ')
            last--;

        for (int i = last; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                return last - i;
            }
        }
        return last + 1;
    }
};

int main()
{
    Solution s;
    string input = "luffy is still joyboy";
    cout << s.lengthOfLastWord(input);
    return 0;
}
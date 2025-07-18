#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string result;

        while (n > 0)
        {
            if (result.empty())
            {
                result.push_back('1');
                n--;
                continue;
            }
            cout << "n = " << n << ": " << result << endl;

            int l = 0, h;
            string tmp = "";
            while (l < result.size())
            {
                h = l;
                while (h < result.size() && result[h] == result[l])
                    h++;
                tmp.push_back('0' + (h - l ));
                tmp.push_back(result[l]);
                l = h;
            }
            result = tmp;
            n--;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(4);
    return 0;
}
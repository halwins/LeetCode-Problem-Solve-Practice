#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int size = needle.size();
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack.size() - 1 < size)
                return -1;
            if (haystack.substr(i, size) == needle)
                return i;
        }
    }
};

int main()
{
    return 0;
}
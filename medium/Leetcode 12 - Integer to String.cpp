#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        std::vector<std::pair<string, int>> roman = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};

        string result;
        int count_tmp;
        for (auto pair : roman)
        {
            if (num / pair.second != 0)
            {
                count_tmp = num / pair.second;
                for (int i = 0; i < count_tmp; i++)
                {
                    result += pair.first;
                }
                num %= pair.second;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
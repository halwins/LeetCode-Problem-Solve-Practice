#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        int i = 0, j = 0;
        int starIdx = -1, sTempIdx = -1; 

        while (i < sLen) {
            if (j < pLen && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (j < pLen && p[j] == '*') {
                starIdx = j;
                sTempIdx = i;
                j++;
            }

            else if (starIdx != -1) {
                j = starIdx + 1;
                i = sTempIdx + 1; 
                sTempIdx++; 
            }
            else {
                return false;
            }
        }

        while (j < pLen && p[j] == '*') {
            j++;
        }

        return j == pLen;
    }
};
int main()
{
    return 0;
}
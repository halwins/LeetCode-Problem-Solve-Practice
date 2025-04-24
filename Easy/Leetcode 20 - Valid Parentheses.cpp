#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    bool isValid(string s)
    {
        if (s.size() % 2) return false;
        stack<char> stack;

        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
                continue;
            }
            if (stack.empty()) return false;
            if (c == ')' && stack.top() != '(')
                return false;
            else if (c == '}' && stack.top() != '{')
                return false;
            else if (c == ']' && stack.top() != '[')
                return false;
            stack.pop();
        }
        return stack.empty();
    }
};
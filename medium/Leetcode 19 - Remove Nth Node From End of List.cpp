#include <bits/stdc++.h>
using namespace std;
// ================================================
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// ================================================
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *high = head, *low = result;
        while (n > 0 && high)
        {
            high = high->next;
            n--;
        }
        while (high && high->next)
        {
            low = low->next;
            high = high->next;
        }
        if (low->next)
            low->next = low->next->next;
        return result;
    }
};

int main()
{
    return 0;
}
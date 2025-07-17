#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *l, *r;
        l = head;
        while (l && l->next)
        {
            r = l->next;
            l->val = l->val + r->val;
            r->val = l->val - r->val;
            l->val = l->val - r->val;

            l = r->next;
        }
        return head;
    }
};

int main()
{
    return 0;
}
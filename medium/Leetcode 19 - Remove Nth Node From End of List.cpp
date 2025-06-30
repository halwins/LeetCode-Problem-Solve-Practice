#include <iostream>
#include <vector>
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head || n <= 0)
            return head;

        ListNode *result = nullptr;
        ListNode *ptr = head;

        while (n - 1 > 0 && ptr != nullptr)
        {
            ptr = ptr->next;
            n--;
        }
        if (n != 1)
            return head;
        result = head;
        while (head != nullptr)
        {
            if (ptr == nullptr)
            {
                head = head->next;
                continue;
            }
        }
    }
};
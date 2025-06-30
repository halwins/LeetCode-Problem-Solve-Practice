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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *head = nullptr, *tail = nullptr;

        while (list1 && list2)
        {
            if (!head)
            {
                if (list1->val < list2->val)
                {
                    head = list1;
                    list1 = list1->next;
                }
                else
                {
                    head = list2;
                    list2 = list2->next;
                }
                tail = head;
                continue;
            }
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        while (list1)
        {
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        }
        while (list2)
        {
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }
        return head;
    }
    ListNode *mergeTwoListCleanCode(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        if (list1->val < list2->val)
        {
            head = tail = list1;
            list1 = list1->next;
        }
        else
        {
            head = tail = list2;
            list2 = list2->next;
        }

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;

        return head;
    }
};
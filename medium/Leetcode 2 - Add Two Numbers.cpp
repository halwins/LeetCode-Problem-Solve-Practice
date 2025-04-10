#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Problem: Two Sum
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 *
 * Assumptions:
 *   - You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Return:
 *   - Add the two numbers and return the sum as a linked list.
 */

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
    // Solution 1:
    // Traverse to the end of both linked lists, then add the corresponding digits together.
    // If there is a carry, add it to the next digit.
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *current = &dummy;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = carry;

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            current->next = new ListNode(sum % 10);
            current = current->next;
            carry = sum / 10;
        }
        return dummy.next;
    }
};
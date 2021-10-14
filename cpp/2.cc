/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res, *beg;
        res = beg = nullptr;
        int carry = 0;
        for (; l1 != nullptr && l2 != nullptr;
            l1 = l1->next, l2 = l2->next) {
            int val = l1->val + l2->val + carry;
            if (val >= 10) {
                val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            if (res == nullptr) {
                res = beg = new ListNode(val);
            } else {
                res->next = new ListNode(val);
                res = res->next;
            }

        }
        for (; l1 != nullptr; l1 = l1->next, res = res->next) {
            int val = l1->val + carry;
            if (val >= 10) {
                val -=10;
                carry = 1;
            } else {
                carry = 0;
            }
            res->next = new ListNode(val);
        }
        for (; l2 != nullptr; l2 = l2->next, res = res->next) {
            int val = l2->val + carry;
            if (val >= 10) {
                val -=10;
                carry = 1;
            } else {
                carry = 0;
            }
            res->next = new ListNode(val);
        }
        if (carry != 0) {
            res->next = new ListNode(1);
        }
        return beg;
    }
};

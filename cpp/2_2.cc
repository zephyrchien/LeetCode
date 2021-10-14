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
        while (l1 != nullptr || l2 != nullptr) {
            const int x1 = l1 ? l1->val : 0;
            const int x2 = l2 ? l2->val : 0;
            int sum = x1 + x2 + carry;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            if (res == nullptr) {
                beg = res = new ListNode(sum);
            } else {
                res->next = new ListNode(sum);
                res = res->next;
            }
        }
        if (carry) res->next = new ListNode(1);
        return beg;
    }
};

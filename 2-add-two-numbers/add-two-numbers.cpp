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
        ListNode* tmp1 = l1; ListNode* tmp2 = l2; 
        ListNode* rNode = new ListNode(-1);
        ListNode* rNodeCopy = rNode;
        int carry = 0;

        while (tmp1 != nullptr || tmp2 != nullptr) {
            int val1 = 0, val2 = 0;
            if (tmp1 != nullptr) {
                val1 = tmp1->val;
                tmp1 = tmp1->next;
            }

            if (tmp2 != nullptr) {
                val2 = tmp2->val;
                tmp2 = tmp2->next;
            }

            ListNode* sumNode = new ListNode((carry+val1+val2)%10);
            carry = (carry+val1+val2)/10;
            rNodeCopy->next = sumNode;
            rNodeCopy = rNodeCopy->next;
        }

        if (carry != 0) {
            ListNode* sumNode = new ListNode(carry);
            rNodeCopy->next = sumNode;
            rNodeCopy = rNodeCopy->next;
        }

        return rNode->next;
    }
};
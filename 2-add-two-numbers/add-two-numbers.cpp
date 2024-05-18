class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* rNodeCopy = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = carry+val1+val2;

            rNodeCopy->next = new ListNode(sum%10);
            carry = sum/10;
            rNodeCopy = rNodeCopy->next;

            if (l1 != nullptr) l1=l1->next;
            if (l2 != nullptr) l2=l2->next;
        }

        if (carry> 0) {
            rNodeCopy->next = new ListNode(carry);
        }

        return dummy.next;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        int step = n;
        while (step>0) {
            step--;
            fast=fast->next;
        }

        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* slow = head;
        while (fast->next != nullptr) {
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }
};
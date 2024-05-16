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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp=head;
        int cnt=0;

        while (tmp != nullptr) {
            cnt++;
            tmp=tmp->next;
        }

        tmp=head;
        if (cnt == n) {
            ListNode* newHead = tmp->next;
            delete head;
            return newHead;
        }

        int skip = cnt-n;
        while (skip>0) {
            skip--;
            if (skip==0) break;
            tmp=tmp->next;
        }

        ListNode* delNode = tmp->next;
        tmp->next = tmp->next->next;
        delete delNode;

        return head;
    }
};
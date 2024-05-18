/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        if (head->next == nullptr) 
            return (head->next==head) ? true:false;

        ListNode* tmp = head;
        unordered_set<ListNode*> st;

        while (tmp!=nullptr) {
            if (st.find(tmp)!=st.end()) {
                return true;
            } else {
                st.insert(tmp);
            }
            tmp=tmp->next;
        }

        return false;
    }
};
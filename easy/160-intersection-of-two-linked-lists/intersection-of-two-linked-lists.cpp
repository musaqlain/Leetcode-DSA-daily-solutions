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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        ListNode *listA = headA;
        ListNode *listB = headB;

        while (listA) {
            set.insert(listA);
            listA = listA->next;
        }

        while (listB) {
            if (set.find(listB) != set.end()) return listB;
            listB = listB->next;
        }

        return NULL;
    }
};
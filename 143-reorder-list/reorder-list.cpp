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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        // find middle of the List
        // using fast and slow algorithm.
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // create two halves of the List and reverse the second Half
        ListNode* secondHalf = reverseList(slow->next);
        slow->next = nullptr;

        ListNode* firstHalf = head;

        // Merge the two Halves, alternatively
        while (firstHalf != nullptr && secondHalf != nullptr) {
            ListNode* firstNext = firstHalf->next;
            ListNode* secondNext = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = firstNext;

            firstHalf = firstNext;
            secondHalf = secondNext;
        }
    }
};
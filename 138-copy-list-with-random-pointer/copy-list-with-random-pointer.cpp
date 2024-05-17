/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        // insert copied node inbetween
        Node* tmp = head;
        while (tmp != nullptr) {
            Node* newNode = new Node(tmp->val);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp=tmp->next->next;
        }

        // connect random pointers
        tmp=head;
        while (tmp!=nullptr) {
            if (tmp->random != nullptr) {
                tmp->next->random = tmp->random->next;
            }
            tmp=tmp->next->next;
        }

        // connect next pointers and extract the newly created list
        tmp=head;
        Node* rNode = new Node(-1);
        Node* res = rNode;
        while (tmp != nullptr && res != nullptr) {
            res->next = tmp->next;
            tmp->next = tmp->next->next;
            res = res->next;
            tmp=tmp->next;
        }

        return rNode->next;
    }
};
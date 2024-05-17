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
        unordered_map<Node*, Node*> mp;
        Node* tmp = head;

        while (tmp != nullptr) {
            Node* newNode = new Node(tmp->val);
            mp[tmp] = newNode;
            tmp = tmp->next;
        }

        tmp=head;
        while(tmp != nullptr) {
            Node* curr = mp[tmp];
            Node* nexx = mp[tmp->next];
            Node* rann = mp[tmp->random];
            
            curr->next = nexx;
            curr->random = rann;

            tmp = tmp->next;
        }

        return mp[head];
    }
};
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

        // Step 3: Separate the lists
        tmp = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        while (tmp != nullptr && copy != nullptr) {
            tmp->next = tmp->next->next;
            if (copy->next != nullptr) {
                copy->next = copy->next->next;
            }
            tmp = tmp->next;
            copy = copy->next;
        }

        return newHead;;
    }
};
class LRUCache {
private:
    class Node {
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;
    int cap;


public:
    LRUCache(int capacity) {
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
        cap = capacity;
    }

    Node* addNode(int key_, int val_) {
        Node* capt = head->next;
        Node* newNode = new Node(key_, val_);

        head->next = newNode;
        capt->prev = newNode;
        newNode->next = capt;
        newNode->prev = head;
        return newNode;
    }

    void deleteNode(Node* oldNode) {
        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;
        delete oldNode;
    }

int get(int key_) {
  if (mp.find(key_) != mp.end()) {
    Node* resnode = mp[key_];
    int res = resnode->val;
    // Move the node to the head without modifying the hash map
    resnode->prev->next = resnode->next;
    resnode->next->prev = resnode->prev;
    resnode->next = head->next;
    resnode->prev = head;
    head->next->prev = resnode;
    head->next = resnode;
    return res;
  }

  return -1;
}

    void put(int key_, int val_) {
        if (mp.find(key_) !=mp.end()) {
            Node* NodeAdd = mp[key_];
            mp.erase(key_);
            deleteNode(NodeAdd);
        }
        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = addNode(key_, val_);
        mp[key_] = newNode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
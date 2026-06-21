class Node {
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key,int val) {
        this->key = key;
        this->val = val;
        prev = next = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> um;
    Node* head;
    Node* tail;
    int size;
    int cap;
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node* node) {
        Node* prev = node->prev;
        prev->next = node->next;
        node->next->prev = prev;
        delete node;
    }
    void insertatbegin(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->next = next;
        next->prev = node;
        node->prev = head;
    }
    void deletelastnode() {
        Node* prev = tail->prev;
        prev->prev->next = tail;
        tail->prev = prev->prev;
        delete prev;
    }
    int get(int key) {
        if(um.find(key) == um.end()) return -1;
        int val = um[key]->val;

        deleteNode(um[key]);
        um.erase(key);
        Node* node = new Node(key,val);
        insertatbegin(node);
        um[key] = node;
        return val;
    }
    
    void put(int key, int value) {
        if(um.find(key) != um.end()) {
            deleteNode(um[key]);
            um.erase(key);
            size--;
        }
        else if(size == cap) {
            Node* prev = tail->prev;
            int ky = prev->key;
            deletelastnode();
            um.erase(ky);
            size--;
        }
        Node* node = new Node(key,value);
        insertatbegin(node);
        um[key] = node;
        size++;
        return;
    }
};

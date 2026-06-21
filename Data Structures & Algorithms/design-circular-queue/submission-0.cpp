class Node {
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class MyCircularQueue {
public:
    Node* head;
    Node* tail;
    int size;
    int cap;
    MyCircularQueue(int k) {
        size = 0;
        cap = k;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    bool enQueue(int value) {
        if(size == cap) return false;

        Node* node = new Node(value);
        Node* prev = tail->prev;

        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;

        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        Node* tmp = head->next;
        head->next = tmp->next;
        tmp->next->prev = head;
        delete tmp;
        size--;
        return true;
    }
    
    int Front() {
        if(head->next == tail) return -1;
        return head->next->val;
    }
    
    int Rear() {
        if(tail->prev == head) return -1;
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
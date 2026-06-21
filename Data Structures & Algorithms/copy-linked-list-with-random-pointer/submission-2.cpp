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
        if(head == NULL) return NULL;

        unordered_map<Node*,Node*> um;
        Node* curr = head;
        while(curr != NULL) {
            Node* tmp = new Node(curr->val);
            um[curr] = tmp;
            curr = curr->next;
        }
        for(auto &[cr,cp]:um) {
            cp->next = cr->next ? um[cr->next] : NULL;
            cp->random = cr->random ? um[cr->random] : NULL;
        }
        return um[head];
    }
};

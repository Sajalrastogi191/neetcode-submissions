class Node {
    public:
    vector<Node*> child;
    bool isend;
    Node() {
        isend = false;
        child.resize(26,NULL);
    }
};
class PrefixTree {
public:
    Node* root;

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char &ch:word) {
            if(curr->child[ch-'a'] == NULL) {
                Node* node = new Node();
                curr->child[ch-'a'] = node;
            }
            curr = curr->child[ch-'a'];
        }
        curr->isend = true;
        return;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char &ch:word) {
            if(curr->child[ch-'a'] == NULL) {
                return false;
            }
            curr = curr->child[ch-'a'];
        }
        return curr->isend == true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char &ch:prefix) {
            if(curr->child[ch-'a'] == NULL) {
                return false;
            }
            curr = curr->child[ch-'a'];
        }
        return true;
    }
};

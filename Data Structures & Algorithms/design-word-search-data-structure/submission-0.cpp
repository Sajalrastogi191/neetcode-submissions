class Node{
    public:
    vector<Node*> child;
    bool isend;
    Node() {
        child.resize(26,nullptr);
        isend = false;
    }
};

class WordDictionary {
public: 
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char&ch:word) {
            if(!curr->child[ch-'a']) {
                curr->child[ch-'a'] = new Node();
            }
            curr = curr->child[ch-'a'];
        }
        curr->isend = true;
        return;
    } 
    bool helper(Node* node,string &word) {
        Node* curr = node;
        for(int j=0;j<word.size();j++) {
            char ch = word[j];
            if(ch == '.') {
                for(int i = 0;i<26;i++) {
                    string temp = word.substr(j+1);
                    if(curr->child[i] && helper(curr->child[i],temp)) {
                        return true;
                    }
                }
                return false;
            }
            if(!curr->child[ch-'a']) {
                return false;
            }
            curr = curr->child[ch-'a'];
        }
        return curr->isend;
    }

    bool search(string word) {
        return helper(root,word);
    }
};

class Node {
public:
    Node* child[26];
    bool end;

    Node() {
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        end = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* temp = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(temp->child[idx] == NULL) {
                temp->child[idx] = new Node();
            }

            temp = temp->child[idx];
        }

        temp->end = true;
    }

    bool search(string word) {
        Node* temp = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(temp->child[idx] == NULL) {
                return false;
            }

            temp = temp->child[idx];
        }

        return temp->end;
    }
    string maxprefix() {
        Node* node = root;
        string ans = "";
        while(node != NULL) {
            if(node->end) return ans;
            int cnt = 0;
            Node* tmp = NULL;
            int idx = -1;
            for(int i = 0;i<26;i++) {
                if(node->child[i] != NULL) {
                    cnt++;
                    tmp = node->child[i];
                    idx = i;
                }
            }
            if(cnt > 1) return ans;
            ans += (char)('a'+idx);
            node = tmp;
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie T;
        for(auto &str:strs) {
            T.insert(str);
        }
        return T.maxprefix();
    }
};
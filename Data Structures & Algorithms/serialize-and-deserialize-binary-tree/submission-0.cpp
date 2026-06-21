class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        queue<TreeNode*> q;
        q.push(root);
        string enc;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node) {
                enc += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                enc+="#,";
            }
        }
        cout<<enc<<endl;
        return enc;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s,str,',');
            if(str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s,str,',');
            if(str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

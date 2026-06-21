class Solution {
public:

    string encode(vector<string>& strs) {
        string s;

        for(auto &str : strs) {
            for(auto &ch : str) {
                s += to_string((int)ch);
                s.push_back(',');
            }
            s += "#,";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        stringstream ss(s);
        string token;

        string curr = "";

        while(getline(ss, token, ',')) {

            if(token == "#") {
                ans.push_back(curr);
                curr = "";
            }
            else {
                int num = stoi(token);
                curr.push_back((char)num);
            }
        }

        return ans;
    }
};

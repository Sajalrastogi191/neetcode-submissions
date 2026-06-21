class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(auto &ast:asteroids) {
            if(ast > 0) {
                st.push(ast);
            }
            else {
                while(!st.empty() && st.top() < abs(ast)) {
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(ast)) {
                    st.pop();
                    continue;
                }
                if(st.empty()) {
                    ans.push_back(ast);
                }
            }
        }
        vector<int> tmp;
        while(!st.empty()) {
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        ans.insert(ans.end(),tmp.begin(),tmp.end());
        return ans;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &ch:tokens) {
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int u = st.top();
                st.pop();
                int v = st.top();
                st.pop();
                if(ch == "+") {
                    st.push(u+v);
                } else if(ch == "-") {
                    st.push(v-u);
                } else if(ch == "*") {
                    st.push(u*v);
                } else {
                    st.push(v/u);
                }
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};

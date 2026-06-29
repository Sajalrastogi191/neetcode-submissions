class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(char &c:s) {
            if(c != ']') {
                st.push(string(1, c));
            } else {
                string repeat = "";
                while(!st.empty() && st.top() != "[") {
                    repeat = st.top() + repeat;
                    st.pop();
                }
                st.pop();

                string k = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }
                string newstr = "";
                int cnt = stoi(k);
                for(int i = 0;i<cnt;i++) {
                    newstr += repeat;
                }
                st.push(newstr);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
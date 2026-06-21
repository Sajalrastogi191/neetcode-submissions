class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto &x:operations) {
            if(x == "+") {
                int u = st.top();
                st.pop();
                int v = st.top();
                st.push(u);
                st.push(u+v);
            } else if(x == "D") {
                st.push(st.top()*2);
            } else if(x == "C") {
                st.pop();
            } else {
                st.push(stoi(x));
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
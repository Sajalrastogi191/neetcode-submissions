class Solution {
public:
    int romanToInt(string s) {
        stack<char> st;
        int sum = 0;
        unordered_map<char,int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        for(char &c:s) {
            if(!st.empty() && um[st.top()] < um[c]) {
                sum += (um[c]-um[st.top()]);
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        while(!st.empty()) {
            sum += um[st.top()];
            st.pop();
        }
        return sum;
    }
};
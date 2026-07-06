class FreqStack {
   public:
    stack<int> st;
    unordered_map<int, int> um;
    int cnt;
    FreqStack() { cnt = 0; }

    void push(int val) {
        st.push(val);
        um[val]++;
        cnt = max(cnt, um[val]);
    }

    int pop() {
        if (st.empty()) return -1;
        stack<int> st2;
        while (!st.empty()) {
            if (um[st.top()] < cnt) {
                st2.push(st.top());
                st.pop();
            } else {
                break;
            }
        }
        int val = st.top();
        if (!st.empty()) st.pop();
        um[val]--;
        bool hasMaxFreq = false;
        for (auto& pair : um) {
            if (pair.second == cnt) {
                hasMaxFreq = true;
                break;
            }
        }
        if (!hasMaxFreq) {
            cnt--;
        }
        
        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
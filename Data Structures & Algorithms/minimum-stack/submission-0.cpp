class MinStack {
public:
    vector<vector<int>> st;
    MinStack() {
        
    }
    void push(int val) {
        if (st.empty()) {
            st.push_back({val, val});
        } else {
            int current_min = min(val, st.back()[1]);
            st.push_back({val, current_min});
        }
    }
    
    void pop() {
        if(!st.empty()) st.pop_back();
    }
    
    int top() {
        return st.back()[0];
    }
    
    int getMin() {
        return st.back()[1];
    }
};

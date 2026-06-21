class StockSpanner {
public:
    stack<pair<int,int>> st; //{idx,price}
    int i;
    StockSpanner() {
        i = -1;
    }
    
    int next(int price) {
        i++;
        int span = 0;
        while(!st.empty() && st.top().second <= price) {
            st.pop();
        }
        if(st.empty()) span = i+1;
        else span =  i-st.top().first;
        st.push({i,price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
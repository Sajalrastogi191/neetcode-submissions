class StockSpanner {
public:
    vector<int> prices;
    stack<int> st;

    int next(int price) {
        prices.push_back(price);
        int i = prices.size() - 1;

        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int span = st.empty() ? i + 1 : i - st.top();

        st.push(i);
        return span;
    }
};
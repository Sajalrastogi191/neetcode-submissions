class Solution {
public:
    unordered_set<int> st;
    bool isHappy(int n) {
        if(st.count(n)) return false;
        if(n == 1) return true;
        st.insert(n);
        int sum = 0;
        while(n != 0) {
            int d = n%10;
            sum += (d*d);
            n /= 10;
        }
        return isHappy(sum);
    }
};

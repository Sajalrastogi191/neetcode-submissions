class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for(int &x:nums) {
            st.insert(x);
        }
        int n = nums.size();
        for(int i = 1;i<=n;i++) {
            if(!st.count(i)) return i;
        }
        return n+1;
    }
};
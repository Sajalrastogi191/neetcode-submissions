class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int ans = 0;
        for(int &p:prices) {
            ans = max(ans,p-buy);
            buy = min(buy,p);
        }
        return ans;
    }
};

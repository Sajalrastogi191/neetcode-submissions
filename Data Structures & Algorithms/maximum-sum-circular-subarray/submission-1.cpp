class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxsum = INT_MIN;
        int sum = 0;
        for(auto &x:nums) {
            sum += x;
            maxsum = max(maxsum,sum);
            if(sum < 0) sum = 0;
            total += x;
        }
        if (maxsum < 0) return maxsum;

        int minsum = INT_MAX;
        sum = 0;
        for(auto &x:nums) {
            sum += x;
            minsum = min(minsum,sum);
            if(sum > 0) sum = 0;
        }
        
        return max(maxsum,total-minsum);
    }
};
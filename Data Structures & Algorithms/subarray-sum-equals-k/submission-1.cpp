class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int sum = 0;
        int ans = 0;
        for(auto &x:nums) {
            um[sum]++;
            sum +=x;
            if(um.find(sum-k) != um.end()) {
                ans+=um[sum-k];
            }
        }
        return ans;
    } 
};
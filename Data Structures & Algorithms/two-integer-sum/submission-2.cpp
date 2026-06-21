class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int  n = nums.size();
        unordered_map<int,int> um;
        for(int i = 0;i<n;i++) {
            um[nums[i]] = i;
        }
        for(int i = 0;i<n;i++) {
            int x = target-nums[i];
            if(um.find(x) != um.end()) {
                int j = um[x];
                if(i != j) return {i,j};
            }
        }
        return {};
    }
};

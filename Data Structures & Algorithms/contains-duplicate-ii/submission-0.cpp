class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] >= 2) return true;
            if(i >= k) mp[nums[i-k]]--;
        }
        return false;
    }
};
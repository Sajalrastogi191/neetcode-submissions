class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int prevMax = maxi;
            int prevMin = mini;

            maxi = max({x, x * prevMax, x * prevMin});
            mini = min({x, x * prevMax, x * prevMin});

            ans = max(ans, maxi);
        }

        return ans;
    }
};
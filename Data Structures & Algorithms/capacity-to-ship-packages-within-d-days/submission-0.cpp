class Solution {
public:
    bool canship(int k,vector<int>& weights,int days) {
        int d = 1;
        int sum = 0;
        for(auto &x : weights) {
            if(sum + x <= k) {
                sum += x;
            } else {
                d++;
                sum = x;
            }
            if(d > days) return false;
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end()),e = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            if(canship(mid,weights,days)) {
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return ans;
    }
}; 
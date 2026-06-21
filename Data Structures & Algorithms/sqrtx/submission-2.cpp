class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;
        int s = 1,e = x;
        int ans = -1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            long long d = (long long)mid * mid;
            if(d <= x) {
                ans = mid;
                s = mid+1;
            } else {
                e = mid-1;
            }   
        }
        return ans;
    }
};
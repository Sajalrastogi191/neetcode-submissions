class Solution {
public:
    bool caneat(int k,vector<int>& piles,int h) {
        int time = 0;
        for(auto &x:piles) {
            time += (((x-1)/k)+1);
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1,e = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(s<=e) {
            int mid = s+(e-s)/2;
            if(caneat(mid,piles,h)) {
                ans = mid;
                e = mid-1;
            } else s = mid+1;
        }
        return ans;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        vector<int> prev = intervals[0];
        for(int i = 1;i<n;i++) {
            if(prev[1] > intervals[i][0]) {
                ans++;
                prev[1] = min(prev[1], intervals[i][1]);
            } else {
                prev =  intervals[i];
            }
        }
        return ans;
    }
};

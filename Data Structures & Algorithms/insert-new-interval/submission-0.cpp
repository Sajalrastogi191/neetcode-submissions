class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int a = intervals[0][0];
        int b = intervals[0][1];
        for(int i = 1;i<n;i++) {
            if(intervals[i][0] > b) {
                ans.push_back({a,b});
                a = intervals[i][0];
            }
            b = max(intervals[i][1],b);
        }
        ans.push_back({a,b});
        return ans;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> trip;
        for(auto it:trips) {
            trip.push_back({it[1],it[2],it[0]});
        }
        int n = trip.size();
        sort(trip.begin(),trip.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int cap = 0;
        for(int i = 0;i<n;i++) {
            while(!pq.empty() && pq.top().first <= trip[i][0]) {
                cap -= pq.top().second;
                pq.pop();
            }
            if(cap+trip[i][2] > capacity) return false;
            cap += trip[i][2];
            pq.push({trip[i][1],trip[i][2]});
        }  
        return true;
    }
};
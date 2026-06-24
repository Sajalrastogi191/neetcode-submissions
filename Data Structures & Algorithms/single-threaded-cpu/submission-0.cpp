class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> newid;
        int n = tasks.size();
        for(int i = 0;i<n;i++) {
            newid.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(newid.begin(),newid.end());
        vector<int> ans;
        int i = 0;
        int time = 0;
        while(i < n || !pq.empty()) {
            if(pq.empty() && time < newid[i][0]) {
                time = newid[i][0];
            }
            while(i < n && newid[i][0] <= time) {
                pq.push({newid[i][1], newid[i][2]});
                i++;
            }
            vector<int> curr = pq.top();
            pq.pop();
            time += curr[0];
            ans.push_back(curr[1]);
        }
        return ans;
    }
};
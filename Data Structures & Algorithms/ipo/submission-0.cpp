class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int  n = profits.size();
        vector<int> isvis(n,false);
        priority_queue<pair<int,int>> pq;
        int p = 0;
        int c = w;

        while(p != k) {
            for(int j = 0;j<n;j++) {
                if(!isvis[j] && capital[j] <= c) {
                    pq.push({profits[j],capital[j]});
                    isvis[j] = true;
                }
            }
            if(pq.empty()) break;
            c += pq.top().first;
            pq.pop();
            p++;
        }
        return c;
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i = 0;i<speed.size();i++) {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());

        stack<float> st;
        for(int i = 0;i<speed.size();i++) {
            float t = (((target-cars[i].first)*1.0)/(cars[i].second*1.0));
            st.push(t);
        }
        int ans = 0;
        double prev = 0;
        while(!st.empty()) {
            if(st.top() > prev) {
                ans++;
                prev = st.top();
            }
            st.pop();
        }
        return ans;
    }
};
 /*

    3 3 
    3 4.5 10 3

    10 4.5 3 3
 */


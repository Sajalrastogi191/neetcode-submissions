class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;
        map<int,int> mp;
        for(int &x : hand) {
            mp[x]++;
        }
        while(mp.size()) {
            int num = mp.begin()->first;
            for(int i = num;i<num+groupSize;i++) {
                if(mp.count(i)) {
                    mp[i]--;
                    if(mp[i] == 0) mp.erase(i);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0;
        int cnt = 0;
        for(int x:nums) {
            if(cnt == 0) num = x;
            if(x == num) cnt++;
            else cnt--;
        }
        return num;
    }
};
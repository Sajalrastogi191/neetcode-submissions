class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long rem = n-1;
        int i = 0;
        while(rem) {
            while(((ans>>i)&1)) {
                i++;
            }
            
            if(rem & 1) ans |= (1LL << i);
            rem >>= 1;
            i++;
        }
        return ans;
    }
};
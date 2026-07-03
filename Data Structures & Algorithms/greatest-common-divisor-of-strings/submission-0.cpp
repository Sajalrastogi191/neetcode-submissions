class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(),m=str2.size();
        if(n > m) return gcdOfStrings(str2,str1);
        string ans="";
        for(int i = 0;i<n;i++) {
            string x = str1.substr(0,i+1);
            if (n % x.size() != 0 || m % x.size() != 0) continue;
            int l = str1.size()/x.size();
            int r = str2.size()/x.size();
            string tmp1="",tmp2="";
            while(l--) {
                tmp1 += x;
            } 
            while(r--) {
                tmp2 += x;
            } 
            if(tmp1 == str1 && tmp2 == str2) {
                ans = x;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        if(n == 0) return "";
        n--;
        string ans=convertToTitle(n/26);
        ans.push_back('A'+(n%26));
        return ans;
    }
};
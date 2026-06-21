class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0,j=s.size()-1;
        bool found = false;
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
                continue;
            } else if(!found) {
                if(s[i+1] == s[j] && isPalindrome(s, i + 1, j)) {
                    return true;
                } else if(s[i] == s[j-1] && isPalindrome(s, i, j - 1)) {
                    return true;
                } else {
                    return false;
                }
            } else if(found) {
                return false;
            }
        }
        return true;
    }

private:
    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
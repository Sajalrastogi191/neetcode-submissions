class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenated strings are different, no common divisor exists
        if (str1 + str2 != str2 + str1) return "";
        
        // Find GCD of lengths
        int g = gcd(str1.size(), str2.size());
        
        // Return the prefix of length g
        return str1.substr(0, g);
    }
};
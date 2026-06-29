class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size()-1;
        while(n >= 0) {
            int sum = carry;
            sum += digits[n];
            digits[n] = sum%10;
            carry = sum/10;
            n--;
        }
        if(carry > 0) {
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};

class Solution {
   public:
    pair<int, int> find(int x, int y, int carry) {
        int sum = x + y + carry;
        return {sum % 2, sum / 2};
    }
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            int x = (i >= 0) ? a[i] - '0' : 0;
            int y = (j >= 0) ? b[j] - '0' : 0;
            pair<int, int> p = find(x, y, carry);
            ans.push_back(p.first + '0');
            carry = p.second;
            i--;
            j--;
        }
        if (carry) {
            ans.push_back('0' + carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
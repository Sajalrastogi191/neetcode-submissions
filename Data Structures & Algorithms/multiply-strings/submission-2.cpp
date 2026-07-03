class Solution {
   public:
    string helper(char ch, string num2) {
        int digit = ch - '0';

        if (digit == 0) return "0";

        string ans = "";
        int carry = 0;

        for (int i = num2.size() - 1; i >= 0; i--) {
            int prod = digit * (num2[i] - '0') + carry;
            ans.push_back((prod % 10) + '0');
            carry = prod / 10;
        }

        while (carry) {
            ans.push_back((carry % 10) + '0');
            carry /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        while (num1.size() > 1 && num1[0] == '0') num1.erase(num1.begin());

        while (num2.size() > 1 && num2[0] == '0') num2.erase(num2.begin());

        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size();
        int m = num2.size();
        string l = "";
        string ans = "0";
        for (int i = n - 1; i >= 0; i--) {
            if (num1[i] == '0') {
                l.push_back('0');
                continue;
            }

            string partial = helper(num1[i], num2);
            partial += l;
            l.push_back('0');
            ans = addStrings(ans, partial);
        }
        int i = 0;
        while (i < ans.size() - 1 && ans[i] == '0') i++;
        return ans.substr(i);
    }
};

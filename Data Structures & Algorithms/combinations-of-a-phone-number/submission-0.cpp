class Solution {
public:
    vector<string> letterCombinationHelper(int idx,string& digits,unordered_map<int,string>& um) {
        if(idx >= digits.size()) {
            return {""};
        }
        vector<string> smallans=letterCombinationHelper(idx+1,digits,um);

        int digit=digits[idx]-'0';
        string temp=um[digit];
        vector<string> ans;

        for(int i=0;i<temp.size();i++) {
            for(int j=0;j<smallans.size();j++) { 
                string comb = temp[i]+smallans[j];
                ans.push_back(comb);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        unordered_map<int,string> um;
        um[2]="abc";
        um[3]="def";
        um[4]="ghi";
        um[5]="jkl";
        um[6]="mno";
        um[7]="pqrs";
        um[8]="tuv";
        um[9]="wxyz";
        vector<string> ans=letterCombinationHelper(0,digits,um);
        return ans;
    }
};
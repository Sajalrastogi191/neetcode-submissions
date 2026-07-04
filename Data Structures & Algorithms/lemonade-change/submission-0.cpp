class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int amount = 0;
        int r5 = 0, r10 = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 20) {
                if (r10 > 0 && r5 > 0) {
                    r10--;
                    r5--;
                } else if (r5 >= 3) {
                    r5 -= 3;
                } else {
                    return false;
                }
            } else if (bills[i] == 10) {
                if (r5 < 1) {
                    return false;
                }
                r5--;
                r10++;
            } else {
                r5++;
            }
        }
        return true;
    }
};
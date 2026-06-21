class Solution {
public:
    void merge(int s,int mid,int e,vector<int>& nums) {
        vector<int> temp;

        int i = s;
        int j = mid + 1;

        while(i <= mid && j <= e) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= e) {
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = s; k <= e; k++) {
            nums[k] = temp[k - s];
        }
    }
    void mergesort(int s,int e,vector<int>& nums) {
        if(s >= e) return;
        int mid = s + (e - s) / 2;
        mergesort(s, mid, nums);
        mergesort(mid + 1, e, nums);
        merge(s, mid, e, nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergesort(0,n-1,nums);
        return nums;
    }
};
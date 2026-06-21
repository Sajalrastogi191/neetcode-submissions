class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0,j = arr.size()-1;
        while((j-i+1) > k) {
            if(abs(arr[i]-x) > abs(arr[j]-x)) i++;
            else j--;
        }
        return vector<int>(arr.begin()+i,arr.begin()+j+1);
    }
};
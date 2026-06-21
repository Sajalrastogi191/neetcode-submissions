/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s = 0,e = mountainArr.length()-1;
        int peak = -1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            int val = mountainArr.get(mid);
            int valleft = mountainArr.get(mid-1);
            int valright = mountainArr.get(mid+1);
            if(val > valleft && val > valright) {
                peak = mid;
                break;
            }
            else if(val > valleft && val < valright) s = mid+1;
            else e = mid-1;
        } 
        s = 0,e=peak;
        while(s <= e) {
            int mid = s+(e-s)/2;
            int val = mountainArr.get(mid);
            if(val == target) return mid;
            else if(val < target) s = mid+1;
            else e = mid-1;
        }
        s = peak+1,e=mountainArr.length()-1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            int val = mountainArr.get(mid);
            if(val == target) return mid;
            else if(val < target) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
};
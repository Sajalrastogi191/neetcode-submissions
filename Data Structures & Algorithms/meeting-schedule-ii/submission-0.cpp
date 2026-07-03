/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            a.push_back(intervals[i].start);
            b.push_back(intervals[i].end);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        int maxroom = 0;
        int room = 0;
        while (i < n && j < n) {
            if (a[i] < b[j]) {
                room++;
                maxroom = max(maxroom, room);
                i++;
            } else {
                room--;
                j++;
            }
        }
        return maxroom;
    }
};

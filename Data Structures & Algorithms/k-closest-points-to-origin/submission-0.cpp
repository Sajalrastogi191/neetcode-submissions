#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        // Max-heap stores pairs of {squared_distance, point_index}
        std::priority_queue<std::pair<int, int>> maxHeap;
        
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;
            
            maxHeap.push({dist, i});
            
            // If the heap exceeds size k, remove the farthest point
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // Extract the remaining k closest points from the heap
        std::vector<std::vector<int>> result;
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second;
            maxHeap.pop();
            result.push_back(points[index]);
        }
        
        return result;
    }
};
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int size;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        size = 0;
        cap = k;
        for(int &x:nums) {
            pq.push(x);
            size++;
            if(size > k) {
                pq.pop();
            }
        }
        return;
    }
    
    int add(int val) {
        pq.push(val);
        size++;
        if(size > cap) {
            pq.pop();
        }
        return pq.top();
    }
};

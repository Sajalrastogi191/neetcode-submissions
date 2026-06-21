class MedianFinder {
public:
    priority_queue<int> mxhp; //maxheap
    priority_queue<int,vector<int>,greater<int>> mnhp; //minheap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxhp.empty()) {
            mxhp.push(num);
        } else if(mxhp.top() <= num) {
            mnhp.push(num);
            if(mnhp.size() > mxhp.size()) {
                mxhp.push(mnhp.top());
                mnhp.pop();
            }
        } else {
            mxhp.push(num);
            if(mxhp.size() > mnhp.size()+1) {
                mnhp.push(mxhp.top());
                mxhp.pop();
            }
        }
    }
    
    double findMedian() {
        if(mxhp.size() == mnhp.size()) {
            return ((mxhp.top()+mnhp.top())*1.0)/2.0;
        } else {
            return mxhp.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
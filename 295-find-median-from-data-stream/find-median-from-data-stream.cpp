class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    void addNum(int num) {

        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        if(abs((int)maxHeap.size() - (int)minHeap.size()) > 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        double res;
        if(maxHeap.size() == minHeap.size()){
            return (double)(maxHeap.top() + minHeap.top())/2;
            

        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
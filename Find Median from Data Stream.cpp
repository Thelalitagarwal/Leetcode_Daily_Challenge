class MedianFinder {
public:
    
    priority_queue<int>MaxHeap;
    priority_queue<int,vector<int>,greater<int>>MinHeap;
    
    MedianFinder(){}
    
    void addNum(int num) {
        MaxHeap.push(num);
        MinHeap.push(MaxHeap.top());
        MaxHeap.pop();
        if(MinHeap.size() > MaxHeap.size())
        {
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }
    }
    
    double findMedian() {    
        if(MaxHeap.size() > MinHeap.size()) return MaxHeap.top();
        else return (double)(MaxHeap.top()+MinHeap.top())/2.0;
    }
};
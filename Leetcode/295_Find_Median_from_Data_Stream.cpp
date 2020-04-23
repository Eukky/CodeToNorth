// 295. Find Median from Data Stream
// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
// So the median is the mean of the two middle value.
// For example,
// [2,3,4], the median is 3
// [2,3], the median is (2 + 3) / 2 = 2.5
// Design a data structure that supports the following two operations:
// void addNum(int num) - Add a integer number from the data stream to the data structure.
// double findMedian() - Return the median of all elements so far.
 
// Example:
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> minQ;
    priority_queue<int, vector<int>, greater<int>> maxQ;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(!minQ.empty() && num > minQ.top()){
            maxQ.push(num);
        }else{
            minQ.push(num);
        }
        if(minQ.size() + 1 < maxQ.size()){
            minQ.push(maxQ.top());
            maxQ.pop();
        }
        if(maxQ.size() + 1 < minQ.size()){
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }
    double findMedian() {
        if(minQ.size() > maxQ.size()){
            return minQ.top();
        }else if(maxQ.size() > minQ.size()){
            return maxQ.top();
        }else if(maxQ.size() == minQ.size()){
            return (maxQ.top() + minQ.top()) / 2.0;
        }else{
            return 0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
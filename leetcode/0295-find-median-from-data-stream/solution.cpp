class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int> maxheap;

    MedianFinder() {
    
    }
    
    void addNum(int num) {
        int n=maxheap.size();
        int m=minheap.size();
        if(n==0 && m==0){
            minheap.push(num);
            return;
        }
        int b=maxheap.size() - minheap.size();
            if(b==0){
                if(num>((double)maxheap.top()+(double)minheap.top())/2){
                    minheap.push(num);
                }
                else{
                    maxheap.push(num);
                }
            }
            else if(b==1){
                if(num<=maxheap.top()){
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                }
                else{
                    minheap.push(num);
                }
            }
            else if(b==-1){
                if(num>minheap.top()){
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                }
                else{
                    maxheap.push(num);
                }
            }
    }
    
    double findMedian() {
        int n=maxheap.size();
        int m=minheap.size();
        int b=maxheap.size() - minheap.size();
            if(b==0) return ((double)maxheap.top()+(double)minheap.top())/2;
            else if(b==1) return maxheap.top();
            else if(b==-1) return minheap.top();
        return -1;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

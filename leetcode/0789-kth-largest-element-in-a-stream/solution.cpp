class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minheap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        int n=nums.size();
        if(n>=k){
            for(int i=0;i<k;i++){
                minheap.push(nums[i]);
            }
            for(int i=k;i<nums.size();i++){
                if(nums[i]>minheap.top()){
                    minheap.pop();
                    minheap.push(nums[i]);
                }
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                minheap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(minheap.size()<k){
            minheap.push(val);
            return minheap.top();
        }
        if(val>minheap.top()){
            minheap.pop();
            minheap.push(val);
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

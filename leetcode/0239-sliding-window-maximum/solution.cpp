class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(dq.empty()||nums[dq.front()]>nums[i]){
                dq.push_front(i);
            }
            else{
                while(!dq.empty() && nums[dq.front()]<=nums[i]){
                    dq.pop_front();
                }
                dq.push_front(i);
            }
        }
        ans.push_back(nums[dq.back()]);
        for(int i=k;i<nums.size();i++){
            if(dq.back()<=i-k){
                dq.pop_back();
            }
            if(nums[dq.front()]>nums[i]){
                dq.push_front(i);
            }
            else{
                while(!dq.empty() && nums[dq.front()]<=nums[i]){
                    dq.pop_front();
                }
                dq.push_front(i);
            }
            ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};

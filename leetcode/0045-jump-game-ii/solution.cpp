class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){return 0;}
        int maxjump=0;
        int ans=0;
        int curr=0;
        int curr_end=0;
        while(curr<nums.size()-1){
            maxjump = max(maxjump, curr + nums[curr]);
            if(curr==curr_end){
                ans++;
                curr_end=maxjump;
            }
            curr++;
        }
        return ans;
    }
};

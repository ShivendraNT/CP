class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump=0;
        int curr=0;
        while(curr<=maxjump && curr<nums.size()){
            int jump=curr+nums[curr];
            maxjump=max(maxjump,jump);
            curr++;
        }
        if(maxjump>=nums.size()-1){
            return true;
        }
        return false;
    }
};

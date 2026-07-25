class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        float n=nums.size();
        float sum=nums[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>(sum/(n-1-i))){
                ans++;
            }
            sum+=nums[i];
        }
        return ans;
    }
};

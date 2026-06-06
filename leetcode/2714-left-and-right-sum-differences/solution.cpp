class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            leftsum.push_back(sum);
            sum+=nums[i];
        }
        sum=0;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=abs(leftsum[i]-sum);
            sum+=nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<min(n,k);i++){
            ans+=(long long)nums[n-i-1]*mul;
            if(mul!=1){
                mul--;
            }
        }
        return ans;
    }
};

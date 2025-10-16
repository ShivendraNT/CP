class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        unordered_map<int,int> prefix;
        prefix[0]=1;
        for (int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if (prefix.find(sum-k)!=prefix.end()){
                ans=ans+prefix[sum-k];
            }
            prefix[sum]++;
        }
        return ans;
    }
};

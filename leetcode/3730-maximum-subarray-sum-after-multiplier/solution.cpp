class Solution {
public:
    long long solve(vector<int>&nums,int k,bool mul){
        int n=nums.size();
        long long ans=LLONG_MIN;
        long long f0,f1,f2;
        long long o=nums[0];
        long long t=mul?(long long)nums[0]*k:(long long)nums[0]/k;
        f0=o;
        f1=t;
        f2=LLONG_MIN;
        ans=max(f0,f1);
        for(int i=1;i<n;i++){
            o=nums[i];
            t=mul?(long long)nums[i]*k:(long long)nums[i]/k;
            long long tempf0=o+max(0LL,f0);
            long long tempf1=t+max({0LL,f1,f0});
            f2=o +max({f2,f1});
            f0=tempf0;
            f1=tempf1;
            ans=max({ans,f0,f1,f2});
        }
        return ans;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        return max(solve(nums,k,true),solve(nums,k,false));
    }
};

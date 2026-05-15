class Solution {
public:
    vector<long> arrsum(vector<int>&nums,int diff){
        long maxsum=0;
        long sum=0;
        int k=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>diff){
                sum=nums[i];
                k++;
            }
            maxsum=max(sum,maxsum);
        }
        return {maxsum,k};
    }
    int splitArray(vector<int>& nums, int k) {
        long right=accumulate(nums.begin(),nums.end(),0);
        long left=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(left<=right){
            long mid=(right-left)/2+left;
            vector<long> info=arrsum(nums,mid);
            if(info[1]<=k){
                ans=info[0];
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};

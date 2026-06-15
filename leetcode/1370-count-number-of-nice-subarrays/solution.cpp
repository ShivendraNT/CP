class Solution {
public:
    // At most k odd numbers
    int atmost(vector<int>& nums, int k){
        if(k<0) return 0;
        int l=0;
        int r=0;
        int cnt=0;
        int odd=0;
        while(r<nums.size()){
            odd+=nums[r]%2;
            while(odd>k){
                odd-=nums[l]%2;
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};

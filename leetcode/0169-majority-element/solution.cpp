class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n){
            int j=i;
            while(j<n&&(nums[i]==nums[j])){
                j++;
            }
            if (j-i>n/2){
                return nums[i];
            }
            i=j++;
        }
        return nums[0];
    }
};

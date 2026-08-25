class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mul=k;
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]>mul){
                return mul;
            }
            else if(nums[i]==mul){
                mul+=k;
            }
            i++;
        }
        return mul;
    }
};

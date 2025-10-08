class Solution {
public:
    bool check(vector<int>& nums) {
        int first=nums[0];
        int prev=nums[0];
        bool rotflag=0;
        for (int i:nums){
            if (i<prev){
                if (rotflag){
                    return false;
                }
                rotflag=1;
            }
            prev=i;
        }
            if (rotflag && nums.back()>first){
                return false;
            }
        return true;
    }
};

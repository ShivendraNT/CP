class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros=0;
        int k=0;
        for (int i:nums){
            if (i==0){
                zeros++;
            }
            else{
                nums[k]=i;
                k++;
            }
        }
        int n=nums.size()-1;
        while(zeros>0){
            nums[n]=0;
            n--;
            zeros--;
        }
    }
};

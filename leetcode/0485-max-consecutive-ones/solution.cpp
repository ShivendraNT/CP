class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int temp=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==1){
                temp=0;
                while(i<nums.size()&&nums[i]==1){
                    temp++;
                    i++;
                }
                if (temp>max){
                    max=temp;
                }
            }
        }
        return max;
    }
};

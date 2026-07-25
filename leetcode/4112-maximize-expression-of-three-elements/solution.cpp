class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int max1=INT_MIN;
        int max2=INT_MIN;
        int mini=INT_MAX;
        for(int i:nums){
            if(i>max1){
                if(max2!=INT_MIN){
                mini=min(max2,mini);
                }
                max2=max1;
                max1=i;
            }
            else if(i>max2){
                if(max2!=INT_MIN){
                mini=min(max2,mini);
                }
                max2=i;
            }
            else if(i<mini){
                mini=i;
            }
        }
        return max1+max2-mini;
    }
};

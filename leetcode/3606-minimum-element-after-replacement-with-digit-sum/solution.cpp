class Solution {
public:
    int getsum(int num){
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int num:nums){
            mini=min(mini,getsum(num));
        }
        return mini;
    }
};

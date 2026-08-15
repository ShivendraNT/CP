class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xori=0;
        bool nonzero=false;
        for(int x:nums){
            xori^=x;
            if(x!=0){
                nonzero=true;
            }
        }
        if(!nonzero){
            return 0;
        }
        if(xori!=0){
            return nums.size();
        }
        return nums.size()-1;
    }
};

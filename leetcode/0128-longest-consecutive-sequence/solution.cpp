class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int maxseq=1;
        int ctr=1;
        for (int i=0;i<nums.size()-1;i++){
            if (nums[i]==nums[i+1]) continue;
            if (nums[i]+1==nums[i+1]) ctr++;
            else ctr=1;
            if (ctr>maxseq){
                maxseq=ctr;
            }
        }
        return maxseq;
    }
};

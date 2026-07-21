class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int oddcnt=0;
        int evencnt=0;
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(nums[i]%2==0){
                ans[i]=oddcnt;
                evencnt++;
            }
            else{
                ans[i]=evencnt;
                oddcnt++;
            }
        }
        return ans;
    }
};

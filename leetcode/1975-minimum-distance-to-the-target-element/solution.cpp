class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
      int n=nums.size();
      int mini=n;
      for(int i=0;i<n;i++){
        if(nums[i]==target){
            int dist=abs(i-start);
            mini=min(mini,dist);
        }
      }
      return mini;  
    }
};

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<bool> valid(n,false);
        valid[0]=true;
        int leftmax=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>leftmax){
                valid[i]=true;
                leftmax=nums[i];
            }
        }
        valid[n-1]=true;
        int rightmax=nums[n-1];
        for(int i=n-1;i>=0;i--){
            if(nums[i]>rightmax){
                valid[i]=true;
                rightmax=nums[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(valid[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

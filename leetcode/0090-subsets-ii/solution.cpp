class Solution {
public:
    void generate(set<vector<int>>&result,vector<int>&curr,int pos,vector<int>&nums){
        if(pos==nums.size()){
            vector<int>ans(curr);
            sort(ans.begin(),ans.end());
            result.insert(ans);
            return;
        }
        curr.push_back(nums[pos]);
        generate(result,curr,pos+1,nums);
        curr.pop_back();
        generate(result,curr,pos+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> curr;
        generate(result,curr,0,nums);
        vector<vector<int>> ans(result.begin(),result.end());
        return ans;
    }
};

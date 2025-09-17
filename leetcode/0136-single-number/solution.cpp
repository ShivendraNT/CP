class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        int len=nums.size();
        int ans=0;
        for (int i=0;i<len;i++){
            map[nums[i]]+=1;
        }
        for (const auto &pair : map){
            if (pair.second==1){
                ans=pair.first;
            }
        }
        return ans;
    }
};

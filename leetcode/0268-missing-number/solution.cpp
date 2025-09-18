class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max_range=nums.size();
        unordered_map<int,int> map;
        for (int i=0; i<=max_range; i++){
            map[i]+=1;
        }
        for (int num:nums){
            map[num]-=1;
        }
        for (const auto &pair:map){
            if (pair.second==1){
                return pair.first;
            }
        }
        return 0;
    }
};

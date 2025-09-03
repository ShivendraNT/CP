class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = find(nums.begin(),nums.end(),target);
        if (it != nums.end()){
            int index=distance(nums.begin(),it);
            return index;
        }
        nums.push_back(target);
        sort(nums.begin(),nums.end());
        it = find(nums.begin(),nums.end(),target);
        if (it != nums.end()){
            int index=distance(nums.begin(),it);
            return index;
        }
        return 0;
    }
};

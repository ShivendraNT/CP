class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        set<long long> window;
        for (int left=0;left<n;left++){
            auto it =window.lower_bound((long long)nums[left]-valueDiff);
            if (it!=window.end()&&abs(*it-nums[left])<=valueDiff) return true;

            window.insert(nums[left]);

            if (window.size()>indexDiff){
                window.erase(nums[left-indexDiff]);
            }
        }
        return false;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; 
        if (k == 0) return; 

        reverse(nums.begin(), nums.end());          // Reverse entire array
        reverse(nums.begin(), nums.begin() + k);    // Reverse first k
        reverse(nums.begin() + k, nums.end());
    }
};

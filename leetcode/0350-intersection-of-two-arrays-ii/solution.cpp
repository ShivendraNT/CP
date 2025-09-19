class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.size()>nums2.size()){
            for (int i: nums2){
                auto it=find(nums1.begin(),nums1.end(),i);
                if (it!=nums1.end()){
                    res.push_back(i);
                    nums1.erase(it);
                }
            }
            return res;
        }
        for (int i: nums1){
                auto it=find(nums2.begin(),nums2.end(),i);
                if (it!=nums2.end()){
                    res.push_back(i);
                    nums2.erase(it);
                }
            }
            return res;

    }
};

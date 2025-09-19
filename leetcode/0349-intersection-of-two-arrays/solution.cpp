class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(),nums1.end());
        set<int> set2(nums2.begin(),nums2.end());
        vector<int> res;
        if (set1.size()>set2.size()){
            for (int i:set2){
                auto it=set1.find(i);
                if (it !=set1.end()){
                    res.push_back(i);
                }
            }
            return res;
        }
        for (int i:set1){
                auto it=set2.find(i);
                if (it !=set2.end()){
                    res.push_back(i);
                }
            }
            return res;

    }
};

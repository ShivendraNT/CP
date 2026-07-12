class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        unordered_map<int, int> mpp;
        int rank = 1;
        for (int elem : st) {
            mpp[elem] = rank++;
        }
        
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            ans.push_back(mpp[arr[i]]);
        }
        
        return ans;
    }
};

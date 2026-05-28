class Solution {
public:
    void generate(vector<vector<int>>& res, vector<int>& curr, int sum, int pos, int target, vector<int>& C) {
        if (sum == target) { res.push_back(curr); return; }
        for (int i = pos; i < C.size() && sum + C[i] <= target; ++i) {
            curr.push_back(C[i]);
            generate(res, curr, sum + C[i], i, target, C);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res; vector<int> curr;
        sort(candidates.begin(), candidates.end());
        generate(res, curr, 0, 0, target, candidates);
        return res;
    }
};

class Solution {
public:
    void generate(vector<vector<int>>& result, vector<int>& curr, int target, vector<int>& C, int pos) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        
        for (int i = pos; i < C.size(); ++i) {
            if (i > pos && C[i] == C[i - 1]) continue;
            
            if (C[i] > target) break; 
            
            curr.push_back(C[i]);
            generate(result, curr, target - C[i], C, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        generate(result, curr, target, candidates, 0);
        return result;
    }
};

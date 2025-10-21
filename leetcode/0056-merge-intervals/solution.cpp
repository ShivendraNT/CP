class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        if (intervals.size()==0) return merged;
        merged.push_back(intervals[0]);
        for (int i=1;i<(int)intervals.size();i++){
            vector<int>&prev=merged.back();
            vector<int> curr=intervals[i];
            if (prev[1]>=curr[0]){
                prev[1]=max(curr[1],prev[1]);
            }
            else{
                merged.push_back(curr);
            }
        }
        return merged;
    }
};

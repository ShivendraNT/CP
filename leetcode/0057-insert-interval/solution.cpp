class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size()==0) return {newInterval};
        int n=intervals.size();
        bool inserted = false;
        for(int i=0;i<n;i++){
            // Before them and between them
            if(intervals[i][1]>=newInterval[0] && !(intervals[i][0]>newInterval[1])){
                int start=min(intervals[i][0],newInterval[0]);
                int end=max(intervals[i][1],newInterval[1]);
                i++;
                while(i<n){
                    if(intervals[i][0]<=end){
                        end=max(end,intervals[i][1]);
                        i++;
                    }
                    else{
                        ans.push_back({start,end});
                        inserted = true;
                        break;
                    }
                }
                if (i == n){
                    ans.push_back({start, end});
                    inserted = true;
                }
                else i--;
            }
            else{
                if (intervals[i][0] > newInterval[1] && !inserted) { 
                    ans.push_back(newInterval);
                    inserted = true; 
                }
                ans.push_back(intervals[i]);
            }
        }
        if (!inserted) ans.push_back(newInterval);
        return ans;
    }
};

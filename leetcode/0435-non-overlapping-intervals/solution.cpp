class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        int length=0;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end){
                end=min(intervals[i][1],end);
            }
            else{
                length++;
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        length++;
        return n-length;
    }
};

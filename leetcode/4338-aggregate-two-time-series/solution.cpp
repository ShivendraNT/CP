class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int size1=series1.size();
        int size2=series2.size();
        int i=0;
        int j=0;
        vector<vector<int>> ans;
        while(i<size1 && j<size2){
            if(series1[i][0]==series2[j][0]){
                ans.push_back({series1[i][0],series1[i][1]+series2[j][1]});
                i++;
                j++;
            }
            else if(series1[i][0]<series2[j][0]){
                ans.push_back({series1[i][0],series1[i][1]+series2[j][1]});
                i++;
            }
            else{
                ans.push_back({series2[j][0],series1[i][1]+series2[j][1]});
                j++;
            }
        }
        while(i<size1){
            ans.push_back({series1[i][0],series1[i][1]});
            i++;
        }
        while(j<size2){
            ans.push_back({series2[j][0],series2[j][1]});
            j++;
        }
        return ans;
    }
};

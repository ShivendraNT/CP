class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector <int>> ans;
        vector<int> row;
        row={1};
        ans.push_back(row);
        if (numRows==1){
            return ans;
        }
        row={1,1};
        ans.push_back(row);
        if(numRows==2){
            return ans;
        }
        row={};
        for (int i=2;i<numRows;i++){
            for (int j=0;j<=i;j++){
                if (j==0 || j==i){
                    row.push_back(1);
                }
                else{
                    row.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            ans.push_back(row);
            row={};
        }
        return ans;
    }
};

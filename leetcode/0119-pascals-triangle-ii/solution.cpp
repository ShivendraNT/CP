class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector <int>> ans;
        vector<int> row;
        row={1};
        ans.push_back(row);
        if (rowIndex==0){
            return ans[rowIndex];
        }
        row={1,1};
        ans.push_back(row);
        if(rowIndex==1){
            return ans[rowIndex];
        }
        row={};
        for (int i=2;i<=rowIndex;i++){
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
        return ans[rowIndex];
    }
};

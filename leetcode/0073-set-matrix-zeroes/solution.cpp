class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> zeros;
        for (int i=0;i<matrix[0].size();i++){
            zeros.push_back(true);
        }
        vector<int> line;
        for (int i=0;i<matrix[0].size();i++){
            line.push_back(0);
        }
        for (int i=0;i<matrix.size();i++){
            bool haszero=false;
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    zeros[j]=false;
                    haszero=true;
                }
            }
            if (haszero) {
                matrix[i]=line;
            }
        }
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<zeros.size();j++){
                if (!zeros[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

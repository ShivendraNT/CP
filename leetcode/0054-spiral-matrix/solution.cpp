class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int columns=matrix[0].size();
        int x=0;
        int y=0;
        int dx=1;
        int dy=0;
        vector<int> ans;
        for (int i=0;i<(rows*columns);i++){
            ans.push_back(matrix[y][x]);
            matrix[y][x]=-101;
            if (!(0<=x+dx && x+dx<columns && 0<=y+dy && y+dy<rows) || matrix[y+dy][x+dx]==-101){
                int temp=dx;
                dx=-dy;
                dy=temp;
            }
            x+=dx;
            y+=dy;
        }
        return ans;
    }
};

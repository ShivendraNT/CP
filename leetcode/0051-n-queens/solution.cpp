class Solution {
public:
    bool validate(vector<string>& board, int row,int col,int n){
        // go up and down columns
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }

        // go diagonally left up
        int i=row;
        int j=col;
        while(i>=0&&j>=0){
            if(board[i--][j--]=='Q') return false;
        }

        // go diagonally right up
        i=row;
        j=col;
        while(i>=0 && j<n){
            if(board[i--][j++]=='Q') return false;
        }
        return true;
    }
    void generate(vector<vector<string>>& result, vector<string>& board,int n,int i){
        if(i==n){
            result.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){
            if(validate(board,i,j,n)){
                board[i][j]='Q';
                generate(result,board,n,i+1);
                            board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        generate(result, board, n, 0);
        return result;
    }
};

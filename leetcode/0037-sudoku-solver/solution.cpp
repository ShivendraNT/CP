class Solution {
public:
    bool validate(vector<vector<char>> & board,int row, int col,char s){
        for(int i=0;i<9;i++){
            if(board[i][col]==s){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[row][i]==s){
                return false;
            }
        }
        int boxrowstart=3*(row/3);
        int boxcolstart=3*(col/3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[boxrowstart+i][boxcolstart+j]==s){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char s='1';s<='9';s++){
                        if(validate(board,i,j,s)){
                            board[i][j]=s;
                        
                        if(solve(board)){
                            return true;
                        }
                        board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

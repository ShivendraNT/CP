class Solution {
public: 
    bool dfs(vector<vector<char>>&board,int i,int j, int pos, string word){
        if(pos==word.size()) return true;

        if(i<0 || j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[pos]){
            return false;
        }

        char temp=board[i][j];
        board[i][j]='0';
        bool found=dfs(board,i+1,j,pos+1,word)||dfs(board,i-1,j,pos+1,word) ||dfs(board,i,j+1,pos+1,word) || dfs(board,i,j-1,pos+1,word);

        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};

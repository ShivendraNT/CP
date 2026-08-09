class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(mat[r][c]==0){
                    continue;
                }
                if(r==0 || c==0){
                    dp[r][c]=1;
                }
                else{
                    dp[r][c]=1+min({dp[r-1][c],dp[r-1][c-1],dp[r][c-1]});
                }
            }
        }
        vector<int> toprow(n,0);
        vector<int> botrow(n,0);
        vector<int> perrow(n,0);
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                perrow[r]=max(perrow[r],dp[r][c]);
            }
        }
        toprow[0]=perrow[0];
        for(int i=1;i<n;i++){
            toprow[i]=max(toprow[i-1],perrow[i]);
        }
        vector<int> perRowTop(n, 0);
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                int s=dp[r][c];
                if(s>0){
                    perRowTop[r-s+1]=max(perRowTop[r-s+1],s);
                }
            }
        }
        botrow[n-1]=perRowTop[n-1];
        for(int i=n-2;i>=0;i--){
            botrow[i]=max(botrow[i+1],perRowTop[i]);
        }
        vector<int> leftcol(m,0),rightcol(m,0);
        vector<int> percol(m,0);
        vector<int> percolleft(m,0);
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                int s=dp[r][c];
                percol[c]=max(percol[c],s);
                if(s>0){
                    percolleft[c-s+1]=max(percolleft[c-s+1],s);
                }
            }
        }
        leftcol[0]=percol[0];
        for(int j=1;j<m;j++){
            leftcol[j]=max(leftcol[j-1],percol[j]);
        }
        rightcol[m-1]=percolleft[m-1];
        for(int j=m-2;j>=0;j--){
            rightcol[j]=max(rightcol[j+1],percolleft[j]);
        }
        int best=0;
        for(int i=0;i+1<n;i++){
            best=max(best,min(toprow[i],botrow[i+1]));
        }
        for(int j=0;j+1<m;j++){
            best=max(best,min(leftcol[j],rightcol[j+1]));
        }
        return best*best;
    }
};

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        vector<vector<int>> dp(c,vector<int>(c,0));
        for(int i=c-2;i>=1;i--){
            for(int j=1;j<=c-2;j++){
                if(i>j)continue;
                int mini=INT_MAX;
                for(int ind=i;ind<=j;ind++){
                    int cost=cuts[j+1]-cuts[i-1] + dp[i][ind-1]+dp[ind+1][j];
                    mini=min(mini,cost);
                }   
                dp[i][j]=mini; 
            }
        }
        return dp[1][c-2];
    }
};

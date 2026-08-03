class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        int ans =0; 
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int one=stoneValue[i]-dp[i+1];
            int two=-1e9;
            if(i+1<n){
                two=stoneValue[i]+stoneValue[i+1]-dp[i+2];
            }
            int three=-1e9;
            if(i+2<n){
                three=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3];
            }
            dp[i]=max({one,two,three});
        }
        ans=dp[0];
        if (ans > 0) {
            return "Alice";
        }
        else if (ans < 0) {
            return "Bob";
        }
        else {
            return "Tie";
        }
    }
};

class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m=requests.size();
        int total=1<<m;
        const long long INF=4e18;
        vector<vector<long long>> dp(total,vector<long long>(m,INF));

        for(int i=0;i<m;i++){
            long long travel=abs(start-requests[i][1]);

            dp[1<<i][i]=max(travel,(long long)requests[i][0]);
        }

        for(int mask=1;mask<total;mask++){
            for(int last=0;last<m;last++){
                if(!(mask&&(1<<last))){
                    continue;
                }
                if(dp[mask][last]==INF){
                    continue;
                }

                for(int j=0;j<m;j++){
                    if(mask&(1<<j)){
                        continue;
                    }

                    long long travel=abs(requests[last][1]-requests[j][1]);
                    long long reachTime=dp[mask][last]+travel;
                    long long newTime=max(reachTime,(long long)requests[j][0]);
                    int newMask=mask|(1<<j);

                    dp[newMask][j]=min(dp[newMask][j],newTime);
                }
            }
        }
        long long ans=INF;
        int full=total-1;
        for(int last=0;last<m;last++){
            ans=min(ans,dp[full][last]);
        }
        return ans;
    }
};

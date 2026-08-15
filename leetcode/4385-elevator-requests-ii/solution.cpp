class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        int m=requests.size();

        vector<int> a;
        for(int x:requests){
            if(x!=start){
                a.push_back(x);
            }
        }
        m=a.size();
        if(m==0){
            return 0;
        }
        sort(a.begin(),a.end());

        a.push_back(start);
        sort(a.begin(),a.end());

        int s=lower_bound(a.begin(),a.end(),start)-a.begin();

        const long long INF=4e18;
        int N=a.size();
        vector<vector<array<long long,2>>> dp(N,vector<array<long long,2>>(N,{INF,INF}));
        dp[s][s][0]=0;
        dp[s][s][1]=0;

        for(int len=1;len<=N;len++){
            for(int l=0;l+len-1<N;l++){
                int r=l+len-1;
                if(dp[l][r][0]==INF && dp[l][r][1]==INF){
                    continue;
                }
                int coveredPositions=r-l+1;

                int startInside=(l<=s && s<=r)?1:0;

                int rem=m-(coveredPositions-startInside);

                if(rem==0){
                    continue;
                }

                // Go left
                if(l>0){
                    long long distLeft=abs(a[l]-a[l-1]);
                    if(dp[l][r][0]!=INF){
                        dp[l-1][r][0]=min(dp[l-1][r][0],dp[l][r][0]+distLeft*rem);
                    }

                    if(dp[l][r][1]!=INF){
                        long long dist=abs(a[r]-a[l-1]);
                        dp[l-1][r][0]=min(dp[l-1][r][0],dp[l][r][1]+dist*rem);
                    }
                }

                // Go right
                if(r+1<N){
                    if(dp[l][r][0]!=INF){
                        long long dist=abs(a[l]-a[r+1]);

                        dp[l][r+1][1]=min(dp[l][r+1][1],dp[l][r][0]+dist*rem);
                    }

                    if(dp[l][r][1]!=INF){
                        long long dist=abs(a[r]-a[r+1]);
                        dp[l][r+1][1]=min(dp[l][r+1][1],dp[l][r][1]+dist*rem);
                    }
                }
            }
        }
                return min(dp[0][N-1][0],dp[0][N-1][1]);
    }
};

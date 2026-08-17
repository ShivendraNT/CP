class Solution {
public:
    int f(vector<int>&stoneValue,int totalsum,int start,int end,vector<vector<int>>&memo){
        if(start>=end){
            return 0;
        }
        int cut=start;
        int currsum=0;
        int maxsum=0;
        if(memo[start][end]!=-1){
            return memo[start][end];
        }
        for(;cut<end;cut++){
            currsum+=stoneValue[cut];
            if (currsum < totalsum - currsum){
                maxsum=max(maxsum,currsum+f(stoneValue,currsum,start,cut,memo));
            }
            else if(currsum==totalsum-currsum){
                maxsum=max(maxsum,currsum+f(stoneValue,currsum,start,cut,memo));
                maxsum=max(maxsum,totalsum-currsum+f(stoneValue,totalsum-currsum,cut+1,end,memo));
            }
            else{
                maxsum=max(maxsum,totalsum-currsum+f(stoneValue,totalsum-currsum,cut+1,end,memo));
            }
        }
        return memo[start][end]=maxsum;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int totalsum=0;
        
        for(int i:stoneValue){
            totalsum+=i;
        }
        int n=stoneValue.size();
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        return f(stoneValue,totalsum,0,n-1,memo);
    }
};

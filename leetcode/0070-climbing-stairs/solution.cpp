class Solution {
public:
    /*
    int f(int step,int n,vector<int>&memo){
        if(step==n){
            return 1;
        }
        if(step>n){
            return 0;
        }
        if(memo[step]!=-1){
            return memo[step];
        }
        return f(step+1,n,memo)+f(step+2,n,memo);
    */
    int climbStairs(int n) {
        vector<int>memo(n+1,0);
        memo[n]=1;
        memo[n-1]=1;
        for(int step=n-2;step>=0;step--){
            memo[step]=memo[step+1]+memo[step+2];
        }
        return memo[0];
    }
};

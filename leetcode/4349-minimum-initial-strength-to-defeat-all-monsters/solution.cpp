class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long> diff(n+1,0);
        for(auto it:boosts){
            int l=it[0];
            int r=it[1];
            long long b=it[2];
            diff[l]+=b;
            diff[r+1]-=b;
        }

        vector<long long> bonus(n,0);
        long long curr=0;
        long long req=0;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            bonus[i]=curr;
            req+=monsters[i];
        }

        long long low=0;
        long long high=req;
        long long ans=high;
        while(low<=high){
            long long mid=(high-low)/2+low;
            long long str=mid;
            bool poss=true;
            for(int i=0;i<n;i++){
                if(str+bonus[i]<monsters[i]){
                    poss=false;
                    break;
                }
                str-=monsters[i];
                if(str<0){
                    str=0;
                }
            }
            if(poss){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
